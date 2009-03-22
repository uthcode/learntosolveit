import os

from shutil import copytree
from commands import getoutput

os.mkdir('example')
print 'BEFORE:'
print getoutput('ls -rlast /tmp/example')
copytree('example','/tmp/example')

print 'AFTER:'
print getoutput('ls -rlast /tmp/example')

os.rmdir('example')
os.rmdir('/tmp/example')
