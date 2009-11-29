N = int(raw_input())
for each in range(N):
    print 'Case #%d:' % (each+1),
    P,K,L = map(int, raw_input().split())
    probs = map(int, raw_input().split())
    probs.sort(reverse=True)
    dict1 = dict()
    for k in range(K):
        dict1[k] = list()
    while probs:
        for key in dict1.keys():
            if len(dict1[key]) < P:
                if probs:
                    dict1[key].append(probs.pop(0))

    min = 0
    for key in dict1:
        for i,v in enumerate(dict1[key]):
            min += (i+1) * v
    print min
