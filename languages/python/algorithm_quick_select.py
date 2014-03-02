import random

def nth(arr, n):
    pivot = arr[0]
    below = [x for x in arr if x < pivot]
    above = [x for x in arr if x > pivot]

    num_less = len(below)
    num_lessoreq = len(arr) - len(above)

    if n < num_less:
        return nth(below, n)
    elif n >= num_lessoreq:
        return nth(above, n-num_lessoreq)
    else:
        return pivot

arr = random.sample(range(10),10)

print nth(arr,0)
print nth(arr,1)
print nth(arr,2)
print nth(arr,3)
print nth(arr,4)
print nth(arr,5)
print nth(arr,6)
print nth(arr,7)
print nth(arr,8)
print nth(arr,9)
