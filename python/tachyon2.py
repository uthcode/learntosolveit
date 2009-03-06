#!/usr/bin/env python
import sys

if len(sys.argv) == 3:
    fhandle, m = open(sys.argv[1],'r'), int(sys.argv[2])
else:
    sys.exit("Usage: python %s <filename> <int_m>" % sys.argv[0])

contents = map((lambda x: x.strip()),fhandle.readlines())

constituent = filter(lambda x: len(x) >=3, contents)

compositewords = []

constituents = {}

for word in constituent:
    constituents[word] = []
    for each_word in constituent:
        if not word == each_word and word in each_word:
            constituents[word].append(each_word)

print constituents

