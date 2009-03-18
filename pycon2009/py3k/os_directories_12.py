# There are several functions for working with directories on filesystem,
# including creating, listing contents and removing them.

import os
dir_name = 'os_directories_example'

print 'Creating', dir_name
os.makedirs(dir_name)

file_name = os.path.join(dir_name, 'example.txt')
print 'Creating', file_name

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
