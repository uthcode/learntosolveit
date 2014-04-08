#!/usr/bin/python

"""
$Id$

This code is useful to maintain uthcode.


"""

import os
import subprocess
import shutil

# build algorithmsinpython
os.chdir('/home/senthil/uthcode/algorithmsinpython')
subprocess.call(["/usr/bin/make","html"])

os.chdir('/home/senthil/uthcode')

subprocess.call(["/usr/bin/python","includecfiles.py"])
subprocess.call(["/usr/bin/python","includecontestfiles.py"])
subprocess.call(["/usr/bin/python","includepythonfiles.py"])
subprocess.call(["/usr/bin/make","clean"])
subprocess.call(["/usr/bin/make","html"])

with open('/home/senthil/.ssh/password') as fh:
    password = fh.read().strip()

shutil.rmtree('/home/senthil/projects/googleappengine/python/bloggart/docs/')
shutil.move('/home/senthil/uthcode/build/html','/home/senthil/projects/googleappengine/python/bloggart/docs/')
shutil.move('/home/senthil/uthcode/algorithmsinpython/_build/html','/home/senthil/projects/googleappengine/python/bloggart/docs/algorithmsinpython')

os.chdir('/home/senthil/projects/googleappengine/python')

exec_stmt = 'echo "%s" |python appcfg.py update bloggart/ --email="orsenthil@gmail.com" --passin' % password
os.system(exec_stmt)
os.chdir('/home/senthil/uthcode')
