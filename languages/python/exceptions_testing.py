from urllib2 import URLError, HTTPError
from StringIO import StringIO

print isinstance(URLError("foo"), HTTPError)
print isinstance(HTTPError("foo", "bar", "baz", "zap", StringIO()), URLError)

try:
	raise HTTPError("foo", "bar", "baz", "zap", StringIO())
except URLError:
	print "caught this exception"
else:
	print "this exception escaped."