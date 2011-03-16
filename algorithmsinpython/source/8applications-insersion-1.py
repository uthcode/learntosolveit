import random

unsorted_list = random.sample(range(100),10)

print unsorted_list
# [46, 15, 79, 50, 86, 4, 54, 21, 97, 84]

for j in range(1, len(unsorted_list)):
    key = unsorted_list[j]
    i = j - 1
    while i >= 0 and unsorted_list[i] > key:
        unsorted_list[i+1] = unsorted_list[i]
        i = i - 1
    unsorted_list[i+1] = key # Why?
    #To accomodate the key index which you have pushed to right.

print unsorted_list
# [4, 15, 21, 46, 50, 54, 79, 84, 86, 97]
