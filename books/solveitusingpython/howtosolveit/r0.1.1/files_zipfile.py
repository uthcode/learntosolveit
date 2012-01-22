# Recipe which demonstrates writing to a zipfile and reading the content from
# it.

import zipfile
import tempfile
import os
import sys

handle, filename = tempfile.mkstemp('.zip')
os.close(handle)

z = zipfile.ZipFile(filename,'w')
z.writestr('hello.py','def f(): return "hello world from " + __file__\n')
z.close()
sys.path.insert(0,filename)
import hello
print hello.f()
os.unlink(filename)
