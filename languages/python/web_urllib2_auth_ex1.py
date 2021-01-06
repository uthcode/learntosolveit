import urllib.request, urllib.error, urllib.parse
authinfo = urllib.request.HTTPBasicAuthHandler()
opener = urllib.request.build_opener(authinfo)
urllib.request.install_opener(opener)
f = urllib.request.urlopen('http://mail.google.com/a/spasticssocietyofkarnataka.org/#inbox')
print(f.info())
