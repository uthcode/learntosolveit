"""
The bisect module implements an algorithm for inserting elements into a list in
sorted order. This can be much more efficient than repeatedly sorting a list or
explicitly sorting a large list after it is constructed.
"""

import bisect

def bisectionsort(A):
    resultant = []
    for elem in A:
        pos = bisect.bisect(resultant, elem)
        bisect.bisect(resultant, elem)
    return resultant

