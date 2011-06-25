#!/usr/bin/env python2.6

import os
dir_name = 'os_directories_example'


print 'Starting at:', os.getcwd()
print os.listdir(os.curdir)

print 'Creating Directory:', dir_name
os.makedirs(dir_name)

file_name = os.path.join(dir_name, 'example.txt')
print 'Creating File:', file_name

f = open(file_name,'wt')

try:
    f.write('example file')
finally:
    f.close()

print 'Listing:', dir_name
print os.listdir(dir_name)

print 'Cleaning up'
os.unlink(file_name)
os.rmdir(dir_name)


print 'Moving up one directory:', os.pardir
os.chdir(os.pardir)

print 'After move:', os.getcwd()
print os.listdir(os.curdir)
