#!/usr/local/bin/python
# $Id$

"""
An Example CGI Program in Python.

Important modules are cgitb - cgitraceback for traceback details when something
fails.

You will have to setup your environment properly for this to work.
"""

import os
import time

import cgitb
cgitb.enable()

print "Content-Type: text/html"
print

print "<HTML>"
print "<H1>Python CGI Example</H1>"
filecontents = os.listdir(os.getcwd())
print "<H2>You can use all Python functions:</H2>"
print "<H3>Like this one shows you the directory contents</H3>"
print filecontents
print "<P>The current time is %s</P>" % time.ctime()
print "</HTML>"

