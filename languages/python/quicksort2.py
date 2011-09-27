import random
def quicksort(m):
    l = []
    r = []
    if len(m) <= 1:
        return m
    p = random.choice(m)
    m.remove(p)
    for e in m:
        if e <= p:
            l.append(e)
        else:
            r.append(e)
    l = quicksort(l)
    r = quicksort(r)
    return l + [p] + r

l = random.sample(range(10),8)
print l
print quicksort(l)
