import os

from shutil import copytree, rmtree
from commands import getoutput

os.mkdir('example')
copytree('example','/tmp/example')

print 'BEFORE:'
print getoutput('ls -rlast /tmp/example')

rmtree('/tmp/example')
print 'AFTER:'
print  getoutput('ls -rlast /tmp/example')

rmtree('example')
