import shutil
import os

os.mkdir('example')
print 'BEFORE:', os.listdir('example')
shutil.copy('shutil_copy.py','example')
print 'AFTER:', os.listdir('example')
os.unlink('example'+ os.sep + 'shutil_copy.py')
os.rmdir('example')
