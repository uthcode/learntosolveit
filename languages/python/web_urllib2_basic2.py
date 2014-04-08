import urllib2

URL = 'http://localhost/basic.html' 

ah = urllib2.HTTPBasicAuthHandler()
ah.add_password('Realm','http://localhost/','username','veryverylongpassword')
urllib2.install_opener(urllib2.build_opener(ah))
r = urllib2.Request(URL)
obj = urllib2.urlopen(r)
print obj.read()

print '*********************************************************'
import urllib2
import sys
import re
import base64
from urlparse import urlparse

theurl = 'http://localhost/basic.html'
# if you want to run this example you'll need to supply
# a protected page with your username and password

username = 'username'
password = 'veryverylongpassword'            # a very bad password

req = urllib2.Request(theurl)
try:
    handle = urllib2.urlopen(req)
except IOError, e:
    # here we *want* to fail
    pass
else:
    # If we don't fail then the page isn't protected
    print "This page isn't protected by authentication."
    sys.exit(1)

if not hasattr(e, 'code') or e.code != 401:
    # we got an error - but not a 401 error
    print "This page isn't protected by authentication."
    print 'But we failed for another reason.'
    sys.exit(1)

authline = e.headers['www-authenticate']
# this gets the www-authenticate line from the headers
# which has the authentication scheme and realm in it


authobj = re.compile(
    r'''(?:\s*www-authenticate\s*:)?\s*(\w*)\s+realm=['"]([^'"]+)['"]''',
    re.IGNORECASE)
# this regular expression is used to extract scheme and realm
matchobj = authobj.match(authline)

if not matchobj:
    # if the authline isn't matched by the regular expression
    # then something is wrong
    print 'The authentication header is badly formed.'
    print authline
    sys.exit(1)

scheme = matchobj.group(1)
realm = matchobj.group(2)
# here we've extracted the scheme
# and the realm from the header
if scheme.lower() != 'basic':
    print 'This example only works with BASIC authentication.'
    sys.exit(1)

base64string = base64.encodestring(
                '%s:%s' % (username, password))[:-1]
authheader =  "Basic %s" % base64string
req.add_header("Authorization", authheader)
try:
    handle = urllib2.urlopen(req)
except IOError, e:
    # here we shouldn't fail if the username/password is right
    print "It looks like the username or password is wrong."
    sys.exit(1)
thepage = handle.read()
