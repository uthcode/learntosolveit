Web Programming
===============

Example of  Smart Redirect Handler 
----------------------------------

::

        import urllib2

        class SmartRedirectHandler(urllib2.HTTPRedirectHandler):
            def http_error_302(self, req, fp, code, msg, headers):
                result = urllib2.HTTPRedirectHandler.http_error_302(self, req, fp,
                                                                         code, msg,
                                                                         headers)
                result.status = code
                return result

        request = urllib2.Request("http://localhost/index.html")
        opener = urllib2.build_opener(SmartRedirectHandler())
        obj = opener.open(request)
        print 'I capture the http redirect code:', obj.status
        print 'Its been redirected to:', obj.url


urllib module
-------------

Parsing RSS feeds
-----------------
