"""
Problem:  http://code.google.com/codejam/contest/dashboard?c=351101#s=p0

The problem becomes simpler to handle by using itertools.combination.
Just have to take care of index position representation being correct for the
problem.

"""
import itertools

N = int(raw_input())
for testcases in range(N):
    C = int(raw_input())
    I = int(raw_input())
    list_i = map(int,raw_input().split())
    for comb in itertools.combinations(list_i,2):
        if sum(comb) == C:
            tc = testcases+1
            n = list_i.index(comb[0])+1
            m = list_i.index(comb[1],n)+1
            print 'Case #%d: %d %d' % (tc,n,m)
