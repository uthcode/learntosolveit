def fibo(n):
    f = [0,1]
    if n in f:
        return f[n]
    for i in range(2,n+1):
        f.append(f[i-1] + f[i-2])
    return f[n]

print fibo(37)
"""
print fibo(1)
print fibo(2)
print fibo(3)
print fibo(4)
print fibo(5)
print fibo(6)
print fibo(37)
"""
