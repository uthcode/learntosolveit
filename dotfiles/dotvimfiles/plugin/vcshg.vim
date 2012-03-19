" vim600: set foldmethod=marker:
"
" Mercurial extension for VCSCommand. This extension is based on svn extension
" to VCSCommand made by Bob Hiestand <bob.hiestand@gmail.com>
"
" Version:       1
" Maintainer:    Vladimir Marek <vlmarek@volny.cz>
" License:
" Copyright (c) 2007 Vladimir Marek
"
" Permission is hereby granted, free of charge, to any person obtaining a copy
" of this software and associated documentation files (the "Software"), to
" deal in the Software without restriction, including without limitation the
" rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
" sell copies of the Software, and to permit persons to whom the Software is
" furnished to do so, subject to the following conditions:
"
" The above copyright notice and this permission notice shall be included in
" all copies or substantial portions of the Software.
"
" THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
" IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
" FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
" AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
" LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
" FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
" IN THE SOFTWARE.
"
" Section: Documentation {{{1
"
" Command documentation {{{2
"
" The following command only applies to files under Mercurial source control.
"
" None currently
"
" Mapping documentation: {{{2
"
" By default, a mapping is defined for each command.  User-provided mappings
" can be used instead by mapping to <Plug>CommandName, for instance:
"
" None currently
"
" The default mappings are as follow:
"
" None currently
"
" Options documentation: {{{2
"
" VCSCommandHGExec
"   This variable specifies the Mercurial executable.  If not set, it defaults to
"   'hg' executed from the user's executable path.

if v:version < 700
  finish
endif

" Section: Variable initialization {{{1

let s:hgFunctions = {}
let s:pushdList = []

" Section: Mercurial help functions {{{1

" Function: s:Pushd(filename)
" Similar to pushd in shell. Argument can be either directory or filename next
" to which we want to get
function! s:Pushd(filename)
  call insert (s:pushdList, VCSCommandChangeToCurrentFileDir(a:filename))
endfunction

" Function: s:Popd()
" Does reverse of s:Pushd, similar to shell popd
function! s:Popd()
  execute 'cd' escape(remove(s:pushdList,0), ' ')
endfunction

" Function: s:getToMyBuffer() 
" Does several things:
" * Tries to get original buffer number (1)
" * Tries to get original buffer name (2)
" * Tries to get just filename (3)
" * Chdirs to the filename (uses s:Pushd(...))
" * Returns [(1), (2), (3)]
function! s:getToMyBuffer()
  let originalBuffer=VCSCommandGetOriginalBuffer(bufnr('%'))
  let fileName=bufname(originalBuffer)
  if !filereadable(fileName)
    throw 'Unable to access the file '.fileName
  endif
  let realFileName = fnamemodify(resolve(fileName), ':t')
  call s:Pushd(fileName)
  return [originalBuffer, fileName, realFileName]
endfunction

" Section: Utility functions {{{1

" Function: s:DoCommand(cmd, cmdName, statusText) {{{2
" Wrapper to VCSCommandDoCommand to add the name of the HG executable to the
" command argument.
function! s:DoCommand(cmd, cmdName, statusText)
  try
    if VCSCommandGetVCSType(expand('%')) == 'Mercurial'
      let fullCmd = VCSCommandGetOption('VCSCommandHGExec', 'hg') . ' ' . a:cmd
      return VCSCommandDoCommand(fullCmd, a:cmdName, a:statusText, {})
    else
      throw 'No suitable plugin'
    endif
  catch /No suitable plugin/
    echohl WarningMsg|echomsg 'Cannot apply Mercurial commands to this file.'|echohl None
  endtry
endfunction

" Section: VCS function implementations {{{1

" Function: s:hgFunctions.Identify(buffer) {{{2
function! s:hgFunctions.Identify(buffer)
  let fileName = resolve(bufname(a:buffer))
  if isdirectory(fileName)
    let directory = fileName
  else
    let directory = fnamemodify(fileName, ':h')
  endif

  call s:Pushd(directory)
  let statusText=system(VCSCommandGetOption('VCSCommandHGExec', 'hg') . ' status -I .')
  call s:Popd()
  if v:shell_error != 0
    return 0
  endif
  return 1
endfunction

" Function: s:hgFunctions.Add() {{{2
function! s:hgFunctions.Add(argList)
  return s:DoCommand(join(['add'] + a:argList, ' '), 'add', join(a:argList, ' '))
endfunction

" Function: s:hgFunctions.Annotate(argList) {{{2
function! s:hgFunctions.Annotate(argList)
  let [originalBuffer, fileName, realFileName] = s:getToMyBuffer()
  try
    if len(a:argList) == 0
      if &filetype == 'HGAnnotate'
        " Perform annotation of the version indicated by the current line.
        let revision = matchstr(getline('.'),'\v^\s*\S*\s*\zs\d+')
      else
        if !exists('b:VCSCommandBufferInfo')
          call VCSCommandEnableBufferSetup()
        endif
        let l:revision = b:VCSCommandBufferInfo[0]
        if revision == ''
          throw 'Unable to obtain version information.'
        elseif revision == 'Unknown'        " XXX
          throw 'File not under source control'
        elseif revision == 'New'            " XXX
          throw 'No annotatation available for new file.'
        endif
      endif
    else
      let revision=a:argList[0]
    endif

    let resultBuffer=s:DoCommand('annotate -u -n -r ' . revision . ' "'. realFileName . '"', 'annotate', revision) 
    if resultBuffer > 0
      set filetype=HGAnnotate
    endif
    return resultBuffer
  finally
    call s:Popd()
  endtry
endfunction

" Function: s:hgFunctions.Commit(argList) {{{2
function! s:hgFunctions.Commit(argList)
  return s:DoCommand('commit -l "' . a:argList[0] . '"', 'commit', '')
endfunction

" Function: s:hgFunctions.Delete() {{{2
function! s:hgFunctions.Delete(argList)
  return s:DoCommand(join(['remove'] + a:argList, ' '), 'delete', join(a:argList, ' '))
endfunction

" 0 args - current file
" 1 args - current file revision REV
" 2 args - current file revisions REV1 & REV2
" Function: s:hgFunctions.Diff(argList) {{{2
function! s:hgFunctions.Diff(argList)
  if len(a:argList) == 1
    let revOptions = ' -r' . a:argList[0]
    let caption = '(' . a:argList[0] . ' : tip)' " XXX I'm not sure if tip fits
  elseif len(a:argList) == 2
    let revOptions = ' -r ' . a:argList[0] . ' -r ' . a:argList[1]
    let caption = '(' . a:argList[0] . ' : ' . a:argList[1] . ')'
  else
    let revOptions = ''
    let caption = ''
  endif

  let resultBuffer = s:DoCommand('diff' . revOptions , 'diff', caption)
  if resultBuffer > 0
    set filetype=diff
  else
    echomsg 'No differences found'
  endif
  return resultBuffer
endfunction

" Function: s:hgFunctions.GetBufferInfo() {{{2
" Provides version control details for the current file.  Current version
" number and current repository version number are required to be returned by
" the vcscommand plugin.
" Returns: List of results:  [revision, repository, branch]

function! s:hgFunctions.GetBufferInfo()
  let [originalBuffer, fileName, realFileName] = s:getToMyBuffer()
  try
    let statusText=system(VCSCommandGetOption('VCSCommandHGExec', 'hg') . ' status "' . realFileName . '"')
    if(v:shell_error)
      return []
    endif

    " File not under Mercurial control.
    if statusText =~ '^?'
      return ['Unknown']
    endif

    if statusText =~ '^A'
      return ['New']
    endif

    let statusText=system(VCSCommandGetOption('VCSCommandHGExec', 'hg') . ' log -l 1 --template "{rev}" "' . realFileName . '"')
    if(v:shell_error)
      echoerr "Error running 'hg log' :".statusText
      return []
    endif

    return [statusText]
  finally
    call s:Popd()
  endtry
endfunction

" Function: s:hgFunctions.Lock(argList) {{{2
"function! s:hgFunctions.Lock(argList)
"  return s:DoCommand(join(['lock'] + a:argList, ' '), 'lock', join(a:argList, ' '))
"endfunction

" Function: s:hgFunctions.Log() {{{2
function! s:hgFunctions.Log(argList)
  if len(a:argList) == 0
    let versionOption = ''
    let caption = ''
  elseif len(a:argList) == 1 && a:argList[0] !~ "^-"
    let versionOption=' -r' . a:argList[0]
    let caption = a:argList[0]
  else
    " Multiple options, or the option starts with '-'
    let caption = join(a:argList, ' ')
    let versionOption = ' ' . caption
  endif

  let resultBuffer=s:DoCommand('log' . versionOption, 'log', caption)
  return resultBuffer
endfunction

" Function: s:hgFunctions.Revert(argList) {{{2
function! s:hgFunctions.Revert(argList)
  return s:DoCommand('revert', 'revert', '')
endfunction

" Function: s:hgFunctions.Review(argList) {{{2
function! s:hgFunctions.Review(argList)
  if len(a:argList) == 0
    let versiontag = '(current)'
    let versionOption = ''
  else
    let versiontag = a:argList[0]
    let versionOption = ' -r ' . versiontag . ' '
  endif

  let resultBuffer = s:DoCommand('cat' . versionOption, 'review', versiontag)
  if resultBuffer > 0
    let &filetype=getbufvar(b:VCSCommandOriginalBuffer, '&filetype')
  endif
  return resultBuffer
endfunction

" Function: s:hgFunctions.Status(argList) {{{2
function! s:hgFunctions.Status(argList)
  return s:DoCommand(join(['status'] + a:argList, ' '), 'status', join(a:argList, ' '))
endfunction

" Function: s:hgFunctions.Unlock(argList) {{{2
"function! s:hgFunctions.Unlock(argList)
"  return s:DoCommand(join(['unlock'] + a:argList, ' '), 'unlock', join(a:argList, ' '))
"endfunction
" Function: s:hgFunctions.Update(argList) {{{2
function! s:hgFunctions.Update(argList)
  return s:DoCommand('update', 'update', '')
endfunction

" Section: Mercurial-specific functions {{{1

" Section: Command definitions {{{1
" Section: Primary commands {{{2

" None currently

" Section: Plugin command mappings {{{1

let s:hgExtensionMappings = {}
let mappingInfo = []
for [pluginName, commandText, shortCut] in mappingInfo
  execute 'nnoremap <silent> <Plug>' . pluginName . ' :' . commandText . '<CR>'
  if !hasmapto('<Plug>' . pluginName)
    let s:hgExtensionMappings[shortCut] = commandText
  endif
endfor

" Section: Menu items {{{1
" None currently

" Section: Plugin Registration {{{1
" If the vcscommand.vim plugin hasn't loaded, delay registration until it
" loads.
if exists('g:loaded_VCSCommand')
  call VCSCommandRegisterModule('Mercurial', expand('<sfile>'), s:hgFunctions, s:hgExtensionMappings)
else
  augroup VCSCommand
    au User VCSLoadExtensions call VCSCommandRegisterModule('Mercurial', expand('<sfile>'), s:hgFunctions, s:hgExtensionMappings)
  augroup END
endif

""" TODO """
