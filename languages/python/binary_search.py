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


ar = sorted(random.sample(range(10),9))
#ar = [0, 1, 3, 4, 5, 6, 7, 8, 9]
r = random.randint(0,10)
#r = 0
print(ar)
print(r)
print('find')
print(find_in_sorted(ar,r))
print(ar)
print(r)
