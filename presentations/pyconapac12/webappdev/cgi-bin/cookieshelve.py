#!/usr/bin/env python
import sha, time, Cookie, os, shelve

cookie = Cookie.SimpleCookie()
string_cookie = os.environ.get('HTTP_COOKIE')

if not string_cookie:
   sid = sha.new(repr(time.time())).hexdigest()
   cookie['sid'] = sid
   message = 'New session'
else:
   cookie.load(string_cookie)
   sid = cookie['sid'].value
cookie['sid']['expires'] = 12 * 30 * 24 * 60 * 60

# The shelve module will persist the session data
# and expose it as a dictionary
session_dir = os.environ['DOCUMENT_ROOT'] + '/tmp/.session'
session = shelve.open(session_dir + '/sess_' + sid, writeback=True)

# Retrieve last visit time from the session
lastvisit = session.get('lastvisit')
if lastvisit:
   message = 'Welcome back. Your last visit was at ' + \
      time.asctime(time.gmtime(float(lastvisit)))
# Save the current time in the session
session['lastvisit'] = repr(time.time())

print """\
%s
Content-Type: text/html\n
<html><body>
<p>%s</p>
<p>SID = %s</p>
</body></html>
""" % (cookie, message, sid)

