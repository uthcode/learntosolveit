def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a%b)
C = input()
for tc in range(C):
    numlist = map(int,raw_input().split()[1:])
    least = numlist[0]
    redlist = [abs(x - least) for x in numlist]
    gcdofall = reduce(gcd, redlist)
    print 'Case #%d:' % (tc+1),
    if least % gcdofall == 0:
        print 0
    else:
        print gcdofall - (least % gcdofall)
