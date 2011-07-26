from itertools import permutations

n = 8
cols = range(n)

for vec in permutations(cols):
    v2 = []
    v3 = []
    for i in cols:
        v2.append(vec[i]+i)
        v3.append(vec[i]-i)
    lenv2 = len(set(v2))
    lenv3 = len(set(v3))
    if (n == lenv2 == lenv3):
        print vec
