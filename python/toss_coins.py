# Example showing tossing of coins

import random

heads = tails = count = 0
choice = ''

while choice.lower() != 'q':
    count = count + 1
    choice = random.choice(["heads","tails"])
    if choice == "heads":
            heads = heads + 1
    else:
            tails = tails + 1
    print choice
    choice = raw_input("Press any key to continue or q to quit")

print 'Total :', count
print 'Heads :', str(heads), ' Percentage ', ((heads * 1.0)/count) * 100
print 'Tails :', str(tails), ' Percentage ', ((tails * 1.0)/count) * 100
