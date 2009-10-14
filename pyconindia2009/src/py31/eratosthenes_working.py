def eratosthenes():
    '''Yields the sequence of prime numbers via the Sieve of Eratosthenes.'''
    D = {}
    q = 2
    while True:
        p = D.pop(q, None)
        if p:
            print('if loop:',p)
            x = p + q
            print(x)
            while x in D:
                x += p
                print(x)
            D[x] = p
            print(D)
        else:
            print('else loop:',q)
            print(D)
            D[q*q] = q
            print('after assinging')
            print(D)
            yield q
        q += 1

if __name__ == '__main__':
    for num in eratosthenes():
        if num > 100: break
        print('yielded:',num)
