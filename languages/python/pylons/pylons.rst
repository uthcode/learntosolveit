Pylons
======

Pylons is a lightweight web framework emphasizing flexibility and rapid
development using standard tools from the Python community.

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

* Store and retrieve data in a way that is natural to the programming language
  involved (the model)

* Represent the data in various ways, most commonly as HTML pages (the view)

* Execute logic code to manipulate the data and control how it is interacted
  with (the controllers)

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

FormEncode
----------


Eggs
----

Eggs, a new package format, have many extra features over the old distutils
packages, including the addition of dependency information used by the
easy_install program installed with your virtual Python environment.

The following list contains the components relevant to Pylons 0.9.7. Of course,
the version numbers might change slightly over time and future versions of
Pylons might have slightly different dependencies, but the following list is
correct at the time of this writing:

Beaker-0.9.5-py2.5.egg

    Beaker is a piece of software used internally by Pylons to implement its
caching and session functionality. The Pylons session global described later in
the chapter uses Beaker, as does Pylons’ caching functionality described in the
Pylons Cookbook at
http://wiki.pylonshq.com/display/pylonsdocs/Caching+in+Templates+and+Controllers,
but you would never normally interact with Beaker yourself directly.

decorator-2.2.0-py2.5.egg

    This is a simple tool used by Pylons to create the @validate and @jsonify
decorators. You’ll learn about @validate in Chapter 6, and you’ll learn about
@jsonify in Chapter 15. Once again, you won’t normally use decorator in your
own programs because you’ll usually use the decorators provided by Pylons.

FormEncode-1.0.1-py2.5.egg

    FormEncode is a library for validating form submissions from web sites.
Although Pylons doesn’t use it internally, Pylons users work with it so often
that it is considered an essential part of Pylons. The FormEncode package also
includes a module named formencode.htmlfill that can be used to populate a
string containing HTML fields with values and error messages. Together
FormEncode and HTML Fill make an ideal tool set for handling forms in a Pylons
application. Chapter 6 is dedicated to explaining how to use FormEncode and
HTML Fill in a Pylons application.

Mako-0.2.0-py2.5.egg

    Mako is one of the three template languages that Pylons 0.9.7 supports out
of the box. The others are Genshi (an XML template language) and Jinja (based
on Django’s template system). You have to install Genshi and Jinja separately
if you want to use them, whereas Mako is included in the default Pylons
installation because it is the recommended template language to use. Using Mako
to generate your views is described in detail in Chapter 5.

nose-0.10.3-py2.5.egg
    This provides tools to help you write and run automated unit tests. Testing
is described in Chapter 12.

Paste-1.6-py2.5.egg, PasteDeploy-1.3.2-py2.5.egg, and PasteScript-1.6.3-py2.5.egg

    Paste comes in three packages for the benefit of framework developers who
require only one part of its functionality. Pylons uses all three packages for
a wide variety of things throughout the framework, but once again, as a Pylons
application developer, you won’t normally directly interact with the Paste
components yourself.

    Over time, the functionality in the Paste modules has been split up into
custom packages. For example, the paste.wsgiwrappers module, which provided the
pylons.request and pylons.response objects in Pylons 0.9.6, is now replaced by
WebOb, which provides the Pylons 0.9.7 versions of those Pylons objects. The
paste.eval_exception module, which provided the 0.9.6 error handling, is
replaced by WebError in Pylons 0.9.7, and even the paste.auth functionality has
been built upon and improved in AuthKit, which you’ll learn about in Chapter
18. Don’t be surprised if future versions of Pylons include even more projects
spun out from their roots in Paste.

    Despite the gradual shift to separate packages, Pylons still relies on
Paste for its configuration files, registry manager, development HTTP server,
project template creation, test fixtures, error documents, and more. The
various parts of Paste are described throughout the book as they are
encountered.

Pylons-0.9.7-py2.5.egg
    This is where everything needed to glue together the other components of
Pylons is found. Pylons itself is relatively small, so if you are the curious
type, feel free to look at its code to get a feel for how everything works.

Routes-1.9-py2.5.egg
    Pylons uses a system called Routes that allows you to map a URL to a set of
variables usually including controller and action. These variables are then
used to determine which Pylons controller class and method should be used to
handle the request. At the same time, Routes allows you to specify a set of
variables and have a URL generated from them so that you never need to
hard-code URLs into your application. I’ll introduce Routes in this chapter,
but you will learn the details of all of Route’s powerful features in Chapter
9.

setuptools-0.6c8-py2.5.egg
    This contains the methods used by the easy_install script to provide all of
its features and allow the use of egg files.

simplejson-1.8.1-py2.5-linux-x86_64.egg
    This package converts data back and forth between JSON and Python formats
and is used by the @jsonify decorator mentioned earlier. Pylons application
developers also occasionally use simplejson directly in their controllers.

Tempita-0.2-py2.5.egg
    Tempita is a small template language that is a dependency of Paste. It is
used only behind the scenes for simple variable substitutions when you create a
new Pylons project directory with the paster create command described later in
this chapter.

WebError-0.8-py2.5.egg
    WebError provides Pylons’ powerful interactive debugging and traceback
functionality described in Chapter 4.

WebHelpers-0.6-py2.5.egg
    WebHelpers is a collection of stand-alone functions and classes that
provide useful functionality such as generating common HTML tags and form
fields, handling multiple pages of results, and doing much more.

WebOb-0.9.2-py2.5.egg
    This provides the new pylons.request and pylons.response objects in Pylons 0.9.7. 

Scripts 

paster

    This is a very useful script that uses the Paste Script package and has a
number of subcommands including paster create and paster serve, which you’ll
see later in this chapter, that are for creating a new Pylons project and
serving a Pylons application, respectively. You’ll also see paster make-config
and paster  setup-app, which are for handling the creation of a config file
from a distributed Pylons project and for setting it up. These are advanced
features you’ll learn about in the SimpleSite tutorial throughout the book.

helloworld

    This is the main application directory, but its name depends on the package
name you gave as the argument to the paster create command when the project was
generated. Pylons applications are usually given a package name in CamelCase,
but the application directory itself is the lowercase version of the package
name. In this case, you specified the package name as HelloWorld, so the main
Pylons application directory is named helloworld. If you were to write import
helloworld, it would be this directory’s files that are imported. I’ll return
to this directory in a moment to explore the subdirectories it contains.

HelloWorld.egg-info

    This is a special directory that contains metadata about your project in a
format that is used by setuptools when you treat the application as an egg.

config
    The config directory is where most Pylons functionality is exposed to your
application for you to customize.

controllers
    The controllers directory is where your application controllers are
written. Controllers are the core of your application. They allow you to handle
requests, load or save data from your model, and pass information to your view
templates for rendering; they are also responsible for returning information to
the browser. You’ll create your first controller in the next section.

lib
    The lib directory is where you can put Python code that is used between
different controllers, third-party code, or any other code that doesn’t fit in
well elsewhere.

model
    The model directory is for your model objects; if you’re using an
object-relational mapper such as SQLAlchemy, this is where your tables,
classes, and relations should be defined. You’ll look at using SQLAlchemy as a
model in Chapter 7.

public
    You’ve already seen the public directory. It is similar to the htdocs
directory in Apache and is where you put all your HTML, images, JavaScript,
CSS, and other static files.

templates
    The templates directory is where view templates are stored.

tests
    The tests directory is where you can put automated unit tests for your application.

__init__.py
    The __init__.py file is present so that the helloworld directory can be imported as a Python module within the egg.

websetup.py
    The websetup.py contains any code that should be executed when an end user
has installed your Pylons application and needs to initialize it. It frequently
contains code to create the database tables required by your application, for
example. We’ll discuss this in Chapter 8. 


It’s now time to learn how to generate the message dynamically using a Pylons
controller. Controllers are the basic building blocks of Pylons applications.
They contain all the programming logic and can be thought of as
mini-applications. Controllers are implemented as Python classes. Each method
of the class is known in Pylons as an action. On each request Pylons routes the
HTTP information to a particular controller action based on the URL that was
requested. The action should return a response, which Pylons passes back to the
server and on to the browser.

Occasionally it is even handy to deliberately put an exception into your code
like this during development to act a bit like a breakpoint and allow you to
see what is happening at that point in the code.

Using the Template Context c Global

Although passing the name argument directly as an extra argument to render()
works perfectly well, it is usually considered a better practice to assign
template variables to Pylons via the template context global c

You can add comments to your templates by starting a line with the ##
characters. A single #  is used quite a lot in templates for CSS selectors and
output for various programming languages, so it was decided ## should be used
for comments rather than adopting the Python comment format of a single #
character.

Make sure the ## characters are at the very start of the line with no
whitespace. For example:

Mako also supports the full range of control structures supported by Python,
including if, elif, else, while, and for. These structures are very useful in
templates. For example, to control which information is displayed, you might
use an if  statement:

% if c.name == 'Pylons Developer':
    Welcome Pylons Developer
% else:
    Welcome guest
% endif

These statements work in the same way they would in Python, including the need
for a colon (:) at the end of the line. The only difference is that because
templates don’t have to conform to the strict indentation rules that Python
source code follows, you have to specify the point at which the control
structure ends. In this case, you used an % endif line, but if you were using a
while loop, for example, you would use % endwhile.

Here’s a quick summary so that you can make sure you don’t accidentally use any
of these as names of your own variables in templates:

context

    This context is the central object that is created when a template is first
executed and is responsible for handling all communication with the outside
world. It includes the output buffer and a dictionary of the variables that can
be freely referenced within a template; this includes the other Mako runtime
built-ins, the Pylons default variables, and any extra variables passed by the
extra_variables argument to render(). As such, the context object is very
important. You can learn more about it at
http://www.makotemplates.org/docs/documentation.html#runtime.

local, self, parent, and next

    These are all namespaces and have particular meanings in the context of
template inheritance chains. You’ll look at these later in the chapter.

capture

    This is a function that calls a given def and captures its resulting
content into a string, which is returned. A def is Mako terminology for a
reusable block of template code wrapped in a <%def> tag that behaves a bit like
a function in Python. You’ll learn about defs and the capture() function later
in the chapter.

caller
    This is a “mini” namespace created when using the <%call> tag to define a
“def call with content.” You don’t deal with caller in this book, but it is
well documented at
http://www.makotemplates.org/docs/documentation.html#defs_defswithcontent if
you are interested.

UNDEFINED

    This is an instance of mako.runtime.Undefined that raises an exception when
its __str__() method is called. It is used when you use a variable in a
template without assigning it a value. If you see an UNDEFINED, it is likely
that you mistyped a variable name or forgot to pass a particular variable to a
template.

pageargs

    This dictionary can be specified with the <%page> tag and tells templates
the arguments that the body() def takes. You’ll look at the body() def and its
use in template inheritance chains later in the book, but for details of
pageargs, consult the Mako documentation at
http://www.makotemplates.org/docs/documentation.html#namespaces_body.

Three very useful methods of the context object are get(), keys(), and write().
Here’s an example demonstrating how they are each used:

You’ll remember from the previous chapter that the <%inherit> tag allows the
body of a template to be inserted into a parent template.

The recommended tool for validating forms in Pylons is FormEncode. FormEncode has two parts:

        * A set of validators used together to create schemas, which convert
form data back and forth between Python objects and their corresponding form
values
        * A tool called HTML Fill that takes an HTML form and parses it for
form fields, filling in values and error messages as it goes from Python
objects

Pylons provides a @validate decorator, which can make the process of validating
form data and redisplaying the form if necessary very easy


Pylons Example Application Code
-------------------------------

* http://www.apress.com/downloadable/download/sample/sample_id/958/
