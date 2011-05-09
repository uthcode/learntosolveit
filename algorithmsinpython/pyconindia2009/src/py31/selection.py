def selectionsort(A):
    for i in range(0, len(A)-1):
        min = i
        for j in range(i+1, len(A)):
            if A[j] < A[min]:
                min = j
        if not (i == min):
            A[i], A[min] = A[min], A[i]
