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
        if piece.lower() == word.lower():
            solutions.add(tuple([piece]))
        elif word.lower().startswith(piece.lower()):
            for rest in combinations(word[len(piece):], list_of_parts):
                solutions.add(tuple([piece] + list(rest)))
    return solutions

list1 = ['mad','Man','hatter','madhatter']
#list1 = ['a','b','c','d','ab','cd','abc','bcd']
wrd = 'madmanmadhatter'

results = combinations(wrd, list1)
print results
print len(results)
"""
results = ((len(x), x) for x in results) # add len
# make it a dict:
dict1 = {}
for size, result in results:
    dict1.setdefault(size, []).append(result)

# print
import pprint
pprint.pprint(dict1)
"""

