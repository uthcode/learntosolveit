import urllib.request, urllib.error, urllib.parse
o = urllib.request.urlopen('http://www.google.com')
print(o)
print(type(o))
