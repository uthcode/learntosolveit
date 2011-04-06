# 'klok' -- A simple alarm clock

# The alarm can be set at 5 minute intervals on a 12 hour basis.
# It is controlled with the mouse:
# - Click and drag around the circle to set the alarm.
# - Click far outside the circle to clear the alarm.
# - Click near the center to set the alarm at the last time set.
# The alarm time is indicated by a small triangle just outside the circle,
# and also by a digital time at the bottom.
# The indicators disappear when the alarm is not set.
# When the alarm goes off, it beeps every minute for five minutes,
# and the clock turns into inverse video.
# Click or activate the window to turn the ringing off.

import stdwin
from stdwinevents import WE_MOUSE_DOWN, WE_MOUSE_MOVE, WE_MOUSE_UP, \
       WE_TIMER, WE_DRAW, WE_SIZE, WE_CLOSE, WE_ACTIVATE
import time
from math import sin, cos, atan2, pi, sqrt

DEFWIDTH, DEFHEIGHT = 200, 200

mouse_events = (WE_MOUSE_DOWN, WE_MOUSE_MOVE, WE_MOUSE_UP)
origin = 0, 0
faraway = 2000, 2000
everywhere = origin, faraway

class struct(): pass   # A class to declare featureless objects

G = struct()           # Global variables (most set in setdimensions())
G.tzdiff = 5*3600      # THINK computes UCT from local time assuming EST!

A = struct()           # Globals used by the alarm
A.set = 1              # True when alarm is set
A.time = 11*60 + 40    # Time when alarm must go off
A.ring = 0             # True when alarm is ringing

def main():
       try:
               realmain()
       except KeyboardInterrupt:
               print 'KeyboardInterrupt'
       finally:
               G.w = 0

def realmain():
       setdimensions(DEFWIDTH, DEFHEIGHT)
       stdwin.setdefwinsize(G.farcorner)
       G.w = stdwin.open('klok')
       settimer()
       while 1:
               type, window, detail = stdwin.getevent()
               if type = WE_DRAW:
                       drawproc(detail)
               elif type = WE_TIMER:
                       settimer()
                       drawproc(everywhere)
               elif type in mouse_events:
                       mouseclick(type, detail)
               elif type = WE_ACTIVATE:
                       if A.ring:
                               # Turn the ringing off
                               A.ring = 0
                               G.w.begindrawing().invert(G.mainarea)
               elif type = WE_SIZE:
                       G.w.change(everywhere)
                       width, height = G.w.getwinsize()
                       height = height - stdwin.lineheight()
                       setdimensions(width, height)
               elif type = WE_CLOSE:
                       break

def setdimensions(width, height):
       if width < height: size = width
       else: size = height
       halfwidth = width/2
       halfheight = height/2
       G.center = halfwidth, halfheight
       G.radius = size*45/100
       G.width = width
       G.height = height
       G.corner = width, height
       G.mainarea = origin, G.corner
       G.lineheight = stdwin.lineheight()
       G.farcorner = width, height + G.lineheight
       G.statusarea = (0, height), G.farcorner
       G.fullarea = origin, G.farcorner

def settimer():
       now = getlocaltime()
       G.times = calctime(now)
       delay = 61 - now % 60
       G.w.settimer(10 * delay)
       minutes = (now/60) % 720
       if A.ring:
               # Is it time to stop the alarm ringing?
               since = (minutes - A.time + 720) % 720
               if since >= 5:
                       # Stop it now
                       A.ring = 0
               else:
                       # Ring again, once every minute
                       stdwin.fleep()
       elif A.set and minutes = A.time:
               # Start the alarm ringing
               A.ring = 1
               stdwin.fleep()

def drawproc(area):
       hours, minutes, seconds = G.times
       d = G.w.begindrawing()
       d.cliprect(area)
       d.erase(everywhere)
       d.circle(G.center, G.radius)
       d.line(G.center, calcpoint(hours*30 + minutes/2, 0.6))
       d.line(G.center, calcpoint(minutes*6, 1.0))
       str = dd(hours) + ':' + dd(minutes)
       p = (G.width - d.textwidth(str))/2, G.height * 3 / 4
       d.text(p, str)
       if A.set:
               drawalarm(d)
               drawalarmtime(d)
       if A.ring:
               d.invert(G.mainarea)

def mouseclick(type, detail):
       d = G.w.begindrawing()
       if A.ring:
               # First turn the ringing off
               A.ring = 0
               d.invert(G.mainarea)
       h, v = detail[0]
       ch, cv = G.center
       x, y = h-ch, cv-v
       dist = sqrt(x*x + y*y) / float(G.radius)
       if dist > 1.2:
               if A.set:
                       drawalarm(d)
                       erasealarmtime(d)
                       A.set = 0
       elif dist < 0.8:
               if not A.set:
                       A.set = 1
                       drawalarm(d)
                       drawalarmtime(d)
       else:
               # Convert to half-degrees (range 0..720)
               alpha = atan2(y, x)
               hdeg = alpha*360.0/pi
               hdeg = 180.0 - hdeg
               hdeg = (hdeg + 720.0) % 720.0
               atime = 5*int(hdeg/5.0 + 0.5)
               if atime <> A.time or not A.set:
                       if A.set:
                               drawalarm(d)
                               erasealarmtime(d)
                       A.set = 1
                       A.time = atime
                       drawalarm(d)
                       drawalarmtime(d)

def drawalarm(d):
       p1 = calcpoint(float(A.time)/2.0, 1.02)
       p2 = calcpoint(float(A.time)/2.0 - 4.0, 1.1)
       p3 = calcpoint(float(A.time)/2.0 + 4.0, 1.1)
       d.xorline(p1, p2)
       d.xorline(p2, p3)
       d.xorline(p3, p1)

def erasealarmtime(d):
       d.erase(G.statusarea)

def drawalarmtime(d):
       # A.time is in the range 0..720 with origin at 12 o'clock
       # Convert to hours (0..12) and minutes (12*(0..60))
       hh = A.time/60
       mm = A.time%60
       str = 'Alarm@' + dd(hh) + ':' + dd(mm)
       p1 = (G.width - d.textwidth(str))/2, G.height
       d.text(p1, str)

def calctime(now):
       seconds = now % 60
       minutes = (now/60) % 60
       hours = (now/3600) % 12
       return hours, minutes, seconds

def calcpoint(degrees, size):
       alpha = pi/2.0 - float(degrees) * pi/180.0
       x, y = cos(alpha), sin(alpha)
       h, v = G.center
       r = float(G.radius)
       return h + int(x*size*r), v - int(y*size*r)

def dd(n):
       s = `n`
       return '0'*(2-len(s)) + s

def getlocaltime():
       return time.time() - G.tzdiff

#main()
