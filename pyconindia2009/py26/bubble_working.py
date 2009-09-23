from getlist import random_list
import time

def generate_list(n):
    return random.sample(xrange(1000000), n)

def bubblesort(A):
    swapped = True
    while swapped:
        swapped = False
        for i in range(len(A)-1):
            if A[i] > A[i+1]:
                A[i], A[i+1] = A[i+1], A[i]
                swapped = True


if __name__ == '__main__':
    list_to_sort = random_list(1000000)
    #print list_to_sort
    x1 = time.time()
    bubblesort(list_to_sort)
    x2 = time.time()
    #print list_to_sort
    print 'taken:', x2-x1, 'ms'

