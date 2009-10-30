========================
Ratpoison Window Manager
========================

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
