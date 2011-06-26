"""
Problem: http://code.google.com/codejam/contest/dashboard?c=351101#s=p1

Solution: Given the high level datastructures in Python, this is extremely
simple. Make it an inclusive range.
"""
N = int(raw_input())
for tc in range(1,N+1):
    print 'Case #%d: %s' % (tc, ' '.join(raw_input().split()[::-1]))
