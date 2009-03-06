from multiprocessing import Pool

def factorial(N, dictionary):
    "Compute a Factorial"

p = Pool(5)
result = p.map(factorial, range(1,1000,10))
for v in result:
    print v
