# By default when a new file is created under Unix, it receives permissions
# based on the umask of the current user. To copy the permissions from one file
# to another use copymode

import shutil
from commands import getstatus

import os

# Create an example file.
f = open('example.txt','w+')
f.write('content')
f.close()

# Set the mode to 0444

os.chmod('example.txt',0444)

shutil.copyfile('example.txt','newfile.txt')

print getstatus('example.txt')

print 'With shutil.copyfile:'
print getstatus('newfile.txt')

print 'After shutil.copymode:'
shutil.copymode('example.txt','newfile.txt')
print getstatus('newfile.txt')

os.unlink('example.txt')
os.unlink('newfile.txt')
