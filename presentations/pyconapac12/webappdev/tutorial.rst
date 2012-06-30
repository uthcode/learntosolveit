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

Location of Source Examples
===========================

http://www.uthcode.com/presentations/pyconapac12/webappdev/


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
* Server - WSGI - Application Interface.


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

---- 

Client and Server
=================

* All Python code is executed on Server.
* Client only sees the output of Python code.
* The output can be Text, HTML, Javascript or CSS.

---- 

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

---- 


Forms
=====

* FieldStorage class of cgi module is all needed to handle forms.
* The Interface is same for GET and POST.


.. code-block:: python

    import cgi
    form = cgi.FieldStorage()

---- 


Forms - Unique Field Names
==========================

* Open form1.html
* Look at process_form.py
* If the HTML Form is changed from GET to POST, the script will still be the same.

---- 

CGI Escape
==========

* Always Escape User Input, when taking the input from the Form.
* This is useful  to prevent script injection 
* Also make it possible to display HTML source code as has just been done above.

.. code-block:: javascript

    <script type="text/javascript"> malicious code here </script>

The cgi.escape() method will transform the above into safe HTML text:

.. code-block:: javascript

    &lt;script type="text/javascript"&gt; malicious code here &lt;/script&gt;

---- 

Multiple field Names
====================

* getlist method.
* Open form2.html and process_check.py

---- 

File Upload Script
==================

* Uploading files to forms
* **enctype** attribute should be set to multipart/form-data
* **input** tag with **file** will create a Browse button.
* open form3.html and save_file.py
* Make sure you have correct permissions to write to directories.


---- 

Big File Upload
===============

* Python Generators.
* Generators return files only in small chunks.
* open form4.html and save_big_file.py

---- 

Safe CGI Shell
==============

* Have a look at CGI Shell with a brower client

http://code.google.com/p/cgpy-shell/

---- 

Cookies
=======

* HTTP is a stateless protocol.
* Every time the user loads a page, it is the first time for the server.
* Server can't say, if the user is middle of traction.
* Already Authenticated.
* Cookie is a Tag placed on Users computer.

---- 


Set the Cookie
==============

* Set the Cookie as an HTTP Header to sent to client.
* Read the Cookie Returned from the client as HTTP Header.
* Look at Set-Cookie header.
* Cookie module - helpful in dealing with Cookies.


Presenter Notes 
--------------- 

* cookie_1.py
* cookie_2.py

---- 

Retrieving the Cookie
=====================

* HTTP_COOKIE environ variable

.. code-block:: python

    cookie_string = os.environ.get('HTTP_COOKIE')
    cookie.load(cookie_string)

* Look at cookie_3.py after loading twice.

---- 

Morsel
======

* When a new key is set for a SimpleCookie object a Morsel instance is created.
* Morsel instance, can only have a predefined set of keys like expires, path, commnent, domain, max-age, secure and version.

.. code-block:: python

    >>> cookie = Cookie.SimpleCookie()
    >>> cookie
    <SimpleCookie: >
    >>>
    >>> cookie['lastvisit'] = str(time.time())
    >>> cookie['lastvisit']
    <Morsel: lastvisit='1159535133.33'>
    >>>
    >>> cookie['lastvisit'].value
    '1159535133.33'


* Look at morsel_1.py


---- 

Sessions
========

* Cookie: Client :: Session : Server
* Session state is kept in a file or DB on a server.
* Session ID travels from Server to Client to Server in Query, Hidden field of Cookie.
* Session lasts until the user leaves the site.

---- 

Cookie Based SID
================

* Lasts until cookie expires.
* The hash of the server time makes an unique SID for each session.
* session_1.py

---- 


Shelve Module
=============

.. code-block:: python

    # The shelve module will persist the session data
    # and expose it as a dictionary
    session = shelve.open('/tmp/.session/sess_' + sid, writeback=True)
    session.close()

* cookieshelve.py Example


---- 

WSGI
====

* WSGI is not a Server.
* WSGI is not a Python Module.
* WSGI is not a Framework.
* WSGI is not an API.
* WSGI is not Software.

---- 

It is PEP 3333
==============

---- 

WSGI
====

* If an application (or framework or toolkit) is written to the WSGI spec then
  it will run on any server written to that spec.

* WSGI applications (meaning WSGI compliant) can be stacked. 

* Those in the middle of the stack are called middleware and must implement
  both sides of the WSGI interface, application and server. 

* For the application in top of it it will behave as a server and for the
  application (or server) bellow as an application.

---------- 

WSGI Application Interface
==========================

* The WSGI application interface is implemented as a callable object: a
  function, a method, a class or an instance with a __call__ method. That's
  callable.

* Must accept two positional parameters.

    * A dictionary containing CGI like variables; and
    * A callback function that will be used by the application to send HTTP
      status code/message and HTTP headers to the server.

* And must return the response body to the server as strings wrapped in an
  iterable.

* Look at app_skel.py


---------- 

Environment Dictionary
======================

* Contains CGI like variables.
* Will be populated by the server.
* Script will output the whole dictionary.
* Load environment.py and visit http://localhost:8051/


---------- 

Response Iterable
=================

If the last script worked change the return line from:

.. code-block:: python

   return [response_body]

to:

.. code-block:: python

   return response_body

* Then run it again. Noticed it slower? What happened is that the server iterated
over the string sending a single byte at a time to the client. 

* So don't forget to wrap the response in a better performance iterable like a
  list.

If the iterable yields more than one string the content_length will be the sum
of all the string's lengths like in this script:

---------- 

Parsing the Request - GET
=========================

Handing GET request.

* Run environment.py and access http://localhost:8051/?age=10&hobbies=software&hobbies=tunning
* Look at parsing_get.wsgi script.

---------- 

Parsing the Request - POST
==========================

* Request method is POST, the query string will be sent in the Request Body instead of URL.
* Look at parsing_post.wsgi
* wsgi.input file like environment variable.
* use CONTENT_LENGTH to read from wsgi.input

---- 

Thank you!
==========

