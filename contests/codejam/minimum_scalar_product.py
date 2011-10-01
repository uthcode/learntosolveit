"""
Problem Statement:
    http://code.google.com/codejam/contest/dashboard?c=32016#s=p0

This becomes easy in python by chosing the correct logic and proper operators.

"""

T = int(raw_input())
for tc in range(1,T+1):
    n = raw_input() # we don't need this in python.
    x = sorted(map(int,raw_input().split()))
    y = sorted(map(int,raw_input().split()),reverse=True)
    print 'Case #%d: %d' % (tc, sum(map(lambda a,b:a*b,x,y)))
