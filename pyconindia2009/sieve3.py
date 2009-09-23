
def eratosthenes():
    '''Yields the sequence of prime numbers via the Sieve of Eratosthenes.'''
    D = {}
    q = 2
    while True:
        if q not in D:
            yield q
            D[q*q] = [q]
        else:
            for p in D[q]:
                D.setdefault(p+q, []).append(p)
            del D[q]

        q += 1


for num in eratosthenes():
    if num > 100:
        break
    print num
