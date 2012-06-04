#!/usr/bin/env python
import time, Cookie

# Instantiate a SimpleCookie object
cookie = Cookie.SimpleCookie()

# The SimpleCookie instance is a mapping
cookie['lastvisit'] = str(time.time())

# Output the HTTP message containing the cookie
print cookie
print 'Content-Type: text/html\n'

print '<html><body>'
print 'Server time is', time.asctime(time.localtime())
print '</body></html>'
