import cookielib, urllib2

cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))

req = urllib2.Request('https://www.idcourts.us/repository/start.do')
res = opener.open(req)
print cj
for c in cj:
    cookie_str = "%s = %s" % (c.name, c.value)
print cookie_str

req = urllib2.Request('https://www.idcourts.us/repository/partySearch.do')
req.add_header("Cookie",cookie_str)
opener.open(req)
print cj
