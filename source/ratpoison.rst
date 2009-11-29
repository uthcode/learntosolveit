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
#!/bin/bash
xrdb ~/.Xresources &
setxkbmap -option ctrl:nocaps
xsetroot -solid white -cursor_name left_ptr &
xset b off &                    # no beeping
## To avoid stty causing a hang when running xinit directly in a tty,
## source with input as /dev/null.
. ~/.bash_profile </dev/null
xdark &
eval "$(twb-agents)"
unset GPG_TTY                   # don't use pinentry-curses

## Dance so screen subprocesses can talk to GDM-spawned X servers.
if test -n "$XAUTHORITY"
then
    xauth extract - $DISPLAY |
    xauth -f ~/.Xauthority merge -
    unset XAUTHORITY
fi

## Finally start the actual apps.
wait
ssh-add &
twb-xterm &
xscreensaver &
exec twb-loop ratpoison
#!/bin/sh
#### This code is written by Trent W. Buck <trentbuck@gmail.com> and
#### placed in the Public Domain.  All warranties are disclaimed.
####
#### Some years ago, I started using ratpoison.  At the time, I used
#### GUI applications, and ratpoison was quite buggy.  Ratpoison would
#### crash, taking the X server and all my GUI apps with it.
####
#### What I needed was a little script that would start ratpoison and
#### then just sit there.  When ratpoison terminated, it would start a
#### new ratpoison process and wait again.  Here it is::
####
####    $@
####    $0 $@
####
#### Sometimes I would exit ratpoison legitimately with the :quit
#### command; I didn't want it to be restarted in that case.  So I
#### modified the program to::
####
####    $@ ||
####    $0 $@
####
#### I noticed that after a few crashes, I had a bunch of sh processes
#### nested like a set of russian dolls.  So I changed it to ::
####
####    $@ ||
####    exec $0 $@
####
#### One time, I managed to make ratpoison crash a few milliseconds
#### after starting (the default font didn't exist).  The loop was too
#### tight; it hogged all the RAM.  I put in a short delay between
#### loops::
####
####    if ! $@
####    then sleep 1
####         exec $0 $@
####    fi
####
#### Then I decided it would be best if it *asked* the user whether or
#### not the program should be restarted.  And here it is:

restartp () {                   # succeeds iff user chooses yes
    t="Run \`$1' again?"
    m="Shell command \`$1' failed with code $2.  Run it again?"
    if test -n "$DISPLAY"
    then
       ## use a popup
       if zenity --version
       then zenity --title="$t" --question --text="$m"
       elif gmessage --version
       then gmessage -buttons Yes:0,No:1 -default Yes "$m"
       elif Xdialog --version
       then Xdialog --title "$t" --yesno "$m" 6 "$(expr length "$m")"
       elif xmessage -help
       then xmessage -buttons Yes:0,No:1 -default Yes "$m"
       else return 0            # give up and assume yes
       fi >/dev/null 2>&1
    else
       ## use stdio
       printf "%s [Y/n] " "$m"
       read response
       case "$response" in
           [nN]*) return 1;;
       esac
       return 0
    fi
}

"$@"                            # run command
case $? in
    0)  exit 0;;                # command succeded
    126)                        # command not executable
        echo >&2 "$0: $1: Permission denied"
        exit 126;;
    127)                        # command not in $PATH
        echo >&2 "$0: $1: command not found"
        exit 127;;
    *)  if restartp "$1" "$?"   # failed; try again?
        then sleep 1
            exec "$0" "$@"
        fi;;
esac
