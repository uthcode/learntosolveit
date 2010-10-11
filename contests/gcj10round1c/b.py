import numpy as np
import sys, os
import math

rl = sys.stdin.readline

T = int(rl())
#T = 29

#===============================================================================
# print T
# for t in xrange(T):
#  L, P, C = map(int, rl().split())
#  print 'L:', L, 'P:', P, 'C:', C
#  tests = 0
#  while P > L * C:
#    tests += 1 
#    tp = math.log(1.0* P / L) / math.log(C) / 2
#    L = C ** tp
#    print 'L:', L, 'P:', P
#    print 'tp', tp
#    
#==============================================================================


for t in xrange(T):
  L, P, C = map(int, rl().split())
#  print 'L:', L, 'P:', P, 'C:', C
  tp = math.log(1.0 * P / L) / math.log(C)
  #print 'tp', tp
  if L * C >= P:
    tests = 0
    
  #if tp < 1:
  else:
    tests = math.ceil(math.log(tp) / math.log(2))

#  print 'L:', L, 'P:', P
    
     
  print 'Case #%i: %i' % (t+1, tests)
  