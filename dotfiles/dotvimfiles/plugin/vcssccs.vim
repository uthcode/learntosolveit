" vim600: set foldmethod=marker:
"
" Mercurial extension for VCSCommand. This extension is based on svn extension
" to VCSCommand made by Bob Hiestand <bob.hiestand@gmail.com>
"
" Version:       2
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
" The following command only applies to files under SCCS source control.
"
" Those functions are NOT implemented (yet?). Their implementation would differ
" for using sccs or TeamWare. Current implementation has enough features to
" support VCSVimDiff and VCSAnnotate
"
" Add
" Delete
" Lock
" Revert
" Unlock
" Update
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
" VCSCommandSCCSPath
"   This variable specifies path to the sccs binaries. If not set, it defaults
"   to empty string (which means use your $PATH). If set, it MUST end by slash

if v:version < 700
  finish
endif

" Section: Variable initialization {{{1

let s:sccsFunctions = {}
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

" Function: s:DoCommand(binary, cmd, cmdName, statusText) {{{2
" Wrapper to VCSCommandDoCommand to add the path to sccs tools
function! s:DoCommand(binary, cmd, cmdName, statusText)
  try
    if VCSCommandGetVCSType(expand('%')) == 'SCCS'
      let fullCmd = VCSCommandGetOption('VCSCommandSCCSPath', '') . a:binary . ' ' . a:cmd
      return VCSCommandDoCommand(fullCmd, a:cmdName, a:statusText, {})
    else
      throw 'No suitable plugin'
    endif
  catch /No suitable plugin/
    echohl WarningMsg|echomsg 'Cannot apply SCCS commands to this file.'|echohl None
  endtry
endfunction

" Section: VCS function implementations {{{1

" Function: s:sccsFunctions.Identify(buffer) {{{2
function! s:sccsFunctions.Identify(buffer)
  let fileName = resolve(bufname(a:buffer))
  if isdirectory(fileName)
    let directoryName = fileName
  else
    let directoryName = fnamemodify(fileName, ':h')
  endif
  if strlen(directoryName) > 0
    let sccsDir = directoryName . '/SCCS'
  else
    let sccsDir = 'SCCS'
  endif
  if isdirectory(sccsDir)
    return 1
  else
    return 0
  endif
endfunction

" Function: s:sccsFunctions.Add() {{{2
function! s:sccsFunctions.Add(argList)
  echoerr "vcssccs: VCSAdd not implemented"
endfunction

" Function: s:sccsFunctions.Annotate(argList) {{{2
function! s:sccsFunctions.Annotate(argList)
  let [originalBuffer, fileName, realFileName] = s:getToMyBuffer()
  try
    if len(a:argList) == 0
      if &filetype == 'SCCSAnnotate'
        " Perform annotation of the version indicated by the current line.
        let l:revision = matchstr(getline('.'),'\v^\s*\zs\d+\.\d+')
      else
        if !exists('b:VCSCommandBufferInfo')
          call VCSCommandEnableBufferSetup()
        endif
        let l:revision = b:VCSCommandBufferInfo[0]
        if l:revision == ''
          throw 'vcssccs: Unable to obtain version information.'
        endif
      endif
    else
      let l:revision=a:argList[0]
    endif

    let resultBuffer=s:DoCommand('sccs', 'get -p -m -s -r' . l:revision, 'annotate', l:revision) 
    if resultBuffer > 0
      set filetype=SCCSAnnotate
    endif
    return resultBuffer
  finally
    call s:Popd()
  endtry
endfunction

" Function: s:sccsFunctions.Commit(argList) {{{2
function! s:sccsFunctions.Commit(argList)
"  This commits only first line :(
"  return s:DoCommand("sccs", "deledit <" . a:argList[0] , 'commit', '')

" This seems to work ok, but may depend on your shell ...
  return s:DoCommand("sccs", "deledit -y\"$(cat " . a:argList[0] .")\"" , 'commit', '')
endfunction

" Function: s:sccsFunctions.Delete() {{{2
function! s:sccsFunctions.Delete(argList)
  echoerr "vcssccs: VCSDelete not implemented"
endfunction

" 0 args - current file vs. last revision
" 1 args - current file vs. revision REV
" 2 args - current file revisions REV1 & REV2
" Function: s:sccsFunctions.Diff(argList) {{{2
function! s:sccsFunctions.Diff(argList)
  if len(a:argList) == 1 " Compare working copy
    let command = 'sccs'
    let revOptions = 'diffs -r' . a:argList[0] . ' -u'
    let caption = '(' . a:argList[0] . ' : working copy)'
  elseif len(a:argList) == 2
    let l:fileName = resolve(bufname(VCSCommandGetOriginalBuffer(bufnr('%'))))
    let l:fileName = fnamemodify(l:fileName, ':p:h') . '/SCCS/s.'
    let command = 'sccsdiff'
    let revOptions = ' -r' . a:argList[0] . ' -r' . a:argList[1] . ' -u '.l:fileName.'<VCSCOMMANDFILE>'
    let caption = '(' . a:argList[0] . ' : ' . a:argList[1] . ')'
  else
    let command = 'sccs'
    let revOptions = 'diffs -u'
    let caption = ''
  endif

  let resultBuffer = s:DoCommand(command, revOptions , 'diff', caption)
  if resultBuffer > 0
    set filetype=diff
  else
    echomsg 'No differences found'
  endif
  return resultBuffer
endfunction

" Function: s:sccsFunctions.GetBufferInfo() {{{2
" Provides version control details for the current file.  Current version
" number and current repository version number are required to be returned by
" the vcscommand plugin.
" Returns: List of results:  [revision, repository, branch]

function! s:sccsFunctions.GetBufferInfo()
  let [originalBuffer, fileName, realFileName] = s:getToMyBuffer()
  try
    let statusText=system(VCSCommandGetOption('VCSCommandSCCSPath', '') . 'sccs prt -y "' . realFileName . '"')
    if(v:shell_error)
      return []
    endif

    " Error is returned above anyway
    if statusText =~ ' nonexistent (ut4)'
      return ['Unknown']
    endif

    " We can't have 'new', sccs create already commits the file
"   if statusText =~ '^A'
"     return ['New']
"   endif

    let statusText=substitute(statusText, '^[^\t]*...', "", "")
    let statusText=substitute(statusText, "\t.*", "", "")

    return [statusText]
  finally
    call s:Popd()
  endtry
endfunction

" Function: s:sccsFunctions.Lock(argList) {{{2
function! s:sccsFunctions.Lock(argList)
  echoerr "vcssccs: VCSLock not implemented"
endfunction

" 0 parameters - full log
" 1 parameter - log of the given commit
" Function: s:sccsFunctions.Log() {{{2
function! s:sccsFunctions.Log(argList)
  if len(a:argList) == 0
    let versionOption = ''
    let caption = ''
  else
    let versionOption=' -y' . a:argList[0]
    let caption = a:argList[0]
  endif

  let resultBuffer=s:DoCommand('sccs', 'prt ' . versionOption, 'log', caption)
  return resultBuffer
endfunction

" Function: s:sccsFunctions.Revert(argList) {{{2
function! s:sccsFunctions.Revert(argList)
  echoerr "vcssccs: VCSRevert not implemented"
endfunction

" Function: s:sccsFunctions.Review(argList) {{{2
function! s:sccsFunctions.Review(argList)
  if len(a:argList) == 0
    let versiontag = '(current)'
    let versionOption = ''
  else
    let versiontag = a:argList[0]
    let versionOption = ' -r ' . versiontag . ' '
  endif

  let resultBuffer = s:DoCommand('sccs', 'get -p -s -k' . versionOption, 'review', versiontag)
  if resultBuffer > 0
    let &filetype=getbufvar(b:VCSCommandOriginalBuffer, '&filetype')
  endif
  return resultBuffer
endfunction

" Function: s:sccsFunctions.Status(argList) {{{2
function! s:sccsFunctions.Status(argList)
  return s:DoCommand('sccs', join(['sact'] + a:argList, ' '), 'status', join(a:argList, ' '))
endfunction

" Function: s:sccsFunctions.Unlock(argList) {{{2
function! s:sccsFunctions.Unlock(argList)
  echoerr "vcssccs: VCSUnlock not implemented"
endfunction

" Function: s:sccsFunctions.Update(argList) {{{2
function! s:sccsFunctions.Update(argList)
  echoerr "vcssccs: VCSUpdate not implemented"
endfunction

" Section: SCCS-specific functions {{{1

" Section: Command definitions {{{1
" Section: Primary commands {{{2

" None currently

" Section: Plugin command mappings {{{1

let s:sccsExtensionMappings = {}
let mappingInfo = []
for [pluginName, commandText, shortCut] in mappingInfo
  execute 'nnoremap <silent> <Plug>' . pluginName . ' :' . commandText . '<CR>'
  if !hasmapto('<Plug>' . pluginName)
    let s:sccsExtensionMappings[shortCut] = commandText
  endif
endfor

" Section: Menu items {{{1
" None currently

" Section: Plugin Registration {{{1
" If the vcscommand.vim plugin hasn't loaded, delay registration until it
" loads.
if exists('g:loaded_VCSCommand')
  call VCSCommandRegisterModule('SCCS', expand('<sfile>'), s:sccsFunctions, s:sccsExtensionMappings)
else
  augroup VCSCommand
    au User VCSLoadExtensions call VCSCommandRegisterModule('SCCS', expand('<sfile>'), s:sccsFunctions, s:sccsExtensionMappings)
  augroup END
endif
