"""
Simple Trie Implementation
"""

import json

_end_marker = "*"

def add_word(trie, word):
    word_trie = trie
    
    for ch in word:
        if ch in word_trie:
            word_trie = word_trie[ch]
        else:
            word_trie[ch] = {}
            word_trie = word_trie[ch]
    
    word_trie[_end_marker] = _end_marker

    return word_trie

def make_trie(*words):
    trie = dict()

    for word in words:
        add_word(trie, word)
    
    return trie

def is_word(trie, word):
    word_trie = trie
    for ch in word:
        if ch in word_trie:
            word_trie = word_trie[ch]
        else:
            return False
    return _end_marker in word_trie

def is_prefix(trie, word):
    word_trie = trie
    for ch in word:
        if ch in word_trie:
            word_trie = word_trie[ch]
        else:
            return False

    return True

def print_trie(trie):
    print(json.dumps(trie, sort_keys=True, indent=2))

trie = make_trie("hi", "hello", "help")

print_trie(trie)

print(is_word(trie, "hello"))
print(is_word(trie, "he"))
print(is_prefix(trie, "he"))