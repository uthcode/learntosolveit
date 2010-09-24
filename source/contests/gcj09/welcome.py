"""
wilan: phoe6: dynamic programming/memoisation
phoe6: oh okay. thanks wilan.
wilan: phoe6: and if you did that - make sure you don't overflow by using modulo
arithmetic (mod 10000)
repsilat: wilan: or arbirary size ints :/
"""

S = 'welcome to code jam'
N = int(raw_input())
result = []

for tc in range(N):
    T = raw_input()

    NT = ''
    for each in T:
        if each in S:
            NT = NT+each

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


    result.append((last[-1] % 10000))

for n,c in enumerate(result):
    print 'Case #%d: %s' % (n+1,str(c).zfill(4))
