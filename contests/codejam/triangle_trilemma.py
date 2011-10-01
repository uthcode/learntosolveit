tc = int(raw_input())
for etc in range(tc):
    x1,y1,x2,y2,x3,y3 = map(int,raw_input().split())
    # Check if slopes are equal
    print 'Case #%d: ' % (etc+1),
    if ((x2-x1)*(y3-y1) == (x3-x1)*(y2-y1)):
        print 'not a triangle'
        continue
    iso=False
    right=False
    obtuse=False
    for i in range(3):
        l1 = pow((x2-x1),2) + pow((y2-y1),2)
        l2 = pow((x3-x2),2) + pow((y3-y2),2)
        l3 = pow((x1-x3),2) + pow((y1-y3),2)

        if (l3 > (l1+l2)):
            obtuse = True
        if (l3 == (l1+l2)):
            right = True
        if (l1 == l2):
            iso = True
        x1,y1,x2,y2,x3,y3 = x2,y2,x3,y3,x1,y1

    if iso:
        print 'isosceles ',
    else:
        print 'scalene ',
    if right:
        print 'right triangle'
    elif obtuse:
        print 'obtuse triangle'
    else:
        print 'acute triangle'
