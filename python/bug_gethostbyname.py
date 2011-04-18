#!/usr/bin/python
#$Id$
"""
Generate a random domain name and see if it actually exists by doing a
gethostbyname call.
"""

from socket import *
import sys

def test(name):
    print "enter test, gethostbyname(%r)" % name
    print "You can press CTRL-C"
    try:
        try:
            gethostbyname(name)
        except:
            print "inner try"
            E = sys.exc_info()[0]
            print type(E), repr(E), E is KeyboardInterrupt
            raise
    except:
        print "outer try"
        E = sys.exc_info()[0]
        print type(E), repr(E), E is KeyboardInterrupt
    print "exit test"

import random
letters = list("typingsomeuselessword")
random.shuffle(letters)
name = ".".join(letters[:5]) + ".com"
test(name)
