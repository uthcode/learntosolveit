import string
T = int(raw_input())
results = {}
for testcase in range(T):
    region = {}
    flow = {}
    H, W = map(int, raw_input().split())
    for i in range(H):
        row = map(int, raw_input().split())
        for j,c in enumerate(row):
            region[(i,j)] = c
    for key in region:
        smallest = region[key]
        flowcell = key
        x,y=key
        validdirs = [(x-1,y), (x,y-1), (x,y+1), (x+1,y)]
        for each in validdirs:
            if each in region:
                value = region[each]
                if value < smallest:
                    smallest = value
                    flowcell = each
        flow[key] = flowcell
    res = {}
    for k in flow:
        node = k
        stack = []
        while not (node in stack):
            stack.append(node)
            node = flow[node]
        else:
            if node in res:
                for k in stack:
                    if not k in res[node]:
                        res[node].append(k)
            else:
                res[node] = []
                for k in stack:
                    if not k in res[node]:
                        res[node].append(k)
    #print res
    for k,v in res.items():
        res[k] = sorted(v)
    #resvals = res.values()
    #each = resvals
    sortedres = sorted(res.values())
    #print sortedres
    result = {}
    for item,c in zip(sortedres, string.lowercase):
        for each in item:
            result[each] = c

    results[testcase] = (H,W,result)

for i in range(T):
    print 'Case #%d:' % (i+1)
    H = results[i][0]
    W = results[i][1]
    result = results[i][2]
    for i in range(H):
        for j in range(W):
            print result[(i,j)],
        print
