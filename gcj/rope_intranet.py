"""
Problem Statement: http://code.google.com/codejam/contest/dashboard?c=619102

This is one of the tricky problems. Leads us to think of it like equation of
lines and it is difficult to imagine properly along those lines.
The simple way to solve this is take each pair of A,B and test against the
other A,B and see if they lie in opposite direction. Mathematically it boils
down to checking Ai-Aj * Bi-Bj < 0 ( if they are in the same direction, it
would be postive, so this equation helps).
I had solved it somehow during the content, but when practising again, I had to
take help of the contest analysis and come up with this solution.

"""
T = int(raw_input())
for tc in range(1,T+1):
    endpoints = []
    N = int(raw_input())
    for n in range(N):
        A,B = map(int,raw_input().split())
        endpoints.append([A,B])
    intersect = 0
    for pair1 in endpoints:
        for pair2 in endpoints:
            if pair1 == pair2:
                continue
            else:
                Ai,Bi = pair1
                Aj,Bj = pair2
                if (Ai-Aj)*(Bi-Bj) < 0:
                    intersect += 1
    print 'Case #%d: %d' % (tc, intersect/2)
