"""
This is a simple program which prints first 100 primes.
Guido had used this example in 1993 paper while explaining python language.
"""
primes = [2]
print 2
i = 3
print i
while len(primes) < 100:
    for p in primes:
        if (i % p == 0) or (p*p > i):
            break

    if i%p != 0:
        primes.append(i)
        print i
    i = i + 2    # Why is it 2 instead of 1.
