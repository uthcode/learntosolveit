"""
Problem: http://code.google.com/codejam/contest/dashboard?c=90101#s=p2
It is a dynamic programming problem. Requires a lot of lateral thinking.
"""
t = 'welcome to code jam'

N = int(raw_input())
for tc in range(1,N+1):
    charcount = [0 for i in range(len(t))]
    s = raw_input()
    validchars = [char for char in s if char in t]
    validchars = ''.join(validchars)
    for ch in validchars:
        newcharcount = charcount[:]
        for i,c in enumerate(t):
            if c == ch:
                if i == 0:
                    newcharcount[i] = newcharcount[i] + 1
                else:
                    newcharcount[i] = newcharcount[i] + charcount[i-1]
            charcount = newcharcount
    output = str(charcount[-1] % 10000).zfill(4)
    print 'Case #%d: %s' % (tc, output)

