initial_array = [2,7,6,-3,5,5,2,-3,7]
set_b = set(initial_array)
for number in set_b:
    if initial_array.count(number) == 1:
        print number
