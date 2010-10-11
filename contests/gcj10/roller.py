from collections import deque
T = int(input())
for t in xrange(T):
    R, k, N = map(int, raw_input().split())
    g = map(int, raw_input().split())
    d = deque(g)
    cost = 0
    for i in xrange(R):
        total = 0
        index = 0
        breakit = 0
        total = sum(d)
        if total <= k:
            cost += total
            continue
        total = 0
        for elements in d:
            index += 1
            total += elements
            if total > k:
                breakit = 1
                break
        if breakit: total -= elements
        d.rotate(-1 * (index-1))
        cost += total
    print 'Case #%d: %d' % (t+1, cost)
