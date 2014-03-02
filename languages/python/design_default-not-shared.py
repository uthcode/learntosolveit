def f(a, L=None):
    if L is None:
        L = []
    L.append(a)
    return L

import pdb
pdb.set_trace()
print f(10)
print f(20)
print f(30)
