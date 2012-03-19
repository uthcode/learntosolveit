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
" VST requires Vim7
if v:version < 700
	finish
endif

" Command :Vst
command! -range=% -nargs=? -complete=custom,VST_Args Vst call vst#vst#VST_Export(<line1>, <line2>, <q-args>)
command! -range=% -nargs=? -complete=custom,VST_Args Vsti call vst#vst#VST_InstantWrapper(<line1>, <line2>, <q-args>)
command! -range=% -nargs=? -complete=custom,VST_Args Vstm call VST_Menus()

" VST_Args: Command line completion for :Vst command {{{
function! VST_Args(A, C, P)
	let args = "html,tex,latex,pdf,toc,head,fold,link,slink,rep,srep,preproc,help,rest"
	return substitute(args, ',', '\n', 'g')
endfunction
" }}}
" Menus {{{
function! VST_Menus()
	if has("gui_running")
		menu VreST.Export\ to\ HTML :Vst html<cr>
		menu VreST.Export\ to\ LaTeX :Vst tex<cr>
		menu VreST.Export\ to\ PDF :Vst pdf<cr>
		menu VreST.Export\ to\ reST :Vst rest<cr>
		menu VreST.Fold :Vst fold<cr>
		menu VreST.Headers :Vst head<cr>
		menu VreST.TOC :Vst toc<cr>
		menu VreST.Help :Vst help<cr>
		inoremenu VreST.Export\ to\ HTML <c-o>:Vst html<cr>
		inoremenu VreST.Export\ to\ LaTeX <c-o>:Vst tex<cr>
		inoremenu VreST.Export\ to\ PDF <c-o>:Vst pdf<cr>
		inoremenu VreST.Export\ to\ reST <c-o>:Vst rest<cr>
		inoremenu VreST.Fold <c-o>:Vst fold<cr>
		inoremenu VreST.Headers <c-o>:Vst head<cr>
		inoremenu VreST.TOC <c-o>:Vst toc<cr>
		inoremenu VreST.Help <c-o>:Vst help<cr>
	endif
endfunction
if exists("g:vst_showmenu") && g:vst_load_menus != 0
	call VST_Menus()
endif
" }}}
" Load auxiliary mappings:
call vst#vst#VST_AuxiliaryMappings()

" vim:fdm=marker:ff=unix:noet:ts=4:sw=4:nowrap
