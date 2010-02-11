# Read the number of lines in a truly humonguous file.

import sys
count = 0
thefile = open(sys.argv[1], 'rb')
while True:
    buffer = thefile.read(8192*1024)
    if not buffer:
        break
    count += buffer.count('\n')

thefile.close()

print count
