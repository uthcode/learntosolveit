#!/usr/bin/env python3.1

import urllib.request, urllib.error, urllib.parse

URL = 'http://localhost/basic.html' 

ah = urllib.request.HTTPBasicAuthHandler()
ah.add_password('Realm','http://localhost/','senthil','senthil')
urllib.request.install_opener(urllib.request.build_opener(ah))
r = urllib.request.Request(URL)
obj = urllib.request.urlopen(r)
print(obj.read())
