import urllib2

URL = 'http://localhost/basic.html' 

ah = urllib2.HTTPBasicAuthHandler()
ah.add_password('Realm','http://localhost/','senthil','senthil')
urllib2.install_opener(urllib2.build_opener(ah))
r = urllib2.Request(URL)
obj = urllib2.urlopen(r)
print obj.read()
