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
