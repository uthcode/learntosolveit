=============
basehttpsever
=============

This is a basic framework for HTTP servers, built on top of the SocketServer
framework.

The following example generates a random message each time you reload the page.
The path variable contains the current URL, which you can use to generate
different contents for different URLs (as it stands, the script returns an
error page for anything but the root path).

.. literalinclude::        basehttpserver-example-1.py
