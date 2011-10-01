from helper import *

# Directions

NORTH, EAST, SOUTH, WEST = range(4)
BITS = [1, 8, 2, 4]
DELTAY = [-1, 0, 1, 0]
DELTAX = [0, 1, 0, -1]
CODE = "0123456789abcdefg"

def parse_case(file):
    return parse_string(file).split()

def solve(case, file):

    # Helpers for direction
    def to_right(direction):
        return (direction + 1) % 4
    def to_left(direction):
        return (direction + 3) % 4
    def turn_around(direction):
        return to_right(to_right(direction))

    # Process and individual step
    def do_step(step, direction, posx, posy):
        if step == 'W':
            return (
                posx + DELTAX[direction],
                posy + DELTAY[direction],
                direction
            )
        elif step == 'L':
            return (posx, posy, to_left(direction))
        elif step == 'R':
            return (posx, posy, to_right(direction))

    # See if size has to be modified
    def adapt_dimensions(posx, posy, dimension):
        minx, miny, maxx, maxy = dimension
        return (
            min(minx, posx),
            min(miny, posy),
            max(maxx, posx),
            max(maxy, posy)
        )

    # Display a maze in coded form
    def display_maze(cells, dimension):
        minx, miny, maxx, maxy = dimension
        for y in xrange(miny, maxy + 1):
            print ''.join(CODE[cells[x,y]] for x in xrange(minx, maxx + 1))

    # Entry is always on the north wall
    direction = SOUTH
    posx, posy = 0, 0
    # Save cells in a hash map - don't know size at start
    cells = {}
    dimension = (sys.maxint, sys.maxint, -sys.maxint - 1, -sys.maxint - 1)
    # Read case
    for path in parse_case(file):
        # Walk each step
        for nr, step in enumerate(path):
            # Adapt dimensions, but ignore cases where we are outside the maze
            if nr > 0 and nr < len(path):
                dimension = adapt_dimensions(posx, posy, dimension)
            # Increase room
            if (posx, posy) not in cells:
                cells[posx, posy] = 0
            # Update walls
            if step == 'W':
                cells[posx, posy] += BITS[direction]
            # Walk
            posx, posy, direction = do_step(step, direction, posx, posy)
        # Turn around
        direction = turn_around(direction)
    # Output solution
    print 'Case #%s:' % case
    display_maze(cells, dimension)

def main():
    file = open_input()
    cases = int(file.readline())
    for case in xrange(1, cases+1):
        solve(case, file)

if __name__ == '__main__':
    main()
