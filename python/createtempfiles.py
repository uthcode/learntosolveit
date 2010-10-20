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
