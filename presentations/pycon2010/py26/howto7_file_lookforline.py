#!/usr/bin/env python2.6

# Reading a Specific Line from a file
import linecache
SOMEFILE = '/usr/share/games/fortunes/perl'
theline = linecache.getline(SOMEFILE,42)
print theline,

def getline(thefilepath, desired_line_number):
    if desired_line_number < 1: return
    for current_line, line in enumerate(open(thefilepath,'rU')):
        if current_line == desired_line_number - 1:
            return line
    return ''

print getline(SOMEFILE, 42)
