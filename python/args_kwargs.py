#!/usr/bin/python

#$Id$
"""
Good example for args and kwargs in a function.
It prints
a: a
b: b
args: ('c', 'd', 'e', 'f') # Note it's a tuple.
kwargs: {'i': 'i', 'h': 'h', 'j': 'j', 'g': 'g'}
"""

def fun(a, b, *args, **kwargs):
    print 'a:',a
    print 'b:',b
    print 'args:', args
    print 'kwargs:', kwargs

fun('a','b','c','d','e','f',g='g',h='h',i='i',j='j')
