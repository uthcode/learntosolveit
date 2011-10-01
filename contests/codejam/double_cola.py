q = ['Sheldon', 'Leonard', 'Penny', 'Rajesh','Howard']
import math
import sys

n = int(raw_input())

if n <= len(q):
    print q[n-1]
    sys.exit()

d = 50

dict_of_values = {}
dict_of_combos = {}
dict_of_values[1] = 0
dict_of_combos[1] = 1
p = 1
for i in range(1,d):
    dict_of_values[i+1] = dict_of_values[i] + 5 * p
    p = p * 2
    dict_of_combos[i+1] = p

for k,v in dict_of_values.items():
    if n < v:
        key = k
        break
key = key-1
value = dict_of_values[key]
index = n - value
mult = dict_of_combos[key]

a, b = divmod(index,mult)
print q[a]
