#!/usr/bin/python
"""
$Id$

Purpose:
    Demonstrate the way the struct module works.

Description:
   One can access substrings of a string in a arbitrary manner while using the
   struct module. This is mostly useful when dealing with byte level
   programming required in embedded systems or while using sockets.

Source:
   Python cookbook perhaps.
"""
import struct
theline = "The quick brown fox jumped over the lazy dog."
# Get a 5-byte string, skip 3, get two 8-byte string, then all the rest:
baseformat = '5s 3x 8s 8s'
# by how many bytes does theline exceed the length implied by this
# base-format ( 24 bytes in this, but struct.calcsize is general)
numremain = len(theline) - struct.calcsize(baseformat)
# complete the format with the appropriate 's' field, then unpack
format = '%s %ds' % (baseformat, numremain)
l, s1, s2, t = struct.unpack(format, theline)
print(l)
print(s1)
print(s2)
print(t)
