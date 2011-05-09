import itertools
import math
import time

addition = {
    ('0','0'):'0',
    ('0','1'):'1',
    ('1','0'):'1',
    ('1','1'):'0'
}

def add(x, y):
    x = str(bin(x))[2:]
    y = str(bin(y))[2:]
    l = max(len(x),len(y))
    x = x.zfill(l)
    y = y.zfill(l)
    s = ''
    for x1,y1 in zip(x,y):
        s += addition[(x1,y1)]
    result = int(s,2)
    return result

T = int(raw_input())
for tc in range(1, T+1):
    largest = -1
    __n = raw_input()
    N = map(int,raw_input().split())
    N = sorted(N)
    #l = 1
    #u = int(math.floor(len(N)/2))
    for g in range(1,len(N)):
        group1 = N[:g]
        group2 = N[g:]
        if reduce(lambda x,y:add(x,y),group1) == reduce(lambda x,y:add(x,y),group2):
            possible_largest = max(sum(group1),sum(group2))
            if possible_largest > largest:
                largest = possible_largest
    if largest == -1:
        print 'Case #%d: NO' % tc
    else:
        print 'Case #%d: %d' % (tc, largest)

