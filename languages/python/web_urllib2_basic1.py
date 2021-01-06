import urllib.request, urllib.error, urllib.parse

URL = 'http://localhost/basic.html'
passwd = '550charpass50charpass50charpass50charpass50charpass0charpass'
#passwd = 'senthil'
ah = urllib.request.HTTPBasicAuthHandler()
ah.add_password('Realm','http://localhost/basic.html','senthil',passwd)
urllib.request.install_opener(urllib.request.build_opener(ah))
r = urllib.request.Request(URL)
obj = urllib.request.urlopen(r)
print(obj.read())
