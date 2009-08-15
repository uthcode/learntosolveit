"""
Book: The Essentials of Computer Architecture.
Chapter: 4
Problem: Write a Computer Program that measures the difference in execution
times between the integer addition and integer division. Execute the operation
100,000 times and compare the difference in the running time. 

Extend the Program to compare between 16 bit, 32 bit and 64 bit integer
addition.

Tip: Python 2.7 has bit_length() for int objects. 

Interesting Observation:
    For 16 bit ints, the operations take more time than 32 bit numbers.

"""
import timeit

for bits in [16,32,64]:
    num1 = pow(2,bits)

    # Integer Addition

    print 'Integer Addition between %d bit numbers' % (bits)
    num2 = num1 + 2
    stmt = "%d +%d" % (num2, num1)
    t = timeit.Timer(stmt)
    m = (100000 * t.timeit(100000) / 100000)
    print '%f usecs/loop' % (m)

    # Integer Division now.

    print 'Integer Division between %d bit numbers' % (bits)
    num2 = 2 * num1
    stmt = "%d/%d" % (num2, num1)
    t = timeit.Timer(stmt)
    m = (100000 * t.timeit(100000) / 100000)
    print '%f usecs/loop' % (m)
