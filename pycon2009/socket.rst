=============
socket module
=============

The Python socket module provides direct access to the standard BSD socket
interface, which is available on most modern computer systems. The advantage of
using Python for socket programming is that socket addressing is simpler and
much of the buffer allocation is done automatically. In addition, it is easy to
create secure sockets and several higher-level socket abstractions are
available.

To create a server, you need to:

   1. create a socket
   2. bind the socket to an address and port
   3. listen for incoming connections
   4. wait for clients
   5. accept a client
   6. send and receive data

To create a client, you need to:

   1. create a socket
   2. connect to the server
   3. send and receive data

.. literalinclude::        socket_echo_client.py
.. literalinclude::        socket_echo_server.py


Additional Notes of Socket Programming.
======================================

Addresses
^^^^^^^^^

The BSD socket interface defines several different types of addresses called
families. These include:

* AF_UNIX: 
  A Unix socket allows two processes running on the same machine to communicate
  with each other through the socket interface. In Python, UNIX socket
  addresses are represented as a string.

* AF_INET:
  An IPv4 socket is a socket between two processes, potentially running on
  different machines, using the current version of IP (IP version 4). This is
  the type of socket most programs use today. In Python, IPv4 socket addresses
  are represented using a tuple of (host, port), where host is a string host
  name and port is an integer called the port number. For the host name you can
  specify either a standard Internet name, such as 'www.cnn.com' or an IP
  address in dotted decimal notation, such as '64.236.24.20'.

* AF_INET6: 
  An IPv6 socket is similar to an IPv4 socket, except that it uses IPv6. The
  main change in IPv6 is that it uses 128 bit addresses, whereas IPv4 uses only
  32 bits; this allows IPv6 to better meet the current high demand for IP
     addresses. In addition, IPv6 uses flow identifiers to provide different
     Quality of Service to applications (i.e. low delay or guaranteed
     bandwidth) and scope identifiers to limit packet delivery to various
     administrative boundaries. In Python, IPv6 socket addresses are
     represented using a tuple of (host, port, flowinfo, scopeid), where
     flowinfo is the flow identifier and scopeid is the scope identifier. Since
     support of IPv6 in many host operating systems is still incomplete, we
     will not discuss IPv6 further in this tutorial.


Sockets
^^^^^^^

To create a socket in Python, use the socket() method

::

        socket(family,type[,protocol])

The family is either AF_UNIX, AF_INET, or AF_INET6. There are several different
types of sockets; the main ones are SOCK_STREAM for TCP sockets and SOCK_DGRAM
for UDP sockets. You can skip the protocol number in most cases.

Please note that the constants listed above for socket family and socket type
are defined inside the socket module. This means that you must import the
socket module and then reference them as 'socket.AF_INET'.

The important thing about the socket() method is it returns a socket object.
You can then use the socket object to call each of its methods, such as bind,
listen, accept, and connect.

s.listen(backlog)
^^^^^^^^^^^^^^^^^

This tells the operating system to keep a backlog of five connections. This
means that you can have at most five clients waiting while the server is
handling the current client. You can set this higher, but the operating system
will typically allow a maximum of 5 waiting connections. To cope with this,
busy servers need to generate a new thread to handle each incoming connection
so that it can quickly serve the queue of waiting clients.

http://ilab.cs.byu.edu/python/socketmodule.html
