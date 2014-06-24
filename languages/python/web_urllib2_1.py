import urllib2
import pudb;pudb.set_trace()
o = urllib2.urlopen('http://www.google.com')
print o
print type(o)
