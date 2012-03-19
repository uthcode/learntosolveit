" Vim reStructured Text
" (c) Mikolaj Machowski 2006
" Author: Mikolaj Machowski ( mikmach AT wp DOT pl )
" Last Change: 4 Nov 2006
" Version: 1.4
" License:
"  Copyright (C) 2006 Mikolaj Machowski <mikmach@wp.pl>
"
"  This script is free software; you can redistribute it and/or
"  modify it under the terms of the GNU Library General Public
"  License as published by the Free Software Foundation; either
"  version 2 of the License, or (at your option) any later version.
"
"  This library is distributed in the hope that it will be useful,
"  but WITHOUT ANY WARRANTY; without even the implied warranty of
"  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
"  Library General Public License for more details.
"
"  You should have received a copy of the GNU Library General Public License
"  along with this library; see the file COPYING.LIB.  If not, write to
"  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
"  Boston, MA 02110-1301, USA.
" 

" Preamble {{{
"
"	Note: This script relies on indentation of elements. You
"	should set it to at least 4.
"
"
if &compatible == 1
	set nocompatible
endif

scriptencoding iso-8859-2

" Initiate some variables. Not really necessary but makes possible to use
" command line completion when doing temporary modifications.
" VST version (for debugging:
let s:vst_ver = '140'
" Write export immediately
if !exists("g:vst_write_export")
	let g:vst_write_export = 0
endif
if !exists("g:vst_included")
	let g:vst_included = split(&rtp, ',')[0].'/autoload/vst/include/'
endif
if !exists("g:vst_css_user")
	let g:vst_css_user = ''
endif
if !exists("g:vst_css_default")
	let g:vst_css_default = ''
endif
if !exists("g:vst_tex_preamble")
	let g:vst_tex_preamble = ''
endif
if !exists("g:vst_pdf_view")
	let g:vst_user_css = 0
endif
if !exists("g:vst_pdf_clean")
	let g:vst_pdf_clean = 0
endif
if !exists("g:vst_tex_post")
	let g:vst_tex_post = ''
endif
if !exists("g:vst_html_post")
	let g:vst_html_post = ''
endif
if !exists("g:vst_containers")
	let g:vst_containers = []
endif

" Placeholders:
"	LISTDEF: list definitions
"	HEADDEF: sections detection
"	   This is ideal:
"	       ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
"	   And is implemented! Also for transitions.
"
" HEADDEF:
let s:vst_headdef = '\(=\{3,}\|+\{3,}\|\*\{3,}\|\^\{3,}\|%\{3,}\|\$\{3,}\|#\{3,}\|@\{3,}\|;\{3,}\|"\{3,}\|\.\{3,}\|,\{3,}\|`\{3,}\|\~\{3,}\|-\{3,}\|!\{3,}\|(\{3,}\|)\{3,}\|:\{3,}\|_\{3,}\|&\{3,}\|}\{3,}\|{\{3,}\||\{3,}\|?\{3,}\|<\{3,}\|>\{3,}\|\\\{3,}\|\[\{3,}\|\]\{3,}\|\/\{3,}\|''\{3,}\)'
let s:vst_headchars = '[][=+*^%$#@;".,`~!():_&{}|?<>/\\''-]'
" LISTDEF:
let s:vst_bulletdef = '[\u2022\u2023\u2043\u204c\u204d\u25d8\u25e6\u2619\u2765\u2767*+-]'
let s:vst_bulletchars = '[\u2022\u2023\u2043\u204c\u204d\u25d8\u25e6\u2619\u2765\u2767*+-]'
"
" }}}

" VST_InstantWrapper: Write export file immediately without changing {{{
" manually g:vst_write_export variable.
" Description: Save value of g:vst_write_export var, set it to 1, call
" VST_Export, and restore old value of variable.
"    line1  - beginning of range (1st line by default)
"    line2  - end of range (last line by default)
"    format - format of export
function! vst#vst#VST_InstantWrapper(line1, line2, format)
	let temp_write_export = g:vst_write_export
	let g:vst_write_export = 1
	call vst#vst#VST_Export(a:line1, a:line2, a:format)
	let g:vst_write_export = temp_write_export
	return
endfunction
" }}}
" VST_Headers:	   Filter out only section titles from other elements {{{
" Description: get only real info about headers/section titles, these are
" bastardized versions of routines from VST_Structure but full scan was too
" slow, had to cut everything what was not necessary.
"	 text: text of whole file in List form
function! VST_Headers(text)

	let doc = a:text

	" Initiate arrays and variables {{{
	let ltype = []
	let lindent = []

	let g:paras = []
	let g:ptype = []
	let g:pindent = []
	let g:plinen = []

	" }}}
	" Detect and create line types {{{
	let lendoc = len(doc)
	for i in range(lendoc)
		if i == lendoc - 1
			let nextline = i - 1
		else
			let nextline = i + 1
		endif
		if doc[i] =~ '^\s*$'
			let ltype += ['blank']
		elseif doc[i] =~ '^\s*\.\. 2html::'
			let ltype += ['2html']
		elseif doc[i] =~ '^\s*\.\. |'
			let ltype += ['replacement']
		elseif doc[i] =~ '^\s*\.\. [[|]\?\w\+:'
			" Names of most directives aren't important for header detection
			" Comment is potential error.
			let ltype += ['nonimp']
		elseif doc[i] =~ '^\s*:.\{-1,}:\s\+'
			let ltype += ['field']
		elseif doc[i] =~ '^\s*(\(\d\+\|[a-zA-Z]\|[icvlxmICVLXM]\+\|#\))\s'
			" LISTDEF: enum embraced in parenthesis
			let cind = len(matchstr(doc[i], '^\s*'))
			let nind = len(matchstr(doc[nextline], '^\s*'))
			if nind > cind
				let ltype += ['oli']
			elseif nind == cind && doc[nextline] =~ '^\s*(\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\))\s'
				let ltype += ['oli']
			elseif doc[nextline] =~ '^\s*$'
				let ltype += ['oli']
			else
				let ltype += ['p']
			endif
		elseif doc[i] =~ '^\s*\(\d\+\|[a-zA-Z]\|[icvlxmICVLXM]\+\|#\)[\]:.)}]\s'
			" LISTDEF:
			let cind = len(matchstr(doc[i], '^\s*'))
			let nind = len(matchstr(doc[nextline], '^\s*'))
			if nind > cind
				let ltype += ['oli']
			elseif nind == cind && doc[nextline] =~ '^\s*\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s'
				let ltype += ['oli']
			elseif doc[nextline] =~ '^\s*$'
				let ltype += ['oli']
			else
				let ltype += ['p']
			endif
		elseif doc[i] =~ '^\s*'.s:vst_bulletdef.'\s'
			" LISTDEF:
			let cind = len(matchstr(doc[i], '^\s*'))
			let nind = len(matchstr(doc[nextline], '^\s*'))
			if nind > cind 
				let ltype += ['uli']
			elseif nind == cind && doc[nextline] =~ '^\s*'.s:vst_bulletdef.'\s'
				let ltype += ['uli']
			elseif doc[nextline] =~ '^\s*$'
				let ltype += ['uli']
			else
				let ltype += ['p']
			endif
		elseif doc[i] =~ '^\s*\(--\|-\|/\|:\|+\)\S.\{-}\(  \|$\)' && doc[i] !~ '^\s*\(--\s\|:\S\+:`\)'
			if lendoc == 1
				let ltype += ['p']
			else
				let ltype += ['optlist']
			endif
		elseif doc[i] =~ '^\s*::\s*$'
			let ltype += ['emptypre']
		elseif doc[i] =~ '^\s*+[=-]\{3,}'
			let ltype += ['table']
		else
			let ltype += ['p']
		endif
		" Check indentation of each line
		let lindent += [strlen(matchstr(doc[i], '^\s*'))]
	endfor
	" }}}
	" Create false 'blank' line number 0 to make looping easier. {{{
	call insert(ltype, 'blank')
	call insert(lindent, 0)
	call insert(doc, '')
	" Create false 'blank' line to the end
	call add(ltype, 'blank')
	call add(lindent, 0)
	call add(doc, '')
	" }}}
	" Create paragraphs from line types {{{
	"
	let i = 0
	let parcounter = -1
	for line in doc
		if ltype[i] == 'blank'
			let i += 1
			continue
		else
			if ltype[i-1] == 'blank'
				let parcounter += 1
				let g:paras += [doc[i]]
				let g:ptype += [ltype[i]]
				let g:pindent += [lindent[i]]
				let g:plinen += [g:vst_reallines[i]]
			else
				let g:paras[parcounter] .= "\n".doc[i]
			endif
		endif

		let i += 1
	endfor
	" }}}
	" Create false 'blank' para number 0 to make looping easier. {{{
	call insert(g:ptype, 'blank')
	call insert(g:pindent, 0)
	call insert(g:paras, '')
	call insert(g:plinen, 0)
	" Create false 'blank' para on the end
	call add(g:ptype, 'blank')
	call add(g:pindent, 0)
	call add(g:paras, '')
	call add(g:plinen, 0)
	" }}}
	" Check and embrace paragraphs in pre tags <pre> (::) {{{
	let i = 0
	while i < len(g:paras)
		" Remove trailing spaces from the end of paragraph. They are meaningless
		" and can cause problems.
		let g:paras[i] = substitute(g:paras[i], '\s\+$', '', '')
		if strpart(g:paras[i], strlen(g:paras[i])-2) == '::' && g:paras[i] !~ '^\s*\.\. [a-zA-Z0-9_-]\+::\s*$' || g:ptype[i] == '2html'
			" For proper embedding of pre into lists I have to set indentation
			" level not to indentation of paragraph (including
			" enumeration/leading character) but indentation of last line.
			let plines = split(g:paras[i], '\n')
			if g:ptype[i] == 'oli'
				if plines[-1] =~ '^\s*(\?\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s*\ze'
					" LISTDEF:
					let initind = strlen(matchstr(plines[-1], '^\s*(\?\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s*\ze'))
				else
					let initind = strlen(matchstr(plines[-1], '^\s*'))
				endif
			elseif g:ptype[i] == 'uli'
					" LISTDEF:
				if plines[-1] =~ '^\s*\zs'.s:vst_bulletdef.'\s*\ze'
					let initind = strlen(matchstr(plines[-1], '^\s*\zs'.s:vst_bulletdef.'\s*\ze'))
				else
					let initind = strlen(matchstr(plines[-1], '^\s*'))
				endif
			elseif g:ptype[i] == 'optlist' || g:ptype[i] == 'dl'
				let initind = strlen(matchstr(plines[-1], '^\s*'))
			elseif g:ptype[i] =~ '^MED'
				if plines[-1] =~ '^\s*\.\. '
					let initind = strlen(matchstr(plines[-1], '^\s*\.\. \ze'))
				else
					let initind = strlen(matchstr(plines[-1], '^\s*'))
				endif
			else
				let initind = g:pindent[i]
			endif
			let j = i + 1
			while j < len(g:paras)
				if initind >= g:pindent[j] || g:ptype[j] == 'notend' || g:ptype[j] == 'blank'
					call insert(g:paras, '', j)
					call insert(g:pindent, g:pindent[j-1], j)
					call insert(g:ptype, 'prend', j)
					call insert(g:plinen, 0, j)

					if g:ptype[i] == '2html'
						let g:paras[i] = ''
						call insert(g:paras, '', i+1)
					else
						call insert(g:paras, '', i+1)
					endif
					call insert(g:pindent, g:pindent[i+1], i+1)
					call insert(g:ptype, 'prebegin', i+1)
					call insert(g:plinen, 0, i+1)

					" Don't allow for checking inside embraced fragment for
					" pre start conditions
					let i = j

					break
				else
					if g:ptype[j] == 'anonlink'
						let parlines = split(g:paras[j], '\n')
						for line in parlines
							call filter(g:vst_anonhlinkdb, 'v:val !~ "'.line.'"')
						endfor
					endif
					let g:ptype[j] = 'pre'
					let g:paras[j] = substitute(g:paras[j], '`', '\&#96;', 'g') 
					let g:paras[j] = substitute(g:paras[j], '_', '\&#95;', 'g') 
					let g:paras[j] = substitute(g:paras[j], '\[', '\&#91;', 'g') 
					let g:paras[j] = substitute(g:paras[j], '\.', '\&#46;', 'g') 
					let g:paras[j] = substitute(g:paras[j], '|', '\&#124;', 'g') 

				endif
				let j += 1
			endwhile
		endif
		let i += 1
	endwhile
	" }}}
	" Build databases NOW.  {{{
	" For this we have to glue together g:paras,
	" split it along \n and perform other footnote detection actions.
	" But we want to make it only once on first parsing, not inside of tables
	if !exists('b:vst_first_parsing')

		" Some actions should be taken only first time when parsing whole file (not in
		" tables cells). Set this variable and unlet it when returning from export
		"let b:vst_first_parsing = 1

		" Build here also other databases?
		let fntext = split(join(g:paras, "\n\n"), "\n")

		call VST_CreateDBs(fntext)

		"let g:vst_anonhlinkdb = filter(copy(fntext), 'v:val =~ "^\\s*\\(\\.\\. __:\\|__ \\)"')

	endif
	" }}}
	" Build replacement database.  {{{
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'replacement'
			let from = matchstr(g:paras[i], '^\s*\.\. |\zs.\{-}\ze|')
			let into = matchstr(g:paras[i], '^\s*\.\. |.\{-}|\s\+\zs.*')
			let g:vst_replacedb[from] = into

		endif
		let i += 1
	endwhile
" }}}
	" Detect if par is a header (<hx>) {{{
	let i = 0
	let h1 = ''
	let h2 = ''
	let h3 = ''
	let h4 = ''
	let h5 = ''
	while i < len(g:paras)
		if g:ptype[i] !~ '^pre'
			if g:paras[i] =~ '\n\s*'.s:vst_headdef.'\s*\(\n\|$\)' && g:ptype[i] !~ 'table'
				let parlines = split(g:paras[i], '\n')
				if parlines[1] =~ '^\s*'.s:vst_headdef.'\s*$'
					let double = ' '
				elseif parlines[0] == parlines[2] && parlines[0] =~ '^\s*'.s:vst_headdef.'\s*$' 
					let double = 'd'
					call remove(parlines, 0)
				endif
				let lchar = matchstr(parlines[1], '.\ze\s*$').double
				if lchar =~ s:vst_headchars
					if h1 == '' || lchar == h1
						let h1 = lchar
						let g:ptype[i] = 'h1'
					elseif h2 == '' || lchar == h2
						let h2 = lchar
						let g:ptype[i] = 'h2'
					elseif h3 == '' || lchar == h3
						let h3 = lchar
						let g:ptype[i] = 'h3'
					elseif h4 == '' || lchar == h4
						let h4 = lchar
						let g:ptype[i] = 'h4'
					elseif h5 == '' || lchar == h5
						let h5 = lchar
						let g:ptype[i] = 'h5'
					else
						let g:ptype[i] = 'h6'
					endif
					let modlchar = substitute(lchar, '[d ]', '', 'g')
					let g:vst_headers[g:ptype[i]] = repeat(modlchar, 9).double
					" Everything after ornament put into next paragraph
					" p type. Ugly but prevents worse things.
					"
					if len(parlines) > 2
						let g:paras[i] = join(parlines[0:1], "\n")
						call insert(g:paras, join(parlines[2:], "\n"), i+1)
						call insert(g:pindent, g:pindent[i], i+1)
						call insert(g:plinen, 0, i+1)

						if parlines[2] =~ '^\s*:.\{-1,}:\s\+'
							call insert(g:ptype, 'field', i+1)
						else
							call insert(g:ptype, 'sub'.g:ptype[i], i+1)
						endif
					else
						let g:paras[i] = join(parlines, "\n")
					endif
				endif
			endif
		endif
		let i += 1
	endwhile
	" }}}

endfunction
" }}}

" VST_Structure: Analyze of text structure
" Description: Take given table and analyze it
" 	- text: text in form of List
function! VST_Structure(text)

let doc = a:text

	" Initiate arrays and variables {{{
	let ltype = []
	let lindent = []

	if !exists("g:vst_recursion")
		let g:vst_recursion = 0
	else
		let g:vst_recursion += 1
	endif

	if exists("g:paras")
		let g:paras_rez += [g:paras]
		let g:paras = []
	else
		let g:paras_rez = []
		let g:paras = []
	endif
	if exists("g:ptype")
		let g:ptype_rez += [g:ptype]
		let g:ptype = []
	else
		let g:ptype_rez = []
		let g:ptype = []
	endif
	if exists("g:pindent")
		let g:pindent_rez += [g:pindent]
		let g:pindent = []
	else
		let g:pindent_rez = []
		let g:pindent = []
	endif
	if exists("g:plinen")
		let g:plinen_rez += [g:plinen]
		let g:plinen = []
	else
		let g:plinen_rez = []
		let g:plinen = []
	endif

	let toc = ''
	" }}}
	" Detect and create line types {{{
	let lendoc = len(doc)
	for line in range(lendoc)
		if line == lendoc - 1
			let nextline = line - 1
		else
			let nextline = line + 1
		endif
		if doc[line] =~ '^\s*$'
			let ltype += ['blank']
		elseif doc[line] =~ '^\s*\.\. _.*:\s*$'
			let ltype += ['intlink']
		elseif doc[line] =~ '^\s*\.\. __:'
			let ltype += ['anonlink']
		elseif doc[line] =~ '^\s*__'
			let ltype += ['anonlink']
		elseif doc[line] =~ '^\s*\.\. _'
			let ltype += ['link']
		elseif doc[line] =~ '^\s*\.\. image::'
			let ltype += ['img']
		elseif doc[line] =~? '^\s*\.\. \(note\|tip\|warning\|attention\|caution\|danger\|error\|hint\|important\|admonition\)::'
			let ltype += ['MED']
		elseif doc[line] =~? '^\s*\.\. figure::'
			let ltype += ['MED-figure']
		elseif doc[line] =~ '^\s*\.\. \[\d\+\]'
			let ltype += ['MED-footnote']
		elseif doc[line] =~ '^\s*\.\. \[#\]'
			let ltype += ['MED-autofootnote']
		elseif doc[line] =~ '^\s*\.\. \[#\k\+\]'
			let ltype += ['MED-labelfootnote']
		elseif doc[line] =~ '^\s*\.\. \[\k\+\]'
			let ltype += ['MED-citation']
		elseif doc[line] =~ '^\s*\.\. pull-quote::'
			let ltype += ['MED-pullquote']
		elseif doc[line] =~ '^\s*\.\. block::'
			let ltype += ['MED-block']
		elseif doc[line] =~ '^\s*\.\. container::'
			let ltype += ['MED-container']
		elseif doc[line] =~ '^\s*\.\. topic::'
			let ltype += ['MED-topic']
		elseif doc[line] =~ '^\s*\.\. sidebar::'
			let ltype += ['MED-sidebar']
		elseif doc[line] =~ '^\s*\.\. compound::'
			let ltype += ['MED-compound']
		elseif doc[line] =~ '^\s*\.\. class::'
			let ltype += ['MED-class']
		elseif doc[line] =~ '^\s*\.\. raw::\s*\(la\)\?tex\s\+html'
			let ltype += ['rawboth']
		elseif doc[line] =~ '^\s*\.\. raw::\s*html\s\+\(la\)\?tex'
			let ltype += ['rawboth']
		elseif doc[line] =~ '^\s*\.\. raw::\s*\(la\)\?tex'
			let ltype += ['rawlatex']
		elseif doc[line] =~ '^\s*\.\. raw::\s*html'
			let ltype += ['rawhtml']
		elseif doc[line] =~ '^\s*\.\. role::'
			let ltype += ['role']
		elseif doc[line] =~ '^\s*\.\. default-role::'
			let ltype += ['defaultr']
		elseif doc[line] =~ '^\s*\.\. latexonly::'
			let ltype += ['latexonly']
		elseif doc[line] =~ '^\s*\.\. htmlonly::'
			let ltype += ['htmlonly']
		elseif doc[line] =~ '^\s*\.\. contents::\s*:local'
			let ltype += ['empty']
		elseif doc[line] =~ '^\s*\.\. contents::'
			let ltype += ['toc']
		elseif doc[line] =~ '^\s*\.\. comment::'
			let ltype += ['comment']
		elseif doc[line] =~ '^\s*\.\. title::'
			let ltype += ['title']
		elseif doc[line] =~ '^\s*\.\. rubric::'
			let ltype += ['rubric']
		elseif doc[line] =~ '^\s*\.\. 2html::'
			let ltype += ['2html']
		elseif doc[line] =~ '^\s*\.\. meta::'
			let ltype += ['meta']
		elseif doc[line] =~ '^\s*\.\. |'
			let ltype += ['replacement']
		elseif doc[line] =~ '^\s*\.\. [a-zA-Z-]\+::' && doc[line] !~ 'header\|footer'
			" Unknown directives treated as pre
			" it doesn't cover contents of these paragraphs, they are
			" processed normally.
			let ltype += ['MED-unknown']
		elseif doc[line] =~ '^\s*\.\.\(\s\|$\)'
			" Everything else beginning with double dot will be treated as
			" comment and completely removed from output. If you want to only
			" hid this use one doc[line] comments
			let ltype += ['MED-comment']
		elseif doc[line] =~ '^\s*(\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\))\s'
			" LISTDEF: enum embraced in parenthesis
			let cind = len(matchstr(doc[line], '^\s*'))
			let nind = len(matchstr(doc[nextline], '^\s*'))
			if nind > cind
				let ltype += ['oli']
			elseif nind == cind && doc[nextline] =~ '^\s*(\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\))\s'
				let ltype += ['oli']
			elseif doc[nextline] =~ '^\s*$'
				let ltype += ['oli']
			else
				let ltype += ['p']
			endif
		elseif doc[line] =~ '^\s*\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s'
			" LISTDEF:
			let cind = len(matchstr(doc[line], '^\s*'))
			let nind = len(matchstr(doc[nextline], '^\s*'))
			if nind > cind
				let ltype += ['oli']
			elseif nind == cind && doc[nextline] =~ '^\s*\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s'
				let ltype += ['oli']
			elseif doc[nextline] =~ '^\s*$'
				let ltype += ['oli']
			else
				let ltype += ['p']
			endif
		elseif doc[line] =~ '^\s*'.s:vst_bulletdef.'\s'
			" LISTDEF:
			let cind = len(matchstr(doc[line], '^\s*'))
			let nind = len(matchstr(doc[nextline], '^\s*'))
			if nind > cind 
				let ltype += ['uli']
			elseif nind == cind && doc[nextline] =~ '^\s*'.s:vst_bulletdef.'\s'
				let ltype += ['uli']
			elseif doc[nextline] =~ '^\s*$'
				let ltype += ['uli']
			else
				let ltype += ['p']
			endif
		elseif doc[line] =~ '^\s*:.\{-1,}:\(\s\+\|$\)'
			let ltype += ['field']
		elseif doc[line] =~ '^\s*::\s*$'
			let ltype += ['emptypre']
		elseif doc[line] =~ '^\s*| '
			let ltype += ['verse']
		elseif doc[line] =~ '^\s*+-\{3,}'
			let ltype += ['table']
		elseif doc[line] =~ '^\s*+=\{3,}'
			let ltype += ['bltable']
		elseif doc[line] =~ '^\s*\(--\|-\|/\|:\|+\)\S.\{-}\(  \|$\)' && doc[line] !~ '^\s*\(--\s\|:\S\+:`\)'
			if lendoc == 1
				let ltype += ['p']
			else
				let ltype += ['optlist']
			endif
		elseif doc[line] =~ '^\s*>>>'
			let ltype += ['doctest']
		elseif doc[line] =~ '^\s*=\{2,}\s\+=\{2,}'
			let ltype += ['simpletbl']
		else
			let ltype += ['p']
			" Remove backslash escaping special meaning for verse paragraphs
			let doc[line] = substitute(doc[line], '^\(\s*\)\\|', '\1|', '')
		endif
		" Check indentation of each doc[line]
		let lindent += [strlen(matchstr(doc[line], '^\s*'))]
	endfor
	" }}}
	" Create false 'blank' line number 0 to make looping easier. {{{
	call insert(ltype, 'blank')
	call insert(lindent, 0)
	call insert(doc, '')
	" Create false 'blank' line to the end
	call add(ltype, 'blank')
	call add(lindent, 0)
	call add(doc, '')
	" }}}
	" Create paragraphs from line types {{{
	"
	let i = 0
	let parcounter = -1
	for line in doc
		if ltype[i] == 'blank'
			let i += 1
			continue
		else
			if ltype[i-1] == 'blank'
				let parcounter += 1
				let g:paras += [doc[i]]
				let g:ptype += [ltype[i]]
				let g:pindent += [lindent[i]]
				let g:plinen += [g:vst_reallines[i]]
			else
				let g:paras[parcounter] .= "\n".doc[i]
			endif
		endif

		let i += 1
	endfor
	" }}}
	" Create false 'blank' para number 0 to make looping easier. {{{
	call insert(g:ptype, 'blank')
	call insert(g:pindent, 0)
	call insert(g:paras, '')
	call insert(g:plinen, 0)
	" Create false 'blank' para on the end
	call add(g:ptype, 'blank')
	call add(g:pindent, 0)
	call add(g:paras, '')
	call add(g:plinen, 0)
	" }}}
	" Loop through paragraphs to concatenate simple tables. {{{
	if string(g:ptype) =~ "'simpletbl'"
		let i = 0
		while i < len(g:paras)
			if g:ptype[i] == 'simpletbl'
				" Check if last line matches simple table syntax
				if g:paras[i] !~ '\n\s*=\{2,}\(\s\+=\{2,}\)\+\s*$' && i < len(g:paras)-1
					let g:paras[i] = g:paras[i]."\n\n".g:paras[i+1]
					" Remove elements from appropriate tables
					call remove(g:paras,   i+1)
					call remove(g:pindent, i+1)
					call remove(g:ptype,   i+1)
					call remove(g:plinen,  i+1)
					let i -= 1
				endif
			endif
			let i += 1
		endwhile
	endif
	" }}}
	" Loop through empty paragraphs to make them really empty. {{{
	if string(g:ptype) =~ "'empty'"
		let i = 0
		while i < len(g:paras)
			if g:ptype[i] == 'empty'
				let g:paras[i] = ''
			endif
			let i += 1
		endwhile
	endif
	" }}}
	" Loop through rawlatex paragraphs correct next paragraphs. {{{
	if string(g:ptype) =~ "'rawlatex'"
		let i = 0
		while i < len(g:paras)
			if g:ptype[i] == 'rawlatex'
				if g:pindent[i+1] > g:pindent[i]
					let g:ptype[i+1] = 'rawlatexcontent'
				endif
			endif
			let i += 1
		endwhile
	endif
	" }}}
	" Loop through rawboth paragraphs correct next paragraphs. {{{
	if string(g:ptype) =~ "'rawboth'"
		let i = 0
		while i < len(g:paras)
			if g:ptype[i] == 'rawboth'
				if g:pindent[i+1] > g:pindent[i]
					let g:ptype[i+1] = 'rawbothcontent'
				endif
			endif
			let i += 1
		endwhile
	endif
	" }}}
	" Loop through rawhtml paragraphs correct next paragraphs. {{{
	if string(g:ptype) =~ "'rawhtml'"
		let i = 0
		while i < len(g:paras)
			if g:ptype[i] == 'rawhtml'
				if g:pindent[i+1] > g:pindent[i]
					let g:ptype[i+1] = 'rawhtmlcontent'
				endif
			endif
			let i += 1
		endwhile
	endif
	" }}}
	" Loop through p paragraphs to sort out additional types (dl). {{{
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'p'
			let parlines = split(g:paras[i], '\n')
			if len(parlines) > 1 && g:paras[i] !~ '^\s*--\?'
				let dlpindent1 = strlen(matchstr(parlines[0], '^\s*'))
				let dlpindent2 = strlen(matchstr(parlines[1], '^\s*'))
				if dlpindent2 > dlpindent1
					let g:ptype[i] = 'dl'
				endif
			endif
		endif
		let i += 1
	endwhile
	" }}}
	" Loop through paragraphs to sort out prequoted type. {{{
	" This par type could be catched only in second par, so we don't have to
	" start from 0
	let i = 1
	while i < len(g:paras)
		if g:ptype[i] == 'p' || g:ptype[i] == 'verse' || g:ptype[i] =~ 'li'
			if g:paras[i] =~ "^\\s*[][<>!:;=|()\"#%'*+$\&,./\?@^_`{}\~-]"
				if g:paras[i-1] =~ '::\s*$' && g:paras[i-1] !~ '^\s*\.\. \w\+::\s*$' && g:pindent[i] == g:pindent[i-1]
					if g:ptype[i] == 'anonlink'
						let parlines = split(g:paras[i], '\n')
						for line in parlines
							call filter(g:vst_anonhlinkdb, 'v:val !~ "'.line.'"')
						endfor
					endif
					let g:ptype[i] = 'prequoted'
					let g:paras[i] = substitute(g:paras[i], '\[', '\&#91;', 'g') 
					let g:paras[i] = substitute(g:paras[i], '_', '\&#95;', 'g') 
					"let g:paras[i-1] = substitute(g:paras[i-1], '::\s*$', ':', '')
				endif
			endif
		endif
		let i += 1
	endwhile
	" }}}
	" Create auto numbered footnotes database {{{
	let g:autofootnotes = []
	if string(g:ptype) =~ "'autofootnote'"
		let i = 0
		while i < len(g:paras)
			if g:ptype[i] == 'autofootnote'
				let g:autofootnotes += [g:paras[i]]
			endif
			let i += 1
		endwhile
	endif
	" }}}
	" Check and embrace paragraphs in pre tags <pre> (::) {{{
	let i = 0
	while i < len(g:paras)
		" Remove trailing spaces from the end of paragraph. They are meaningless
		" and can cause problems.
		let g:paras[i] = substitute(g:paras[i], '\s\+$', '', '')
		if strpart(g:paras[i], strlen(g:paras[i])-2) == '::' && g:paras[i] !~ '^\s*\.\. [a-zA-Z0-9_-]\+::\s*$' || g:ptype[i] == '2html'
			" For proper embedding of pre into lists I have to set indentation
			" level not to indentation of paragraph (including
			" enumeration/leading character) but indentation of last line.
			let plines = split(g:paras[i], '\n')
			if g:ptype[i] == 'oli'
				" LISTDEF:
				if plines[-1] =~ '^\s*(\?\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s*'
					let initind = strlen(matchstr(plines[-1], '^\s*(\?\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s*\ze'))
				else
					let initind = strlen(matchstr(plines[-1], '^\s*'))
				endif
			elseif g:ptype[i] == 'uli'
				" LISTDEF:
				if plines[-1] =~ '^\s*\zs'.s:vst_bulletdef.'\s*'
					let initind = strlen(matchstr(plines[-1], '^\s*\zs'.s:vst_bulletdef.'\s\+\ze'))
				else
					let initind = strlen(matchstr(plines[-1], '^\s*'))
				endif
			elseif g:ptype[i] == 'dl'
				let initind = strlen(matchstr(plines[-1], '^\s*'))
			elseif g:ptype[i] == 'optlist'
				let initind = strlen(matchstr(plines[-1], '^\s*'))
			elseif g:ptype[i] =~ '^MED'
				if plines[-1] =~ '^\s*\.\. '
					let initind = strlen(matchstr(plines[-1], '^\s*\.\. \ze'))
				else
					let initind = strlen(matchstr(plines[-1], '^\s*'))
				endif
			else
				let initind = g:pindent[i]
			endif
			let j = i + 1
			while j < len(g:paras)
				if initind >= g:pindent[j] || g:ptype[j] == 'notend' || g:ptype[j] == 'blank'
					call insert(g:paras, '</vim:pre>', j)
					call insert(g:pindent, g:pindent[j-1], j)
					call insert(g:ptype, 'prend', j)
					call insert(g:plinen, 0, j)

					if g:ptype[i] == '2html'
						let g:paras[i] = VST_FirstLine(g:paras[i])
						let g:paras[i] = substitute(g:paras[i], '\s\+', ' ', 'g')
						let darray = split(g:paras[i], ' ')
						let data = ''
						if len(darray) > 2
							let data .= darray[2]
							if len(darray) > 3
								" Looks strange but need something not likely
								" to occur in colorscheme name and acceptable
								" as class name
								let data .= '----'.darray[3]
							endif
						endif
						let g:paras[i] = ''
						call insert(g:paras, '<vim:pre class="tohtml-'.data.'">', i+1)
					else
						if g:paras[i] =~ '^\s*::\s*$'
							call insert(g:paras, '<vim:pre'.VST_AddClass(i, 1, ' ', '').'>', i+1)
						else
							call insert(g:paras, '<vim:pre>', i+1)
						endif
					endif
					call insert(g:pindent, g:pindent[i+1], i+1)
					call insert(g:ptype, 'prebegin', i+1)
					call insert(g:plinen, 0, i+1)

					" Don't allow for checking inside embraced fragment for
					" pre start conditions
					let i = j

					break
				else
					if g:ptype[j] == 'anonlink'
						let parlines = split(g:paras[j], '\n')
						for line in parlines
							call filter(g:vst_anonhlinkdb, 'v:val !~ "'.line.'"')
						endfor
					endif
					let g:ptype[j] = 'pre'
					let g:paras[j] = substitute(g:paras[j], '$', '\n', '')
					" In pre paragraphs special characters also have to be
					" escaped.
					let g:paras[j] = VST_SpecCharacter(g:paras[j])
					" Prevent splitting for auto footnotes and hyperlinks or
					" special treatment of backslashes
					let g:paras[j] = substitute(g:paras[j], '`',  '\&#96;', 'g') 
					let g:paras[j] = substitute(g:paras[j], '\.', '\&#46;', 'g') 
					let g:paras[j] = substitute(g:paras[j], '\[', '\&#91;', 'g') 
					let g:paras[j] = substitute(g:paras[j], '\\', '\&#92;', 'g') 
					let g:paras[j] = substitute(g:paras[j], '_',  '\&#95;', 'g') 
					let g:paras[j] = substitute(g:paras[j], '|',  '\&#124;', 'g') 

				endif
				let j += 1
			endwhile
		endif
		let i += 1
	endwhile
	" }}}
	" Build databases NOW.  {{{
	" For this we have to glue together g:paras,
	" split it along \n and perform other footnote detection actions.
	" But we want to make it only once on first parsing, not inside of tables
	if !exists('b:vst_first_parsing')

		" Some actions should be taken only first time when parsing whole file (not in
		" tables cells). Set this variable and unlet it when returning from export
		let b:vst_first_parsing = 1

		let fntext = split(join(g:paras, "\n\n"), "\n")

		" Create hyperlink and other databases
		call VST_CreateDBs(fntext)

		" Check how many numbered footnotes are in file
		let numberedfnotes = filter(copy(fntext), 'v:val =~ "^\\s*\\.\\. \\[\\d\\+\\]"')
		let fnotesnumbers = []
		for line in numberedfnotes
			let fnotesnumbers += [matchstr(line, '^\s*\.\. \[\zs\d\+\ze]')]
		endfor
		let s:maxfnumber = max(fnotesnumbers)

		" Check how many labeled footnotes is in file and build labels db
		" Dictionary with key -> text label, value -> number of footnote
		let g:labeledfnotes = filter(copy(fntext), 'v:val =~ "\\[#\\k\\+\\]_"')
		let g:lfnotes = {}
		let k = s:maxfnumber + 1
		let i = 0
		while i < len(g:labeledfnotes)
			let label = matchstr(g:labeledfnotes[i], '\[#\zs\k\+\ze]_')
			let g:lfnotes[label] = k
			let i += 1
			let k += 1
		endwhile
		let s:maxlnumber = len(g:labeledfnotes)

		" Build citation database, only list of citation labels:
		let citlabels = filter(copy(fntext), 'v:val =~ "\\[\\k\\+\\]_"')
		let g:clabels = []
		let i = 0
		while i < len(citlabels)
			let g:clabels += [matchstr(citlabels[i], '\[\zs\k\+\ze]_')]
			let i += 1
		endwhile

	endif
	" }}}
	" Build replacement database.  {{{
	if string(g:ptype) =~ "'replacement'"
		let i = 0
		while i < len(g:paras)
			if g:ptype[i] == 'replacement'
				let from = matchstr(g:paras[i], '^\s*\.\. |\zs.\{-}\ze|')
				let into = matchstr(g:paras[i], '^\s*\.\. |.\{-}|\s\+\zs.*')
				let g:vst_replacedb[from] = into
			endif
			let i += 1
		endwhile
	endif
" }}}
	" Detect and create multi element directives (MED) {{{
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] =~ '^MED'
			let firstpar = matchstr(g:paras[i], '^\s*\.\. \w\+::\s*\zs.*')
			" Header of MED {{{
			if g:ptype[i] == 'MED'
				let medtype = matchstr(g:paras[i], '^\s*\.\. \zs\w\+\ze::')
			elseif g:ptype[i] =~ '-footnote$'
				let medtype = 'footnote'
			elseif g:ptype[i] =~ '-figure$'
				let medtype = 'figure'
			elseif g:ptype[i] =~ '-autofootnote$'
				let medtype = 'autofootnote'
			elseif g:ptype[i] =~ '-citation$'
				let medtype = 'citation'
			elseif g:ptype[i] =~ '-class$'
				let medtype = 'class'
			elseif g:ptype[i] =~ '-compound$'
				let medtype = 'compound'
			elseif g:ptype[i] =~ '-comment$'
				let medtype = 'comment'
			elseif g:ptype[i] =~ '-container$'
				let medtype = 'container'
			elseif g:ptype[i] =~ '-labelfootnote$'
				let medtype = 'labelfootnote'
			elseif g:ptype[i] =~ '-pullquote$'
				let medtype = 'pullquote'
			elseif g:ptype[i] =~ '-block$'
				let medtype = 'block'
			elseif g:ptype[i] =~ '-topic$'
				let medtype = 'topic'
			elseif g:ptype[i] =~ '-sidebar$'
				let medtype = 'sidebar'
			elseif g:ptype[i] =~ '-unknown$'
				let medtype = 'unknown'
			endif
				
			let divindent = repeat(' ', g:pindent[i])
			if medtype =~? '\(\<note\|tip\|warning\|attention\|caution\|danger\|error\|hint\|important\|admonition\)'
				if medtype == 'admonition'
					if firstpar =~ '\n\s*:class:'
						let class = VST_IdMaker(matchstr(firstpar, '\n\s*:class:\s*\zs.*\ze\s*'))
						let name = matchstr(firstpar, '^.*\ze\s*\n')
					else
						let name = matchstr(firstpar, '^.*\ze\s*$')
						let class = 'note'
					endif
					let g:paras[i] = divindent.'<vim:div class="'.tolower(class).VST_AddClass(i,0,' ','').'">'
					let title = name
					let firstpar = ''
				else
					let g:paras[i] = divindent.'<vim:div class="'.tolower(medtype).VST_AddClass(i,0,' ','').'">'
					let title = substitute(tolower(medtype), '^.', '\U\0', '') 
				endif

				let title = divindent.'<vim:p><vim:span class="notetitle">'.title.'</vim:span></vim:p>'

				if firstpar != ''
					let firstpar = substitute(firstpar, '\(^\|\n\)\s\+', '\n', 'g')
					let g:paras[i] = g:paras[i]."\n".title.VST_Structure(split(firstpar, "\n"))
				else
					let g:paras[i] = g:paras[i]."\n".title."\n"
				endif

				let medtype = 'div'

			elseif medtype == 'figure'
				" figure MED {{{
				" supported sub-directives: alt, height, width, scale, align,
				" target, class, identify, figwidth, figclass
				let src = ''
				let width = ''
				let height = ''
				let alt =  ''
				let title = ''
				let identify = ''
				let scale = ''
				let target = ''
				let class = ''
				let align = ''
				let figalign = ''
				let figwidth = ''
				let figclass = ''
				let parlines = split(g:paras[i], '\n')
				for parline in parlines
					let parline = substitute(parline, '^\s*', '', '')
					if src == ''
						let src = matchstr(parline, '\.\. figure::\s*\zs.\{-}\ze\s*$')
						if !filereadable(escape(src, ' \%#'))
							let noimage = 1
							let g:vst_error .= "No image: ".src."\n"
						else
							let noimage = 0
						endif
					endif
					if width == ''
						let width = matchstr(parline, ':width:\s*\zs.\{-}\ze\s*$')
					endif
					if height == ''
						let height = matchstr(parline, ':height:\s*\zs.\{-}\ze\s*$')
					endif
					if alt == ''
						let alt = matchstr(parline, ':alt:\s*\zs.\{-}\ze\s*$')
					endif
					if title == ''
						let title = matchstr(parline, ':title:\s*\zs.\{-}\ze\s*$')
					endif
					if align == ''
						let align = matchstr(parline, ':align:\s*\zs.\{-}\ze\s*$')
					endif
					if figwidth == ''
						let figwidth = matchstr(parline, ':figwidth:\s*\zs.\{-}\ze\s*$')
					endif
					if figclass == ''
						let figclass = matchstr(parline, ':figclass:\s*\zs.\{-}\ze\s*$')
					endif
					if figalign == ''
						let figalign = matchstr(parline, ':figalign:\s*\zs.\{-}\ze\s*$')
					endif
					if scale == ''
						let scale = matchstr(parline, ':scale:\s*\zs.\{-}\ze\s*$')
						if scale =~ '\D'
							let scale = ''
						endif
					endif
					if target == ''
						let target = matchstr(parline, ':target:\s*\zs.\{-}\ze\s*$')
						if target == 'self' && src != ''
							let target = src
						endif
						while target =~ '_\s*$'
							let title = matchstr(target, '^\s*\(`\?\)\zs.*\ze\1_\s*$')
							" If ends in _ it is probably indirect link, process it
							if has_key(g:vst_hlinkdb, title) && g:vst_hlinkdb[title] != ''
								let target = escape(g:vst_hlinkdb[title], '&\~')
							else
								let target = '#l'.tolower(VST_IdMaker(title))
							endif
						endwhile
					endif
					if class == ''
						let class = matchstr(parline, ':class:\s*\zs.\{-}\ze\s*$')
					endif
					if identify == ''
						let identify = matchstr(parline, ':identify:')
						if identify != '' 
							if executable('identify') && noimage == 0
								let [width, height] = VST_IdentifyImage(src, parline)
							else
								let [width, height] = ['', '']
							endif
						endif
					endif
				endfor

				if src != ''
					let src = 'src="'.VST_ProtectLiteral(src).'"'
				endif
				if scale != ''
					if width != ''
						let width = width*scale/100
					endif
					if height != ''
						let height = height*scale/100
					endif
				endif
				if width != ''
					let width = 'width="'.width.'"'
				endif
				if height != ''
					let height = 'height="'.height.'"'
				endif
				if alt != ''
					let alt = 'alt="'.alt.'"'
				endif
				if title != ''
					let title = 'title="'.title.'"'
				endif
				" reST compatibility, if there is no figalign option but align
				" is defined it is probably reST document not supporting
				" figalign.
				if figalign == '' && align != ''
					let figalign = align
					let align = ''
				endif
				if class != ''
					if align == ''
						let class = 'class="'.class.'"'
					else
						let class = 'class="'.class.' vst'.align.'"'
					endif
				else
					if align == ''
						let class = ''
					else
						let class = 'class="vst'.align.'"'
					endif
				endif
				if target != ''
					if target =~ '_\s*$'
						let address = matchstr(VST_Hyperlink(target), '^.\{-}>\ze')
					else
						let address = '<vim:a href="'.VST_ProtectLiteral(target).'">'
					endif
					let imagepart = address."\n<vim:img ".src.' '.width.' '.height.' '.class.' '.alt.' '.title." />\n</vim:a>"
				else
					let imagepart = "\n<vim:img ".src.' '.width.' '.height.' '.class.' '.alt.' '.title." />\n"
				endif

				if figclass != ''
					if figalign == ''
						let figclass = 'class="'.figclass.'"'
					else
						let figclass = 'class="'.figclass.' vst'.figalign.'"'
					endif
				else
					if figalign == ''
						let figclass = 'class="figure"'
					else
						let figclass = 'class="figure vst'.figalign.'"'
					endif
				endif

				if figwidth != ''
					if figwidth == 'image'
						if exists('width')
							let figw = matchstr(width, '\d\+')
							let figwidth = 'style="width:'.figw.'px"'
						endif
					else
						let figwidth = 'style="width:'.figwidth.'px"'
					endif
				endif
				let g:paras[i] = divindent.'<vim:figure '.figclass.' '.figwidth.">\n".divindent.imagepart
			" }}}
			elseif medtype == 'footnote'
			" Footnote \[\d\+\] {{{
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			let indent = repeat(' ', g:pindent[i])
			let g:paras[i] = 
				\ substitute(g:paras[i], '^\s*\.\. \[\(\d\+\)\]', indent.'<vim:footnote>\n'.indent.'<vim:div class="fnumber"><vim:a href="#target-\1" name="footnote-\1">[\1]</vim:a></vim:div>\n'.indent.'<vim:div class="ftext">', '')
			let firstpar = matchstr(g:paras[i], '<vim:div class="ftext">\zs.*')
			let firstpar = substitute(firstpar, '\(^\|\n\)\s\+', '\n', 'g')
			let firstpar = VST_Structure(split(firstpar, "\n"))
			let g:paras[i] = substitute(g:paras[i], '<vim:div class="ftext">\zs.*', '', '')
			let g:paras[i] .= firstpar
			" }}}
			elseif medtype == 'autofootnote'
			" Footnote \[#\] {{{
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			let indent = repeat(' ', g:pindent[i])
			if !exists('b:vst_afs')
				let g:autofnote = s:maxfnumber + s:maxlnumber + 1
				let b:vst_afs = 1
			endif
			let k = g:autofnote
			let g:paras[i] = 
				\ substitute(g:paras[i], '^\s*\.\. \[#\]', indent.'<vim:footnote>\n'.indent.'<vim:div class="fnumber"><vim:a href="#target-'.k.'" name="footnote-'.k.'">['.k.']</vim:a></vim:div>\n'.indent.'<vim:div class="ftext">', '')
			let firstpar = matchstr(g:paras[i], '<vim:div class="ftext">\zs.*')
			let firstpar = substitute(firstpar, '\(^\|\n\)\s\+', '\n', 'g')
			let firstpar = VST_Structure(split(firstpar, "\n"))
			let g:paras[i] = substitute(g:paras[i], '<vim:div class="ftext">\zs.*', '', '')
			let g:paras[i] .= firstpar
			let g:autofnote += 1
			let medtype = 'footnote'
			" }}}
			elseif medtype == 'labelfootnote'
			" Footnote \[#\k\+\] {{{
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			let indent = repeat(' ', g:pindent[i])
			let label = matchstr(g:paras[i], '^\s*\.\. \[#\zs\k\+\ze\]')
			let k = g:lfnotes[label]
			let g:paras[i] = 
				\ substitute(g:paras[i], '^\s*\.\. \[#\k\+\]', indent.'<vim:footnote>\n'.indent.'<vim:div class="fnumber"><vim:a href="#target-'.k.'" name="footnote-'.k.'">['.k.']</vim:a></vim:div>\n'.indent.'<vim:div class="ftext">', '')
			let firstpar = matchstr(g:paras[i], '<vim:div class="ftext">\zs.*')
			let firstpar = substitute(firstpar, '\(^\|\n\)\s\+', '\n', 'g')
			let firstpar = VST_Structure(split(firstpar, "\n"))
			let g:paras[i] = substitute(g:paras[i], '<vim:div class="ftext">\zs.*', '', '')
			let g:paras[i] .= firstpar
			let medtype = 'footnote'
			" }}}
			elseif medtype == 'citation'
			" Citation \[\k\+\] {{{
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			let indent = repeat(' ', g:pindent[i])
			let label = matchstr(g:paras[i], '^\s*\.\. \[\zs\k\+\ze\]')
			let g:paras[i] = 
				\ substitute(g:paras[i], '^\s*\.\. \[\k\+\]', indent.'<vim:citation>\n'.indent.'<vim:div class="cnumber"><vim:a href="#ctarget-'.label.'" name="citation-'.label.'">['.label.']</vim:a></vim:div>\n'.indent.'<vim:div class="ctext">', '')
			let firstpar = matchstr(g:paras[i], '<vim:div class="ctext">\zs.*')
			let firstpar = substitute(firstpar, '\(^\|\n\)\s\+', '\n', 'g')
			let firstpar = VST_Structure(split(firstpar, "\n"))
			let g:paras[i] = substitute(g:paras[i], '<vim:div class="ctext">\zs.*', '', '')
			let g:paras[i] .= firstpar
			" }}}
			elseif medtype == 'class'
			" Multi element class {{{
			" We don't need to change content of par, it is purely virtual MED
			let classname = matchstr(g:paras[i], '^\s*\.\. class::\s*\zs.*\ze\s*$')
			let g:paras[i] = VST_IdMaker(classname)
			let indent = repeat(' ', g:pindent[i])
			" }}}
			elseif medtype == 'comment'
			" Multi element comment {{{
			let indent = repeat(' ', g:pindent[i])
			let g:paras[i] = '<vim:comment>'.g:paras[i]
			" }}}
			elseif medtype == 'compound'
			" Multi element compound {{{
			let indent = repeat(' ', g:pindent[i])
			if firstpar =~ '\n\s*:class:'
				let class = 'vstcompound '.VST_IdMaker(matchstr(firstpar, '\n\s*:class:\s*\zs.*\ze\s*\(\n\|$\)'))
			else
				let class = 'vstcompound'
			endif
			let g:paras[i] = indent.'<vim:block id="id-'.i.'" class="'.tolower(class).'">'
			let g:vst_containers += [tolower(class)]

			let medtype = 'block'

			" }}}
			elseif medtype == 'container'
			" Multi line div {{{
			let indent = repeat(' ', g:pindent[i])
			let class = matchstr(g:paras[i], '^\s*\.\. container::\s*\zs.*\ze\s*')
			let class = VST_IdMaker(class)
			let g:paras[i] = indent.'<vim:container id="id-'.i.'" class="'.tolower(class).'">'
			let g:vst_containers += [tolower(class)]
			" }}}
			elseif medtype == 'topic'
			" Multi element topic {{{
			let indent = repeat(' ', g:pindent[i])
			if firstpar =~ '\n\s*:class:'
				let class = 'topic '.VST_IdMaker(matchstr(firstpar, '\n\s*:class:\s*\zs.*\ze\s*'))
				let name = matchstr(firstpar, '^.*\ze\s*\n')
			else
				let name = matchstr(firstpar, '^.*\ze\s*$')
				let class = 'topic'
			endif
			let g:paras[i] = divindent.'<vim:topic class="'.tolower(class).'">'
			let title = name
			if title != ''
				let title = divindent.'<vim:p><vim:span class="notetitle">'.title.'</vim:span></vim:p>'
			else
				let title = ''
			endif
			let firstpar = ''

			let g:paras[i] .= "\n".title
			" }}}
			elseif medtype == 'sidebar'
			" Multi element sidebar {{{
			let indent = repeat(' ', g:pindent[i])
			if firstpar =~ '\n\s*:class:'
				let class = 'vstsidebar '.VST_IdMaker(matchstr(firstpar, '\n\s*:class:\s*\zs.*\ze\s*\(\n\|$\)'))
			else
				let class = 'vstsidebar'
			endif
			let name = matchstr(firstpar, '^.*\ze\s*\n')
			if firstpar =~ ':subtitle:'
				let subtitle = matchstr(firstpar, ':subtitle:\s*\zs.\{-}\ze\s*\(\n\|$\)')
			else
				let subtitle = ''
			endif
			let g:paras[i] = divindent.'<vim:sidebar class="'.tolower(class).'">'
			let title = name
			if title != ''
				let title = divindent.'<vim:p><vim:span class="notetitle">'.title.'</vim:span></vim:p>'
			else
				let title = ''
			endif

			if subtitle != ''
				let title .= "\n".'<vim:p class="notesubtitle">'.subtitle.'</vim:p>'
			endif
			let firstpar = ''

			let g:paras[i] .= "\n".title
			" }}}
			elseif medtype == 'block'
			" Multi line div {{{
			let indent = repeat(' ', g:pindent[i])
			let class = matchstr(g:paras[i], '^\s*\.\. block::\s*\zs.*\ze\s*')
			let class = VST_IdMaker(class)
			let g:paras[i] = indent.'<vim:block id="id-'.i.'" class="'.tolower(class).'">'
			let g:vst_containers += [tolower(class)]
			" }}}
			elseif medtype == 'pullquote'
			" Bigger blockquote {{{
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			let indent = repeat(' ', g:pindent[i])
			let g:paras[i] = 
				\ substitute(g:paras[i], '^\s*\.\. pull-quote::', indent.'<vim:pullquote'.VST_AddClass(i,1,' ','').'>', '')
			" }}}
			elseif medtype == 'unknown'
			" Unknown multi element div {{{
			let indent = repeat(' ', g:pindent[i])
			let g:paras[i] = indent.'<vim:unknown>'.g:paras[i]
			" }}}
			else
				let g:paras[i] = divindent.'<vim:div class="note">'
				let title = 'Unknown'
				let title = divindent.'<vim:p><vim:span class="notetitle">'.title.'</vim:span></vim:p>'
				if firstpar != ''
					let firstpar = substitute(firstpar, '\(^\|\n\)\s\+', '', 'g')
					let g:paras[i] = g:paras[i]."\n".title.VST_Structure(split(firstpar, "\n"))
				else
					let g:paras[i] = g:paras[i]."\n".title."\n"
				endif
			endif

			" }}}
			let j = i + 1
			while j < len(g:paras)
				let noteindent = g:pindent[j] - g:pindent[i]
				if g:pindent[i] >= g:pindent[j] || g:ptype[j] == 'notend' || g:ptype[j] == 'blank'
					if medtype =~ 'footnote\|citation'
						call insert(g:paras, repeat(' ', g:pindent[j]).'</vim:div></vim:'.medtype.'>', j)
					elseif medtype == 'class'
						if j - i == 1
							call insert(g:paras, repeat(' ', g:pindent[j]).'', j)
						else
							call insert(g:paras, repeat(' ', g:pindent[j]).'<vim:class'.classname.' />', j)
						endif
					else
						call insert(g:paras, repeat(' ', g:pindent[j]).'</vim:'.medtype.'>', j)
					endif
					call insert(g:pindent, g:pindent[i], j)
					"call insert(g:pindent, g:pindent[j-1], j)
					call insert(g:ptype, 'notend', j)
					call insert(g:plinen, 0, j)
					break
				else
					"if g:pindent[j] == noteindent
					if g:ptype[j] == 'blockquote' && g:pindent[j] == noteindent
						let g:ptype[j] = 'p'
					endif
				endif
				let j += 1
			endwhile

		endif
		let i += 1
	endwhile
	" }}}
	" Detect and create transitions (<hr>) {{{
	let i = 0
	for par in g:paras
		if i < len(g:paras)
			if g:paras[i] !~ '\n' && g:paras[i] =~ '^\s*'.s:vst_headdef.'\s*$'
				if g:ptype[i] !~ '^pre'
					let g:ptype[i] = 'hr'
					let class = VST_AddClass(i, 1, '', '')
					let g:paras[i] = substitute(g:paras[i], '.*', '\n<vim:hr '.class.'/>\n', '')
				endif
			endif
		endif
		let i += 1
	endfor
	" }}}
	" Detect blockquote paragraphs {{{
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'p' && g:pindent[i] > g:pindent[i-1]
			if g:ptype[i] !~ '^pre' && g:ptype[i-1] !~ '^MED' && g:ptype[i-1] !~ 'optlist'
				let g:ptype[i] = 'blockquote'
			endif
			if g:ptype[i-1] =~ '^MED' && g:pindent[i] > g:pindent[i-1] + 3
				let g:ptype[i] = 'blockquote'
			endif
		endif
		let i += 1
	endwhile
	" }}}
	" Detect if par is a header (<hx>) {{{
	let i = 0
	let h1 = ''
	let h2 = ''
	let h3 = ''
	let h4 = ''
	let h5 = ''
	while i < len(g:paras)
		if g:ptype[i] !~ '^pre'
			if g:paras[i] =~ '\n\s*'.s:vst_headdef.'\s*\(\n\|$\)' && g:ptype[i] !~ 'table' && g:paras[i] !~ 'vim:comment'
				let parlines = split(g:paras[i], '\n')
				if parlines[1] =~ '^\s*'.s:vst_headdef.'\s*$'
					let double = ' '
				elseif parlines[0] == parlines[2] && parlines[0] =~ '^\s*'.s:vst_headdef.'\s*$' 
					let double = 'd'
					call remove(parlines, 0)
				endif
				let lchar = matchstr(parlines[1], '.\ze\s*$').double
				if lchar =~ s:vst_headchars
					if h1 == '' || lchar == h1
						let h1 = lchar
						let g:ptype[i] = 'h1'
					elseif h2 == '' || lchar == h2
						let h2 = lchar
						let g:ptype[i] = 'h2'
					elseif h3 == '' || lchar == h3
						let h3 = lchar
						let g:ptype[i] = 'h3'
					elseif h4 == '' || lchar == h4
						let h4 = lchar
						let g:ptype[i] = 'h4'
					elseif h5 == '' || lchar == h5
						let h5 = lchar
						let g:ptype[i] = 'h5'
					else
						let g:ptype[i] = 'h6'
					endif
					let modlchar = substitute(lchar, '[d ]', '', 'g')
					let g:vst_headers[g:ptype[i]] = repeat(modlchar, 9).double

					if len(parlines) > 2
						let g:paras[i] = join(parlines[0:1], "\n")
						call insert(g:paras, join(parlines[2:], "\n"), i+1)
						call insert(g:pindent, g:pindent[i], i+1)
						call insert(g:plinen, 0, i+1)

						if parlines[2] =~ '^\s*(\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\))\s'
							" LISTDEF:
							call insert(g:ptype, 'oli', i+1)
						elseif parlines[2] =~ '^\s*\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s'
							" LISTDEF:
							call insert(g:ptype, 'oli', i+1)
						elseif parlines[2] =~ '^\s*'.s:vst_bulletdef.'\s'
							call insert(g:ptype, 'uli', i+1)
						elseif parlines[2] =~ '^\s*:.\{-1,}:\(\s\+\|$\)'
							call insert(g:ptype, 'field', i+1)
						elseif parlines[2] =~ '^\s*::\s*$'
							call insert(g:ptype, 'emptypre', i+1)
						elseif parlines[2] =~ '^\s*| '
							call insert(g:ptype, 'verse', i+1)
						elseif parlines[2] =~ '^\s*+-\{3,}'
							call insert(g:ptype, 'table', i+1)
						elseif parlines[2] =~ '^\s*+=\{3,}'
							call insert(g:ptype, 'bltable', i+1)
						elseif parlines[2] =~ '^\s*\(--\|-\|/\|:\|+\)\S.\{-}\(  \|$\)' && doc[line] !~ '^\s*\(--\s\|:\S\+:`\)'
							call insert(g:ptype, 'optlist', i+1)
						elseif parlines[2] =~ '^\s*>>>'
							call insert(g:ptype, 'doctest', i+1)
						elseif parlines[2] =~ '^\s*=\{2,}\s\+=\{2,}'
							call insert(g:ptype, 'simpletbl', i+1)
						else
							" Everything after ornament put into next
							" paragraph sub type. Ugly but prevents worse
							" things.
							call insert(g:ptype, 'sub'.g:ptype[i], i+1)
						endif
					else
						let g:paras[i] = join(parlines, "\n")
					endif
				endif
			endif
		endif
		let i += 1
	endwhile
	" }}}
" Formatting
" Create dl paragraph {{{
if string(g:ptype) =~ "'dl'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'dl'
		"let initind = strlen(matchstr(g:paras[i], '\n\zs\s*\ze.\{-}'))
		let parlines = split(g:paras[i], '\n')
		let initind = strlen(matchstr(parlines[-1], '^\s*'))
		let j = i + 1
			while j < len(g:paras)
				if g:pindent[j] < initind || g:ptype[j] == 'blank'
					let newind = repeat(' ', g:pindent[j])
					call insert(g:paras, newind.'</vim:dd>'."\n".newind.'</vim:dl>', j)
					call insert(g:pindent, g:pindent[i], j)
					call insert(g:ptype, 'dlend', j)
					call insert(g:plinen, 0, j)

					call insert(g:paras, repeat(' ', g:pindent[i]).'<vim:dl'.VST_AddClass(i,1,' ','').'>', i)
					call insert(g:pindent, g:pindent[i], i)
					call insert(g:ptype, 'dlbegin', i)
					call insert(g:plinen, 0, i)

					" Recompensate paragraph inserted before current position.
					let i += 1

					break
				else
					if g:ptype[j] == 'blockquote'
						if g:pindent[j] == initind
							let g:ptype[j] = 'p'
						endif
					endif

				endif
				let j += 1
			endwhile
			
		endif
		let i += 1
	endwhile
endif
" }}}
" Detect and pre-prepare definition list (<dl>) {{{
if string(g:ptype) =~ "'dl'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'dl'
			let defterm = matchlist(g:paras[i], '^\(.\{-}\n\)\(\s*\)\(.*\)')
			let defpar = split(substitute(defterm[3], '\n\s*', '\n', 'g'), "\n")
			let defterm[1] = VST_SpecCharacter(defterm[1])
			let defpart = "\n".'<vim:dt class="normal">'.defterm[1].'</vim:dt>'."\n".defterm[2].'<vim:dd class="normal">'."\n".defterm[2]
			let g:paras[i] = defpart.VST_Structure(defpar)
		endif
		let i += 1
	endwhile
endif
" }}}
" Prepare quoted literal paragraphs (:: <! etc.) {{{
" This can be only one paragraph so don't worry about other pre troubles
if string(g:ptype) =~ "'prequoted'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'prequoted'
			" In pre paragraphs special characters also have to be
			" escaped.
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			" Prevent splitting for auto footnotes and hyperlinks
			let g:paras[i] = substitute(g:paras[i], '\[', '\&#91;', 'g') 
			let g:paras[i] = substitute(g:paras[i], '_', '\&#95;', 'g') 

			if g:paras[i-3] =~ '^\s*::\s*$'
				let g:paras[i] = '<vim:pre class="quoted'.VST_AddClass(i-3, 0, ' ', '').'">'
					\."\n".g:paras[i]."\n".'</vim:pre>'
			else
				let g:paras[i] = '<vim:pre class="quoted">'."\n".g:paras[i]
					\."\n".'</vim:pre>'
			endif

		endif
		let i += 1
	endwhile
endif
	" }}}
" Create option list paragraph {{{
if string(g:ptype) =~ "'optlist'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'optlist'
			" Detect indentation of option list
			let listindent = strlen(matchstr(g:paras[i], '^\s*\zs\(--\|-\|/\|:\|+\)\S.\{-}  \s*'))
			let j = i + 1
			while j < len(g:paras)
				if g:pindent[j] <= g:pindent[i] || g:ptype[j] == 'blank'
					let newind = repeat(' ', g:pindent[j])
					call insert(g:paras, newind.'</vim:dd>'."\n".newind.'</vim:dl class="option'.VST_AddClass(i,0, ' ','').'">', j)
					call insert(g:pindent, g:pindent[i], j)
					call insert(g:ptype, 'optend', j)
					call insert(g:plinen, 0, j)

					call insert(g:paras, repeat(' ' , g:pindent[i]).'<vim:dl class="option'.VST_AddClass(i,0, ' ','').'">', i)
					call insert(g:pindent, g:pindent[i], i)
					call insert(g:ptype, 'optbegin', i)
					call insert(g:plinen, 0, i)

					" Recompensate inserted paragraph before current position.
					let i += 1

					break
				else
					if g:ptype[j] == 'blockquote'
						if g:pindent[j] == g:pindent[i] + listindent
							let g:ptype[j] = 'p'
						endif
					endif

				endif
				let j += 1
			endwhile
			
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			let g:paras[i] = substitute(g:paras[i], '^\(\s*\)\(--\|-\|/\|:\|+\)\(\S.\{-}\)  ', '\n<vim:dt class="option">\2\3</vim:dt>\n\1<vim:dd class="option">\n\1<vim:p>', '')
			let g:paras[i] = substitute(g:paras[i], '\n\(\s*\)\(--\|-\|/\|:\|+\)\(\S.\{-}\)  ', '</vim:p></vim:dd>\n\1<vim:dt class="option">\2\3</vim:dt>\n\1<vim:dd class="option">\n\1<vim:p>', 'g')
			let g:paras[i] = substitute(g:paras[i], '$', '</vim:p>', '')
		endif
	let i += 1
	endwhile
endif
" }}}
" Create field list {{{
if string(g:ptype) =~ "'field'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'field'
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			let parlines = split(g:paras[i], '\(^\s*\|\n\s*\):\@=')
			let j = 0
			for parline in parlines
				let fkey = tolower(matchstr(parlines[j], '^\s*:\zs.\{-}\ze:'))
				let fcontent = matchstr(parlines[j], '^\s*:.\{-}:\s*\zs.*')
				if fkey == 'date' && fcontent == 'NONE'
					let parlines[j] = ''
				endif
				if fkey != ''
					let g:vst_fielddb[fkey] = fcontent
				endif
				let parlines[j] = substitute(parlines[j], '^\s*:', '<vim:dt class="field">', '')
				let parlines[j] = substitute(parlines[j], '\(vim\)\@<!:', ':</vim:dt><vim:dd class="field">', '')
				let parlines[j] .= '</vim:dd>'."\n"
				let parlines[j] = substitute(parlines[j], '\c\(class="field">\)\(organization\|date\|status\|revision\|version\|dedication\|abstract\|copyright\)', '\1\u\2', 'g')
				" Adjustments for special types of fields: dedication, abstract
				" Has to wait for fixing MEDding of field lists
				let parlines[j] = substitute(parlines[j], 'class="field">Dedication:</vim:dt><vim:dd class="field">', 'class="field fdedication">Dedication</vim:dt><vim:dd class="field fdedication">','')
				let parlines[j] = substitute(parlines[j], 'class="field">Abstract:</vim:dt><vim:dd class="field">', 'class="field fabstract">Abstract</vim:dt><vim:dd class="field fabstract">','')
				let j += 1
			endfor
			let g:paras[i] = join(parlines, "\n")
			let g:paras[i] = '<vim:dl class="field'.VST_AddClass(i,0, ' ', '').'">'.g:paras[i]
			let g:paras[i] = substitute(g:paras[i], '\(Address:</vim:dt><vim:dd class="field">\)\(.\{-}\)</vim:dd>', '\=submatch(1)."<vim:pre class=\"address\">".substitute(submatch(2), "\\(^\\|\\n\\)\\s\\+", "\\n", "g")."</vim:pre></vim:dd>"','g')
			if has('unix')
				" On unices above substitute leaves ^M intead of new line, replace
				" it with real new line
				let g:paras[i] = substitute(g:paras[i], '\%d13', '\n', 'g')
			endif
			let g:paras[i] .= '</vim:dl>'

		endif
		let i += 1
	endwhile
endif
" }}}
" Parse meta paragraphs (.. meta::) {{{
" Loop creates database, it will be parsed in exports accordingly to its
" syntax
if string(g:ptype) =~ "'meta'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'meta'
			let parlines = split(g:paras[i], '\(^\s*\|\n\s*\):\@=')
			let j = 0
			for parline in parlines
				let mkey = tolower(matchstr(parlines[j], '^\s*:\zs.\{-}\ze:'))
				let mcontent = matchstr(parlines[j], '^\s*:.\{-}:\s*\zs.*')
				if mkey != ''
					let g:vst_metadb[mkey] = mcontent
				endif
				let j += 1
			endfor
			let g:paras[i] = ''
		endif
		let i += 1
	endwhile
endif
" }}}
" Create image paragraphs (.. image::) {{{
if string(g:ptype) =~ "'img'"
	let i = 0
	while i < len(g:paras)-1 
		if g:ptype[i] == 'img'
			let g:paras[i] = VST_ImagePar(g:paras[i], 1)
		endif
		let i += 1
	endwhile
endif
" }}}
" Create comment paragraph - comment (.. comment::) {{{
if string(g:ptype) =~ "'comment'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'comment'
			let g:paras[i] = '<vim:comment>'.substitute(g:paras[i], '^\s*\.\. comment::', '', '').'</vim:comment>'
		endif
		let i += 1
	endwhile
endif
" }}}
" Create rubric paragraph (.. rubric::) {{{
if string(g:ptype) =~ "'rubric'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'rubric'
			if g:paras[i] =~ ':class:'
				let class = matchstr(g:paras[i], ':class:\s*\zs.*\ze\s*$')
				let g:paras[i] = substitute(g:paras[i], '\s*:class:.*$', '', '')
				let g:paras[i] = '<vim:rubric class="'.class.'">'.substitute(g:paras[i], '\s*\.\. rubric::', '', '').'</vim:rubric>'
			else
				let g:paras[i] = '<vim:rubric'.VST_AddClass(i, 1, ' ', '').'>'.substitute(g:paras[i], '\s*\.\. rubric::', '', '').'</vim:rubric>'
			endif
		endif
		let i += 1
	endwhile
endif
" }}}
" Create ul paragraph {{{
if string(g:ptype) =~ "'uli'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'uli'
			" LISTDEF:
			" Detect style of unordered list
			let style = matchstr(g:paras[i], '^\s*\zs'.s:vst_bulletdef.'\s\+')
			let listindent = strlen(matchstr(g:paras[i], '^\s*\zs'.s:vst_bulletdef.'\s\+'))
			if style =~ '+'
				let ustyle = 'square'
			elseif style =~ '\*'
				let ustyle = 'circle'
			elseif style =~ '-'
				let ustyle = 'disc'
			else
				let ustyle = 'disc'
			endif
			let j = i + 1
			while j < len(g:paras)
				if g:pindent[j] <= g:pindent[i] || g:ptype[j] == 'blank' || g:ptype[j] == 'hr'
					let newind = repeat(' ', g:pindent[j])
					call insert(g:paras, newind.'</vim:li>'."\n".newind.'</vim:ul class="'.ustyle.VST_AddClass(i,0,' ','').'">', j)
					call insert(g:pindent, g:pindent[i], j)
					call insert(g:ptype, 'ulend', j)
					call insert(g:plinen, 0, j)

					call insert(g:paras, repeat(' ' , g:pindent[i]).'<vim:ul class="'.ustyle.VST_AddClass(i,0,' ','').'">', i)
					call insert(g:pindent, g:pindent[i], i)
					call insert(g:ptype, 'ulbegin', i)
					call insert(g:plinen, 0, i)

					" Recompensate inserted paragraph before current position.
					let i += 1

					break
				else
					if g:ptype[j] == 'blockquote'
						if g:pindent[j] == g:pindent[i] + listindent
							let g:ptype[j] = 'p'
						endif
					endif

				endif
				let j += 1
			endwhile
			
			if ustyle == 'disc'
				" Potential danger: this also includes * and +
				let elements = split(g:paras[i], '\(^\|\n\)\s*[\u2022\u2023\u2043\u204c\u204d\u25d8\u25e6\u2619\u2765\u2767-]\s\+')
			elseif ustyle == 'circle'
				let elements = split(g:paras[i], '\(^\|\n\)\s*\*\s\+')
			elseif ustyle == 'square'
				let elements = split(g:paras[i], '\(^\|\n\)\s*+\s\+')
			endif
			for inc in range(len(elements))
	let s:vst_bulletdef = '[\u2022\u2023\u2043\u204c\u204d\u25d8\u25e6\u2619\u2765\u2767*+-]'
				let elements[inc] = substitute(elements[inc], '\n\s*', '\n', 'g')
				let elements[inc] = VST_Structure(split(elements[inc], "\n"))
			endfor
			let g:paras[i] = '<vim:li>'.join(elements, "</vim:li>\n<vim:li>")

		endif
	let i += 1
	endwhile
endif
" }}}
" Create ol paragraph {{{
if string(g:ptype) =~ "'oli'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'oli'
			" Detect style of ordered list
			" LISTDEF:
			let style = matchstr(g:paras[i], '^\s*(\?\zs\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)\ze[\]:.)}]\s*')
			let listindent = strlen(matchstr(g:paras[i], '^\s*(\?\zs\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s*'))
			if style =~ '^\(I\|[ICDVLMX]\{2,}\)$'
				let ostyle = 'upperroman'
			elseif style =~ '^\(i\|[icdvlmx]\{2,}\)$'
				let ostyle = 'lowerroman'
			elseif style =~ '[a-z]'
				let ostyle = 'loweralpha'
			elseif style =~ '[A-Z]'
				let ostyle = 'upperalpha'
			elseif style =~ '[0-9#]'
				let ostyle = 'decimal'
			endif
			let j = i + 1
			while j < len(g:paras)
				if g:pindent[j] <= g:pindent[i] || g:ptype[j] == 'blank' || g:ptype[j] == 'hr'
					call insert(g:paras, repeat(' ' , g:pindent[j]).'</vim:li>'.repeat(' ' , g:pindent[j]).'</vim:ol class="'.ostyle.VST_AddClass(i,0,' ','').'">', j)
					call insert(g:pindent, g:pindent[i], j)
					call insert(g:ptype, 'olend', j)
					call insert(g:plinen, 0, j)

					" Get number of first element
					" LISTDEF:
					let start = tolower(matchstr(g:paras[i], '^\s*(\?\zs\(\d\+\|[icdvlmxICDVLMX]\+\|[a-zA-Z]\|#\)\ze'))
					if start == '1' || start == 'a' || start == '#' || start == 'i'
						let number = ''
					elseif start =~ '[0-9]'
						let number = ' start="'.start.'"'
					elseif start =~ '[icdvlmx][icdvlmx]'
						let rtable = split(start, '\ze.')
						let j = 0
						while j < len(rtable)
							if rtable[j] == 'i'
								let rtable[j] = 1
							elseif rtable[j] == 'v'
								let rtable[j] = 5
							elseif rtable[j] == 'x'
								let rtable[j] = 10
							elseif rtable[j] == 'l'
								let rtable[j] = 50
							elseif rtable[j] == 'c'
								let rtable[j] = 100
							elseif rtable[j] == 'd'
								let rtable[j] = 500
							elseif rtable[j] == 'm'
								let rtable[j] = 1000
							endif
							let j += 1
						endwhile
						let j = 0
						while j < len(rtable)
							if get(rtable, j+1) != 0 && rtable[j] < rtable[j+1]
								let rtable[j] = rtable[j] * -1
							endif
							let j += 1
						endwhile
						
						exe 'let total = '.join(rtable, '+')
						let number = ' start="'.total.'"'
					else
						let number = ' start="'.(char2nr(start)-96).'"'
					endif

					call insert(g:paras, repeat(' ' , g:pindent[i]).'<vim:ol class="'.ostyle.VST_AddClass(i,0,' ','').'"'.number.'>', i)
					call insert(g:pindent, g:pindent[i], i)
					call insert(g:ptype, 'olbegin', i)
					call insert(g:plinen, 0, i)

					" Recompensate inserted paragraph before current position.
					let i += 1

					break
				else
					if g:ptype[j] == 'blockquote'
						if g:pindent[j] == g:pindent[i] + listindent
							let g:ptype[j] = 'p'
						endif
					endif
				endif
				let j += 1
			endwhile

			" LISTDEF:
			
			let space = matchstr(g:paras[i], '^\s*')
			if ostyle == 'upperroman'
				let elements = split(g:paras[i], '\(^\|\n\)\s*(\?\(I\|[ICDVLMX]\{2,}\|#\)[\]:.)}]\s*')
			elseif ostyle == 'lowerroman'
				let elements = split(g:paras[i], '\(^\|\n\)\s*(\?\(i\|[icdvlmx]\{2,}\|#\)[\]:.)}]\s*')
			elseif ostyle == 'loweralpha'
				" Allow max 2 characters for "head" of alpha lists. It will give
				" enough combinations withoug allowing for messing with content
				let elements = split(g:paras[i], '\(^\|\n\)\s*(\?[a-z#]\{,2}[\]:.)}]\s*')
			elseif ostyle == 'upperalpha'
				let elements = split(g:paras[i], '\(^\|\n\)\s*(\?[A-Z#]\{,2}[\]:.)}]\s*')
			elseif ostyle == 'decimal'
				let elements = split(g:paras[i], '\(^\|\n\)\s*(\?[0-9#]\+[\]:.)}]\s*') 
			endif
			for inc in range(len(elements))
				let elements[inc] = substitute(elements[inc], '\n\s*', '\n', 'g')
				let elements[inc] = VST_Structure(split(elements[inc], "\n"))
			endfor
			let g:paras[i] = '<vim:li>'.join(elements, "</vim:li>\n<vim:li>")

		endif
	let i += 1
	endwhile
endif
" }}}
" Create internal anchors - intlink (.. _blah blah:){{{
if string(g:ptype) =~ "'intlink'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'intlink'
			" Testing for links broken into multiple lines
			if len(substitute(g:paras[i], '^\s*\.\. _.\{-}:\_s*', '', '')) == 0
				let title = tolower(matchstr(g:paras[i], '^\s*\.\. _\zs.\{-}\ze:'))
				let g:paras[i] = "\n".'<vim:p id="l'.VST_IdMaker(title).'"></vim:p>'."\n"
			else
				let g:paras[i] = ''
			endif
		endif
		let i += 1
	endwhile
endif
" }}}
" Create table of contents - toc (.. contents::) {{{
if string(g:ptype) =~ "'toc'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'toc'
			let b:IsTOC = 1
			if matchstr(g:paras[i], '\n\s*:depth:') != ''
				" This juggling is necessary to make corrections on different
				" treating of TOC levels in LaTeX and HTML.
				let depth = matchstr(g:paras[i], '\n\s*:depth:\s*\zs\d\+\ze') + 1
				let s:vst_tocdepth = depth - 1
				let g:paras[i] = substitute(g:paras[i], '\s*:depth:.\{-}\(\n\|$\)', '', 'g')
			endif
			if matchstr(g:paras[i], '\n\s*:class:') != ''
				let tocclass = 'toc '.VST_IdMaker(matchstr(g:paras[i], '\n\s*:class:\s*\zs.\{-1,}\ze\s*\(\n\|$\)'))
				let g:paras[i] = substitute(g:paras[i], '\s*:class:.\{-}\(\n\|$\)', '', 'g')
			else
				let tocclass = 'toc'
			endif
			if matchstr(g:paras[i], '::\s*\zs.\{-}\ze\(\n\|$\)') != ''
				" Alternative title of toc
				let toc = '<vim:p id="tocheader" class="'.tocclass.'">'.matchstr(g:paras[i], '::\s*\zs.\{-}\ze\(\n\|$\)')."<\/vim:p>\n"
			else
				let toc = "<vim:p id=\"tocheader\" class=\"".tocclass."\">Contents<\/vim:p>\n"
			endif
			let toc .= "<vim:ul class=\"".tocclass."\">\n"
			let j = 0
			while j < len(g:paras)
				if g:ptype[j] =~ '^h\d'
					let hdepth = strpart(g:ptype[j], '1')
					if exists('depth') && depth != ''
						if hdepth > depth
							let j += 1
							continue
						endif
					endif
					let g:paras[j] = VST_SpecCharacter(g:paras[j])
					let stitle = matchstr(g:paras[j], '^\s*\zs.*\ze\n')
					let htitle = VST_IdMaker(tolower(stitle))
					let tocli = repeat(' ', hdepth).'<vim:li class="'.g:ptype[j].'" id="toc-l'.htitle.'"><vim:a href="#l'.htitle.'">'.stitle.'</vim:a></vim:li>'
					let toc .= tocli."\n"
				endif
				let j += 1
			endwhile
			let toc .= "<\/vim:ul class=\"toc\">\n<vim:!--.. comment:: end of toc -->"
			let g:paras[i] = toc
		endif
		let i += 1
	endwhile
endif
" }}}
" Create h[1-6] paragraphs {{{
let i = 0
while i < len(g:paras)
	if g:ptype[i] =~ '^h\d'
		if g:ptype[i] == 'h1' && !exists("g:vst_doc_title")
			let g:vst_doc_title = substitute(g:paras[i], '^.*\zs\n.*$', '', '')
		endif
		let g:paras[i] = VST_SpecCharacter(g:paras[i])
		let stitle = tolower(matchstr(g:paras[i], '^\s*\zs.*\ze\n'))
		let stitle = VST_IdMaker(stitle)
		let g:paras[i] = substitute(g:paras[i], '^.*\zs\n.*$', '</vim:'.g:ptype[i].'>', '')
		let g:paras[i] = substitute(g:paras[i], '^\s*', '\0<vim:'.g:ptype[i].VST_AddClass(i,1,' ','').' id="l'.stitle.'">', '')
	endif
	let i += 1
endwhile
" }}}
" Create document title (.. title::) {{{
if string(g:ptype) =~ "'title'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'title'
			let g:vst_doc_title = substitute(g:paras[i], '^\s*\.\. title::\s*', '', '')
			let g:paras[i] = ''
		endif
		let i += 1
	endwhile
endif
" }}}
" Create verse paragraphs ("| ") {{{
if string(g:ptype) =~ "'verse'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'verse'
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			let g:paras[i] = VST_CreateVerse(g:paras[i])

			let g:paras[i] = substitute(g:paras[i], '<vim:p class="verse', '\0'.VST_AddClass(i,0, ' ',''), '')
		endif
		let i += 1
	endwhile
endif
" }}}
" Create raw LaTeX paragraph (next after .. raw:: latex) {{{
if string(g:ptype) =~ "'rawlatexcontent'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'rawlatexcontent'
			let class = VST_AddClass(i,1, ' ', '')
			let g:paras[i] = "<vim:rawlatex".class.">\n".VST_ProtectLiteral(g:paras[i])."\n</vim:rawlatex>"
		endif
		let i += 1
	endwhile
endif
" }}}
" Create raw HTML paragraph (next after .. raw:: html) {{{
if string(g:ptype) =~ "'rawhtmlcontent'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'rawhtmlcontent'
			let g:paras[i] = "<vim:rawhtml>\n".VST_ProtectLiteral(g:paras[i])."\n</vim:rawhtml>"
		endif
		let i += 1
	endwhile
endif
" }}}
" Create raw both paragraph (next after .. raw:: <both>) {{{
if string(g:ptype) =~ "'rawbothcontent'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'rawbothcontent'
			let g:paras[i] = "<vim:rawboth>\n".g:paras[i]."\n</vim:rawboth>"
		endif
		let i += 1
	endwhile
endif
" }}}
" Create LaTeX only paragraph - latexonly (.. raw:: latex) {{{
if string(g:ptype) =~ "'latexonly'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'latexonly'
			let g:paras[i] = substitute(g:paras[i], '\(\s*\)$', '\n\1</vim:latexonly>', '')
			let g:paras[i] = substitute(g:paras[i], '^\(\s*\)\.\. latexonly::\s*\n', '\n\1<vim:latexonly>\n', '')
			let g:paras[i] = substitute(g:paras[i], '^\(\s*\)\.\. latexonly::', '\n\1<vim:latexonly>\n', '')
		endif
		let i += 1
	endwhile
endif
" }}}
" Create HTML only paragraph - htmlonly (.. raw:: html) {{{
if string(g:ptype) =~ "'htmlonly'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'htmlonly'
			let g:paras[i] = substitute(g:paras[i], '\(\s*\)$', '\n\1</vim:htmlonly>', '')
			let g:paras[i] = substitute(g:paras[i], '^\(\s*\)\.\. htmlonly::\s*\n', '\n\1<vim:htmlonly>\n', '')
			let g:paras[i] = substitute(g:paras[i], '^\(\s*\)\.\. htmlonly::', '\n\1<vim:htmlonly>\n', '')
		endif
		let i += 1
	endwhile
endif
" }}}
" Check and embrace paragraphs in blockquote tags {{{
if string(g:ptype) =~ "'blockquote'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'blockquote'
			let j = i + 1
			while j < len(g:paras)
				let noteindent = g:pindent[j] - g:pindent[i]
				if g:pindent[i] > g:pindent[j]  || g:ptype[j] == 'blank' || g:ptype[j] == 'notend'
					call insert(g:paras, repeat(' ' , g:pindent[i]).'</vim:blockquote>', j)
					call insert(g:pindent, g:pindent[i], j)
					call insert(g:ptype, 'blockend', j)
					call insert(g:plinen, 0, j)

					call insert(g:paras, repeat(' ' , g:pindent[i]).'<vim:blockquote'.VST_AddClass(i,1,' ', '').'>', i)
					call insert(g:pindent, g:pindent[i], i)
					call insert(g:ptype, 'blockbegin', i)
					call insert(g:plinen, 0, i)

					" Recompensate inserted paragraph before current position.
					let i += 1

					" Region embraced , now I have to take care about paragraph
					let g:ptype[i] = 'p'

					break

				endif
				let j += 1
			endwhile
		endif
	let i += 1
	endwhile
endif
" }}}
" Create table {{{
if string(g:ptype) =~ "'table'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] =~ 'table'
			let g:tclen = []
			let g:thash = {}
			let g:tabb = []
			let g:taba = []

			let lines = split(g:paras[i], '\n')
			let newrow = 0
			unlet! trow

			let line_count = 0
			let headfoot_counter = 0
			unlet! usedthead
			unlet! usedtfoot 

			for line in lines
				let row = substitute(line, '^\s*\|\s*$', '', 'g')
				if row =~ '^+'
					if exists('trow')

						let g:tabb += [deepcopy(trow)]

						let rl = 0
						while rl < len(trow)
							let trow[rl] = VST_SpecCharacter(trow[rl])
							let cell = split(trow[rl], "\n")
							let trow[rl] = VST_Structure(cell)
							let rl += 1
						endwhile
						
						let g:taba += [trow]

					endif
					if row =~ '^+=' && line_count > 0
						let headfoot_counter += 1
					endif
					" Add head/foot structure elements to the end of last cell in
					" row. Later switch order of elements by regexps.
					if headfoot_counter > 0 && !exists('usedthead') && !exists('usedtfoot')
						let g:taba[-1][-1] .= '</vim:thead>'
						let usedthead = 1
					endif
					if headfoot_counter > 1 && !exists('usedtfoot')
						let g:taba[-1][-1] .= '<vim:tfoot>'
						let usedtfoot = 1
					endif
					let g:hf = headfoot_counter
					let newrow = 1
					let g:thash[len(split(row, '+'))] = split(row, '+')
					continue
				else
					if newrow == 1
						let trow = split(row, '\(^\| \)|\( \|$\)')
						let newrow = 0
					else
						let tmprow = split(row, '\(^\| \)|\( \|$\)')
						let rl = 0
						while rl < len(tmprow)
							let trow[rl] .= "\n".tmprow[rl]
							let rl += 1
						endwhile
					endif
				endif
				let line_count += 1
			endfor


			" Get lengths of most standard cells in table, need this for testing
			" of cells for length if they are longer
			let g:tstandard = g:thash[max(keys(g:thash))]
			let tl = 0
			while tl < len(g:tstandard)
				let g:tclen += [len(g:tstandard[tl])]
				let tl += 1
			endwhile

			" Check relative sizes of table columns
			" I need this to declare widths of columns in LaTeX export
			exe 'let g:sum = '.join(g:tclen, '+')
			let g:sizes = []
			for col in g:tclen
				let colwidth = col*90/g:sum
				if len(colwidth) == 1
					let colwidth = '0'.colwidth
				endif
				let g:sizes += [colwidth]
			endfor

			" insertion of columns size for proper breaking of text in table cells
			let colnumber = join(g:sizes, '+').'+'

			let tl = 0
			let g:ctable = ''
			while tl < len(g:tabb)
				let trow = g:tabb[tl]
				let g:ctable .= '<vim:tr>'
				let cn = 0
				let tcc = cn
				while cn < len(trow)
					let cll = trow[cn]
					if stridx(cll, "\n") != -1
						let g:celllength = strlen(matchstr(cll, '^.\{-}\ze\n')) + 2
					else
						let g:celllength = strlen(cll) + 2
					endif
					let k = 0
					let tempst = 0
					while 1
						if k < 2
							let tempst += g:tclen[tcc+k] + k
						else
							let tempst += g:tclen[tcc+k] + 1
						endif
						if g:celllength == tempst
							if k > 0
								let tccplus = tcc + k
								exe 'let g:summa = '.join(g:sizes[tcc : tccplus], '+')
								if exists("g:vst_center_multicol") && g:vst_center_multicol != 1
									let g:ctable .= "<vim:td colspan=\"".(k+1)."\" summary=\"".g:summa."\">".g:taba[tl][cn]."</vim:td>"
								else
									let g:ctable .= "<vim:td colspan=\"".(k+1)."\" style=\"text-align: center;\" summary=\"".g:summa."\">".g:taba[tl][cn]."</vim:td>"
								endif
							else
								let g:ctable .= "<vim:td>".g:taba[tl][cn]."</vim:td>"
							endif
							let tcc += k
							break
						else
							let k += 1
							continue
						endif
					endwhile
					let tcc += 1
					let cn += 1
				endwhile
				let g:ctable .= "\n</vim:tr>"
				let tl += 1
			endwhile


			" Check if table is borderless
			if g:ptype[i] == 'bltable'
				let class = 'vstbless'
			else
				let class = 'vstborder'
			endif
			" Info about borders is awful abuse of summary...
			let ttable = "<vim:table class=\"".class.VST_AddClass(i,0,' ','')."\" summary=\"".class."coln".colnumber."\">\n".g:ctable."</vim:table>"

			if headfoot_counter > 0
				let ttable = substitute(ttable, '<vim:table[^>]*>', '\0\n<vim:thead>', '')
				let ttable = substitute(ttable, '\(</vim:thead>\)\(</vim:td>\n</vim:tr>\)', '\2\n\1\n', '')
			endif
			if headfoot_counter == 2
				let ttable = substitute(ttable, '<.vim:table>', '</vim:tfoot>\n\0', '')
				let ttable = substitute(ttable, '\(<vim:tfoot>\)\(</vim:td>\n</vim:tr>\)', '\2\n\1\n', '')
			endif

			let g:paras[i] = ttable

		endif
		let i += 1
	endwhile
	unlet! trow
	unlet! row
endif
" }}}
" Create subtitle paragraphs {{{
let i = 0
while i < len(g:paras)
	if g:ptype[i] =~ 'subh\d'
		let g:paras[i] = VST_SpecCharacter(g:paras[i])
		let g:paras[i] = "\n".repeat(' ', g:pindent[i]).'<vim:p class="'.g:ptype[i].'">'."\n".g:paras[i]
		" Remove last line of subtitle if this is ornament. 
		" Treatment of headers in reST is weird.
		let g:paras[i] = substitute(g:paras[i], '\n\s*'.s:vst_headdef.'\s*$', '', '')
		let g:paras[i] .= "\n".repeat(' ', g:pindent[i])."</vim:p>\n"
	endif
	let i += 1
endwhile
" }}}
" Doctest paragraphs {{{
if string(g:ptype) =~ "'doctest'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] == 'doctest'
			let class = VST_AddClass(i,1, ' ', '')
			let g:paras[i] = VST_SpecCharacter(g:paras[i])
			let g:paras[i] = "\n".repeat(' ', g:pindent[i])."<vim:pre".class.">\n".g:paras[i]
			let g:paras[i] .= "\n".repeat(' ', g:pindent[i])."</vim:pre>\n"
		endif
		let i += 1
	endwhile
endif
" }}}
" Simple table paragraphs {{{
if string(g:ptype) =~ "'simpletbl'"
	let i = 0
	while i < len(g:paras)

		if g:ptype[i] == 'simpletbl'

			unlet! usedthead
			unlet! usedtfoot
			unlet! usethead

			let plines = split(g:paras[i], '\n')
			let header = substitute(plines[0], '^\s\+', '', '')
			" Remove framing === === lines
			let plines = plines[1:-2]
			let usethead = 0
			for j in range(len(plines))
				let plines[j] = substitute(plines[j], '^\s\{'.g:pindent[i].'}', '', '')
				if plines[j] =~ '^\(=\{2,}\s*\)\+$'
					let usethead += 1
				endif
			endfor
			" Get width of cols {{{
			let cols = []
			for k in split(header, '[^=]=')
				let cols += [len(matchstr(header, '^=*\s*'))]
				let header = substitute(header, '^=*\s*', '', '')
			endfor
			" Due to nature of formatting last column may seem narrower than rest.
			" Add 1 to slightly recompense that.
			let cols[-1] += 1
			" Calculate percentage widths of columns.
			exe 'let total_width = '.join(cols, '+')
			let sizes = []
			for col in cols
				let colwidth = col*90/total_width
				if len(colwidth) == 1
					let colwidth = '0'.colwidth
				endif
				let sizes += [colwidth]
			endfor
			let col_desc = join(sizes, '+').'+'
			" }}}
			" Split plines into separate cells {{{
			let table = []
			for line in plines

				let trow = []

				for k in range(len(cols))
					if k == len(cols)-1
						let trow += [line]
					else
						let trow += [line[0:(cols[k]-1)]]
						let line = line[(cols[k]):]
					endif
				endfor

				let table += [trow]

			endfor
			" }}}
			" Now create real, multiline if necessary, cells {{{
			let rtable = []
			for k in range(len(table))

				let row = table[k]

				if k == 0
					let prevrow = ['-----']
				else
					let prevrow = table[k-1]
				endif

				if row[0] =~ '^\s*$'
					if prevrow[0] =~ '[-=]\{2,}'
						let addrow = 0
					else
						let addrow = 1
					endif
				else
					let addrow = 0
				endif

				if addrow == 0
					let temprow = []
					for j in range(len(cols))
						if row[j] !~ '^[=-]\{2,}'
							let temprow += [row[j]]
						elseif row[j] =~ '^=\{2,}'
							let temprow += ['-vst-thfelem-']
						endif
					endfor
					let rtable += [temprow]
				elseif addrow == 1
					for j in range(len(cols))
						if row[j] !~ '^[=-]\{2,}'
							let temprow[j] .= "\n".row[j]
						elseif row[j] =~ '^=\{2,}'
							let temprow += ['-vst-thfelem-']
						endif
					endfor
				endif

			endfor
			" }}}

			" Translate data structure into Vim reStructured Text markup
			" Go through cells, call Structure function, join().
			let class = VST_AddClass(i,0, ' ', '')
			let g:paras[i] = '<vim:table class="vstborder'.class."\" summary=\"vstbordercoln".col_desc."\">\n"

			" insert thead at the beginning
			if usethead > 0
				let g:paras[i] .= "<vim:thead>\n"
			endif
				
			for k in range(len(rtable))
				let row = rtable[k]

				if row == []
					let k += 1
					continue
				endif

				" Interpret text inside of cells looking for structures {{{
				for j in range(len(row))
					if row[j] =~ '^-vst-thfelem-$'
						let j += 1
						continue
					else
						let row[j] = VST_SpecCharacter(row[j])
						let cellt = split(row[j], "\n")
						" Remove in-frontal space from one-line cells to avoid
						" interpretation of text as blockquote
						"if len(cellt) == 1
						"	let cellt[0] = substitute(cellt[0], '^\s\+', '', '')
						"endif
						let row[j] = VST_Structure(cellt)
					endif
				endfor
				" }}}

				" Create marked text and add thead and tfoot when appropriate
				if usethead > 0 && !exists("usedthead") && join(row, '') =~ '^\(-vst-thfelem-\)\+$'
					let g:paras[i] .= "\n</vim:thead>\n"
					let usedthead = 1
					continue
				endif
				if usethead > 1 && exists("usedthead") && join(row, '') =~ '^\(-vst-thfelem-\)\+$'
					let g:paras[i] .= "\n<vim:tfoot>\n"
					unlet usedthead
					let usedtfoot = 1
					continue
				endif

				let g:paras[i] .= '<vim:tr><vim:td>'.join(row, '</vim:td><vim:td>').'</vim:td></vim:tr>'."\n"


			endfor

			if exists("usedtfoot")
				unlet usedtfoot
				let g:paras[i] .= "\n</vim:tfoot>\n"
			endif

			unlet! usedthead
			unlet! usedtfoot
			unlet! usethead

			let g:paras[i] .= '</vim:table>'

		endif
		let i += 1
	endwhile
endif
" }}}
" Create p paragraph {{{
let i = 0
while i < len(g:paras)
	if g:ptype[i] == 'p'
		let g:paras[i] = VST_SpecCharacter(g:paras[i])
		if g:paras[i] =~ '^\s\+---\?\s.*\S' && g:ptype[i+1] == 'blockend'
			let class = VST_AddClass(i,0, '', '')
			let g:paras[i] = "\n".repeat(' ', g:pindent[i])."<vim:p class=\"attribution".class."\">\n".g:paras[i]
		else
			let class = VST_AddClass(i,1, ' ', '')
			let g:paras[i] = "\n".repeat(' ', g:pindent[i])."<vim:p".class.">\n".g:paras[i]
		endif
		let g:paras[i] .= "\n".repeat(' ', g:pindent[i])."</vim:p>\n"
	endif
	let i += 1
endwhile
" }}}
" Insert raw files placeholders {{{
if string(g:ptype) =~ "'raw\(latex\|html\|both\)'"
	let i = 0
	while i < len(g:paras)
		if g:ptype[i] =~ '^raw\(latex\|html\|both\)$'
			if g:paras[i] =~ ':file:'
				let file = matchstr(g:paras[i], ':file:\s*\zs.*')
				let g:paras[i] = '-vst-raw-file-placeholder:'.VST_ProtectLiteral(file)
			else
				let g:paras[i] = ''
			endif
		endif
		let i += 1
	endwhile
endif
" }}}
" Insert MED-classes {{{
if string(g:ptype) =~ "'MED-class'"
	let i = 0
	while i < len(g:paras)
		if i == len(doc) - 1
			let nextline = i - 1
		else
			let nextline = i + 1
		endif
		if g:ptype[i] == 'MED-class' && g:ptype[nextline] != 'notend'
			let name = g:paras[i]
			let j = i + 1
			while j < len(g:paras)
				if g:ptype[j] == 'notend' && g:pindent[j] == g:pindent[i] && g:paras[j] =~ '^\s*<vim:class'.name
					let g:paras[j] = ''
					break
				else
					if g:ptype[j] !~ '^[uo]li$'
						let initial = matchstr(g:paras[j], '^\_s*\zs<vim:\w\+[^>]*>')
						if initial !~ 'class\s*=\s*[''"]'
							let final = substitute(initial, '\(/\)\?>', ' class="'.name.'" \1>', '')
						elseif initial =~ 'class\s*=\s*[''"]'
							let final = substitute(initial, '\(class\s*=\s*\)\([''"]\)\(.\{-}\)\2', '\1\2\3 '.name.'\2', '')
						endif
						let g:paras[j] = substitute(g:paras[j], initial, final, '')
					endif
					let j += 1
				endif
			endwhile
		endif
		let i += 1
	endwhile
endif
" }}}
" Nuke auxiliary elements {{{
let i = 0
while i < len(g:paras)
	if g:ptype[i] == 'link'
		let g:paras[i] = ''
	elseif g:ptype[i] == 'anonlink'
		let g:paras[i] = ''
	elseif g:ptype[i] == 'replacement'
		let g:paras[i] = ''
	elseif g:ptype[i] == 'rawhtml'
		let g:paras[i] = ''
	elseif g:ptype[i] == 'rawlatex'
		let g:paras[i] = ''
	elseif g:ptype[i] == 'rawboth'
		let g:paras[i] = ''
	elseif g:ptype[i] == 'emptypre'
		let g:paras[i] = ''
	elseif g:ptype[i] == 'role'
		let g:paras[i] = ''
	elseif g:ptype[i] == 'MED-class'
		let g:paras[i] = ''
	endif
	let i += 1
endwhile
" }}}
" Create markup {{{
let i = 0
while i < len(g:paras)
	" Careful checking if given construct exists in paragraph. 
	" BIG speed gains.
	if g:ptype[i] !~ '^pre\|^hr\|^blank'
		if g:paras[i] =~ '|'
			let g:paras[i] = VST_Replacement(g:paras[i])
		endif
		if g:paras[i] =~ '[*`=]'
			let g:paras[i] = VST_Markup(g:paras[i])
		endif
		if g:paras[i] =~ ':`' || g:paras[i] =~ '`:'
			let g:paras[i] = VST_Roles(g:paras[i])
		endif
		if g:paras[i] =~ '\[\d\+\]_'
			let g:paras[i] = VST_Footnotes(g:paras[i])
		endif
		if g:paras[i] =~ 'http' || g:paras[i] =~ 'mailto' || g:paras[i] =~ 'ftp'
			let g:paras[i] = VST_SA_Hyperlink(g:paras[i])
		endif
		if g:paras[i] =~ '\[#\k\+\]_'
			let g:paras[i] = VST_LabelFootnote(g:paras[i])
		endif
		if g:paras[i] =~ '\[\k\+\]_'
			let g:paras[i] = VST_Citations(g:paras[i])
		endif
	endif
	let i += 1
endwhile
" }}}
" Fixing! {{{
"
let file = join(g:paras, "\n")
" Remove commented content
" let file = substitute(file, '<vim:comment>.\{-}</vim:comment>', '', 'g')
" Remove replacement placeholders
let file = substitute(file, '{-vst-replace-{', '', 'g')
let file = substitute(file, '}-vst-replace-}', '', 'g')
" Glueing together dl
let file = substitute(file, '</vim:dl>\_s\{-}<vim:dl.\{-}>', '', 'g')
" Remove li to embed lists
let file = substitute(file, '</vim:li>\(\_s\{-}<vim:[uo]l\)', '\1', 'g')
" Glueing ol and ul
let file = substitute(file, '\(<vim:li><vim:p class="\)firstli\(">\_.\{-}</vim:p>\_s*</vim:li>\_s*<vim:li\)', '\1onlyli\2', 'g')
let file = substitute(file, '</vim:ul class="\([^"]*\)">\_s*<vim:ul class="\1[^>]*>', '', 'g')
let file = substitute(file, '</vim:ul class="\(\w\+\)[^"]\{-}">\_s*<vim:ul class="\1[^>]*>', '', 'g')
let file = substitute(file, '</vim:ul class="\%(circle\|square\|disc\)">', '</vim:ul>', 'g')
let file = substitute(file, '</vim:ol class="\([^"]*\)">\_s*<vim:ol class="\1[^>]*>', '', 'g')
" This one can have bad influence on consecutive ol lists with different
" numbering
let file = substitute(file, '</vim:ol class="\(\w\+\)[^"]\{-}">\_s*<vim:ol class="\1[^>]*>', '', 'g')
let file = substitute(file, '</vim:ol class=".\{-}>', '</vim:ol>', 'g')
let file = substitute(file, '</vim:ul class=".\{-}">', '</vim:ul>', 'g')
" Removing redundant \n
let file = substitute(file, '\_s*</vim:pre>', '\n</vim:pre>\n', 'g')
let file = substitute(file, '\n\n\n\(\s*\)<vim:p', '\n\n\1<vim:p', 'g')
let file = substitute(file, '\n\n\n\(\s*\)<vim:pre', '\n\n\1<vim:pre', 'g')
let file = substitute(file, '\n\s*</vim:dt>', '</vim:dt>', 'g')
" Remove double :: at the end of paragraphs indicating code in next.
let file = substitute(file, '::\(\_s*</vim:p>\)', ':\1', 'g')
" Remove double :: when it was the only element after list indicator
let file = substitute(file, '<vim:li><vim:p class="\%(first\|only\)li">\s*:</vim:p>', '<vim:li>', 'g')
" Remove empty pre paragraphs
let file = substitute(file, '<vim:pre[^>]\{-}>\n</vim:pre>', '', 'g')
" Remove links created inside of image src
let file = substitute(file, '<\(vim:\)\?img\([^>]\{-}\)src="<vim:a href=".\{-}">\([^<]*\)</vim:a>"', 
			\ '<\1img\2src="\3"', 'g')
" let file = substitute(file, ' 	 	 \n', '', 'g')
" Remove too much of empty space at the end of footnotes
let file = substitute(file, '\n\(</vim:div></vim:footnote>\)', '\1', 'g')


" }}}
" Restore structure from temporary variables {{{
if len(g:paras_rez) > 0
	let g:paras = g:paras_rez[-1]
	call remove(g:paras_rez, -1)
endif
if len(g:ptype_rez) > 0
	let g:ptype = g:ptype_rez[-1]
	call remove(g:ptype_rez, -1)
endif
if len(g:pindent_rez) > 0
	let g:pindent = g:pindent_rez[-1]
	call remove(g:pindent_rez, -1)
endif
if len(g:plinen_rez) > 0
	let g:plinen = g:plinen_rez[-1]
	call remove(g:plinen_rez, -1)
endif
" }}}

return file

" End of VST_Structure
endfunction

function! vst#vst#VST_Export(line1, line2, format) range " {{{

" VST_DictTable: creation of nice looking table from dictionary {{{
" Description: Go through all key value pairs and create nicely looking table
" 	db: dictionary itself
"   key: header of key column
"   value: header of value column
"   sort: 0/1 sort table or not
function! VST_DictTable(db, key, value, sort)

	let valmargin = 20
	let dict = a:db
	let table = a:key.repeat(' ', valmargin-strlen(a:key)).a:value."\n"
	if a:sort == 0
		for key in keys(dict)
			if dict[key] !~ '^\s*$'
				if valmargin - strlen(key) < 1
					let table .= key."\n".repeat(' ', valmargin).substitute(dict[key], '\n', ' ', 'g')."\n"
				else
					let table .= key.repeat(' ', valmargin - strlen(key)).substitute(dict[key], '\n', ' ', 'g')."\n"
				endif
			endif
		endfor
	else
		for key in sort(keys(dict))
			if dict[key] !~ '^\s*$'
				if valmargin - strlen(key) < 1
					let table .= key."\n".repeat(' ', valmargin).substitute(dict[key], '\n', ' ', 'g')."\n"
				else
					let table .= key.repeat(' ', valmargin - strlen(key)).substitute(dict[key], '\n', ' ', 'g')."\n"
				endif
			endif
		endfor
	endif

	"return table
	call input(table)
	"echo table

endfunction
" }}}
" VST_TocTable: creation of nice looking table of contents {{{
" Description: Go through all 3 element items in list and render them in
" nicely looking table
" 	list: list itself
"   fcol: header of first column
"   scol: header of second column
"   tcol: header of third column
"   sinfo: special info
function! VST_TocTable(list, fcol, scol, tcol, sinfo)

	let secmargin = 15
	let thdmargin = 40
	let table = a:fcol.repeat(' ', secmargin-len(a:fcol))
		\ .a:scol.repeat(' ',thdmargin-len(a:scol)).a:tcol."\n"

	let i = 0
	while i < len(a:list)
		let [level, title, line] = a:list[i]
		let title = substitute(title, '\n.\{-}$', '', '')
		" Add a markers around name of section were cursor is
		if !exists("a:list[i+1]")
			let nextsection = line('$')
		else
			let nextsection = a:list[i+1][2]
		endif
		let title = b:vst_toc_numbers[title].'   '.substitute(title, '^\s\+', '', '')
		if a:sinfo >= line && a:sinfo < nextsection
			let title = '[[[ '.title.' ]]]'
		endif
		let table .= level.' '.g:vst_headers[level].' '
			\ .repeat(' ', secmargin-len(level.g:vst_headers[level].'  '))
			\ .title.repeat(' ', thdmargin-len(title)).' '.line."\n"
		let i += 1
	endwhile

	return table

endfunction
" }}}
" VST_CreateDBs: creation of databases {{{
function! VST_CreateDBs(table)
	" Preprocess table to get class of role into the same line
	" Preprocessing here is nice idea for links, they don't have to be changed
	" physically in document, no messing with adding/removing lines. It slow
	" things down but more precise processing is Good Thing(tm)
	"     table: text to analyze in List form
	let preproc = a:table
	let i = 0
	while i < len(preproc)
		if i == len(preproc) - 1
			let nextline = i - 1
		else
			let nextline = i + 1
		endif
		if preproc[i] =~ '^\s*\.\. role:'
			if preproc[nextline] =~ '^\s*:class:'
				let preproc[i] = preproc[i].' -vst-role-'.preproc[nextline]
			else
				let preproc[i] = preproc[i].' -vst-role-'
			endif
		endif
		" Connect multiline link definitions
		if preproc[i] =~ '^\s*\(\.\. _\|__ \)' 
			if preproc[nextline] !~ '^\s*\(\.\. _\|__ \)' && preproc[nextline] !~ '^\s*$'
				let findent = strlen(matchstr(preproc[i], '^\s*'))
				let sindent = strlen(matchstr(preproc[nextline], '^\s*'))
				if (findent + 3) <= sindent
					let preproc[i] = substitute(preproc[i], '\s\+$', '', '')
						\.substitute(preproc[nextline], '^\s\+', '', '')
					call remove(preproc, nextline)
					" Turn counter down to process more than 2 lines 
					let i -= 1
				endif
			endif
		endif
		let i += 1
	endwhile

	for i in range(len(preproc))
		if preproc[i] =~ '^\s*\.\. _'
			" Hyperlink database
			let title = tolower(matchstr(preproc[i], '_\zs.\{-}\ze:'))
			let url = matchstr(preproc[i], '_.\{-}:\s*\zs.*')
			let k = 1
			while url == '' && len(preproc) > (i+k) && stridx(preproc[i+k], '_') > -1
					let url = matchstr(preproc[i+k], '_.\{-}:\s*\zs.*')
					let k += 1
			endwhile
			unlet! k
			if url =~ '@' && url !~ '^http\|^s\?ftp'
				let url = 'mailto:'.url
			endif
			if title != '' && title != '_'
				let g:vst_hlinkdb[title] = url
			endif
		elseif preproc[i] =~ '^\s*\.\. role'
			let rolekey = matchstr(preproc[i], 'role::\s*\zs.\{-}\ze\s*-vst-role-')
			let rolevalue = matchstr(preproc[i], '-vst-role-\s*:class:\s*\zs.*\ze\s*$')
			if rolevalue == ''
				let rolevalue = rolekey
			endif
			let g:vst_roledb[rolekey] = rolevalue
		endif
	endfor
	" Add embedded reusable URIs
	" I have to join and split file again to avoid problems with: links
	" splitted across lines and more than one link in line
	let dbfile = join(a:table)
	" This is done only for links, compress white space
	let dbfile = substitute(dbfile, '\s\+', ' ', 'g')
	let dbtable = split(dbfile, '>`_[^_]')
	let i = 0
	while i < len(dbtable)-1
		" Hyperlink database
		let expr= matchstr(dbtable[i], '.*`\zs.\{-}$')
		if expr =~ '^<'
			let title = tolower(matchstr(expr, '<\zs.*'))
		else
			let title = tolower(matchstr(expr, '\zs.\{-}\ze <.*$'))
		endif
		let url = matchstr(expr, ' <\zs.\{-}$')
		if url =~ '@' && url !~ '^http\|^ftp'
			let url = 'mailto:'.url
		endif
		if title != ''
			let g:vst_hlinkdb[title] = url
		endif
		let i += 1
	endwhile

endfunction
" }}}
" VST_FoldText: Create text for folds {{{
function! VST_FoldText()
	let text = getline(v:foldstart)
	let length = v:foldend - v:foldstart
	let indent = '+'.v:folddashes.repeat(' ', 5-len(length)).length
		\ .' lines: '
	let line = b:vst_fold_numbers[text].'   '.substitute(text, '^\s\+', '', '')
	let symbol = repeat(' ', 50-len(line)).'('
		\ .matchstr(getline(v:foldstart+1), '^\s*\zs...\ze').')'
	return indent.repeat(' ', 15-len(indent)).line.symbol.' '
endfunction
" }}}
" VST_ColNumbers: Create <col /> tags for HTML {{{
"    numbers - values for width of columns, String with + to separate numbers
function! VST_ColNumbers(numbers)
	let widths = split(a:numbers, '+')
	let col_string = ''
	for width in widths
		let col_string .= '<col width="'.width.'%" />'
	endfor
	return col_string
endfunction
" }}}

" Auxiliary functions: {{{
" Unicode2Char:	  Return char according to hex code {{{
"    nr - decimal value of Unicode character
function! Unicode2Char(nr)
	let n = join(reverse(split(tolower(a:nr), '.\zs')), '')

	let r = 0
	let i = 0
	while i <= len(n)
		if n[i] == 'a'
			let p = 10
		elseif n[i] == 'b'
			let p = 11
		elseif n[i] == 'c'
			let p = 12
		elseif n[i] == 'd'
			let p = 13
		elseif n[i] == 'e'
			let p = 14
		elseif n[i] == 'f'
			let p = 15
		else
			let p = n[i]
		endif

		if p == 0
			let fp = 0
		else
			exe 'let fp = '.repeat('16*', i).p
		endif

		let r += fp

		let i += 1
	endwhile
	return nr2char(r)
endfunction
" }}}
" VST_2html:		 Parse 2html directive {{{
" Description: Go through document looking for 2html directives, copy text of
" directive to new buffer and process it there with 2html.vim, at the end
" replace original text with colored text and additional <style> declaration.
function! VST_2html()
	silent call cursor(1,1)
	syntax on
	" Backup of important elements
	let bufnumber = bufnr('%')
	let z_rez = @z
	let y_rez = @y
	let @z = ''
	let @y = ''
	if exists('g:colors_name')
		let col_scheme = g:colors_name
	else
		let col_scheme = 'default'
	endif
	" Saving 2html.vim options {{{
	if exists('g:html_number_lines')
		let h_number_lines = g:html_number_lines
	else
		let h_number_lines = 2
	endif
	if exists('g:html_use_css')
		let h_use_css = g:html_use_css
	else
		let h_use_css = 2
	endif
	if exists('g:html_no_pre')
		let h_no_pre = g:html_no_pre
	else
		let h_no_pre = 2
	endif
	if exists('g:use_xhtml')
		let h_use_xhtml = g:use_xhtml
	else
		let h_use_xhtml = 2
	endif
	" }}}
	" And set values necessary for good work
	let g:html_number_lines = 0
	let g:html_use_css = 1
	let g:html_no_pre = 0
	let g:use_xhtml = 1
	if &compatible == 1
		set nocompatible
	endif
	if &splitbelow == 0
		let splitb = 0
		set splitbelow
	else
		let splitb = 1
	endif

	while search('<pre class="tohtml-[^"]\+">', 'W')
		let @z = ''
		let @y = ''
		let line = line('.')
		" Retrieve filetype and colorscheme data
		let data = matchstr(getline('.'), '<pre class="tohtml-\zs.\{-}\ze">')
		let darray = split(data, '----')
		let filetype = darray[0]
		if len(darray) > 1
			let cscheme = darray[1]
		endif
		let line2 = search('<\/pre>', 'W')
		" There may be situation, by an user error, omission, etc. 2html
		" directive will be empty. In that case silently quit.
		if line + 1 == line2
			return
		endif
		silent exe (line+1).','.(line2-1).' delete z'
		silent below 1new tmp-2html
		silent 0put z
		silent exe 'setlocal ft='.filetype
		if exists('cscheme')
			silent! exe 'colorscheme '.cscheme
		endif
		" I have to revert special characters because TOhtml will do it once
		" again destroing & entities
		" list: &lt;, &gt;, &copy;
		" How to prevent massacre of user used entities?
		" How probably they are in pre?
		%s/&lt;/</ge
		%s/&gt;/>/ge
		%s/&amp;/\&/ge
		" @-entity was treated literally by 2html.vim
		%s/&#64;/@/ge
		silent runtime syntax/2html.vim
		" Remove html headers, I don't need them inside of file
		" Still problem with style inside of body
		silent g+<!DOCTYPE\|</\?html\|</\?head>\|</\?pre>\|</\?body>\|</\?p>\|<title>\|<meta +d
		silent g+<?xml+d
		if exists('cscheme')
			silent exe 'g+^body+s+^body+.tohtml-'.filetype.'----'.cscheme.'+e'
		else
			silent exe 'g+^body+s+^body+.tohtml-'.filetype.'+e'
		endif
		" 2html.vim in full auto _always_ use html_no_pre = 1. Weird.
		silent %s/&#x20;/ /ge
		silent %s/<br\/>//ge
		" Restore @ -> &#64; to prevent mail harvesting
		silent %s/@/\&#64;/ge
		silent call cursor(1,1)
		silent /<style/,/<\/style/yank y
		let style = split(@y, '\n')
		let main_style = style[-3:-3]
		let main_style_name = split(main_style[0], ' ')[0]
		let style = style[2:-4]
		silent call map(style, "main_style_name.' '.v:val")
		let style = main_style + style
		if exists('g:vst_2html_css')
			let g:vst_2html_css += style
		else
			let g:vst_2html_css = style
		endif
		silent call cursor(1,1)
		silent normal! "zyG
		silent bwipeout! tmp-2html.html
		silent bwipeout! tmp-2html
		let @z = substitute(@z, '\n\+$', '', '')
		if exists('cscheme')
			let @z = substitute(@z, '.*</style>', '\n<pre class="tohtml-'.filetype.'----'.cscheme.'">', '')
		else
			let @z = substitute(@z, '.*</style>', '\n<pre class="tohtml-'.filetype.'">', '')
		endif
		silent exe 'buffer! '.bufnumber
		silent exe line
		silent! put z
		let line3 = line('.') - 1
		silent exe line
		silent delete
		silent exe line3
		unlet! cscheme
	endwhile

	" Restore settings
	let @z = z_rez
	let @y = y_rez
	if splitb == 0
		set nosplitbelow
	endif
	silent exe 'buffer! '.bufnumber
	silent exe 'colorscheme '.col_scheme
	" Restoring 2html.vim options {{{
	if h_number_lines == 2
		unlet g:html_number_lines
	else
		let g:html_number_lines = h_number_lines
	endif
	if h_use_css == 2
		unlet g:html_use_css
	else
		let g:html_use_css = h_use_css
	endif
	if h_no_pre == 2
		unlet g:html_no_pre
	else
		let g:html_no_pre = h_no_pre
	endif
	" }}} 

endfunction
" }}}
" VST_AddClass:	  Return class string if prev par is class (.. class::) {{{
" Description: Check previous paragraph and in case it is class return string
"	  class="classname", classname or ''.
"	  parnumber - number of described paragraph
"	  full - check if return full declaration or name only
"	  	1 - full declaration class="classname"
"	  	0 - name only
"	  pre - prefix
"	  post - suffix
function! VST_AddClass(parnumber, full, pre, post)
	" Escaping of special characters
	if g:ptype[a:parnumber-1] == 'notend' && g:ptype[a:parnumber-2] == 'MED-class'

		"let name = matchstr(g:paras[a:parnumber-2], '^\s*\.\. class::\s*\zs.\{-1,}\ze\s*$')
		let name = VST_IdMaker(g:paras[a:parnumber-2])
		if a:full == 1
			let class = 'class="'.name.'"'
		else
			let class = name
		endif
		let class = a:pre.class.a:post
	else
		let class = ''
	endif

	return class

endfunction
" }}}
" VST_AnonHyperlink: Create anonymous hyperlinks {{{
function! VST_AnonHyperlink(text)
	let parlines = split(a:text, '-vst-anon-hyperlink-')
	let i = 0
	let g:a0 = []
	while i < len(g:vst_anonhlinkdb) 
		if g:vst_anonhlinkdb[i] =~ '_\s*$'
			let href = g:vst_anonhlinkdb[i]
			let title = tolower(matchstr(href, '\(\.\. __ :\|__\)\s*\(`\?\)\zs.*\ze\2_\s*$'))
			while href =~ '_\s*$'
				" If ends in _ it is probably indirect link, process it.
				if has_key(g:vst_hlinkdb, title) && g:vst_hlinkdb[title] != ''
					let href = escape(g:vst_hlinkdb[title], '&\~')
				else
					let href = '#l'.VST_IdMaker(title)
				endif
			endwhile
		else
			let href = matchstr(g:vst_anonhlinkdb[i], '^\s*\(\.\. __:\|__\)\s*\zs.*')
		endif
		let g:a0 += [href]
		if i < len(parlines) - 1
			let parlines[i] .= href
		endif
		let i += 1
	endwhile
	let par = join(parlines, '')
	
	return par

endfunction
" }}}
" VST_AutoFootnote:  Create auto-numbered footnotes [#]_ {{{
function! VST_AutoFootnote(text)
	let parlines = split(a:text, '\[#]_')
	let i = 0
	let k = s:maxfnumber + s:maxlnumber + 1
	while i < len(parlines)-1
		let parlines[i] .= '<vim:a href="#footnote-'.k.'" name="target-'.k.'">['.k.']</vim:a>'
		let i += 1
		let k += 1
	endwhile
	let par = join(parlines, '')
	
	return par

endfunction
" }}}
" VST_Citations:	 Create citations [first]_ {{{
function! VST_Citations(text)
	let par = substitute(a:text, '\[\(\k\{-}\)]_', '<vim:a href="#citation-\1" name="ctarget-\1">[\1]</vim:a>', 'g')
	
	return par
endfunction
" }}}
" VST_CreateVerse:   Create verse paragraph ("| ") {{{
" Description: 
function! VST_CreateVerse(text)
	" Escaping of special characters
	let par = substitute(a:text, '\n\s*|\( *\)', '\="<vim:br />-vst-new-line-".repeat("&nbsp;", len(submatch(1)))', 'g')
	let par = substitute(par, '^\s*|\( *\)', '\="<vim:p class=\"verse\">-vst-new-line-".repeat("&nbsp;", len(submatch(1)))', 'g')
	let par .= "\n</vim:p>"
	let par = substitute(par, '-vst-new-line-', '\n', 'g')

	return par
endfunction
" }}}
" VST_EscapingSlash: Remove escaping backslashes {{{
function! VST_EscapingSlash(text)
	let par = substitute(a:text, '\n', ' -vst-new-line- ', 'g')

	" Special constructs for escaping:
	" \*	   -> *
	" \`	   -> `
	" \=	   -> = (commented)
	" \<Space> -> <Nop>
	" \-	   -> &nbsp;
	"
	" To escape backslash, use backslash:
	" \\*, \\<Space>, \\-
	
	" Remove single escaping backslash before letters and digits which can form
	" lists enumerators:
	let par = substitute(par, '\\\@<!\\\([A-Za-z0-9#][\]:.)}]\)', '\1', 'g')

	" Remove single escaping backslash befor | at the beginning of paragraph
	" let par = substitute(par, '^\(\s*\)\\|', '\1|', 'g')
	
	" Take care about \*
	let par = substitute(par, '\\\@<!\\\*', '*', 'g')
	" And remove escaping \
	let par = substitute(par, '\\\\\*', '\\*', 'g')

	" Take care about \`
	let par = substitute(par, '\\\@<!\\`', '`', 'g')
	" And remove escaping \
	let par = substitute(par, '\\\\`', '\\`', 'g')

	" Take care about \=
	" let par = substitute(par, '\\\@<!\\=', '=', 'g')
	" And remove escaping \
	" let par = substitute(par, '\\\\=', '\\=', 'g')

	" Take care about \<Space>
	let par = substitute(par, '\\\@<!\\ \(-vst-new-line-\)\@!', '', 'g')
	" And remove escaping \
	let par = substitute(par, '\\\\ \(-vst-new-line-\)\@!', '\\ ', 'g')
	" At last get rid of artificial new lines
	let par = substitute(par, ' -vst-new-line- ', '\n', 'g')

	" Take care about \-
	let par = substitute(par, '\\\@<!\\-', '\&nbsp;', 'g')
	" And remove escaping \
	let par = substitute(par, '\\\\-', '\\-', 'g')
	

	return par
endfunction
" }}}
" VST_ExtraRoles:	Change text :roles: into proper tags " {{{
function! VST_ExtraRoles(name, text)

	if len(filter(copy(keys(g:vst_roledb)), "v:val == a:name")) > 0
		let par = '<vim:span class="'.VST_IdMaker(g:vst_roledb[a:name]).'">'.a:text.'</vim:span>'
	else
		let par = a:text
	endif

	return par
endfunction
" }}}
" VST_FirstLine:	 Returns first and only first line " {{{
" without trailing spaces of given text
function! VST_FirstLine(text)
	return matchstr(a:text, '^\s*\ze.\{-}\ze\s*\(\n\|$\)')

endfunction
" }}}
" VST_Footnotes:	 Create footnotes [\d\+]_ {{{
function! VST_Footnotes(text)
	let parlines = split(a:text, '\(\[\d\+\]\)\@<=_')
	let j = 0
	for parline in parlines
		let parlines[j] = substitute(parlines[j], '\[\(\d\+\)]$', '<vim:a href="#footnote-\1" name="target-\1">\0</vim:a>', '')
		let j += 1
	endfor
	let par = join(parlines, '')
	
	return par

endfunction
" }}}
" VST_Hyperlink:	 Create inline `markup of hyperlinks`_ " {{{
function! VST_Hyperlink(text)
	let par = substitute(a:text, '\n', ' -vst-new-line- ', 'g')
	" Technical spaces
	" Adding spaces at the end and start of paragraph isn't elegant but
	" catching of ^ and $ in regexps by \| is very expensive.
	let par = ' '.par.' '
	" `Inline external anchors`_
	if par =~ '__'
		" Embedded anonymous hyperlinks, Note: second space is nonbreaking
		" space \x160
		let par = substitute(par, "[-  '\"([{</:>]\\@<=`\&lt;\\(.\\{-1,}\\)\&gt;`__[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '\="<vim:a href=\"".VST_ProtectLiteral(submatch(1))."\" title=\"".VST_ProtectLiteral(submatch(1))."\">".VST_ProtectLiteral(submatch(1))."</vim:a>"', 'g')
		let par = substitute(par, "[-  '\"([{</:>]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\) \&lt;\\(.\\{-1,}\\)\&gt;`__[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '\="<vim:a href=\"".VST_ProtectLiteral(submatch(3))."\" title=\"".submatch(1).submatch(2)."\">".submatch(1).submatch(2)."</vim:a>"', 'g')
		" Multi word anon hyperlink (enclosed in backticks)
		let par = substitute(par, "[-  '\"([{</:>]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`__[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '\="<vim:a href=\"-vst-anon-hyperlink-\" title=\"".VST_RemoveTags(submatch(1).submatch(2))."\">".submatch(1).submatch(2)."</vim:a>"', 'g')
		" One word anon hyperlink
		let par = substitute(par, "[-  '\"([{</:>]\\@<=\\([[:alnum:]._-]\\{-2,}\\)__[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '<vim:a href="-vst-anon-hyperlink-" title="\1">\1</vim:a>', 'g')
		let par = substitute(par, "[-  '\"([{</:>]\\@<=\\(\\k\\{-1,}\\)__[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '<vim:a href="-vst-anon-hyperlink-" title="\1">\1</vim:a>', 'g')
	endif
	" Embedded hyperlinks
	let par = substitute(par, "[-  '\"([{</:>]\\@<=`\&lt;\\([^`]\\{-1,}\\)\&gt;`_[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '\="<vim:a href=\"".VST_ProtectLiteral(submatch(1))."\" title=\"".VST_ProtectLiteral(submatch(1))."\">".VST_ProtectLiteral(submatch(1))."</vim:a>"', 'g')
	let par = substitute(par, "[-  '\"([{</:>]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\) \&lt;\\(.\\{-1,}\\)\&gt;`_[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '\="<vim:a href=\"".VST_ProtectLiteral(submatch(3))."\" title=\"".submatch(1).submatch(2)."\">".submatch(1).submatch(2)."</vim:a>"', 'g')
	" Multi word hyperlink (enclosed in backticks)
	let par = substitute(par, "[-  '\"([{</:>]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`_[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '\="<vim:a hrefext=\"".VST_RemoveTags(submatch(1).submatch(2))."\" title=\"".VST_RemoveTags(submatch(1).submatch(2))."\">".submatch(1).submatch(2)."</vim:a>"', 'g')
	" One word hyperlink
	let par = substitute(par, "[-  '\"([{</:>]\\@<=\\([[:alnum:]._-]\\{-2,}\\)_[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '<vim:a hrefext="\1" title="\1">\1</vim:a>', 'g')
	let par = substitute(par, "[-  '\"([{</:>]\\@<=\\(\\k\\{-1,}\\)_[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '<vim:a hrefext="\1" title="\1">\1</vim:a>', 'g')

	" Strange splitting is necessary to be sure it will be unique and only one
	" hyperlink per element.
	let parlines = split(par, 'vim:a h')
	let j = 0
	for parline in parlines
		if parline =~ '^refext='
			let title = tolower(matchstr(parlines[j], '^refext="\zs.\{-}\ze"'))
			let title = substitute(title, '\s\+-vst-new-line-\s\+', ' ', 'g')
			" There was already some processing in text, while data in hlinkdb
			" is in its crude form. I need to reverse some changes to match
			" them:
			let title = substitute(title, '&amp;', '\&', 'g')
			let title = substitute(title, '&lt;', '<', 'g')
			let title = substitute(title, '&gt;', '>', 'g')
			let title = substitute(title, '&copy;', '(c)', 'g')
			let title = substitute(title, '&#64;', '@', 'g')

			if has_key(g:vst_hlinkdb, title) && g:vst_hlinkdb[title] != ''
				let href = escape(g:vst_hlinkdb[title], '&\~')
				if href =~ '_\s*$'
					while href =~ '_\s*$'
						" If ends in _ it is probably indirect link, process it
						" We need to remove _ from the end to get proper key name.
						let shref = tolower(matchstr(href, '^\s*\(`\?\)\zs.*\ze\1_\s*$'))
						if has_key(g:vst_hlinkdb, shref) && g:vst_hlinkdb[shref] != ''
							let href = escape(g:vst_hlinkdb[shref], '&\~')
						else
							let href = '#l'.tolower(VST_IdMaker(shref))
						endif
					endwhile
				else
					let href = escape(g:vst_hlinkdb[title], '&\~')
				endif
			else
				let href = '#l'.VST_IdMaker(title)
			endif
			let parlines[j] = substitute(parlines[j], '^refext=".\{-}"', 'ref="'.href.'"', 'g') 
			let parlines[j] = substitute(parlines[j], 'title="\(.\{-}\)"', '\="title=\"".substitute(submatch(1), " -vst-new-line-\s*", " ", "g")."\""', 'g') 
		endif
		let j += 1
	endfor
	let par = join(parlines, 'vim:a h')

	let par = substitute(par, '^ ', '', '')
	let par = substitute(par, ' $', '', '')
	let par = substitute(par, ' -vst-new-line- ', '\n', 'g')
	" Without this regexp new line placeholders wouldn't be removed from
	" broken embedded URIs
	let par = substitute(par, ' -vst-new-line-\(\S\)', '\1', 'g')

	return par
endfunction
" }}}
" VST_IdentifyImage: Return dimensions of image {{{
function! VST_IdentifyImage(imagename, line)
	let iscale = matchstr(a:line, ':identify:\s*\zs.\{-}\ze\s*$')
	let istring = system('identify -format %wx%h "'.a:imagename.'"')
	if istring =~ '^identify'
		let width = ''
		let height = ''
	endif
	" identify may return new line char at the end breaking some regexps in
	" final stage.
	let istring = substitute(istring, '\n', '', 'g')
	let dimensions = split(istring, 'x')
	if iscale != '' && iscale !~ '\D'
		let width = dimensions[0]*iscale/100
		let height = dimensions[1]*iscale/100
	else
		let [width, height] = dimensions
	endif

	return [width, height]

endfunction
" }}}
" VST_IdMaker:	   Create strings used in name and href {{{
" arguments of links
" Description: Split string to list (necessary to escape unholy mess with
" utf-8 && multibyte characters) and iterate through elements:
" 	When char is \w or - leave unchanged, 
" 	when \s change to -, 
" 	when other use built-in char2nr() function.
function! VST_IdMaker(str)
  " Changing to list is necessary to escape mess with utf-8 characters
  let link = split(a:str, '.\zs')
  let out = ''
  let ix = 0
  while ix < len(link)
	if link[ix] =~ '[a-zA-Z0-9_-]'
		let out .= link[ix]
	elseif link[ix] =~ '\s'
		let out .= '-'
	else
		let out .= char2nr(link[ix])
	endif
	let ix += 1
  endwhile
  return out
endfunction
" }}}
" VST_ImagePar:	  Process image par and return image {{{
" Description: Process image paragraph checking options and composing vim:img
" tag
"	  par - image paragraph
"	  full - is this standalone image or replacement
"		 1 - standalone image, put tag in new line
"		 0 - tag inline, add inline class
function! VST_ImagePar(par, full)
	if a:full == 1
		let nl = "\n"
		let inline = ''
	else
		" This will be inline image. No need for new line at the end of tag
		" and we have to declare inlininess of it
		let nl = ''
		let inline = ' inline'
	endif
	let src = ''
	let width = ''
	let height = ''
	let alt =  ''
	let title = ''
	let identify = ''
	let align = ''
	let scale = ''
	let target = ''
	let class = ''
	let parlines = split(a:par, '\n')
	for parline in parlines
		let parline = substitute(parline, '^\s*', '', '')
		if src == ''
			let src = matchstr(parline, '\(\.\. \)\?image::\s*\zs.\{-}\ze\s*$')
			if !filereadable(escape(src, ' \#%'))
				let noimage = 1
				let g:vst_error .= "No image: ".src."\n"
			else
				let noimage = 0
			endif
		endif
		if width == ''
			let width = matchstr(parline, ':width:\s*\zs.\{-}\ze\s*$')
		endif
		if height == ''
			let height = matchstr(parline, ':height:\s*\zs.\{-}\ze\s*$')
		endif
		if alt == ''
			let alt = matchstr(parline, ':alt:\s*\zs.\{-}\ze\s*$')
		endif
		if title == ''
			let title = matchstr(parline, ':title:\s*\zs.\{-}\ze\s*$')
		endif
		if align == ''
			let align = matchstr(parline, ':align:\s*\zs.\{-}\ze\s*$')
		endif
		if scale == ''
			let scale = matchstr(parline, ':scale:\s*\zs.\{-}\ze\s*$')
			if scale =~ '\D'
				let scale = ''
			endif
		endif
		if target == ''
			let target = matchstr(parline, ':target:\s*\zs.\{-}\ze\s*$')
			if target == 'self' && src != ''
				let target = src
			endif
			while target =~ '_\s*$'
				" If ends in _ it is probably indirect link, process it
				let title = matchstr(target, '^\s*\(`\?\)\zs.*\ze\1_\s*$')
				if has_key(g:vst_hlinkdb, title) && g:vst_hlinkdb[title] != ''
					let href = escape(g:vst_hlinkdb[title], '&\~')
				else
					let href = '#l'.tolower(VST_IdMaker(title))
				endif
			endwhile
		endif
		if class == ''
			let class = matchstr(parline, ':class:\s*\zs.\{-}\ze\s*$')
		endif
		if identify == ''
			let identify = matchstr(parline, ':identify:')
			if identify != '' 
				if executable('identify') && noimage == 0
					let [width, height] = VST_IdentifyImage(src, parline)
				else
					let [width, height] = ['', '']
				endif
			endif
		endif
	endfor
	if src != ''
		let tempsrc = VST_ProtectLiteral(src)
		let src = 'src="'.tempsrc.'"'
	endif
	if scale != ''
		if width != ''
			let width = width*scale/100
		endif
		if height != ''
			let height = height*scale/100
		endif
	endif
	if width != ''
		let width = ' width="'.width.'"'
	endif
	if height != ''
		let height = ' height="'.height.'"'
	endif
	if alt != ''
		let alt = ' alt="'.alt.'"'
	else
		let alt = ' alt="'.tempsrc.'"'
	endif
	if title != ''
		let title = ' title="'.title.'"'
	endif
	if class != ''
		if align == ''
			let class = ' class="'.class.inline.'"'
		else
			let class = ' class="'.class.inline.' vst'.align.'"'
		endif
	else
		if align == ''
			if inline != ''
				let class = ' class="inline"'
			else
				let class = ' '
			endif
		else
			let class = ' class="vst'.align.'"'
		endif
	endif

	if src != ''
		if target != ''
			if target =~ '_\s*$'
				let address = matchstr(VST_Hyperlink(target), '^.\{-}>\ze')
			else
				let address = '<vim:a href="'.VST_ProtectLiteral(target).'">'
			endif
			let para = address.nl."<vim:img ".src.width.height.class.alt.title." />".nl."</vim:a>"
		else
			let para = "\n<vim:img ".src.width.height.class.alt.title." />".nl
		endif
	else
		let para = '<vim:!-- '.a:par.' -->'
	endif
	if a:full == 1
		return "<vim:p>\n".para."\n</vim:p>"
	else
		return para
	endif
endfunction
" }}}
" VST_LabelFootnote: Create auto-numbered footnotes [#first]_ {{{
function! VST_LabelFootnote(text)
	let par = a:text
	for label in keys(g:lfnotes)
		let k = g:lfnotes[label] 
		let par = substitute(par, '\[#'.label.']_', '<vim:a href="#footnote-'.k.'" name="target-'.k.'">['.k.']</vim:a>', 'g')
	endfor
	
	unlet! k

	return par

endfunction
" }}}
" VST_Markup:		Create inline markup of text styles " {{{
function! VST_Markup(text)
	let par = substitute(a:text, '\n', ' -vst-new-line- ', 'g')
	" Technical spaces
	let par = ' '.par.' '
	" Take care about escaping of asterisk
	let par = substitute(par, '\\\@<!\\\*', '-vst-escape-asterisk-', 'g')
	" Take care about single asterisk
	let par = substitute(par, ' \* ', ' \&#42; ', 'g')
	" Take care about single asterisk inside of (), {}, [], '', ""
	let par = substitute(par, "\\([[({<]\\)\\*\\([])}> ]\\)", '\1\&#42;\2', 'g')
	let par = substitute(par, "\\(['\"]\\)\\*\\([\"']\\)", '\1\&#42;\2', 'g')
	" Take care about double asterisk inside of (), {}, [], '', ""
	let par = substitute(par, "\\([[({<]\\)\\*\\*\\([])}> ]\\)", '\1\&#42;\&#42;\2', 'g')
	let par = substitute(par, "\\(['\"]\\)\\*\\*\\([\"']\\)", '\1\&#42;\&#42;\2', 'g')
	" Take care about backticks inside of (), {}, [], '', ""
	let par = substitute(par, "\\([[({<]\\)`\\([])}> ]\\)", '\1\&#96;\2', 'g')
	let par = substitute(par, "\\(['\"]\\)`\\([\"']\\)", '\1\&#96;\2', 'g')
	" Take care about double backticks inside of (), {}, [], '', ""
	let par = substitute(par, "\\([[({<]\\)``\\([])}> ]\\)", '\1\&#96;\&#96;\2', 'g')
	let par = substitute(par, "\\(['\"]\\)``\\([\"']\\)", '\1\&#96;\&#96;\2', 'g')
	"" **strong**, Note: second space in next 3 LOC is nonbreaking space - \x160
	let par = substitute(par, "[-  '\"([{</:>~]\\@<=\\*\\* \\@<!\\(.\\{-}\\)\\*\\*[\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '<vim:strong>\1</vim:strong>', 'g')
	"" *emph*
	let par = substitute(par, "[-  '\"([{</:>~]\\@<=\\* \\@<!\\(.\\{-1,}\\)\\*[\\]<\\-  '\")}>/\\\:.,;!?]\\@=", '<vim:em>\1</vim:em>', 'g')
	"" ``literal`` (<code> like), ``code``, Note: space after :space: is
	" nonbreaking space, not included into :space:
	let par = substitute(par, "[-  '\"([{</:>~]\\@<=``\\([^[:space:] ]\\)\\(.\\{-}\\)``[\\]<\\-  '\")}>/\\\:.,;!?]\\@=", '\="<vim:code>".VST_ProtectLiteral(submatch(1).submatch(2))."</vim:code>"', 'g')

	let par = substitute(par, ' -vst-new-line- ', '\n', 'g')

	" Restore escaped asterisk
	let par = substitute(par, '-vst-escape-asterisk-', '\\*', 'g')
	" Restore asterisks
	let par = substitute(par, '&#42;', '*', 'g')
	" Restore backticks
	let par = substitute(par, '&#96;', '`', 'g')
	" Remove technical spaces
	let par = substitute(par, ' $', '', '')
	let par = substitute(par, '^ ', '', '')


	return par
endfunction
" }}}
" VST_ProtectLiteral: Change special chars inside of literals into entities {{{
" Description: take text from submatch and change meaningful characters into
" entities.
function! VST_ProtectLiteral(text)
	" Escaping of special characters
	"let par = substitute(a:text, "[[`\_|:]", '\="\&#".char2nr(submatch(0)).";"', 'g')
	let par = substitute(a:text, '`', '\&#96;', 'g')
	let par = substitute(par, '[', '\&#91;', 'g')
	let par = substitute(par, '\', '\&#92;', 'g')
	let par = substitute(par, '_', '\&#95;', 'g')
	let par = substitute(par, '|', '\&#124;', 'g')
	" : is required part of raw links, if we don't want to convert them,
	" "remove" colon
	let par = substitute(par, ':', '\&#58;', 'g')

	return par
endfunction
" }}}
" VST_RemoveTags:	 Returns given string without vim tags {{{
function! VST_RemoveTags(text)
	return substitute(a:text, '<.\?vim:[^>]\{-}>', '', 'g')

endfunction
" }}}
" VST_Replacement:   Resolve |replacements| into full text {{{
function! VST_Replacement(text)

	let par = a:text
	" Loop through entries in replacedb 
	" keys and values have to be proper Vim regexp constructs
	for key in keys(g:vst_replacedb)
		let replace = g:vst_replacedb[key]
		"let replace = escape(g:vst_replacedb[key], '\&~')
		" [^:] blocks processing of reST style image replacement
		if replace =~ '^image:[^:]'
			" Old style image, deprecated {{{
			" Create image. We have here one line of pairs term:definition,
			" but definition can be a string with spaces embraced in quotes.
			" image:src with:420 alt:"this image"
			let img = substitute(replace, '\(\w\+\):', ',"\1":', 'g') 
			let img = substitute(img, ':\([^"].\{-}\)\( \|$\)', ':"\1"', 'g') 
			let img = '{'.substitute(img, '^\s*,', '', 'g').'}'
			unlet! g:image
			let g:image = eval(img)
			let replace = '<vim:img class="inline" '
			for attr in keys(g:image)
				if attr == 'image'
					let item = 'src="'.g:image[attr].'" '
					let replace .= item
				elseif attr == 'identify' || attr == 'target'
					continue
				else
					let item = attr.'="'.g:image[attr].'" '
					let replace .= item
				endif
			endfor
			let replace .= '/>'
			if has_key(g:image, 'target')
				if g:image['target'] == 'self'
					let ttarget = g:image['image']
				endif
				let replace = '<vim:a href="'.g:image['image'].'">'.replace.'</vim:a>'
			endif
			let par = substitute(par, '|'.key.'|', replace, 'g')
			" }}}
		elseif replace =~ '^replace::'
			" Plain replace {{{
			if replace =~ ':ltrim:'
				let ltrim = '\s*'
				let rtrim = ''
			elseif replace =~ ':trim:'
				let ltrim = '\s*'
				let rtrim = '\s*'
			elseif replace =~ ':rtrim:'
				let ltrim = ''
				let rtrim = '\s*'
			else
				let ltrim = ''
				let rtrim = ''
			endif
			" Process special characters in key: lt, gt, amp
			" They were already processed in text
			let key = substitute(key, '&', '\&amp;', 'g')
			let key = substitute(key, '<', '\&lt;', 'g')
			let key = substitute(key, '>', '\&gt;', 'g')
			let replace = matchstr(replace, '^replace::\s*\zs.\{-}\ze\_s*\(\.\. \|:trim:\|:ltrim:\|:rtrim:\|$\)')
			"let replace = matchstr(replace, '^replace::\s*\zs.\{-}\ze\s*$')
			let replace = escape(VST_SpecCharacter(replace), '&~\')
			if par =~ '|_'
				" Placeholder necessary to later trigger markup commands
				let par = substitute(par, ltrim.'|'.key.'|__'.rtrim, '`{-vst-replace-{'.replace.'}-vst-replace-}`__', 'g')
				let par = substitute(par, ltrim.'|'.key.'|_'.rtrim, '`{-vst-replace-{'.replace.'}-vst-replace-}`_', 'g')
				if has_key(g:vst_hlinkdb, key)
					" replace can contain markup - in text it will be proceed,
					" in db no. Force 
					let proceed = VST_Markup(replace)
					let proceed = VST_Roles(proceed)
					let proceed = VST_EscapingSlash(proceed)
					" And remove tags!
					let proceed = substitute(proceed, '<.\?vim:[^>]\{-}>', '', 'g')
					let g:vst_hlinkdb[tolower(proceed)] = g:vst_hlinkdb[key]
				endif
			endif
			let par = substitute(par, ltrim.'|'.key.'|'.rtrim, replace, 'g')
			" }}}
		elseif replace =~ '^unicode::'
			" Unicode {{{
			if replace =~ ':ltrim:'
				let ltrim = '\s*'
				let rtrim = ''
			elseif replace =~ ':trim:'
				let ltrim = '\s*'
				let rtrim = '\s*'
			elseif replace =~ ':rtrim:'
				let ltrim = ''
				let rtrim = '\s*'
			else
				let ltrim = ''
				let rtrim = ''
			endif
			let g:vst_encoding = "utf-8"
			" We need this interference - without that character would be
			" inserted improperly
			let origenc = &encoding
			set encoding=utf-8
			let key = substitute(key, '&', '\&amp;', 'g')
			let key = substitute(key, '<', '\&lt;', 'g')
			let key = substitute(key, '>', '\&gt;', 'g')
			let replace = matchstr(replace, '^unicode::\s*\zs.\{-}\ze\s*\(\.\. \|:trim:\|:ltrim:\|:rtrim:\|$\)')
			let replace = substitute(replace, '\(0x\|x\|\\x\|U+\|u\|\\u\|&#x\)\([0-9a-fA-F]\+\)', '\=Unicode2Char(submatch(2))', 'g')
			let replace = substitute(replace, '\_s' , '', 'g')
			let replace = escape(VST_SpecCharacter(replace), '&~\')
			if par =~ '|_'
				let par = substitute(par, '|'.key.'|__', '`'.replace.'`__', 'g')
				let par = substitute(par, '|'.key.'|_', '`'.replace.'`_', 'g')
				if has_key(g:vst_hlinkdb, key)
					" replace can contain markup - in text it will be proceed,
					" in db no. Force 
					let proceed = VST_Markup(replace)
					let proceed = VST_Roles(proceed)
					let proceed = VST_EscapingSlash(proceed)
					" And remove tags!
					let proceed = substitute(proceed, '<.\?vim:[^>]\{-}>', '', 'g')
					let g:vst_hlinkdb[tolower(proceed)] = g:vst_hlinkdb[key]
				endif
			endif
			"let par = substitute(par, ltrim.'|'.key.'|__'.rtrim, '`'.replace.'`__', 'g')
			"let par = substitute(par, ltrim.'|'.key.'|_'.rtrim, '`'.replace.'`_', 'g')
			let par = substitute(par, ltrim.'|'.key.'|'.rtrim, replace, 'g')
			let &encoding = origenc
			" }}}
		elseif replace =~ '^image::'
			" Image replacement {{{
			let replace = VST_ImagePar(replace, 0)
			let replace = escape(replace, '&~\')
			let par = substitute(par, '|'.key.'|', replace, 'g')
			" }}}
		elseif replace =~ '^date::'
			" Date replacement {{{
			let replace = matchstr(replace, 'date::\s*\zs.*$')
			let replace = substitute(replace, '\s*$', '', '')
			if exists("*strftime")
				if replace == ''
					let replace = strftime("%Y-%m-%d")
				else
					let replace = strftime(replace)
				endif
			else
				let replace = localtime()
			endif

			let replace = escape(replace, '&~\')
			let par = substitute(par, '|'.key.'|', replace, 'g')
			" }}}
		elseif replace =~ '^\w\+::'
			" Don't perform replacement of reST style replacement directives.
			" This can cause big mess.
			continue
		endif
	endfor


	return par
endfunction
" }}}
" VST_Roles:		 Change text :roles: into proper tags " {{{
function! VST_Roles(text)
	let par = substitute(a:text, '\n', ' -vst-new-line- ', 'g')
	" Technical spaces
	let par = ' '.par.' '
	" :sub:`text` and `text`:sub:
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:sub:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:sub>\1</vim:sub>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:sub:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:sub>\1</vim:sub>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:subscript:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:sub>\1</vim:sub>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:subscript:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:sub>\1</vim:sub>', 'g')
	" :sup:`text` and `text`:sup:
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:sup:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:sup>\1</vim:sup>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:sup:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:sup>\1</vim:sup>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:superscript:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:sup>\1</vim:sup>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:superscript:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:sup>\1</vim:sup>', 'g')
	" :strong:`text` and `text`:strong:
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:strong:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:strong>\1</vim:strong>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:strong:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:strong>\1</vim:strong>', 'g')
	" :emphasis:`text` and `text`:emphasis:
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:emphasis:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:em>\1</vim:em>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:emphasis:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:em>\1</vim:em>', 'g')
	" :literal:`text` and `text`:literal:
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:literal:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:code>\1</vim:code>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:literal:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:code>\1</vim:code>', 'g')
	" :big:`text` and `text`:big:
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:big:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:span class="big">\1</vim:span>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:big:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:span class="big">\1</vim:span>', 'g')
	" :small:`text` and `text`:small:
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:small:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:span class="small">\1</vim:span>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:small:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:span class="small">\1</vim:span>', 'g')
	" :title-reference:, :title:, :t:
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:title-reference:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:cite>\1</vim:cite>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:title:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:cite>\1</vim:cite>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:t:`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:cite>\1</vim:cite>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:title-reference:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:cite>\1</vim:cite>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:title:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:cite>\1</vim:cite>', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:t:[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '<vim:cite>\1</vim:cite>', 'g')
	" any other role
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=:\\(\\S\\+\\):`\\([^`]\\{-1,}\\)`[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '\=VST_ExtraRoles(submatch(1), submatch(2))', 'g')
	let par = substitute(par, "[-  `'\"([{</:>]\\@<=`\\([^`]\\{-1,}\\)`:\\(\\S\\+\\):[\\]\\-  '\")}<>/\\\:.,;!?]\\@=", '\=VST_ExtraRoles(submatch(1), submatch(2))', 'g')

	let par = substitute(par, ' -vst-new-line- ', '\n', 'g')
	" Remove technical spaces
	let par = substitute(par, ' $', '', '')
	let par = substitute(par, '^ ', '', '')

	return par
endfunction
" }}}
" VST_DefaultRole:		 Change `default roles` into proper tags " {{{
function! VST_DefaultRole(text)

	let par = substitute(a:text, '\n', ' -vst-new-line- ', 'g')
	" Technical spaces
	let par = ' '.par.' '

	" Take care about backticks inside of (), {}, [], '', ""
	let par = substitute(par, "\\([['\"({<]\\)`\\([])}>\"']\\)", '\1\&#96;\2', 'g')

	let split_file = split(par, '\(^\|-vst-new-line-\)\s*\.\. default-role::\s*')

	if len(split_file) == 1
		let roled = substitute(split_file[0], "[-  '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\(.\\{-}\\)`[`\\]<\\-  '\")}>/\\:\\.,;!?]\\@=", '<vim:cite>\1\2</vim:cite>', 'g')
	else
		for i in range(len(split_file))

			if i == 0
				let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:]`]\\)\\(.\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:cite>\1\2</vim:cite>', 'g')
			else
				let role = matchstr(split_file[i], '^.\{-}\ze\s\+-vst-new-line- ')
				let split_file[i] = substitute(split_file[i], '^.\{-}-vst-new-line- ', '', '')
				if role =~ '^\(t\|title\|title-reference\)$'
					let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:cite>\1\2</vim:cite>', 'g')
				elseif role =~ '^sup\(erscript\)\?$'
					let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:sup>\1\2</vim:sup>', 'g')
				elseif role =~ '^sub\(script\)\?$'
					let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:sub>\1\2</vim:sub>', 'g')
				elseif role =~ '^strong$'
					let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:strong>\1\2</vim:strong>', 'g')
				elseif role =~ '^emphasis$'
					let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:em>\1\2</vim:em>', 'g')
				elseif role =~ '^literal$'
					let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:code>\1\2</vim:code>', 'g')
				elseif role =~ '^big$'
					let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:span class="big">\1\2</vim:span>', 'g')
				elseif role =~ '^small$'
					let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:span class="small">\1\2</vim:span>', 'g')
				else
					let role = VST_IdMaker(role)
					let split_file[i] = substitute(split_file[i], "[- '\"([{</:>;]\\@<=`\\([^[:space:] `]\\)\\([^`]\\{-}\\)`[`\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:span class="'.role.'">\1\2</vim:span>', 'g')
				endif
			endif
		endfor
		let roled = join(split_file, "\n")
	endif

	let par = substitute(roled, ' -vst-new-line- ', '\n', 'g')
	" Restore backticks
	let par = substitute(par, '&#96;', '`', 'g')
	" Remove technical spaces
	let par = substitute(par, ' $', '', '')
	let par = substitute(par, '^ ', '', '')

	return par
endfunction
" }}}
" VST_SA_Hyperlink:  Process explicit hyperlinks {{{
" Description: Find text following rules of certain protocol and change it
" into <a href>.
" Supported: http, https, ftp, sftp, mailto
function! VST_SA_Hyperlink(text)

	function! VST_PunctTrap(link)
		let punctless = a:link
		if punctless =~ '[.?!;,]$'
			let punctless = matchstr(punctless, '.*\ze.$')
		endif
		return VST_ProtectLiteral(punctless)
	endfunction

	let par = a:text
	" Handle standalone links in <> brackets.
	let par = substitute(par, '&lt;\(https\?://[a-zA-Z0-9./%&@#:;?=_-]\+\)&gt;\(`_\)\@!', '\="\&lt;<vim:a href=\"".VST_PunctTrap(submatch(1))."\">".VST_ProtectLiteral(submatch(1))."</vim:a>\&gt;"', 'g')
	let par = substitute(par, '&lt;\(s\?ftp://[a-zA-Z0-9./%&#@:;?=_-]\+\)&gt;\(`_\)\@!', '\="\&lt;<vim:a href=\"".VST_PunctTrap(submatch(1))."\">".VST_ProtectLiteral(submatch(1))."</vim:a>\&gt;"', 'g')
	let par = substitute(par, '&lt;mailto:\([a-zA-Z0-9@&#.;?=_-]\+\)&gt;\(`_\)\@!', '\="\&lt;<vim:a href=\"mailto:".VST_PunctTrap(submatch(1))."\">".VST_ProtectLiteral(submatch(1))."</vim:a>\&gt;"', 'g')

	let par = substitute(par, '\(href="\|&lt;\)\@<!https\?://[a-zA-Z0-9./%&@#:;?=_-]\+', '\="<vim:a href=\"".VST_PunctTrap(submatch(0))."\">".VST_ProtectLiteral(submatch(0))."</vim:a>"', 'g')
	let par = substitute(par, '\(href="\|&lt;\)\@<!s\?ftp://[a-zA-Z0-9./%&#@:;?=_-]\+', '\="<vim:a href=\"".VST_PunctTrap(submatch(0))."\">".VST_ProtectLiteral(submatch(0))."</vim:a>"', 'g')
	let par = substitute(par, '\(href="\|&lt;\)\@<!mailto:\([a-zA-Z0-9@&#.;?=_-]\+\)', '\="<vim:a href=\"".VST_PunctTrap(submatch(0))."\">".VST_ProtectLiteral(submatch(2))."</vim:a>"', 'g')

	" Remove doubled links caused by http regexps.
	let par = substitute(par, '\(<vim:a href=".\{-}">\)\1', '\1', 'g')
	let par = substitute(par, '</vim:a></vim:a>', '</vim:a>', 'g')
	" In 99% of causes some punct chars at the end of link (.?!;,) shouldn't be
	" there and was already catched by VST_PunctTrap
	let par = substitute(par, '\([.?!;,]\+\)</vim:a>', '</vim:a>\1', 'g')

	return par
endfunction
" }}}
" VST_SpecCharacter: Change special chars into entities {{{
" Supported: &, <, >, (c) 
function! VST_SpecCharacter(text)
	" Escaping of special characters
	let par = substitute(a:text, '&\([#a-z0-9]\+;\)\@!', '\&amp;', 'g')
	let par = substitute(par, '\\&[#a-z0-9]', '\&amp;#', 'g')
	let par = substitute(par, '(c)', '\&copy;', 'g')
	let par = substitute(par, '@', '\&#64;', 'g')
	let par = substitute(par, '<', '\&lt;', 'g')
	let par = substitute(par, '>', '\&gt;', 'g')
	return par
endfunction
" }}}
" VST_Target:		Create <span id> tags for _`inline targets` {{{
function! VST_Target(text)
	let par = substitute(a:text, '\n', ' -vst-new-line- ', 'g')
	" Technical spaces
	let par = ' '.par.' '
	" _`Inline internal targets`
	let par = substitute(par, "[- '\"([{</:>]\\@<=_`\\([^[:space:] `]\\)\\(.\\{-}\\)`[\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:span targetid="\1\2" title="\1\2" class="target">\1\2</vim:span>', 'g')
	let par = substitute(par, "[- '\"([{</:>]\\@<=_\\([[:alnum:]._-]\\{-2,}\\)[\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:span targetid="\1" title="\1" class="target">\1</vim:span>', 'g')
	let par = substitute(par, "[- '\"([{</:>]\\@<=_\\(\\k\\{-1,}\\)[\\]<\\- '\")}>/\\:\\.,;!?]\\@=", '<vim:span targetid="\1" title="\1" class="target">\1</vim:span>', 'g')
	" Strange splitting is necessary to be sure it will be unique and only one
	" hyperlink per element.
	let parlines = split(par, 'vim:span targeti')
	let j = 0
	for parline in parlines
		if parline =~ '^d='
			let title = tolower(matchstr(parlines[j], '^d="\zs.\{-}\ze"'))
			let href = VST_IdMaker(substitute(title, '\s\+-vst-new-line-\s\+', ' ', 'g'))
			let parlines[j] = substitute(parlines[j], '^d=".\{-}"', 'd="l'.href.'"', 'g') 
		endif
		let j += 1
	endfor
	let par = join(parlines, 'vim:span i')

	let par = substitute(par, '^ ', '', '')
	let par = substitute(par, ' $', '', '')

	let par = substitute(par, ' -vst-new-line- ', '\n', 'g')

	return par
endfunction
" }}}
" VST_FoldExpr: Folding expression {{{
" lnum - current line to evaluate fold level
function! VST_FoldExpr(lnum)
	if getline(a:lnum) =~ "'"
		let line = substitute(getline(a:lnum), "'", "''", 'g')
	else
		let line = getline(a:lnum)
	endif
	if b:vst_fold_lvl =~ 'r'
		if string(b:vst_flvl_1) =~? "[[ ]'".escape(line, '.*\[~&^$')."'[],]"
			return '>1'
		elseif string(b:vst_flvl_2) =~? "[[ ]'".escape(line, '.*\[~&^$')."'[],]"
			return '>2'
		elseif string(b:vst_flvl_3) =~? "[[ ]'".escape(line, '.*\[~&^$')."'[],]"
			return '>3'
		elseif string(b:vst_flvl_4) =~? "[[ ]'".escape(line, '.*\[~&^$')."'[],]"
			return '>4'
		elseif string(b:vst_flvl_5) =~? "[[ ]'".escape(line, '.*\[~&^$')."'[],]"
			return '>5'
		elseif string(b:vst_flvl_6) =~? "[[ ]'".escape(line, '.*\[~&^$')."'[],]"
			return '>6'
		else
			return '='
		endif
	endif
	"let list = keys(b:vst_fold)
	let list = keys(b:vst_fold_list)
	if string(list) =~? "[[ ]'".escape(line, '.*\[~&^$')."'[],]"
		return '>1'
	else
		return '1'
	endif
endfunction
" }}}
" VST_D: simple debug {{{
" Description: echo structure of document in form of list:
"   <par number>) <par indentation> <par type>
function! VD()
	for i in range(len(g:paras))
		"echo i.') '.g:pindent[i].'  '.g:ptype[i].'  '.split(g:paras[i], "\n")[0]."\n"
		echo i.') '.g:pindent[i].'  '.g:ptype[i].'  '."\n"
	endfor
endfunction
" }}}
" VST_End: remove unnecessary global variables and other garbage {{{
" Description: function unlet! g:vars which may clash in next calls of VST
" functions
function! VST_End()
	unlet! g:paras g:paras_rez
	unlet! g:pindent g:pindent_rez
	"unlet! g:ptype g:ptype_rez
	unlet! g:plinen g:plinen_rez
	unlet! g:vst_recursion
	unlet! g:vst_doc_title
endfunction
" }}}
" }}}

	" Initialize error message
	let g:vst_error = ''

	" Source project file
	if filereadable("vstrc.vim")
		source vstrc.vim
	endif

	" We don't need freaking tabs!
	setlocal expandtab
	retab

	" For proper working of script nocompatible has to be set but setting it
	" explicitly may break other settings which usually don't disturb
	if &compatible == 1
		set nocompatible
	endif

	let format = tolower(a:format)

	if format == ''
		let format = 'html'
	endif

	let text = getline(a:line1, a:line2)

	" Include external files before anything else will be done {{{
	" But only for "real" export
	if ',pdf,xml,html,s5,latex,tex,preproc,' =~ ','.format.','
	let rec_counter = 0
	while rec_counter < &maxfuncdepth/2
		" if len(filter(copy(text), 'v:val =~ "^\\s*\\.\\. \\(header\\|include\\|footer\\)::"')) > 0
		" Tried to do in one regexp, but its alternative was sometimes working, sometimes not
		" Note: it always works... even inside of preformatted text
		let isinclude = len(filter(copy(text), 'v:val =~ "^\\s*\\.\\. include::"'))
		let isheader = len(filter(copy(text), 'v:val =~ "^\\s*\\.\\. header::"'))
		let isfooter = len(filter(copy(text), 'v:val =~ "^\\s*\\.\\. footer::"'))
		" End loop when there are no including commands, save up to 100
		" filtering
		if isinclude == 0 && isheader == 0 && isfooter == 0
			break
		endif
		if isinclude > 0 || isheader > 0 || isfooter > 0
			let i = 0
			while i < len(text)
				if text[i] =~ '^\s*\.\. \(header\|include\|footer\)::'
					let include = matchlist(text[i], '^\(\s*\)\.\. \(header\|include\|footer\)::\s*\(.*\)\s*$')
					" Do nothing if file isn't readable, general VST policy:
					" silently ignore all author errors.
					
					if include[3] =~ '^<' && include[3] =~ '>$'
						let include[3] = matchstr(include[3], '^.\zs.*\ze.$')
						let include[3] = g:vst_included.'/'.include[3]
					endif
					" let inc_indent = len(include[1])
					" EXPERIMENTAL: change \ into / - windows separator into
					" unix separator and vice versa depending on running
					" system
					if has("win16") || has("win32") || has("win64") || has("win95") || has("dos16") || has("dos32")
						let include[3] = substitute(include[3], '/', '\\', 'g')
					else
						let include[3] = substitute(include[3], '\\', '/', 'g')
					endif
					if filereadable(include[3])
						let included = readfile(include[3])
						call map(included, 'include[1].v:val')
						if include[2] == 'header'
							let text[i] = ''
							let included += ['']
							call extend(text, included, 0)
						elseif include[2] == 'footer'
							let text[i] = ''
							let included = [''] + included
							call extend(text, included)
						else
							let text[i] = ''
							call extend(text, included, i+1)
						endif
					elseif include[3] == 'vstfooter' || include[3] == ''
						if exists("*strftime")
							let date = strftime("%c")
						else
							let date = "Unknown"
						endif
						let included = ['.. block:: vstfooter', '', '   -----------------------',
							\ '', '   Vim reStructured Text document. Generated: '.date
							\.'. `View VST source`_', '', 
							\ '   .. _view VST source: '.expand("%"),'']
						call extend(text, included)
						let text[i] = ''
					elseif include[2] =~ 'header\|footer' && text[i-2] !~ '::\s*$'
						" Second part of above condition is hack to allow for
						" proper compilation of f/h examples. Simple test should
						" cover most of them.
						if include[2] == 'footer'
							let text[i] = ''
							if format !~ 's5'
								let included = ['.. block:: vstfooter','', '   ------------------------',
									\ '', '   '.VST_ProtectLiteral(include[3]), '']
								call extend(text, included)
							else
								let s5footer = VST_ProtectLiteral(include[3])
							endif
						elseif include[2] == 'header'
							let text[i] = ''
							let included = ['.. block:: vstfooter','', '   '.VST_ProtectLiteral(include[3]),
								\ '', '   ------------------------', '']
							call extend(text, included, 0)
						endif
					else
						if include[3] !~ '^{.*}$'
							let text[i] = ''
							let included = [include[1].'.. Unknown file: '.VST_ProtectLiteral(include[3]), 
								\ '', include[1].'..']
							call extend(text, included, i+1)
						endif
					endif
					if exists('included')
						let i += len(included)
					endif
				endif
				let i += 1
			endwhile
		endif
		let rec_counter += 1
	endwhile
	unlet! rec_counter
	endif
	" }}}
	" Preprocess text to ... 	{{{
	" But not for preproc export:
	if format !~ '^pre'
	" Separate preprocessing for modeline correction
	" Not elegant but prevents from messing with last element in main loop
	" This take care about modeline in last line
	" Remove filetype setting from modeline to not confuse Vim in exported
	" files
	for i in range(&modelines+1) + range(len(text)-&modelines, len(text)-1) 
		if get(text, i) != ''
			if text[i] =~ '^\s*\.\. vim:.*re\?st'
				let text[i] = substitute(text[i], '\s\?\%(filetype\|ft\)=re\?st', '', 'g')
				if text[i] =~ 'vim:\s*\(set\)\?\s*:\?\s*$'
					let text[i] = ''
				endif
			endif
		endif
	endfor
	" We need to keep track of real lines. Create hash with keys of virtual
	" lines created by preprocessing and real lines
	let i = 0
	let g:vst_reallines = {}
	let rl_correction = 0
	while i < len(text)-1
		" Remove control characters, some Emacs deviation
		if text[i] =~ '[[:cntrl:]]'
			let text[i] = substitute(text[i], '[[:cntrl:]]', '', 'g')
		endif
		" If comment directive is empty and following line is blank change
		" it to .. comment:: directive. In this way indentation still will be
		" taken into account
		if text[i] =~ '^\s*\.\.\s*$' && text[i+1] =~ '^\s*$'
			let text[i] = substitute(text[i], '^\(\s*\.\.\)', '\1 comment::', '')
		endif
		" Insert blank line between one line directives
		if text[i] =~ '^\s*\(\.\.\|__\) ' && text[i+1] =~ '^\s*\(\.\.\|__\) '
			let findent = strlen(matchstr(text[i], '^\s*'))
			let sindent = strlen(matchstr(text[i+1], '^\s*'))
			" But only if those .. are on the same level of indentation
			if findent == sindent
				call insert(text, '', i+1)
				let rl_correction -= 1
			endif
		endif
		" Insert blank line between option of directive and directive in next
		" line
		if text[i] =~ '^\s\+:\w\+:' && text[i+1] =~ '^\s*\.\. '
			let findent = strlen(matchstr(text[i], '^\s*'))
			let sindent = strlen(matchstr(text[i+1], '^\s*'))
			" But only if option has bigger indentation than directive
			if (sindent + 3) <= findent
				call insert(text, '', i+1)
				let rl_correction -= 1
			endif
		endif
		" Insert blank line between named admonition and unordered|ordered
		" list in next line Have to be splitted in two if's because || is
		" horrible ineffective.  
		" LISTDEF: here is list definition which may require adjustment
		if text[i] =~? '^\s*\.\. \(note\|tip\|warning\|attention\|caution\|danger\|error\|hint\|important\|admonition\)::\s*$' && text[i+1] =~ '^\s*'.s:vst_bulletdef.'\s'
			let findent = strlen(matchstr(text[i], '^\s*'))
			let sindent = strlen(matchstr(text[i+1], '^\s*'))
			" But only if list has bigger indentation than directive
			if (findent + 3) <= sindent
				call insert(text, '', i+1)
				let rl_correction -= 1
			endif
		endif
		if text[i] =~? '^\s*\.\. \(note\|tip\|warning\|attention\|caution\|danger\|error\|hint\|important\|admonition\)::\s*$' && text[i+1] =~ '^\s*\(\d\+\|[a-zA-Z]\|[icdvlmxICDVLMX]\+\|#\)[\]:.)}]\s'
			let findent = strlen(matchstr(text[i], '^\s*'))
			let sindent = strlen(matchstr(text[i+1], '^\s*'))
			" But only if list has bigger indentation than directive
			if (findent + 3) <= sindent
				call insert(text, '', i+1)
				let rl_correction -= 1
			endif
		endif
		let i += 1
		let g:vst_reallines[i] = i + rl_correction
	endwhile
	" In main loop we are not interested in last item, here add correction for
	" this
	let g:vst_reallines[i+1] = i + 1 + rl_correction
	endif
	" }}}
	" Initiate variables for non export specific databases: {{{
	let g:vst_headers = {}
	let g:vst_hlinkdb = {}
	let g:vst_replacedb = {}
	let g:vst_roledb = {}

	" }}}

	let g:vst_anonhlinkdb = filter(copy(text), 'v:val =~ "^\\s*\\(\\.\\. __:\\|__ \\)"')
	if ',pdf,xml,html,s5,latex,tex,' =~ ','.format.','
		let g:vst_footnotedb = {}
		let g:vst_citationdb = {}
		let g:vst_fielddb = {}
		let g:vst_metadb = {}

		unlet! g:vst_encoding

		" Necessary for working of labels
		if '-' !~ '\k'
			let b:vst_hyphenisk = 1
			set isk+=-
		else
			let b:vst_hyphenisk = 0
		endif

		" Main function
		let file = VST_Structure(text)

		unlet! b:vst_afs
		unlet! b:vst_first_parsing

		if file =~ '\[#\]_'
			let file = VST_AutoFootnote(file)
		endif

		" Process hyperlinks {{{
		let lines = split(file, '<vim:p')
		let i = 0
		while i < len(lines)
			if lines[i] =~ '_'
				" Take care about \`
				let lines[i] = substitute(lines[i], '\\\@<!\\`__', '-vst-escape-backtick-ddash-', 'g')
				let lines[i] = substitute(lines[i], '\\\@<!\\`_', '-vst-escape-backtick-dash-', 'g')
				let lines[i] = substitute(lines[i], '\\\@<!\\`', '-vst-escape-backtick-', 'g')
				" Take care about quoted backtick quoted backtics
				let lines[i] = substitute(lines[i], "\\([['\"({<]\\)`\\([])}>\"' ]\\)", '\1\&#96;\2', 'g')
				let lines[i] = substitute(lines[i], "\\([['\"({<]\\)_`\\([])}>\"' ]\\)", '\1_\&#96;\2', 'g')
				" Take care about "``"
				let lines[i] = substitute(lines[i], '"``"', '-vst-quot-dbacktick-', 'g')
				" Take care about alone _ and __
				let lines[i] = substitute(lines[i], ' _ ', ' \&#95; ', 'g')
				let lines[i] = substitute(lines[i], ' __ ', ' \&#95;\&#95; ', 'g')
				" Take care about __ in programmer expressions __init__ like (shaky)
				let lines[i] = substitute(lines[i], '\([[:punct:][:space:] ]\)__\(\k*\)__\([[:punct:][:space:] ]\?\)', '\1\&#95;\&#95;\2\&#95;\&#95;\3', 'g')
				" Ugly, ugly, prevent from linkination of ".. __:" in text
				let lines[i] = substitute(lines[i], ' __\(\S\)', ' \&#95;\&#95;\1', 'g')
				" Take care about anonymous references
				let lines[i] = substitute(lines[i], "\\([['\"({<]\\)__\\([])}>\"' ]\\)", '\1\&#95;\&#95;\2', 'g')
				" Take care about "``"

				" Main hyperlink processing
				let lines[i] = VST_Hyperlink(lines[i])
				let lines[i] = VST_Target(lines[i])

				" Restore \`
				let lines[i] = substitute(lines[i], '-vst-escape-backtick-ddash-', '\\`__', 'g')
				let lines[i] = substitute(lines[i], '-vst-escape-backtick-dash-', '\\`_', 'g')
				let lines[i] = substitute(lines[i], '-vst-escape-backtick-', '\\`', 'g')
				" Take care about "``"
				let lines[i] = substitute(lines[i], '-vst-quot-dbacktick-', '"``"', 'g')
				" Restore ` and _
				let lines[i] = substitute(lines[i], '&#96;', '`', 'g')
				let lines[i] = substitute(lines[i], '&#95;', '_', 'g')

			endif
			"if lines[i] =~ '\\'
			"	let lines[i] = VST_EscapingSlash(lines[i])
			"endif
			let i += 1
		endwhile
		let file = join(lines, '<vim:p')
		" Sometimes regexps are catching single _ as link. Remove such glitches
		let file = substitute(file, '<vim:a href="#l_" title="_">_</vim:a>', '_', 'g')
		" Sometimes regexps are catching \` as link. Remove such glitches
		let file = substitute(file, '<vim:a href="#l\\`" title="\\`">\\`</vim:a>', '\\`', 'g')
		" }}}
		" Create footnote and citation dbs: {{{
		" Go with stridx and strpart cutting file and retrieve information.
		" Necessary for LaTeX export.
		let fn = file
		while stridx(fn, '<vim:footnote') != -1
			let index = stridx(fn, '<vim:footnote')
			let fn = strpart(fn, index)
			let number = matchstr(fn, '<vim:div class="fnumber"><vim:a href="#target-\d\+" name="footnote-\d\+">\[\zs\d\+\ze\]</vim:a></vim:div>')
			let content = matchstr(fn, '<vim:div class="ftext">\zs.\{-}\ze\_s*</vim:div>')
			let g:vst_footnotedb[number] = content
			let fn = strpart(fn, 2)
		endwhile
		let fn = file
		while stridx(fn, '<vim:citation') != -1
			let index = stridx(fn, '<vim:citation')
			let fn = strpart(fn, index)
			let label = matchstr(fn, '<vim:div class="cnumber"><vim:a href="#ctarget-\k\+" name="citation-\k\+">\[\zs\k\+\ze\]</vim:a></vim:div>')
			let content = matchstr(fn, '<vim:div class="ctext">\zs.\{-}\ze\_s*</vim:div>')
			let g:vst_citationdb[label] = '['.label.'] '.content
			let fn = strpart(fn, 2)
		endwhile
		" }}}

		if len(g:vst_anonhlinkdb) > 0
			let file = VST_AnonHyperlink(file)
		endif

		" Process default roles
		let file = VST_DefaultRole(file)
		" Remove escaping slashes.
		let file = VST_EscapingSlash(file)

		" Removing - from 'isk'
		if b:vst_hyphenisk == 1
			set isk-=-
		endif
		unlet! b:vst_hyphenisk

		" Replace &#96; with `
		let file = substitute(file, '&#96;', '`', 'g')
		" Replace &#91; with [
		let file = substitute(file, '&#91;', '[', 'g')
		" Replace &#92; with \
		let file = substitute(file, '&#92;', '\\', 'g')
		" Replace &#95; with _
		let file = substitute(file, '&#95;', '_', 'g')
		" Replace &#46; with .
		let file = substitute(file, '&#46;', '.', 'g')
		" Replace &#124; with |
		let file = substitute(file, '&#124;', '|', 'g')
		" Replace &#58; with :
		let file = substitute(file, '&#58;', ':', 'g')

		" VST_URIMaker: Create real, properly encrypted URIs. {{{
		function! VST_URIMaker(uri)
			" Auxiliary functions lifted from eval.txt {{{
			" The function Nr2Hex() returns the Hex string of a number.
			func! Nr2Hex(nr)
			  let n = a:nr
			  let r = ""
			  while n
				let r = '0123456789ABCDEF'[n % 16] . r
				let n = n / 16
			  endwhile
			  return r
			endfunc
			" The function String2Hex() converts each character in a string to a two
			" character Hex string.
			func! String2Hex(str)
			  let out = ''
			  let ix = 0
			  while ix < strlen(a:str)
				let out = out . Nr2Hex(char2nr(a:str[ix]))
				let ix = ix + 1
			  endwhile
			  return out
			endfunc " }}}
			let uri = a:uri
			if uri =~ '^#'
				return uri
			endif
			" URI:
			if uri =~ '^[-_!~*():?;@&=+$.,/a-zA-Z0-9#]*$'
				return uri
			else
				let elements = split(uri, '#')
				let first = elements[0]
				if len(elements) > 1
					let rest = '#'.join(elements[1:-1], '#')
				else
					let rest = ''
				endif
				let link = split(first, '.\zs')
				let out = ''
				let ix = 0
				while ix < len(link)
					if link[ix] =~ '[-_!~*():?;@&=+$.,/a-zA-Z0-9#]'
						let out .= link[ix]
					elseif link[ix] =~ '%'
						" Bold assumption: all escape sequences I saw on the net
						" were uppercased
						if link[ix+1] =~ '[A-F0-9]' && link[ix+2] =~ '[A-F0-9]'
							let out .= link[ix] . link[ix+1] . link[ix+2]
							let ix = ix + 2
						else
							let out .= '%'.String2Hex('%')
						endif
					else
						let out .= '%'.String2Hex(link[ix])
					endif
					let ix += 1
				endwhile
			endif
			return out.rest
		endfunction
		" }}}
		let file = substitute(file, 'vim:\(img src="\|a href="\)\(.\{-}\)"', '\="vim:".submatch(1).VST_URIMaker(submatch(2))."\""', 'g')

		" Figure out proper MIME charset from the 'encoding' option. {{{
		if exists("g:vst_encoding")
			let encoding = g:vst_encoding
		else
			if &fileencoding != ''
				let encoding = &fileencoding
			else
				let encoding = &encoding
			endif
		endif
		if encoding =~ '^8bit\|^2byte'
			let encoding = substitute(s:vim_encoding, '^8bit-\|^2byte-', '', '')
		endif
		if encoding == 'latin1'
			let encoding = 'iso-8859-1'
		elseif encoding =~ "^cp12"
			let encoding = substitute(encoding, 'cp', 'windows-', '')
		elseif encoding == 'sjis'
			let encoding = 'Shift_JIS'
		elseif encoding == 'euc-cn'
			let encoding = 'GB_2312-80'
		elseif encoding == 'euc-tw'
			let encoding = ""
		elseif encoding == 'big5'
			let encoding = "Big5"
		elseif encoding =~ '^euc\|^iso\|^koi'
			let encoding = substitute(encoding, '.*', '\U\0', '')
		elseif encoding == 'cp949'
			let encoding = 'KS_C_5601-1987'
		elseif encoding == 'cp936'
			let encoding = 'GBK'
		elseif encoding =~ '^ucs\|^utf'
			let encoding = 'UTF-8'
		else
			let encoding = ""
		endif
		" }}}
		let filename = expand("%:r")
	endif

	if format =~ '^\(html\|s5\)$'
		" HTML export {{{

		let language = matchstr(v:lang, '.*\ze_')

		" CSS: {{{
		let rtp = split(&rtp, ',')
		for i in range(len(rtp))
			if filereadable(rtp[i].'/autoload/vst/default.css')
				let defcssfile = rtp[i].'/autoload/vst/default.css'
				break
			endif
		endfor

		let default_css = join(readfile(defcssfile), "\n")

		" g:vst_css_default g:vst_css_user
		if g:vst_css_default == '' && g:vst_css_user == ''
			let css = '<style type="text/css">'."\n".'/*<![CDATA[*/'."\n"
						\ .default_css."\n".'/*]]>*/'."\n".'</style>'
		endif

		if g:vst_css_default == '' && g:vst_css_user != ''
			let css = '<style type="text/css">'."\n".'/*<![CDATA[*/'."\n"
						\ .default_css."\n".'/*]]>*/'."\n".'</style>'
			let css .= '<link rel="stylesheet" href="'.g:vst_css_user.'" type="text/css" />'."\n"
		endif

		if g:vst_css_default != '' && g:vst_user_css == ''
			if g:vst_css_default !~ 'NONE'
				let completecss = ['/* Vim reStructured Text CSS */', ''] + split(default_css, '\n')
				call writefile(completecss, g:vst_css_default)
				let css = '<link rel="stylesheet" href="'.g:vst_css_default.'" type="text/css" />'."\n"
			else
				let css = "\n"
			endif
		endif

		if g:vst_css_default != '' && g:vst_css_user != ''
			if g:vst_css_default !~ 'NONE'
				let completecss = ['/* Vim reStructured Text CSS */', ''] + split(default_css, '\n')
				call writefile(completecss, g:vst_css_default)
				let css = '<link rel="stylesheet" href="'.g:vst_css_default.'" type="text/css" />'."\n"
			else
				let css = "\n"
			endif
			let css .= '<link rel="stylesheet" href="'.g:vst_css_user.'" type="text/css" />'."\n"
		endif
		" }}}

		" META Info {{{
		let metainfo = ''
		let metaauthor = ''
		let metatitle = ''
		let metasubject = ''
		let metakeywords = ''
		let metadate = ''
		if has_key(g:vst_fielddb, 'author')
			let metaauthor = '<meta name="Author" content="'.g:vst_fielddb['author']."\" />\n"
		endif
		if has_key(g:vst_fielddb, 'title')
			let metatitle = '<meta name="Title" content="'.g:vst_fielddb['title']."\" />\n"
		endif
		if has_key(g:vst_fielddb, 'keywords')
			let metakeywords = '<meta name="Keywords" content="'.g:vst_fielddb['keywords']."\" />\n"
		endif
		if has_key(g:vst_fielddb, 'subject')
			let metasubject = '<meta name="Subject" content="'.g:vst_fielddb['subject']."\" />\n"
		endif
		if has_key(g:vst_fielddb, 'date')
			if g:vst_fielddb['date'] != 'NONE'
				let metadate = '<meta name="Date" content="'.g:vst_fielddb['date']."\" />\n"
			endif
		endif
		let metainfo = metaauthor.metatitle.metakeywords.metasubject.metadate

		let metadata = ''
		for key in keys(g:vst_metadb)
			if key =~ '^http-equiv='
				let item = substitute(key, 'http-equiv=\(.*\)', 'http-equiv="\1"', '')
				let element = '<meta '.item.' content="'.g:vst_metadb[key].'" />'."\n"
			elseif key =~ '^description \(lang\|scheme\|dir\)'
				let item = substitute(key, 'description \(lang\|scheme\|dir\)=\(.*\)', 'name="description" \1="\2", '')
				let element = '<meta '.item.' content="'.g:vst_metadb[key].'" />'."\n"
			else
				let element = '<meta name="'.key.'" content="'.g:vst_metadb[key].'" />'."\n"
			endif
			let metadata .= element
		endfor

		if exists("g:vst_doc_title")
			let htmltitle = substitute(g:vst_doc_title, '^\s*', '', '')
            let htmltitle = VST_SpecCharacter(htmltitle)
		elseif metasubject != ''
			let htmltitle = g:vst_fielddb['subject']
		else
			let htmltitle = expand("%")
		endif
		" }}}

		" S5 special content {{{
		if format == 's5'
			if exists('s5footer')
				let s5foot = VST_Structure(split(s5footer, '0000000000000000000'))
				let s5foot = substitute(s5foot, '^\_s*<vim:p>\_s*', '', '')
				let s5foot = substitute(s5foot, '\_s*</vim:p>\_s*$', '', '')
				unlet! s5footer
			else
				if has_key(g:vst_fielddb, 'author')
					let s5author = g:vst_fielddb['author']
				else
					let s5author = 'Author'
				endif
				if has_key(g:vst_fielddb, 'date') && g:vst_fielddb['date'] != 'NONE'
					let s5date = g:vst_fielddb['date']
				else
					let s5date = 'Date'
				endif
				let s5foot = s5author.' &#8226; '.s5date
			endif
			let s5head = ''
					\.'<!-- configuration parameters -->'."\n"
					\.'<meta name="defaultView" content="slideshow" />'."\n"
					\.'<meta name="controlVis" content="hidden" />'."\n"
					\.'<meta name="version" content="S5 1.1" />'."\n"
					\.'<!-- style sheet links -->'."\n"
					\.'<link rel="stylesheet" href="s5ui/slides.css" type="text/css" media="projection" id="slideProj" />'."\n"
					\.'<link rel="stylesheet" href="s5ui/outline.css" type="text/css" media="screen" id="outlineStyle" />'."\n"
					\.'<link rel="stylesheet" href="s5ui/print.css" type="text/css" media="print" id="slidePrint" />'."\n"
					\.'<link rel="stylesheet" href="s5ui/opera.css" type="text/css" media="projection" id="operaFix" />'."\n"
					\.'<!-- S5 JS -->'."\n"
					\.'<script src="s5ui/slides.js" type="text/javascript"></script>'."\n"
					\.'<!-- VST-S5 -->'."\n"
					\.'<style type="text/css">'."\n"
					\.'/*<![CDATA[*/'."\n"
					\.'h1:before, h2:before, h3:before, h4:before, h5:before, h6:before { content: "" }'."\n"
					\.'/*]]>*/'."\n"
					\.'</style>'."\n"
			let s5body = ''
					\.'<div class="layout">'."\n"
					\.'<div id="controls"><!-- DO NOT EDIT --></div>'."\n"
					\.'<div id="currentSlide"><!-- DO NOT EDIT --></div>'."\n"
					\.'<div id="header"></div>'."\n"
					\.'<div id="footer">'."\n"
					\.'<h1>'.htmltitle.'</h1>'."\n"
					\.'<h2>'.s5foot.'</h2>'."\n"
					\.'</div>'."\n"
                    \.'</div>'."\n"
                    \.'<div class="presentation">'
			let s5body2 = "</div>\n</div>"
		else
			let s5body = ''
			let s5head = ''
			let s5body2 = ''
		endif
		" }}}

		let metainfo .= metadata

		if file =~ '<vim:ol[^>]*start="'
			let g:zzz = 1
			let doctype =
				\ '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"'."\n"
				\.'    "http://www.w3.org/TR/html4/loose.dtd">'."\n"
				"\ '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" '."\n"
				"\.'	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> '."\n"
		else
			let doctype = 
				\ '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN"'."\n"
				\.'    "http://www.w3.org/TR/html4/strict.dtd">'."\n"
				"\ '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" '."\n"
				"\.' "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">'."\n"
		endif

		let header = 
			\ doctype
			\.'<html xmlns="http://www.w3.org/1999/xhtml" lang="'.language.'" '
			\.'xml:lang="'.language.'">'."\n"
			\.'<head>'."\n"
			\.'<meta http-equiv="Content-Type" content="text/html; charset='.encoding.'" />'."\n"
			\.'<title>'.htmltitle.'</title>'."\n"
			\.'<meta name="Generator" content="Vim reStructured Text '.s:vst_ver.' - Vim '.v:version/100.".".v:version % 100.'" />'."\n"
			\.metainfo."\n"
			\.css."\n"
			\.s5head."\n"
			\.'</head>'."\n"
			\.'<body>'."\n"

		let closing = '</body>'."\n".'</html>'

		let file = header."\n".s5body."\n".file."\n".s5body2."\n".closing
		let file = substitute(file, '</vim:', '</', 'g')
		let file = substitute(file, '<vim:', '<', 'g')
		" let file = substitute(file, '\(\[\d\+\]</a>\)_', '\1', 'g')
		" let file = substitute(file, '\(\[#\]</a>\)_', '\1', 'g')
		
		" Create comment tags
		let file = substitute(file, '</comment>', ' -->', 'g')
		let file = substitute(file, '<comment.\{-}>', '<!-- ', 'g')

		" Replace rawlatex with pre tags
		"let file = substitute(file, '</rawlatex', '</pre', 'g')
		"let file = substitute(file, '<rawlatex>', '<pre class="rawlatex"', 'g')
		"let file = substitute(file, '<rawlatex class="\(.\{-}\)">', '<pre class="rawlatex \1">', 'g')
		" Remove rawlatex content
		let file = substitute(file, '<rawlatex.\{-}</rawlatex>', '', 'g')

		" Remove latexonly tags and contents
		let file = substitute(file, '<latexonly\.{-}>.\{-}</latexonly>', '', 'g')

		" Replace footnote and citation with div class="footnote"
		let file = substitute(file, '</footnote', '</div', 'g')
		let file = substitute(file, '<footnote>', '<div class="footnote">', 'g')
		let file = substitute(file, '<footnote class="\(.\{-}\)">', '<div class="footnote \1">', 'g')
		let file = substitute(file, '</citation', '</div', 'g')
		let file = substitute(file, '<citation>', '<div class="footnote">', 'g')
		let file = substitute(file, '<citation class="\(.\{-}\)">', '<div class="footnote \1">', 'g')

		" Replace topic with div
		let file = substitute(file, '</topic', '</div', 'g')
		let file = substitute(file, '<topic', '<div ', 'g')

		" Replace sidebar with div
		let file = substitute(file, '</sidebar', '</div', 'g')
		let file = substitute(file, '<sidebar', '<div ', 'g')

		" Replace figure with div
		let file = substitute(file, '</figure', '</div', 'g')
		let file = substitute(file, '<figure', '<div', 'g')

		" Replace block with div
		let file = substitute(file, '</block\>', '</div', 'g')
		let file = substitute(file, '<block\>', '<div', 'g')

		" Replace container with div
		let file = substitute(file, '</container\>', '</div', 'g')
		let file = substitute(file, '<container\>', '<div', 'g')

		" Replace unknown with div and header
		let file = substitute(file, '</unknown\>', '</div', 'g')
		let file = substitute(file, '<unknown>', '<div class="unknown"><strong>Unknown element:</strong><br />', 'g')

		" Replace pullquote with blockquote class
		let file = substitute(file, '</pullquote', '</blockquote', 'g')
		let file = substitute(file, '<pullquote>', '<blockquote class="pull">', 'g')
		let file = substitute(file, '<pullquote class="\(.\{-}\)">', '<blockquote class="pull \1">', 'g')

		" Replace rubric with span class
		let file = substitute(file, '</rubric', '</p', 'g')
		let file = substitute(file, '<rubric>', '<p class="rubric">', 'g')
		let file = substitute(file, '<rubric class="\(.\{-}\)">', '<p class="rubric \1">', 'g')

		" Turn field list (dl) into table.
		" This can be expensive set of regexps so check if this element exists
		" at all
		if file =~ 'dt class="field'
			let file = substitute(file, '<dl class="field\(.\{-}\)">', '<table class="field\1" summary="Field list">', 'g')
			let file = substitute(file, '\(<dd class="field.\{-}\n\)</dl>', '\1</table>', 'g')
			let file = substitute(file, '<dt class="field fabstract">Abstract<.dt><dd class="field fabstract">\(.\{-}\)<.dd>', '<tr><td class="fkey fakey" colspan="2">Abstract</td></tr><tr><td class="fval faval" colspan="2">\1</td></tr>', 'g')
			let file = substitute(file, '<dt class="field fdedication">Dedication<.dt><dd class="field fdedication">\(.\{-}\)<.dd>', '<tr><td class="fkey fdkey" colspan="2">Dedication</td></tr><tr><td class="fval fdval" colspan="2">\1</td></tr>', 'g')
			let file = substitute(file, '<dt class="field.\{-}>\(.\{-}\)<.dt><dd class="field.\{-}>\(.\{-}\)<.dd>', '<tr><td class="fkey">\1</td><td class="fval">\2</td></tr>', 'g')
		endif

		" Replace weird table summary value with proper <col /> tags
		let file = substitute(file, '<table\( class="vst.\{-}summary="\).\{-}coln\(.\{-}\)">', '\="<table".submatch(1)."\">".VST_ColNumbers(submatch(2))', 'g')
		" Remove class attribute from closing of dl list
		let file = substitute(file, '\(</dl\) class=".\{-}"', '\1', 'g')

		" Remove summary from td tags
		let file = substitute(file, '\(<td[^>]*\) summary=".\{-}"', '\1', 'g')

		" Remove rawhtml tags
		let file = substitute(file, '</rawhtml>', '', 'g')
		let file = substitute(file, '<rawhtml.\{-}>', '', 'g')

		" Remove rawboth tags
		let file = substitute(file, '</rawboth>', '', 'g')
		let file = substitute(file, '<rawboth.\{-}>', '', 'g')

		" Remove htmlonly tags
		let file = substitute(file, '</htmlonly>', '', 'g')
		let file = substitute(file, '<htmlonly.\{-}>', '', 'g')

		" Remove consecutive empty lines
		let file = substitute(file, '\n\n\{3,}', '\n\n', 'g')

		" Replace --(-) with emdash entity in attributions
		let file = substitute(file, '\(<p class="attribution.\{-}>\_s\{-}\)---\?', '\1\&#8212;', 'g')

		" Add backlinks from section headers
		if exists("b:IsTOC") && b:IsTOC == 1
			let file = substitute(file, '\(<h\d id="\)\(.\{-}\)"\(.\{-}>\)', '\1\2"\3<a href="#toc-\2">', 'g')
			let file = substitute(file, '<\/h\d>', '<\/a>\0', 'g')
			unlet! b:IsTOC
		endif

		new
		if &compatible == 1
			set nocompatible
		endif
		silent! 0put =file
		" Beautify HTML a bit:
		" Reduce indentation inside of <pre> tags to minimum of 1 space {{{
		silent call cursor(1,1)
		while search('^\s*<pre', 'W')
			let rawlatex = (getline('.') =~ 'class="rawlatex' ? 1 : 0)
			silent normal! j
			let line1 = line('.')
			let indlist = []
			while getline('.') !~ '</pre'
				if getline('.') =~ '^\s*$'
					silent normal! j
					continue
				endif
				let preind = strlen(matchstr(getline('.'), '^\s*'))
				let indlist += [preind]
				silent normal! j
			endwhile
			let line2 = line('.')-1
			" When pre is empty (closing tag is in next line after opening
			" tag) don't continue
			if line1 == line2 + 1
				continue
			endif
			let lineend = line('.')
			let ind = min(indlist) <= 0 ? 0 : min(indlist)
			silent exe line1.','.line2.'s/^ \{'.ind.'}/ /e'
			" Previously doubled \ was treated as escaped and reduced to one.
			" Now it is highly probable that one \ at the end of line was
			" supposed to be new line symbol.
			if rawlatex == 1
				silent exe line1.','.line2.'s/\\$/\\\\/e'
			endif
		endwhile
		" }}}
		" Put 2html CSS styles into head {{{
		silent call cursor(1,1)
		if search('<pre class="tohtml-[^"]\+">')
			call VST_2html()
			if exists('g:vst_2html_css')
				silent call cursor(1,1)
				let tohtml_css = '<style type="text/css">'."\n".'/*<![CDATA[*/'."\n"
					\ .join(g:vst_2html_css, "\n")."\n".'/*]]>*/'."\n".'</style>'
				call search('<\/head>')
				put! =tohtml_css
				unlet! g:vst_2html_css
			endif
		endif
		redraw!
		" }}}
		" Insert raw files {{{
		silent call cursor(1,1)
		while search('-vst-raw-file-placeholder:', 'W')
			let rawfile = matchstr(getline('.'), '-vst-raw-file-placeholder:\zs.*')
			let g:rf = rawfile
			silent s/.*//ge
			if filereadable(rawfile)
				exe 'silent read '.escape(rawfile, ' \#%')
			endif
		endwhile
		" }}}
		setlocal ft=html 

		" S5 postprocessing {{{
		if format == 's5'
			silent call cursor(1,1)
			silent call search('<div class="presentation">')
			let line = line('.')
			silent exe line.',$ s/<h1/<div class="slide">\r<h1/ge'
			silent exe line.',$ s/<h2/<div class="slide">\r<h1/ge'
			silent exe line.',$ s/<div class="slide">/<\/div>\r\0/ge'
			silent exe line.',$ s/<\/h2>/<\/h1>/ge'
			"silent g/<a href="http/s/<a href=".\{-}"/\0 class="external"/ge
			silent exe line
			silent exe line.',$ s/\(<div class="presentation">\)\_s*<\/div>/\1/ge'
			" Create s5ui directory and file structure
			if !isdirectory('s5ui')
				call mkdir('s5ui')
			endif
			let s5files = [
						\ 'blank.gif',
				  		\ 'framing.css',
				  		\ 'iepngfix.htc',
				  		\ 'opera.css',
				  		\ 'outline.css',
				  		\ 'pretty.css',
				  		\ 'print.css',
				  		\ 's5-core.css',
				  		\ 'slides.css',
				  		\ 'slides.js']
			let workingdir = expand('%:p:h').'/'
			for file in s5files
				if !filereadable('s5ui/'.file)
					let rtp = split(&rtp, ',')
					for i in range(len(rtp))
						if filereadable(rtp[i].'/autoload/vst/s5ui/'.file)
							let s5file = rtp[i].'/autoload/vst/s5ui/'.file
							break
						endif
					endfor
					silent exe 'below 1split '.escape(s5file, ' \#%')
					silent exe 'write! '.escape(workingdir' \#%').'s5ui/'.escape(file, ' \#%')
					silent exe 'bw! '.escape(s5file, ' \#%')
				endif
			endfor
			" Write file after changes
			silent exe 'cd '.escape(workingdir, ' \#%')

		endif
		" }}}
		if exists("g:vst_write_export") && g:vst_write_export != 0
			silent exe 'write! '.escape(filename, ' \#%').'.html'
		endif
		" User postprocessing
		if g:vst_html_post != '' && filereadable(g:vst_html_post)
			exe 'silent! source '.escape(g:vst_html_post, ' \#%')
		endif
		silent call cursor(1,1)
		call VST_End()
		" }}}
	elseif format == 'xml'
		" XML export {{{
		new
		silent 0put =file
		setlocal ft=xml
		if exists("g:vst_write_export") && g:vst_write_export != 0
			silent exe 'write! '.escape(filename, ' \#%').'.xml'
		endif
		silent call cursor(1,1)
		call VST_End()
		" }}}
	elseif format =~? '^re\?st$'
		" reST export {{{
		let rest_file = getline(1, '$')
		" Potential problems when size of register has limits. :help 'viminfo'
		new
		silent! 0put =rest_file
		unlet! rest_file
		silent! %s/\(^\s*\.\. \)block::/\1admonition::/ge
		silent! g/^\s*:identify:/d
		silent! %s/\(^\s*\)\(:\S.\{-}  \)/\1--VIM, \2/ge
		" <c-v>160 - non breaking space
		silent! %s/\\\@<!\\-/ /ge
		silent! %s/\(^\s*\)\.\. 2html::.*/\1::
		silent call cursor(1,1)
		" }}}
	elseif format =~ '^\(tex\|pdf\)$'
		" LaTeX export {{{
		"
		function! VST_CreateTexComment(text)
			let scomm = split(a:text, '\n')
			let i = 0
			while i < len(scomm)
				let scomm[i] = substitute(scomm[i], '^', '%%', '')
				let i += 1
			endwhile
			let par = join(scomm, '\n')
			return par
		endfunction

		" Handle encoding and country options. {{{
		let encoding = tolower(encoding)
		if encoding =~ 'iso-8859-1\|iso-8859-15'
			let encoding = 'latin1'
		elseif encoding =~ "windows-"
			let encoding = substitute(encoding, 'windows-', , 'cp', '')
		elseif encoding == 'iso-8859-2'
			let encoding = 'latin2'
		elseif encoding == 'sjis'
			let encoding = 'Shift_JIS'
		elseif encoding == 'euc-cn'
			let encoding = 'GB_2312-80'
		elseif encoding == 'euc-tw'
			let encoding = ""
		elseif encoding =~ '^euc\|^iso\|^koi'
			let encoding = substitute(encoding, '.*', '\U\0', '')
		elseif encoding == 'cp949'
			let encoding = 'KS_C_5601-1987'
		elseif encoding == 'cp936'
			let encoding = 'GBK'
		elseif encoding =~ '^ucs\|^utf'
			let encoding = 'UTF-8'
		else
			let encoding = ""
		endif

		" Country specific settings
		" Automatically add polski when iso-8859-2 is used.
		if encoding =~ 'latin2\|cp1250'
			let countrysettings = '\usepackage{polski}'
		else
			let countrysettings = ''
		endif
		" }}}

		" TOC depth
		if exists("s:vst_tocdepth")
			let tocdepth = '\setcounter{tocdepth}{'.s:vst_tocdepth.'}'
		else
			let tocdepth = ''
		endif

		" User defined preamble
		if exists("g:vst_tex_preamble") && filereadable(g:vst_tex_preamble)
			let userpreamble = "\\input{".g:vst_tex_preamble."}"
		else
			let userpreamble = ''
		endif

		let footer = '\end{document}'

		"let file = substitute(file, "><", ">\n<", "g")
		" Special characters I
		" Here to not catch any backslashes
		let file = substitute(file, '\', '$\\backslash$', 'g')
		" Here to not catch footnotes
		let file = substitute(file, '{', '\\{', 'g')
		let file = substitute(file, '}', '\\}', 'g')

		" Remove special chars catchers
		let file = substitute(file, '&#64;', '@', 'g')
		let file = substitute(file, '&#91;', '[', 'g')
		let file = substitute(file, '&#92;', '\\', 'g')
		let file = substitute(file, '&#58;', ':', 'g')
		let file = substitute(file, '&\\#64;', '@', 'g')
		let file = substitute(file, '&\\#91;', '[', 'g')
		let file = substitute(file, '&\\#92;', '\\', 'g')
		let file = substitute(file, '&\\#58;', ':', 'g')

		" Footnotes have to be here to process them by other substitutions:
		for fn in keys(g:vst_footnotedb)
			let fnumberleft = '<vim:a href="#footnote-'.fn.'" name="target-'.fn.'">\['
			let fnumberright = '\]</vim:a>'
			let content = escape(g:vst_footnotedb[fn], '&/\~')
			let file = substitute(file, fnumberleft.fn.fnumberright, '\\footnote{'.content.'}', '')
		endfor
		" Citations have to be here to process them by other substitutions:
		for fn in keys(g:vst_citationdb)
			let fnumberleft = '<vim:a href="#citation-'.fn.'" name="ctarget-'.fn.'">\['
			let fnumberright = '\]</vim:a>'
			let content = escape(g:vst_citationdb[fn], '&/\~')
			let file = substitute(file, fnumberleft.fn.fnumberright, '\\footnote{'.content.'}', '')
		endfor
		" Remove footnotes from xml
		let file = substitute(file, '<vim:footnote.\{-}</vim:footnote>', '', 'g')
		" Remove citations from xml
		let file = substitute(file, '<vim:citation.\{-}</vim:citation>', '', 'g')

		" Replace rawhtml with pre tags
		"let file = substitute(file, '<vim:rawhtml>', '<vim:pre>', 'g')
		"let file = substitute(file, '<.vim:rawhtml>', '</vim:pre>', 'g')

		" Replace rawhtml with htmlonly tags
		let file = substitute(file, '<vim:rawhtml>', '<vim:htmlonly>', 'g')
		let file = substitute(file, '<.vim:rawhtml>', '</vim:htmlonly>', 'g')

		" Remove htmlonly tags and contents
		let file = substitute(file, '<vim:htmlonly>.\{-}<.vim:htmlonly>', '', 'g')


		" Special characters II
		let file = substitute(file, '\~', '\\\~{}', 'g')
		let file = substitute(file, '&nbsp;', '\~', 'g')
		let file = substitute(file, '&amp;', '\\\&', 'g')
		let file = substitute(file, '&lt;', '<', 'g')
		let file = substitute(file, '&gt;', '>', 'g')
		let file = substitute(file, '&copy;', '(c)', 'g')
		let file = substitute(file, '#', '\\#', 'g')
		let file = substitute(file, '\(backslash\)\@<!\$\(.backslash\)\@!', '\\$', 'g')
		let file = substitute(file, '%', '\\%', 'g')
		let file = substitute(file, '\^', '\\^{}', 'g')
		" Hah. This will break _ in links. Problem may exists also with &amp
		let file = substitute(file, '_', '\\_', 'g')
		" TeX symbols
		let file = substitute(file, 'LaTeX', '\\LaTeX{}', 'g')
		let file = substitute(file, 'a\@<!TeX', '\\TeX{}', 'g')
		" Very dirty hack to compile docs but should fix also other things.
		" Maybe not so common but very hard to spot when proofreading text.
		let file = substitute(file, '>\\<', '>\\\\<', 'g')
		let file = substitute(file, '\(^\|\s\)\\\($\|\s\)', '\1\\\2', 'g')
		"
		let file = substitute(file, "^", '\\begin{document}'."\n", "")

		" Create subtitles
		let file = substitute(file, '<vim:p class="subh.\{-}>\(.\{-}\)</vim:p>', '\\subtitle{\1}', "g")

		" Create verse environment
		let file = substitute(file, '<vim:p class="verse.\{-}>\(.\{-}\)</vim:p>', '\\begin{verse}\n\1\n\\end{verse}', "g")

		" Create attributions
		let file = substitute(file, '<vim:p class="attribution.\{-}>\(.\{-}\)</vim:p>', '\\attribution{\1}', "g")
		
		" Replace table of contents
		let file = substitute(file, '<vim:p id="tocheader" \_.\{-}\.\. comment:: end of toc -->', '\n\\tableofcontents', '')

		" Replace new line tags <vim:br>
		let file = substitute(file, '\n\s*<vim:br.\{-}>\s*\n', '\n\n', "g")
		let file = substitute(file, '<vim:br.\{-}>', '\\\\', "g")

		" Title
		let file = substitute(file, '<vim:h1.\{-}>\_s*\(.\{-}\)</vim:h1>', '\\title{\1}\n\\maketitle', "g")
		" Sections
		let file = substitute(file, '<vim:h2 id="\(.\{-}\)".\{-}>', '\\hypertarget{\1}{}\n\\section{', "g")
		let file = substitute(file, '<vim:h3 id="\(.\{-}\)".\{-}>', '\\hypertarget{\1}{}\n\\subsection{', "g")
		let file = substitute(file, '<vim:h4 id="\(.\{-}\)".\{-}>', '\\hypertarget{\1}{}\n\\subsubsection{', "g")
		let file = substitute(file, '<vim:h5 id="\(.\{-}\)".\{-}>', '\\hypertarget{\1}{}\n\\paragraph{', "g")
		let file = substitute(file, '<vim:h6 id="\(.\{-}\)".\{-}>', '\\hypertarget{\1}{}\n\\subparagraph{', "g")
		let file = substitute(file, '<.vim:h[1-6]>', '}', 'g')

		" Rawlatex directive
		" Ha. I didn't anticipate this - special chars inside of rawlatex will be
		" escaped. Operating on string is faster than going through file line
		" by line so unescaping of chars in while loop similar to pre handling still
		" should be faster.
		let file = substitute(file, '<vim:rawlatex>', '% Begin rawlatex', "g")
		let file = substitute(file, '<.vim:rawlatex>', '% End rawlatex', "g")
		" And the same for latexonly
		let file = substitute(file, '<vim:latexonly>', '% Begin rawlatex', "g")
		let file = substitute(file, '<.vim:latexonly>', '% End rawlatex', "g")
		" And the same for rawboth
		let file = substitute(file, '<vim:rawboth>', '% Begin rawlatex', "g")
		let file = substitute(file, '<.vim:rawboth>', '% End rawlatex', "g")

		" Lists
		let file = substitute(file, '<vim:li.\{-}>', '\\item ', 'g')
		let file = substitute(file, '<.vim:li>', "", "g")
		let file = substitute(file, '<vim:ul.\{-}>', '\\begin{itemize}', "g")
		let file = substitute(file, '<.vim:ul.\{-}>', '\\end{itemize}', "g")
		" Enumitem and enumerate are in conflict. It has to be one or the
		" other
		if file =~ 'vim:ol class="[^>]\{-}start="'
			let file = substitute(file, '<vim:ol class="loweralpha[^>]\{-}start="\(\d\+\)">', '\\begin{enumerate}[label=\\alph*.,start=\1]', "g")
			let file = substitute(file, '<vim:ol class="upperalpha[^>]\{-}start="\(\d\+\)">', '\\begin{enumerate}[label=\\Alph*.,start=\1]', "g")
			let file = substitute(file, '<vim:ol class="lowerroman[^>]\{-}start="\(\d\+\)">', '\\begin{enumerate}[label=\\roman*.,start=\1]', "g")
			let file = substitute(file, '<vim:ol class="upperroman[^>]\{-}start="\(\d\+\)">', '\\begin{enumerate}[label=\\Roman*.,start=\1]', "g")
			let file = substitute(file, '<vim:ol class="decimal[^>]\{-}start="\(\d\+\)">', '\\begin{enumerate}[label=\\arabic*.,start=\1]', "g")
			let file = substitute(file, '<vim:ol class="loweralpha.\{-}>', '\\begin{enumerate}[label=\\alph*.]', "g")
			let file = substitute(file, '<vim:ol class="upperalpha.\{-}>', '\\begin{enumerate}[label=\\Alph*.]', "g")
			let file = substitute(file, '<vim:ol class="lowerroman.\{-}>', '\\begin{enumerate}[label=\\roman*.]', "g")
			let file = substitute(file, '<vim:ol class="upperroman.\{-}>', '\\begin{enumerate}[label=\\Roman*.]', "g")
			let file = substitute(file, '<vim:ol.\{-}>', '\\begin{enumerate}[label=\\arabic*.]', "g")
			let listings = 'enumitem'
		else
			let file = substitute(file, '<vim:ol class="loweralpha.\{-}>', '\\begin{enumerate}[a.]', "g")
			let file = substitute(file, '<vim:ol class="upperalpha.\{-}>', '\\begin{enumerate}[A.]', "g")
			let file = substitute(file, '<vim:ol class="lowerroman.\{-}>', '\\begin{enumerate}[i.]', "g")
			let file = substitute(file, '<vim:ol class="upperroman.\{-}>', '\\begin{enumerate}[I.]', "g")
			let file = substitute(file, '<vim:ol.\{-}>', '\\begin{enumerate}[1.]', "g")
			let listings = 'enumerate'
		endif
		let file = substitute(file, '<.vim:ol>', '\\end{enumerate}', "g")

		" Field lists
		let file = substitute(file, '<vim:dl class="field.\{-}>', '\\begin{deflist}{Keywords:}\n', 'g')
		let file = substitute(file, '<vim:dt class="field.\{-}>\(.\{-}\)</vim:dt>', '\\item[\1]', 'g')
		let file = substitute(file, '<vim:dd class="field.\{-}>', '', 'g')
		let file = substitute(file, '</vim:dd>', '', 'g')
		let file = substitute(file, "</vim:dl>", '\\end{deflist}', 'g')

		" Option lists
		let file = substitute(file, '<vim:dl class="option">', '\\begin{optlist}{longoptionslist}\n', 'g')
		let file = substitute(file, '<vim:dt>\(.\{-}\)</vim:dt>', '\\item[\1]', 'g')
		let file = substitute(file, '<vim:dt class="option">\(.\{-}\)</vim:dt>', '\\item[\1]', 'g')
		let file = substitute(file, '<vim:dd class="option">', '', 'g')
		let file = substitute(file, '<vim:dd>', '', 'g')
		let file = substitute(file, "</vim:dl class=\"option\">", '\\end{optlist}', 'g')

		" Definition lists
		let file = substitute(file, '<vim:dl>', '\\begin{deflist}{iii}', 'g')
		let file = substitute(file, '<vim:dt class="normal">\(.\{-}\)</vim:dt>', '\\item[\1]', 'g')
		let file = substitute(file, '<vim:dd class="normal">', '', 'g')
		let file = substitute(file, '</vim:dd>', '', 'g')
		"let file = substitute(file, "</vim:dl>", '\\end{deflist}', 'g')
		"
		" Rubric
		let file = substitute(file, '<vim:rubric.\{-}>', '\\rubric{ ', "g")
		let file = substitute(file, "</vim:rubric>", ' }', "g")

		" Pull-quote
		let file = substitute(file, '<vim:pullquote>', '\\begin{pullquote}', "g")
		let file = substitute(file, "</vim:pullquote>", '\\end{pullquote}', "g")

		" Blockquote
		let file = substitute(file, "<vim:blockquote.\\{-}>", '\\begin{quotation}', "g")
		let file = substitute(file, "</vim:blockquote>", '\\end{quotation}', "g")

		" Text styles
		let file = substitute(file, '<vim:em.\{-}>', '\\emph{', "g")
		let file = substitute(file, "</vim:em>", "}", "g")
		let file = substitute(file, '<vim:strong.\{-}>', '\\textbf{', "g")
		let file = substitute(file, "</vim:strong>", "}", "g")
		let file = substitute(file, '<vim:code.\{-}>', '\\texttt{', "g")
		let file = substitute(file, "</vim:code>", "}", "g")

		" Tables
		let file = substitute(file, '<vim:table class="\(.\{-}\)" summary=".\{-}coln\(.\{-}\)">', '\\setlongtables\n\\begin{center}\n\\begin{longtable}[c]{\1coln\2}\\hline\n', "g")
		let file = substitute(file, "<vim:thead>", '', "g")
		let file = substitute(file, "</vim:thead>", '\\endhead', "g")
		let file = substitute(file, "<vim:tfoot>", '', "g")
		let file = substitute(file, "</vim:tfoot>", '', "g")
		let file = substitute(file, "</vim:table>", '\\end{longtable}\n\\end{center}', "g")
		let file = substitute(file, '<vim:tr>\n\?<vim:td>', '', "g")
		let file = substitute(file, '<vim:td>', ' \& ', "g")
		let file = substitute(file, "</vim:tr>", ' \\\\ \\hline', "g")
		let file = substitute(file, '<vim:tr>\n\?<vim:td colspan="\(.\{-}\)".\{-} summary="\(.\{-}\)">\(.\{-}\)\_s*</vim:td>', '\n\\multicolumn{\1}{|p{0.\2\\textwidth}|}{\3}', "g")
		let file = substitute(file, '<vim:td colspan="\(.\{-}\)".\{-} summary="\(.\{-}\)">\(.\{-}\)\_s*</vim:td>', ' \& \\multicolumn{\1}{p{0.\2\\textwidth}|}{\3}', "g")
		let file = substitute(file, "</vim:td>", '', "g")

		" Line
		" \transition allows for easy change of transition display, eg. for
		" fancy graphics
		let file = substitute(file, "<vim:hr.\\{-}>", '\\transition', "g")

		" Comment
		let file = substitute(file, "<vim:!--", '% ', "g")

		" Links
		let file = substitute(file, '<vim:a href="\(#\)\?\(.\{-}\)".\{-}>\(.\{-}\)</vim:a>', '\\href{\2}{\3}', 'g')
		let file = substitute(file, '<vim:span id="\(.\{-}\)".\{-}>\(.\{-}\)</vim:span>', '\\hypertarget{\1}{\2}', 'g')

		" Subscript, superscript
		let file = substitute(file, '<vim:sub.\{-}>\(.\{-}\)</vim:sub>', '\\subs{\1}', 'g')
		let file = substitute(file, '<vim:sup.\{-}>\(.\{-}\)</vim:sup>', '\\sups{\1}', 'g')

		" Fix address special field
		let file = substitute(file, '<vim:pre class="address">\(.\{-}\)</vim:pre>', '\1', 'g')

		" Replace unknown with pre elements in frame
		let file = substitute(file, '<vim:unknown>', '<vim:span class="big">Unknown element</vim:span>\n<vim:pre>', 'g')
		let file = substitute(file, '</vim:unknown>', '</vim:pre>', 'g')

		" Title-reference role (<vim:cite>)
		let file = substitute(file, '<vim:cite.\{-}>', '\\emph{', 'g')
		let file = substitute(file, '</vim:cite>', '}', 'g')

		" Class big, small
		let file = substitute(file, '<vim:span class="big.\{-}>', '{\\large ', 'g')
		let file = substitute(file, '<vim:span class="small.\{-}>', '{\\small ', 'g')
		let file = substitute(file, '</vim:span>', '}', 'g')

		" Figure
		let file = substitute(file, '<vim:figure.\{-}>', '\\begin{center}\n\\begin{minipage}{0.6\\textwidth}', 'g')
		let file = substitute(file, '</vim:figure>', '\\end{minipage}\n\\end{center}', 'g')

		" Create ghost commands for custom block directives
		let file = substitute(file, '<vim:block.\{-}class="\(.\{-}\)">', '\\vst\1{', 'g')
		let file = substitute(file, '</vim:block>', '}', 'g')

		" Create ghost commands for custom container directives
		let file = substitute(file, '<vim:container.\{-}class="\(.\{-}\)">', '\\vst\1{', 'g')
		let file = substitute(file, '</vim:container>', '}', 'g')

		" Topic
		let file = substitute(file, '<vim:topic.\{-}>', '\\hfill\\begin{minipage}{0.9\\textwidth}', 'g')
		let file = substitute(file, '</vim:topic>', '\\end{minipage}', 'g')

		" Sidebar
		let file = substitute(file, '<vim:sidebar.\{-}>', '\\hfill\\begin{minipage}{0.9\\textwidth}', 'g')
		let file = substitute(file, '</vim:sidebar>', '\\end{minipage}', 'g')

		" Divs
		let file = substitute(file, '<vim:div.\{-}>', '\\begin{center}\n\\fbox{\\begin{minipage}{0.8\\textwidth}', 'g')
		let file = substitute(file, '</vim:div>', '\\end{minipage}}\n\\end{center}', 'g')
		" Div titles (<vim:span> was already replaced)
		let file = substitute(file, '<vim:span class="notetitle">\(.\{-}\)}', '\\textbf{\\sffamily\\large \1}\n\\vspace{2mm}', 'g')

		" Remove rest of vim:span
		" let file = substitute(file, '<vim:span.\{-}>', '\\emph{', 'g')
		let file = substitute(file, '<vim:span class="\(.\{-}\)">', '\\vst\1{', 'g')

		" Replace empty vim:p tags when hypertargets
		let file = substitute(file, '<vim:p id="\(.\{-}\)"></vim:p>', '\\hypertarget{\1}{}', "g")
		" Ignore all other <vim:p> tags
		let file = substitute(file, '<.\?vim:p\>.\{-}>', "", "g")

		" Make sure no (La)TeX entity is in URL address of hyperlinks
		let file = substitute(file, '\\href{\([^}]\{-}\)\\\(La\)\?TeX{}', '\\href{\1\2TeX', 'g')
		let file = substitute(file, '\\hypertarget{\([^}]\{-}\)\\\(La\)\?TeX{}', '\\hypertarget{\1\2TeX', 'g')
		" Unescape _ from hyperlinks
		let file = substitute(file, '\\href{\([^}]\{-}\)\\_', '\\href{\1_', 'g')
		let file = substitute(file, '\\hypertarget{\([^}]\{-}\)\\_', '\\hypertarget{\1_', 'g')
		" Prepare newcommands from roles
		if exists("g:vst_roledb")
			let rolenewcommands = '%% Commands for content of roles directives'."\n"
			let rolekeys = keys(g:vst_roledb)
			for i in range(len(rolekeys))
				let name = g:vst_roledb[rolekeys[i]]
				let rolenewcommands .= '\newcommand{\vst'.name.'}[1]{\textnormal{#1}}'."\n"
			endfor
			unlet! rolekeys
			unlet! name
		else
			let rolenewcommands = "\n"
		endif
		" Prepare newcommands from containers
		if len("g:vst_containers") > 0
			let containernewcommands = '%% Commands for content of container directives'."\n"
			let usednames = ''
			for name in g:vst_containers
				if usednames !~ ','.name.','
					let usednames .= ','.name.','
					let containernewcommands .= '\newcommand{\vst'.name.'}[1]{#1}'."\n"
				endif
			endfor
		else
			let containernewcommands = "\n"
		endif

		" Preamble {{{
		" This one is better for deflist but has some not nice side effects
		" which have to be worked out
		"\.'{\renewcommand{\makelabel}[1]{\parbox[b]{\labelwidth}{\makebox[0pt][l]{\textbf{##1}}\mbox{}\\}}'."\n"
		let preamble = 
			\ '\documentclass[12pt]{article}'."\n"
			\.'%% Generated by Vim reStructured Text '.s:vst_ver.' - Vim '.v:version/100.".".v:version % 100."\n"
			\.'\usepackage[a4paper,margin=2.5cm,nohead]{geometry}'."\n"
			\.'\usepackage{'.listings."}\n"
			\.'\usepackage{graphicx}'."\n"
			\.'\usepackage{longtable}'."\n"
			\.'\usepackage{tabularx}'."\n"
			\.'\usepackage{amsmath}'."\n"
			\.'\usepackage['.encoding."]{inputenc}\n"
			\.countrysettings."\n"
			\.'\newenvironment{deflist}[1]{%'."\n"
			\.'\begin{list}{}'."\n"
			\.'{\renewcommand{\makelabel}[1]{\textbf{##1}\hfill}'."\n"
			\.'\settowidth{\labelwidth}{\textbf{#1}}'."\n"
			\.'\leftmargin=\labelwidth'."\n"
			\.'\advance \leftmargin\labelsep}}'."\n"
			\.'{\end{list}}'."\n"
			\.'\newenvironment{optlist}[1]{%'."\n"
			\.'\begin{list}{}'."\n"
			\.'{\renewcommand{\makelabel}[1]{\texttt{##1}\hfill}'."\n"
			\.'\settowidth{\labelwidth}{\texttt{#1}}'."\n"
			\.'\leftmargin=\labelwidth'."\n"
			\.'\advance \leftmargin\labelsep}}'."\n"
			\.'{\end{list}}'."\n"
			\.'\newenvironment{pullquote}{\begin{quotation}\Large}{\end{quotation}}'."\n"
			\.'\setlength{\extrarowheight}{2pt}'."\n"
			\.tocdepth."\n"
			\.'\newcommand{\transition}{\begin{center}\rule{.8\textwidth}{0.2pt}\end{center}}'."\n"
			\.'\newcommand{\subtitle}[1]{{\large\textsc{#1}}\vskip15pt}'."\n"
			\.'\newcommand{\subs}[1]{\raisebox{-0.7ex}{\footnotesize #1}}'."\n"
			\.'\newcommand{\sups}[1]{\raisebox{0.7ex}{\footnotesize #1}}'."\n"
			\.'\newcommand{\attribution}[1]{\raggedleft\textit{#1}}'."\n"
			\.'\newcommand{\rubric}[1]{\vskip15pt{\large #1}}'."\n"
			\.rolenewcommands."\n"
			\.containernewcommands."\n"
			\.userpreamble."\n"
			\.'\usepackage[pdftex]{hyperref}'."\n"
		" Additional data {{{
		let author = ''
		let data = ''
		if has_key(g:vst_fielddb, 'author')
			let author = '\author{'.g:vst_fielddb['author'].'}'."\n"
		endif
		if has_key(g:vst_fielddb, 'date')
			if g:vst_fielddb['date'] == 'NONE'
				let g:vst_fielddb['date'] = ''
			endif
			let data = '\date{'.g:vst_fielddb['date'].'}'."\n"
		else
			let data = ''
		endif
		" }}}
		" PDF Info {{{
		let pdfinfo = ''
		let pdfauthor = ''
		let pdftitle = ''
		let pdfsubject = ''
		let pdfkeywords = ''
		if has_key(g:vst_fielddb, 'author')
			let pdfauthor = 'pdfauthor={'.g:vst_fielddb['author']."},\n"
		endif
		if has_key(g:vst_fielddb, 'title')
			let pdftitle = 'pdftitle={'.g:vst_fielddb['title']."},\n"
		endif
		if has_key(g:vst_fielddb, 'keywords')
			let pdfkeywords = 'pdfkeywords={'.g:vst_fielddb['keywords']."},\n"
		endif
		if has_key(g:vst_fielddb, 'subject')
			let pdfsubject = 'pdfsubject={'.g:vst_fielddb['subject']."}"
		endif
		for key in keys(g:vst_metadb)
			if key =~ 'author' && pdfauthor == ''
				let pdfauthor = 'pdfauthor={'.g:vst_metadb[key]."},\n"
			elseif key =~ 'title' && pdftitle == ''
				let pdftitle = 'pdftitle={'.g:vst_metadb[key]."},\n"
			elseif key =~ 'keywords' && pdfkeywords == ''
				let pdfkeywords = 'pdfkeywords={'.g:vst_metadb[key]."},\n"
			elseif key =~ 'subject' && pdfsubject == ''
				let pdfsubject = 'pdfsubject={'.g:vst_metadb[key]."}"
			endif
		endfor

		if exists("g:vst_doc_title")
			let pdftitle = 'pdftitle={'.substitute(g:vst_doc_title, '^\s*', '', '')."},\n"
		endif
				
		let pdfinfo = "\\hypersetup{\npdfcreator={VST, LaTeX, hyperref},\n"
			\."bookmarksopen=true,\nbookmarksopenlevel=2,\n"
			\."colorlinks=true,urlcolor=blue,\n"
			\.pdfauthor.pdftitle.pdfkeywords.pdfsubject."}\n"

		let file = preamble."\n".pdfinfo."\n".author.data."\n".file."\n".footer
		" }}}
		" }}}
		
		" Create comments
		let file = substitute(file, '<vim:comment>\(.\{-}\)<.vim:comment>', '\=VST_CreateTexComment(submatch(1))', 'g')

		new
		if &compatible == 1
			set nocompatible
		endif
		0put =file

		" Go through tables to tune them {{{
		" 1. Create preamble of table
		" 2. Remove \hline for borderless tables
		silent call cursor(1,1)
		while search('begin{longtable', 'W')
			unlet! line1 line2
			let line1 = line('.')
			if getline('.') =~ 'vstbordercoln'
				"silent exe line1.','.line2.'s/\(multicolumn{\d\+}{\)\(.\{-}\)}/\=submatch(1).substitute(submatch(2), "\\(\\d\\+\\)+", "|p{0.\\1\\\\\\\\textwidth}", "g")."}"/ge'
				silent s/vstbordercoln\(.\{-}\)}/\='|'.substitute(submatch(1), '\(\d\+\)+', 'p{0.\1\\\\textwidth}|', 'g').'}'/e
				call search('end{longtable', 'W')
				let line2 = line('.')
				"silent exe line1.','.line2.'s/\(multicolumn{\d\+}{\)\(.\{-}\)}/\=submatch(1).substitute(submatch(2), "\\(\\d\\+\\)+", "|p{0.\\1\\\\\\textwidth}", "g")."}"/ge'
				"silent exe line1.','.line2.'s/\(\& \\multicolumn{\d\+}{\)|/\1/ge'
			elseif getline('.') =~ 'vstblesscoln'
				silent s/vstblesscoln\(.\{-}\)}/\=substitute(submatch(1), '\(\d\+\)+', 'p{0.\1\\\\textwidth} ', 'g').'}'/e
				call search('end{longtable', 'W')
				let line2 = line('.')
				silent exe line1.','.line2.'s/\\hline\($\|\\end{longtable\)/\1/e'
				silent exe line1.','.line2.'g/\\multicolumn/s/\(\\textwidth}\)|/\1/ge'
				silent exe line1.','.line2.'g/\\multicolumn/s/\(\\multicolumn{\d\+}{\)|/\1/ge'
			endif
			" NOTE: this changes range so line1, line2 are useless after that
			silent exe line1.','.line2.'s/\_s*&\_s*/\r\&\r/ge'
		endwhile
		" }}}
		" Process <img> {{{
		silent call cursor(1,1)
		while search('<vim:img', 'W') != 0
			let image = getline('.')
			let imagelink = 0
			" Detect if image is link. It requires messing with order of
			" elements
			if getline(line('.')-1) =~ 'href.*{$'
				let imagelink = 1
				let link = getline(line('.')-1)
			endif
			let class = matchstr(image, 'class="\zs.\{-}\ze"')
			let src = matchstr(image, 'src="\zs.\{-}\ze"')
			let width = matchstr(image, 'width="\zs.\{-}\ze"')
			let height = matchstr(image, 'height="\zs.\{-}\ze"')
			if width == '' && height == ''
				let dimensions = ''
			elseif width != '' && height == ''
				let dimensions = '[width='.width.'pt]'
			elseif height != '' && width == ''
				let dimensions = '[height='.height.'pt]'
			else
				let dimensions = '[height='.height.'pt, width='.width.'pt]'
			endif
			let figure = '\\includegraphics'.dimensions.'{'.src.'}'
			let alt = ''
			let title = ''
			let opening = ''
			let caption = ''
			let closing = ''
			if class !~ 'inline'
				let alt = matchstr(image, 'alt="\zs.\{-}\ze"')
				let title = matchstr(image, 'title="\zs.\{-}\ze"')
				let opening = '\\begin{figure}[ht]\\centering'
				if title != ''
					let caption = '\\caption{'.title.'}'
				"elseif alt != ''
					"let caption = '\\caption{'.alt.'}'
				else
					let caption = ''
				endif
				let closing = '\\end{figure}'
			endif
			if imagelink != 0
				let link = escape(link, '\')
				let imagestring = opening.link.figure.'}'.caption.closing
				" Remove href end closing }, it require jumping between the
				" lines.
				silent .-1s/.*//e
				silent .+2s/.*//e
				silent normal! k
			else
				let imagestring = opening.figure.caption.closing
			endif
			silent exe 's+<vim:img.\{-}>+'.imagestring.'+e'
			silent normal! j
		endwhile
		" }}}
		" Processing preformatted text. {{{
		" Not using verbatim because it is
		" in conflict with minipages
		silent call cursor(1,1)
		while search('^\s*<vim:pre', 'W')
			silent s+.*+\\begin{ttfamily}\\begin{flushleft}+
			silent normal! j
			let line1 = line('.')
			let indlist = []
			while getline('.') !~ '</vim:pre'
				if getline('.') =~ '^\s*$'
					silent normal! j
					continue
				endif
				let preind = strlen(matchstr(getline('.'), '^\s*'))
				let indlist += [preind]
				silent normal! j
			endwhile
			let line2 = line('.')-1
			if line2 < line1
				let line2 = line1
			endif
			let lineend = line('.')
			let ind = min(indlist) <= 0 ? 0 : min(indlist)
			silent exe line1.','.line2.'s/^ \{'.ind.'}/ /e'
			silent exe line1.','.line2.'s+^+\\mbox{+e'
			silent exe line1.','.line2.'s+$+}\\\\+e'
			silent exe line1.','.line2.'s/ /\~/ge'
			silent exe lineend's+.*+\\end{flushleft}\\end{ttfamily}+'
		endwhile
		" }}}
		" Unescaping special chars from rawlatex. {{{
		silent call cursor(1,1)
		while search('^\s*% Begin rawlatex', 'W')
			silent normal! j
			let line1 = line('.')
			while getline('.') !~ '% End rawlatex'
				silent normal! j
			endwhile
			let line2 = line('.')-1
			silent exe line1.','.line2.'s/^\s\+//e'
			silent exe line1.','.line2.'s/\$\\backslash\$/\\/ge'
			silent exe line1.','.line2.'s/\\\$/$/ge'
			silent exe line1.','.line2.'s/\\\({\|\}\)/\1/ge'
			silent exe line1.','.line2.'s/\\\^{}/^/ge'
			silent exe line1.','.line2.'s/\\\~{}/\~/ge'
			silent exe line1.','.line2.'s/\\#/#/ge'
			silent exe line1.','.line2.'s/\\%/%/ge'
			silent exe line1.','.line2.'s/\\_/_/ge'
			" Hack to workaround inner slash escaping mechanism. consider
			" single backslash at the end of line as double backslash meaning
			" 'new line'
			silent exe line1.','.line2.'s/\\$/\\\\/ge'
		endwhile
		" }}}
		" In lines not belonging to pre enclose < and > in $$ to show them. {{{
		" \langle, \rangle would be more proper solution but they
		" look too differently for my taste.
		silent v/^\\mbox/s/</$<$/ge
		silent v/^\\mbox/s/>/$>$/ge
		silent v/^\\mbox\|begin{longtable\|multicolumn{/s/|/$|$/ge
		" }}}
		" Beautyfication of LaTeX output {{{
		silent %s/^\s*$//
		silent %s/\n\{3,}/\r\r/
		silent %s/\n\+\(\n\s*\\end\)/\1/
		silent %s/\(\\begin{.\{-}}\n\)\n\+/\1/
		" Compressing of titles
		silent %s/title{\n/title{/e
		silent %s/section{\n/section{/e
		silent %s/paragraph{\n/paragraph{/e
		" Shorten lists
		silent %s/\\item\s*\n\n/\\item\r/e
		" Because multiple spaces are meaningless:
		silent %s/\s\+/ /ge
		" Test it
		silent %s/{\_s*/{/ge
		silent %s/\n\n\s*&\s*\n\n/\r\&\r/ge
		silent %s/\n\n \(\\\\ \\hline\)\s*\n\n/\r\1\r/ge
		" Fix vertical space in admonitions
		silent %s/\(\\vspace{2mm}\n\)\(\S\)/\1\r\2/ge
		" Replace lines for .. figure:: - image first, minipage later.
		silent %s/\(\\begin{minipage}{0\.6\\textwidth}\)\n\(\\begin{figure.*\)/\2\r\1/ge
		" Remove special chars catchers
		silent %s/&#64;/@/ge
		silent %s/&#91;/[/ge
		silent %s/&#92;/\\/ge
		silent %s/&#58;/:/ge
		silent %s/&\\#64;/@/ge
		silent %s/&\\#91;/[/ge
		silent %s/&\\#92;/\\/ge
		silent %s/&\\#58;/:/ge
		" Insert new line before \item[], it causes problems in complex
		" environments
		silent %s/\\item\[/\r\0/ge
		" But we don't like if there is more than one blank line
		silent %s/\n\n\n\\item\[/\r\r\\item\[/ge
		" Remove empty deflist environment
		" may be a problem when :Date: NONE is the only element of field list
		silent %s/\\begin{deflist}{.\{-}}\n\\end{deflist}//ge
		" Replace non-breaking space characters with ~
		silent %s/ /\~/ge
		" }}}
		" Insert raw files {{{
		silent call cursor(1,1)
		while search('-vst-raw-file-placeholder:', 'W')
			let file = matchstr(getline('.'), '-vst-raw-file-placeholder:\zs.*')
			" Remove \ before _ - in most cases it was placed there by
			" escaping mechanism, not user
			let file = substitute(file, '\\_', '_', 'g')
			silent s/.*//ge
			exe 'silent read '.escape(file, ' \#%')
		endwhile
		" }}}

		redraw!

		" This is place for special CJK postprocessing
		" What if &encoding=='utf-8'?
		if &encoding =~? 'big5\|cp950\|euc-tw' || ( &encoding =~? '^utf' && v:ctype =~ 'big5' )

			silent! g/^\\usepackage.*geometry}/s/.*/\0\r\\usepackage{CJK}/
			silent! g/^\\usepackage.*inputenc}/d
			silent! g/^\\usepackage.*hyperref}/s/.*/\\usepackage[CJKbookmarks,bookmarks=false,pdftex]{hyperref}
			silent! g/^bookmarksopen=true,$/d
			silent! g/^bookmarksopenlevel=2,$/d
			if encoding == 'Big5'
				silent! g/\\begin{document}/s/.*/\0\\begin{CJK}{Bg5}{}/
			elseif encoding == 'UTF-8'
				silent! g/\\begin{document}/s/.*/\0\\begin{CJK}{UTF8}{}/
			else
				silent! g/\\begin{document}/s/.*/\0\\begin{CJK}{}{}/
			endif
			silent! g/\\end{document}/s/.*/\\end{CJK}\0/

			let cjkpreamble = '\renewcommand\CJKglue{\hskip -0.3pt plus 0.08\baselineskip}'."-cjk-newline-placeholder-"
				\.'\linespread{1.382}'."-cjk-newline-placeholder-"
				\.'\renewcommand{\arraystretch}{1.2}'."-cjk-newline-placeholder-"
				\.'\parindent=0pt'."-cjk-newline-placeholder-"
				\.'\parskip=1.382ex'."-cjk-newline-placeholder-"
				\.'\renewenvironment{quote}'."-cjk-newline-placeholder-"
				\.' {\list{}{\topsep 1ex\parsep 0ex\setlength\leftmargin{1.5em}%'."-cjk-newline-placeholder-"
				\.' \rightmargin\leftmargin}\item\relax\linespread{1.0}\small}%'."-cjk-newline-placeholder-"
				\.' {\endlist}'."-cjk-newline-placeholder-"
				\.'\let\oldfootnote\footnote'."-cjk-newline-placeholder-"
				\.'\renewcommand\footnote[1]{\oldfootnote{\renewcommand\baselinestretch{1.0}%'."-cjk-newline-placeholder-"
				\.'\large\footnotesize\ignorespaces#1}}'."-cjk-newline-placeholder-"
				\.'\addtolength{\footnotesep}{3pt}'

			silent call cursor(1,1)
		    silent call search('^\\usepackage{amsmath}')
			silent call append(line('.'), cjkpreamble)
			" Placeholder stuff is necessary because no Vim function for
			" inserting text like newline character.
			silent! %s/-cjk-newline-placeholder-/\r/g
			silent call cursor(1,1)

		endif

		" User postprocessing
		if g:vst_tex_post != '' && filereadable(g:vst_tex_post)
			exe "silent! source ".g:vst_tex_post
		endif

		" Handling of pdf export {{{
		if format =~ 'pdf'
			silent call cursor(1,1)
			let file_tex = filename.'.tex'
			if !exists('g:vst_pdf_command')
				let g:vst_pdf_command = 'pdflatex -interaction=nonstopmode'
			endif
			silent exe 'write! '.escape(file_tex, ' \#%')
			silent exe "call system(\"".g:vst_pdf_command." '".file_tex."'\")"
			if search('\\tableofcontents', 'W')
				silent exe "call system(\"".g:vst_pdf_command." '".file_tex."'\")"
			endif
			if v:shell_error == 0
				bw! %
				echomsg "Document compiled OK. You can view it in PDF viewer."
				if exists("g:vst_pdf_clean") && g:vst_pdf_clean == 1
					call delete(file_tex)
					call delete(filename.'.log')
					call delete(filename.'.out')
					call delete(filename.'.aux')
				endif
				if exists("g:vst_pdf_view") && g:vst_pdf_view == 1
					if !exists("g:vst_pdf_viewer")
						if has("win32")
							let g:vst_pdf_viewer = ""
						elseif has("unix") 
							if executable("kpdf")
								let g:vst_pdf_viewer = "kpdf"
							elseif executable("xpdf")
								let g:vst_pdf_viewer = "xpdf"
							else
								let g:vst_pdf_viewer = "no_pdf_viewer"
							endif
						endif
					endif
					silent exe "call system(\"".g:vst_pdf_viewer." '".filename.".pdf'\")"
					silent redraw!
				endif
			else
				echomsg "Something went wrong, check TeX code or command settings."
			endif
			silent call cursor(1,1)
			call VST_End()
			return
		endif
		" }}}

		" Latex-Suite (or any other tex ftype settings) brokes *many*
		" things. Load it at the end
		setlocal ft=tex
		if exists("g:vst_write_export") && g:vst_write_export != 0
			silent exe 'write! '.escape(filename, ' \#%').'.tex'
		endif

		silent call cursor(1,1)
		" }}}
	" Auxiliary commands {{{
	elseif format =~ '^head'
		" Symbols for section titles {{{
		call VST_Headers(text)
		unlet! b:vst_first_parsing
		call VST_DictTable(g:vst_headers, 'Level', 'Symbol', 0)
		" }}}
	elseif format =~ '^toc'
		" Table of contents for file {{{
		let line = line('.')
		call VST_Headers(text)
		unlet! b:vst_first_parsing
		let i = 1
		let tocc = []
		let b:vst_toc_numbers = {}
		let i1 = -1
		let i2 = -1
		let i3 = -1
		let i4 = -1
		let i5 = -1
		let i6 = -1

		while i < len(g:paras)
			if g:ptype[i] =~ '^h\d'
				" Real table
				call add(tocc, [g:ptype[i], g:paras[i], g:plinen[i]])
				" Header numbers
				let header_text = matchstr(g:paras[i], '^.\{-}\ze\n')
				let lvl = strpart(g:ptype[i], 1)
				if lvl == 1
					let b:vst_toc_numbers[header_text] = ''
					let i2 = 0
					let i3 = 0
					let i4 = 0
					let i5 = 0
					let i6 = 0
				elseif lvl == 2
					let i2 += 1
					let b:vst_toc_numbers[header_text] = i2.'  '
					let i3 = 0
					let i4 = 0
					let i5 = 0
					let i6 = 0
				elseif lvl == 3
					let i3 += 1
					let b:vst_toc_numbers[header_text] = i2.'.'.i3.'  '
					let i4 = 0
					let i5 = 0
					let i6 = 0
				elseif lvl == 4
					let i4 += 1
					let b:vst_toc_numbers[header_text] = i2.'.'.i3.'.'.i4.'  '
					let i5 = 0
					let i6 = 0
				elseif lvl == 5
					let i5 += 1
					let b:vst_toc_numbers[header_text] = i2.'.'.i3.'.'.i4.'.'.i5.'  '
					let i6 = 0
				elseif lvl == 6
					let i6 += 1
					let b:vst_toc_numbers[header_text] = i2.'.'.i3.'.'.i4.'.'.i5.'.'.i6.'  '
				endif
			endif
			let i += 1
		endwhile

		echo VST_TocTable(tocc, 'Nr', 'Title', ' Line', line)
		" }}}
	elseif format =~ '^fold'
		" Folding {{{
		let b:vst_fold = {}
		call VST_Headers(text)
		unlet! b:vst_first_parsing
		" Prepare numbers of head lines {{{
		let b:vst_fold_numbers = {}
		let i = 0
		let i1 = -1
		let i2 = -1
		let i3 = -1
		let i4 = -1
		let i5 = -1
		let i6 = -1
		while i < len(g:paras)
			if g:ptype[i] =~ '^h\d'
				let header_text = matchstr(g:paras[i], '^.\{-}\ze\n')
				let lvl = strpart(g:ptype[i], 1)
				if lvl == 1
					let b:vst_fold_numbers[header_text] = ''
					let i2 = 0
					let i3 = 0
					let i4 = 0
					let i5 = 0
					let i6 = 0
				elseif lvl == 2
					let i2 += 1
					let b:vst_fold_numbers[header_text] = i2.'  '
					let i3 = 0
					let i4 = 0
					let i5 = 0
					let i6 = 0
				elseif lvl == 3
					let i3 += 1
					let b:vst_fold_numbers[header_text] = i2.'.'.i3.'  '
					let i4 = 0
					let i5 = 0
					let i6 = 0
				elseif lvl == 4
					let i4 += 1
					let b:vst_fold_numbers[header_text] = i2.'.'.i3.'.'.i4.'  '
					let i5 = 0
					let i6 = 0
				elseif lvl == 5
					let i5 += 1
					let b:vst_fold_numbers[header_text] = i2.'.'.i3.'.'.i4.'.'.i5.'  '
					let i6 = 0
				elseif lvl == 6
					let i6 += 1
					let b:vst_fold_numbers[header_text] = i2.'.'.i3.'.'.i4.'.'.i5.'.'.i6.'  '
				endif

				let b:vst_fold[header_text] = lvl-1
			endif
			let i += 1
		endwhile
		" }}}
		" Prepare fold levels {{{
		let b:vst_fold_lvl = matchstr(format, '\zs.\ze\s*$')
		if b:vst_fold_lvl =~ 'r'
			for i in [1, 2, 3, 4, 5, 6]
				let b:vst_fold_list_{i} = filter(deepcopy(b:vst_fold), 'v:val == i')
				let b:vst_flvl_{i} = keys(b:vst_fold_list_{i})
			endfor
		else
			if b:vst_fold_lvl !~ '\d'
				let b:vst_fold_lvl = 0
			elseif b:vst_fold_lvl =~ '\d' && b:vst_fold_lvl > 6
				let b:vst_fold_lvl = 6
			endif
			if b:vst_fold_lvl != 0
				let b:vst_fold_list = filter(deepcopy(b:vst_fold), 'v:val <= b:vst_fold_lvl')
			else
				let b:vst_fold_list = b:vst_fold
			endif
		endif
		" }}}
		setlocal foldmethod=expr
		setlocal foldexpr=VST_FoldExpr(v:lnum)
		setlocal foldtext=VST_FoldText()
		" }}}
	elseif format =~ '^fblank'
		" Folding by blank lines {{{
		let directive = matchstr(format, '^f\zs.*')
		setlocal foldmethod=expr
		set foldexpr=getline(v:lnum)=~'^\\s*$'&&getline(v:lnum+1)=~'\\S'?'<1':1
		function! VST_FoldText()
			let text = getline(v:foldstart)
			let indent = '+'.v:folddashes
			return indent.repeat(' ', 2).text.' '
		endfunction
		setlocal foldtext=VST_FoldText()
		" }}}
	elseif format =~ '^f'
		" Folding by directive {{{
	"elseif format =~ '^f\(block\|container\|image\|figure\|sidebar\|compound\|topic\|rubric\|table\|tip\|note\|warning\|admonition\|include\|pull-quote\|class\|meta\|raw\|2html\)'
		let directive = matchstr(format, '^f\zs.*')
		setlocal foldmethod=expr
		"exe "setlocal foldexpr=getline(v:lnum)=~?'^\\\\s*\\\.\\\.\\\ ".directive."::'?'>1':1"
		exe "setlocal foldexpr=getline(v:lnum)=~?'^\\\\s*\\\.\\\.\\\ ".directive."'?'>1':1"
		function! VST_FoldDirective()
			let text = getline(v:foldstart)
			let indent = '+'.v:folddashes
			let fill = 65 - (len(indent) + len(text) + 3)
			if fill < 1
				let fill = 1
			endif
			return indent.'  '.text.repeat(' ', fill).v:foldstart.' ('.v:foldstart*100/line('$').'%)'
		endfunction
		setlocal foldtext=VST_FoldDirective()
		" }}}
	elseif format =~ '^link'
		" Link table {{{
		call VST_Headers(text)
		unlet! b:vst_first_parsing
		call VST_DictTable(g:vst_hlinkdb, 'Text', 'Link', 0)
		" }}}
	elseif format =~ '^slink'
		" Sorted link table {{{
		call VST_Headers(text)
		unlet! b:vst_first_parsing
		call VST_DictTable(g:vst_hlinkdb, 'Text', 'Link', 1)
		" }}}
	elseif format =~ '^rep'
		" Replacement table {{{
		call VST_Headers(text)
		unlet! b:vst_first_parsing
		call VST_DictTable(g:vst_replacedb, 'Symbol', 'Replacement', 0)
		" }}}
	elseif format =~ '^srep'
		" Sorted replacement table {{{
		call VST_Headers(text)
		unlet! b:vst_first_parsing
		call VST_DictTable(g:vst_replacedb, 'Symbol', 'Replacement', 1)
		" }}}
	elseif format =~ '^help'
		" Help for commands {{{
		echo 
			\ "Help for :Vst arguments:\n"
			\."html  - [default] export to HTML format\n"
			\."tex   - export to LaTeX format\n"
			\."pdf   - export to LaTeX format and compile PDF\n"
			\."rest  - export to reST format\n"
			\."s5    - export to S5 HTML presentation\n"
			\."  ---------------\n"
			\."toc   - file table of contents\n"
			\."head  - show used symbols for headers\n"
			\."link  - show table of link declarations\n"
			\."slink - show sorted table of link declarations\n"
			\."rep   - show table of replacements\n"
			\."srep  - show sorted table of replacements\n"
			\."preproc - process inclusion commands (non-recursively)\n"
			\."help  - this message\n"
			\."  ---------------\n"
			\."fold  - (re)create folds in file\n"
			\."foldr - (re)create folds recursively in file\n"
			\."fold1 - (re)create folds of 1st level headers in file\n"
			\."fold2 - (re)create folds up to 2nd level header in file\n"
			\."fold3 - (re)create folds up to 3rd level header in file\n"
			\."fold4 - (re)create folds up to 4th level header in file\n"
			\."fold5 - (re)create folds up to 5th level header in file\n"
			\."fold6 - (re)create folds up to 6th level header in file\n"
			\."  ---------------\n"
			\."Additional commands:\n"
			\.":Vsti - immediately write file\n"
			\.":Vstm - display menus (no arguments)"
		return ''
		" }}}
	elseif format =~ '^pre'
		" Interpret all including commands and put them in file {{{
		silent normal! ggdG
		let jtext = join(text, "\n")
		silent 0put =jtext
		silent call cursor(1,1)
		" }}}
	" }}}
	endif 

	call VST_End()

	return ''

endfunction
" }}}

" Functions for auxiliary mappings {{{
function! vst#vst#VST_AuxiliaryMappings()
" VST_Ornaments: insert ornaments depending on position {{{
" Description: Depending on position and inserted character inserted before
" cursor fill ornaments: single section ornaments, double section ornaments,
" transition element
function! VST_Ornaments()
	" Get ornament character
	" HEADDEF:
	let s:vst_headdef = '\(=\{3,}\|+\{3,}\|\*\{3,}\|\^\{3,}\|%\{3,}\|\$\{3,}\|#\{3,}\|@\{3,}\|;\{3,}\|"\{3,}\|\.\{3,}\|,\{3,}\|`\{3,}\|\~\{3,}\|-\{3,}\|!\{3,}\|(\{3,}\|)\{3,}\|:\{3,}\|_\{3,}\|&\{3,}\|}\{3,}\|{\{3,}\||\{3,}\|?\{3,}\|<\{3,}\|>\{3,}\|\\\{3,}\|\[\{3,}\|\]\{3,}\|\/\{3,}\|''\{3,}\)'
	let s:vst_headchars2 = '\(=\|+\|\*\|\^\|%\|\$\|#\|@\|;\|"\|\.\|,\|`\|\~\|-\|!\|(\|)\|:\|_\|&\|}\|{\||\|?\|<\|>\|\\\|\[\|\]\|\/\|''\)'
	let curline = getline(line('.'))
	let character = curline[len(curline)-1]
	if curline =~ '^\s*$'
		" Temporary thing, to by-pass headchars test
		let character = '-'
	elseif curline !~ '^\s*'.s:vst_headchars2.'\+$'
		return ''
	endif

	let prevline = getline(line('.')-1)
	let nextline = getline(line('.')+1)

	if prevline =~ '^\s*$'
		let prevline_is_empty = 1
	else
		let prevline_is_empty = 0
	endif

	if nextline =~ '^\s*$'
		let nextline_is_empty = 1
	else
		let nextline_is_empty = 0
	endif

	if prevline_is_empty == 1 && nextline_is_empty == 1
		" We are to insert transition element
		if &tw > 50
			let trans_len = &tw/3
		else
			let trans_len = 20
		endif
		if curline =~ '^\s*$'
			" Current line consists of only white characters. Try to find last
			" used transition
			let last_trans_line = search('\n\s*\n\s*'.s:vst_headdef.'\s*\n\s*\n' , 'bWn') + 2
			if last_trans_line == 2
				let character = '-'
			else
				let character = matchstr(getline(last_trans_line), '^\s*\zs.\ze')
			endif
		endif
		return repeat(character, trans_len)
	elseif prevline_is_empty == 0 && nextline_is_empty == 1
		" Insert single ornament
		let prevline_len = len(prevline)
		if curline =~ '^\s*$'
			" Current line consists of only white characters. Try to find last
			" single ornament section
			let last_single_ornament = search('\(\%^\|\n\s*\n\|\%^\s*\n\).\{-}\n\s*'.s:vst_headdef.'\s*\n\s*\n' , 'bWn') + 3
			if last_single_ornament == 4 && getline(1) =~ '^\s*$' && getline(2) =~ '^\s*$'
				let last_single_ornament = 4
			elseif last_single_ornament == 4 && getline(1) =~ '^\s*$'
				let last_single_ornament = 3
				let real3 = 1
			elseif last_single_ornament == 4
				let last_single_ornament = 2
			endif
			if last_single_ornament == 3 
				if !exists('real3')
					let character = '-'
				else
					let character = matchstr(getline(last_single_ornament), '^\s*\zs.\ze')
					unlet! real3
				endif
			else
				let character = matchstr(getline(last_single_ornament), '^\s*\zs.\ze')
			endif
		endif
		if prevline_len < 3
			let ornament_len = 3 - len(curline)
		else
			let ornament_len = prevline_len - len(curline)
		endif
		return repeat(character, ornament_len)."\n"
	elseif prevline_is_empty == 1 && nextline_is_empty == 0
		" Insert double ornament
		let nextline_len = len(nextline)
		" Unfortunately this line borks undo history
		normal! 2"_dd
		if curline =~ '^\s*$'
			" Current line consists of only white characters. Try to find last
			" used ornament
			let last_double_ornament = search('\(\%^\|\n\s*\n\|\%^\s*\n\)\s*'.s:vst_headdef.'\s*\n.\{-}\n\s*\2\s*\n' , 'bWn') + 2
			if last_double_ornament == 3 && getline(1) =~ '^\s*$' && getline(2) !~ '^\s*$'
				let last_double_ornament = 4
			endif
			if last_double_ornament == 2
				let character = '='
			else
				let character = matchstr(getline(last_double_ornament), '^\s*\zs.\ze')
			endif
		endif
		if len(curline) == 0
			let correction = 0
		else
			let correction = 1
		endif
		if nextline_len < 3
			let ornament_len = 3
		else
			let ornament_len = nextline_len
		endif
		let ornament = repeat(character, ornament_len)
		return ornament."\n".nextline."\n".ornament."\n"
	else
		return ''
	endif

	return ''

endfunction
" }}}
" VST_RotateOrnaments: rotate characters in ornaments {{{
" headers
function! VST_RotateOrnaments()
	" HEADDEF:
	let s:vst_headdef = '\(=\{3,}\|+\{3,}\|\*\{3,}\|\^\{3,}\|%\{3,}\|\$\{3,}\|#\{3,}\|@\{3,}\|;\{3,}\|"\{3,}\|\.\{3,}\|,\{3,}\|`\{3,}\|\~\{3,}\|-\{3,}\|!\{3,}\|(\{3,}\|)\{3,}\|:\{3,}\|_\{3,}\|&\{3,}\|}\{3,}\|{\{3,}\||\{3,}\|?\{3,}\|<\{3,}\|>\{3,}\|\\\{3,}\|\[\{3,}\|\]\{3,}\|\/\{3,}\|''\{3,}\)'
	let s:vst_headchars2 = '\(=\|+\|\*\|\^\|%\|\$\|#\|@\|;\|"\|\.\|,\|`\|\~\|-\|!\|(\|)\|:\|_\|&\|}\|{\||\|?\|<\|>\|\\\|\[\|\]\|\/\|''\)'
	" Make sure we are in position to perform any actions
	" This is more general regexp, could match several 
	if getline('.') !~ '^\s*'.s:vst_headdef.'\s*$'
		return 0
	endif

	" Get situation: double/single ornament, transition
	let prevline = getline(line('.')-1)
	let nextline = getline(line('.')+1)

	if prevline =~ '^\s*$'
		let prevline_is_empty = 1
	else
		let prevline_is_empty = 0
	endif

	if nextline =~ '^\s*$'
		let nextline_is_empty = 1
	else
		let nextline_is_empty = 0
	endif

	if !exists("g:vst_headers")
		call input('No knowledge about headers, run :Vst head')
		return 0
	endif

	if nextline_is_empty == 1 && prevline_is_empty == 0
		" Single ornament
		let a = 0
	endif
	" Make sure we have data about headers. Note: updating of data will be
	" done manually or updated at the end
endfunction
" }}}
" Auxiliary mappings
inoremap <silent> <C-B>o <C-R>=VST_Ornaments()<CR>
"noremap <silent> <C-B>o <C-R>=VST_RotateOrnaments()<CR>
endfunction
" vim:fdm=marker:ff=unix:noet:ts=4:sw=4:nowrap
