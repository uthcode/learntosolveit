intersections = {}

def checkintersections(point, coords):
    x1, y1 = point
    newlist = coords[:]
    newlist.remove(point)
    for each in newlist:
        x2,y2 = each
        slope = (y2-y1)/(x2-x1)
        if slope < 0:
            if (x2,y2) in intersections:
                if (x1,y1) in intersections[(x2,y2)]:
                    continue
            if (x1,y1) in intersections:
                intersections[(x1,y1)].append((x2,y2))
            else:
                intersections[(x1,y1)] = [(x2,y2)]
T = input()
for tc in range(T):
    intersections = {}
    print 'Case #%d:' % (tc+1),
    N = input()
    coords  = []
    for i in range(N):
        x,y = map(int, raw_input().split())
        coords.append((x,y))
    for point in coords:
        checkintersections(point, coords)
    number = 0
    for values in intersections.values():
        number += len(values)

    print number
