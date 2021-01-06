memo = {}

def fact(n):
    if n in memo:
        return memo[n]
    if n == 0:
        return 1
    else:
        ans = n * fact(n-1)
        memo[n] = ans
        return ans

t = int(input())
for i in range(t):
    n = int(input())
    print(fact(n))
