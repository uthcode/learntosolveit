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


Web Python Patterns
===================

Two web programming models - CGI Standard and mod_python Hosting Providers.

.. code-block:: python

    def code():
        print "hello, world"


Presenter Notes
---------------

CGI is ideal to learn the basic web programming concepts as there is no magic
running to hide those from the programmer. Part of the framework communities
take it as obsolete but read those comments with caution as some are just
snobbish. 
If you have no web programming experience and/or want to grow solid roots then
CGI is the way to go.  The WSGI application<->server interface specification is
gaining momentum and is today an acclamation. To use it is necessary to master
web programming concepts and/or a framework/toolkit.  

---------- 

Task
====

#) Run the CGI HTTPServer.
#) Write a CGI Script.
#) Expose the CGI Variables.
#) Execute an Involved CGI Script.

---------- 

Topics
======


Presenter Notes
---------------

Some host providers only let you run CGI scripts in a certain directory, often
named cgi-bin. In this case all you have to do to run the script is to call it
like this:

http://my_server.tld/cgi-bin/my_script.py

The script will have to be made executable by "others". Give it a 755
permission or check the executable boxes if there is a graphical FTP interface.

Some hosts let you run CGI scripts in any directory. In some of these hosts you
don't have to do anything to configure the directories. In others you will have
to add these lines to a file named .htaccess in the directory you want to run
CGI scripts from:

    Options +ExecCGI
    AddHandler cgi-script .py

If the file does not exist create it. All directories below a directory with a
.htaccess file will inherit the configurations. So if you want to be able to
run CGI scripts from all directories create this file in the document root.

If you are using your own server then probably you won't need to do anything to
run a CGI script at the cgi-bin directory. Just make sure there is a line like
the next in httpd.conf and that it is not commented. The trailing slashs are
required.

    ScriptAlias /cgi-bin/ "/path/to/cgi-bin/directory/"

If you are using the line above and want html files to be handled correctly in
the cgi-bin directory add the next to httpd.conf. No trailing slash.

    <Directory /path/to/cgi-bin/directory>
       AddHandler default-handler .html .htm
    </Directory>

To run a script saved at the root:

http://my_server.tld/my_script.py

If it was saved in some directory:

http://my_server.tld/some_dir/some_subdir/my_script.py

If your desktop is the server then execute it like this:

http://localhost/cgi-bin/my_script.py

---------- 

CGI
===

It is necessary that the script outputs the HTTP header. The HTTP header
consists of one or more messages followed by a blank line. If the output of the
script is to be interpreted as HTML then the content type will be text/html.
The blank line signals the end of the header and is required.

.. code-highlight:: python

    print "Content-Type: text/html"
    print

Blank Lines

.. code-highlight:: python

    print "Content-Type: text/html\n"

---------- 

Client versus Server
====================

When programming for the Web you are in a client-server environment. All python
code will be executed at the server only. The client's http agent (e.g. the
browser) will never see a single line of python. In instead it will only get
the python script output, be it text, html, css, javascript etc. So do not make
things like trying to open a file in the client's computer as if the python
script were running there. You can only achieve what your python script output
can and the http clients in general have a very restrictive security context.


If the user inputed data is to be shown in a HTML document then it is necessary
to escape it from HTML tags or else everything inside < > will be interpreted
by the HTML parser including javascript code like

.. code-highlight:: javascript

<script type="text/javascript"> malicious code here </script>

The cgi.escape() method will transform the above into safe HTML text:

.. code-highlight:: javascript

&lt;script type="text/javascript"&gt; malicious code here &lt;/script&gt;

This is useful not only to prevent script injection but also to make it
possible to display HTML source code as has just been done above.


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

