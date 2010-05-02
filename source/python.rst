============
Python Notes
============

.. warning:: 
        Rough Notes.

TODO
====

* study diveintopython3 (20)
* use of namedtuple in py3k branch for urlparse.
* Digest Authentication is not working.
* Classic Classes and new-style classes.
* Complete the forms for PyCon payment.

* Email Module work is in progress where the discussions are going on for the
  different types and type of support for Internal and External APIs and the
  way to handle text and binary data.


* http://ffwl.unfuddle.com/  username is orsenthil and password is your initials.
 

Python bugs
-----------

Tests needing network flag?
http://bugs.python.org/issue1659


BaseHTTPServer incorrectly implements response code 100
http://bugs.python.org/issue1491

urllib(2) should allow automatic decoding by charset

http://bugs.python.org/issue1599329

Add a "decode to declared encoding" version of urlopen to urllib
http://bugs.python.org/issue4733

issue1314572 Trailing slash redirection for SimpleHTTPServer

issue1462525 -  URI parsing library 
http://bugs.python.org/issue1462525

issue1643370 - recursive urlparse

issue1673007 - urllib2 requests history + HEAD support

issue1712522 -  urllib.quote throws exception on Unicode

issue1722 -  Undocumented urllib functions 

issue1755841 - Patch for [ 735515 ] urllib2 should cach 

issue2202 - urllib2 fails against IIS 6.0

[issue1229646] httplib error checking.
                                                                                                      
In Python3 the code for httplib changed:                                                              
Py3:                                                                                                  
http://svn.python.org/view/python/branches/py3k/Lib/http/client.py?view=markup#send                   
Py2: http://svn.python.org/view/python/trunk/Lib/httplib.py?view=markup#send                          
                                                                                                      
Does this still need to be fixed on Py2.7 (and maybe on Py3 too)?  

issue1027206 - unicode DNS names in socket, urllib, urlopen

issue8150 - urllib needs ability to set METHOD for HTTP requests

issue8143 - urlparse has a duplicate of urllib.unquote

issue2987 -  RFC2732 support for urlparse

issue3243 -  Support iterable bodies in httplib

issue3244 -  multipart/form-data encoding

issue4758 -  Python 3.x internet documentation needs wor

issue5650 -  Obsolete RFC's should be removed from doc

issue5673 -  Add timeout option to subprocess.Popen

issue6280 -  calendar.timegm() belongs in time module

issue6312 -  httplib fails with HEAD requests to pages

issue6500 -  urllib2 maximum recursion depth exceeded  (1)

issue6520 -  urllib.urlopen does not have timeout parame

issue1208304 - urllib2's urlopen() method causes a memor

issue6631    -  urlparse.urlunsplit() can't handle relative

issue6640    -  urlparse should parse mailto: URL headers as

issue7150    -  datetime operations spanning MINYEAR give b

issue7152    -  urllib2.build_opener() skips ProxyHandler

issue7159    -  Urllib2 authentication memory

issue7291    -  urllib2 cannot handle https with proxy requ 

issue7305    -  urllib2.urlopen() segfault using SSL on Solaris

issue7464    -  circular reference in HTTPResponse by urllib

issue7620    -  Vim syntax highlight 

issue7648    -  test_urllib2 fails on Windows if not run from

issue7665    -  test_urllib2 fails if path contains "\"

issue7668    -  test_httpservers fails with non-ascii path

issue7776    -  httplib.py: ._tunnel() broken

issue7806    -  httplib.HTTPConnection.getresponse closes s

issue8083    -  urllib proxy interface is too limited

issue8095    -  test_urllib2 crashes on OS X 10.3

issue8077    -  cgi handling of POSTed files is broken

print as a function in python3.
New string model
classic class vs new style class and everything is new style class.
Updated Syntax for Exceptions
Improved Exception Handling Mechanism,
Chaging the Division Operator.
True Division PEP 238
New Binary Literals, bin, oct and hex
Dictionary methods PEP 3106
Type Updates and io class ( PEP 3116)
Dictionary Comprehensions
set comprehensions
tuple methods - count and index.
Changes to reserved keywords.
removed - print and exec
added - as, with, nonlocal, True and False

Changes to Operators.
Removed <> and backticks
Added - bytes, bytearray and range
Removed - basestring, buffer, file, long, unicode and xrange

use of 2to3 tool.

Python 2.6 status and Python 2.7 plan.
Python 3.1 status and further plans.


        
urllib 
======

functions
---------
* urlopen
* install_opener
* build_opener
* request_host
* _parse_proxy
* randombytes
* parse_keqv_list
* parse_http_list

class
-----
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

RFC Hierarchy for Relative URL formats

:: 

        RFC3986(STD066) - This is the current and is the standard.
        |
        RFC2396 - This was previous one.
        |
        RFC2368
        |
        RFC1808 - urlparse header says, it follows this. But this has been upgraded a lot times.
        |
        RFC1738 - It started with this. 

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
turn, delegate it further).

:: 
        userinfo = *( unreserved / pct-encoded / sub-delims / ":" )
        host = IP-literal / IPv4address / reg-name

In order to disambiguate the syntax host between IPv4address and reg-name, we
apply the "first-match-wins" algorithm. A host identified by an Internet
Protocol literal address, version 6 [RFC3513] or later, is distinguished by
enclosing the IP literal within square brackets ("[" and "]"). This is the only
place where square bracket characters are allowed in the URI syntax.

::
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
represented in NON ASCII how to go about with encoding/decoding that.

::

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

Dissecting urlparse:
--------------------

* __all__ methods provides the public interfaces to all the methods like
urlparse, urlunparse, urljoin, urldefrag, urlsplit and urlunsplit.

* then there is classification of schemes like uses_relative, uses_netloc,
non_hierarchical, uses_params, uses_query, uses_fragment

- there should be defined in an rfc most probably 1808.

- there is a special '' blank string, in certain classifications, which
means that apply by default.

* valid characters in scheme name should be defined in 1808.

* class ResultMixin is defined to provide username, password, hostname and
port.

* from collections import namedtuple. This should be from python2.6.
namedtuple is pretty interesting feature.

* SplitResult and ParseResult. Very good use of namedtuple and ResultMixin

* The behaviour of the public methods urlparse, urlunparse, urlsplit and
urlunsplit and urldefrag matter most.

urlparse - scheme, netloc, path, params, query and fragment.
urlunparse will take those parameters and construct the url back.

urlsplit - scheme, netloc, path, query and fragment.
urlunsplit - takes these parameters (scheme, netloc, path, query and fragment)
and returns a url.

As per the RFC3986, the url is split into: 

scheme, authority, path, query, frag = url

The authority part in turn can be split into the sections:
user, passwd, host, port = authority

The following line is the regular expression for breaking-down a
well-formed URI reference into its components.

:: 

        ^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?
        12 3 4 5 6 7 8 9

        scheme = $2
        authority = $4
        path = $5
        query = $7
        fragment = $9


The urlsplit functionality in the urllib can be moved to new regular
expression based parsing mechanism.

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

1) There is an url with two '//'s in the path.
2) The call is data = urllib2.urlopen(url).read()
3) urlopen calls the build_opener. build_opener builds the opener using (tuple)
of handlers.
4) opener is an instance of OpenerDirector() and has default HTTPHandler and
HTTPSHandler.
5) When the Request call is made and the request has 'http' protocol, then
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


Strings, Bytes and Python 3
===========================

Q: Convert a Hexadecimal Strings ("FF","FFFF") to Decimal
A: int("FF",16) and int("FFFF",16)

Q: Represent 255 in Hexadecimal.
A: print '%X' % 255

If you want to encode a string in base16, base32 or base64 encoding, the python
standard library provides base64 module which is based on the RFC 3564.

What is the difference between string, bytes and buffer?

In Python 2.0, the normal strings were of 8 bit characters and for representing
Characters from foreign languages, a special kind of class was provided, which
was called Unicode String.

The string object when they had to be stored or transfered over the wire, they
had to be encoded into bytes. As normal string character was 8 bits, they
directly corresponded to one byte and Python2.0 had an implicit ascii encoding
which conveniently encoded them to 8-bit bytes.  The Unicode object had to have
an encoding specified, which encoded the unicoded strings into sequence of
bytes.

Just as string object had an encode method, to convert to bytes, the bytes
object had a decode method, that takes a character encoding an returns a
string.

In Python 3.0, the normal string was made the Unicode String. However, the 8bit
character datatype was still retained and it was called as bytes.

In other words. Python2.6 supports both simple text and binary data in its
normal string type and provides an alternative string type for non-ASCII type
called the Unicode text. Whereas Python3.0 supports Unicode text in its normal
string type, with ASCII being treated a simple type of unicode and provides an
alternative string type for binary data called bytes.

What is the difference between linefeed and a newline?
newline is composed of Linefeed character. 

What is class bytearray?

A Byte is 8 bits and array is a sequence. A Bytearray object can be constructed
using integers only or text string along with an encoding or using another
bytes or bytearray or any other object implementing a buffer API. More
importantly, it is mutable.

Python3 comes with 3 types of string objects, one for textual data and two for
binary data.

 * str - for representing Unicode text.
 * bytes - for representing Binary data.
 * bytearray - a mutable flavor of bytes type.

3.0 str type defined an immutable sequence of characters (not neccesarily
bytes), which may be either normal text such as ASCII or multi byte UTF-8.  A
new type called bytes was introduced to support truly binary data.

In 2.x; the general string type filled this binary data role, because strings
were just a sequence of bytes. In 3.0, the bytes type is defined as an
immutable sequence of 8-bit integers representing absolute byte values.  A 3.0
bytes object really is a sequence of small integers, each of which is in the
range 0 through 255; indexing a bytes returns int, slicing one returns another
bytes and running list() on one returns a list of integers, not characters.
While they were at it, the Python developers also added bytearray type in 3.0,
a variant of bytes, which is mutable and also supports in-place changes. The
bytearray type supports the usual string operations that str and bytes do, but
has inplace change operations also.

Because str and bytes are sharply differentiated by the language, the net
effect is that you must decide whether your data is text or binary in nature
and use 'str' or 'bytes' objects to represent its content in your script
respectively.

Image or audio file or packed data processed with the struct module is an
exmaple of bytes object. Python3.0 has a sharp distinction between text, binary
data and files.

::
        $ python
        Python 2.6.2 (release26-maint, Apr 19 2009, 01:58:18) [GCC 4.3.3] on linux2
        >>> import sys
        >>> print sys.getdefaultencoding()
        ascii
        >>> 
        07:56 PM:senthil@:~/uthcode/source
        $ python3.1
        Python 3.1a2+ (py3k:71811, Apr 22 2009, 20:47:22) [GCC 4.3.2] on linux2
        >>> import sys
        >>> print(sys.getdefaultencoding())
        utf-8
        >>> 

Ultimately, the mode in which you open a file will dictate which type of object
your script will use to represent its contents.

 * bytes or binary mode files.
 * bytearray to update data without making copies of it in memory.
 * If you are processing something that is textual in nature, such as program
   output, HTML, internationalized text, and CSV or XML files, you probably
   want to use str or text mode files.


Unicode Notes
=============

A good introductory document for getting started with Unicode is, 
`Joel's article on Unicode`_

Trivia:
In ASCII when you press CNTL, you subtract 64 from the value of the next
character.  So BELL is ASCII 7, which is CNTL+G, (CNTL is 64) and G is 71.

IN ASCII, the Codes below 32 were called unprintable. The space was 32 and
letter A was 65.  This could conveniently be stored in 7 bits.  Most computers
in those days were using 8 bit bytes, so not only you could store all the ASCII
characters, you had a whole bit to spare.  Because bytes have room for upto
eight bits, lots of people got into thinking, "gosh, we can use codes 128-255
for our own purposes." :) Eventually, this OEM free-for-all got codified in the
ANSI standard.  In the ANSI standard, everyone agreed for bottom 128 but not
the upper limits.  Asian alphabets have thousands of letters, which were never
going to fit into 8 bits.  This was actually solved by a messy system called
DBCS, the "double byte character set" in which some letters were stored in one
byte and others took two bytes.It was easy to move forward in a string, but it
was impossible to move backwards in the string.  Programmers were encouraged
not to use s++ or s-- but instead rely on Windows' AnsiNext and AnsiPrev
functions which knew how to deal with that mess.

Unicode

Unicode was a brave effort to create a single character set that included every
reasonable writing system on the planet.  Some people are under the
mis-conception that unicode is simply a 16-bit code where each character takes
16 bits and therefore there are 65,536 possible characters, which is incorrect.

In Unicode, every alphabet is assigned a magic number by the Unicode consortium
which is written like this: U+0639. This number is called the code-point. The
U+ means "Unicode" and the numbers are in hexadecimal notation. U+0639 is the
arabic letter Ain (ع).

There is no real limit on the number of letters that Unicode can define and in
fact, they have gone beyond 65,536 so not every unicode letter can really be
squeezed into two bytes. That was a myth anyways.

OK, so we have a string: Hello which, in Unicode, corresponds to these five
code-points: U+0048 U+0065 U+006C U+006C U+006F 

It was U- before 3.0 and then it became U+. If you look at the release notes of
Unicode 3.0, you might find the reason for the change.

How do we store those numbers?  That is where encoding comes in.

The earliest idea was, that to store the numbers in two bytes each:

	00 48 00 65 00 6C 00 6C 00 6F.

Why not it be stored like this:

	48 00 65 00 6C 00 6C 00 6F 00

Well, it could be stored in that way too. Early implementors wanted to store
the numbers in either big-endian or little-endian, in whichever way their
particular CPU  was fastest at...  So, people came up with Byte Order Mark,
where FEFF denoted Little Endian and FFFE denoted big endian.

FEFF - Little Endian
FFFE - Big Endian

Feel for Little Endian (FE for Little Endian and its opposite for Big Endian)

For a while, it seemed like that might be good enough, but programmers were
complaining. "Look at all those zeros!", they said, since they were Americans
and they were looking at English text which rarely used code points above
U+OOFF.  People decided to ignore Unicode and things got worse.  And thus was
invented the brilliant concept of UTF-8. (Read Rob Pike's mail)

In UTF-8, every code point from 0-127 is stored in a single byte. Only code
points 128 and above are stored using 2, 3, in fact upto 6 bytes.  This has the
neat side-effect that English text looks exactly the same in UTF-8 as it did in
ASCII, so Americans don't even notice anything wrong.  Specifically, Hello
which was "0048, 0065, 006C, 006C and 006F" would simply be stored as
48,65,6C,6C and 6F.

So, here we have ways such as UCS-2 (UTF-16), which had its own UCS-2 little
endian or UCS-2 big endian and then UTF-8 encoding method.  There are also a
bunch of other ways of encoding Unicode. There is something called UTF-7, which
is lot like UTF-8 but guarantees that the high bit will always be zero.  It was
for systems which can recognize only 7 bits. UCS-4 which stores each code point
in 4 bytes, which has a nice property that every single code point can be
stored in same number of bytes. But that is memory hungry.

There are hundreds of traditional encodings, which can only store some
code-points correctly and change all other code points into question marks.
Some popular encodings of the English text are, Windows 1252 and ISO-8859-1,
aka Latin-1 (also useful for any western european languages). But try to store
Russian, or Hebrew letters in those encodings and you will get a bunch of
question marks. UTF 7, UTF 8, UTF 16 and UTF 32 all have the nice property of
being able to store any code point correctly.

If you have a string in memory, in a file, or in an email message, you have to
know what encoding it is in or you cannot interpret it or display to your users
correctly.  All the problems of ????, comes down to the fact that if you don't
tell me whether a particular string is encoded using UTF-8 or ASCII or ISO
8859-1 (Latin 1) or Western 1252 (Western European), you simply cannot display
it correctly or even figure it out where it actually ends.  There are over 100
encodings, and above code point 127, all the bets are off.

How do we preserve this information about what encoding a string uses?  Email,
Content-Type: text/plain; charset="UTF-8" For a web page, the original idea was
that the web server would return a similar Content-Type http header along with
the web page itself -- not in the HTML itself, but as one of the response
headers that are sent before the HTML page.

Relying on webserver to send Content-Type was problematic, because many
different people could use the same web-server for different types of web
pages.  It would be convenient, if you could put the Content-Type of the HTML
file right in the HTML file itself, using some kind of a special tag.  All
encoding uses same character between 32 and 127, so you could get to the point
wherein you could read the <meta> header.

The RFC which explains UTF-8

::
        http://www.ietf.org/rfc/rfc3629.txt

        The most interesting part of the RFC, which is leading me to understand the
        system better is explained here:

           The table below summarizes the format of these different octet types.
           The letter x indicates bits available for encoding bits of the
           character number.

           Char. number range  |        UTF-8 octet sequence
              (hexadecimal)    |              (binary)
           --------------------+---------------------------------------------
           0000 0000-0000 007F | 0xxxxxxx
           0000 0080-0000 07FF | 110xxxxx 10xxxxxx
           0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
           0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

           Encoding a character to UTF-8 proceeds as follows:

           1.  Determine the number of octets required from the character number
               and the first column of the table above.  It is important to note
               that the rows of the table are mutually exclusive, i.e., there is
               only one valid way to encode a given character.

           2.  Prepare the high-order bits of the octets as per the second
               column of the table.

           3.  Fill in the bits marked x from the bits of the character number,
               expressed in binary.  Start by putting the lowest-order bit of
               the character number in the lowest-order position of the last
               octet of the sequence, then put the next higher-order bit of the
               character number in the next higher-order position of that octet,
               etc.  When the x bits of the last octet are filled in, move on to
               the next to last octet, then to the preceding one, etc. until all
               x bits are filled in.

           The definition of UTF-8 prohibits encoding character numbers between
           U+D800 and U+DFFF, which are reserved for use with the UTF-16
           encoding form (as surrogate pairs) and do not directly represent
           characters.  When encoding in UTF-8 from UTF-16 data, it is necessary
           to first decode the UTF-16 data to obtain character numbers, which
           are then encoded in UTF-8 as described above.  This contrasts with
           CESU-8 [CESU-8], which is a UTF-8-like encoding that is not meant for
           use on the Internet.  CESU-8 operates similarly to UTF-8 but encodes
           the UTF-16 code values (16-bit quantities) instead of the character
           number (code point).  This leads to different results for character
           numbers above 0xFFFF; the CESU-8 encoding of those characters is NOT
           valid UTF-8.

           Decoding a UTF-8 character proceeds as follows:

           1.  Initialize a binary number with all bits set to 0.  Up to 21 bits
               may be needed.

           2.  Determine which bits encode the character number from the number
               of octets in the sequence and the second column of the table
               above (the bits marked x).

           3.  Distribute the bits from the sequence to the binary number, first
               the lower-order bits from the last octet of the sequence and
               proceeding to the left until no x bits are left.  The binary
               number is now equal to the character number.

           Implementations of the decoding algorithm above MUST protect against
           decoding invalid sequences.  For instance, a naive implementation may
           decode the overlong UTF-8 sequence C0 80 into the character U+0000,
           or the surrogate pair ED A1 8C ED BE B4 into U+233B4.  Decoding
           invalid sequences may have security consequences or cause other
           problems.  See Security Considerations (Section 10) below.

        4.  Syntax of UTF-8 Byte Sequences

           For the convenience of implementors using ABNF, a definition of UTF-8
           in ABNF syntax is given here.

           A UTF-8 string is a sequence of octets representing a sequence of UCS
           characters.  An octet sequence is valid UTF-8 only if it matches the
           following syntax, which is derived from the rules for encoding UTF-8
           and is expressed in the ABNF of [RFC2234].

           UTF8-octets = *( UTF8-char )
           UTF8-char   = UTF8-1 / UTF8-2 / UTF8-3 / UTF8-4
           UTF8-1      = %x00-7F
           UTF8-2      = %xC2-DF UTF8-tail
           UTF8-3      = %xE0 %xA0-BF UTF8-tail / %xE1-EC 2( UTF8-tail ) /
                         %xED %x80-9F UTF8-tail / %xEE-EF 2( UTF8-tail )
           UTF8-4      = %xF0 %x90-BF 2( UTF8-tail ) / %xF1-F3 3( UTF8-tail ) /
                         %xF4 %x80-8F 2( UTF8-tail )
           UTF8-tail   = %x80-BF

           NOTE -- The authoritative definition of UTF-8 is in [UNICODE].  This
           grammar is believed to describe the same thing Unicode describes, but
           does not claim to be authoritative.  Implementors are urged to rely
           on the authoritative source, rather than on this ABNF.


The official name of the encoding is UTF-8, where UTF stands for UCS
Transformation Format 8.  Write it as UTF-8 only.

So there is no limit on the number of the characters that Unicode could define.
So, it has definiely exceeded beyond, 65536 characters.

Exercise 1:
Convert the following to Unicode:
1) "Hello, World"
2) à¤¨à¤®à¤¸à¥à¤à¤¾à¤° à¤¦à¥à¤¨à¤¿à¤¯à¤¾ 

Answer:
1)"Hello, World" is present in U0000 and 
U+0048 U+0065 U+006C U+006C U+006F U+002C U+0057 U+006F U+0072 U+006C U+0064

2) à¤¨à¤®à¤¸à¥à¤à¤¾à¤° à¤¦à¥à¤¨à¤¿à¤¯à¤¾
is the devnagari script that starts with U0900 
U+0928 U+092E U+0938 U+0942 U+0915 U+090 U+0930 U+0926 U+0941 U+0928 U+092F U+093F U+0965

The above was just a bunch of code points. We have not said anything about how
to store them in memory or represent them in email messages yet.

Encodings

English meaning of encoding is is wrapping it in a cipher code.  The earlier
method was to store those codepoints which are 4 hexadecimal digits as 2 bytes.
1 hexa digit can be written in 4 bits, 2 hexa digits can be written in 8 bits
which is 1 byte and so 4 hexa digits can be written in 2 bytes.

Convert Unicode to Hexadecimals.
Excellent tutorial.
http://ln.hixie.ch/?start=1064324988&count=1

Typing Unicode and maths symbols on gnome-terminal

1) Hold CTRL+SHIFT + U + codepoint + SPACE
2) For e.g. CTRL+SHIFT+U+2201+SPACE will give Unicode Maths Symbol 

Unicode code point chart:
http://inamidst.com/stuff/unidata/

What is Global Interpretor Lock?
================================

Global Interpretor lock is used to protect the Python Objects from being
modified by multiple threads at once. To keep multiple threads running, the
interpretor automatically releases and reaquires the lock at regular intervals.
It also does this around potentially slow or blocking low level operations,
such a file and network I/O.  This is used internally to ensure that only one
thread runs in the Python VM at a time. Python offers to switch amongst threads
only between bytecode instructions. Each bytecode instruction and all C
implemented function is atomic from Python program's point of view.

Different types of concurrency models
=====================================

* Java and C# uses shared memory concurrency model with locking provided by
  monitors. Message passing concurrency model have been implemented on top of
  the existing shared memory concurrency model.

* Erlang uses message passing concurrency model.

* Alice Extensions to Standard ML supports concurrency via Futures.

* Cilk is concurrent C.

* The Actor Model.

* Petri Net Model.

Some History of Inter Process Communication
===========================================

By the early 60s computer control software had evolved from Monitor control
software, e.g., IBSYS, to Executive control software. Computers got "faster"
and computer time was still neither "cheap" nor fully used. It made
multiprogramming possible and necessary.

Multiprogramming means that several programs run "at the same time"
(concurrently). At first they ran on a single processor (i.e., uniprocessor)
and shared scarce resources. Multiprogramming is also basic form of
multiprocessing, a much broader term.

Programs consist of sequence of instruction for processor. Single processor can
run only one instruction at a time. Therefore it is impossible to run more
programs at the same time. Program might need some resource (input ...) which
has "big" delay. Program might start some slow operation (output to printer
...). This all leads to processor being "idle" (unused). To use processor at
all time the execution of such program was halted. At that point, a second (or
nth) program was started or restarted. User perceived that programs run "at the
same time" (hence the term, concurrent).

Shortly thereafter, the notion of a 'program' was expanded to the notion of an
'executing program and its context'. The concept of a process was born.

This became necessary with the invention of re-entrant code.  Threads came
somewhat later. However, with the advent of time-sharing; computer networks;
multiple-CPU, shared memory computers; etc., the old "multiprogramming" gave
way to true multitasking, multiprocessing and, later, multithreading.

Context Management Protocol support
:: 
        with bz2.BZ2File() as f:
                f.something()

Counter class in the collections module that behave like dictionary; but return
0 instead of {{{KeyError}}}.  There is a namedtuple class in python.

compileall module is a script which will compile all the .py files in the path
to .pyc files.  py_compile is module which does the actual byte compilation.

py_compile.compile(fullname, None, dfile, True)

inspect module.

turtle module is a good one to get started with Python. turtle modle is updated
to 1.1 by Gregor Lingl. I promised to write a tutorial on turtle module. This
is pending.

How can we differentiate if an expression used is a general expression or a
boolean expression.

Having a construct like:

::

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


Now you can compare the headers for expiry in cache control.

Header field definition:
http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html

To add header:
Go to the /etc/httpd/conf/httpd.conf
For e.g:
Add the information on headers
Header set Author "Senthil"

Why do YOU like Python?
-----------------------

 * Python enables programs to be written compactly and readably.
 * Strongly typed and a Dynamic Language.
 * Why settle for snake oil, when you can have the whole snake? _Usenet post by Mark Jackson, 1998 and also mentioned on top of python-dev page!_

Language Feature: Source code encoding
--------------------------------------

 * With that declaration, all characters in the source file will be treated as having the encoding *encoding*, and it will be possible to directly write Unicode string literals in the selected encoding.
 * The list of possible encodings can be found in the Python Library Reference, in the section on 
[http://docs.python.org/library/codecs.html#module-codecs codecs]
* By using UTF-8, most languages in the world can be used simultaneously in string literals and the comments.


Language Feature: Unicode
-------------------------

 * Starting with Python 2.0 a new data type for storing text data is available to the programmer: the Unicode object.  _>>> u'Hello World !'_
 * Python unicode escape encoding: _>>> u'Hello\u0020World !'_
 * built-in function unicode() , default encoding is ASCII
 * To convert unicode to a 8-bit string using a specified encoding.

::
        >>> u"Ã¤Ã¶Ã¼".encode('utf-8')
        '\xc3\xa4\xc3\xb6\xc3\xbc'


 * From a data in a specific encoding to a unicode string.

::
        >>> unicode('\xc3\xa4\xc3\xb6\xc3\xbc', 'utf-8')
        u'\xe4\xf6\xfc'


Language Feature: Unicode

* understanding unicode is easy, when we accept the need to explicitly convert
  between the bytestring and unicode string.

* More examples:

   german_ae = unicode('\xc3\xa4','utf8')

::
        >>> german_ae = unicode("\xc3\xa4",'utf8')
        >>> sentence = "this is a " + german_ae
        >>> sentece2 = "Easy!"
        >>> sentence2 = "Easy!"
        >>> para = ".".join([sentence, sentence2])
        >>> para
        u'this is a \xe4.Easy!'
        >>> print para
        this is a ä.Easy!
        >>> 

* Without an encoding, the bytestring is essentially meaningless. 
* The default encoding assumed by Python is ASCII


Python Specialities: else clauses on loops 
------------------------------------------

* Loop statements may have an else clause; 
* It is executed when the loop terminates through exhaustion of the list (with for).
* Or when the condition becomes false (with while), 
* But not when the loop is terminated by a break statement.

::
        >>> for n in range(2, 10):
        ...     for x in range(2, n):
        ...         if n % x == 0:
        ...             print n, 'equals', x, '*', n/x
        ...             break
        ...     else:
        ...         # loop fell through without finding a factor
        ...         print n, 'is a prime number'
        ...
        2 is a prime number
        3 is a prime number
        4 equals 2 * 2
        5 is a prime number
        6 equals 2 * 3
        7 is a prime number
        8 equals 2 * 4
        9 equals 3 * 3

Control Flow: function execution
--------------------------------

The execution of a function introduces a new symbol table used for the local
variables of the function. More precisely, all variable assignments in a
function store the value in the local symbol table; whereas variable references
first look in the local symbol table, then in the local symbol tables of
enclosing functions, then in the global symbol table, and finally in the table
of built-in names. Thus, global variables cannot be directly assigned a value
within a function (unless named in a global statement), although they may be
referenced.

The actual parameters (arguments) to a function call are introduced in the
local symbol table of the called function when it is called; thus, arguments
are passed using call by value (where the value is always an object reference,
not the value of the object). [1] When a function calls another function, a new
local symbol table is created for that call.

A function definition introduces the function name in the current symbol table.
The value of the function name has a type that is recognized by the interpreter
as a user-defined function. This value can be assigned to another name which
can then also be used as a function.

Control Flow: functions
-----------------------

* What is the output?

:: 
        i = 5

        def f(arg=i):
            print arg

        i = 6
        f()


        def f(a, L=[]):
            L.append(a)
            return L

        print f(1)
        print f(2)
        print f(3)

* first one will print 5, because default values are evaluated at the point of
  function definition in the defining scope.

* The default value is evaluated only once. This makes a difference when the
  default value is a mutatable object. In order to prevent argument sharing.

::
          def f(a, L=None):
            if L is None:
                L = []
            L.append(a)
            return L

Data Structures: Functional Programming Tools 
---------------------------------------------

* There are three built-in functions that are very useful when used with lists:
  filter(), map() and reduce()
* filter(function, sequence)
* map(function, sequence)
* More than one sequence may be passed; the function must then have as many
  arguments as there are sequences and is called with the corresponding item
  from each sequence. 
* reduce(function, sequence)
* function in reduce is a binary function

::

        >>> def f(x): return x % 2 != 0 and x % 3 != 0
        ...
        >>> filter(f, range(2, 25))
        [5, 7, 11, 13, 17, 19, 23]

        >>> def cube(x): return x*x*x
        ...
        >>> map(cube, range(1, 11))
        [1, 8, 27, 64, 125, 216, 343, 512, 729, 1000]

        >>> seq = range(8)
        >>> def add(x, y): return x+y
        ...
        >>> map(add, seq, seq)
        [0, 2, 4, 6, 8, 10, 12, 14]

        >>> def sum(seq):
        ...     def add(x,y): return x+y
        ...     return reduce(add, seq, 0)
        ...
        >>> sum(range(1, 11))
        55
        >>> sum([])
        0

Data Structures: List comprehensions 
------------------------------------

* Each list comprehension consists of an expression followed by a for clause, then zero or more for or if clauses.
* If the expression would evaluate to a tuple, it must be parenthesized.


::

        >>> freshfruit = ['  banana', '  loganberry ', 'passion fruit  ']
        >>> [weapon.strip() for weapon in freshfruit]
        ['banana', 'loganberry', 'passion fruit']
        >>> vec = [2, 4, 6]
        >>> [3*x for x in vec]
        [6, 12, 18]
        >>> [3*x for x in vec if x > 3]
        [12, 18]
        >>> [3*x for x in vec if x < 2]
        []
        >>> [[x,x**2] for x in vec]
        [[2, 4], [4, 16], [6, 36]]
        >>> [x, x**2 for x in vec]  # error - parens required for tuples
          File "<stdin>", line 1, in ?
            [x, x**2 for x in vec]
                       ^
        SyntaxError: invalid syntax
        >>> [(x, x**2) for x in vec]
        [(2, 4), (4, 16), (6, 36)]
        >>> vec1 = [2, 4, 6]
        >>> vec2 = [4, 3, -9]
        >>> [x*y for x in vec1 for y in vec2]
        [8, 6, -18, 16, 12, -36, 24, 18, -54]
        >>> [x+y for x in vec1 for y in vec2]
        [6, 5, -7, 8, 7, -5, 10, 9, -3]
        >>> [vec1[i]*vec2[i] for i in range(len(vec1))]
        [8, 12, -54]
        
Python IAQ
----------

::

        mat = [[1,2,3],
               [4,5,6],
               [7,8,9]
               ]

How would you transpose the matrix?

:: 
        result = [[1,4,7],
                  [2,5,8],
                  [3,6,9]
                  ]

        Answer:
        >>>zip(\*mat)



Comparing Sequences and Other Types 
-----------------------------------

* lexicographic comparision between the same types.
* comparing objects of different types is legal.
* types are ordered by their name ( list < string < tuple). *this must not be relied upon however*
* mixed numeric types are compared according to numeric value.

::
        (1, 2, 3)              < (1, 2, 4)
        [1, 2, 3]              < [1, 2, 4]
        'ABC' < 'C' < 'Pascal' < 'Python'
        (1, 2, 3, 4)           < (1, 2, 4)
        (1, 2)                 < (1, 2, -1)
        (1, 2, 3)             == (1.0, 2.0, 3.0)
        (1, 2, ('aa', 'ab'))   < (1, 2, ('abc', 'a'), 4)



Handling Exceptions
-------------------

* A try statement may have more than one except clause, to specify handlers for

::

  different exceptions.

          ... except (RuntimeError, TypeError, NameError):

          ...     pass

* The last except clause may omit the exception name(s), to serve as a
  wildcard. Use this with extreme caution, since it is easy to mask a real
  programming error in this way! 

*  It can also be used to print an error message and then re-raise the
  exception (allowing a caller to handle the exception as well)

* The try ... except statement has an optional else clause, executed when the
  try clause does not raise an exception.

::

        for arg in sys.argv[1:]:
            try:
                f = open(arg, 'r')
            except IOError:
                print 'cannot open', arg
            else:
                print arg, 'has', len(f.readlines()), 'lines'
                f.close()

Defining Clean-up Actions 
-------------------------

* A finally clause is always executed before leaving the try statement, whether
an exception has occurred or not.

* In real world applications, the finally clause is useful for releasing
  external resources (such as files or network connections), regardless of
  whether the use of the resource was successful.

Pre-defined Clean-up actions
----------------------------

* with statement

* Some objects define standard clean-up actions to be undertaken when the
  object is no longer needed, regardless of whether or not the operation using
  the object succeeded or failed. 

::

        with open("myfile.txt") as f:
            for line in f:
                print line

* After the statement is executed, the file f is always closed, even if a
  problem was encountered while processing the lines. 

Classes in Python 
-----------------

* In C++ terminology, all class members (including the data members) are
  public, and all member functions are virtual. There are no special
  constructors or destructors.  
* Python Scopes and Namespaces
* A namespace is a mapping from names to objects. Most namespaces are currently
  implemented as Python dictionaries.

Classs in Python
----------------

* When a class definition is entered, a new namespace is created, and used as
  the local scope and thus, all assignments to local variables go into this new
  namespace. In particular, function definitions bind the name of the new
  function here.
* When a class definition is left normally (via the end), a class object is
  created. This is basically a wrapper around the contents of the namespace
  created by the class definition;The original local scope (the one in effect
  just before the class definition was entered) is reinstated, and the class
  object is bound here to the class name given in the class definition header
* Class Objects support attribute notation and instantiation.
* Class instantiation creates instance objects.
* Instance Objects supports attribute references, which are of two kinds data
  attributes and methods.


Inheritance in Python 
---------------------

* Old style classes it is depth first, left to right.
* For new style classes to support super(), it follows a diamond inheritance.


Iterators
---------

* The use of iterators pervades and unifies Python.
* Behind the scenes, the iterator statement calls iter() on the container
  object. 
* The function returns an iterator object that defines the method next() which
  accesses elements in the container one at a time.  
* StopIterationException terminates
* In your classes, define __iter__ which will return self and the next method.

Generators
----------

* Just like regular function, but instead of return they use yield.
* Generators are used to return iterators.
* Generator expressions which are very similar to list comprehensions.

 * Python Standard Library. 
 * Explore!

 
Explain Classmethods, Staticmethods and Decorators in Python.
=============================================================

In Object Oriented Programming, you can create a method which can get
associated either with a class or with an instance of the class, namely an
object. 

And most often in our regular practice, we always create methods to be
associated with an object. Those are called instance methods.

For e.g.
::

        class Car:
                def cartype(self):
                        self.model = "Audi"

        mycar = Car()
        mycar.cartype()
        print mycar.model

Here cartype() is an instance method, it associates itself with an instance
(mycar) of the class (Car) and that is defined by the first argument ('self').

When you want a method not to be associated with an instance, you call that as
a staticmethod.

How can you do such a thing in Python?

The following would never work:

::

        >>> class Car:
        ... 	def getmodel():
        ... 		return "Audi"
        ... 	def type(self):
        ... 		self.model = getmodel()

Because, getmodel() is defined inside the class, Python binds it to the Class
Object.  You cannot call it by the following way also, namely: Car.getmodel()
or Car().getmodel() , because in this case we are passing it through an
instance ( Class Object or a Instance Object) as one of the argument while our
definition does not take any argument.

As you can see, there is a conflict here and in effect the case is, It is an
"unbound local **method**" inside the class.

Now comes Staticmethod.

Now, in order to call getmodel(), you can to change it to a static method.

::

        >>> class Car:
        ... 	def getmodel():
        ... 		return "Audi"
        ...     getmodel = staticmethod(getmodel)
        ... 	def cartype(self):
        ... 		self.model = Car.getmodel()
        ... 		
        >>> mycar = Car()
        >>> mycar.cartype()
        >>> mycar.model
        'Audi'

Now, I have called it as Car.getmodel() even though my definition of getmodel
did not take any argument. This is what staticmethod function did.  getmodel()
is a method which does not need an instance now, but still you do it as
Car.getmodel() because getmodel() is still bound to the Class object. 

Decorators
----------

getmodel = staticmethod(getmodel)

If you look at the previous code example, the function staticmethod took a
function name as a argument and the return value was a function which we
assigned to the same name.

staticmethod() function thus wrapped our getmodel function with some extra
features and this wrapping is called as Decorator.

The same code can be written like this.

::

        >>> class Car:
        ... 	@staticmethod
        ... 	def getmodel():
        ... 		return "Audi"
        ... 	def cartype(self):
        ... 		self.model = Car.getmodel()
        ... 		
        >>> mycar = Car()
        >>> mycar.cartype()
        >>> mycar.model
        'Audi'

For a better explaination on what is decorator:

http://personalpages.tds.net/~kent37/kk/00001.html

Please remember that this concept of Decorator is independent of staticmethod
and classmethod.  Now, what is a difference between staticmethod and
classmethod?

In languages like Java,C++, both the terms denote the same :- methods for which
we do not require instances. But there is a difference in Python. A class
method receives the class it was called on as the first argument. This can be
useful with subclasses.

We can see the above example with the classmethod and a decorator as:

::

        >>>
        >>> class Car:
        ... 	@classmethod
        ... 	def getmodel(cls):
        ... 		return "Audi"
        ... 	def gettype(self):
        ... 		self.model = Car.getmodel()
        ... 		
        >>> mycar = Car()
        >>> mycar.gettype()
        >>> mycar.model
        'Audi'


The following are the references in order to understand further:
1) Alex-Martelli explaining it with code: http://code.activestate.com/recipes/52304/
2)  Decorators: http://personalpages.tds.net/~kent37/kk/00001.html

Good Article on Decorators

http://personalpages.tds.net/~kent37/kk/00001.html

Static Methods and Class Methods
--------------------------------

A class method receives the class it was called on as the first
argument. This can be useful with subclasses. A staticmethod doesn't get a
class or instance argument. It is just a way to put a plain function into the
scope of a class.

And that's the definition of the difference in Python.
In the wider world of OOP they are two names for the same concept.
Smalltalk and Lisp etc used the term "class method" to mean a
method that applied to the class as a whole.

C++ introduced the term "static method" to reflect the fact that it
was loaded in the static area of memory and thus could be called
without instantiating an object. This meant it could effectively be
used as a class method.

[In C it is possible to prefix a normal function definition with
the word static to get the compiler to load the function into
static memory - this often gives a performance improvement.]

Python started off implementing "static methods" then later
developed the sligtly more powerful and flexible "class methods" and
rather than lose backward compatibility called them classmethod.
So in Python we have two ways of doing more or less the same
(conceptual) thing.  // Alan

Conceptually they are both ways of defining a method that
applies at the class level and could be used to implement
class wide behavior. Thats what I mean. If you want to build
a method to determine how many instances are active at
any time then you could use either a staticmethod or a
classmethod to do it. Most languages only give you one
way. Python, despite its mantra, actually gives 2 ways to
do it in this case. // Alan

http://code.activestate.com/recipes/52304/

http://stackoverflow.com/questions/136097/what-is-the-difference-between-staticmethod-and-classmethod-in-python

Method (Computer Science)

In object-oriented programming, a method is a subroutine that is exclusively
associated either with a class (called class methods or static methods) or with
an object (called instance methods). Like a procedure in procedural programming
languages, a method usually consists of a sequence of statements to perform an
action, a set of input parameters to customize those actions, and possibly an
output value (called the return value) of some kind. Methods can provide a
mechanism for accessing (for both reading and writing) the encapsulated data
stored in an object or a class.

Instance methods are associated with a particular object, while class or static
methods are associated with a class. In all typical implementations, instance
methods are passed a hidden reference (e.g. this, self or Me) to the object
(whether a class or class instance) they belong to, so that they can access the
data associated with it. 

For class/static methods this may or may not happen according to the language;
A typical example of a class method would be one that keeps count of the number
of created objects within a given class.

A method may be declared as static, meaning that it acts at the class level
rather than at the instance level. Therefore, a static method cannot refer to a
specific instance of the class (i.e. it cannot refer to this, self, Me, etc.),
unless such references are made through a parameter referencing an instance of
the class, although in such cases they must be accessed through the parameter's
identifier instead of this. An example of a static member and its consumption
in C# code:

::

        public class ExampleClass
        {
          public static void StaticExample()
          {
             // static method code
          }
         
          public void InstanceExample()
          {
             // instance method code here
             // can use THIS
          }   
        }
         
        /// Consumer of the above class:
         
        // Static method is called -- no instance is involved
        ExampleClass.StaticExample();
         
        // Instance method is called
        ExampleClass objMyExample = new ExampleClass();
        objMyExample.InstanceExample();


Confusingly, methods marked as class in Object Pascal also cannot refer to a
class object, as can class methods in Python or Smalltalk. For example, this
Python method can create an instance of Dict or of any subclass of it, because
it receives a reference to a class object as cls:

::

        class Dict:
           @classmethod
           def fromkeys(cls, iterable, value=None):
               d = cls()
               for key in iterable:
                   d[key] = value
               return d


http://en.wikipedia.org/wiki/Method_(computer_science)


Question:
What is metaclass attributes?
Look a bit into property.
Usage of Ellipses


What is the difference between process and a thread?

Both threads and processes are methods of parallelizing an application.
However, processes are independent execution units that contain their own state
information, use their own address spaces, and only interact with each other
via interprocess communication mechanisms (generally managed by the operating
system). Applications are typically divided into processes during the design
phase, and a master process explicitly spawns sub-processes when it makes sense
to logically separate significant application functionality. Processes, in
other words, are an architectural construct.

By contrast, a thread is a coding construct that doesn't affect the
architecture of an application. A single process might contains multiple
threads; all threads within a process share the same state and same memory
space, and can communicate with each other directly, because they share the
same variables.

Threads typically are spawned for a short-term benefit that is usually
visualized as a serial task, but which doesn't have to be performed in a linear
manner (such as performing a complex mathematical computation using
parallelism, or initializing a large matrix), and then are absorbed when no
longer required. The scope of a thread is within a specific code module—which
is why we can bolt-on threading without affecting the broader application.

Global Interpreter Lock:

The GIL is a single lock inside of the Python interpreter, which effectively
prevents multiple threads from being executed in parallel, even on multi-core
or multi-CPU systems!

* All threads within a single process share memory; this includes Python's
  internal structures (such as reference counts for each variable).  Course
  grained locking.
* fine grained locking.
* @synchronized decorator
* technically speaking, threads have shared heaps but separate stacks.
* Interpreter of a language is said to be stackless if the function calls in
  the language do not use the C Stack. In effect, the entire interpretor has to
  run as a giant loop.

What is Global Interpretor Lock in Python?

The Global Interpreter Lock (GIL) is used to protect Python objects from being
modified from multiple threads at once. Only the thread that has the lock may
safely access objects.

To keep multiple threads running, the interpreter automatically releases and
reacquires the lock at regular intervals (controlled by the
sys.setcheckinterval function). It also does this around potentially slow or
blocking low-level operations, such as file and network I/O.

Indeed the GIL prevents the *interpreter* to run two threads of bytecodes
concurrently.

But it allows two or more threadsafe C library to run at the same time.

The net effect of this brilliant design decision are:

1. it makes the interpreter simpler and faster

2. when speed does not matter (ie: bytecode is interpreted) there’s not too
much to worry about threads.

3. when speed does matter (ie: when C code is run) Python applications is not
hampered by a brain dead VM that is so ’screwed’ up that it must pause
to collect its garbage.


Links:

http://jessenoller.com/2009/02/01/python-threads-and-the-global-interpreter-lock/
http://en.wikipedia.org/wiki/Global_Interpreter_Lock

Python Standard Library
-----------------------

Python's standard library is very extensive, offering a wide range of
facilities as indicated by the long table of contents listed below. The library
contains built-in modules (written in C) that provide access to system
functionality such as file I/O that would otherwise be inaccessible to Python
programmers, as well as modules written in Python that provide standardized
solutions for many problems that occur in everyday programming. Some of these
modules are explicitly designed to encourage and enhance the portability of
Python programs by abstracting away platform-specifics into platform-neutral
APIS.

In addition to the standard library, there is a growing collection of several
thousand components (from individual programs and modules to packages and
entire application development frameworks), available from the Python Package
Index.

4.21   How do you specify and enforce an interface spec in Python?

An interface specification for a module as provided by languages such as C++
and Java describes the prototypes for the methods and functions of the module.
Many feel that compile-time enforcement of interface specifications helps in
the construction of large programs.

Python 2.6 adds an abc module that lets you define Abstract Base Classes (ABC).
You can then use isinstance() and issubclass to check whether an instance or a
class implements a particular ABC. The collections modules defines a set of
useful ABC s such as Iterable, Container, and Mutablemapping.

For Python, many of the advantages of interface specifications can be obtained
by an appropriate test discipline for components. There is also a tool,
PyChecker, which can be used to find problems due to subclassing.

A good test suite for a module can both provide a regression test and serve as
a module interface specification and a set of examples. Many Python modules can
be run as a script to provide a simple "self test." Even modules which use
complex external interfaces can often be tested in isolation using trivial
"stub" emulations of the external interface. The doctest and unittest modules
or third-party test frameworks can be used to construct exhaustive test suites
that exercise every line of code in a module.

An appropriate testing discipline can help build large complex applications in
Python as well as having interface specifications would. In fact, it can be
better because an interface specification cannot test certain properties of a
program. For example, the append() method is expected to add new elements to
the end of some internal list; an interface specification cannot test that your
append() implementation will actually do this correctly, but it's trivial to
check this property in a test suite.

Writing test suites is very helpful, and you might want to design your code
with an eye to making it easily tested. One increasingly popular technique,
test-directed development, calls for writing parts of the test suite first,
before you write any of the actual code. Of course Python allows you to be
sloppy and not write test cases at all.


Coroutines

Coroutines are subroutines that allow multiple entry points for suspending and
resuming execution at certain locations.  Subroutine are subprograms, methods,
functions for performing a subtask and it is relatively independent of other
task.  Coroutines are usful for implementing cooperative tasks, iterators,
infinite lists and pipes.  Cooperative Tasks - Similar programs, CPU is yielded
to each program coperatively.  Iterators - an object that allows the programmer
to traverse all the elements of a collection.  Lazy Evaluation is the technique
for delaying the computation till the result is required. Why Infite Lists and
Lazy evaluation are given together?  Coroutines in which subsequent calls can
be yield more results are called as generators.  Subroutines are implemented
using stacks and coroutines are implemented using continuations.  continuation
are an abstract representation of a control state, or the rest of the
computation, or rest of the code to be executed.

Multithreading

Multithreading computers have hardware support to efficiently execute multiple
threads.  Threads of program results from fork of a computer program into two
or more concurrently running tasks.  In multi-threading the threads have to
share a single core,cache and TLB unlike the multiprocessing machines.

Twisted Framework

Asynchronous, Event-Driven Applications for Distributed Network Environment.
At the core of Twisted Framework is its Network Layer, which can used to
integrate any existing  protocol as well as model new ones.  Twisted is a pure
python framework.  As a platform, twisted should be focussed on integration.
Twisted supports Asynchronous programming and deferred abstraction, which
symbolizes a promised result and which can pass eventual result to  handler
functions.  Document will give you a high-level overview of concurrent
programming and Twisted's concurrency model: non-blocking code and asynchronous
code.  Concurrent programming - Need. It is either computationally intensive;
or it has to wait for the data to be available as a result.  A fundamental
feature of Network Programming is waiting for data.  Not waiting on data:-
handle each connection in a separate OS process; so that OS will take of
letting other process run while one is waiting.  Handle each connection in a
separate thread; threading framework takes care of the details.  Use
non-blocking system calls to handle all connections in one thread.  The Normal
Model when using twisted framework is by using Non-Blocking Calls.  When
dealing with many connections in one thread, the scheduling is the
responsiblity of the application, not the operating system, and is usually
implemented by calling a registered function when each function is ready to go
for reading or writing - commonly known as asynchronous, event based, callback
based programming.  In synchrnous programming, a function requests data, waits
for the data, and then processes it. In asynchronous programming, a function
requests the data, and lets the library call the callback function when the
data is ready.

It is the second class of concurrency problems, non-computationally intensive
tasks that involve an appreciable delay that deferreds are designed to help
solve.  They do this by giving a simple management interface for callbacks and
applications.  blocking - means, if one tasks is waiting for data, the other
task cannot get CPU but also waits until the first tasks finishes.  The typical
asynchronous model to notify can application that some data is ready is called
as callback.  Twisted uses Deferred objects to managed callback sequence.
Libraries know that they make their results available by using
Deferred.callback and errors by Deferred.errback.  How does the parent function
or its controlling program know that connection does not exist and when it will
know, when the connection becomes alive?  Twisted has an object that signals
this situation, it is called twisted.internet.defer.Deferred Deferred has two
purposes; first is saying that I am a signal, of whatever you wanted me to do
is still pending; second you can ask differed to run things when the data
arrives.  the way to tell the deffered what to do when the data arrives is by
defining a callback - asking the deferred to call a function once the data
arrives.  28.  One Twisted library function that returns a Deferred is
twisted.web.client.getPage.

If nothing else is understood, please understand that you create a differed object, add a callback function to that object and add an errorback function to that object. Differed will get called after a particular period of time or some data is avaiable.
30. Differed Objects are signals that the function that you have called does not have the data, you want available.
31. What Differeds dont do: Make your code asynchronous!.
32. Differeds are the signals for asynchronous functions to use to pass results onto the callbacks, but using them does not guarantee that you have asynchronous functions.
33. Twisted provides a facility to run the blocking function in a separate thread instead of blocking them.
34. Evolution of finger. By the end of this tutorial; the finger service will answer the TCP finger requests on port 1079 and will read data from the web.
35. Install http://www.zope.org/Products/ZopeInterface before installing twisted from source. 
36. What is a Factory design pattern? What is a Protocol when the term is used in Twisted?
37. A Twisted Protocol handles code in an asynchronous manner. What this means is that the Protocol does not wait for an event, but rather handles the event as they arrive from network.
38. In the Twisted client, an instance of the Protocol class will be instantiated with you connect to the Server and will go away when the connection is finished.
39. Deferreds are an object which represent a promise of something; 
40. Like getPage() returned a Deferred object, which means that when the getPage is called ( It may not be called sequentially, because it is  asynchronous); a callback may be attached to the defered object which will ask it do whatever with the data, in our case, the callback was to print the data.

41. [http://pig.slug.org.au/talks/Twisted2/slides.html Good Tutorial]

42. There is reactor.callLater(time,callback,value) and there is task.deferLater(reactor,time,func)

43. twisted.internet.task.coiterate might be helpful to write a fibonacci series function in a asynchronous way.

44. twisted multiprocessing using ampoule.

45. spawning externally processes asynchrnously using twisted. twisted.internet.utils.getProcessValue('/usr/bin/sftp',['remote_machine','local_machine'])

46. Why is the twisted package which essentially deals with asynchronous I/O and events named internet. It is confusing with the general and difficult to remember for the newbie. Documentation update might be desirable. The internet in this documentation means internetworking.

47. Twisted is a platform for developing Internet applications.

48. Deferred abstraction symbolises a promised result and which can pass on an eventual result to a handler functions.

49. I dont get the howto/plugin.html page at all? How do I implement plugin for the IMaterial Interface?



Callbacks
=========
* twisted.internet.defer.Deferred is a promise that the function at some point
  in time will have a result.
* The Deferred mechanism, standardizes the application programmers inferface
  with all sort of blocking and delayed operations.
* Understanding reactor.callLater(2, d.callback, x*3) // What is the purpose of
  the second argument in this case?
* considered the deferred returned by twisted.enterprise.adbapi
* failure is typically an instance of twisted.python.failure.Failure instance.
* You can typically get away by not adding errbacks and still get the errors logged.
* Be careful though; if you keep a reference to the Deferred around, preventing
  it from being garbage-collected. How do I?
* It is possible to adapt, synchronous functions to return Deferred.
* Sometimes you want to be notified after several different events have all
  happened, rather than waiting for each one individually.
* You may want to wait for all connections in a list to close.
* Generating Deferreds is a Document introducing writing of Asynchronous
  functions generating deferreds.
* twisted.internet.defer.AlreadyCalledError 
* deferreds are not a non-blocking talisman; they are a signal for asynchronous
  functions to use to pass results to callback once the results are available.
* Returning Deferreds from synchronous functions; reasons :- API compatiblity
  with another function which returns deferred or making the function
  asynchronous in the future.

* Integrating blocking code with Twisted.

twisted.internet.threads.deferToThread will setup a thread to run your blocking
function, return a deferred and do the callback when the thread completes.

Firing Deferreds more than once is impossible. You can only call
Deferred.callback() or Deferred.errback() once.

Event Loop, Message Dispatcher, Message Loop or Message Pump is an event
construct that waits for and dispatches events in a program.

* event: Event Driven programming or Event Based Programming is where program
  flow happens based on events like mouse movement or key press or signal from
  another thread.

* Event Driven Programming is paradigm, in which there is a main-loop, which
  does event-detection and event-handling.

Comment: In the question I asked, everyone thought that my main requirement was
event detection of new file arrival. 

Whereas my main event is request for logs from data-source; and based on the
data-source, I want to pass it to the event-handler.

It works by polling an internal or external event provider which generally
*blocks* until an event has arrived and then calls the relevant event handler
in order to handle the event.

The event loop may be used in conjuction with a reactor, if the event provider
follows a file interface, which can be select(ed) or poll(ed).

* reactor:  The reactor design pattern is a concurrent programming pattern, for
  handling service requests delivered concurrently to a service handler by one
  or more inputs.

* The service handler then demultiplexes the incoming requests and dispatches
  them synchronously to associated request handlers.

The event loop almost always operates asynchronously with the message
originator.  The event loop forms the central constuct flow of the program, is
the highest level of control within the program. It is often termed as the
main-loop or the main-event loop.

The event loop is the specific implementation techniques of system which does
message passing.

Under Unix, everything is a file-paradigm naturally leads to a file based
event-loop. select and poll system calls monitor a set of file-descriptors for
events.

Handling Signals:

One of few things in Unix that do not confirm to file descriptors are
asynchronous events (signals); signals are received in signal handlers, small,
limited piece of code that run while rest of the task is suspended. 

* In Computing, Network Programming is essentially identified as socket
  programming or client-server programming, involves writing computer programs
  that communicate with other programs across the Computer Network.  The
  program initiating the communication is called the client and the program
  waiting for the communication to get initiated is called the server.
  The client and the server process together form the distributed system. The
  connection between the client and the server process may be connection
  oriented (TCP/IP or session) or connectionless (UDP)

The program that can act both as server and client is based on peer-to-peer
communication. Sockets are usually implemented by an API library such a
Berkeley sockets, first introduced in 1983. The example functions provided by
the API library include:

* socket() - creates a new socket of certain type, identified by the integer
  number and allocates system resources to it.
* bind() is used at the server side; associates a socket with a socket adddress
  structure, typically a IP Address and a Port number.
* listen() is used again on the server side, causes a bound TCP socket to
  listen to enter a listening state.
* connect() is used on the client side; used to assign a free local port number
  to the socket. It causes an attempt to establish a new TCP Connection.
* accept() is used on the server side; It accepts a received incoming connect()
  request and creates a new socket associated with the socket address pair for
  this connection.
* send(), recv(), write(), read() or recvfrom() and sendto() are used for
  sending and receiving data.
* close() is used to terminate the connection and release the resources
  allocated to the socket. 

Twisted project supports TCP, UDP, SSL/TLS and IP Multicast, Unix Domain
Sockets, a large number of protocols such  as HTTP, XMPP, NNTP, IMAP, SSH, IRC,
FTP.

Deferred is a value which has not been computed yet; because it needs data from
remote peer.

Requesting method requests a data; and gets a Deferred object.
Requesting method attaches callbacks to the Deferred object, 

Interface classes are a way of specifying what methods and attributes an 

* In the Twisted, internet term actually denotes internetworking.

External Training Presentations 

Alex Martelli's Tutorials
-------------------------

1) http://www.aleax.it/python_mat_en.html

2) http://www.strakt.com/dev_talks.html

Norman Matloff's Python Tutorials
---------------------------------

1) http://heather.cs.ucdavis.edu/~matloff/python.html 

Python Books
------------

http://www.rexx.com/~dkuhlman/python_book_01.html

Python and Vim
--------------

http://henry.precheur.org/2008/4/18/Indenting_Python_with_VIM.html
 
http://blog.sontek.net/2008/05/11/python-with-a-modular-ide-vim/ 

How is the Dictionary keys assigned in Python? 
----------------------------------------------

Tutorials

* Alex Martellis Callback tutorial: http://www.youtube.com/watch?v=LCZRJStwkKM


Interfaces

* In Java World, interfaces form the contract between the class and the outside
  world, and this contract is enforced at the build time by the compiler.

Essay:

A programming language should equip us with structures that help us to reason more effectively.
Smalltalk and Scheme have powerful influence on language designers.

Caught an exception while rendering: The model BlogPost is already registered

http://adil.2scomplement.com/2008/09/django-the-model-mymodel-is-already-registered/

Object Oriented Programming
---------------------------

Factory Method Pattern 
----------------------

* Object Oriented Design Pattern.
* It is a creational pattern, dealing with creation of objects (products)
  without specifying the exact class.
* The creational patterns abstract the concept of instantiating objects.
* It handles this case by defining a separate method for creation objects.
* The subclasses of that method or object (??)can override to specify the
  derived type of the product that will be created.
* Factory method is used to refer to any method whose main purpose is to create
  objects. 
* The Factory pattern in c++ wraps the usual object creation syntax new
  someclass() in a function or a method which can control the creation.
* Advantages is that, code using the class no longer needs to know all the
  details of creation. It may not even know the exact type of object
  created.
* Abstract Factory provides additional indirection to let the type of object
  which is created to vary.
* Factory pattern is fundamental in python; while languages like C++ use
  ClassName class; to create classes python uses function class syntax to
  create objects. Even builtin types str, int provide factory pattern.

References
----------

* [http://code.activestate.com/recipes/86900/ Factory Example]
* [http://www.suttoncourtenay.org.uk/duncan/accu/pythonpatterns.html Python Patterns]

* SAX - Simple API for XML - serial access parser API for XML.

* SAX provides a mechanism for reading data from an XML document. Its popular
  alternative is DOM.

Unlike DOM there is no formal specification of SAX. The Java implementation of
SAX is considered to be normative, and implementations in other languages
attempt to follow the rules laid down in that implementation, adjusting for
differences in the language when necessary.

Benefits of SAX - less memory, it is serial.  DOM requires to load the entire
XML tree.

Drawbacks:

Certain kind of XML validation requires to read the complete XML.

I do not know how to use HTMLParser module in Python Standard Library. There is
not a good example in the Python docs also.  HTMLParser implementation supports
HTML 2.0 language as described in RFC 1866.

xml.etree.ElementTree

First of all understand that Element Tree is a tree datastructure. It
represents the XML document as a Tree. The XML Nodes are Elements. (Thus Element Tree)
Now, if I were to structure an html document as a element tree.

::


                <html>
                  |
                <head> -------
                /   \        |
             <title> <meta> <body>
                           /   |  \
                        <h1>  <h2> <para>
                                   /   \
                                  <li> <li>


The Element type is a flexible container object, designed to store hierarchical
data structures in memory. The type can be described as a cross between a list
and a dictionary.  The C implementation of xml.etree.ElementTree is available
as xml.etree.cElementTree


Why and when do you subclass object?

The Evolution of  Python Programmer
-----------------------------------
http://gist.github.com/289467

.. _Joel's article on Unicode: http://www.joelonsoftware.com/articles/Unicode.html 
