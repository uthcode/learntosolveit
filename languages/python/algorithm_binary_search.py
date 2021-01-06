import random

def find_in_sorted(arr, x):
    def binsearch(start, end):
        if start == end:
            return -1
        mid = start + (end - start) // 2
        if x < arr[mid]:
            return binsearch(start, mid)
        elif x > arr[mid]:
            return binsearch(mid+1, end)
        else:
            return mid
    return binsearch(0, len(arr))


ar = sorted(random.sample(list(range(10)),9))
r = random.randint(0,10)
print((find_in_sorted(ar,r)))
