import cookielib
import urllib2

cookiejar = cookielib.LWPCookieJar()
http_handler = urllib2.HTTPHandler(debuglevel=1)
opener = urllib2.build_opener(http_handler,urllib2.HTTPCookieProcessor(cookiejar))
urllib2.install_opener(opener)
url = 'https://www.orange.sk/'
req = urllib2.Request(url, None)
s = opener.open(req)
