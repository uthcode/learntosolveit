N = int(raw_input())
for tc in range(1, N+1):
    items = raw_input().split()
    dict1 = {}
    dict2 = {}
    while items:
        C = items.pop(0)
        for i in range(int(C)):
            bn = items.pop(0)
            dict1[''.join(sorted(bn[:2]))] = bn[2]
        D = items.pop(0)
        for i in range(int(D)):
            bo = items.pop(0)
            dict2[bo[0]] = bo[1]
            dict2[bo[1]] = bo[0]
        N = items.pop(0)
        S = items.pop(0)
    stack = []
    for s in S:
        if stack:
            top = stack[-1]
            check = ''.join(sorted(top+s))
            if check in dict1:
                stack[-1] = dict1[check]
            elif s in dict2 and (dict2[s] in stack):
                stack = []
            else:
                stack.append(s)
        else:
            stack.append(s)
    output = str(stack)
    output = output.replace("'","")
    output = output.replace('"','')
    print 'Case #%d: %s' % (tc, output)
