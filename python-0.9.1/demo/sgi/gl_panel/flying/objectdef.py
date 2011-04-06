from math import *
from objdict import *
from gl import *

FUZZY = 0.00001

# first try - brute force method (ala M.Overmars...)

def makespinobject (smooth,rot,n,x1,z1,nx1,nz1,x2,z2,nx2,nz2) :
       object = []
       dth = 2.0 * pi / float (rot)
       for i in range (0, n) :
               for j in range (0, rot) :
                       th = dth * float (j)
                       #
                       if smooth = 1:
                               a1 = th
                               a2 =th+dth
                       else :
                               a1 = th + dth / 2.0
                               a2 = th + dth / 2.0
                       #
                       v0 = (x1[i]*sin(th),x1[i]*cos(th),z1[i])
                       n0 = (nx1[i]*sin(a1),nx1[i]*cos(a1),nz1[i])
                       #
                       v1 = (x1[i]*sin(th+dth),x1[i]*cos(th+dth),z1[i])
                       n1 = (nx1[i]*sin(a2), nx1[i]*cos(a2), nz1[i])
                       #
                       v2 = (x2[i]*sin(th+dth),x2[i]*cos(th+dth),z2[i])
                       n2 = (nx2[i]*sin(a2), nx2[i]*cos(a2), nz2[i])
                       #
                       v3 = (x2[i]*sin(th), x2[i]*cos(th), z2[i])
                       n3 = (nx2[i]*sin(a1), nx2[i]*cos(a1), nz2[i])
                       #
                       patch = ((v0,n0), (v1,n1), (v2,n2), (v3,n3))
                       #patch = ((n0,v0), (n1,v1), (n2,v2), (n3,v3))
                       #
                       if x1[i] < FUZZY :
                               patch = patch[1:]
                       #
                       object.append (patch)
       #
       return object

def makesphere (n):
       asin = []
       acos = []
       for i in range (0, n-1):
               asin.append (sin((pi/float (n))*(1.0+float (i))))
               acos.append(cos((pi/float (n))*(1.0+float (i))))
       #
       x1 = [0.0] + asin
       z1 = [1.0] + acos
       nx1 = [0.0] + asin
       nz1 = [1.0] + acos
       #
       x2 = asin + [0.0]
       z2 = acos + [-1.0]
       nx2 = asin + [0.0]
       nz2 = acos + [-1.0]
       #
       return makespinobject (1,2*n,n,x1,z1,nx1,nz1,x2,z2,nx2,nz2)

def makecylinder(n) :
       x1 =  [0.0, 1.0, 1.0]
       nx1 = [0.0, 1.0, 0.0]
       z1 =  [1.0, 1.0, -1.0]
       nz1 =  [1.0, 0.0, -1.0]
       #
       z2 =  [1.0, -1.0, -1.0]
       nz2 =  [1.0, 0.0, -1.0]
       x2 =  [1.0, 1.0, 0.0]
       nx2 = [0.0, 1.0, 0.0]
       #
       return makespinobject(1,2*n,3,x1,z1,nx1,nz1,x2,z2,nx2,nz2)

def makecone(n) :
       x1 =  [0.0, 1.0, 1.0]
       nx1 = [2.0/sqrt(5.0), 0.0, 0.0]
       z1 =  [1.0, -1.0, -1.0]
       nz1 = [1.0/sqrt(5.0), -1.0, -1.0]
       #
       x2 =  [1.0, 0.0, 0.0]
       nx2 = [2.0/sqrt(5.0), 0.0, 0.0]
       nz2 = [1.0/sqrt(5.0), -1.0, -1.0]
       z2 = [-1.0, -1.0, -1.0]
       #
       return makespinobject(1,2*n,2,x1,z1,nx1,nz1,x2,z2,nx2,nz2)

def makecube() :
       x1 =  [0.0, sqrt(2.0), sqrt (2.0)]
       nx1 = [0.0, 1.0, 0.0]
       z1 =  [1.0, 1.0, -1.0]
       nz1 = [1.0, 0.0, -1.0]
       #
       x2 =  [sqrt(2.0), sqrt(2.0), 0.0]
       nx2 = [0.0, 1.0, 0.0]
       z2 =  [1.0, -1.0, -1.0]
       nz2 = [1.0, 0.0, -1.0]
       #
       return makespinobject(0,4,3,x1,z1,nx1,nz1,x2,z2,nx2,nz2)


def makepyramid() :
       x1 =  [0.0, sqrt(2.0), 0.0]
       nx1 = [2.0 / sqrt(5.0), 0.0, 0.0]
       z1 =  [1.0, -1.0, 0.0]
       nz1 = [1.0 / sqrt(5.0), -1.0, 0.0]
       #
       x2 =  [sqrt(2.0), 0.0, 0.0]
       nx2 = [2.0 / sqrt(5.0), 0.0, 0.0]
       z2 =  [-1.0, -1.0, -1.0]
       nz2 = [1.0/sqrt(5.0), -1.0, 0.0]
       #
       return makespinobject(0,4,3,x1,z1,nx1,nz1,x2,z2,nx2,nz2)

def makeobjects () :
       cube = makecube()
       sphere = makesphere (6)
       cylinder = makecylinder (6)
       cone = makecone (6)
       pyramid = makepyramid ()
       #
       odict = {}
       odict ['cube'] = cube
       odict ['pyramid'] = pyramid
       odict ['sphere'] = sphere
       odict ['cylinder'] = cylinder
       odict ['cone'] = cone
       odict ['diamond'] = cube
       odict ['disk'] = sphere
       #
       return odict


renderfuncs = [bgnpolygon, endpolygon]

def putFunc (funcs) :
       renderfuncs [:] = funcs

def drawobject (obj) :
       #
       for patch in obj :
               renderfuncs[0] ()
               vnarray (patch)
               renderfuncs[1] ()

