n, R, r = map(int, raw_input().split())
area_of_big = R * R
area_of_small = r * r
if (n !=1 and n * area_of_small >= area_of_big):
    print "NO"
else:
    half_n = n/2
    if ((half_n * 2 * r) > (2*R)):
        print "NO"
    else:
        print "YES"

