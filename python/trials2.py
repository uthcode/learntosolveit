import re, itertools

def combinations(word, list_of_parts):
    """
    dict1 = {'abcd':[(1,[('a','b','c','d')]),
                     (3,[('a','b','cd'),('ab','c','d')])
                     (2,[('abc','d'),('a','bcd')])]
            }

    Step 1, aim for:

        store = [[abc,d][a,bcd],[a,b,cd],[ab,c,d],[a,b,c,d]]
    """
    solutions = set()
    for piece in list_of_parts:
        if piece == word:
            solutions.add(tuple([piece]))
        elif re.match(piece, word):
            for rest in combinations(word[len(piece):], list_of_parts):
                solutions.add(tuple([piece] + list(rest)))
    return solutions

list1 = ['mad','man','madman','manhatter']
wrd  = 'madmanmadhatter'
#list1 = ['a','b','c','d','ab','cd','abc','bcd']
#wrd = 'abcd'

results = combinations(wrd, list1)
results = ((len(x), x) for x in results) # add len
# make it a dict:
dict1 = {}
for size, result in results:
    dict1.setdefault(size, []).append(result)

# print
import pprint
pprint.pprint(dict1)

