import urllib2

URL = 'http://livejournal.com/users/phoe6/data/rss?auth=digest' 

ah = urllib2.HTTPDigestAuthHandler()
ah.add_password('lj','http://phoe6.livejournal.com/','phoe6','mypassword')
urllib2.install_opener(urllib2.build_opener(ah))
r = urllib2.Request(URL)
obj = urllib2.urlopen(r)
print obj.read()
