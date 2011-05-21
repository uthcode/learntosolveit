"""
The simulation has to be close to the word. I got the large one wrong because I
tried to use a dict for the opposed list. But using a list was the correct way
to go.
"""

N = int(raw_input())
for tc in range(1, N+1):
    items = raw_input().split()
    dict1 = {}
    list1 = []
    while items:
        C = items.pop(0)
        for i in range(int(C)):
            bn = items.pop(0)
            dict1[''.join(sorted(bn[:2]))] = bn[2]
        D = items.pop(0)
        for i in range(int(D)):
            bo = items.pop(0)
            list1.append(bo)
            list1.append(bo[::-1])
        N = items.pop(0)
        S = items.pop(0)
    stack = []
    for s in S:
        if stack:
            top = stack[-1]
            check = ''.join(sorted(top+s))
            if check in dict1:
                stack[-1] = dict1[check]
                continue
            # check for emptying the list
            wipe = False
            for e in stack:
                if e + s  in list1:
                    wipe = True

            if wipe:
                stack = []
                continue
            else:
                stack.append(s)
        else:
            stack.append(s)
    output = str(stack)
    output = output.replace("'","")
    output = output.replace('"','')
    print 'Case #%d: %s' % (tc, output)
