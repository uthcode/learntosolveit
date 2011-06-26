#!/usr/bin/python
# $Id:$
"""
Problem Statement:
http://code.google.com/codejam/contest/dashboard?c=351101#s=p2

This is extremely simple. You just have to know to use dictionary upfront and
simple logic to deal with the samekey pressing twice where you append space.
Building the solution in partial stages, where you develop without including
space and then adding the logic to space was faster than thinking of the whole
solution upfront.

"""
t9_dict = {
        'a':2,
        'b':22,
        'c':222,
        'd':3,
        'e':33,
        'f':333,
        'g':4,
        'h':44,
        'i':444,
        'j':5,
        'k':55,
        'l':555,
        'm':6,
        'n':66,
        'o':666,
        'p':7,
        'q':77,
        'r':777,
        's':7777,
        't':8,
        'u':88,
        'v':888,
        'w':9,
        'x':99,
        'y':999,
        'z':9999,
        ' ':0
        }

N = int(raw_input())
for tc in range(1,N+1):
    txt = list(raw_input())
    result = []
    prev_keystroke = ''
    for t in txt:
        next_keystroke = str(t9_dict[t])
        if next_keystroke[0] in prev_keystroke:
            result.append(' ')
        result.append(next_keystroke)
        prev_keystroke = next_keystroke
    print 'Case #%d: %s' % (tc , ''.join(result))
