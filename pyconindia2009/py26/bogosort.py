from random import shuffle
 
# Bogo-sort deck in place
while not all(x <= y for x, y in zip(deck, deck[1:])):
    shuffle(deck)
