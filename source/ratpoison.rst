========================
Ratpoison Window Manager
========================

Website: http://ratpoison.nongnu.org/

::

        startup_message off
        unmanage panel
        unmanage MPlayer

        #layouts [ ] [|] [|= [-] [+]
        definekey top M-F1 exec ratpoison -c "echo Layout 1" -c "select -" -c "only" -c "next"
        definekey top M-F2 exec ratpoison -c "echo Layout 2" -c "select -" -c "only" -c "hsplit" -c "next"
        definekey top M-F3 exec ratpoison -c "echo Layout 3" -c "select -" -c "only" -c "hsplit" -c "next" -c "focusright" -c "next" -c "vsplit" -c "next"
        definekey top M-F4 exec ratpoison -c "echo Layout 4" -c "select -" -c "only" -c "vsplit" -c "next"
        definekey top M-F5 exec ratpoison -c "echo Layout 5" -c "select -" -c "only" -c "hsplit" -c next -c "vsplit" -c next -c "focusright" -c next -c "vsplit" -c "next"

        set winname title
        set winfmt %n %s %t
        set fgcolor #FFFFFF
        set bgcolor #000000
        set font -*-terminus-medium-r-normal-*-14-*-*-*-*-*-*-*
        set winliststyle column
        set inputwidth 400
        set waitcursor 1
        set padding 0 20 0 0
        set barpadding 1 1
        set wingravity n 
        set transgravity center
        set bargravity nw
        set border 0
        set barborder 1
        set inputwidth 800

        definekey top M-S-Return exec urxvt
        definekey top M-m exec $(dmenu_path | dmenu)
        definekey top M-w exec ratpoison -c "select `ratpoison -c "windows" | dmenu | awk '{print $1}'`" 
        definekey top M-q kill
        definekey top M-C-Left exchangeleft
        definekey top M-C-Right exchangeright
        definekey top M-C-Up exchangeup
        definekey top M-C-Down exchangedown
        definekey top M-Left resize -20 0
        definekey top M-Right resize 20 0
        definekey top M-Up resize 0 20
        definekey top M-Down resize 0 -20

        bind o only
        bind v hsplit
        bind h vsplit


phoe6: I use :tmpwm openbox at times, but once I exit it. I don't have control
over ratpoison windows.. I seem to need to close all windows and start over
again.. have you observed it? Is there any solution?
twb: phoe6: I noticed that a while ago, it's a bug
twb: I just have ratpoison configured to auto-restart, and so I "close" openbox
by doing "killall -9 openbox ratpoison"
twb: http://twb.ath.cx/Preferences/.bin/twb-loop and http://twb.ath.cx/
Preferences/.xinitrc
phoe6: thanks twb.. that's a good idea to auto-restart ratpoison and doing a
kill.
phoe6: do you know the status of the bug. is it already reported at ratpoison
tracker?
twb: I worked that out years ago when ratpoison would segfault hourly :-)
twb: I don't know, I just ignored it. I use :tmpwm maybe once a year.
phoe6: :) hahaa
twb: I noticed the problem years ago, and I think I mentioned it to sabetts in
passing.
phoe6: you know what, if you do topcoder ( which is a javaws) or say play with
(Alice programming) you seem to need :tmpwm. That's one thing which is helping
me as not to get back to gnome-window manager. :)
twb: You might prefer xmonad or something, to ratpoison. It supports "floating
windows", so you don't have to :tmpwm just for one or two windows.
phoe6: hmm.. should try that one.
