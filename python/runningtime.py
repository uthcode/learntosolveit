"""
Book: The Essentials of Computer Architecture.
Chapter: 4
Problem: Write a Computer Program that measures the difference in execution
times between the integer addition and integer division. Execute the operation
100,000 times and compare the difference in the running time. 
"""
import timeit
t1 = timeit.Timer("4+2")
m1 = (100000 * t1.timeit(100000) / 100000)
print 'Integer Addition takes: %f usecs/loop' % m1
t2 = timeit.Timer("4/2")
m2 = (100000 * t2.timeit(100000) / 100000)
print 'Integer Division takes: %f usecs/loop' % m2
print 'The difference is %s usecs' % (m2-m1)
