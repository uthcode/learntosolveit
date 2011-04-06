import urllib2
import pudb
pudb.set_trace()

req = urllib2.Request('ftp://ftp.gnome.org/')
res = urllib2.urlopen(req)
