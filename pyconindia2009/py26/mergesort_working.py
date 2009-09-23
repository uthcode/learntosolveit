import math
import random


def generate_list(n):
    return random.sample(xrange(1000000), n)

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

def merge_sort(m):
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

    left = merge_sort(left)
    right = merge_sort(right)

    left_last_item = left[len(left)-1]
    right_first_item = right[0]

    if left_last_item > right_first_item:
        result = merge(left, right)
    else:
        left.extend(right)
        result = left

    return result



if __name__ == '__main__':
    list_to_sort = generate_list(10)
    print list_to_sort
    out = merge_sort(list_to_sort)
    print out
