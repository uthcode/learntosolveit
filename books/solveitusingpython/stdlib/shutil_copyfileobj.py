#!/usr/bin/env python2.6

import shutil

# open a file, with w+ mode.

f1 = open('example1.txt','w+')

f1.write("""
I was born in a barrel of butcher knives
Trouble I love and peace I despise
Wild horses kicked me in my side
Then a rattlesnake bit me and he walked off and died.
		-- Bo Diddley
""")

# Writing would have changed the file-pointer, so I do a seek(0), in order to
# return it back to first position.

f1.seek(0)

f2 = open('example2.txt','w+')

# I am going to copy using shutil.copyfileobj.  This works on open file handles
# and copies the contents of the fsrc to fdst. The file handlle will reach to
# the end again.

shutil.copyfileobj(f1,f2)

# Let me check, if both files are same now.

f1.seek(0)
f2.seek(0)

print f1.read() == f2.read()

# print contents from second file.

f2.seek(0)
print f2.read()

# time to close the file handlers.
f1.close()
f2.close()
