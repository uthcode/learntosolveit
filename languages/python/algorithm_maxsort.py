def maxsort(A):
    size = len(A) -1
    for i in range(0,size):
        max_index = 0
        for j in range(0, (size -i)+1):
            if A[j] > A[max_index]:
                max_index = j
        A[size-i], A[max_index] = A[max_index], A[size-i]

A = [5,4,3,2,1]
maxsort(A)
print(A)
