#!/usr/bin/env python
import Cookie, time

cookie = Cookie.SimpleCookie()

# name/value pair
cookie['lastvisit'] = str(time.time())

# expires in x seconds after the cookie is output.
# the default is to expire when the browser is closed
cookie['lastvisit']['expires'] = 30 * 24 * 60 * 60

# path in which the cookie is valid.
# if set to '/' it will valid in the whole domain.
# the default is the script's path.
cookie['lastvisit']['path'] = '/cgi-bin/'

# the purpose of the cookie to be inspected by the user
cookie['lastvisit']['comment'] = 'holds the last user\'s visit date'

# domain in which the cookie is valid. always stars with a dot.
# to make it available in all subdomains
# specify only the domain like .my_site.com
cookie['lastvisit']['domain'] = '.www.my_site.com'

# discard in x seconds after the cookie is output
# not supported in most browsers
cookie['lastvisit']['max-age'] = 30 * 24 * 60 * 60

# secure has no value. If set directs the user agent to use
# only (unspecified) secure means to contact the origin
# server whenever it sends back this cookie
cookie['lastvisit']['secure'] = ''

# a decimal integer, identifies to which version of
# the state management specification the cookie conforms.
cookie['lastvisit']['version'] = 1

print 'Content-Type: text/html\n'

print '<p>', cookie, '</p>'
for morsel in cookie:
   print '<p>', morsel, '=', cookie[morsel].value
   print '<div style="margin:-1em auto auto 3em;">'
   for key in cookie[morsel]:
      print key, '=', cookie[morsel][key], '<br />'
   print '</div></p>'
