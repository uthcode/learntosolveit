Key difference between HTTP 1.0 and HTTP 1.1
============================================

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








