import os
from shutil import move
from glob import glob

f = open('example.txt','wt')
f.write('contents')
f.close()

print 'BEFORE:', glob('example*')
move('example.txt','example.out')
print 'AFTER:', glob('example*')
os.unlink('example.out')
