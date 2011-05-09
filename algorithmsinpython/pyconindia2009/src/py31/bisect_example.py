"""
The bisect module implements an algorithm for inserting elements into a list in
sorted order. This can be much more efficient than repeatedly sorting a list or
explicitly sorting a large list after it is constructed.
"""

import bisect

from getlist import random_list

def bisection_verbose(A):
    resultant = []

    for element in A:
        position = bisect.bisect(resultant, element)
        bisect.insort(resultant, element)
        print(element, position, resultant)

    return resultant

if __name__ == '__main__':
    list_to_sort = random_list(10)
    print(list_to_sort)
    sorted_list = bisection_verbose(list_to_sort)
    print(sorted_list)
