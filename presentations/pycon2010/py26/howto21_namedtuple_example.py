#!/usr/bin/env python2.6

from collections import namedtuple
Point = namedtuple('Point', 'x y', verbose=True)
pp = Point(10,20)
print pp.x, pp.y
