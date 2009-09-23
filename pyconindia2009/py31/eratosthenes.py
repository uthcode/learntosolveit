def eratosthenes():
    '''Yields the sequence of prime numbers via the Sieve of Eratosthenes.'''
    D = {}
    q = 2
    while True:
        p = D.pop(q, None)
        if p:
            x = p + q
            while x in D:
                x += p
            D[x] = p
        else:
            D[q*q] = q
            yield q
        q += 1
