--
pyljvim: LiveJournal Plugin for VIM using Python.
-- 

pyljvim helps to post to LiveJournal from vim itself. Users of vim
having python installed in their machines should find this facility useful.

Requirements: 
	python, vim :) I don't know if it'll work in old python and vim,
	I did tested it in python 2.2 and vim 6.1 environment.
	If you manage to run this with python 1.5.2 and vim 5.x -- 
	let me know, I'll be happy (but you really should upgrade :).

Installation:
  To Install on Windows.
  0)Provide Accurate Details to Configfile.txt
  1)python setup.py install
  2)Open vim and type :LJTemplate extended or standart.
  3)Type :LJPost to post to the journal.
  4)Thanks it!

  Follow the below for Unix based systems, as I not yet worked on making installation on Linux Simpler.
	No fancy install script is available, hand-operation mode.
	Possible installation scenario:
	
	tar -xzf pyljvim-0.0.1.tar.gz
	cd pyljvim-0.0.1
	cp syntax/lj.vim ~/.vim/syntax/
	cp macros/pyljpost.vim ~/.vim/macros/
	cp src/pyljpost.py /usr/local/bin/
	mkdir ~/.pyljvim
	mkdir ~/.pyljvim/templates
	cp templates/* ~/.pyljvim/templates
	echo "source ~/.vim/macros/pyljpost.vim" >> ~/.vimrc
	echo 'let g:pyljpost_path = "/usr/local/bin/pyljpost.py"' >> ~/.vimrc 

Configuration variables
	g:pyljpost_path 	-- path to pyljpost.py, include the "pyljpost.py"
						   itself.
	g:pyljpost_templates_path -- path to templates
	g:pyljpost_encoding -- your terminal encoding, from which to encode to utf-8

	g:pyljpost_username -- LJ Username
	g:pyljpost_password -- LJ Password 
	^^^^^
	These two, if not setted, would be asked upon the post.

Usage
	Once the macros is sourced, two new functions become available,
	LJTemplate and LJPost.

	LJTemplate [template-name]
		This function creates a new buffer, load template <template-name> 
		(standart, if not given), creates the Date: field (if present in
		template), and goes to append mode.
	Once you're ready with your immortal thoughts, goes 
	LJPost
		This function does the actual posting and deletes the buffer and the
		temporary file.

Of course, both functions can be mapped to Your-Beloved-Key.
You can easily create new templates (by writing new files at template_path),
with your own parameters. Full list of available parameters is in "extended"
template. Please note that "Subject" header is required in order to
post.

In case of any comments, bugfixes, etc., mail me, <wart@tepkom.ru> OR  O.R.Senthil Kumaran <Senthil_OR@Dell.com>
