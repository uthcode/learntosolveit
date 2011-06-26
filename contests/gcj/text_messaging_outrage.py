"""
Problem: http://code.google.com/codejam/contest/dashboard?c=32015#

Description:
        When it is meant by the frequency of each letter, it is not the message
        itself which is given, instead it is simplied for "us to use". I was
        thinking if the probablity is of any use in the solution after we fin
        the optimal layout. But yes, it is used in the calculation.

        The idea is to simulate.
"""

N = int(raw_input())
for tc in range(1, N+1):
    P, K, L = map(int, raw_input().split())
    L = map(int,raw_input().split())
    L = sorted(L,reverse=True)
    # construct the keys and the probablities
    dict_of_keys = dict()
    for key in range(K):
        dict_of_keys[key] = list()

    while L:
        for key in dict_of_keys:
            if L and len(dict_of_keys[key]) < P:
                dict_of_keys[key].append(L.pop(0))

    minimum = 0
    for value in dict_of_keys.values():
        for k,v in enumerate(value):
            minimum += (k+1)*v
    print 'Case #%d: %d' % (tc, minimum)
