import urllib.request, urllib.error, urllib.parse

URL = 'http://localhost/allowed.html'

ah = urllib.request.HTTPDigestAuthHandler()
ah.add_password('Realm','http://localhost/','senthil','kumaran')
urllib.request.install_opener(urllib.request.build_opener(ah))
r = urllib.request.Request(URL)
r.add_data("1")
obj = urllib.request.urlopen(r)
print(obj.read())
r.add_data("10")
obj = urllib.request.urlopen(r)
print(obj.read())
