#!/usr/bin/env python


import re
import sys
import time

if len(sys.argv) == 3:
    fhandle, m = open(sys.argv[1],'r'), int(sys.argv[2])
    try:
        assert m >=2
    except AssertionError:
        sys.exit("Usage: <int_m> should be greater than or equal to 2")
else:
    sys.exit("Usage: python %s <filename> <int_m>" % sys.argv[0])

contents = map((lambda x: x.strip()),fhandle.readlines())
wordlist = filter(lambda x: len(x) >=3, contents)

# This is a test wordlist for the program.
#wordlist = ['mad','hatter','madhatter','hattermad','madman','man','manhatter',
#            'madhatterman','madhatman','madmadmanhatter']

# Catch Unresonable combination requests early.
wordlist.sort(key=len)
smallest = len(wordlist[0])
largest  = len(wordlist[len(wordlist)-1])
lm = largest/smallest

if m > lm:
    print 0
    sys.exit()

# lets proceed. build worddict with atomic words as keys and all the words its a
# part as the values. If it is just its own part, not interested, ignore it.

worddict = {}

for word in wordlist:
    word_pattern = re.compile('\S*'+word+'\S*',re.IGNORECASE)
    matched = word_pattern.findall(' '.join(wordlist))
    if not len(matched) == 1:
        matched.remove(word)
        worddict[word] = matched

wordlist2 = worddict.keys()

countdict = {}

# wordlist2 or keys of the worddict consists only of the atomic words.
# values of the each atomic word in the dict consists of all the words that
# contain but need not be composite.Out of the values, identification of
# composite words is required. This reduces the sample space for comparision.

def combination(word,list_of_parts):
    solutions = set()
    for piece in list_of_parts:
        if piece.lower() == word.lower():
            solutions.add(tuple([piece]))
        elif word.lower().startswith(piece.lower()):
            #elif re.match(piece,word,re.IGNORECASE):
            for rest in combination(word[len(piece):],list_of_parts):
                solutions.add(tuple([piece] + list(rest)))
    return solutions

for word, compwords in worddict.iteritems():
    for compword in compwords:
        result = combination(compword,wordlist2)
        for each in result:
            n = len(each)
            try:
                if not compword in countdict[n]:
                    countdict[n].append(compword)
            except KeyError:
                countdict[n] = [compword]


try:
    print len(countdict[m])
except KeyError:
    print 0

