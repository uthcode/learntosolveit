import math
import pudb
pudb.set_trace()
def gorosort(n):
    if n == 2:
        return 2
    else:
        return math.factorial(n/2) + gorosort(n/2+1)

T = int(raw_input())
for tc in range(1, T+1):
    _n = raw_input()
    N = map(int, raw_input().split())
    sortedn = sorted(N)
    n = 0
    for x,y in zip(sortedn,N):
        if x == y:
            n+= 1
    tosort = len(N) - n
    if tosort > 2:
        print gorosort(tosort-1) + 2
    else:
        print gorosort(tosort)

