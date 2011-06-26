import itertools

list1 = ['a','b','c','d','ab','cd','abc','bcd']

word = 'abcd'

# what is required is:

"""
dict1 = {'abcd':[(1,[('a','b','c','d')]),
                 (3,[('a','b','cd'),('ab','c','d')])
                 (2,[('abc','d'),('a','bcd')])]
        }

Step 1, aim for:

    store = [[abc,d][a,bcd],[a,b,cd],[ab,c,d],[a,b,c,d]]
"""

store = []

list1.sort(key=len,reverse=True)

def checkcomposition(key, list_of_words):
    word = 'abcd'
    list_of_possible = [''.join(x) for x in itertools.permutations(list_of_words)]
    for each in list_of_possible:
        if ((key + each) in word) or ((each+key) in word):
            return True
            break
    else:
            return False

for key in list1:
    if key in word:
        if not store or key == word:
            store.append([key])
        else:
            for i in range(len(store)):
                if key not in store[i]:
                    if checkcomposition(key,store[i]):
                        store[i].append(key)
            else:
                store.append([key])


print store
