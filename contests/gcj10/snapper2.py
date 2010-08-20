def tobits(num):
    l = []
    while num:
        if num % 2 == 0:
            l.append(0)
        else:
            l.append(1)
        num /= 2
    l.reverse()
    return l

def lastn(l,n):
    if n > len(l):
        return []
    start = len(l) - n
    return l[start:]

T = int(input())
for t in range(T):
    n, k = map(int, raw_input().split())
    result = lastn(tobits(k),n)
    print 'Case #%d:' % (t+1),
    if 0 in result or not result:
        print 'OFF'
    else:
        print 'ON'
