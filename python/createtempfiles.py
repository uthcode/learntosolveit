"""
This program creates temporary files with content in them.  This serves as
useful utility if you want to fill a directory full of temporary files with
some content.  The content is Zen of Python.

Capturing output with module evaluation by tempeorary redirection of stdout is
shown here. Control the mkstemp call according to your requirements.

"""
import tempfile
import random
import os
import sys

num = random.randint(100,1000)

fhandle = open('zen','w')
old_stdout, sys.stdout = sys.stdout, fhandle
import this
sys.stdout = old_stdout
fhandle.close()
zen = open('zen').read()
os.remove('zen')

for i in range(num):
    fname = tempfile.mkstemp(suffix='.gz',prefix=str(i), dir=os.path.abspath('in'),
                     text=True)[1]
    fhandle = open(fname, 'w')
    fhandle.write(zen)
    fhandle.close()
