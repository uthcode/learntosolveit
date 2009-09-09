import re

firstline = raw_input()
L,D,N = firstline.split()
words = []
patterns = []
count = []
for each in range(int(D)):
    words.append(raw_input())

for each in range(int(N)):
    patterns.append(raw_input())

for each in patterns:
    w = each.replace('(','[')
    w = w.replace(')',']')
    pat = re.compile(w)
    n = 0
    for eachword in words:
        if pat.match(eachword):
            n = n + 1
    count.append(n)

for n,i in enumerate(count):
    print 'Case #%d: %d' % (n+1,i)

