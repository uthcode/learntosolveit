import http.cookiejar
import urllib.request, urllib.error, urllib.parse

cookiejar = http.cookiejar.LWPCookieJar()
http_handler = urllib.request.HTTPHandler(debuglevel=1)
opener = urllib.request.build_opener(http_handler,urllib.request.HTTPCookieProcessor(cookiejar))
urllib.request.install_opener(opener)
#url = 'https://www.orange.sk/'
url = 'https://www.idcourts.us/repository/start.do'
req = urllib.request.Request(url, None)
cookie = cookiejar[0]
print(cookie.value)
"""
s = opener.open(req)
print cookiejar
url = 'https://www.idcourts.us/repository/partySearch.do'
req = urllib2.Request(url, None)
s = opener.open(req)
print cookiejar
url = 'https://www.idcourts.us/repository/start.do'
req = urllib2.Request(url, None)
s = opener.open(req)
print cookiejar
url = 'https://www.idcourts.us/repository/partySearch.do'
req = urllib2.Request(url, None)
s = opener.open(req)
print cookiejar
"""
