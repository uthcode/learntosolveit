Web Services Gateway Interface
==============================

It is easy to build **a web application framework in Python.** WSGI is Python
PEP 333, the Web Server Gateway Interface. It's a protocol for communicating
with Python web applications WSGI works by callbacks. 
     
The application provides a function which the server calls for each request::

        application(environ, start_response)

`environ` is a Python dictionary containing the CGI-defined environment
variables plus a few extras. One of the extras is `wsgi.input`, the file object
from which to read the POST variables. `start_response` is a callback by which
the application returns the HTTP header::

        start_response(status, response_headers, exc_info=None)

`status` is an HTTP status string (e.g., "200 OK"). `response_headers` is a
list of 2-tuples, the HTTP headers in key-value format. `exc_info` is used in
exception handling; we won't cover it here.

The application function then returns an iterable of body chunks. In the
simplest case this can be::

        ["<html>Hello, world!</html>"]

Getting slightly more elaborate, here's the second-smallest WSGI application in
the world::

        def app2(environ, start_response):
            start_response("200 OK", [])
            s = "<html>You requested <strong>%s</strong></html>"
            s %= environ['PATH_INFO']
            return [s]

The protocol may look strange, but it's designed to meet the needs of the
widest possible variety of existing and potential frameworks and servers and
middleware. 

Middleware are reusable components providing generic services normally handled
by frameworks; e.g., a Session object, a Request object, error handling.
They're implemented as wrapper functions; i.e., decorators. Inbound they can
add keys to the dictionary (e.g., quixote.request for a Quixote-style Request
object). Outbound they can modify HTTP headers or translate the body into Latin
or Marklar. Here's a small middleware.::

        class LowercaseMiddleware:
            def __init__(self, application):
                self.application = application   # A WSGI application callable.

            def __call__(self, environ, start_response):
                pass  # We could set an item in 'environ' or a local variable.
                for chunk in self.application(environ, start_response):
                    yield chunk.lower()

Assuming we had a Server Constructor Server, we could do::

        app = LowercaseMiddleware(app2)
        server = Server(app)

Since it's so easy to write a WSGI application, you may wonder, "Who needs a
framework?" That's a legitimate question, although the answer is, "It's tedious
without one." 

Your application is responsible for every URL under it; e.g., if it's installed
as http://localhost:8080/, it would have to do something intelligent with
http://localhost:8080/foo/bar/baz. Code to parse the URL and switch to an
appropriate function is... **a framework!** So you may as well use an existing
framework and save yourself the tedium.

Writing a WSGI server interface is more complex. There's an example in PEP 333.

WSGI opens the way for a lot of interesting possibilities. Simple frameworks
can be turned completely into middleware. Some frameworks might be able to run
on top of other frameworks or even be emulated by them. Ideally, existing
applications would run unchanged or with minimal changes. But this is also a
time for framework developers to rethink how they're doing things and perhaps
switch to more middleware-friendly APIs.

web.py ( http://webpy.org/ ) is a single module (~1000 lines) that does WSGI
and an extremely simple O-R mapping, with Cheetah for (non-XML) templates. 

With respect to WSGI, its original purpose wasn't to do "middleware"; it was
just a way to connect an application to arbitrary web servers, so the same
application can be run under mod_python, CGI, FastCGI, SCGI, in a Twisted or
other Python HTTP server, etc. That was and is the main point of WSGI. 

The existence of middleware is just a natural side-effect of having a way to
connect an app to a server, in the same way that proxy servers and caches are a
side-effect of having HTTP.

But just as it was a good idea to specify some of the allowed behaviors of
proxies and caches in the HTTP spec, so too it was a good idea to address
middleware in the WSGI spec. Basically, WSGI in itself is just a Python
encoding of HTTP and nothing more.

WSGI PEP is basically a port of the Java servlet API, implemented in terms of
simple callables and built-in data types rather than having an object/method
interface. 

Thus, any framework that's WSGI compliant support should give you the "server
independence" you're looking for. You just need a WSGI "gateway" for the
server, and find out how the framework exposes an "application" object to be
run by the gateway.


