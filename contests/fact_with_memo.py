memo ={}

def fact(n):
    if n in memo:
        return memo[n]
    elif n == 0:
        return 1
    else:
        x = fact(n-1) * n
        memo[n] = x
        return x

a = fact(10)
b = fact(20)

print a,b
