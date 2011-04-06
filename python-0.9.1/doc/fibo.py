# Fibonacci numbers demo

def fib(n):    # write Fibonacci series up to n
    a, b = 0, 1
    while b <= n:
          print b,
          a, b = b, a+b

def fib2(n): # return Fibonacci series up to n
    ret = []
    a, b = 0, 1
    while b <= n:
          ret.append(b)
          a, b = b, a+b
    return ret
