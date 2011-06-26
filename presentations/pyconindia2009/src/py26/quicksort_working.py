import random

def generate_list(n):
    return random.sample(xrange(1000000), n)
    

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

if __name__ == '__main__':
    list_to_sort = generate_list(10)
    print list_to_sort
    output = quicksort(list_to_sort)
    print output
