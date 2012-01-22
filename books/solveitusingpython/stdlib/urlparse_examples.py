from urlparse import urlparse, urlsplit, urldefrag, urlunparse, urljoin

URL = 'http://user:password@netloc:80/path;parameters?query=argument#fragment'
parsed = urlparse(URL)
print parsed
print 'scheme   :', parsed.scheme
print 'netloc   :', parsed.netloc
print 'path     :', parsed.path
print 'params   :', parsed.params
print 'query    :', parsed.query
print 'fragment :', parsed.fragment
print 'username :', parsed.username
print 'password :', parsed.password
print 'hostname :', parsed.hostname
print 'port     :', parsed.port

# urlsplit is different from urlparse, in the way that it returns a 5 tuple
# instead of 6 tuple and it does not have parameters.

splited = urlsplit(URL)
print splited
print 'scheme   :', splited.scheme
print 'netloc   :', splited.netloc
print 'path     :', splited.path
print 'query    :', splited.query
print 'fragment :', splited.fragment
print 'username :', splited.username
print 'password :', splited.password
print 'hostname :', splited.hostname
print 'port     :', splited.port

# urldefrag method removes the fragment only from the url

url, fragment = urldefrag(URL)
print 'fragment :', fragment

# Unparsing a url.
# A parsed object or splited object has geturl() which can be used to retrieve
# the original url.

parsed = urlparse(URL)
print 'parsed   :', parsed
print 'url      :', parsed.geturl()

splited = urlsplit(URL)
print 'splited  :', splited
print 'url      :', splited.geturl()

# But, there is a separate unparse method which works even for tuples of the
# parsed data.

parsed = urlparse(URL)
t = tuple(parsed)
print 'url  :', urlunparse(t)

# Superfluous parts may be dropped while unparsing

URL = 'http://netloc/path;?#'
print 'Original :', URL
print 'Parsed   :', urlparse(URL)
print 'Unparsed :', urlunparse(urlparse(URL))

# urljoin method follows the rules specified in the RFC to join the url to the
# base url.


print 'urljoin example:', urljoin('http://www.example.com/path/file.html', 'anotherfile.html')
print 'urljoin example2:', urljoin('http://www.example.com/path/file.html', '../anotherfile.html')

