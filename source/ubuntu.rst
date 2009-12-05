======
Ubuntu
======

phoe6: In xterm, I can change the size of fonts and windows by doing Control +
Right Click and Selecting Huge from the VT Font menu. Can I have this setting
in the .Xresources file? I am not able to find out what I should do.

phoe6: Everytime I don't want to do a CTRL+RIGHT CLICK + Select Huge VT Font. I
want it as my standard configuration.

place the following in   .Xresources    or    .Xdefault

::
         Xterm.*font:                     10x20
         .Xresources is a one time load event when you starup the window manager.
         .Xdefaults is loaded on every xterm window.

For more info *man  X* or *man  xterm*

For list of fonts,xlsfonts Edit .Xdefaults in your home directory and add a
line as follows:

::

        font: 9x15
        font: -adobe-courier-medium-r-normal-*-14-*-*-*-*-*-*-*

The next time you start an X session, you should have the specified font as
your default. 

You want a line like:

::

        XTerm*VT100*font:            Fixed

(except different). Look in your app-defaults/XTerm file for clues. 

My Constant thoughts with Ubuntu is to how to automate various tasks that I
routinely do.

ratpoison window manager related:
	* starting nm-applet automatically.
mutt folders.
office email via mutt.

fetchmail automatically.
http://ubuntuforums.org/showthread.php?t=175438

Virtual machine
----------------
1. Install Ubuntu JeOS for just enough Operating System. It is super cool.
2. Follow this information for expanding the console only portion. 
   http://forums.virtualbox.org/viewtopic.php?f=3&t=12590&p=51680&hilit=JeOS#p51680
3. My Settings were:
   VboxManage setextradata Juice "CustomVideoMode1" "1424x856x16"
4. Managing ssh: http://linuxgazette.net/issue67/nazario2.html


httpd
-----

Also at this point, you can specify which features you want included in Apache
HTTPd by enabling and disabling modules. The Apache HTTP Server comes with a
Base set of modules included by default. Other modules are enabled using the
--enable-module option, where module is the name of the module with the 
mod_string removed and with any underscore converted to a dash. You can also
choose to compile modules as shared objects (DSOs) -- which can be loaded or
unloaded at runtime -- by using the option --enable-module=shared. Similarly,
you can disable Base modules with the --disable-module option. Be careful when
using these options, since configure cannot warn you if the module you specify
does not exist; it will simply ignore the option.

Ubuntu's HTTPD Document gives a general overview.
https://help.ubuntu.com/8.04/serverguide/C/httpd.html

To enable the mod_filter and mod_ext_filter I had to do:
sudo a2enmod ext_filter
sudo a2enmod filter

::

        [08:59:48 senthil]$sudo a2enmod ext_filter
        Enabling module ext_filter.
        Run '/etc/init.d/apache2 restart' to activate new configuration!
        [/etc/apache2/mods-available]
        [09:00:14 senthil]$sudo a2enmod filter
        Enabling module filter.
        Run '/etc/init.d/apache2 restart' to activate new configuration!

The text replacement at the response worked properly.

::

        # mod_ext_filter directive to define a filter which
        # replaces text in the response
        #
        ExtFilterDefine fixtext mode=output intype=text/html \
        cmd="/bin/sed s/verdana/arial/g"

        <Location />
        # core directive to cause the fixtext filter to
        # be run on output
        SetOutputFilter fixtext
        </Location> 

Now I can slow down the server too..


mutt
----

::


        #======================================================#
        # Boring details
        set realname = "Senthil Kumaran"
        set from = "orsenthil@gmail.com"
        set use_from = yes
        set envelope_from ="yes"

        # If not set in environment variables:
        set spoolfile = /var/spool/mail/ors

        #======================================================#
        # Folders
        set folder="~/Mail"                # Mailboxes in here
        set record="+sent"                 # where to store sent messages
        set postponed="+postponed"         # where to store draft messages
        set move=yes                       # Don't move mail from the spool.

        #======================================================#
        # Watch these mailboxes for new mail:
        mailboxes ! +Fetchmail +slrn +mutt
        set sort_browser=alpha    # Sort mailboxes by alpha(bet)

        #======================================================#
        # Order of headers and what to show
        hdr_order Date: From: User-Agent: X-Mailer \
                  To: Cc: Reply-To: Subject:
        ignore *
        unignore Date: From: User-Agent: X-Mailer  \
                 To: Cc: Reply-To: Subject:
                       
        #======================================================#
        # which editor do you want to use? 
        # vim of course!
        set editor="vim -c 'set tw=70 et' '+/^$' " 
        set edit_headers          # See the headers when editing

        #======================================================#
        # Aliases

        set sort_alias=alias  # sort aliases in alpha order by alias name

        #======================================================#
        # Sorting
        set sort=threads
        set sort_aux=subject

        #======================================================#
        # Colours: This scheme is fairly basic and only
        # really works if your Terminal background is white

        #color hdrdefault black        default   
        #color quoted     red          default   
        #color signature  brightblack  default   
        #color indicator  brightwhite  red
        #color attachment black        green
        #color error      red          default   
        #color message    blue         default   
        #color search     brightwhite  magenta
        #color status     brightyellow blue
        #color tree       red          default   
        #color normal     blue         default   
        #color tilde      green        default   
        #color bold       brightyellow default   
        #color markers    red          default  


        #======================================================#
        # Experiments with Suitable Colors
        #

        color hdrdefault green default   
        color header     yellow default Subject*
        color header     yellow default From*
        color quoted     blue default   
        color signature  green default   
        color indicator  yellow default
        color attachment white default
        color error      red   cyan 
        color message    magenta cyan 
        color search     white default
        color status     red cyan
        color tree       magenta default   
        color normal     cyan default   
        color tilde      green default   
        color bold       brightyellow default   
        color markers    red default  

        #======================================================#
        # Odds and ends
        #
        set markers          # mark wrapped lines of text in the pager with a +
        set smart_wrap       # Don't wrap mid-word
        set pager_context=5  # Retain 5 lines of previous page when scrolling.
        set status_on_top    # Status bar on top.

        set sendmail_wait=-1
        #======================================================#
        # To deal with HTML mails.
        #
        set implicit_autoview
        auto_view text/html application/x-pgp-message
        set mailcap_path = "~/.mailcap"
        macro index \cb |urlview\n 'call urlview to extract URLs out of a message'
        push <show-version>  # Shows mutt version at startup
        alias ssk_friends ssk_friends <SSK_friends@yahoogroups.co.in>

Makefile
--------

* Makefile contains a list of rules and dependencies on how to build a program.
 

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

! this are Xresources to make xterm look good
! put into ~/.Xresources
! after changing contents, run xrdb -merge .Xresources
! gentoo has a bug so that it doesnt read it when X starts, so add above
! command to /etc/xfce4/xinitrc (top) and be happy.

!xterm*background:	Black
!xterm*foreground:	Grey
xterm*font:		-Misc-Fixed-Medium-R-Normal--20-200-75-75-C-100-ISO10646-1
!xterm*font:		-misc-fixed-medium-r-normal--18-*-*-*-*-*-iso10646-1
!xterm*iconPixmap: ...
!xterm*iconPixmap:       /usr/share/pixmaps/gnome-gemvt.xbm
!xterm*iconMask:         /usr/share/pixmaps/gnome-gemvt-mask.xbm
!XTerm*iconName: terminal
!Mwm*xterm*iconImage: /home/a/a1111aa/xterm.icon
XTerm*loginShell: true
XTerm*foreground: gray90
XTerm*background: black
XTerm*cursorColor: rgb:00/80/00
XTerm*borderColor: white
XTerm*scrollColor: black
XTerm*visualBell: true
XTerm*saveLines: 1000
!! XTerm.VT100.allowSendEvents: True
XTerm*allowSendEvents: True
XTerm*sessionMgt: false
!XTerm*eightBitInput:  false
!XTerm*metaSendsEscape: true
!XTerm*internalBorder:  10
!XTerm*highlightSelection:  true
!XTerm*VT100*colorBDMode:  on
!XTerm*VT100*colorBD:  blue
!XTerm.VT100.eightBitOutput:  true
!XTerm.VT100.titeInhibit:  false
XTerm*color0: black
XTerm*color1: red3
XTerm*color2: green3
XTerm*color3: yellow3
XTerm*color4: DodgerBlue1
XTerm*color5: magenta3
XTerm*color6: cyan3
XTerm*color7: gray90
XTerm*color8: gray50
XTerm*color9: red
XTerm*color10: green
XTerm*color11: yellow
XTerm*color12: blue
XTerm*color13: magenta
XTerm*color14: cyan
XTerm*color15: white
XTerm*colorUL: yellow
XTerm*colorBD: white
!XTerm*mainMenu*backgroundPixmap:     gradient:vertical?dimension=400&start=gray10&end=gray40
!XTerm*mainMenu*foreground:          white 
!XTerm*vtMenu*backgroundPixmap:       gradient:vertical?dimension=550&start=gray10&end=gray40
!XTerm*vtMenu*foreground:             white
!XTerm*fontMenu*backgroundPixmap:     gradient:vertical?dimension=300&start=gray10&end=gray40
!XTerm*fontMenu*foreground:           white
!XTerm*tekMenu*backgroundPixmap:      gradient:vertical?dimension=300&start=gray10&end=gray40
!XTerm*tekMenu*foreground:            white
!XTerm Profiles (idea from dag wieers)
XTerm*rightScrollBar: true
