"""
Problem Statement:
    http://code.google.com/codejam/contest/dashboard?c=90101#s=p0

The idea is to indentify that this problem becomes easy to solve one you
recognize that it easy to contrust a regex pattern and let the actual task of
solving to the regex library.
"""
import re

L, D, N = map(int,raw_input().split())
words = []
for word in range(D):
    words.append(raw_input())
for tc in range(1,N+1):
    inputstr = raw_input()
    inputstr = inputstr.replace('(','[')
    inputstr = inputstr.replace(')',']')
    inputpattern = re.compile(inputstr)
    matches = 0
    for word in words:
        if inputpattern.match(word):
            matches += 1
    print 'Case #%d: %d' % (tc, matches)
