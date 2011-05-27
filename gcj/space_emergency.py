T = int(raw_input())
for tc in range(1,T+1):
    _input = raw_input().split()
    L = int(_input.pop(0))
    t = int(_input.pop(0))
    N = int(_input.pop(0))
    C = int(_input.pop(0))
    stardistance =  _input * (N/len(_input))
    if len(stardistance) < N:
        stardistance += _input
    stardistance = stardistance[:N]
    print stardistance
