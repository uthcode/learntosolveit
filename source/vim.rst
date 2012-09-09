==========
Vim Editor
==========

Vim is my default text editor. I have tried to used multitude of editors and
ides and I often found to revert back to vim, as I think that it captures my
thought process well. I seem to have grown accustomed to it.

I like the charityware concept of vim too.

Plugins
-------

I discovered this well-maintained, easy to use bunch of plugins called 'spf13'
after discovering this, my search for good plugins / vimrc's has almost zeroed.
The plugins are kept in git repository and easy to update as well.

http://vim.spf13.com


Seven Habits of Effective Text Editing
--------------------------------------

This is a very simple high level overview presentation given by the author of
the vim editor. If you are first time user or a beginner, this tutorial could
be of help to you.

http://www.moolenaar.net/habits.html

Breakthrough Paper
------------------

vi editor was breakthrough advancement in computer programming world. It set
the stage for new generation for programmers to start edit on a full screen and
directly on the system buffer. The design and keystrokes are extremely intuitive.

This paper written by Computer Science pionner "Bill Joy" and "Mark Horton"
introduces vim editor to the then CS programmers and system users.

http://docs.freebsd.org/44doc/usd/12.vi/paper.html


Concepts and Keystores
^^^^^^^^^^^^^^^^^^^^^^

Bill Joy's "Introduction to Display editing using vi" is a great tutorial to
understand and appreciate the rationale behind the vi keystrokes. The material
is relevant for the Vim editor as well.

These notes can serve as quick reference material to the tutorial and getting
started with vi also.

* **d** for delete
* **c** for change

both can be applied to a word by suffixing it with **w**.

* **h j k l** as cursor positioning keys.

If not sure on which state the editor is in, hitting **ESC** key for few times
makes the editor go in quiescent state.

* **/** key

Now when you have pressed / key and the cursor is at the bottom, you can return
to the previous position by pressing the **DEL** key.

When the cursor is at the first position in the last line, then it is
performing a computation.

* **ZZ** Save and quit.
* **:q!** end the editor session.
* **^D** Scrolls Down in a file. *D stands for Down.*
* **^U** Scrolls UP. *U stands for Up.*

The Up and Down commands were really mmenomic. There are few more commands
which are similar to scrolling the file.

* **^E** Expose one more line at the bottom of the screen. *E stands for Expose.*
* **^Y** Exposes one line at the top of the screen. *It is non-mnemonic, but Y is next to U.*
* **^F** Forward in a file. 
* **^B** Backward in a file. 

Both ^F and ^B keeps a few lines for continuity.

Let's look at Search patterns using vim.

* **/Search** for a pattern. **n** will move the next occurrence of the word.
* **?Search** for a pattern backward direction. n will take it to the next occurrence of the word in the reverse direction. If the search string you give is not present in the file, then a diagnostic is printed in the last line and cursor is returned to where it was before.
* **/^search** will search for search in the beginning of the line.
* **/end$** will search for end at the end of the line.

Search can be considered a form of navigation if you know the word you want to
go to. But often navigations requirements are pretty generic. Like the following.

* **G** Goes to the End of the file.
* **nG** will Go to the nth line.
* **``** Go to the previous position in the file,mostly used when you G'ed to a different line.

Unrelated, but since it uses the same keystroke - 

* **^G** gives the state of the file

Now for some line based navigation.

* **+** moves to the next line
* **-** moves to the previous line. 
* **RETURN** Key has the same effect as + key.

* H Home
* nH n lines from H
* M middle of the screen.
* L Last line of the screen.
* w advance cursor to the next word of the line.
* b move backward a word.
* W advance cursor forward without stopping at punctuation. W think as Big Word.
* B advance cursor backward without stoppingg at punctuaton.
* The word keys wrap around the end of the line rathar than stopping at the end.
* SPACE Advance by one position.
* ^H Backspace the cursor
* ^N Next line same column.
* ^P Previous line same column.
* view instead of vi will set readonly option to the file being edited.
* i stands for insert
* e moves to end of the word.
* a appends. So e and then a might be helpful to pluralize the word.
* i places the cursor to the left of the word and a places the cursor to the right of the word.
* o inserts a line below.
* O inserts a line above.

Many editor related commands are invoked by the same letter key and differ
upper case vs lower case.The main difference being the upper case letter act in
the opposite direction than (up or backward) the lower case letter.

* ^H or # is used to backspace can be used in the editor as well.
* @,^X or ^U to kill input lines for the character you typed on the input line.

Notice that you cannot erase a character which you have not inserted. Cannot
backspace over end of line.

* x deletes the character.
* nx deletes n characters.
* dw deletes the word.
* . hitting the . keys repeats the previous command. analogous with ellipsis '...'
* db deletes the word backwards.
* dSPACE deletes a single character equivalent to x
* cw changes the word
* dd deletes the line.
* @ signs you see are just placeholder.It helps prevent lengthy redraws of lines.
* cc changes the whole line.
* ndd,ncc deletes or changes n lines.
* dnL delete upto (nlines) or including the Last line.
* u undo command to reverse the change. u also undoes a u.
* U restores the current line to the state before you started changing it. u does only a single character.
* fx finds the next x character in the current line.
* ; finds the next instance of the same character
* F finds the character backwards.; repeats it backward.
* tx finds the text upto the next x. helpful where you dtx - delete upto but not x;
* T reverse of t
* $ moves to the end of the line.

^V Control Characters can be brought in the file by beginning an insert and then typing a Ctrl-v before the control character.

* ( previous sentence
* ) Next Sentence
* d) Deletes upto the end of the current sentence.
* d( If in middle of sentences deletes to the beginning. OR if at the beginning deletes the previous sentence.
* { and } operations move over paragraphs.
* [[ and ]] move over sections.
* y yanks a copy of the object which follows into the unnamed buffer.
* "xy; x can take [a-z] stands for the buffer name and take the text in the corresponding buffer.
* p puts the text below or after the cursor.
* P puts before or above the cursor.
* "xP puts the content in the register x.
* YP Makes a copy of the current line and leaves you on the copy, which is before the current line.
* Y is convenient abbreviation for yy.
* Yp will make a copy of the current line and place it after the current line.
* nYP Number of lines to duplicate.

* "a5dd delete 5 lines and place it in a.
* "ap at the resting place,puts the contents of the buffer a.
* :e edit another file.
* :q! quits editor without saving.
* :e! re-edits the same file (starting over)
* set autowrite
* :n move the next file in when you do a :e to open a new file from the current file.
* :!cmdCR Get to a shell and execute a single command. The system will run the single command cmd and system will ask you to hit Return to continue. You can give another command when it asks for a Return.
* :sh Will give you a new shell. Do a Ctrl-D when done. (Unix)
* mx marks the current line with a letter.

::
        * a moves to the marked position.

* Ctrl-L Refreshes the Screen.
* @ characters in the screen can be removed by pressing Ctrl-R (??)
* zRETURN will place the line to the top of the window
* z. will place the line under the cursor to the middle of the window.
* set slow
* set noslow
* set redraw
* set noredraw
* options are three kinds: numeric options,string options or toggle options.
* :set
* :set opt?CR
* :set allCR
* vi -r for recovering files if the system crashed.
* :set wm1=10CR Setting the wrap margin to 10. This causes all lines to be
  broken at a space at least 10 columns from the right hand edge of the screen.
* J joins the line.
* set autoindent
* set shiftwidth
* << Shift One line left
* >> Shift One line right
* <L Shift rest of the display left
* >L Shift rest of the display right
* % Matching Parenthesis
* ]] moves to the next } in a program. useful with y]]
* !sortCR will run the sort command over the buffer or the selected list(Unix).
* set lisp
* =% at the beginning of the function, will realign all the lines of the function declaration.
* :map lhs rhsCR
* :map q :wq
* (This is supposed to be :map q :wq^V^VCRCR;the first CR for map association and second CR for the command itself)
* Placing a ! after the word map causes the map to be applied in the input mode rather than command mode.
* :abbreviate (:ab)
* :unabbreviate (:una)
* :ab cs Computer Science
* 5a+-----ESC
* +-----+-----+-----+-----+-----
* new window size is reflected when / or ? is prefixed with count. (unable to verify this)
* dw 3. deletes 3 more words. 2. will delete two more words.
* :x write if neccessary and then quit (same as ZZ)
* :e name; edit file name
* :e! reedit discarding the changes.
* :e + n edit starting at the end.
* :e +n edit starting at n
* :e # edit an alternate file
* :w filename;write filename
* :w! filename;overwrite filename
* :x,yw name write lines x through y to name
* :r name read the file name to buffer
* :n edit the next file in the arg list
* :n! edit next file, discarding the changes to the current.
* :n args;specify new argument list
* :ta tag edit file containing tag. (:help ta)
* :e +/pat
* :e +?pat
* :ta can be used with ctags programs. :ta <function_name> will move you to that function.
* /pattern-n nth line before the line containing the pattern
* /pattern+n nth line after the line containing the pattern
* set ic ignores the case during the search
* set noic toggles the above.
* set nomagic the search is now NOT regex
* Q escapes you to ex mode
* An appendix of all the characters is presented.
* :vimtutor


Vim site www.vim.org 

phoe6: Is there a way to make vim "Show" the tabs and spaces by escape sequences. In my python script, its mixed up, I just want to see it.
mgedmin: phoe6: set list
mgedmin: I also recommend :set listchars=tab:>-,trail:.,extends:>
mgedmin: as well as :set expandtab
phoe6: thanks, set list did it. let me try the other suggestion.
phoe6: this might be needed only when you want to see it. right, would be a bad bad idea to put it in vimrc
phoe6: the second suggest was cool too. expandtab just expands tabs to equal number of spaces, am I right?
phoe6: does using screen disturb the .vimrc in any way?
mgedmin: phoe6: I have set list listchars=... in my .vimrc, yes
mgedmin: epxendtab makes the <tab> key insert spaces, not tabs
phoe6: hmm..
mgedmin: I also recommend set softtabstop=4
mgedmin: to convert existing tabs to spaces, use :retab


set foldexpr=getline(v:lnum)=~'^class'?'>1':'='

phoe6: yeah, I know. I was to try expr today
phoe6: I have been unsuccessful with fold-expr.
phoe6: :set fdm=expr and then setting that :set foldexpr 
phoe6: is anythign else needed? 
djanowski: hello all. i'm writing a function that behaves differently depending
on the file type. how can i get the current file type into a variable?
jnrowe: djanowski▶ &filetype already exists ;)
graywh: phoe6, oh, i know why
phoe6: what could be reason, graywh?
graywh: the problem is that the lines that don't match the pattern return 0
djanowski: jnrowe: awesome, let me check
graywh: :set foldexpr=getline(v:lnum)=~'^class'?'>1':'='
graywh: that will only match top-level classes, obviously
djanowski: jnrowe: is there an equivalent to C's switch statement?
phoe6: :) yeah..
graywh: if you want better python folding, find a plugin that does everything
phoe6: ^class would match and if that returns > 1 what does '=' do?
phoe6: I mean, I am trying to understand your foldexpr. 
graywh: keeps fold level from previous line
graywh: :h fold-expr and keep reading
graywh: it's in a table
phoe6: I see. thanks graywh
phoe6: :)
graywh: i use this for python
graywh: http://www.vim.org/scripts/script.php?script_id=515
