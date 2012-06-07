#!/usr/bin/env python
import time

# This is the message that contains the cookie
# and will be sent in the HTTP header to the client
print 'Set-Cookie: lastvisit=' + str(time.time())

# To save one line of code
# we replaced the print command with a '\n'
print 'Content-Type: text/html\n'
# End of HTTP header

print '<html><body>'
print 'Server time is', time.asctime(time.localtime())
print '</body></html>'
