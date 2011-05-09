import math

def merge(left, right):
    result = list()
    while (len(left) > 0) and (len(right) > 0):
        if left[0] <= right[0]:
            result.append(left[0])
            left = left[1:]
        else:
            result.append(right[0])
            right = right[1:]
    if left:
        result.extend(left)
    else:
        result.extend(right)

    return result

def mergesort(m):
    left = list()
    right = list()
    result = list()

    if len(m) <= 1:
        return m
    middle = int(math.ceil(len(m)/2.0))
    for x in range(0,middle):
        left.append(m[x])
    for x in range(middle,len(m)):
        right.append(m[x])

    left = mergesort(left)
    right = mergesort(right)

    left_last_item = left[len(left)-1]
    right_first_item = right[0]

    if left_last_item > right_first_item:
        result = merge(left, right)
    else:
        left.extend(right)
        result = left

    return result
