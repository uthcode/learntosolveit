#!/usr/bin/env python3.1

# Reading a Specific Line from a file
import linecache
SOMEFILE = '/usr/share/games/fortunes/perl'
theline = linecache.getline(SOMEFILE,42)
print(theline, end=' ')

def getline(thefilepath, desired_line_number):
    if desired_line_number < 1: return
    for current_line, line in enumerate(open(thefilepath,'rU')):
        if current_line == desired_line_number - 1:
            return line
    return ''

print(getline(SOMEFILE, 42))
