#!/usr/bin/env python

import sha, time, cgi, os

sid = cgi.FieldStorage().getfirst('sid')

if sid: # If session exists
   message = 'Already existent session'
else: # New session
   # The sid will be a hash of the server time
   sid = sha.new(repr(time.time())).hexdigest()
   message = 'New session'

qs = 'sid=' + sid

print """\
Content-Type: text/html\n
<html><body>
<p>%s</p>
<p>SID = %s</p>
<p><a href="./set_sid_qs.py?sid=%s">reload</a></p>
</body></html>
""" % (message, sid, sid)
