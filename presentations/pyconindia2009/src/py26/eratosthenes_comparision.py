import optparse

def eratosthenes_1():
    '''Yields the sequence of prime numbers via the Seive of Eratosthenes.'''
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


def eratosthenes_2():
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

def time_eratosthenes():
    from timeit import Timer
    t1 = Timer("eratosthenes_1()", "from __main__ import eratosthenes_1")
    print t1.timeit()
    t1 = Timer("eratosthenes_2()", "from __main__ import eratosthenes_2")
    print t1.timeit()

if __name__ == '__main__':
    parser = optparse.OptionParser()
    parser.add_option('-t','--timeit',action='store_true',dest='timeit',default=False)
    options, arguments = parser.parse_args()
    if options.timeit:
        time_eratosthenes()
    else:
        for num in eratosthenes_1():
            if num > 100: break
            print num,
        print 
        for num in eratosthenes_2():
            if num > 100: break
            print num,
