"""
Make sure to read the contest analysis for this problem.
http://code.google.com/codejam/contest/dashboard?c=975485#s=p3&a=3
"""

import math

T = int(raw_input())
for tc in range(1, T+1):
    _n = raw_input()
    N = map(int, raw_input().split())
    # how many are not in it's correct position?
    sorted_n = sorted(N)
    hits = 0
    for required,actual in zip(sorted_n,N):
        if required != actual:
            hits += 1
    print 'Case #%d: %0.6f' % (tc, hits)
