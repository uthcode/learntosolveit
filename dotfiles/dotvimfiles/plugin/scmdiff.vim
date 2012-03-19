if !exists("g:SCMDiffCommand")
let g:SCMDiffCommand = 'svn'
endif

if exists("loaded_scmdiff") || &cp
finish
endif
let loaded_scmdiff = 1

map ,d :call <SID>SCMDiff()<CR>
map <C-g> :set nodiff<CR>
noremap <unique> <script> <plug>Dh :call <SID>SCMDiff("h")<CR>
com! -bar -nargs=? D :call s:SCMDiff(<f-args>)

let g:scmdiff_rev = ''

function! s:SCMDiff(...)
if a:0 == 1
if a:1 == 'none'
let g:scmdiff_rev = ”
else
let g:scmdiff_rev = a:1
endif
endif

let ftype = &filetype
let tmpfile = tempname()
let cmd = 'cat ' . bufname('%') . ' > ' . tmpfile
let cmd_output = system(cmd)
let tmpdiff = tempname()
let cmd = g:SCMDiffCommand . ' diff ' . g:scmdiff_rev . ' ' . bufname('%') . ' > ' . tmpdiff
let cmd_output = system(cmd)
if v:shell_error && cmd_output != ''
echohl WarningMsg | echon cmd_output 
return
endif

let cmd = 'patch -R -p0 ' . tmpfile . ' ' . tmpdiff
let cmd_output = system(cmd)
if v:shell_error && cmd_output != ''
echohl WarningMsg | echon cmd_output 
return
endif

if exists('s:killbuffs')
2,9999 bdelete
endif
let s:killbuffs = 1
if a:0 > 0 && a:1 == 'h'
exe 'diffsplit' . tmpfile
else
exe 'vert diffsplit' . tmpfile
endif 

exe 'set filetype=' . ftype

hide
set foldcolumn=0
set foldlevel=100
set diffopt= " removed filler so we don’t show deleted lines
highlight DiffAdd ctermbg=black ctermfg=DarkGreen
highlight DiffChange ctermbg=black ctermfg=DarkGreen
highlight DiffText ctermbg=black ctermfg=DarkGreen cterm=underline
highlight DiffDelete ctermbg=red ctermfg=white

endfunction

"autocmd CursorHold * call s:SCMDiff()
