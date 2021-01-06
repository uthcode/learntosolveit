"""
Book: The Essentials of Computer Architecture.
Chapter: 4
Problem: Write a Computer Program that measures the difference in execution
times between the integer division and floating point division. Execute the operation
100,000 times and compare the difference in the running time. 

Interesting Observation:
    * Integer Division is taking more time.

"""

import timeit
num1 = pow(2,64)
num2 = num1 * 2
stmt = "%d/%d" % (num2,num1)
print('Test:', stmt)
t1 = timeit.Timer(stmt)
m1 = (100000 * t1.timeit(100000) / 100000)
print('Integer Division takes: %f usecs/loop' % m1)

num2 = num1 * 2.0
stmt = "%f/%f" % (num2, num1)
print('Test:', stmt)
t2 = timeit.Timer(stmt)
m2 = (100000 * t2.timeit(100000) / 100000)
print('Floating point Division takes: %f usecs/loop' % m2)
print('The difference is %s usecs' % (m2-m1))
