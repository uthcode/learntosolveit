"""
$ python list_sort_timeit.py 
Using sort method: 20.0662879944
Using sorted builin method: 259.009809017
"""

import random
import timeit
import gc

print 'Using sort method:',
x = min(timeit.Timer("test_list1.sort()","gc.enable();import random;test_list1=random.sample(xrange(1000),1000)").repeat())
print x

print 'Using sorted builin method:',
x =  min(timeit.Timer("sorted(test_list2)","gc.enable();import random;test_list2=random.sample(xrange(1000),1000)").repeat())
print x


