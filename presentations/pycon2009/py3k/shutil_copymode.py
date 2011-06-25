# By default when a new file is created under Unix, it receives permissions
# based on the umask of the current user. To copy the permissions from one file
# to another use copymode

from shutil import copymode
from commands import getstatus
import os

f = open('file_to_change.txt','wt')
f.write('content')
f.close()

os.chmod('file_to_change.txt',0444)

print 'BEFORE:', getstatus('file_to_change.txt')
copymode('shutil_copymode.py', 'file_to_change.txt')
print 'AFTER:', getstatus('file_to_change.txt')

os.unlink('file_to_change.txt')
