# Factorize numbers -- slow, could use a table of all primes <= 2*16

import sys
import math

error = 'fact.error'           # exception

def fact(n):
       if n < 1: raise error        # fact() argument should be >= 1
       if n = 1: return []     # special case
       res = []
       _fact(n, 2, res)
       return res

def _fact(n, lowest, res):
       highest = int(math.sqrt(float(n+1)))
       for i in range(lowest, highest+1):
               if n%i = 0:
                       res.append(i)
                       _fact(n/i, i, res)
                       break
       else:
               res.append(n)

def main():
       if len(sys.argv) > 1:
               for arg in sys.argv[1:]:
                       n = eval(arg)
                       print n, fact(n)
       else:
               try:
                       while 1:
                               print fact(input())
               except EOFError:
                       pass

main()
