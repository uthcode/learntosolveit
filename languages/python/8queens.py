from itertools import permutations

# What's the difference between permutations and combinations.
# permutations is about arrangements.
# combinations is about choosing.

n = 8
queens = range(n)
for pos in permutations(queens):
    # how many times is the if statement below evaluated?
    # How does subtracting and addition the position work?
    if (n == len(set(pos[i]+i for i in queens))
          == len(set(pos[i]-i for i in queens))):
        print pos
