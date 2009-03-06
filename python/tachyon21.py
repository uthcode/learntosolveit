#!/usr/bin/env python
import re
import sys
import itertools

if len(sys.argv) == 3:
    fhandle, m = open(sys.argv[1],'r'), int(sys.argv[2])
else:
    sys.exit("Usage: python %s <filename> <int_m>" % sys.argv[0])

contents = map((lambda x: x.strip()),fhandle.readlines())
#wordlist = filter(lambda x: len(x) >=3, contents)

wordlist = ['mad','hatter','madhatter','hattermad','madman','man','manhatter',
            'madhatterman','madhatman','madmadmanhatter']

worddict = {}

for word in wordlist:
    word_pattern = re.compile('\S*'+word+'\S*')
    matched = word_pattern.findall(' '.join(wordlist))
    if not len(matched) == 1:
        matched.remove(word)
        worddict[word] = matched

wordlist2 = worddict.keys()


compwords = []
rest = []

"""
for key,value in worddict.iteritems():
    for each in value:
        pre,key,post = each.partition(key)
        if not pre:
            if post in wordlist2 and each not in compwords:
                compwords.append(each)
        if not post:
            if pre in wordlist2 and each not in compwords:
                compwords.append(each)
"""

"""
for key,value in worddict.iteritems():
    for each in value:
        pre,key,post = each.partition(key)
        if not pre:
            if post in wordlist2 and each not in compwords:
                if not each in compwords:
                    compwords.append(each)
            elif each not in rest:
                rest.append(each)
        if not post:
            if pre in wordlist2 and each not in compwords:
                compwords.append(each)
            elif each not in rest:
                rest.append(each)
"""
countdict = {}

for word, compwords in worddict.iteritems():
    for compword in compwords:
        compword_test_count = 1
        for each_word in wordlist2:
            if not each_word == word and each_word in compword:
                compword_test_count += 1
        try:
            if not compword in countdict[compword_test_count]:
                countdict[compword_test_count].append(compword)
        except KeyError:
            countdict[compword_test_count] = [compword]
        compword_test_count = 0


print countdict
#print len(compwords)
#print rest,len(rest)
