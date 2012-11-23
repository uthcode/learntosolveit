"""
3 2
3 1 1
"""
import sys

n, k = map(int, raw_input().split())
list_of_numbers = map(int, raw_input().split())
length_of_list = len(list_of_numbers)

operation = 0

while operation < length_of_list:
    to_end = list_of_numbers[k-1]
    list_of_numbers.append(to_end)
    list_of_numbers.pop(0)
    operation += 1
    if len(list_of_numbers) == list_of_numbers.count(list_of_numbers[0]):
        print operation
        sys.exit()
else:
    print -1

