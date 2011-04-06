# Data used by fancy nurbs demo.

TRUE = 1
FALSE = 0

RED = 0xff
YELLOW = 0xffff

#
# nurb order
#
ORDER = 4

#
# identity matrix
#
idmat = [1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1]

#
# s and t knots
#
surfknots = [-1, -1, -1, -1, 1, 1, 1, 1]

#
# list of list of control points
#
def make_ctlpoints():
       c = []
       #
       ci = []
       ci.append(-2.5,  -3.7,  1.0)
       ci.append(-1.5,  -3.7,  3.0)
       ci.append(1.5,  -3.7, -2.5)
       ci.append(2.5,  -3.7,  -0.75)
       c.append(ci)
       #
       ci = []
       ci.append(-2.5,  -2.0,  3.0)
       ci.append(-1.5,  -2.0,  4.0)
       ci.append(1.5,  -2.0,  -3.0)
       ci.append(2.5,  -2.0,  0.0)
       c.append(ci)
       #
       ci = []
       ci.append(-2.5, 2.0,  1.0)
       ci.append(-1.5, 2.0,  0.0)
       ci.append(1.5,  2.0,  -1.0)
       ci.append(2.5,  2.0,  2.0)
       c.append(ci)
       #
       ci = []
       ci.append(-2.5,  2.7,  1.25)
       ci.append(-1.5,  2.7,  0.1)
       ci.append(1.5,  2.7,  -0.6)
       ci.append(2.5,  2.7,  0.2)
       c.append(ci)
       #
       return c

ctlpoints = make_ctlpoints ()

#
# trim knots
#
trimknots = [0., 0., 0.,  1., 1.,  2., 2.,  3., 3.,   4., 4., 4.]

def make_trimpoints():
       c = []
       #
       c.append(1.0, 0.0, 1.0)
       c.append(1.0, 1.0, 1.0)
       c.append(0.0, 2.0, 2.0)
       c.append(-1.0, 1.0, 1.0)
       c.append(-1.0, 0.0, 1.0)
       c.append(-1.0, -1.0, 1.0)
       c.append(0.0, -2.0, 2.0)
       c.append(1.0, -1.0, 1.0)
       c.append(1.0, 0.0, 1.0)
       #
       return c

trimpoints = make_trimpoints()
