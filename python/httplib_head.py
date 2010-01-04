import httplib
conn = httplib.HTTPConnection("www.google.com")
conn.request("HEAD","/index.html")
res = conn.getresponse()
for header,value in res.getheaders():
    print header, value
