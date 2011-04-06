#! /ufs/guido/bin/sgi/python

from gl import *
from objdict import *
from GL import *
import DEVICE, time
import objectdef, light, panel, material

def fixmatact (p) :
       p.diffR.fixact ()
       p.diffG.fixact ()
       p.diffB.fixact ()
       p.specR.fixact ()
       p.specG.fixact ()
       p.specB.fixact ()
       p.shine.fixact ()

def fixlichtact (p) :
       p.R.fixact ()
       p.G.fixact ()
       p.B.fixact ()
       p.X.fixact ()
       p.Y.fixact ()
       p.Z.fixact ()
       p.local.fixact ()

def cbsetlight (a) :
       p = a.back
       setlight (p, a.label)

def cbsetmaterial (a) :
       p = a.back
       setmaterial (p, a.label)

mater = [0]
licht = [0]

def setmaterial (p, mname) :
       #
       mater [0:1] = [material.materdict [mname]]
       #
       p.diffR.val = mater [0][1]
       p.diffG.val = mater [0][2]
       p.diffB.val = mater [0][3]
       #
       p.specR.val = mater [0][5]
       p.specG.val = mater [0][6]
       p.specB.val = mater [0][7]
       #
       p.shine.val = mater [0][9] / 128.0
       fixmatact (p)

def setlight (p, mname) :
       #
       licht [0:1] = [material.lichtdict [mname]]
       #
       p.R.val = licht [0][1]
       p.G.val = licht [0][2]
       p.B.val = licht [0][3]
       #
       p.X.val = (licht [0][5] + 10.0) / 20.0
       p.Y.val = (licht [0][6] + 10.0) / 20.0
       p.Z.val = (licht [0][7] + 10.0) / 20.0
       #
       p.local.val = licht [0][8]
       #
       fixlichtact (p)

def cbmaterial (a) :
       #
       if mater[0] = 0 : return
       #
       p = a.back
       mater [0][5:8] = [p.diffR.val, p.diffG.val, p.diffB.val]
       mater [0][1:4] = [p.specR.val, p.specG.val, p.specB.val]
       mater [0][9:10] = [128.0 * p.shine.val]
       light.bindlight (0)

def cblight (a) :
       #
       if licht[0] = 0 : return
       #
       p = a.back
       licht [0][1:4] = [p.R.val, p.G.val, p.B.val]
       licht [0][5:8] = [20.0 * p.X.val - 10.0, 20.0 * p.Y.val - 10.0, 20.0 * p.Z.val - 10.0]
       if p.local.val = 0.0 :
               licht [0][8:9] = [0.0]
       else:
               licht [0][8:9] = [1.0]
       #
       light.bindlight (0)

#
# initgl : initialize window, pipeline, light, viewing
#
def initgl () :
       #
       # init window
       #
       foreground ()
       keepaspect (1, 1)
       prefposition (100, 500, 100, 500)
       w = winopen ('flying objects')
       keepaspect (1, 1)
       winconstraints ()
       #
       # configure pipline
       #
       doublebuffer ()
       shademodel (GOURAUD)
       zbuffer (1)
       RGBmode ()
       gconfig ()
       #
       # init lighting
       #
       light.bindlight (1)
       #
       # set viewing
       #
       lookat (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0)
       #

#
# drawit : draws the object with the given attributes.
#
# rfac : the rotation factor.
# mat  : the material identification
# attr : a list of attributes :
#
#      [[rotate vector ], [tranlate vector], [scale vector]]
#      i.e :
#      [[rX, rY, rZ], [tX, tY, tZ], [sX, sY, sZ]]
#
def drawit(object, rfac, attr, mat) :
       pushmatrix()
       rot (attr[0][0] * float (rfac), 'X')
       rot (attr[0][1] * float (rfac), 'Y')
       rot (attr[0][2] * float (rfac), 'Z')
       translate(attr[1][0], attr[1][1], attr[1][2])
       scale(attr[2][0], attr[2][1], attr[2][2])
       lmbind(MATERIAL, mat)
       objectdef.drawobject(object)
       popmatrix()

def callbacksphere (a) :
       putDict (objects, 'sphere', int (a.val))

def callbackcylinder (a) :
       putDict (objects, 'cylinder', int (a.val))

def callbackcube (a) :
       putDict (objects, 'cube', int (a.val))

def callbackicecream (a) :
       putDict (objects, 'icecream', int (a.val))

def callbackdisk (a) :
       putDict (objects, 'disk', int (a.val))

def callbackdiamond (a) :
       putDict (objects, 'diamond', int (a.val))

def callbackglass (a) :
       putDict (objects, 'glass', int (a.val))

def callbackpyramid (a) :
       putDict (objects, 'pyramid', int (a.val))

def callbacktable (a) :
       putDict (objects, 'table', int (a.val))

def callbackflat (a) :
       shademodel(FLAT)

def callbackgouraud (a) :
       shademodel(GOURAUD)

def callbackwire (a) :
       objectdef.putFunc ([bgnclosedline, endclosedline])

def callbackfilled (a) :
       objectdef.putFunc ([bgnpolygon, endpolygon])

def callbackquit (a) :
       import sys
       sys.exit (-1)

def allObjects(p, val) :
       p.sphere.val = val
       p.sphere.fixact ()
       p.cube.val = val
       p.cube.fixact ()
       p.cylinder.val = val
       p.cylinder.fixact ()
       p.pyramid.val = val
       p.pyramid.fixact ()
       p.disk.val = val
       p.disk.fixact ()
       p.diamond.val = val
       p.diamond.fixact ()
       p.icecream.val = val
       p.icecream.fixact ()
       p.table.val = val
       p.table.fixact ()
       p.fixpanel()


def callbackshowall (a) :
       #print objects
       for key in objects.keys () :
               #print key
               putDict (objects, key, 1)
       allObjects (a.back, 1.0)

def callbackshownone (a) :
       for key in objects.keys () :
               putDict (objects, key, 0)
       allObjects (a.back, 0.0)

#
# main : makeobjects, initialze graphics, and loop continuously.
#
def main () :
       #
       # iter keeps track of the iterations. It is used as the
       # (x, y, z) rotation increments to which the objects rotate.
       iter = 0
       #
       # make the objects. the objects are put in the odict dictionary
       #
       od =  objectdef.makeobjects ()
       #
       # initialize gl
       #
       initgl ()
       #
       # initialize time and iterations per second
       #
       time0 = time.time () # epoch-time of previous second
       fps = 0 # frames per second
       #
       # initialize panels
       #
       panel.needredraw()
       panels = panel.defpanellist('flying.s') #XXX
       p = panels[0]
       p.sphere.upfunc = callbacksphere
       p.cylinder.upfunc = callbackcylinder
       p.cube.upfunc = callbackcube
       p.icecream.upfunc = callbackicecream
       p.disk.upfunc = callbackdisk
       p.diamond.upfunc = callbackdiamond
       # NOT YET IMPLEMENTED  p.glass.upfunc = callbackglass
       p.pyramid.upfunc = callbackpyramid
       p.table.upfunc = callbacktable
       p.wire.upfunc = callbackwire
       p.filled.upfunc = callbackfilled
       p.flat.upfunc = callbackflat
       p.gouraud.upfunc = callbackgouraud
       p.quit.upfunc = callbackquit
       p.showall.upfunc = callbackshowall
       p.shownone.upfunc = callbackshownone
       p.showall.back = p
       p.shownone.back = p
       #
       qanels = panel.defpanellist('freeze.s') #XXX
       q = qanels[0]
       #
       ranels = panel.defpanellist('materials.s') #XXX
       r = ranels[0]
       r.m9.upfunc = cbsetmaterial
       r.m8.upfunc = cbsetmaterial
       r.m7.upfunc = cbsetmaterial
       r.m6.upfunc = cbsetmaterial
       r.m5.upfunc = cbsetmaterial
       r.m4.upfunc = cbsetmaterial
       r.m3.upfunc = cbsetmaterial
       r.m2.upfunc = cbsetmaterial
       r.m1.upfunc = cbsetmaterial
       r.specR.activefunc = cbmaterial
       r.specG.activefunc = cbmaterial
       r.specB.activefunc = cbmaterial
       r.diffR.activefunc = cbmaterial
       r.diffG.activefunc = cbmaterial
       r.diffB.activefunc = cbmaterial
       r.shine.activefunc = cbmaterial
       r.m9.back = r
       r.m8.back = r
       r.m7.back = r
       r.m6.back = r
       r.m5.back = r
       r.m4.back = r
       r.m3.back = r
       r.m2.back = r
       r.m1.back = r
       r.diffR.back = r
       r.diffG.back = r
       r.diffB.back = r
       r.specR.back = r
       r.specG.back = r
       r.specB.back = r
       r.shine.back = r
       #
       sanels = panel.defpanellist('light.s') #XXX
       s = sanels[0]
       s.X.back = s
       s.Y.back = s
       s.Z.back = s
       s.R.back = s
       s.G.back = s
       s.B.back = s
       s.light1.back = s
       s.light2.back = s
       s.local.back = s
       s.light1.upfunc = cbsetlight
       s.light2.upfunc = cbsetlight
       s.R.activefunc = cblight
       s.G.activefunc = cblight
       s.B.activefunc = cblight
       s.X.activefunc = cblight
       s.Y.activefunc = cblight
       s.Z.activefunc = cblight
       #
       while 1 :
               #
               act = panel.dopanel()
               #
               wid =  panel.userredraw ()
               if wid :
                       winset (wid)
                       reshapeviewport()
               #
               # increment iter
               #
               if int (q.freeze.val) = 0 :
                       iter = iter +  1
                       fps = fps + 1
                       if time.time() - time0 >= 1 :
                               f = float(fps)/float(time.time()-time0)
                               q.mystrip.val = f
                               q.mystrip.fixact ()
                               q.fixpanel()
                               time0 = time.time()
                               fps = 0
               #
               # clear the zbuffer and make the background light blue
               #
               zclear()
               c3i (LightBlue)
               clear()
               #
               # for each object in the objects dictionary
               #
               for key in objects.keys() :
                       #
                       # if the object should be displayed
                       #
                       if getDict (objects, key, 0) = ONE :
                               loo = getDict (objects, key, 1)
                               for o in loo :
                                       #
                                       # get attributes and materail
                                       #
                                       attr = o [1]
                                       mat  = o [2]
                                       #
                                       #  display the object
                                       #
                                       drawit(od[o[0]],iter,attr,mat)
               #
               swapbuffers()
               #

main()
