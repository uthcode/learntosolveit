#!/usr/local/bin/python
import cgitb
cgitb.enable()

print "Content-Type: text/html"
print 

import os

print "<HTML>"
print "<H1>Python CGI Example</H1>"
filecontents = os.listdir(os.getcwd())
print "<H2>You can use all Python functions:</H2>"
print "<H3>Like this one shows you the directory contents</H3>"
print filecontents
import time
print "<P>The current time is %s</P>" % time.ctime()
print "</HTML>"

