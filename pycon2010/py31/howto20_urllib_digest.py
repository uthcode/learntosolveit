#!/usr/bin/env python3.1

import urllib.request, urllib.error, urllib.parse
import getpass

URL = 'http://livejournal.com/users/phoe6/data/rss?auth=digest' 

ah = urllib.request.HTTPDigestAuthHandler()
password = getpass.getpass()
ah.add_password('lj','http://phoe6.livejournal.com/','phoe6',password)
urllib.request.install_opener(urllib.request.build_opener(ah))
r = urllib.request.Request(URL)
obj = urllib.request.urlopen(r)
print(obj.read())
