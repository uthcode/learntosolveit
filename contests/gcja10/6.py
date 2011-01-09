T = int(raw_input())
for tc in range(T):
    num = [int(x) for x in raw_input().split()]
    P = num.pop(0)
    C = num.pop(0)
    average = sum(num)/C
    while True:
        for i in range(len(num)):
            if num[i] > average:
                num[i] = average
        newaverage = sum(num)/C
        if newaverage == average:
            break
        average = newaverage
    print 'Case #%d: %d' % (tc+1, average)
