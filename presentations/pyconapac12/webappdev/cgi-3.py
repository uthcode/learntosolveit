#!/usr/bin/env python
print "Content-Type: text/html"
print
import cgitb
try:
   f = open('non-existent-file.txt', 'r')
except:
   cgitb.handler()
