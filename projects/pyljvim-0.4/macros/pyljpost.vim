"
"
" VIM Script to interface pyljpost, A Trivial LiveJournal Poster.
" 
" The methodology is simple. 
" You call the function LJTemplate, new buffer with template appears,
" you enter your immortal thoughts, call LJPost, and they get posted.
" 
"
" Detailed description:
"  LJTemplate <template_name>
"	There are two templates by default: standart and extended.
"  	Standart has only Subject and Mood, while extended has got
"	all possible headers.
" 	Since templates are just files, you can easily create new
"	ones. Filename would be the template name.
"	
"  LJPost
"	LJPost takes your current buffer file, and calls pyljpost.py
"	with it as a parameter, then removes the file.
"	Username and password are stored in variables, and, if empty,
"	are asked upon the post.
"
"
" Changelog:
"	0.0.1	-- 	Initial Revision.
"

"if exists("loaded_pyljpost") || &cp
"  finish
"endif
let loaded_pyljpost = 1

" Default value for pyljpost_path variable
if !exists("g:pyljpost_path") 
	if has("win32")
		let g:pyljpost_path = "C:\pyljpost.py"
	else
		let g:pyljpost_path = "~/Projects/pyljvim-0.0.1/pyljpost.py"
	endif	
endif

if !exists("g:pyljpost_templates_path")
	let g:pyljpost_templates_path = "~/.pyljpost/templates"
endif

if !exists("g:pyljpost_encoding")
	if has("win32")
		let g:pyljpost_encoding = "cp1251"
	else
		let g:pyljpost_encoding = "koi8-r"
	endif
endif

" Define commands for our functions
:com -nargs=* LJPost call LJPost(<f-args>)
:com -nargs=* LJTemplate call LJTemplate(<f-args>)
:com -nargs=* LJUserPassword call LJUserPassword(<f-args>)


" LJUserPassword: set username and password for LiveJournal Posting.
" 			Shamelessly stolen from netrw :)
"   Usage:  
"		:call LJUserPassword()			-- will prompt for userid and password
"	    :call LJUserPassword("uid")		-- will prompt for password
"	    :call LJUserPassword("uid","password") -- sets global userid and password
function! LJUserPassword(...)

 " get/set userid
 if a:0 == 0
  if !exists("g:pyljpost_username") || g:pyljpost_username == ""
   " via prompt
   let g:pyljpost_username= input('Enter LJ username: ')
  endif
 else	" from command line
  let g:pyljpost_username= a:1
 endif

 " get password
 if a:0 <= 1 " via prompt
  let g:pyljpost_password= inputsecret("Enter LJ Password: ")
 else " from command line
  let g:pyljpost_password=a:2
 endif
endfunction
" end LJUserPassword

" LJTemplate: Create a temporary file, fill it with template, and let user 
"			  edit it.
function! LJTemplate(...)
	if a:0 == 0
		" No template name given, assume its standart
		let template = "standart"
	else
		let template = a:1
	endif

	let tempname = tempname()	
	exec "bad " . tempname
	exec "buffer " . tempname
	exec "0read " . g:pyljpost_templates_path . "/" . template
	" Now it's time to find "Date:" field, if it is present,
	" and fill it with RFC-822 date.
	" Seems like this would work on GNU systems only,
	" because of the GNU timezone extension used here.
	" FIXME: Perhaps, use simplified date format, and parse
	" 		it manually in pyljpost.py?
	let date_ln = search("Date")
	if date_ln != 0
		let cur_lang = v:lang
		exec "language C"
		let date_string = strftime("%a, %d %b %Y %H:%M:%S %z", localtime())
		exec date_ln . "s/Date\:/Date\: " . date_string
		exec "language " . cur_lang
	endif
	set ft=lj
	" Let's go to Subject line.
	let subj_ln = search("Subject")
	if subj_ln != 0
		exec ":" . subj_ln
		exec "startinsert!"
	else
		" You really should have Subject in template, but anyway
		exec "goto 1"
	endif
	
endfunction

" LJPost: write buffer, call pyljpost.py with appropriate parameters.
"

function! LJPost(...)
	exec "write!"
	let fname = expand("%")
	if !exists("g:pyljpost_username") || !exists("g:pyljpost_password")
		call LJUserPassword()
	endif
	exec "!python " . g:pyljpost_path . " " . g:pyljpost_username . " " . g:pyljpost_password . " " . g:pyljpost_encoding . " " . fname
	exec "bd"
endfunction
	

	

