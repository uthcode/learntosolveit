" Author: Mikolaj Machowski
" Example of macro for g:vst_html_post file
call cursor(1,1)
while search('^\s*{read\w\{-}:.\{-}}\s*$', 'W')
	let data = matchlist(getline('.'), '^\s*{read\(\w\{-}\):\(.\{-}\)}\s*$')
	silent s/.*//ge
	if data[1] == ''
		let output = readfile(data[2])
	else
		if data[1] == 'bang'
			let data[1] = ''
		endif
		let output = split(system(data[1].' '.data[2]), "\n")
	endif
	call map(output, "' '.v:val")
	let jout = "<pre>\n".join(output, "\n")."\n</pre>"
	put =jout
endwhile
