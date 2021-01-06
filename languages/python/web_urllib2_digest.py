import urllib.request, urllib.error, urllib.parse

URL = 'http://localhost/allowed.html' 

ah = urllib.request.HTTPDigestAuthHandler()
ah.add_password('Realm','http://localhost/','senthil','kumaran')
urllib.request.install_opener(urllib.request.build_opener(ah))
r = urllib.request.Request(URL)
obj = urllib.request.urlopen(r)
print(obj.read())
