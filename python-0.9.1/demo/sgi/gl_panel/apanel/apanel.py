#! /ufs/guido/bin/sgi/python

# A (too) trivial control panel to record a sound sample and play it back.
# Requires the audio built-in module.
# Requires the NASA AMES Panel Library.

import sys

import gl
import panel

panel.block(1)

import audio

def main():
       gl.foreground()
       gl.noport()
       #gl.prefposition(700, 850, 950, 970)
       wid = gl.winopen('audio demo')
       #
       panels = panel.defpanellist('apanel.s') # XXX
       p = panels[0]
       p.playbackbutton.back = p
       p.recordbutton.back = p
       p.sample = ''
       #
       def quit(a):
               sys.exit(0)
       #
       p.quitbutton.downfunc = quit
       #
       def playback(a):
               p = a.back
               gain = int(255.0*p.outputgain.val)
               a.val = 1.0
               a.fixact()
               panel.drawpanel()
               audio.setoutgain(gain)
               audio.write(p.sample)
               audio.setoutgain(0)
               a.val = 0.0
               a.fixact()
       #
       p.playbackbutton.downfunc = playback
       #
       def record(a):
               p = a.back
               size = int(10.0 * 8192.0 * p.recordsize.val)
               a.val = 1.0
               a.fixact()
               panel.drawpanel()
               audio.setoutgain(0)
               p.sample = audio.read(size)
               a.val = 0.0
               a.fixact()
       #
       p.recordbutton.downfunc = record
       #
       while 1:
               act = panel.dopanel()

main()
