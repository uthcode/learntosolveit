import urllib2
import pdb

pdb.set_trace()
authinfo = urllib2.HTTPBasicAuthHandler()
opener = urllib2.build_opener(authinfo)
urllib2.install_opener(opener)
f = urllib2.urlopen('http://mail.google.com/a/spasticssocietyofkarnataka.org/#inbox')
print f.info()
