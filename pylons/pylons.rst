Pylons
======

Here are some problems with writing CGI scripts

* Every script in the site needs the same code to load the config file and to
  handle the errors.
* Writing database access code is very repetitive, and the data structures from
  the database don’t necessarily represent the objects your application wants
  to deal with.
* CGI scripts can be slow because the whole Python interpreter as well as the
  modules the script uses need to be loaded into memory on each request.
* Designers will find it difficult to change the theme of the site because the
  HTML-generating code is interspersed with Python code.
* Code is frequently duplicated in multiple scripts so over time the code can
  become difficult to maintain as developers change the database or the code in
  certain files but aren’t aware that other scripts also rely on the way the
  database or code used to work.
* It can be difficult to understand how the whole application is structured
  because each script can behave fairly autonomously.
* URLs in the form /cgi-bin/path/to/script.cgi?controller=page&action=view&id=3
  do not readily reflect the structure of your web application and are not as
  natural to a user as a URL such as /page/view/3.

Solution

* A Model View Controller (MVC) architecture
* Convention over configuration

Pylons also puts particular emphasis on loose coupling and clean separation.

The Model View Controller architecture is a result of the recognition that, at
their heart, most web applications:

* Store and retrieve data in a way that is natural to the programming language involved (the model)
* Represent the data in various ways, most commonly as HTML pages (the view)
* Execute logic code to manipulate the data and control how it is interacted with (the controllers)

Requests are dispatched to a controller, which is an ordinary Python class with
methods called actions that handle the application logic. The controller then
interacts with the model classes to fetch data from the database. Once all the
necessary information has been gathered, the controller passes the key
information to a view template where an HTML representation of the data is
generated and returned to the user’s browser. The user then interacts with the
view to create a new request, and the process starts again. The model and
controller don’t contain code for generating HTML, and the view templates
shouldn’t interact directly with the model.

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

Exploring Pylons

Beaker is used for caching

Paste is used for project setup, testing, and deployment. Using the common INI
configuration format, Paste allows for multiple "profiles", so that developers
can run development and deployment setups from the same codebase without
revealing sensitive parts of Pylons, such as the interactive debugger, to
production users.

URL Dispatching

Currently the only widely used URL dispatcher for Pylons is Routes, a Python
reimplementation of Ruby on Rails' URL dispatching, although any
WSGI-compatible URL dispatcher can be used. While Routes is a separate library,
it was developed for use in Pylons and its development remains closely in sync
with Pylons.

Templating Language, Mako is text-based (as opposed to XML-based), and support
includes, inheritance and embedding arbitrary Python code.

Pylons has no default database library. Both SQLObject and SQLAlchemy  are
known to be used.

Paste

Python Paste, often simply called paste, is a set of utilities  for web
development in Python. Paste has been described as "a framework for web
frameworks".

The Python Paste package contains Python modules that help in implementing WSGI
middleware. The package includes a WSGI wrapper for CGI applications. It also
includes a simple webserver that can produce WSGI requests.

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

Paste helps in developing such WSGI middleware systems. For example, it is used
in the Pylons web application framework.

Paste has been a long-running open source project, dating from at least 2005.
As it has grown, it has unbundled several other utilities from the Paste core.
These utilities are part of the Paste project, but form their own packages and
have their own version numbers. They include:

* WebOb is a wrapper around the WSGI environment.
* Paste Deploy is a system for finding and configuring WSGI applications and
  servers.
* Paste Script, WebTest, ScriptType, INITools, Tempita, WaitForIt, WPHP,
  WSGIFilter, and WSGIProxy are other notable bundles.

Mako is significantly more powerful than Django, with arbitrary expressions,
defs, template inheritance (beyond layouts).


Pylons applications are usually given a package name in CamelCase, but the
application directory itself is the lowercase version of the package name. 

