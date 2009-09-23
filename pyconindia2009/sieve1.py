import math

def isprime(num):
    for x in range(2, int(math.sqrt(num))):
        if num % x == 0:
            return False
    return True

def sieve(n):
    list_of_ints = [x for x in range(2,n+1)]
    for num in list_of_ints:
        if not isprime(num):
            list_of_ints.remove(num)

    return list_of_ints
