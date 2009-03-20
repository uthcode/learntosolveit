import os
import shutil
from commands import getoutput

# Create an example directory.
os.mkdir('example')

# Write an empty test file.
f = open('example.txt','wt')
f.write('contents')
f.close()

# move the file to that directory.
shutil.move('example.txt','example')

# copy the entire directory tree to a different location.

shutil.copytree('example','/tmp/example')

print 'BEFORE:'
print getoutput('ls -rlast /tmp/example')

# remove the directory tree
shutil.rmtree('/tmp/example')

print 'AFTER:'
print getoutput('ls -rlast /tmp/example')

shutil.rmtree('example')
