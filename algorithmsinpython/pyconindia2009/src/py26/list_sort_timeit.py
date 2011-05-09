"""
Example Output:
$ python list_sort_timeit.py 
Using sort method: 19.0166599751
Using sorted builin method: 23.203567028
"""

import random
import timeit

print 'Using sort method:',
x = min(timeit.Timer("test_list1.sort()","import random;test_list1=random.sample(xrange(1000),1000);test_list1.sort()").repeat())
print x

print 'Using sorted builin method:',
x =  min(timeit.Timer("sorted(test_list2)","import random;test_list2=random.sample(xrange(1000),1000);test_list2.sort()").repeat())
print x
