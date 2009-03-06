#!/usr/bin/env python

test_words =  ['mad', 'hatter', 'madhatter', 'hattermad', 'madman', 'man',
               'manhatter', 'madhatterman', 'madhatman', 'madmadmanhatter']

atomic_words = ['madhatter', 'madman', 'hatter', 'manhatter', 'man', 'mad']

# For each test word, determine if it is a composite word.
# For the composite words, determine the n values, that is number of atomic
# words that it can make. n can be 2, 3 or more for a single word itself.

# Sort according to wordlength, highest word-length first
"""
for i in range(len(atomic_words)-1):
    for j in range(i+1,len(atomic_words)):
        if len(atomic_words[j]) > len(atomic_words[i]):
            atomic_words[i],atomic_words[j] = atomic_words[j],atomic_words[i]
"""

atomic_words.sort(key=len,reverse=True)

test = test_words[3]

node_graph = {}

for each in atomic_words:
    if test.startswith(atomic_word):
        node_graph[each] = 

