========================
Ratpoison Window Manager
========================

Website: http://ratpoison.nongnu.org/

::

        startup_message off
        unmanage panel


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
