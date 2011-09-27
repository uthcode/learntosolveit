from itertools import permutations
n = 8
queens = range(n)
for pos in permutations(queens):
    if (n == len(set(pos[i]+i for i in queens))
          == len(set(pos[i]-i for i in queens))):
        print pos
