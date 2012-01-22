from shutil import *
import os
from StringIO import StringIO
import sys

class VerboseStringIO(StringIO):
    def read(self, n=-1):
        next = StringIO.read(self, n)
        print 'read(%d) =>' % n, next
        return next

sample_string = "Harp not on that string.-- William Shakespeare, 'Henry VI'"

print 'Default:'
input = VerboseStringIO(sample_string)
output = StringIO()
copyfileobj(input, output)

print

print 'All at Once:'
input = VerboseStringIO(sample_string)
output = StringIO()
copyfileobj(input, output, -1)

print

print 'Blocks of 20'
input = VerboseStringIO(sample_string)
output = StringIO()
copyfileobj(input, output, 20)
