import tempfile
import shutil
import os
import re

#re_pattern = re.compile('([\d.]*)\s(\d*)\s(\d*)\s(\w*)')
re_pattern = re.compile(r'([\d.]*)\s(123)\s(321)\s(\w*)')
fname = '1.txt'

fh, abs_path = tempfile.mkstemp()
new_file = open(abs_path, 'w')
old_file = open(fname)
for line in old_file:
    new_line = re.sub(re_pattern,r'\1 \2 \3 %s' % 'RESPONSE_SENT',line)
    new_file.write(new_line)
new_file.close()
os.close(fh)
old_file.close()
#os.remove(fname)
shutil.move(abs_path, fname)
