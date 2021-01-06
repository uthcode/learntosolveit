import urllib.request, urllib.error, urllib.parse

proxy = urllib.request.ProxyHandler({'http': 'http:// username:password@proxyurl:proxyport',
                              'https': 'https://username:password@proxyurl:proxyport'}
                             )
auth = urllib.request.HTTPBasicAuthHandler()
opener = urllib.request.build_opener(proxy, auth, urllib.request.HTTPHandler)
urllib.request.install_opener(opener)

conn = urllib.request.urlopen('http://python.org')
return_str = conn.read()
