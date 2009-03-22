# Note the use of os.curdir and os.pardir to refer to the current and parent
# directories in a portable manner.

import os

print 'Starting:', os.getcwd()
print os.listdir(os.curdir)

print 'Moving up one:', os.pardir
os.chdir(os.pardir)

print 'After move:', os.getcwd()
print os.listdir(os.curdir)
