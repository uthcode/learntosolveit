from random import shuffle
from getlist import random_list

# Bogo-sort deck in place
def bogosort(deck):
    while not all(x < y for x, y in zip(deck, deck[1:])):
        shuffle(deck)

if __name__ == '__main__':
    deck = random_list(10)
    print 'Before Sorting:',deck
    bogosort(deck)
    print 'After Bogosort:',deck
