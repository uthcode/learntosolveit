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
