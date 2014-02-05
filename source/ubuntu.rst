======
Ubuntu
======

Bash Shortcuts
--------------

    Ctrl-a  Move to the start of the line.
    Ctrl-e  Move to the end of the line.
    Alt-] x Moves the cursor forward to the next occurrence of x.
    Alt-Ctrl-] x    Moves the cursor backwards to the previous occurrence of x.
    Ctrl-u  Delete from the cursor to the beginning of the line.
    Ctrl-k  Delete from the cursor to the end of the line.
    Ctrl-w  Delete from the cursor to the start of the word.
    Ctrl-y  Pastes text from the clipboard.
    Ctrl-l  Clear the screen leaving the current line at the top of the screen.
    Ctrl-x Ctrl-u   Undo the last changes. Ctrl-_
    Alt-r   Undo all changes to the line.
    Alt-Ctrl-e  Expand command line.
    Ctrl-r  Incremental reverse search of history.
    Alt-p   Non-incremental reverse search of history.
    !!  Execute last command in history
    !abc    Execute last command in history beginning with abc
    !n  Execute nth command in history
    ^abc^xyz    Replace first occurrence of abc with xyz in last command and execute it

Vim
===

From: Tim Chase
Subject: Re: appending and incrementing the numbers from a particular point
To: Senthil Kumaran

::

        > My requirement is to add more rows with incrementing numbers upto say 2300.
        > like:
        > 2191 Default SomeText
        > 2192 Default SomeText.
        > 2193
        > 2194
        > 2195
        > .
        > .
        > .
        > .
        > .
        > 2300
        > ~
        > ~
        > How should I go about doing this in vim.


        Well, there are several ways to go about it (as usual...this *is* vim ;)

        The first that comes to mind is something like the following:

        :let i=2193 | while (i <= 3000) | put =i | let i=i+1 | endwhile

        When executed on the "2192" line, will add a whole bunch of other lines
        afterwards. If you want your default text stuff in there too, you can
        simply change the "put =i" to

        put =i." Default Some Text"

        which will pre-populate it with values if you want. If you like to be
        left at the top of that inserted stuff, you can try the inverse. On a
        blank/emtpy line below "2192", you can do

        :let i=3000 | while (i > 2192) | put! =i | let i=i-1 | endwhile

        This would be a direct answer to your question of "how to add more rows,
        incrementing a number each time".

        If, however, you'd like to have it auto-number, something like this
        mapping might do the trick for you (all one line):

        :inoremap <cr> <cr><c-o>:let i=substitute(getline(line('.')-1),
        '^\(\d*\).*', '\1', '')<cr><c-r>=i>0?(i+1).' ':''<cr>

        It can be done without a holding "i" variable, but it becomes about
        twice as large, as both instances of "i" would be replaced with the
        entire contents of the "substitute()" call.

        It should gracefully handle lines with numbers and lines without numbers.

        Help on the following topics should give you more details on what's
        going on there.

        :help getline()
        :he line()
        :he i_^R
        :he while
        :he let
        :he :put
        :he substitute()
        :he /\d

        Hope this helps,

        When executed on the "2192" line, will add a whole bunch of other lines
        afterwards. If you want your default text stuff in there too, you can
        simply change the "put =i" to

        put =i." Default Some Text"

        If someone is relying on this. The change should be:

        put = i . \"Default Text\"

        Note the space between the . and escape of quotes.

Auto scrolling of text in vim.
http://vim.wikia.com/wiki/Automatic_scrolling_of_text

Programs for Study
------------------

* algotutor
* fraqtive
* golly
* gplanarity
* graphthing


Starting with Tmux
------------------

* Start by typing tmux
* CNTL+B is the hotkey for tmux, just as CTRL+A was for screen.
* CNTL+B is remapped to CNTL+A
* CNTL+A ? will give you help for different things.
* CNTL+A c will create a new window.
* CNTL+A x will kill the window.
* CNTL+A <num> will help you move within those windows.

This is enough to get you started with tmux.
