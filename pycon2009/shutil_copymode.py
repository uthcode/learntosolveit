# By default when a new file is created under Unix, it receives permissions
# based on the umask of the current user. To copy the permissions from one file
# to another use copymode

import shutil
import subprocess

import os

# Create an example file.
f = open('example.txt','w+')
f.write('content')
f.close()

# Set the mode to 0444

os.chmod('example.txt',0444)

shutil.copyfile('example.txt','newfile.txt')

subprocess.call(['ls', '-ld', 'example.txt'])

print 'With shutil.copyfile:'
subprocess.call(['ls', '-ld', 'newfile.txt'])

print 'After shutil.copymode:'
shutil.copymode('example.txt','newfile.txt')
subprocess.call(['ls', '-ld', 'newfile.txt'])

os.unlink('example.txt')
os.unlink('newfile.txt')
