import urllib2
authinfo = urllib2.HTTPBasicAuthHandler()
opener = urllib2.build_opener(authinfo)
urllib2.install_opener(opener)
f = urllib2.urlopen('http://mail.google.com/a/spasticssocietyofkarnataka.org/#inbox')
print f.info()
