#!/usr/bin/env python

import sys

print "Content-Type: text/plain"
print

sys.stderr = sys.stdout

f = open('non-existent-file.txt', 'r')

