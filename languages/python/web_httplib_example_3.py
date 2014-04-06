import http.client
#import pudb
#pudb.set_trace()
conn = http.client.HTTPConnection("www.python.org")
conn.request("GET","/index.html")
res = conn.getresponse()
print(res.getheaders())
print(res.getheader('server'))
print(res.getheader('space','mine'))
