Introduction to Web Development
===============================

----

Welcome
=======

Thanks for coming to PyCon Apac and attending this session.

    - **Senthil Kumaran** 
    - *Python Core Developer*
    - *Engineer at Lucasfilm, Singapore*.

Presentation slides available at http://www.uthcode.com

.. image:: senthil_qr2.png


---- 


Web Architecture
================

---- 

Simple Web sites. Complex Websites.
===================================

---- 

HTML
====

---- 

FORMS
=====

---- 


HTTP
====

* http://www.w3.org/Protocols/
* 

---- 


Apache
======

---- 

cgi.py
======

---- 

WSGI
====

* PEP 3333

---- 

wsgiref.py
==========

---- 


Web Python 
==========

* WSGI Specification.
* CGI 
* CGI is ideal to learn basic web programming.
* Learning Server <-> WSGI <-> Application Interface.

Two web programming models - CGI Standard and mod_python Hosting Providers.

.. code-block:: python

    def code():
        print "hello, world"


Presenter Notes
---------------

If you have no web programming experience and/or want to grow solid roots then
CGI is the way to go.

The WSGI application<->server interface specification is gaining momentum and
is today an acclamation. To use it is necessary to master web programming
concepts and/or a framework/toolkit.  

---------- 

CGI Tutorial
============

* cgi-bin directory.
* Permissions 755
* Example httpd.conf

.. code-block:: apache

    ScriptAlias /cgi-bin/ "/path/to/cgi-bin/directory/"

    <Directory /path/to/cgi-bin/directory>
       AddHandler default-handler .html .htm
    </Directory>

---------- 

Hello, World
============

* Hello, World CGI Script
* Look at SHEBANG line.
* Content-Type header.


Presenter Notes
---------------

Try helloworld.py

Client and Server
=================

* All Python code is executed on Server.
* Client only sees the output of Python code.
* The output can be Text, HTML, Javascript or CSS.

CGI Debugging
=============

* Catch Syntax Errors by running locally before uploading.
* error_log and access_log are the log files.
* cgitb module
* handler method to handle catched exceptions.
* Header set to text/plain
 

Presenter Notes 
--------------- 

debugging_1.py
debugging_2.py
debugging_3.py

Forms
=====

* FieldStorage class of cgi module is all needed to handle forms.
* The Interface is same for GET and POST.

.. code-highlight:: python

    import cgi
    form = cgi.FieldStorage()


Forms - Unique Field Names
==========================

* Open form1.html
* Look at process_form.py
* If the HTML Form is changed from GET to POST, the script will still be the same.


CGI Escape
==========

* Always Escape User Input, when taking the input from the Form.
* This is useful  to prevent script injection 
* Also make it possible to display HTML source code as has just been done above.

.. code-highlight:: javascript

    <script type="text/javascript"> malicious code here </script>

The cgi.escape() method will transform the above into safe HTML text:

.. code-highlight:: javascript

    &lt;script type="text/javascript"&gt; malicious code here &lt;/script&gt;


#) Run the CGI HTTPServer.
#) Write a CGI Script.
#) Expose the CGI Variables.
#) Execute an Involved CGI Script.

---------- 

Topics
======




---------- 

CGI
===

With CGI you download it using curl or wget directly to a directory in your
site's hierarchy like a tmp directory:

.. code::

    http://my_site.tld/getshellcmd.py?curl -o tmp/Django-0.95.tar.gz http://media.djangoproject.com/releases/0.95/Django-0.95.tar.gz

    http://my_site.tld/getshellcmd.py?tar -xzvf tmp/Django-0.95.tar.gz

---------- 

WSGI
====

What WSGI is not: a server, a python module, a framework, an API or any kind of
software. What it is: an interface specification by which server and
application communicate. Both server and application interface sides are
specified. It does not exist anywhere else other than as words in the PEP 3333.

If an application (or framework or toolkit) is written to the WSGI spec then it
will run on any server written to that spec.

WSGI applications (meaning WSGI compliant) can be stacked. Those in the middle
of the stack are called middleware and must implement both sides of the WSGI
interface, application and server. For the application in top of it it will
behave as a server and for the application (or server) bellow as an
application.

A WSGI server (meaning WSGI compliant) only receives the request from the
client, pass it to the application and then send the response provided by the
application to the client. It does nothing else. All the gory details must be
supplied by the application or middleware.

It is not necessary to learn the WSGI spec to use frameworks or toolkits. To
use middleware one must have a minimum understanding of how to stack them with
the application or framework unless it is already integrated in the framework
or the framework provides some kind of wrapper to integrate those that are not.

Python 2.5 and later comes with a WSGI server which will be used in this
tutorial. In 2.4 and earlier it can be installed. For anything other than
learning I strongly recommend Apache with mod_wsgi.

All the code in this tutorial is low level and has the sole purpose to be
didactic by showing the WSGI specification at work. It is not meant for real
use. For production code use toolkits, frameworks and middleware.

http://pypi.python.org/pypi/wsgiref

http://code.google.com/p/modwsgi/

---------- 

WSGI Application Interface
==========================

The WSGI application interface is implemented as a callable object: a function,
a method, a class or an instance with a __call__ method. That callable

---------- 

Application Interface
=====================

Must accept two positional parameters:

* A dictionary containing CGI like variables; and

* A callback function that will be used by the application to send HTTP status
  code/message and HTTP headers to the server.

and must return the response body to the server as strings wrapped in an
iterable.

---------- 

Environment Dictionary
======================

---------- 

Response Iterable
=================

If the last script worked change the return line from:

   return [response_body]

to:

   return response_body

Then run it again. Noticed it slower? What happened is that the server iterated
over the string sending a single byte at a time to the client. So don't forget
to wrap the response in a better performance iterable like a list.

If the iterable yields more than one string the content_length will be the sum
of all the string's lengths like in this script:

---------- 

Parsing the Request - GET
=========================

Handing GET request.

---------- 

Older Way
=========

If you installed mod_python from a Linux package you probably already have this
line in your httpd.conf:

.. code-highlight:: apache

    LoadModule python_module modules/mod_python.so


    <Directory /path/to/publisher/directory>
       SetHandler mod_python
       PythonHandler mod_python.publisher
       PythonDebug On
    </Directory>


    <Files ~ "\.(gif|html|jpg|png)$">
       SetHandler default-handler
    </Files>


Thank you!
==========

