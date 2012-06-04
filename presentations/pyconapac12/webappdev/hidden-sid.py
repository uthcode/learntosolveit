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
<form method="post">
<input type="hidden" name=sid value="%s">
<input type="submit" value="Submit">
</form>
</body></html>
""" % (message, sid, sid)
