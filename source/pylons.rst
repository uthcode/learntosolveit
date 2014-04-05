======
Pylons
======

Pylons is a lightweight web framework emphasizing flexibility and rapid
development using standard tools from the Python community.

**Problems with CGI Scripts**

Here are some problems with writing CGI scripts, especially when writing big
web applications.

It can be difficult to understand how the whole application is structured
because each script can behave fairly autonomously. This part may be easy to
write, but is difficult (and boring) to maintain. Code is frequently duplicated
in multiple scripts so over time the code can become difficult to maintain as
developers change the database or the code in certain files but aren’t aware
that other scripts also rely on the way the database or code used to work.

Every script in the site needs the same code to load the config file and to
handle the errors. Writing database access code is very repetitive, and the
data structures from the database don’t necessarily represent the objects your
application wants to deal with.

CGI scripts can be slow because the whole Python interpreter as well as the
modules the script uses need to be loaded into memory on each request.
Designers will find it difficult to change the theme of the site because the
HTML-generating code is interspersed with Python code.URLs in the 
form /cgi-bin/path/to/script.cgi?controller=page&action=view&id=3
do not readily reflect the structure of your web application and are not as
natural to a user as a URL such as /page/view/3.

**Solution - MVC**

The Model View Controller architecture is a result of the recognition that, at
their heart, most web applications:

* Store and retrieve data in a way that is natural to the programming language
  involved (the model)
* Represent the data in various ways, most commonly as HTML pages (the view)
* Execute logic code to manipulate the data and control how it is interacted
  with (the controllers)

**Web Frameworks**

Web frameworks such as Django and Ruby on Rails have become extremely popular
in recent years because they provide a structure that allows you to quickly
create good-looking web sites by defining the way the data is structured. The
tools they provide then work on that data either to automatically generate code
(scaffold in the case of Ruby on Rails) or to create form interfaces at runtime
(as is the case with Django).

Pylons provides sensible low-level APIs and methodologies that allow you to
quickly and easily glue together the component parts you choose to use for
yourself.

Pylons is a collection of very carefully chosen 3rd party software.

**Pylons**

In Pylons, Requests, usually made via browser intially, are dispatched to a
controller, which is an ordinary Python class with methods called actions that
handle the application logic. The controller then interacts with the model
classes to fetch data from the database. 

Once all the necessary information has been gathered, the controller passes the
key information to a view template where an HTML representation of the data is
generated and returned to the user’s browser. 

The user then interacts with the view to create a new request, and the process
starts over again. 

The model and controller don’t contain code for generating HTML, and the view
templates shouldn’t interact directly with the model.

**Exploring Pylons**


**Routes**

Currently the only widely used URL dispatcher for Pylons is Routes, a Python
reimplementation of Ruby on Rails' URL dispatching, although any
WSGI-compatible URL dispatcher can be used.

Routes allows you to map a URL to a set of variables usually including
controller and action. These variables are then used to determine which Pylons
controller class and method should be used to handle the request. At the same
time, Routes allows you to specify a set of variables and have a URL generated
from them so that you never need to hard-code URLs into your application. 

**Templates**

Templating Language, Mako is text-based (as opposed to XML-based), and support
includes, inheritance and embedding arbitrary Python code.

Mako is significantly more powerful than Django, with arbitrary expressions,
defs, template inheritance (beyond layouts).

**Database**

Pylons has no default database library. Both SQLObject and SQLAlchemy  are
known to be used.

**WSGI Standard**

The WSGI standard is an interface that allows applications to use Python code
to handle HTTP requests. A WSGI application is passed a Python representation
of an HTTP request by an application, and returns content which will normally
eventually be rendered by a web browser. A common use for this is when a web
server serves content created by Python code.

There are, however, other uses: WSGI middleware is Python code that receives a
WSGI request and then performs logic based upon this request, before passing
the request on to a WSGI application or more WSGI middleware. WSGI middleware
appears to an application as a server, and to the server as an application.

This is analogous to the function of pipes on Unix systems. Functionality
provided by WSGI middleware may include authentication, logging, url
redirection, creation of sessions, and compression.

**Paste**

Paste helps in developing such WSGI middleware systems used in the Pylons web
application framework.

Paste is used for project setup, testing, and deployment in Pylons. 

* The package includes a WSGI wrapper for CGI applications.
* It also includes a simple webserver that can produce WSGI requests.

Paste has been a long-running open source project, dating from at least 2005.
As it has grown, it has unbundled several other utilities from the Paste core.
These utilities are part of the Paste project, but form their own packages and
have their own version numbers. They include:

* WebOb is a wrapper around the WSGI environment.
* Paste Deploy is a system for finding and configuring WSGI applications and
  servers.
* Paste Script, WebTest, ScriptType, INITools, Tempita, WaitForIt, WPHP,
  WSGIFilter, and WSGIProxy are other notable bundles.

Pylons applications are usually given a package name in CamelCase, but the
application directory itself is the lowercase version of the package name. 

**Scripts**

*paster*

This is a very useful script that uses the Paste Script package and has a
number of subcommands including paster create and paster serve,that are for
creating a new Pylons project and serving a Pylons application, respectively.
You’ll also see paster make-config and paster  setup-app, which are for
handling the creation of a config file from a distributed Pylons project and
for setting it up.


**Pylons**

This is where everything needed to glue together the other components of Pylons
is found. Pylons itself is relatively small, so if you are the curious type,
feel free to look at its code to get a feel for how everything works.

**Setuptools and Eggs**

This contains the methods used by the easy_install script to provide all of its
features and allow the use of egg files. Eggs, package format, but is simply a
zip file with some meta-data such as dependency used distutils packing system.
It is commonly used way for packaging in Python.

**simplejson**

This package converts data back and forth between JSON and Python formats and
is used by the @jsonify decorator mentioned earlier. Pylons application
developers also occasionally use simplejson directly in their controllers.

**decorator**

This is a simple tool used by Pylons to create the @validate and @jsonify
decorators. 

**Beaker**

Beaker is a piece of software used internally by Pylons to implement its
`Caching`_ and session functionality but you would never normally interact with
Beaker yourself directly.

**Tempita**

Tempita is a small template language that is a dependency of Paste. It is used
only behind the scenes for simple variable substitutions when you create a new
Pylons project directory with the paster create command described later in this
chapter.

**Mako**

Mako is one of the three template languages that Pylons 0.9.7 supports out of
the box. The others are Genshi (an XML template language) and Jinja (based on
Django’s template system). You have to install Genshi and Jinja separately if
you want to use them, whereas Mako is included in the default Pylons
installation because it is the recommended template language to use.

**WebOb**

This provides the new pylons.request and pylons.response objects in Pylons
0.9.7. 

**WebError**

WebError provides Pylons’ powerful interactive debugging and traceback
functionality described in Chapter 4.

**WebHelpers**

WebHelpers is a collection of stand-alone functions and classes that provide
useful functionality such as generating common HTML tags and form fields,
handling multiple pages of results, and doing much more.

**FormEncode**

FormEncode is a library for validating form submissions from web sites.
Although Pylons doesn’t use it internally, Pylons users work with it so often
that it is considered an essential part of Pylons. The FormEncode package also
includes a module named formencode.htmlfill that can be used to populate a
string containing HTML fields with values and error messages. Together
FormEncode and HTML Fill make an ideal tool set for handling forms in a Pylons
application. 

**nose**

This provides tools to help you write and run automated unit tests.


*Examples to look*

http://www.rexx.com/~dkuhlman/pylons_quick_site.html
http://code.google.com/p/pyatl-pylons/

https://github.com/reddit/reddit/wiki


`Pylons Example Application Code`_

.. _Caching: http://wiki.pylonshq.com/display/pylonsdocs/Caching+in+Templates+and+Controllers,
.. _Pylons Example Application Code:   http://www.apress.com/downloadable/download/sample/sample_id/958/
.. _Pylons Reference Docs: http://docs.pylonsproject.org/projects/pylons-webframework/en/latest/
