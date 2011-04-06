# Module 'stdwinsupport'

import stdwin

eventnames =              ['null', 'activate', 'char', 'command']
eventnames = eventnames + ['mouse_down', 'mouse_move', 'mouse_up', 'menu']
eventnames = eventnames + ['size', 'move', 'draw', 'timer', 'deactivate']

we_null       =  0
we_activate   =  1
we_char       =  2
we_command    =  3
we_mouse_down =  4
we_mouse_move =  5
we_mouse_up   =  6
we_menu       =  7
we_size       =  8
we_move       =  9
we_draw       = 10
we_timer      = 11
we_deactivate = 12

commandnames = ['?', 'close', 'left', 'right', 'up', 'down', 'cancel']
commandnames = commandnames + ['backspace', 'tab', 'return']

wc_close     = 1
wc_left      = 2
wc_right     = 3
wc_up        = 4
wc_down      = 5
wc_cancel    = 6       # not reported -- turned into KeyboardInterrupt
wc_backspace = 7
wc_tab       = 8
wc_return    = 9
