import sys
import urllib2
import cookielib

class HTTPMyDebugProcessor(urllib2.AbstractHTTPHandler):
    """Track HTTP Requests and responses with this custom handlers. Be sure to
    add it your build_opener call, or use: handler_order = 900 """
    def __init__(self, httpout = sys.stdout):
        self.httpout = httpout
    def http_request(self, request):
        if __debug__:
            host, full_url = request.get_host(), request.get_full_url()
            url_path = full_url[full_url.find(host) + len(host):]
            self.httpout.write("%s\n" % request.get_full_url())
            self.httpout.write("\n")
            self.httpout.write("%s %s\n" % (request.get_method(), url_path))

            for header in request.header_items():
                self.httpout.write("%s: %s\n" % header[:])

            self.httpout.write("\n")

        return request

    def http_response(self, request, response):
        if __debug__:
            code, msg, hdrs = response.code, response.msg, response.info()
            self.httpout.write("HTTP/1.x %s %s\n" % (code, msg))
            self.httpout.write(str(hdrs))

        return response

    https_request = http_request
    https_response = http_response

# Example
cjar = cookielib.LWPCookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cjar),HTTPMyDebugProcessor(),)
#opener = urllib2.build_opener(HTTPMyDebugProcessor(),)
urllib2.install_opener(opener)
##response = urllib2.urlopen("http://www.google.com")
#response = urllib2.urlopen("https://www.idcourts.us/repository/start.do")
#response = urllib2.urlopen("https://www.idcourts.us/repository/searchParty.do")
req = urllib2.Request('http://www.microsoft.com/windows/windows-7/default.aspx')
#req = urllib2.Request('https://www.idcourts.us/repository/start.do')
res = opener.open(req)

print cjar
for c in cjar:
    cookie_str = "%s=%s" % (c.name, c.value)
print cookie_str

req = urllib2.Request('http://www.microsoft.com/windows/windows-xp/default.aspx')
#req.add_header("Cookie",cookie_str)
opener.open(req)
print cjar
