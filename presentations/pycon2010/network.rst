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


**echo client**
::
        import socket

        host = '127.0.0.1'
        port = 50000
        size = 1024

        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((host, port))
        s.send("Hello,World")
        data = s.recv(size)
        s.close()
        print 'Received:', data

**echo server**
::
        import socket

        host = '127.0.0.1'
        port = 50000
        backlog = 5
        size = 1024
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((host, port))
        s.listen(backlog)
        while True:
            client, address = s.accept()
            data = client.recv(size)
            if data:
                client.send(data)
            client.close()

Connecting to IRC and logging the messages
------------------------------------------

.. literalinclude::        py31/howto19_socket_irclogger.py
