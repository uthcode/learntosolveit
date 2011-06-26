import pudb
import urllib2
pudb.set_trace()
req = urllib2.Request("http://in.pycon.org")
res = urllib2.urlopen(req)
