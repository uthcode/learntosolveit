n, R, r = map(int, raw_input().split())

print 2 * 3.14 * R
print n * 2 * 3.14 * r
if (2 * 3.14 * R) >= ( n * 2 * 3.14 * r):
    print "YES"
else:
    print "NO"
