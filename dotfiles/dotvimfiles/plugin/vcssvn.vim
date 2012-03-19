" vim600: set foldmethod=marker:
"
" SVN extension for VCSCommand.
"
" Version:       VCS development
" Maintainer:    Bob Hiestand <bob.hiestand@gmail.com>
" License:
" Copyright (c) 2007 Bob Hiestand
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
" Options documentation: {{{2
"
" VCSCommandSVNExec
"   This variable specifies the SVN executable.  If not set, it defaults to
"   'svn' executed from the user's executable path.
"
" VCSCommandSVNDiffExt
"   This variable, if set, sets the external diff program used by Subversion.
"
" VCSCommandSVNDiffOpt
"   This variable, if set, determines the options passed to the svn diff
"   command (such as 'u', 'w', or 'b').

" Section: Plugin header {{{1

if v:version < 700
	echohl WarningMsg|echomsg 'VCSCommand requires at least VIM 7.0'|echohl None
	finish
endif

runtime plugin/vcscommand.vim

if !executable(VCSCommandGetOption('VCSCommandSVNExec', 'svn'))
	" SVN is not installed
	finish
endif

let s:save_cpo=&cpo
set cpo&vim

" Section: Variable initialization {{{1

let s:svnFunctions = {}

" Section: Utility functions {{{1

" Function: s:DoCommand(cmd, cmdName, statusText, options) {{{2
" Wrapper to VCSCommandDoCommand to add the name of the SVN executable to the
" command argument.
function! s:DoCommand(cmd, cmdName, statusText, options)
	if VCSCommandGetVCSType(expand('%')) == 'SVN'
		let fullCmd = VCSCommandGetOption('VCSCommandSVNExec', 'svn') . ' ' . a:cmd
		return VCSCommandDoCommand(fullCmd, a:cmdName, a:statusText, a:options)
	else
		throw 'SVN VCSCommand plugin called on non-SVN item.'
	endif
endfunction

" Section: VCS function implementations {{{1

" Function: s:svnFunctions.Identify(buffer) {{{2
function! s:svnFunctions.Identify(buffer)
	let fileName = resolve(bufname(a:buffer))
	if isdirectory(fileName)
		let directoryName = fileName
	else
		let directoryName = fnamemodify(fileName, ':h')
	endif
	if strlen(directoryName) > 0
		let svnDir = directoryName . '/.svn'
	else
		let svnDir = '.svn'
	endif
	if isdirectory(svnDir)
		return 1
	else
		return 0
	endif
endfunction

" Function: s:svnFunctions.Add() {{{2
function! s:svnFunctions.Add(argList)
	return s:DoCommand(join(['add'] + a:argList, ' '), 'add', join(a:argList, ' '), {})
endfunction

" Function: s:svnFunctions.Annotate(argList) {{{2
function! s:svnFunctions.Annotate(argList)
	if len(a:argList) == 0
		if &filetype == 'SVNAnnotate'
			" Perform annotation of the version indicated by the current line.
			let caption = matchstr(getline('.'),'\v^\s+\zs\d+')
			let options = ' -r' . caption
		else
			let caption = ''
			let options = ''
		endif
	elseif len(a:argList) == 1 && a:argList[0] !~ '^-'
		let caption = a:argList[0]
		let options = ' -r' . caption
	else
		let caption = join(a:argList, ' ')
		let options = ' ' . caption
	endif

	let resultBuffer = s:DoCommand('blame' . options, 'annotate', caption, {})
	if resultBuffer > 0
		set filetype=SVNAnnotate
	endif
	return resultBuffer
endfunction

" Function: s:svnFunctions.Commit(argList) {{{2
function! s:svnFunctions.Commit(argList)
	let resultBuffer = s:DoCommand('commit -F "' . a:argList[0] . '"', 'commit', '', {})
	if resultBuffer == 0
		echomsg 'No commit needed.'
	endif
endfunction

" Function: s:svnFunctions.Delete() {{{2
function! s:svnFunctions.Delete(argList)
	return s:DoCommand(join(['delete'] + a:argList, ' '), 'delete', join(a:argList, ' '), {})
endfunction

" Function: s:svnFunctions.Diff(argList) {{{2
function! s:svnFunctions.Diff(argList)
	if len(a:argList) == 0
		let revOptions = [] 
		let caption = ''
	elseif len(a:argList) <= 2 && match(a:argList, '^-') == -1
		let revOptions = ['-r' . join(a:argList, ':')]
		let caption = '(' . a:argList[0] . ' : ' . get(a:argList, 1, 'current') . ')'
	else
		" Pass-through
		let caption = join(a:argList, ' ')
		let revOptions = a:argList
	endif

	let svnDiffExt = VCSCommandGetOption('VCSCommandSVNDiffExt', '')
	if svnDiffExt == ''
		let diffExt = []
	else
		let diffExt = ['--diff-cmd ' . svnDiffExt]
	endif

	let svnDiffOpt = VCSCommandGetOption('VCSCommandSVNDiffOpt', '')
	if svnDiffOpt == ''
		let diffOptions = []
	else
		let diffOptions = ['-x -' . svnDiffOpt]
	endif

	let resultBuffer = s:DoCommand(join(['diff'] + diffExt + diffOptions + revOptions), 'diff', caption, {})
	if resultBuffer > 0
		set filetype=diff
	else
		if svnDiffExt == ''
			echomsg 'No differences found'
		endif
	endif
	return resultBuffer
endfunction

" Function: s:svnFunctions.GetBufferInfo() {{{2
" Provides version control details for the current file.  Current version
" number and current repository version number are required to be returned by
" the vcscommand plugin.
" Returns: List of results:  [revision, repository, branch]

function! s:svnFunctions.GetBufferInfo()
	let originalBuffer = VCSCommandGetOriginalBuffer(bufnr('%'))
	let fileName = bufname(originalBuffer)
	let statusText = system(VCSCommandGetOption('VCSCommandSVNExec', 'svn') . ' status -vu "' . fileName . '"')
	if(v:shell_error)
		return []
	endif

	" File not under SVN control.
	if statusText =~ '^?'
		return ['Unknown']
	endif

	let [flags, revision, repository] = matchlist(statusText, '^\(.\{8}\)\s\+\(\S\+\)\s\+\(\S\+\)\s\+\(\S\+\)\s')[1:3]
	if revision == ''
		" Error
		return ['Unknown']
	elseif flags =~ '^A'
		return ['New', 'New']
	else
		return [revision, repository]
	endif
endfunction

" Function: s:svnFunctions.Info(argList) {{{2
function! s:svnFunctions.Info(argList)
	return s:DoCommand(join(['info'] + a:argList, ' '), 'info', join(a:argList, ' '), {})
endfunction

" Function: s:svnFunctions.Lock(argList) {{{2
function! s:svnFunctions.Lock(argList)
	return s:DoCommand(join(['lock'] + a:argList, ' '), 'lock', join(a:argList, ' '), {})
endfunction

" Function: s:svnFunctions.Log(argList) {{{2
function! s:svnFunctions.Log(argList)
	if len(a:argList) == 0
		let options = []
		let caption = ''
	elseif len(a:argList) <= 2 && match(a:argList, '^-') == -1
		let options = ['-r' . join(a:argList, ':')]
		let caption = options[0]
	else
		" Pass-through
		let options = a:argList
		let caption = join(a:argList, ' ')
	endif

	let resultBuffer = s:DoCommand(join(['log', '-v'] + options), 'log', caption, {})
	return resultBuffer
endfunction

" Function: s:svnFunctions.Revert(argList) {{{2
function! s:svnFunctions.Revert(argList)
	return s:DoCommand('revert', 'revert', '', {})
endfunction

" Function: s:svnFunctions.Review(argList) {{{2
function! s:svnFunctions.Review(argList)
	if len(a:argList) == 0
		let versiontag = '(current)'
		let versionOption = ''
	else
		let versiontag = a:argList[0]
		let versionOption = ' -r ' . versiontag . ' '
	endif

	let resultBuffer = s:DoCommand('cat' . versionOption, 'review', versiontag, {})
	if resultBuffer > 0
		let &filetype = getbufvar(b:VCSCommandOriginalBuffer, '&filetype')
	endif
	return resultBuffer
endfunction

" Function: s:svnFunctions.Status(argList) {{{2
function! s:svnFunctions.Status(argList)
	let options = ['-u', '-v']
	if len(a:argList) == 0
		let options = a:argList
	endif
	return s:DoCommand(join(['status'] + options, ' '), 'status', join(options, ' '), {})
endfunction

" Function: s:svnFunctions.Unlock(argList) {{{2
function! s:svnFunctions.Unlock(argList)
	return s:DoCommand(join(['unlock'] + a:argList, ' '), 'unlock', join(a:argList, ' '), {})
endfunction
" Function: s:svnFunctions.Update(argList) {{{2
function! s:svnFunctions.Update(argList)
	return s:DoCommand('update', 'update', '', {})
endfunction

" Section: Plugin Registration {{{1
call VCSCommandRegisterModule('SVN', expand('<sfile>'), s:svnFunctions, [])

let &cpo = s:save_cpo
