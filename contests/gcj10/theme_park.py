def calculateend(groups, start, k):
    total = 0
    count = 0
    countover = False
    grouplen = len(groups)
    i = start
    while total <= k:
        total += groups[i]
        i += 1
        count += 1
        if i == grouplen:
            i = 0 # loop over.
        if count == grouplen:
            countover = True
            break
    if countover and total <= k:
        return i, total
    else:
        if i:
            i = i -1
        else:
            i = grouplen - 1
        extra = groups[i]
        total = total - extra
        return i, total

T = input()
for tc in range(T):
    print 'Case #%d:' % (tc+1),
    R, k, N = map(int, raw_input().split())
    groups = map(int, raw_input().split())
    travelpattern = {}
    for i in range(N):
        end, cost = calculateend(groups, i, k)
        travelpattern[i] =  (end, cost)
    total = 0
    start = 0
    pattern = {}
    for i in range(N+1):
        end, cost = travelpattern[start]
        start = end
        total += cost
        if cost not in pattern:
            pattern[cost] = 1
        else:
            pattern[cost] += 1
    print pattern
