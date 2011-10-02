def reducelist(elem):
    nitems = len(elem)
    if nitems > sum(elem):
        return -1 # IMPOSSIBLE
    empty_list = [0 for i in range(nitems)]
    elem.sort()
    #elem.reverse()
    count = 0
    while (sum(empty_list) != nitems):
        each = elem.pop()
        count += 1
        for i in range(0,len(empty_list)):
            if each == 0:
                break
            elif empty_list[i] == 1:
                pass
            else:
                empty_list[i] = 1
                each -= 1
    return count

C  = int(raw_input())
impossible = 0
for tc in range(C):
    N, T = [int(x) for x in raw_input().split()]
    E = int(raw_input())
    res = [0 for i in range(N)]
    for e in range(E):
        H, P = [int(x) for x in raw_input().split()]
        if H == T:
            res[H-1] = 0
        else:
            if res[H-1] == 0:
                res[H-1] = [P]
            else:
                res[H-1].append(P)
    resstr = ''
    for element in res:
        if type(element) == type([]):
            element = reducelist(element)
        if element == -1:
            resstr = 'IMPOSSIBLE'
            break
        else:
            resstr = resstr + ' ' + str(element)
    print 'Case #%d: %s' % (tc+1, resstr)
