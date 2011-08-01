from itertools import permutations

"""
With the solution represented as a vector with one queen in each row, we don't
have to check to see if two queens are on the same row. By using a permutation
generator, we know that no value in the vector is repeated, so we don't have to
check to see if two queens are on the same column. Since rook moves don't need
to be checked, we only need to check bishop moves.

The technique for checking the diagonals is to add or subtract the column
number from each entry, so any two entries on the same diagonal will have the
same value (in other words, the sum or difference is unique for each
diagnonal). Now all we have to do is make sure that the diagonals for each of
the eight queens are distinct. So, we put them in a set (which eliminates
duplicates) and check that the set length is eight (no duplicates were
removed).

Any permutation with non-overlapping diagonals is a solution. So, we print it
and continue checking other permutations.
"""


n = 8
cols = range(n)

for vec in permutations(cols):
    v2 = []
    v3 = []
    for i in cols:
        v2.append(vec[i]+i)
        v3.append(vec[i]-i)
    lenv2 = len(set(v2))
    lenv3 = len(set(v3))
    if (n == lenv2 == lenv3):
        print vec
