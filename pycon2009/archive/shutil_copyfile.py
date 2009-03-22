import os
import shutil

from shutil import copyfile
from glob import glob

print 'BEFORE:', glob('shutil_copyfile.*')
copyfile('shutil_copyfile.py', 'shutil_copyfile.py.copy')
print 'AFTER:', glob('shutil_copyfile.*')
os.unlink('shutil_copyfile.py.copy')
