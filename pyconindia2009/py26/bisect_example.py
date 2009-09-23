"""
The bisect module implements an algorithm for inserting elements into a list in
sorted order. This can be much more efficient than repeatedly sorting a list or
explicitly sorting a large list after it is constructed.
"""

import random
import bisect

def generate_list(n):
    return random.sample(xrange(1000000), n)

def bisection(A):
    resultant = []
    for elem in A:
        pos = bisect.bisect(resultant, elem)
        bisect.bisect(resultant, elem)
    return resultant

def bisection_method_verbose(A):
    resultant = []

    for element in A:
        position = bisect.bisect(resultant, element)
        bisect.insort(resultant, element)
        print element, position, resultant

    return resultant

if __name__ == '__main__':
    list_to_sort = generate_list(10)
    print list_to_sort
    sorted_list = bisection_method_verbose(list_to_sort)
    print sorted_list
