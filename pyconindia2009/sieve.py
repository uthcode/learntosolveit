
def sieve(n):
    list_of_ints = [x for x in range(1,n+1)]
    for i in range(1,n+1):
        for j in range(1,n+1):
            comp = i + j + (2*i*j)
            if comp <= n:
                if x in list_of_ints:
                    list_of_ints.remove(comp)

    return list_of_ints

output = sieve(100)
for v in output:
    print v
