=====================
Python HTTP Libraries
=====================

------------
urllib notes
------------

**functions**

* urlopen
* install_opener
* build_opener
* request_host
* _parse_proxy
* randombytes
* parse_keqv_list
* parse_http_list

**class**

* Request
* OpenerDirector
* BaseHandler
  * HTTPErrorProcessor
  * HTTPCookieProcessor
  * HTTPDefaultErrorHandler
  * HTTPRedirectHandler
  * ProxyHandler
  * AbstractHTTPHandler
  * UnknownHandler
  * FileHandler
  * FTPHandler
  * CacheFTPHandler

* AbstractHTTPHandler
  * HTTPHandler
  * HTTPSHandler

* HTTPPasswordMgr
  * HTTPPasswordMgrWithDefaultRealm

* AbstractBasicAuthHandler

* AbstractBasicAuthHandler, BaseHandler
  * HTTPBasicAuthHandler
  * ProxyBasicAuthHandler

* AbstractDigestAuthHandler

* BaseHandler, AbstractDigestAuthHandler
  * HTTPDigestAuthHandler
  * ProxyDigestAuthHandler


urlopen -> build_opener -> OpenerDirector() -> OpenerDirector.add_handler for
each class and handler -> OpenerDirector.open() method on the composite object.
-> Request -> returns stateful url -> protocol_request is called -> _open ->
and protocol_response is called and returned. The handler is invoked in the
specific order as specified by the Handler attribute.

**OpenerDirector**

handlers is a list.
handle_open is a dictionary.
handle_error is a dictionary.
process_request is a dictionary.
process_response is a dictionary.

When handlers are getting added, it should not have attribute called
add_parent.

For each handler don't add the methods redirect_request, do_open, proxy_open

The methods which are like _error, _open, _request, _response are handled in a
special manner.  The error, open and response are called conditions.  And the
terms preceding them are called protocol.

When it is an error condition, some magic is done to find it's kind. The error
kind could have been got from the error_XXX, but instead, it the position is
determined and then it is extraced from the method name. Surprisingly, kind is
not used in the error block. Instead, in the OpenerDirector's handle_error
dictionary, for the protocol, which got an _error, a key is added, the value is
initially {}.

If the condition is _open, the kind is the protocol and the lookup is handle_open dictionary.
If the condition is _request, the kind is the protocol and the lookup process_request dictionary.
If the condition is _response, the kind is the protocol and the lookup is process_response.

Why is it that redirect_request, do_open and proxy_open are not handled.

Because it is a for loop on the methods of the handler, the kind and the lookup
is set at the end and it could be either for error, open, request or response.
But within the for loop, the handler having those methods is added. It is
bisect.insorted and then, again, it is bisect.insorted for all the handlers.

So, it seems that for that portion of the code, the appropriate handlers are
added. That is all.

What happens is, for any of these dictionaries, if it is an error, open,
request or response, dictionary method's setdefault is called for that protocol

There is a doubt when added=True comes in, handlers is list of all handlers is
added. What's an add_unredirectedheader doing and what is it's purpose?  What
is self._call_chain's behavior?  The redirect_cache was not setting in, because
the object's parent method was calling and entirely new request, forgetting
about the current request. When made a change that request object is carrying
the information about the redirect, the cache hit was observed. Something along
the same lines would be good.

Dissecting urlparse:
--------------------

* __all__ methods provides the public interfaces to all the methods like
  urlparse, urlunparse, urljoin, urldefrag, urlsplit and urlunsplit.

* then there is classification of schemes like uses_relative, uses_netloc,
  non_hierarchical, uses_params, uses_query, uses_fragment

* there should be defined in an rfc most probably 1808.

* there is a special '' blank string, in certain classifications, which means
  that apply by default.

* valid characters in scheme name should be defined in 1808.

* class ResultMixin is defined to provide username, password, hostname and
  port.

* The behaviour of the public methods urlparse, urlunparse, urlsplit and
  urlunsplit and urldefrag matter most.

urlparse - scheme, netloc, path, params, query and fragment.  urlunparse will
take those parameters and construct the url back.

urlsplit - scheme, netloc, path, query and fragment.
urlunsplit - takes these parameters (scheme, netloc, path, query and fragment)
and returns a url.

As per the RFC3986, the url is split into: 

scheme, authority, path, query, frag = url

The authority part in turn can be split into the sections:
user, passwd, host, port = authority

The following line is the regular expression for breaking-down a
well-formed URI reference into its components:: 

        ^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?
        12 3 4 5 6 7 8 9

        scheme = $2
        authority = $4
        path = $5
        query = $7
        fragment = $9


The urlsplit functionality in the urllib can be moved to new regular expression
based parsing mechanism.

From man uri, which confirms to rfc2396 and HTML 4.0 specs.

* An absolute identifier refers to a resource independent of context, while a
  relative identifier refers to a resource by describing the difference from
  the current context.

* A path segment while contains a colon character ':' can't be used as the
  first segment of a relative URI path. Use it like this './file:path'

* A query can be given in the archaic "isindex" format, consisting of a word or
  a phrase and not including an equal sign (=). If = is there, then it must be
  after & like &key=value format.

Character Encodings:

* Reserved characters: ;/?:@&=+$,
* Unreserved characters: ALPHA, DIGITS, -_.!~*'()

An escaped octet is encoded as a character triplet consisting of the percent
character '%' followed by the two hexadecimal digits representing the octet
code.HTML 4.0 specification section B.2 recommends the following, which should
be considered best available current guidance:

1) Represent each non-ASCII character as UTF-8
2) Escape those bytes with the URI escaping mechanism, converting each byte to
   %HH where HH is the hexadecimal notation of the byte value.

One of the important changes when adhering to RFC3986 is parsing of IPv6
addresses.

CacheFTPHandler testcases are hard to write. 

Here's how the control goes.

#) There is an url with two '//'s in the path

#) The call is data = urllib2.urlopen(url).read()

#) urlopen calls the build_opener. build_opener builds the opener using (tuple)
of handlers.

#) opener is an instance of OpenerDirector() and has default HTTPHandler and
HTTPSHandler.

#) When the Request call is made and the request has 'http' protocol, then
http_request method is called.

::

         HTTPHandler has http_request method which is
         AbstractHTTPHandler.do_request_ Now, for this issue we get to the
         do_request_ method and see that host is set in the do_request_ method
         in the get_host() call.

         request.get_selector() is the call which is causing this particular
         issue of "urllib2 getting confused with path containing //".
         .get_selector() method returns self.__r_host.


Now, when proxy is set using set_proxy(), self.__r_host is self.__original (
The original complete url itself), so the get_selector() call is returns the
sel_url properly and we can get the host from the splithost() call on the
sel_url.

When proxy is not set, and the url contains '//' in the path segment, then
.get_host() (step 7) call would have seperated the self.host and self.__r_host
(it pointing to the rest of the url) and .get_selector() simply returns this
(self.__r_host, rest of the url expect host. Thus causing call to fail.

9) Before the fix, request.add_unredirected_header('Host', sel_host or host)
had the escape mechanism set for proper urls wherein with sel_host is not set
and the host is used. Unfortunately, that failed when this bug caused sel_host
to be set to self.__r_host and Host in the headers was being setup wrongly (
rest of the url).

The patch which was attached appropriately fixed the issue. I modified and
included for py3k.

* urllib2 in python 3k was divided into urllib.request and urllib.error. I was
  thinking if the urllib.response class is included; but no, response object is
  nothing but a addinfourl object.

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

* Apache 2.0 supports IPv6.

::
        phoe6:  I want to setup a test server which will do a redirect ( I know
        how to do that), but with a delay. So that when I am testing my client,
        I can test the clients timeout. Can someone give me suggestions as how
        can i go about this?

        jMCg: phoe6: http://httpd.apache.org/docs/2.2/mod/mod_ext_filter.html#examples

* apache is configured by placing directives in configuration files. the main configuration file is called apache2.conf
* Other configuration files are added by Include directive.

How is the HTTP response given by the urllib?
GetRequestHandler which takes the responses as the parameter and returns a handler.
What does the GetRequestHandler do?
It takes responses as one of its argument.
Implements a FakeHTTPRequestHandler which is extending BaseHTTPRequestHandler.
BaseHTTPRequestHandler implements do_GET, do_POST and send_head
The send_head method when it is returning the body it is sending it properly.

Why is that the response is getting trimmed to 49042?


Having a construct like::

        def __init__(self, *args, **kwargs):
        BaseClass.__init__(self, *args, **kwargs)

But in the base class, I find that it is not taking the tuple and dict as
arguments.

* What is an addrinfo struct.

The getaddrinfo() function returns a list of 5-tuples with the following
structure: (family, socktype, proto, canonname, sockaddr)

family, socktype, proto are all integer and are meant to be passed to the
socket() function. canonname is a string representing the canonical name of the
host. It can be a numeric IPv4/v6 address when AI_CANONNAME is specified for a
numeric host.

socket.gethostbyname(hostname)

Translate a host name to IPv4 address format. The IPv4 address is returned as a
string, such as '100.50.200.5'. If the host name is an IPv4 address itself it
is returned unchanged. See gethostbyname_ex() for a more complete interface.
gethostbyname() does not support IPv6 name resolution, and getaddrinfo() should
be used instead for IPv4/v6 dual stack support.

We need to replace the gethostbyname socket call. Because it is only IPv4
specific. using the getaddrinfo() function can include the IPv4/v6 dual stack
support.

import socket
print socket.gethostbyname(hostname)

def gethostbyname(hostname)
family, socktype, proto, canonname, sockaddr = socket.getaddrinfo(hostname)
return canonname

RFC 1123 date format:
Thu, 01 Dec 1994 16:00:00 GMT

::

        >>> datereturned = "Thu, 01 Dec 1994 16:00:00 GMT"
        >>> dateexpired = "Sun, 05 Aug 2007 03:25:42 GMT"
        >>> obj1 = datetime.datetime(*time.strptime(datereturned, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
        >>> obj2 = datetime.datetime(*time.strptime(dateexpired, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
        >>> if obj1 == obj2:
        print "Equal"
        elif obj1 > obj2:
        print datereturned
        elif obj1 < obj2:
        print dateexpired

Apache setup and URL RFCs
-------------------------

In order to setup a password for your apache based site, in the
/var/www/.htaccess file specify the username and password as senthil:senthil

Some clients support the no_proxy environment variable that specifies a set of
domains for which the proxy should not be consulted; the contents is a
comma-separated list of domain names, with an optional :port part.

WWW-Authenticate

The WWW-Authenticate response-header field must be included in 401
(unauthorized) response messages. The field value consists of at least one
challenge that indicates the authentication scheme(s) and parameters applicable
to the Request-URI.

       WWW-Authenticate = "WWW-Authenticate" ":" 1#challenge

The HTTP access authentication process is described in Section 11. User agents
must take special care in parsing the WWW-Authenticate field value if it
contains more than one challenge, or if more than one WWW-Authenticate header
field is provided, since the contents of a challenge may itself contain a
comma-separated list of authentication parameters. 

Following are some of the notes I took, while working on urllib patches.  It
should be a handy reference when working on bugs again.

RFC 3986 Notes:

A URI is a sequence of characters that is not always represented as a sequence
of octets.Percent-encoded octets may be used within a URI to represent
characters outside the range of the US-ASCII coded character set.

Specification uses Augmented Backus-Naur Form (ABNF) notation of RFC2234,
including the following core ABNF syntax rules defined by that specification:
ALPHA (letters), CR ( carriage return), DIGIT (decimal digits), DQUOTE (double
quote), HEXDIG (hexadecimal digits), LF (line feed) and SP (space).

Section 1 of RFC3986 is very generic. Understand that URI should be
transferable and single generic syntax should denote the whole range of URI
schemes.URI Characters are, in turn, frequently encoded as octets for transport
or presentation. This specification does not mandate any character encoding for
mapping between URI characters and the octets used to store or transmit those
characters.

pct-encoded = "%" HEXDIG HEXDIG

For consistency, uri producers and normalizers should use uppercase
hexadecimal digits, for all percent - encodings.

reserved = gen-delims / sub-delims
gen-delims = ":" / "/" / "?" / "#" / "[" / "]" / "@"
sub-delims = "!" / "$" / "&" / "'" / "(" / ")"
/ "*" / "+" / "," / ";" / "="

unreserved = ALPHA / DIGIT / "-" / "." / "_" / "~"

When a new URI scheme defines a component that represents textual data
consisting of characters from the Universal Character Set, the data should
first be encoded as octets according to the UTF-8 character encoding [STD63];
then only those octets that do not correspond to characters in the unreserved
set should be percent- encoded. For example, the character A would be
represented as "A", the character LATIN CAPITAL LETTER A WITH GRAVE would be
represented as "%C3%80", and the character KATAKANA LETTER A would be
represented as "%E3%82%A2".

How that is being used encoding reservered characters within data. Transmission
of url from local to public when using a different encoding - translate at the
interface level.

URI = scheme ":" hier-part [ "?" query ] [ "#" fragment ]

hier-part = "//" authority path-abempty
/ path-absolute
/ path-rootless
/ path-empty

Many URI schemes include a hierarchical element for a naming
authority so that governance of the name space defined by the
remainder of the URI is delegated to that authority (which may, in
turn, delegate it further):: 

        userinfo = *( unreserved / pct-encoded / sub-delims / ":" )
        host = IP-literal / IPv4address / reg-name

In order to disambiguate the syntax host between IPv4address and reg-name, we
apply the "first-match-wins" algorithm. A host identified by an Internet
Protocol literal address, version 6 [RFC3513] or later, is distinguished by
enclosing the IP literal within square brackets ("[" and "]"). This is the only
place where square bracket characters are allowed in the URI syntax::

        IP-literal = "[" ( IPv6address / IPvFuture ) "]"

        IPvFuture = "v" 1*HEXDIG "." 1*( unreserved / sub-delims / ":" )

        IPv6address = 6( h16 ":" ) ls32
        / "::" 5( h16 ":" ) ls32
        / [ h16 ] "::" 4( h16 ":" ) ls32
        / [ *1( h16 ":" ) h16 ] "::" 3( h16 ":" ) ls32
        / [ *2( h16 ":" ) h16 ] "::" 2( h16 ":" ) ls32
        / [ *3( h16 ":" ) h16 ] "::" h16 ":" ls32
        / [ *4( h16 ":" ) h16 ] "::" ls32
        / [ *5( h16 ":" ) h16 ] "::" h16
        / [ *6( h16 ":" ) h16 ] "::"

        ls32 = ( h16 ":" h16 ) / IPv4address
        ; least-significant 32 bits of address

        h16 = 1*4HEXDIG
        ; 16 bits of address represented in hexadecimal

        IPv4address = dec-octet "." dec-octet "." dec-octet "." dec-octet

        dec-octet = DIGIT ; 0-9
        / %x31-39 DIGIT ; 10-99
        / "1" 2DIGIT ; 100-199
        / "2" %x30-34 DIGIT ; 200-249
        / "25" %x30-35 ; 250-255

        reg-name = *( unreserved / pct-encoded / sub-delims )


Non-ASCII characters must first be encoded according to UTF-8 [STD63], and then
each octet of the corresponding UTF-8 sequence must be percent-encoded to be
represented as URI characters.  When a non-ASCII registered name represents an
internationalized domain name intended for resolution via the DNS, the name
must be transformed to the IDNA encoding [RFC3490] prior to name lookup.

Section 3 was about sub-components and their structure and if they are
represented in NON ASCII how to go about with encoding/decoding that::

        path = path-abempty ; begins with "/" or is empty
        / path-absolute ; begins with "/" but not "//"
        / path-noscheme ; begins with a non-colon segment
        / path-rootless ; begins with a segment
        / path-empty ; zero characters

        path-abempty = *( "/" segment )
        path-absolute = "/" [ segment-nz *( "/" segment ) ]
        path-noscheme = segment-nz-nc *( "/" segment )
        path-rootless = segment-nz *( "/" segment )
        path-empty = 0<pchar>
        segment = *pchar
        segment-nz = 1*pchar
        segment-nz-nc = 1*( unreserved / pct-encoded / sub-delims / "@" )
        ; non-zero-length segment without any colon ":"

        pchar = unreserved / pct-encoded / sub-delims / ":" / "@"

        relative-ref = relative-part [ "?" query ] [ "#" fragment ]

        relative-part = "//" authority path-abempty
        / path-absolute
        / path-noscheme
        / path-empty

Section 4 was on the usage aspects and heuristics used in determining in the
scheme in the normal usages where scheme is not given.  Base uri must be
stripped of any fragment components prior to it being used as a Base URI.

Section 5 was on relative reference implementation algorithm. I had covered
them practically in the Python urlparse module.Section 6 was on Normalization
of URIs for comparision and various normalization practices that are used.


RFC 3986 Notes
--------------

Mon Aug 25 10:17:01 IST 2008

- A URI is a sequence of characters that is not always represented as a
  sequence of octets. ( What are octets? OCTETS means 8 Bits. Nothing else!)
- Percent-encoded octets may be used within a URI to represent characters
  outside the range of the US-ASCII coded character set.
- Specification uses Augmented Backus-Naur Form (ABNF) notation of [RFC2234],
  including the followig core ABNF syntax rules defined by that specification:
  ALPHA (letters), CR ( carriage return), DIGIT (decimal digits), DQUOTE
  (double quote), HEXDIG (hexadecimal digits), LF (line feed) and SP (space).

Section 1 of RFC3986 is very generic. Undestand that URI should be transferable
and single generic syntax should denote the whole range of URI schemes.

* URI Characters are, in turn, frequently encoded as octets for transport or
  presentation.

* This specification does not mandate any character encoding for mapping
  between URI characters and the octets used to store or transmit those
  characters.

  pct-encoded = "%" HEXDIG HEXDIG

* For consistency, uri producers and normalizers should use uppercase
  hexadecimal digits, for all percent - encodings.

  reserved    = gen-delims / sub-delims

  gen-delims  = ":" / "/" / "?" / "#" / "[" / "]" / "@"

  sub-delims  = "!" / "$" / "&" / "'" / "(" / ")"
              / "*" / "+" / "," / ";" / "="


  unreserved  = ALPHA / DIGIT / "-" / "." / "_" / "~"

  When a new URI scheme defines a component that represents textual
  data consisting of characters from the Universal Character Set [UCS],
  the data should first be encoded as octets according to the UTF-8
  character encoding [STD63]; then only those octets that do not
  correspond to characters in the unreserved set should be percent-
  encoded.  For example, the character A would be represented as "A",
  the character LATIN CAPITAL LETTER A WITH GRAVE would be represented
  as "%C3%80", and the character KATAKANA LETTER A would be represented
  as "%E3%82%A2".

Section 2, was on encoding and decoding the characters in the url scheme. How
that is being used encoding reservered characters within data. Transmission of
url from local to public when using a different encoding - translate at the
interface level.

      URI         = scheme ":" hier-part [ "?" query ] [ "#" fragment ]

      hier-part   = "//" authority path-abempty
                  / path-absolute
                  / path-rootless
                  / path-empty

Many URI schemes include a hierarchical element for a naming
authority so that governance of the name space defined by the
remainder of the URI is delegated to that authority (which may, in
turn, delegate it further).

      userinfo    = \*( unreserved / pct-encoded / sub-delims / ":" )
      host        = IP-literal / IPv4address / reg-name

In order to disambiguate the syntax host between IPv4address and reg-name, we
apply the "first-match-wins" algorithm:

A host identified by an Internet Protocol literal address, version 6
[RFC3513] or later, is distinguished by enclosing the IP literal
within square brackets ("[" and "]").  This is the only place where
square bracket characters are allowed in the URI syntax.

      IP-literal = "[" ( IPv6address / IPvFuture  ) "]"

      IPvFuture  = "v" 1*HEXDIG "." 1*( unreserved / sub-delims / ":" )

      IPv6address =                            6( h16 ":" ) ls32
                  /                       "::" 5( h16 ":" ) ls32
                  / [               h16 ] "::" 4( h16 ":" ) ls32
                  / [ \*1( h16 ":" ) h16 ] "::" 3( h16 ":" ) ls32
                  / [ \*2( h16 ":" ) h16 ] "::" 2( h16 ":" ) ls32
                  / [ \*3( h16 ":" ) h16 ] "::"    h16 ":"   ls32
                  / [ \*4( h16 ":" ) h16 ] "::"              ls32
                  / [ \*5( h16 ":" ) h16 ] "::"              h16
                  / [ \*6( h16 ":" ) h16 ] "::"

      ls32        = ( h16 ":" h16 ) / IPv4address
                  ; least-significant 32 bits of address

      h16         = 1*4HEXDIG
                  ; 16 bits of address represented in hexadecimal

      IPv4address = dec-octet "." dec-octet "." dec-octet "." dec-octet

      dec-octet   = DIGIT                 ; 0-9
                  / %x31-39 DIGIT         ; 10-99
                  / "1" 2DIGIT            ; 100-199
                  / "2" %x30-34 DIGIT     ; 200-249
                  / "25" %x30-35          ; 250-255

      reg-name    = \*( unreserved / pct-encoded / sub-delims )

Non-ASCII characters must first be encoded according to UTF-8 [STD63], and then
each octet of the corresponding UTF-8 sequence must be percent- encoded to be
represented as URI characters. 

When a non-ASCII registered name represents an internationalized domain name
intended for resolution via the DNS, the name must be transformed to the IDNA
encoding [RFC3490] prior to name lookup. 

Section 3 was about sub-components and their structure and if they are
represented in NON ASCII how to go about with encoding/decoding that.

      path          = path-abempty    ; begins with "/" or is empty
                    / path-absolute   ; begins with "/" but not "//"
                    / path-noscheme   ; begins with a non-colon segment
                    / path-rootless   ; begins with a segment
                    / path-empty      ; zero characters

      path-abempty  = \*( "/" segment )
      path-absolute = "/" [ segment-nz \*( "/" segment ) ]
      path-noscheme = segment-nz-nc \*( "/" segment )
      path-rootless = segment-nz \*( "/" segment )
      path-empty    = 0<pchar>
      segment       = \*pchar
      segment-nz    = 1\*pchar
      segment-nz-nc = 1\*( unreserved / pct-encoded / sub-delims / "@" ) ; non-zero-length segment without any colon ":"

      pchar         = unreserved / pct-encoded / sub-delims / ":" / "@"

      relative-ref  = relative-part [ "?" query ] [ "#" fragment ]

      relative-part = "//" authority path-abempty
                    / path-absolute
                    / path-noscheme
                    / path-empty

Section 4 was on the usage aspects and heuristics used in determining in the
scheme in the normal usages where scheme is not given. 

Base uri must be stripped of any fragment components prior to it being used as
a Base URI.

Section 5 was on relative reference implementation algorithm. I had covered
them practically in the Python urlparse module.

Section 6 was on Normalization of URIs for comparision and various
normalization practices that are used.


Use of namedtuple in py3k branch for urlparse.
----------------------------------------------

Dissecting urlparse:

1) __all__ methods provides the public interfaces to all the methods like
urlparse, urlunparse, urljoin, urldefrag, urlsplit and urlunsplit.

2) then there is classification of schemes like uses_relative, uses_netloc,
non_hierarchical, uses_params, uses_query, uses_fragment

* there should be defined in an rfc most probably 1808.
* there is a special '' blank string, in certain classifications, which means
  that apply by default.

3)valid characters in scheme name should be defined in 1808.

4) class ResultMixin is defined to provide username, password, hostname and
port.

5) from collections import namedtuple. This should be from python2.6.
namedtuple is pretty interesting feature. 

6) SplitResult and ParseResult. Very good use of namedtuple and ResultMixin

7) The behaviour of the public methods urlparse, urlunparse, urlsplit and
urlunsplit and urldefrag matter most.

urlparse - scheme, netloc, path, params, query and fragment.
urlunparse will take those parameters and construct the url back.

urlsplit - scheme, netloc, path, query and fragment.
urlunsplit - takes these parameters (scheme, netloc, path, query and fragment)
and returns a url.

urlparse x urlunparse
urlsplit x urlunsplit
urldefrag
urljoin

::

	Changes to urlsplit functionality in urllib.
	As per the RFC3986, the url is split into:
		scheme, authority, path, query, frag = url

	The authority part in turn can be split into the sections:
		user, passwd, host, port = authority

	The following line is the regular expression for breaking-down a
	well-formed URI reference into its components.	

	^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?
     12            3  4          5       6  7        8 9

      scheme    = $2
      authority = $4
      path      = $5
      query     = $7
      fragment  = $9

	The urlsplit functionality in the urllib can be moved to new regular
	expression based parsing mechanism.


From man uri, which confirms to rfc2396 and HTML 4.0 specs.

- An absolute identifier refers to a resource independent of context, while a
  relative identifier refers to a resource by describing the difference from
  the current context.

- A path segment while contains a colon character ':' can't be used as the
  first segment of a relative URI path. Use it like this './file:path'

- A query can be given in the archaic "isindex" format, consisting of a word or
  a phrase and not including an equal sign (=). If = is there, then it must be
  after & like &key=value format.

Character Encodings:

- Reserved characters: ;/?:@&=+$,
- Unreserved characters: ALPHA, DIGITS, -_.!~*'()

An escaped octet is encoded as a character triplet consisting of the percent
character '%' followed by the two  hexadecimal digits representing the octet
code.

HTML 4.0 specification section B.2 recommends the following, which should be
considered best available current guidance:

1) Represent each non-ASCII character as UTF-8
2) Escape those bytes with the URI escaping mechanism, converting each byte to
   %HH where HH is the hexadecimal notation of the byte value.

One of the important changes when adhering to RFC3986 is parsing of IPv6
addresses.

----------------------------------------------------------------------

Having a construct like::

    def __init__(self, *args, **kwargs):
        BaseClass.__init__(self, *args, **kwargs)

But in the base class, I find that it is not taking the tuple and dict as
arguments.

I dont understand the 
assert(proxies, 'has_key'), "proxies must be mapping"

----------------------------------------------------------------------

* What is an addrinfo struct.

The getaddrinfo() function returns a list of 5-tuples with the following structure:
(family, socktype, proto, canonname, sockaddr)

family, socktype, proto are all integer and are meant to be passed to the
socket() function. canonname is a string representing the canonical name of the
host. It can be a numeric IPv4/v6 address when AI_CANONNAME is specified for a
numeric host. 

socket.gethostbyname(hostname)

    Translate a host name to IPv4 address format. The IPv4 address is returned
    as a string, such as '100.50.200.5'. If the host name is an IPv4 address
    itself it is returned unchanged. See gethostbyname_ex() for a more complete
    interface. gethostbyname() does not support IPv6 name resolution, and
    getaddrinfo() should be used instead for IPv4/v6 dual stack support.


We need to replace the gethostbyname socket call. Because it is only IPv4
specific. using the getaddrinfo() function can include the IPv4/v6 dual stack
support.::

    import socket
    print socket.gethostbyname(hostname)

    def gethostbyname(hostname)
        family, socktype, proto, canonname, sockaddr = socket.getaddrinfo(hostname)
        return canonname

----------------------------------------------------------------------

Compare dates for cache control

RFC 1123 date format:
Thu, 01 Dec 1994 16:00:00 GMT

::

    >>> datereturned = "Thu, 01 Dec 1994 16:00:00 GMT"
    >>> dateexpired = "Sun, 05 Aug 2007 03:25:42 GMT"
    >>> obj1 = datetime.datetime(*time.strptime(datereturned, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
    >>> obj2 = datetime.datetime(*time.strptime(dateexpired, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
    >>> if obj1 == obj2:
        print "Equal"
    elif obj1 > obj2:
        print datereturned
    elif obj1 < obj2:
        print dateexpired

Now you can compare the headers for expiry in cache control.

Header field definition:
http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html

Adding Header information to Apache:
http://webmaster.info.aol.com/apache.html

To add header:
Go to the /etc/httpd/conf/httpd.conf
For e.g:
Add the information on headers
Header set Author "Senthil"

Q) Question is can I add a test for cache.
A) Its not a functionality, but its merely an internal optimization.

Q) If test for cache needs to be written, how will you write it?
A) request an url and redirect and request it again and verify that it is
coming frm a dictionary or the dictionary value is stored.

::

    from_url = "http://example.com/a.html"
    to_url = "http://example.com/b.html"

    h = urllib2.HTTPRedirectHandler()
    o = h.parent = MockOpener()
    req = Request(from_url, origin_req_host="example.com")
    count = 0
    try:
        while 1:
            redirect(h, req, "http://example.com")
            count = count + 1
            if count > 2:
                self.assertEqual("http://example.com",
                urllib2.HTTPRedirectHandler().cache[req].geturl())
    except urllib2.HTTPError:
        self.assertEqual(count, urllib2.HTTPRedirectHandler.max_repeats)	

CacheFTPHandler testcasesare hard to write.

Playing the competition requires to have solved the similar problem a couple of
times earlier.

Header field definition:
http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html

To add header:
Go to the /etc/httpd/conf/httpd.conf
For e.g:
Add the information on headers
Header set Author "Senthil"

Key difference between HTTP 1.0 and HTTP 1.1
--------------------------------------------

Inspite of it's success, HTTP 1.0 is widely understood of have numerous flaws.
HTTP 1.0 evolved from the original 0.9 version. HTTP 1.0 has never been
formally specified.

Over a period of 4 years, the HTTP working group developed a improved protocol
called HTTP 1.1 - When was it started? 

HTTP 1.1 - the IEFT Internet draft standard.
Recent versions of popular agents claim HTTP 1.1 support.

HTTP 1.1 states the various requirements for clients, proxies and servers.
However, additional context or the rationales for the changed features can help
developers understand the motivation behind the changes, and provide them with
the richer understanding of the protocol.

Additionally, these rationales can give implementors a broader feel for the
pros and cons of the indiviual features.

Major changes between the HTTP 1.0 and HTTP 1.1 protocols.

RFC 1945 is the HTTP 1.0 spec.
Numerous rules are implied by HTTP 1.1 spec rather than being stated.

Extesibility
Caching
Bandwith Optimization
Network connection management
Message transmission.
Internet address conservation.
Error notification
Security, Integrity and Authenticity
Content Negotiation

HTTP 1.1 effort assumed, from the outset, that compatiblity with the installed base of HTTP implementation.
HTTP has always specified that if an implementation receives a header that it does not understand, it must ignore the header.
Version number in an HTTP message can be used to deduce the capabilities of the sender.

The version number in an HTTP message refers to the hop-by-hop sender of the
message, not the end-to-end sender. Thus the message's version number is
directly useful in determining hop-by-hop message-level capabilities, but not
very useful in determining end-to-end capabilities. For example, if an HTTP/1.1
origin server receives a message forwarded by an HTTP/1.1 proxy, it cannot tell
from that message whether the ultimate client uses HTTP/1.0 or HTTP/1.1.

For this reason, as well as to support debugging, HTTP/1.1 defines a Via header
that describes the path followed by a forwarded message. The path information
includes the HTTP version numbers of all senders along the path and is recorded
by each successive recipient.

The OPTIONS method

HTTP/1.1 introduces the OPTIONS method, a way for a client to learn about the
capabilities of a server without actually requesting a resource. For example, a
proxy can verify that the server complies with a specific version of the
protocol. 
protocol.


Browsers
--------

The location of the resource is specified by the User using a URI.
The rendering engine will start getting the contents from Networking layer.
This is usually done in 8k chunks.
Parsing the HTML to construct the DOM tree.
Render Tree construction.
Layout of the Render Tree.
Painting the Render Tree.

Links
-----

* http://stockrt.github.com/p/emulating-a-browser-in-python-with-mechanize/


