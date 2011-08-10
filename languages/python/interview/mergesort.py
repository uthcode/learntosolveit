import random
import math

def merge(left,right):
    result = []
    while left and right:
        if left[0] < right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
    if left:
        result.extend(left)
    else:
        result.extend(right)
    return result

def mergesort(m):
    left = []
    right = []
    result = []

    if len(m) <=1:
        return m
    middle = len(m)/2

    left = m[:middle]
    right = m[middle:]

    left = mergesort(left)
    right = mergesort(right)

    if left[-1] > right[0]:
        result = merge(left, right)
    else:
        result = left + right
    return result

p = random.sample(range(10),8)
print p
print mergesort(p)
