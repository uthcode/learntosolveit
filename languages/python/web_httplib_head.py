import http.client
conn = http.client.HTTPConnection("www.google.com")
conn.request("HEAD","/index.html")
res = conn.getresponse()
for header,value in res.getheaders():
    print(header, value)
