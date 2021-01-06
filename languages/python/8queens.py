from itertools import permutations

# What's the difference between permutations and combinations.
# permutations is about arrangements.
# combinations is about choosing.


def eight_queens():
    queens = list(range(8))
    for pos in permutations(queens):
        # how many times is the if statement below evaluated?
        # How does subtracting and addition the position work?
        if (8 == len(set(pos[i] + i for i in queens))
                == len(set(pos[i] - i for i in queens))):
            print(pos)


if __name__ == '__main__':
    eight_queens()
