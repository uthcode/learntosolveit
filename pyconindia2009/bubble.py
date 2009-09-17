import random

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
    list_to_sort = generate_list(10)
    print list_to_sort
    bubblesort(list_to_sort)
    print list_to_sort

