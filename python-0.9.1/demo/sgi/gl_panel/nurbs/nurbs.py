#! /ufs/guido/bin/sgi/python

# Fancy NURBS demo.  Require Z buffer and Panel Library.

from gl import *
from GL import *
from DEVICE import *
from nurbsdata import *
import panel

#
# flags = trim_f, invis_f, cpvis_f, tpvis_f, axvis_f, freeze_f
#
TRIM   = 0
VIS    = 1
CPVIS  = 2
TPVIS  = 3
AXVIS  = 4
FREEZE = 5
flags = [0, 1, 0, 0, 0, 0]

def draw_axis () :
       cpack (0x0)
       zero = (0.0, 0.0, 0.0)
       #
       one = (1.0, 0.0, 0.0)
       smallline (zero, one)
       cmov (1.0, 0.0, 0.0)
       charstr ('x')
       #
       one = (0.0, 1.0, 0.0)
       smallline (zero, one)
       cmov (0.0, 1.0, 0.0)
       charstr ('y')
       #
       one = (0.0, 0.0, 1.0)
       smallline (zero, one)
       cmov (0.0, 0.0, 1.0)
       charstr ('z')

DELTA = 0.1

def cross (p) :
       p0 = [p[0], p[1], p[2]]
       p1 = [p[0], p[1], p[2]]
       for i in range (0, 3) :
               p0[i] = p0[i] + DELTA
               p1[i] = p1[i] - DELTA
               smallline (p0, p1)
               p0[i] = p0[i] - DELTA
               p1[i] = p1[i] + DELTA

def smallline (p0, p1) :
       bgnline ()
       v3f (p0)
       v3f (p1)
       endline ()

def draw_pts (pnts, color) :
       linewidth (2)
       cpack (color)
       for i in pnts :
               cross (i)

def init_windows():
       foreground()
       wid = winopen('nurbs')
       wintitle('NURBS Surface')
       doublebuffer()
       RGBmode()
       gconfig()
       lsetdepth(0x000, 0x7fffff)
       zbuffer( TRUE )

def init_view():
       mmode(MPROJECTION)
       ortho( -5., 5., -5., 5., -5., 5. )
       #
       mmode(MVIEWING)
       loadmatrix(idmat)
       #
       lmbind(MATERIAL, 1)

def set_scene(flags):
       #
       lmbind(MATERIAL, 0)
       RGBcolor(150,150,150)
       lmbind(MATERIAL, 1)
       clear()
       zclear()
       #
       if not flags[FREEZE] :
               rotate( 100, 'y' )
               rotate( 100, 'z' )

def draw_trim_surface(flags):
       pnts = ctlpoints
       if flags[VIS] :
               bgnsurface()
               nurbssurface(surfknots,surfknots,pnts,ORDER,ORDER,N_XYZ)
               if flags[TRIM]:
                       bgntrim()
                       nurbscurve(trimknots,trimpoints,ORDER-1,N_STW)
                       endtrim()
               endsurface()
       #
       if flags[CPVIS] :
               for i in pnts :
                       draw_pts (i, RED)
       #
       if flags[TPVIS] :
               tpts = trimpoints
               draw_pts (tpts, YELLOW)
       #
       if flags[AXVIS] :
               draw_axis ()
       #
       swapbuffers()

def make_lights():
       lmdef(DEFLMODEL,1,[])
       lmdef(DEFLIGHT,1,[])
       #
       # define material #1
       #
       a = []
       a = a + [EMISSION, 0.0, 0.0, 0.0]
       a = a + [AMBIENT,  0.1, 0.1, 0.1]
       a = a + [DIFFUSE,  0.6, 0.3, 0.3]
       a = a + [SPECULAR,  0.0, 0.6, 0.0]
       a = a + [SHININESS, 2.0]
       a = a + [LMNULL]
       lmdef(DEFMATERIAL, 1, a)
       #
       # turn on lighting
       #
       lmbind(LIGHT0, 1)
       lmbind(LMODEL, 1)

def main():
       init_windows()
       make_lights()
       init_view()
       #
       panel.needredraw()
       panels = panel.defpanellist('nurbs.s')
       p = panels[0]
       #
       def cbtrim (a) :
               flags[TRIM:TRIM+1] = [int (a.val)]
       p.trim.upfunc = cbtrim
       #
       def cbquit (a) :
               import sys
               sys.exit (1)
       p.quit.upfunc = cbquit
       #
       def cbmotion (a) :
               flags[FREEZE:FREEZE+1] = [int (a.val)]
       p.motion.upfunc = cbmotion
       #
       def cbxyzaxis (a) :
               flags[AXVIS:AXVIS+1] = [int (a.val)]
       p.xyzaxis.upfunc = cbxyzaxis
       #
       def cbtrimpnts (a) :
               flags[TPVIS:TPVIS+1] = [int (a.val)]
       p.trimpnts.upfunc = cbtrimpnts
       #
       def cbcntlpnts (a) :
               flags[CPVIS:CPVIS+1] = [int (a.val)]
       p.cntlpnts.upfunc = cbcntlpnts
       #
       def cbnurb (a) :
               flags[VIS:VIS+1] = [int (a.val)]
       p.nurb.upfunc = cbnurb
       #
       set_scene(flags)
       setnurbsproperty( N_ERRORCHECKING, 1.0 )
       setnurbsproperty( N_PIXEL_TOLERANCE, 50.0 )
       draw_trim_surface(flags)
       #
       while 1:
               act = panel.dopanel()
               #
               wid =  panel.userredraw ()
               if wid :
                       winset (wid)
                       reshapeviewport()
                       set_scene(flags)
                       draw_trim_surface(flags)
               #
               set_scene(flags)
               draw_trim_surface(flags)

main()
