import random

def random_list(n):
    return random.sample(xrange(10000000), n)

def insertionsort(A):
    """ Insertion sort in python.
    """
    for j in range(1, len(A)):
        key = A[j]
        i = j -1
        while (i >= 0) and (A[i] > key):
            A[i+1] = A[i]
            i = i -1
        A[i+1] = key

if __name__ == '__main__':
    list_to_sort = random_list(10)
    print list_to_sort
    insertionsort(list_to_sort)
    print list_to_sort
