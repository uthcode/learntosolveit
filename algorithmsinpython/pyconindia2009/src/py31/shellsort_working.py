import random

def generate_list(n):
    return random.sample(range(1000000), n)

def shellsort(A):
    inc = int(round(len(A)/2))
    while inc:
        for i in range(inc, len(A)):
            temp = A[i]
            j = i
            while ((j >= inc)  and (A[j-inc] > temp)):
                A[j] = A[j-inc]
                j = j - inc
            A[j] = temp
        inc = int(round(inc/2.2))

if __name__ == '__main__':
    list_to_sort = generate_list(10)
    print(list_to_sort)
    shellsort(list_to_sort)
    print(list_to_sort)
