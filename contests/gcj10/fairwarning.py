from fractions import gcd

C = int(input())
for i in xrange(C):
    events = map(int, raw_input().split())
    events = events[1:]
    events = sorted(events)
    least = events[0]
    seconds = 0
    highest = 0
    for s in xrange(least,-1L,-1):
        newevents = map(lambda m: m+s, events)
        nseconds = reduce(gcd,newevents)
        newevents = map(lambda m: m/nseconds, newevents)
        if nseconds >= seconds:
            highest = s
            seconds = nseconds
    print 'Case #%d: %d' % (i+1, highest)
