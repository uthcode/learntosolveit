import urllib.request, urllib.error, urllib.parse

basic_handler = urllib.request.HTTPBasicAuthHandler()
basic_handler.add_password('Realm','http://localhost/','senthil','senthil')

digest_handler = urllib.request.HTTPDigestAuthHandler()
digest_handler.add_password('Realm','http://localhost/','senthil','kumaran')
opener = urllib.request.build_opener(basic_handler, digest_handler)
opener = urllib.request.build_opener(digest_handler, basic_handler)
urllib.request.install_opener(opener)

basic_url = r'http://localhost/basic.html'
digest_url = r'http://localhost/allowed.html'

print(urllib.request.urlopen(digest_url).read())
print(urllib.request.urlopen(basic_url).read())
