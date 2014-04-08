import urllib2

URL = 'http://localhost/basic.html'
passwd = '550charpass50charpass50charpass50charpass50charpass0charpass'
#passwd = 'senthil'
ah = urllib2.HTTPBasicAuthHandler()
ah.add_password('Realm','http://localhost/basic.html','senthil',passwd)
urllib2.install_opener(urllib2.build_opener(ah))
r = urllib2.Request(URL)
obj = urllib2.urlopen(r)
print obj.read()
