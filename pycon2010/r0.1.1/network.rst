Network Programming
===================

socket module
-------------

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

Connecting to IRC and logging the messages
------------------------------------------

.. literalinclude::        socket_irclogger-py3k.py
