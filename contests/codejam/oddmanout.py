N = int(raw_input())
t = 1
for tc in range(N):
    C = int(raw_input())
    nums = [int(n) for n in raw_input().split()]
    pairs = []
    for each in nums:
        if each not in pairs:
            pairs.append(each)
        else:
            pairs.remove(each)
    print 'Case #%d: %d' % (t, pairs[0])
    t += 1
