"""
Problem Statment: http://code.google.com/codejam/contest/dashboard?c=32003#s=p1
Very Interesting problem. Required a good amount of thinking in order to solve
it.
"""
# directions  - visualize it.
import sys

NORTH,EAST,SOUTH,WEST = range(4)
BITS = [1,8,2,4]
DELTA_Y = [-1, 0, 1, 0]
DELTA_X = [0, 1, 0, -1]
CODE = '0123456789abcdef'  # convenience for direct indexing


def update_dimensions(posx, posy, dimensions):
    minx,miny,maxx,maxy = dimensions
    minx = min(posx, minx)
    miny = min(posy, miny)
    maxx = max(posx, maxx)
    maxy = max(posy, maxy)
    return (minx,miny,maxx,maxy)

def turn_left(direction):
    return (direction + 3) % 4

def turn_right(direction):
    return (direction + 1) % 4

def turn_around(direction):
    return turn_right(turn_right(direction))

def do_step(step, posx, posy, direction):
    if step == 'W':
        direction = direction
        posx = posx + DELTA_X[direction]
        posy = posy + DELTA_Y[direction]
    if step == 'L':
        direction = turn_left(direction)
        posx = posx
        posy = posy
    if step == 'R':
        direction = turn_right(direction)
        posx = posx
        posy = posy
    return posx, posy, direction

N = int(raw_input())
for tc in range(1,N+1):
    bothmovement = raw_input().split()
    # intial direction of movement
    direction = SOUTH
    posx, posy = 0,0
    cells = {}
    dimensions = (sys.maxint,sys.maxint,-sys.maxint-1,-sys.maxint-1)
    for movement in bothmovement:
        for count, step in enumerate(movement):
            if count > 0 and count < len(movement):
                dimensions = update_dimensions(posx,posy,dimensions)
            if not (posx,posy) in cells:
                cells[(posx,posy)] = 0
            # construct the wall
            if step == 'W':
                cells[(posx,posy)] += BITS[direction]
            # do the step
            posx,posy,direction = do_step(step,posx,posy,direction)
        direction = turn_around(direction)

    minx,miny,maxx,maxy = dimensions
    print 'Case #%d:' % tc
    for y in range(miny,maxy+1):
        output = ''
        for x in range(minx, maxx+1):
            output += CODE[cells[(x,y)]]
        print output
