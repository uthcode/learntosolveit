import http.cookiejar, urllib.request, urllib.error, urllib.parse

cj = http.cookiejar.CookieJar()
opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cj))

req = urllib.request.Request('https://www.idcourts.us/repository/start.do')
res = opener.open(req)
print(cj)
for c in cj:
    cookie_str = "%s = %s" % (c.name, c.value)
print(cookie_str)

req = urllib.request.Request('https://www.idcourts.us/repository/partySearch.do')
req.add_header("Cookie",cookie_str)
opener.open(req)
print(cj)
