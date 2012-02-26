"""
Preference -
((Price(A) < Price(B)) and (Weight(A) <= Weight(B))) or ((Weight(A) < Weight(B)) and (Price(A) <= Price(B)))

Bargain -
[A,B1,B2,B3,B4] A > B1 > B2 > B3 > B4

Terrible -
[D1,D2,D3,D4,C] D1 > D2 > D3 > D4 > C

A == C # possible

You want how many Bargain and Terrible offered ( Can't understand)

As you said, Product A is better than Product B if whatever criteria you said
is met.

If they are not met, then there are some possibilities:

    - Pa > Pb and Wa > Wb. Product A is worse than Product B. It is not a bargain.
    - Pa > Pb and Wa < Wb or Pa < Pb and Wa > Wb. Neither Product A nor Product
    B are better than each other (A does not cost less than B AND have equal or
    lesser weight than B, vice versa). Both are bargains.
    - Pa <= Pb and Wa <= Wb. Product A is a bargain. If either Pa < Pb or Wa < Wb,
    then Product A is better than Product B. If Pa = Pb and Wa = Wb, then both
    Product A and B are bargains.

By the way, I determined this through experimentation, and my comparisons do
match up with the example input.

"""

T = int(raw_input())
#T = 1

def next_p(P, M, A, B):
    return ((A*P + B) % M) + 1

def next_w(W, K, C, D):
    return ((C*W + D) % K) + 1

def calculate_tb(N, P, W, M, K, A, B, C, D):
    ps = [P]
    ws = [W]
    for i in range(2,N+1):
        P = next_p(P,M,A,B)
        W = next_w(W,K,C,D)
        ps.append(P)
        ws.append(W)
    return ps, ws

for tc in range(T):
    N, P, W, M, K, A, B, C, D = map(int,raw_input().split())
    terrible, bargain = calculate_tb(N, P, W, M, K, A, B, C, D)
    print terrible, bargain
    result = []
    for i,j in zip(terrible, bargain):
        result.append([i,j])
    print result

