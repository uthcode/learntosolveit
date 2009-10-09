def partition(arr, p, r):
    x = arr[p]
    i = p - 1
    j = r + 1
    while True:
        if arr[j] <= x:
            pass
        else:
            j = j - 1
        if arr[i] >= x:
            pass
        else:
            i = i + 1

        if i < j:
            a[i],a[j] = a[j], a[i]
        else:
            return j

def quicksort(arr, p, r):
    if p < r:
        q = partition(arr, p, r)
        quicksort(arr, p, q)
        quicksort(arr, q+1, r)

