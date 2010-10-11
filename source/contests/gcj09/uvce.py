import pudb
pudb.set_trace()

S = 'uvce is my college'
T = 'uvce is my college. i like uvce because it is my college. we have akamai coming to my college.'
NT = ''

for each in T:
    if each in S:
        NT = NT+each
print NT

# Hold the template for list of characters to search
last = [0 for i in S]

for t_char in NT:
    next = last[:]
    for i in range(len(S)):
        s_char = S[i]
        if s_char == t_char:
            if i == 0:
                next[i] = next[i] + 1
            else:
                next[i] = next[i] + last[i-1]
    last = next

print last[-1]
