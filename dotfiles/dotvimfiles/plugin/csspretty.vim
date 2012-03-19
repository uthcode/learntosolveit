""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"		CssPretty 		Todd Freed		todd.freed@gmail.com
"
"		Introduction
" -------------------
"  Provides functionality to format text as css such that
"  each selector and declaration is on its own line
"
"  	Usage
" -------------------
"  CssPretty()
"  	The entire buffer is formatted as css text
"
"  CssPretty([])
"  	The entire buffer is formatted as css text and returned
"  	as a List of lines
"
"  CssPretty(start {, end, {[]}})
"  	The section of the buffer starting on line {start} and
"  	continuing to the end of the buffer, or until line {end}
"  	will be formatted as css text. If the third parameter is
"  	specified, then this is returned as a List of lines and
"  	the buffer is not modified
"
"  CssPretty(text)
"  	The {text} parameter is formatted as css text and returned
"  	as a List of lines
"
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" generates whitespace
function! Whitespace(indent)
	let tabstop = 3

	return repeat(' ', a:indent * tabstop)
endfunction

" Trim whitespace from beginning and end of val. optionally include other
" characters to trim from the beginning and end with 2nd and 3rd params
function! Trim(val, ...)
	let startchars = ''
	let endchars = ''
	if(len(a:000) > 0)
		let startchars = a:000[0]
	endif
	if(len(a:000) > 1)
		let endchars = a:000[1]
	endif

	let start = "^[ \t" . startchars . "]*"
	let end = "[ \t" . endchars . "]*$"

	let val = substitute(a:val, start, '', '')
	let val = substitute(val, end, '', '')

	return val
endfunction

function! CssPretty(...)
	let buf = ''

	if(len(a:000) > 0 && type(a:000[0]) == type(''))
		let buf = a:000[0]
	else
		let bufnum = bufnr("%")

		let firstline = 1
		let lastline = len(getbufline(bufnum, 1, "$"))
		if len(a:000) > 0 && type(a:000[0]) == type(0)
			let firstline = a:000[0]
		endif
		if len(a:000) > 1 && type(a:000[1]) == type(0)
			let lastline = a:000[1]
		endif

		let linearray = getbufline(bufnum, firstline, lastline)

		" Get the buffer into one string
		for index in range(lastline - firstline + 1)
			let o = getline(index +  firstline)
			let buf = buf . o
		endfor
	endif

	" Generate indexes of all css declarations in the buffer
	let regex = "\\([^{]*\\){\\([^}]*\\)}"
	let match = {'start': 0, 'end': 0}
	let matches = [match]
	while match['start'] > -1
		call add(matches, match)

		let start = match(buf, regex, matches[-1]['end'])
		if start > -1
			let rawmatch = matchlist(buf, regex, matches[-1]['end'])

			let end = start + len(rawmatch[0])
			let selector = Trim(rawmatch[1])
			let contents = Trim(rawmatch[2], '', ';')

			let declarations = []
			for o in split(contents, ';')
				let property = Trim(split(o, ':')[0])
				let value = Trim(split(o, ':')[1])

				call add(declarations, {'property': property, 'value': value})
			endfor

		endif

		let match = {'start': start, 'end': end, 'len': end - start, 'selector': selector, 'declarations': declarations}
	endwhile

	" remove first entry - it was a dummy
	call remove(matches, 0, 1)

	" Generate array of new lines
	let lines = []
	for x in range(len(matches))
		let match = matches[x]

		call add(lines, match['selector'])
		call add(lines, '{')
		for declaration in match['declarations']
			call add(lines, Whitespace(1) . declaration['property'] . ": " . declaration['value'] . ';')
		endfor
		call add(lines, '}')
	endfor

	" just return the lines if requested
	if len(a:000) > 2 || (len(a:000) > 0 && type(a:000[0]) == type([])) || (len(a:000) > 1 && type(a:000[1]) == type([]))
		return lines
	" or if this function was invoked with a string as its first argument
	elseif len(a:000) > 0 && type(a:000[0]) == type('')
		return lines
	endif

	" Otherwise, rewrite the buffer by first removing all lines from the buffer in the specified range, inclusive
	for x in range(lastline - firstline + 1)
		call setline(x+firstline, '')
	endfor
	call cursor(lastline, 1)
	for x in range(lastline - firstline + 1)
		exe 'normal ' . "a\b\e"	
	endfor

	" and appending into the buffer
	let line = firstline - 1
	for x in range(len(lines))
		call append(line, lines[x])
		let line = line + 1
	endfor

endfunction
