import itertools

def getnext(N):
    answer = set()
    for each in itertools.permutations(N):
        answer.add(''.join(each))
    ans = []
    for each in answer:
        ans.append(int(each))
    ans.sort()
    if (ans.index(int(N)) == len(ans)-1):
        answer = set()
        for each in itertools.permutations(N+'0'):
            answer.add(''.join(each))
        nans = []
        for each in answer:
            nans.append(int(each))
        ans.extend(nans)
        cor_ans = set(ans)
        ans = []
        for each in cor_ans:
            ans.append(each)
        ans.sort()
        #return retval
    #else:
    return ans[ans.index(int(N))+1]

T = int(raw_input())
for X in range(T):
    print 'Case #%d: ' % (X+1),
    N = raw_input()
    answer = getnext(N)
    print answer


