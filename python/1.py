import urllib2

with urllib2.urlopen('http://www.google.com') as req:
    res = req.read()
print res
