import random
list_to_sort = random.sample(range(10),8)

def insertion_sort(listtosort):
    for i in range(1,len(listtosort)):
        key = listtosort[i]
        j = i - 1
        while ( j > 0) and (key < listtosort[j]):
            listtosort[j+1] = listtosort[j]
            j -= 1
        listtosort[j] = key
    return listtosort

print insertion_sort(list_to_sort)

