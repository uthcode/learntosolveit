import random

random_sequence = random.sample(range(100),10)
print('The random sequence of numbers is:',end=' ')
print(random_sequence)

largest_number = random_sequence[0]

for each_number in random_sequence[1:]:
    if each_number > largest_number:
        largest_number = each_number

print('The largest number is:',end=' ')
print(largest_number)
