#! /ufs/guido/bin/sgi/python

# A demo of GL's viewing transformations, showing two views on one scene.
# Requires the NASA AMES Panel Library.  Requires Z buffer.

from gl import *
from GL import *
import panel
from math import sin, cos, pi

inf = 1000000.0
far = 1000.0
near = 100.0

def main():
       foreground()
       #
       keepaspect(1, 1)
       prefposition(10, 610, 10, 610)
       obswid = winopen('Observer View')
       doublebuffer()
       RGBmode()
       gconfig()
       #
       keepaspect(1, 1)
       prefposition(10, 310, 650, 950)
       topwid = winopen('Top View')
       doublebuffer()
       RGBmode()
       gconfig()
       #
       panels = panel.defpanellist('observer.s')
       panels = panels + panel.defpanellist('camera.s')
       panels = panels + panel.defpanellist('topview.s')
       #
       p = panels[0]
       q = panels[1]
       r = panels[2]
       #
       p.farclip = q.farclip
       p.nearclip = q.nearclip
       p.zoom = q.zoom
       p.quitbutton = q.quitbutton
       #
       p.xpos = r.xpos
       p.zpos = r.zpos
       p.direction = r.direction
       #
       p.direction.winds = 1.0         # allow full rotation
       #
       def quit(act):
               import sys
               sys.exit(0)
       p.quitbutton.downfunc = quit
       #
       p.left.back = p
       p.fast_left.back = p
       p.right.back = p
       p.fast_right.back = p
       p.forward.back = p
       p.fast_forward.back = p
       p.reverse.back = p
       p.fast_reverse.back = p
       p.up.back = p
       p.down.back = p
       #
       p.left.activefunc = left
       p.fast_left.activefunc = fast_left
       p.right.activefunc = right
       p.fast_right.activefunc = fast_right
       p.forward.activefunc = forward
       p.fast_forward.activefunc = fast_forward
       p.reverse.activefunc = reverse
       p.fast_reverse.activefunc = fast_reverse
       p.up.activefunc = up
       p.down.activefunc = down
       #
       makeobjects()
       #
       drawall(p, obswid, topwid)
       panel.needredraw()
       while 1:
               act = panel.dopanel()
               if panel.userredraw() or act:
                       drawall(p, obswid, topwid)

def left(a):
       doturn(a.back, 0.01)

def fast_left(a):
       doturn(a.back, 0.1)

def right(a):
       doturn(a.back, -0.01)

def fast_right(a):
       doturn(a.back, -0.1)

def doturn(p, angle):
       alpha = lookangle(p) + angle
       # Reverse the following assignment:
       #       alpha = pi*1.5 - p.direction.val*2.0*pi
       val = (pi*1.5 - alpha) / 2.0 / pi
       while val < 0.0: val = val + 1.0
       while val > 1.0: val = val - 1.0
       p.direction.val = val
       p.direction.fixact()

def forward(a):
       dostep(a.back, 1.0)

def fast_forward(a):
       dostep(a.back, 10.0)

def reverse(a):
       dostep(a.back, -1.0)

def fast_reverse(a):
       dostep(a.back, -10.0)

def dostep(p, step):
       x, y, z = observerpos(p)
       alpha = lookangle(p)
       x = x + step*cos(alpha)
       z = z - step*sin(alpha)
       # Reverse the following assignments:
       #       x = 2.0 * p.xpos.val * near - near
       #       z = near - 2.0 * p.zpos.val * near
       p.xpos.val = (x + near) / 2.0 / near
       p.zpos.val = - (z - near) / 2.0 / near
       p.xpos.fixact()
       p.zpos.fixact()

def up(a):
       doup(a.back, 0.2)

def down(a):
       doup(a.back, -0.2)

def doup(p, step):
       x, y, z = observerpos(p)
       y = y + step
       # Reverse:
       #       y = p.ypos.val * near
       p.ypos.val = y/near
       p.ypos.fixact()

def drawall(p, obswid, topwid):
       #
       winset(obswid)
       obsview(p)
       drawscene()
       swapbuffers()
       #
       winset(topwid)
       topview(p)
       drawscene()
       drawobserver(p)
       swapbuffers()

def drawobserver(p):
       x, y, z = observerpos(p)
       alpha = lookangle(p)
       fov = 2.0 + 1798.0 * p.zoom.val
       beta = fov*pi/3600.0            # Half fov, expressed in radians
       #
       c3i(0, 255, 0)
       #
       move(x, y, z)
       x1 = x + inf*cos(alpha+beta)
       y1 = y
       z1 = z - inf*sin(alpha+beta)
       draw(x1, y1, z1)
       #
       move(x, y, z)
       x1 = x + inf*cos(alpha-beta)
       y1 = y
       z1 = z - inf*sin(alpha-beta)
       draw(x1, y1, z1)

def observerlookat(p):
       x, y, z = observerpos(p)
       alpha = lookangle(p)
       return x, y, z, x+near*cos(alpha), y, z-near*sin(alpha), 0

def observerpos(p):
       x = 2.0 * p.xpos.val * near - near
       y = p.ypos.val * near
       z = near - 2.0 * p.zpos.val * near
       return x, y, z

def lookangle(p):
       return pi*1.5 - p.direction.val*2.0*pi

idmat = 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1

def topview(p):
       mmode(MVIEWING)
       ortho(-far, far, -far, far, far, -far)
       loadmatrix(idmat)
       rotate(900, 'x')

def obsview(p):
       fov = 2.0 + 1798.0 * p.zoom.val
       nearclip = p.nearclip.val * 10.0
       farclip = p.farclip.val * 10.0*far
       aspectratio = 1.0
       mmode(MVIEWING)
       perspective(int(fov), aspectratio, nearclip, farclip)
       loadmatrix(idmat)
       lookat(observerlookat(p))

def drawscene():
       #
       # clear window
       #
       c3i(0, 0, 0)
       clear()
       #
       # turn on z buffering and clear it
       #
       zbuffer(TRUE)
       zclear()
       #
       # dark blue sky (depending on your gamma value!)
       #
       c3i(0, 0, 150)
       callobj(41)
       #
       # bright red near and far units circle
       # (use rotate since circ() always draws in x-y plane)
       #
       c3i(255, 0, 0)
       pushmatrix()
       rotate(900, 'x')
       circ(0.0, 0.0, near)
       circ(0.0, 0.0, far)
       popmatrix()
       #
       # bright white striping
       #
       c3i(255, 255, 200)
       callobj(42)
       #
       # building (does its own colors)
       #
       building()
       #
       # some other objects
       #
       dice()

def makeobjects():
       #
       # sky object
       #
       makeobj(41)
       pmv(-inf, 0.0, -far)
       pdr(inf, 0.0, -far)
       pdr(inf, inf, -far)
       pdr(-inf, inf, -far)
       pclos()
       closeobj()
       #
       # road stripes object
       #
       makeobj(42)
       stripes()
       closeobj()
       #
       # lighting model definitions
       #
       deflight()

def stripes():
       #
       # left line
       #
       botrect(-11, -10, far, -far)
       #
       # right line
       #
       botrect(10, 11, far, -far)
       #
       # center lines
       #
       z = far
       while z > -far:
               botrect(-0.5, 0.5, z, z - 4.0)
               z = z - 10.0

def dice():
       from block import block
       uselight()
       pushmatrix()
       translate(0.0, 1.0, -20.0)
       rotate(200, 'y')
       block(1, 0, 0, 0, 0, 0)
       translate(1.0, 0.0, 3.0)
       rotate(500, 'y')
       block(2, 0, 0, 0, 0, 0)
       popmatrix()

def deflight():
       # Material for first die (red)
       lmdef(DEFMATERIAL, 1, (DIFFUSE, 1.0, 0.0, 0.0))
       # Material for second die (green)
       lmdef(DEFMATERIAL, 2, (DIFFUSE, 0.0, 1.0, 0.0))
       # First light source (default: white, from front)
       lmdef(DEFLIGHT, 1, ())
       # Second light source (red, from back)
       lmdef(DEFLIGHT, 2, (POSITION, 0.0, 1.0, -1.0, 0.0))
       lmdef(DEFLIGHT, 2, (LCOLOR, 1.0, 0.0, 0.0))
       # Lighting model
       lmdef(DEFLMODEL, 1, (AMBIENT, 0.0, 0.0, 1.0))

def uselight():
       lmbind(LIGHT0, 1)
       lmbind(LIGHT1, 2)
       lmbind(LMODEL, 1)
       # (materials are bound later)

def building():
       #
       c3i(0, 255, 255)
       #
       # house bounding coordinates
       #
       x1 = 20.0
       x1a = 25.0
       x2 = 30.0
       y1 = 0.0
       y2 = 15.0
       y2a = 20.0
       z1 = -40.0
       z2 = -55.0
       #
       # door y and z coordinates
       #
       dy1 = 0.0
       dy2 = 4.0
       dz1 = -45.0
       dz2 = -47.0
       #
       # front side (seen from origin)
       #
       A1 = (x1, y1, z1)
       B1 = (x2, y1, z1)
       C1 = (x2, y2, z1)
       D1 = (x1a, y2a, z1)
       E1 = (x1, y2, z1)
       #
       # back size
       #
       A2 = (x1, y1, z2)
       B2 = (x2, y1, z2)
       C2 = (x2, y2, z2)
       D2 = (x1a, y2a, z2)
       E2 = (x1, y2, z2)
       #
       # door in the left side
       #
       P = x1, dy1, dz2
       Q = x1, dy2, dz2
       R = x1, dy2, dz1
       S = x1, dy1, dz1
       #
       # draw it
       #
       concave(TRUE)
       c3i(255, 0, 0)
       face(A1, B1, C1, D1, E1)
       c3i(127, 127, 0)
       face(A1, E1, E2, A2, P, Q, R, S)
       c3i(0, 255, 0)
       face(E1, D1, D2, E2)
       c3i(0, 127, 127)
       face(D1, C1, C2, D2)
       c3i(0, 0, 255)
       face(C1, B1, B2, C2)
       c3i(127, 0, 127)
       face(E2, D2, C2, B2, A2)
       concave(FALSE)

def face(points):
       bgnpolygon()
       varray(points)
       endpolygon()

# draw a rectangle at y=0.0
#
def botrect(x1, x2, z1, z2):
       polf(x1, 0.0, z1, x2, 0.0, z1, x2, 0.0, z2, x1, 0.0, z2)

main()
