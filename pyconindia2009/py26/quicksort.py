import random

def quicksort(A):
    lesser = []
    greater = []

    if len(A) <= 1:
        return A

    index = random.randint(0,len(A)-1)
    pivot = A.pop(index)

    for x in A:
        if x < pivot:
            lesser.append(x)
        elif x >= pivot:
            greater.append(x)

    lesser = quicksort(lesser)
    greater = quicksort(greater)

    return lesser + [pivot] + greater
