import urllib2

basic_handler = urllib2.HTTPBasicAuthHandler()
basic_handler.add_password('Realm','http://localhost/','senthil','senthil')

digest_handler = urllib2.HTTPDigestAuthHandler()
digest_handler.add_password('Realm','http://localhost/','senthil','kumaran')
opener = urllib2.build_opener(basic_handler, digest_handler)
opener = urllib2.build_opener(digest_handler, basic_handler)
urllib2.install_opener(opener)

basic_url = r'http://localhost/basic.html'
digest_url = r'http://localhost/allowed.html'

print urllib2.urlopen(digest_url).read()
print urllib2.urlopen(basic_url).read()
