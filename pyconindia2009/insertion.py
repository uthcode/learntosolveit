import random

def generate_list(n):
    return random.sample(xrange(1000000),n)

def insertionsort(A):
    """ Insertion sort in python.
    Start with the second element as the key and compare it with the elements
    preceding it. If you find the elements greater than key, shift the list one
    by one and when you find the element is lesser than key, insert the key at
    that position.
    """
    for j in range(1, len(A)): 
        key = A[j]
        i = j -1
        while (i >= 0) and (A[i] > key):
            A[i+1] = A[i]
            i = i -1
        A[i+1] = key

if __name__ == '__main__':
    list_to_sort = generate_list(100)
    print list_to_sort
    insertionsort(list_to_sort)
    print list_to_sort
