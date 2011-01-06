import itertools
N = int(raw_input())
i = 1
for tc in range(N):
    C = int(raw_input())
    l = int(raw_input())
    items = list(int(e) for e in raw_input().split())
    for answer in itertools.combinations(items,2):
        if sum(answer) == C:
            e1 = items.index(answer[0])
            e2 = items.index(answer[1],e1+1)
            print 'Case #%d: %d %d' %(i, e1+1, e2+1)
    i += 1
