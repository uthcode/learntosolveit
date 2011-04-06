#! /ufs/guido/bin/sgi/python

# ptags
#
Create a tags file for Python programs
# Tagged are:
# - functions (even inside other defs or classes)
# - classes
# - filenames
# Warns about files it cannot open.
# No warnings about duplicate tags.

import sys
import posix
import path
import string

keywords = ['def', 'class']    # If you add keywords, update starts!!!
starts = 'dc'                  # Starting characters of keywords

whitespace = string.whitespace
identchars = string.letters + string.digits + '_'

tags = []      # Modified!

def main():
       args = sys.argv[1:]
       for file in args: treat_file(file)
       if tags:
               fp = open('tags', 'w')
               tags.sort()
               for s in tags: fp.write(s)

def treat_file(file):
       try:
               fp = open(file, 'r')
       except:
               print 'Cannot open', file
               return
       base = path.basename(file)
       if base[-3:] = '.py': base = base[:-3]
       s = base + '\t' + file + '\t' + '1\n'
       tags.append(s)
       while 1:
               line = fp.readline()
               if not line: break
               maketag(line, file)

def maketag(line, file):
       i = 0
       while line[i:i+1] in whitespace: i = i+1
       if line[i:i+1] not in starts: return
       n = len(line)
       j = i
       while i < n and line[i] not in whitespace: i = i+1
       if line[j:i] not in keywords: return
       while i < n and line[i] in whitespace: i = i+1
       j = i
       while i < n and line[i] in identchars: i = i+1
       name = line[j:i]
       while i < n and line[i] in whitespace: i = i+1
       if i < n and line[i] = '(': i = i+1
       s = name + '\t' + file + '\t' + '/^' + line[:i] + '/\n'
       tags.append(s)

main()
