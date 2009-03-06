def get_primes(p,n):
    primes = []
    for num in range(p,n+1):
        for divisor in range(2,num):
            if num % divisor == 0:
                break
        else:
            primes.append(num)
    return primes

def get_prime_factor(a,b):
    if a > b:
        get_prime_factor(b,a)
    else:
        primes = []
        for num in range(2,a):
            if a % num == 0 and b % num == 0:
                primes.append(num)
        return primes

C = input()
for tcs in range(C):
    A,B,P = (int(x) for x in raw_input().split())
    list_of_primes = get_primes(P,B)
    set = 0
    for i in range(A,B):
        for j in range(A+1,B+1):
            prime_factors = get_prime_factor(i,j)
            if prime_factors:
                for num in prime_factors:
                    if num in list_of_primes:
                        set = set + 1
    print 'Case #%d: %d' % (tcs+1,set)
