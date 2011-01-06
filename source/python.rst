============
Python Notes
============

.. warning:: 
        Rough Notes.

How do see the system calls?
----------------------------

By using strace. strace is a Linux command line utility that traces the system calls.
You can create a program like this:

::

        $cat 1.py
        print 'hello'

And run the strace using using following syntax

::

        $strace python 1.py


What is spitted out is an enormous amout of details on the system calls which
are executed when running this program.


wsgi
----

It is easy to build a web application framework.

WSGI is Python PEP 333, the Web Server Gateway Interface. It's a a protocol for
communicating with Python web applications. WSGI works by callbacks. The
application provides a function which the server calls for each request:

application(environ, start_response)

environ is a Python dictionary containing the CGI-defined environment variables
plus a few extras. One of the extras is "wsgi.input", the file object from
which to read the POST variables. start_response is a callback by which the
application returns the HTTP header.

start_response(status, response_headers, exc_info=None)

status is an HTTP status string (e.g., "200 OK"). response_headers is a list of
2-tuples, the HTTP headers in key-value format. exc_info is used in exception
handling; we won't cover it here.

The application function then returns an iterable of body chunks. In the
simplest case this can be:

["<html>Hello, world!</html>"]

Getting slightly more elaborate, here's the second-smallest WSGI application in
the world:

def app2(environ, start_response):
    start_response("200 OK", [])
    s = "<html>You requested <strong>%s</strong></html>"
    s %= environ['PATH_INFO']
    return [s]

The protocol may look strange, but it's designed to meet the needs of the
widest possible variety of existing and potential frameworks and servers. And
middleware. Middleware are reusable components providing generic services
normally handled by frameworks; e.g., a Session object, a Request object, error
handling. They're implemented as wrapper functions; i.e., decorators. Inbound
they can add keys to the dictionary (e.g., quixote.request for a Quixote-style
Request object). Outbound they can modify HTTP headers or translate the body
into Latin or Marklar. Here's a small middleware:

class LowercaseMiddleware:
    def __init__(self, application):
        self.application = application   # A WSGI application callable.

    def __call__(self, environ, start_response):
        pass  # We could set an item in 'environ' or a local variable.
        for chunk in self.application(environ, start_response):
            yield chunk.lower()
Assuming we had a server constructor Server, we could do:

app = LowercaseMiddleware(app2)
server = Server(app)

Since it's so easy to write a WSGI application, you may wonder, "Who needs a
framework?" That's a legitimate question, although the answer is, "It's tedious
without one." Your application is responsible for every URL under it; e.g., if
it's installed as http://localhost:8080/, it would have to do something
intelligent with http://localhost:8080/foo/bar/baz. Code to parse the URL and
switch to an appropriate function is... a framework! So you may as well use an
existing framework and save yourself the tedium.

Writing a WSGI server interface is more complex. There's an example in PEP 333.
I wrote an object-oriented one for Quixote (in wsgi_server.py). But the
experience taught me it's more fun to write the application side.

WSGI opens the way for a lot of interesting possibilities. Simple frameworks
can be turned completely into middleware. Some frameworks might be able to run
on top of other frameworks or even be emulated by them. Ideally, existing
applications would run unchanged or with minimal changes. But this is also a
time for framework developers to rethink how they're doing things and perhaps
switch to more middleware-friendly APIs.


Guido's approach to Web Framework in his blog post "Teach me Web Framework"

Before I post this, let me attempt at a brief classification of the features
that every web framework needs.

* Independence from web server technology. You should be able to run the same
application under Apache, as a CGI script, as a stand-alone server (e.g.
BaseHTTPServer or Zope's or Twisted's built-in server), etc. (The Java Servlet
API does this really well IMO -- I used it at Elemental.) This should include
logging and basic error handling (an API to generate any HTTP error, as well as
a try/except around application code that returns a 500 error code if the
application code fails.

* Templating with reuse. Every web application needs to mix computed data (in
which category I include data retrieved from a database) with HTML mark-up, and
often a lot of the HTML markup is common for many pages (e.g. global
navigation).
* Cookie handling. For authentication, preferences, sessions, etc.
* Query parsing. The bread and butter of form handling.
* URL dispatch. You've got to be flexible in how URL paths are mapped to
callables. Zope's URL-to-object mapping is extremely flexible. Django's
approach is nice too.


PJE's response

Guido, you'll probably find that web.py ( http://webpy.org/ ) best suits your
style. It's a single module (~1000 lines) that does WSGI and an extremely
simple O-R mapping, with Cheetah for (non-XML) templates. If you don't like it,
I can't imagine which of the other dozens of frameworks out there you *would*
like. It's a bit rough around the edges (I suspect that its SQL quoting is
broken for some database quoting styles, for example), and it's nothing
particularly fancy, and it's about as far away as possible from something I or
Jim Fulton would write, so it shouldn't be the least bit scary. :)

With respect to WSGI, its original purpose wasn't to do "middleware"; it was
just a way to connect an application to arbitrary web servers, so the same
application can be run under mod_python, CGI, FastCGI, SCGI, in a Twisted or
other Python HTTP server, etc. That was and is the main point of WSGI. The
existence of middleware is just a natural side-effect of having a way to
connect an app to a server, in the same way that proxy servers and caches are a
side-effect of having HTTP.

But just as it was a good idea to specify some of the allowed behaviors of
proxies and caches in the HTTP spec, so too it was a good idea to address
middleware in the WSGI spec. Basically, WSGI in itself is just a Python
encoding of HTTP, nothing more.

Looking back at your post, I just realized you hadn't actually read the WSGI
PEP, so I should probably mention that it it's basically a port of the Java
servlet API, implemented in terms of simple callables and built-in data types
rather than having an object/method interface. 

Thus, any framework that's WSGI compliant support should give you the "server
independence" you're looking for. You just need a WSGI "gateway" for the
server, and find out how the framework exposes an "application" object to be
run by the gateway.


and or operators
----------------

and returns the right operand if the left is true. or returns the right operand
if the left is false. Otherwise they both return the left operand. They are
said to coalesce

Iterable and Iterator
---------------------

Because an iterator generally points to a single instance in a collection.
Iterable implies that one may obtain an iterator from an object to traverse
over its elements - and there's no need to iterate over a single instance,
which is what an iterator represents.

+1: A collection is iterable. An iterator is not iterable because it's not a
collection.

I will have to get this right - sockets accept only binary strings, not unicode.

>>> hasattr('lol','__next__')
False
>>> import collections
>>> isinstance('lol',collections.Iterable)
True
>>> for i in 'lol':
...     print(i)
...
l
o
l
>>> hasattr('lol','__iter__')
True


Basically, this whole patch (both parts of it) will be much better off iif
there is a clean way to say "a is an iterable but a is not a sequence", because
even though b'this is a message' is Iterable, we want to treat it differently
compared to, say, a generator object; we do NOT want to use the Iterator
features (iter, next) of it, we want to use the sequencey features (by sending
the whole chunk of it, by calling len)

---

A string is a sequence (isinstance('', Sequence) == True) and as any sequence
it is iterable (isinstance('', Iterable)). Though hasattr('', '__iter__') ==
False and it might be confusing. 

---

1. What is the difference between a bytes string and a unicode.

Byte string is the 8 bit string. Unicode is not a 8 bit string. Unicode strings
are a new generation of strings in themselves.


OpenerDirector
--------------

handlers is a list.
handle_open is a dictionary.
handle_error is a dictionary.
process_request is a dictionary.
process_response is a dictionary.

When handlers are getting added, it should not have attribute called
add_parent.
For each handler don't add the methods redirect_request, do_open, proxy_open

The methods which are like _error, _open, _request, _response are handled in a
special manner.  The error, open and response are called conditions.  And the
terms preceding them are called protocol.

When it is an error condition, some magic is done to find it's kind. The error
kind could have been got from the error_XXX, but instead, it the position is
determined and then it is extraced from the method name. Surprisingly, kind is
not used in the error block. Instead, in the OpenerDirector's handle_error
dictionary, for the protocol, which got an _error, a key is added, the value is
initially {}.

If the condition is _open, the kind is the protocol and the lookup is handle_open dictionary.
If the condition is _request, the kind is the protocol and the lookup process_request dictionary.
If the condition is _response, the kind is the protocol and the lookup is process_response.

Why is it that redirect_request, do_open and proxy_open are not handled.

Because it is a for loop on the methods of the handler, the kind and the lookup
is set at the end and it could be either for error, open, request or response.
But within the for loop, the handler having those methods is added. It is
bisect.insorted and then, again, it is bisect.insorted for all the handlers.

So, it seems that for that portion of the code, the appropriate handlers are
added. That is all.

What happens is, for any of these dictionaries, if it is an error, open,
request or response, dictionary method's setdefault is called for that protocol

There is a doubt when added=True comes in, handlers is list of all handlers is
added.

What's an add_unredirectedheader doing and what is it's purpose?  What is
self._call_chain's behavior?  The redirect_cache was not setting in, because
the object's parent method was calling and entirely new request, forgetting
about the current request. When made a change that request object is carrying
the information about the redirect, the cache hit was observed. Something along
the same lines would be good.



Extending Python
----------------
* To support extensions, the Python API (Application Programmers Interface)
  defines a set of functions, macros and variables that provide access to most
  aspects of the Python run-time system. The Python API is incorporated in a C
  source file by including the header "Python.h".

Bytes in API
------------

* Is ASCII with surrogateescape OK?
* Non Decodable Bytes in System Character Interfaces.
* PEP - 383 seems pretty cool. ( C-API allows reading of bytes whether it is a character or not).
* Issue4661


How is the Python Private methods and Attributes handled?
---------------------------------------------------------

They are handled by name mangling.

::

        >>> class Foo(object):
        ...     def __init__(self):
        ...         self.__baz = 42
        ...     def foo(self):
        ...         print self.__baz
        ...     
        >>> class Bar(Foo):
        ...     def __init__(self):
        ...         super(Bar, self).__init__()
        ...         self.__baz = 21
        ...     def bar(self):
        ...         print self.__baz
        ...
        >>> x = Bar()
        >>> x.foo()
        42
        >>> x.bar()
        21
        >>> print x.__dict__
        {'_Bar__baz': 21, '_Foo__baz': 42}

Unicode Characters
------------------

In python 2.x, the a string starting with u'' is a unicode object. It might
contain unicode code-point in the hexadecimal notation. If your terminal
supports it, then printing that unicode object will print the proper character.

chr - Gives the characters of length 1 from in the range 0 to 256. That is \x00
to \xff. It should be known that It borders the ASCII and it is the Latin-1
character set. 

It should also be known that \u00ff and \xff are both same.

Python Objects
--------------

All Python Objects have:

* A Unique identifier (returned by id())
* A Type (returned by type())
* And a content.

The Identifier and the type of the object cannot be changed. Only under limited
circumstances, user defined types can be changed.

Some objects allow you to change their content, while some objects will not
allow you to change the content.  The type is represented by type object which
knows more obout the objects of this type, like how many memory they occupy,
what methods they have.

Objects have 0 or more methods.
Objects have 0 or more names.

There is no variable in python. They are just names and that too within
namespaces. The names refer to a particular object on assignment.

Even if the objects have methods, you can never change its type or identity.
Things like attribute assignments and item references are just syntactic sugar.

Here's another easter egg:

>>> from __future__ import braces
    File "<stdin>", line 1
SyntaxError: not a chance

Coding Style: Readability Counts
================================

* One blank line between functions.
* Two blank lines between classes.
* Add a space after "," in dicts, lists, tuples, & argument lists, and after
  ":" in dicts, but not before.
* Put spaces around assignments & comparisons (except in argument lists).
* No spaces just inside parentheses or just before argument lists.
* No spaces just inside docstrings.
* ``joined_lower`` for functions, methods, attributes
* ``joined_lower`` or ``ALL_CAPS`` for constants
* ``StudlyCaps`` for classes
* ``camelCase`` **only** to conform to pre-existing conventions
* Attributes: ``interface``, ``_internal``, ``__private``

But try to avoid the ``__private`` form.  I never use it.

Long Lines & Continuations
==========================

* Keep lines below 80 characters in length.
* Use implied line continuation inside parentheses/brackets/braces::

       def __init__(self, first, second, third,
                    fourth, fifth, sixth):
           output = (first + second + third
                     + fourth + fifth + sixth)

* Use backslashes as a last resort::

       VeryLong.left_hand_side \
           = even_longer.right_hand_side()

* Backslashes are fragile; they must end the line they're on.  If you add a
  space after the backslash, it won't work any more.  Also, they're ugly.

Long Strings
============

* Note named string objects are **not** concatenated::

   >>> a = 'three'
   >>> b = 'four'
   >>> a b
     File "<stdin>", line 1
       a b
         ^
   SyntaxError: invalid syntax

* That's because this automatic concatenation is a feature of the Python
  parser/compiler, not the interpreter.  You must use the "+" operator to
  concatenate strings at run time.

  text = ('Long strings can be made up '
  'of several shorter strings.')

* The parentheses allow implicit line continuation.
* Multiline strings use triple quotes:
   ::

       """Triple
       double
       quotes"""

   ::

       '''\
       Triple
       single
       quotes\
       '''
* In the last example above (triple single quotes), note how the backslashes
  are used to escape the newlines.  This eliminates extra newlines, while
  keeping the text and quotes nicely left-justified.  The backslashes must be
  at the end of their lines.

Compound Statements
===================

Good::

    if foo == 'blah':
        do_something()
    do_one()
    do_two()
    do_three()

Bad::

    if foo == 'blah': do_something()
    do_one(); do_two(); do_three()

Dictionary ``setdefault`` Method (1)
====================================

.. container:: handout

   Here we have to initialize mutable dictionary values.  Each
   dictionary value will be a list.  This is the naïve way:

Initializing mutable dictionary values::

    equities = {}
    for (portfolio, equity) in data:
        if portfolio in equities:
            equities[portfolio].append(equity)
        else:
            equities[portfolio] = [equity]

.. class:: incremental

   ``dict.setdefault(key, default)`` does the job much more
   efficiently::

       equities = {}
       for (portfolio, equity) in data:
           equities.setdefault(portfolio, []).append(
                                                equity)

.. container:: handout

   ``dict.setdefault()`` is equivalent to "get, or set & get".  Or
   "set if necessary, then get".  It's especially efficient if your
   dictionary key is expensive to compute or long to type.

   The only problem with ``dict.setdefault()`` is that the default
   value is always evaluated, whether needed or not.  That only
   matters if the default value is expensive to compute.

   If the default value **is** expensive to compute, you may want to
   use the ``defaultdict`` class, which we'll cover shortly.


Dictionary ``setdefault`` Method (2)
====================================

.. container:: handout

   Here we see that the ``setdefault`` dictionary method can also be
   used as a stand-alone statement:

``setdefault`` can also be used as a stand-alone statement::

       navs = {}
       for (portfolio, equity, position) in data:
           navs.setdefault(portfolio, 0)
           navs[portfolio] += position * prices[equity]

.. container:: handout

   The ``setdefault`` dictionary method returns the default value, but
   we ignore it here.  We're taking advantage of ``setdefault``'s side
   effect, that it sets the dictionary value only if there is no value
   already.


``defaultdict``
===============

New in Python 2.5.

.. container:: handout

   ``defaultdict`` is new in Python 2.5, part of the ``collections``
   module.  ``defaultdict`` is identical to regular dictionaries,
   except for two things:

   * it takes an extra first argument: a default factory function; and
   * when a dictionary key is encountered for the first time, the
     default factory function is called and the result used to
     initialize the dictionary value.

   There are two ways to get ``defaultdict``:

   * import the ``collections`` module and reference it via the
     module,

     .. container:: spoken

        |==>|

   * or import the ``defaultdict`` name directly:

     .. container:: spoken

        |==>|

.. class:: incremental

   ::

       import collections
       d = collections.defaultdict(...)

   ::

       from collections import defaultdict
       d = defaultdict(...)

.. container:: handout

   Here's the example from earlier, where each dictionary value must
   be initialized to an empty list, rewritten as with ``defaultdict``:

.. class:: incremental

   ::

       from collections import defaultdict

       equities = defaultdict(list)
       for (portfolio, equity) in data:
           equities[portfolio].append(equity)

.. container:: handout

   There's no fumbling around at all now.  In this case, the default
   factory function is ``list``, which returns an empty list.

   This is how to get a dictionary with default values of 0: use
   ``int`` as a default factory function:

.. class:: incremental

   ::

       navs = defaultdict(int)
       for (portfolio, equity, position) in data:
           navs[portfolio] += position * prices[equity]

.. container:: handout

   You should be careful with ``defaultdict`` though.  You cannot get
   ``KeyError`` exceptions from properly initialized ``defaultdict``
   instances.  You have to use a "key in dict" conditional if you need
   to check for the existence of a specific key.


Building & Splitting Dictionaries
=================================

Here's a useful technique to build a dictionary from two lists (or sequences):
one list of keys, another list of values.::

       given = ['John', 'Eric', 'Terry', 'Michael']
       family = ['Cleese', 'Idle', 'Gilliam', 'Palin']
       pythons = dict(zip(given, family))
       >>> pprint.pprint(pythons)
       {'John': 'Cleese',
        'Michael': 'Palin',
        'Eric': 'Idle',
        'Terry': 'Gilliam'}

Note that the order of the results of .keys() and .values() is different from
the order of items when constructing the dictionary.  The order going in is
different from the order coming out.  This is because a dictionary is
inherently unordered.  However, the order is guaranteed to be consistent (in
other words, the order of keys will correspond to the order of values), as long
as the dictionary isn't changed between calls.


Truth Values
============

The ``True`` and ``False`` names are built-in instances of type ``bool``,
Boolean values.  Like ``None``, there is only one instance of each.

=================================  ================================
False                              True
=================================  ================================
``False`` (== 0)                   ``True`` (== 1)

``""`` (empty string)              any string but ``""`` (``" "``, 
                                   ``"anything"``)

``0``, ``0.0``                     any number but ``0`` (1, 0.1, -1, 3.14)

``[]``, ``()``, ``{}``, ``set()``  any non-empty container
                                   (``[0]``, ``(None,)``, ``['']``)

``None``                           almost any object that's not
                                   explicitly False
=================================  ================================


Index & Item (2): ``enumerate``
===============================

The ``enumerate`` function takes a list and returns (index, item)
pairs:

>>> print list(enumerate(items))
[(0, 'zero'), (1, 'one'), (2, 'two'), (3, 'three')]

We need use a ``list`` wrapper to print the result because ``enumerate`` is a
lazy function: it generates one item, a pair, at a time, only when required.  A
``for`` loop is one place that requires one result at a time.  ``enumerate`` is
an example of a *generator*. ``print`` does not take one result at a time -- we
want the entire result, so we have to explicitly convert the generator into a
list when we print it.

An example showing how the ``enumerate`` function actually returns an iterator
(a generator is a kind of iterator).::

   >>> enumerate(items)
   <enumerate object at 0x011EA1C0>
   >>> e = enumerate(items)
   >>> e.next()
   (0, 'zero')
   >>> e.next()
   (1, 'one')
   >>> e.next()
   (2, 'two')
   >>> e.next()
   (3, 'three')
   >>> e.next()
   Traceback (most recent call last):
     File "<stdin>", line 1, in ?
   StopIteration


Other languages have "variables"
================================

In many other languages, assigning to a variable puts a value into a box.

Python has "names"
==================

In Python, a "name" or "identifier" is like a parcel tag (or nametag) attached
to an object.

Here, an integer 1 object has a tag labelled "a".  If we reassign to "a", we
just move the tag to another object:

Now the name "a" is attached to an integer 2 object.

The original integer 1 object no longer has a tag "a".  It may live on, but we
can't get to it through the name "a".  (When an object has no more references
or tags, it is removed from memory.)

If we assign one name to another, we're just attaching another nametag to an
existing object:

           b = a

The name "b" is just a second tag bound to the same object as "a".

Although we commonly refer to "variables" even in Python (because it's common
terminology), we really mean "names" or "identifiers".  In Python, "variables"
are nametags for values, not labelled boxes.

If you get nothing else out of this tutorial, I hope you understand how Python
names work.  A good understanding is certain to pay dividends, helping you to
avoid cases like this:

Default Parameter Values
========================

This is a common mistake that beginners often make.  Even more advanced
programmers make this mistake if they don't understand Python names.

::

    def bad_append(new_item, a_list=[]):
        a_list.append(new_item)
        return a_list


The problem here is that the default value of ``a_list``, an empty list, is
evaluated at function definition time.  So every time you call the function,
you get the **same** default value.  Try it several times:

   ::

       >>> print bad_append('one')
       ['one']

   ::

       >>> print bad_append('two')
       ['one', 'two']

Lists are a mutable objects; you can change their contents.  The correct way to
get a default list (or dictionary, or set) is to create it at run time instead,
**inside the function**.::

       def good_append(new_item, a_list=None):
           if a_list is None:
               a_list = []
           a_list.append(new_item)
           return a_list

Advanced % String Formatting
============================

What many people don't realize is that there are other, more flexible ways to
do string formatting:

By name with a dictionary::

       values = {'name': name, 'messages': messages}
       print ('Hello %(name)s, you have %(messages)i '
              'messages' % values)

Here we specify the names of interpolation values, which are looked up in the
supplied dictionary.

Notice any redundancy?  The names "name" and "messages" are already defined in
the local namespace.  We can take advantage of this.

By name using the local namespace::

       print ('Hello %(name)s, you have %(messages)i '
              'messages' % locals())


The namespace of an object's instance attributes is just a dictionary,
``self.__dict__``.

By name using the instance namespace::

       print ("We found %(error_count)d errors"
              % self.__dict__)

Equivalent to, but more flexible than::

       print ("We found %d errors"
              % self.error_count)

List Comprehensions
===================

List comprehensions ("listcomps" for short) are syntax shortcuts for this
general pattern.

As a list comprehension::

       new_list = [fn(item) for item in a_list
                   if condition(item)]

Listcomps are clear & concise, up to a point.  You can have multiple
``for``-loops and ``if``-conditions in a listcomp, but beyond two or three
total, or if the conditions are complex, I suggest that regular ``for`` loops
should be used.  Applying the Zen of Python, choose the more readable way.::

   For example, a list of the squares of 0–9:

   >>> [n ** 2 for n in range(10)]
   [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

   A list of the squares of odd 0–9:

   >>> [n ** 2 for n in range(10) if n % 2]
   [1, 9, 25, 49, 81]


Generator Expressions
=====================

Let's sum the squares of the numbers up to 100:
As a loop::

       total = 0
       for num in range(1, 101):
           total += num * num

We can use the ``sum`` function to quickly do the work for us, by building the
appropriate sequence.

As a list comprehension::

       total = sum([num * num for num in range(1, 101)])

As a generator expression::

       total = sum(num * num for num in xrange(1, 101))


Generator expressions ("genexps") are just like list comprehensions, except
that where listcomps are greedy, generator expressions are lazy.  Listcomps
compute the entire result list all at once, as a list.  Generator expressions
compute one value at a time, when needed, as individual values.  This is
especially useful for long sequences where the computed list is just an
intermediate step and not the final result.

In this case, we're only interested in the sum; we don't need the intermediate
list of squares.  We use ``xrange`` for the same reason: it lazily produces
values, one at a time.

For example, if we were summing the squares of several billion integers, we'd
run out of memory with list comprehensions, but generator expressions have no
problem.  This does take time, though!  

::
       total = sum(num * num
                   for num in xrange(1, 1000000000))

The difference in syntax is that listcomps have square brackets, but generator
expressions don't.  Generator expressions sometimes do require enclosing
parentheses though, so you should always use them.

Rule of thumb:

* Use a list comprehension when a computed list is the desired end result.
* Use a generator expression when the computed list is just an intermediate
  step.


We needed a dictionary mapping month numbers (both as string and as integers)
to month codes for futures contracts.  It can be done in one logical line of
code.

The way this works is as follows:

* The ``dict()`` built-in takes a list of key/value pairs (2-tuples).
* We have a list of month codes (each month code is a single letter, and a
  string is also just a list of letters).  We enumerate over this list to get
  both the month code and the index.
* The month numbers start at 1, but Python starts indexing at 0, so the month
  number is one more than the index.
* We want to look up months both as strings and as integers.  We can use the
  ``int()`` and ``str()`` functions to do this for us, and loop over them.

Recent example::

        month_codes = dict((fn(i+1), code)
            for i, code in enumerate('FGHJKMNQUVXZ')
            for fn in (int, str))

   ``month_codes`` result::

       { 1:  'F',  2:  'G',  3:  'H',  4:  'J', ...
        '1': 'F', '2': 'G', '3': 'H', '4': 'J', ...}


Sorting
=======

::

    a_list.sort()

(Note that the list is sorted in-place: the original list is sorted, and the
``sort`` method does **not** return the list or a copy.)

But what if you have a list of data that you need to sort, but it doesn't sort
naturally (i.e., sort on the first column, then the second column, etc.)?  You
may need to sort on the second column first, then the fourth column.
We can use list's built-in ``sort`` method with a custom function::

       def custom_cmp(item1, item2):
           return cmp((item1[1], item1[3]),
                      (item2[1], item2[3]))

       a_list.sort(custom_cmp)

This works, but it's extremely slow for large lists.

Sorting with DSU *
==================

DSU = Decorate-Sort-Undecorate

\* Note: DSU is often no longer necessary.  See the next section,
`Sorting With Keys`_ for the new approach.

Instead of creating a custom comparison function, we create an auxiliary list
that *will* sort naturally.::

       # Decorate:
       to_sort = [(item[1], item[3], item)
                  for item in a_list]

       # Sort:
       to_sort.sort()

       # Undecorate:
       a_list = [item[-1] for item in to_sort]

The first line creates a list containing tuples: copies of the sort terms in
priority order, followed by the complete data record.The second line does a
native Python sort, which is very fast and efficient. The third line retrieves
the **last** value from the sorted list.  Remember, this last value is the
complete data record.  We're throwing away the sort terms, which have done
their job and are no longer needed. This is a tradeoff of space and complexity
against time.  Much simpler and faster, but we do need to duplicate the
original list.

Sorting With Keys
=================

Python 2.4 introduced an optional argument to the ``sort`` list method, "key",
which specifies a function of one argument that is used to compute a comparison
key from each list element.  For example: ::

       def my_key(item):
           return (item[1], item[3])

       to_sort.sort(key=my_key)

The function ``my_key`` will be called once for each item in the ``to_sort``
list.

You can make your own key function, or use any existing one-argument function
if applicable:

   * ``str.lower`` to sort alphabetically regarless of case.
   * ``len`` to sort on the length of the items (strings or containers).
   * ``int`` or ``float`` to sort numerically, as with numeric strings
     like "2", "123", "35".


Generators
==========

We've already seen generator expressions.  We can devise our own arbitrarily
complex generators, as functions: ::

    def my_range_generator(stop):
        value = 0
        while value < stop:
            yield value
            value += 1

    for i in my_range_generator(10):
        do_something(i)

The ``yield`` keyword turns a function into a generator.  When you call a
generator function, instead of running the code immediately Python returns a
generator object, which is an iterator; it has a ``next`` method.  ``for``
loops just call the ``next`` method on the iterator, until a ``StopIteration``
exception is raised.  You can raise ``StopIteration`` explicitly, or implicitly
by falling off the end of the generator code as above.

Generators can simplify sequence/iterator handling, because we don't need to
build concrete lists; just compute one value at a time.  The generator function
maintains state.

This is how a ``for`` loop really works.  Python looks at the sequence supplied
after the ``in`` keyword.  If it's a simple container (such as a list, tuple,
dictionary, set, or user-defined container) Python converts it into an
iterator.  If it's already an iterator, Python uses it directly.

Then Python repeatedly calls the iterator's ``next`` method, assigns the return
value to the loop counter (``i`` in this case), and executes the indented code.
This is repeated over and over, until ``StopIteration`` is raised, or a
``break`` statement is executed in the code.

A ``for`` loop can have an ``else`` clause, whose code is executed after the
iterator runs dry, but **not** after a ``break`` statement is executed.  This
distinction allows for some elegant uses.  ``else`` clauses are not always or
often used on ``for`` loops, but they can come in handy.  Sometimes an ``else``
clause perfectly expresses the logic you need.

For example, if we need to check that a condition holds on some item, any item,
in a sequence::

       for item in sequence:
           if condition(item):
               break
       else:
           raise Exception('Condition not satisfied.')

Example Generator
=================

Filter out blank rows from a CSV reader (or items from a list)::

    def filter_rows(row_iterator):
        for row in row_iterator:
            if row:
                yield row

    data_file = open(path, 'rb')
    irows = filter_rows(csv.reader(data_file))


Reading Lines From Text/Data Files
==================================

::

    datafile = open('datafile')
    for line in datafile:
        do_something(line)

This is possible because files support a ``next`` method, as do other
iterators: lists, tuples, dictionaries (for their keys), generators.

There is a caveat here: because of the way the buffering is done, you cannot
mix ``.next`` & ``.read*`` methods unless you're using Python 2.5+.

Importing
=========

::

        from module import *

You've probably seen this "wild card" form of the import statement.  You may
even like it.  **Don't use it.**


The ``from module import *`` wild-card style leads to namespace pollution.
You'll get things in your local namespace that you didn't expect to get.  You
may see imported names obscuring module-defined local names.  You won't be able
to figure out where certain names come from.  Although a convenient shortcut,
this should not be in production code.

Moral: **don't use wild-card imports!**

It's much better to:

* reference names through their module (fully qualified identifiers),
* import a long module using a shorter name (alias; recommended),
* or explicitly import just the names you need.


Namespace pollution alert!  ::

       import module
       module.name

Or import a long module using a shorter name (alias): ::

       import long_module_name as mod
       mod.name


Or explicitly import just the names you need: ::

       from module import name
       name


Note that this form doesn't lend itself to use in the interactive interpreter,
where you may want to edit and "reload()" a module.

Modules & Scripts
=================

To make a simultaneously importable module and executable script::

    if __name__ == '__main__':
        # script code here


When imported, a module's ``__name__`` attribute is set to the module's file
name, without ".py".  So the code guarded by the ``if`` statement above will
not run when imported.  When executed as a script though, the ``__name__``
attribute is set to "__main__", and the script code *will* run.

Except for special cases, you shouldn't put any major executable code at the
top-level.  Put code in functions, classes, methods, and guard it with ``if
__name__ == '__main__'``.


Module Structure
================

This is how a module should be structured.::

    """module docstring"""

    # imports
    # constants
    # exception classes
    # interface functions
    # classes
    # internal functions & classes

    def main(...):
        ...

    if __name__ == '__main__':
        status = main()
        sys.exit(status)

Packages
========

::

    package/
        __init__.py
        module1.py
        subpackage/
            __init__.py
            module2.py


- Used to organize your project.
- Reduces entries in load-path.
- Reduces import name conflicts.

Example::

import package.module1
from package.subpackage import module2
from package.subpackage.module2 import name

In Python 2.5 we now have absolute and relative imports via a future import::

       from __future__ import absolute_import

Simple is Better Than Complex
=============================

Debugging is twice as hard as writing the code in the first place.  Therefore,
if you write the code as cleverly as possible, you are, by definition, not
smart enough to debug it.

    -- Brian W. Kernighan, co-author of *The C Programming Language*
       and the "K" in "AWK"


In other words, keep your programs simple!


* "Python Objects", Fredrik Lundh,
  http://www.effbot.org/zone/python-objects.htm

* "How to think like a Pythonista", Mark Hammond,
  http://python.net/crew/mwh/hacks/objectthink.html

* "Python main() functions", Guido van Rossum,
  http://www.artima.com/weblogs/viewpost.jsp?thread=4829

* "Python Idioms and Efficiency",
  http://jaynes.colorado.edu/PythonIdioms.html

* "Python track: python idioms",
  http://www.cs.caltech.edu/courses/cs11/material/python/misc/python_idioms.html

* "Be Pythonic", Shalabh Chaturvedi,
  http://shalabh.infogami.com/Be_Pythonic2

* "Python Is Not Java", Phillip J. Eby,
  http://dirtsimple.org/2004/12/python-is-not-java.html

* "What is Pythonic?", Martijn Faassen,
  http://faassen.n--tree.net/blog/view/weblog/2005/08/06/0

* "Sorting Mini-HOWTO", Andrew Dalke,
  http://wiki.python.org/moin/HowTo/Sorting

* "Python Idioms", http://www.gungfu.de/facts/wiki/Main/PythonIdioms

print as a function in python3.
New string model
classic class vs new style class and everything is new style class.
Updated Syntax for Exceptions
Improved Exception Handling Mechanism,
Chaging the Division Operator.
True Division PEP 238
New Binary Literals, bin, oct and hex
Dictionary methods PEP 3106
Type Updates and io class ( PEP 3116)
Dictionary Comprehensions
set comprehensions
tuple methods - count and index.
Changes to reserved keywords.
removed - print and exec
added - as, with, nonlocal, True and False

Changes to Operators.
Removed <> and backticks
Added - bytes, bytearray and range
Removed - basestring, buffer, file, long, unicode and xrange

use of 2to3 tool.

Python 2.6 status and Python 2.7 plan.
Python 3.1 status and further plans.

urllib 
======

functions
---------
* urlopen
* install_opener
* build_opener
* request_host
* _parse_proxy
* randombytes
* parse_keqv_list
* parse_http_list

class
-----
* Request
* OpenerDirector
* BaseHandler
  * HTTPErrorProcessor
  * HTTPCookieProcessor
  * HTTPDefaultErrorHandler
  * HTTPRedirectHandler
  * ProxyHandler
  * AbstractHTTPHandler
  * UnknownHandler
  * FileHandler
  * FTPHandler
  * CacheFTPHandler

* AbstractHTTPHandler
  * HTTPHandler
  * HTTPSHandler

* HTTPPasswordMgr
  * HTTPPasswordMgrWithDefaultRealm

* AbstractBasicAuthHandler

* AbstractBasicAuthHandler, BaseHandler
  * HTTPBasicAuthHandler
  * ProxyBasicAuthHandler

* AbstractDigestAuthHandler

* BaseHandler, AbstractDigestAuthHandler
  * HTTPDigestAuthHandler
  * ProxyDigestAuthHandler


urlopen -> build_opener -> OpenerDirector() -> OpenerDirector.add_handler for
each class and handler -> OpenerDirector.open() method on the composite object.
-> Request -> returns stateful url -> protocol_request is called -> _open ->
and protocol_response is called and returned. The handler is invoked in the
specific order as specified by the Handler attribute.

In order to setup a password for your apache based site, in the
/var/www/.htaccess file specify the username and password as senthil:senthil

Some clients support the no_proxy environment variable that specifies a set of
domains for which the proxy should not be consulted; the contents is a
comma-separated list of domain names, with an optional :port part.

WWW-Authenticate

The WWW-Authenticate response-header field must be included in 401
(unauthorized) response messages. The field value consists of at least one
challenge that indicates the authentication scheme(s) and parameters applicable
to the Request-URI.

       WWW-Authenticate = "WWW-Authenticate" ":" 1#challenge

The HTTP access authentication process is described in Section 11. User agents
must take special care in parsing the WWW-Authenticate field value if it
contains more than one challenge, or if more than one WWW-Authenticate header
field is provided, since the contents of a challenge may itself contain a
comma-separated list of authentication parameters. 

Following are some of the notes I took, while working on urllib patches.  It
should be a handy reference when working on bugs again.

RFC 3986 Notes:

A URI is a sequence of characters that is not always represented as a sequence
of octets.Percent-encoded octets may be used within a URI to represent
characters outside the range of the US-ASCII coded character set.

Specification uses Augmented Backus-Naur Form (ABNF) notation of RFC2234,
including the following core ABNF syntax rules defined by that specification:
ALPHA (letters), CR ( carriage return), DIGIT (decimal digits), DQUOTE (double
quote), HEXDIG (hexadecimal digits), LF (line feed) and SP (space).

Section 1 of RFC3986 is very generic. Understand that URI should be
transferable and single generic syntax should denote the whole range of URI
schemes.URI Characters are, in turn, frequently encoded as octets for transport
or presentation. This specification does not mandate any character encoding for
mapping between URI characters and the octets used to store or transmit those
characters.

pct-encoded = "%" HEXDIG HEXDIG

For consistency, uri producers and normalizers should use uppercase
hexadecimal digits, for all percent - encodings.

reserved = gen-delims / sub-delims
gen-delims = ":" / "/" / "?" / "#" / "[" / "]" / "@"
sub-delims = "!" / "$" / "&" / "'" / "(" / ")"
/ "*" / "+" / "," / ";" / "="

unreserved = ALPHA / DIGIT / "-" / "." / "_" / "~"

When a new URI scheme defines a component that represents textual data
consisting of characters from the Universal Character Set, the data should
first be encoded as octets according to the UTF-8 character encoding [STD63];
then only those octets that do not correspond to characters in the unreserved
set should be percent- encoded. For example, the character A would be
represented as "A", the character LATIN CAPITAL LETTER A WITH GRAVE would be
represented as "%C3%80", and the character KATAKANA LETTER A would be
represented as "%E3%82%A2".

How that is being used encoding reservered characters within data. Transmission
of url from local to public when using a different encoding - translate at the
interface level.

URI = scheme ":" hier-part [ "?" query ] [ "#" fragment ]

hier-part = "//" authority path-abempty
/ path-absolute
/ path-rootless
/ path-empty

Many URI schemes include a hierarchical element for a naming
authority so that governance of the name space defined by the
remainder of the URI is delegated to that authority (which may, in
turn, delegate it further).

:: 
        userinfo = *( unreserved / pct-encoded / sub-delims / ":" )
        host = IP-literal / IPv4address / reg-name

In order to disambiguate the syntax host between IPv4address and reg-name, we
apply the "first-match-wins" algorithm. A host identified by an Internet
Protocol literal address, version 6 [RFC3513] or later, is distinguished by
enclosing the IP literal within square brackets ("[" and "]"). This is the only
place where square bracket characters are allowed in the URI syntax.

::
        IP-literal = "[" ( IPv6address / IPvFuture ) "]"

        IPvFuture = "v" 1*HEXDIG "." 1*( unreserved / sub-delims / ":" )

        IPv6address = 6( h16 ":" ) ls32
        / "::" 5( h16 ":" ) ls32
        / [ h16 ] "::" 4( h16 ":" ) ls32
        / [ *1( h16 ":" ) h16 ] "::" 3( h16 ":" ) ls32
        / [ *2( h16 ":" ) h16 ] "::" 2( h16 ":" ) ls32
        / [ *3( h16 ":" ) h16 ] "::" h16 ":" ls32
        / [ *4( h16 ":" ) h16 ] "::" ls32
        / [ *5( h16 ":" ) h16 ] "::" h16
        / [ *6( h16 ":" ) h16 ] "::"

        ls32 = ( h16 ":" h16 ) / IPv4address
        ; least-significant 32 bits of address

        h16 = 1*4HEXDIG
        ; 16 bits of address represented in hexadecimal

        IPv4address = dec-octet "." dec-octet "." dec-octet "." dec-octet

        dec-octet = DIGIT ; 0-9
        / %x31-39 DIGIT ; 10-99
        / "1" 2DIGIT ; 100-199
        / "2" %x30-34 DIGIT ; 200-249
        / "25" %x30-35 ; 250-255

        reg-name = *( unreserved / pct-encoded / sub-delims )


Non-ASCII characters must first be encoded according to UTF-8 [STD63], and then
each octet of the corresponding UTF-8 sequence must be percent-encoded to be
represented as URI characters.  When a non-ASCII registered name represents an
internationalized domain name intended for resolution via the DNS, the name
must be transformed to the IDNA encoding [RFC3490] prior to name lookup.

Section 3 was about sub-components and their structure and if they are
represented in NON ASCII how to go about with encoding/decoding that.

::

        path = path-abempty ; begins with "/" or is empty
        / path-absolute ; begins with "/" but not "//"
        / path-noscheme ; begins with a non-colon segment
        / path-rootless ; begins with a segment
        / path-empty ; zero characters

        path-abempty = *( "/" segment )
        path-absolute = "/" [ segment-nz *( "/" segment ) ]
        path-noscheme = segment-nz-nc *( "/" segment )
        path-rootless = segment-nz *( "/" segment )
        path-empty = 0<pchar>
        segment = *pchar
        segment-nz = 1*pchar
        segment-nz-nc = 1*( unreserved / pct-encoded / sub-delims / "@" )
        ; non-zero-length segment without any colon ":"

        pchar = unreserved / pct-encoded / sub-delims / ":" / "@"

        relative-ref = relative-part [ "?" query ] [ "#" fragment ]

        relative-part = "//" authority path-abempty
        / path-absolute
        / path-noscheme
        / path-empty

Section 4 was on the usage aspects and heuristics used in determining in the
scheme in the normal usages where scheme is not given.  Base uri must be
stripped of any fragment components prior to it being used as a Base URI.

Section 5 was on relative reference implementation algorithm. I had covered
them practically in the Python urlparse module.Section 6 was on Normalization
of URIs for comparision and various normalization practices that are used.

Dissecting urlparse:
--------------------

* __all__ methods provides the public interfaces to all the methods like
urlparse, urlunparse, urljoin, urldefrag, urlsplit and urlunsplit.

* then there is classification of schemes like uses_relative, uses_netloc,
non_hierarchical, uses_params, uses_query, uses_fragment

- there should be defined in an rfc most probably 1808.

- there is a special '' blank string, in certain classifications, which
means that apply by default.

* valid characters in scheme name should be defined in 1808.

* class ResultMixin is defined to provide username, password, hostname and
port.

* The behaviour of the public methods urlparse, urlunparse, urlsplit and
urlunsplit and urldefrag matter most.

urlparse - scheme, netloc, path, params, query and fragment.
urlunparse will take those parameters and construct the url back.

urlsplit - scheme, netloc, path, query and fragment.
urlunsplit - takes these parameters (scheme, netloc, path, query and fragment)
and returns a url.

As per the RFC3986, the url is split into: 

scheme, authority, path, query, frag = url

The authority part in turn can be split into the sections:
user, passwd, host, port = authority

The following line is the regular expression for breaking-down a
well-formed URI reference into its components.

:: 

        ^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?
        12 3 4 5 6 7 8 9

        scheme = $2
        authority = $4
        path = $5
        query = $7
        fragment = $9


The urlsplit functionality in the urllib can be moved to new regular
expression based parsing mechanism.

From man uri, which confirms to rfc2396 and HTML 4.0 specs.

* An absolute identifier refers to a resource independent of context, while a
  relative identifier refers to a resource by describing the difference from
  the current context.

* A path segment while contains a colon character ':' can't be used as the
  first segment of a relative URI path. Use it like this './file:path'

* A query can be given in the archaic "isindex" format, consisting of a word or
  a phrase and not including an equal sign (=). If = is there, then it must be
  after & like &key=value format.

Character Encodings:

* Reserved characters: ;/?:@&=+$,
* Unreserved characters: ALPHA, DIGITS, -_.!~*'()

An escaped octet is encoded as a character triplet consisting of the percent
character '%' followed by the two hexadecimal digits representing the octet
code.HTML 4.0 specification section B.2 recommends the following, which should
be considered best available current guidance:

1) Represent each non-ASCII character as UTF-8
2) Escape those bytes with the URI escaping mechanism, converting each byte to
   %HH where HH is the hexadecimal notation of the byte value.

One of the important changes when adhering to RFC3986 is parsing of IPv6
addresses.

CacheFTPHandler testcases are hard to write. 

Here's how the control goes.

1) There is an url with two '//'s in the path.
2) The call is data = urllib2.urlopen(url).read()
3) urlopen calls the build_opener. build_opener builds the opener using (tuple)
of handlers.
4) opener is an instance of OpenerDirector() and has default HTTPHandler and
HTTPSHandler.
5) When the Request call is made and the request has 'http' protocol, then
http_request method is called.

::

         HTTPHandler has http_request method which is
         AbstractHTTPHandler.do_request_ Now, for this issue we get to the
         do_request_ method and see that host is set in the do_request_ method
         in the get_host() call.

         request.get_selector() is the call which is causing this particular
         issue of "urllib2 getting confused with path containing //".
         .get_selector() method returns self.__r_host.

Now, when proxy is set using set_proxy(), self.__r_host is self.__original (
The original complete url itself), so the get_selector() call is returns the
sel_url properly and we can get the host from the splithost() call on the
sel_url.

When proxy is not set, and the url contains '//' in the path segment, then
.get_host() (step 7) call would have seperated the self.host and self.__r_host
(it pointing to the rest of the url) and .get_selector() simply returns this
(self.__r_host, rest of the url expect host. Thus causing call to fail.

9) Before the fix, request.add_unredirected_header('Host', sel_host or host)
had the escape mechanism set for proper urls wherein with sel_host is not set
and the host is used. Unfortunately, that failed when this bug caused sel_host
to be set to self.__r_host and Host in the headers was being setup wrongly (
rest of the url).

The patch which was attached appropriately fixed the issue. I modified and
included for py3k.

* urllib2 in python 3k was divided into urllib.request and urllib.error. I was
  thinking if the urllib.response class is included; but no, response object is
  nothing but a addinfourl object.

Example of  Smart Redirect Handler 
----------------------------------

::

        import urllib2

        class SmartRedirectHandler(urllib2.HTTPRedirectHandler):
            def http_error_302(self, req, fp, code, msg, headers):
                result = urllib2.HTTPRedirectHandler.http_error_302(self, req, fp,
                                                                         code, msg,
                                                                         headers)
                result.status = code
                return result

        request = urllib2.Request("http://localhost/index.html")
        opener = urllib2.build_opener(SmartRedirectHandler())
        obj = opener.open(request)
        print 'I capture the http redirect code:', obj.status
        print 'Its been redirected to:', obj.url

* Apache 2.0 supports IPv6.

::
        phoe6:  I want to setup a test server which will do a redirect ( I know
        how to do that), but with a delay. So that when I am testing my client,
        I can test the clients timeout. Can someone give me suggestions as how
        can i go about this?

        jMCg: phoe6: http://httpd.apache.org/docs/2.2/mod/mod_ext_filter.html#examples

* apache is configured by placing directives in configuration files. the main configuration file is called apache2.conf
* Other configuration files are added by Include directive.

How is the HTTP response given by the urllib?
GetRequestHandler which takes the responses as the parameter and returns a handler.
What does the GetRequestHandler do?
It takes responses as one of its argument.
Implements a FakeHTTPRequestHandler which is extending BaseHTTPRequestHandler.
BaseHTTPRequestHandler implements do_GET, do_POST and send_head
The send_head method when it is returning the body it is sending it properly.

Why is that the response is getting trimmed to 49042?

Strings, Bytes and Python 3
===========================

Q: Convert a Hexadecimal Strings ("FF","FFFF") to Decimal
A: int("FF",16) and int("FFFF",16)

Q: Represent 255 in Hexadecimal.
A: print '%X' % 255

If you want to encode a string in base16, base32 or base64 encoding, the python
standard library provides base64 module which is based on the RFC 3564.

What is the difference between string, bytes and buffer?

In Python 2.0, the normal strings were of 8 bit characters and for representing
Characters from foreign languages, a special kind of class was provided, which
was called Unicode String.

The string object when they had to be stored or transfered over the wire, they
had to be encoded into bytes. As normal string character was 8 bits, they
directly corresponded to one byte and Python2.0 had an implicit ascii encoding
which conveniently encoded them to 8-bit bytes.  The Unicode object had to have
an encoding specified, which encoded the unicoded strings into sequence of
bytes.

Just as string object had an encode method, to convert to bytes, the bytes
object had a decode method, that takes a character encoding an returns a
string.

In Python 3.0, the normal string was made the Unicode String. However, the 8bit
character datatype was still retained and it was called as bytes.

In other words. Python2.6 supports both simple text and binary data in its
normal string type and provides an alternative string type for non-ASCII type
called the Unicode text. Whereas Python3.0 supports Unicode text in its normal
string type, with ASCII being treated a simple type of unicode and provides an
alternative string type for binary data called bytes.

What is the difference between linefeed and a newline?
newline is composed of Linefeed character. 

What is class bytearray?

A Byte is 8 bits and array is a sequence. A Bytearray object can be constructed
using integers only or text string along with an encoding or using another
bytes or bytearray or any other object implementing a buffer API. More
importantly, it is mutable.

Python3 comes with 3 types of string objects, one for textual data and two for
binary data.

 * str - for representing Unicode text.
 * bytes - for representing Binary data.
 * bytearray - a mutable flavor of bytes type.

3.0 str type defined an immutable sequence of characters (not neccesarily
bytes), which may be either normal text such as ASCII or multi byte UTF-8.  A
new type called bytes was introduced to support truly binary data.

In 2.x; the general string type filled this binary data role, because strings
were just a sequence of bytes. In 3.0, the bytes type is defined as an
immutable sequence of 8-bit integers representing absolute byte values.  A 3.0
bytes object really is a sequence of small integers, each of which is in the
range 0 through 255; indexing a bytes returns int, slicing one returns another
bytes and running list() on one returns a list of integers, not characters.
While they were at it, the Python developers also added bytearray type in 3.0,
a variant of bytes, which is mutable and also supports in-place changes. The
bytearray type supports the usual string operations that str and bytes do, but
has inplace change operations also.

Because str and bytes are sharply differentiated by the language, the net
effect is that you must decide whether your data is text or binary in nature
and use 'str' or 'bytes' objects to represent its content in your script
respectively.

Image or audio file or packed data processed with the struct module is an
exmaple of bytes object. Python3.0 has a sharp distinction between text, binary
data and files.

::
        $ python
        Python 2.6.2 (release26-maint, Apr 19 2009, 01:58:18) [GCC 4.3.3] on linux2
        >>> import sys
        >>> print sys.getdefaultencoding()
        ascii
        >>> 
        07:56 PM:senthil@:~/uthcode/source
        $ python3.1
        Python 3.1a2+ (py3k:71811, Apr 22 2009, 20:47:22) [GCC 4.3.2] on linux2
        >>> import sys
        >>> print(sys.getdefaultencoding())
        utf-8
        >>> 

Ultimately, the mode in which you open a file will dictate which type of object
your script will use to represent its contents.

 * bytes or binary mode files.
 * bytearray to update data without making copies of it in memory.
 * If you are processing something that is textual in nature, such as program
   output, HTML, internationalized text, and CSV or XML files, you probably
   want to use str or text mode files.


Unicode Notes
=============

A good introductory document for getting started with Unicode is, 
`Joel's article on Unicode`_

Trivia:
In ASCII when you press CNTL, you subtract 64 from the value of the next
character.  So BELL is ASCII 7, which is CNTL+G, (CNTL is 64) and G is 71.

IN ASCII, the Codes below 32 were called unprintable. The space was 32 and
letter A was 65.  This could conveniently be stored in 7 bits.  Most computers
in those days were using 8 bit bytes, so not only you could store all the ASCII
characters, you had a whole bit to spare.  Because bytes have room for upto
eight bits, lots of people got into thinking, "gosh, we can use codes 128-255
for our own purposes." :) Eventually, this OEM free-for-all got codified in the
ANSI standard.  In the ANSI standard, everyone agreed for bottom 128 but not
the upper limits.  Asian alphabets have thousands of letters, which were never
going to fit into 8 bits.  This was actually solved by a messy system called
DBCS, the "double byte character set" in which some letters were stored in one
byte and others took two bytes.It was easy to move forward in a string, but it
was impossible to move backwards in the string.  Programmers were encouraged
not to use s++ or s-- but instead rely on Windows' AnsiNext and AnsiPrev
functions which knew how to deal with that mess.

Unicode

Unicode was a brave effort to create a single character set that included every
reasonable writing system on the planet.  Some people are under the
mis-conception that unicode is simply a 16-bit code where each character takes
16 bits and therefore there are 65,536 possible characters, which is incorrect.

In Unicode, every alphabet is assigned a magic number by the Unicode consortium
which is written like this: U+0639. This number is called the code-point. The
U+ means "Unicode" and the numbers are in hexadecimal notation. U+0639 is the
arabic letter Ain (ع).

There is no real limit on the number of letters that Unicode can define and in
fact, they have gone beyond 65,536 so not every unicode letter can really be
squeezed into two bytes. That was a myth anyways.

OK, so we have a string: Hello which, in Unicode, corresponds to these five
code-points: U+0048 U+0065 U+006C U+006C U+006F 

It was U- before 3.0 and then it became U+. If you look at the release notes of
Unicode 3.0, you might find the reason for the change.

How do we store those numbers?  That is where encoding comes in.

The earliest idea was, that to store the numbers in two bytes each:

	00 48 00 65 00 6C 00 6C 00 6F.

Why not it be stored like this:

	48 00 65 00 6C 00 6C 00 6F 00

Well, it could be stored in that way too. Early implementors wanted to store
the numbers in either big-endian or little-endian, in whichever way their
particular CPU  was fastest at...  So, people came up with Byte Order Mark,
where FEFF denoted Little Endian and FFFE denoted big endian.

FEFF - Little Endian
FFFE - Big Endian

Three F's together is BIG.

For a while, it seemed like that might be good enough, but programmers were
complaining. "Look at all those zeros!", they said, since they were Americans
and they were looking at English text which rarely used code points above
U+OOFF.  People decided to ignore Unicode and things got worse.  And thus was
invented the brilliant concept of UTF-8. (Read Rob Pike's mail)

In UTF-8, every code point from 0-127 is stored in a single byte. Only code
points 128 and above are stored using 2, 3, in fact upto 6 bytes.  This has the
neat side-effect that English text looks exactly the same in UTF-8 as it did in
ASCII, so Americans don't even notice anything wrong.  Specifically, Hello
which was "0048, 0065, 006C, 006C and 006F" would simply be stored as
48,65,6C,6C and 6F.

So, here we have ways such as UCS-2 (UTF-16), which had its own UCS-2 little
endian or UCS-2 big endian and then UTF-8 encoding method.  There are also a
bunch of other ways of encoding Unicode. There is something called UTF-7, which
is lot like UTF-8 but guarantees that the high bit will always be zero.  It was
for systems which can recognize only 7 bits. UCS-4 which stores each code point
in 4 bytes, which has a nice property that every single code point can be
stored in same number of bytes. But that is memory hungry.

There are hundreds of traditional encodings, which can only store some
code-points correctly and change all other code points into question marks.
Some popular encodings of the English text are, Windows 1252 and ISO-8859-1,
aka Latin-1 (also useful for any western european languages). But try to store
Russian, or Hebrew letters in those encodings and you will get a bunch of
question marks. UTF 7, UTF 8, UTF 16 and UTF 32 all have the nice property of
being able to store any code point correctly.

If you have a string in memory, in a file, or in an email message, you have to
know what encoding it is in or you cannot interpret it or display to your users
correctly.  All the problems of ????, comes down to the fact that if you don't
tell me whether a particular string is encoded using UTF-8 or ASCII or ISO
8859-1 (Latin 1) or Western 1252 (Western European), you simply cannot display
it correctly or even figure it out where it actually ends.  There are over 100
encodings, and above code point 127, all the bets are off.

How do we preserve this information about what encoding a string uses?  Email,
Content-Type: text/plain; charset="UTF-8" For a web page, the original idea was
that the web server would return a similar Content-Type http header along with
the web page itself -- not in the HTML itself, but as one of the response
headers that are sent before the HTML page.

Relying on webserver to send Content-Type was problematic, because many
different people could use the same web-server for different types of web
pages.  It would be convenient, if you could put the Content-Type of the HTML
file right in the HTML file itself, using some kind of a special tag.  All
encoding uses same character between 32 and 127, so you could get to the point
wherein you could read the <meta> header.

The RFC which explains UTF-8

::
        http://www.ietf.org/rfc/rfc3629.txt

        The most interesting part of the RFC, which is leading me to understand the
        system better is explained here:

           The table below summarizes the format of these different octet types.
           The letter x indicates bits available for encoding bits of the
           character number.

           Char. number range  |        UTF-8 octet sequence
              (hexadecimal)    |              (binary)
           --------------------+---------------------------------------------
           0000 0000-0000 007F | 0xxxxxxx
           0000 0080-0000 07FF | 110xxxxx 10xxxxxx
           0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
           0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

           Encoding a character to UTF-8 proceeds as follows:

           1.  Determine the number of octets required from the character number
               and the first column of the table above.  It is important to note
               that the rows of the table are mutually exclusive, i.e., there is
               only one valid way to encode a given character.

           2.  Prepare the high-order bits of the octets as per the second
               column of the table.

           3.  Fill in the bits marked x from the bits of the character number,
               expressed in binary.  Start by putting the lowest-order bit of
               the character number in the lowest-order position of the last
               octet of the sequence, then put the next higher-order bit of the
               character number in the next higher-order position of that octet,
               etc.  When the x bits of the last octet are filled in, move on to
               the next to last octet, then to the preceding one, etc. until all
               x bits are filled in.

           The definition of UTF-8 prohibits encoding character numbers between
           U+D800 and U+DFFF, which are reserved for use with the UTF-16
           encoding form (as surrogate pairs) and do not directly represent
           characters.  When encoding in UTF-8 from UTF-16 data, it is necessary
           to first decode the UTF-16 data to obtain character numbers, which
           are then encoded in UTF-8 as described above.  This contrasts with
           CESU-8 [CESU-8], which is a UTF-8-like encoding that is not meant for
           use on the Internet.  CESU-8 operates similarly to UTF-8 but encodes
           the UTF-16 code values (16-bit quantities) instead of the character
           number (code point).  This leads to different results for character
           numbers above 0xFFFF; the CESU-8 encoding of those characters is NOT
           valid UTF-8.

           Decoding a UTF-8 character proceeds as follows:

           1.  Initialize a binary number with all bits set to 0.  Up to 21 bits
               may be needed.

           2.  Determine which bits encode the character number from the number
               of octets in the sequence and the second column of the table
               above (the bits marked x).

           3.  Distribute the bits from the sequence to the binary number, first
               the lower-order bits from the last octet of the sequence and
               proceeding to the left until no x bits are left.  The binary
               number is now equal to the character number.

           Implementations of the decoding algorithm above MUST protect against
           decoding invalid sequences.  For instance, a naive implementation may
           decode the overlong UTF-8 sequence C0 80 into the character U+0000,
           or the surrogate pair ED A1 8C ED BE B4 into U+233B4.  Decoding
           invalid sequences may have security consequences or cause other
           problems.  See Security Considerations (Section 10) below.

        4.  Syntax of UTF-8 Byte Sequences

           For the convenience of implementors using ABNF, a definition of UTF-8
           in ABNF syntax is given here.

           A UTF-8 string is a sequence of octets representing a sequence of UCS
           characters.  An octet sequence is valid UTF-8 only if it matches the
           following syntax, which is derived from the rules for encoding UTF-8
           and is expressed in the ABNF of [RFC2234].

           UTF8-octets = *( UTF8-char )
           UTF8-char   = UTF8-1 / UTF8-2 / UTF8-3 / UTF8-4
           UTF8-1      = %x00-7F
           UTF8-2      = %xC2-DF UTF8-tail
           UTF8-3      = %xE0 %xA0-BF UTF8-tail / %xE1-EC 2( UTF8-tail ) /
                         %xED %x80-9F UTF8-tail / %xEE-EF 2( UTF8-tail )
           UTF8-4      = %xF0 %x90-BF 2( UTF8-tail ) / %xF1-F3 3( UTF8-tail ) /
                         %xF4 %x80-8F 2( UTF8-tail )
           UTF8-tail   = %x80-BF

           NOTE -- The authoritative definition of UTF-8 is in [UNICODE].  This
           grammar is believed to describe the same thing Unicode describes, but
           does not claim to be authoritative.  Implementors are urged to rely
           on the authoritative source, rather than on this ABNF.


The official name of the encoding is UTF-8, where UTF stands for UCS
Transformation Format 8.  Write it as UTF-8 only.

So there is no limit on the number of the characters that Unicode could define.
So, it has definiely exceeded beyond, 65536 characters.

Exercise 1:
Convert the following to Unicode:
1) "Hello, World"
2) à¤¨à¤®à¤¸à¥à¤à¤¾à¤° à¤¦à¥à¤¨à¤¿à¤¯à¤¾ 

Answer:
1)"Hello, World" is present in U0000 and 
U+0048 U+0065 U+006C U+006C U+006F U+002C U+0057 U+006F U+0072 U+006C U+0064

2) à¤¨à¤®à¤¸à¥à¤à¤¾à¤° à¤¦à¥à¤¨à¤¿à¤¯à¤¾
is the devnagari script that starts with U0900 
U+0928 U+092E U+0938 U+0942 U+0915 U+090 U+0930 U+0926 U+0941 U+0928 U+092F U+093F U+0965

The above was just a bunch of code points. We have not said anything about how
to store them in memory or represent them in email messages yet.

Encodings

English meaning of encoding is is wrapping it in a cipher code.  The earlier
method was to store those codepoints which are 4 hexadecimal digits as 2 bytes.
1 hexa digit can be written in 4 bits, 2 hexa digits can be written in 8 bits
which is 1 byte and so 4 hexa digits can be written in 2 bytes.

Convert Unicode to Hexadecimals.
Excellent tutorial.
http://ln.hixie.ch/?start=1064324988&count=1

Typing Unicode and maths symbols on gnome-terminal

1) Hold CTRL+SHIFT + U + codepoint + SPACE
2) For e.g. CTRL+SHIFT+U+2201+SPACE will give Unicode Maths Symbol 

Unicode code point chart:
http://inamidst.com/stuff/unidata/

What is Global Interpretor Lock?
================================

Global Interpretor lock is used to protect the Python Objects from being
modified by multiple threads at once. To keep multiple threads running, the
interpretor automatically releases and reaquires the lock at regular intervals.
It also does this around potentially slow or blocking low level operations,
such a file and network I/O.  This is used internally to ensure that only one
thread runs in the Python VM at a time. Python offers to switch amongst threads
only between bytecode instructions. Each bytecode instruction and all C
implemented function is atomic from Python program's point of view.

Different types of concurrency models
=====================================

* Java and C# uses shared memory concurrency model with locking provided by
  monitors. Message passing concurrency model have been implemented on top of
  the existing shared memory concurrency model.

* Erlang uses message passing concurrency model.

* Alice Extensions to Standard ML supports concurrency via Futures.

* Cilk is concurrent C.

* The Actor Model.

* Petri Net Model.

Some History of Inter Process Communication
===========================================

By the early 60s computer control software had evolved from Monitor control
software, e.g., IBSYS, to Executive control software. Computers got "faster"
and computer time was still neither "cheap" nor fully used. It made
multiprogramming possible and necessary.

Multiprogramming means that several programs run "at the same time"
(concurrently). At first they ran on a single processor (i.e., uniprocessor)
and shared scarce resources. Multiprogramming is also basic form of
multiprocessing, a much broader term.

Programs consist of sequence of instruction for processor. Single processor can
run only one instruction at a time. Therefore it is impossible to run more
programs at the same time. Program might need some resource (input ...) which
has "big" delay. Program might start some slow operation (output to printer
...). This all leads to processor being "idle" (unused). To use processor at
all time the execution of such program was halted. At that point, a second (or
nth) program was started or restarted. User perceived that programs run "at the
same time" (hence the term, concurrent).

Shortly thereafter, the notion of a 'program' was expanded to the notion of an
'executing program and its context'. The concept of a process was born.

This became necessary with the invention of re-entrant code.  Threads came
somewhat later. However, with the advent of time-sharing; computer networks;
multiple-CPU, shared memory computers; etc., the old "multiprogramming" gave
way to true multitasking, multiprocessing and, later, multithreading.

Context Management Protocol support
:: 
        with bz2.BZ2File() as f:
                f.something()

Counter class in the collections module that behave like dictionary; but return
0 instead of {{{KeyError}}}.  There is a namedtuple class in python.

compileall module is a script which will compile all the .py files in the path
to .pyc files.  py_compile is module which does the actual byte compilation.

py_compile.compile(fullname, None, dfile, True)

inspect module.

turtle module is a good one to get started with Python. turtle modle is updated
to 1.1 by Gregor Lingl. I promised to write a tutorial on turtle module. This
is pending.

How can we differentiate if an expression used is a general expression or a
boolean expression.

Having a construct like:

::

        def __init__(self, *args, **kwargs):
        BaseClass.__init__(self, *args, **kwargs)

But in the base class, I find that it is not taking the tuple and dict as
arguments.

* What is an addrinfo struct.

The getaddrinfo() function returns a list of 5-tuples with the following
structure: (family, socktype, proto, canonname, sockaddr)

family, socktype, proto are all integer and are meant to be passed to the
socket() function. canonname is a string representing the canonical name of the
host. It can be a numeric IPv4/v6 address when AI_CANONNAME is specified for a
numeric host.

socket.gethostbyname(hostname)

Translate a host name to IPv4 address format. The IPv4 address is returned as a
string, such as '100.50.200.5'. If the host name is an IPv4 address itself it
is returned unchanged. See gethostbyname_ex() for a more complete interface.
gethostbyname() does not support IPv6 name resolution, and getaddrinfo() should
be used instead for IPv4/v6 dual stack support.

We need to replace the gethostbyname socket call. Because it is only IPv4
specific. using the getaddrinfo() function can include the IPv4/v6 dual stack
support.

import socket
print socket.gethostbyname(hostname)

def gethostbyname(hostname)
family, socktype, proto, canonname, sockaddr = socket.getaddrinfo(hostname)
return canonname

RFC 1123 date format:
Thu, 01 Dec 1994 16:00:00 GMT

::

        >>> datereturned = "Thu, 01 Dec 1994 16:00:00 GMT"
        >>> dateexpired = "Sun, 05 Aug 2007 03:25:42 GMT"
        >>> obj1 = datetime.datetime(*time.strptime(datereturned, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
        >>> obj2 = datetime.datetime(*time.strptime(dateexpired, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
        >>> if obj1 == obj2:
        print "Equal"
        elif obj1 > obj2:
        print datereturned
        elif obj1 < obj2:
        print dateexpired


Now you can compare the headers for expiry in cache control.

Header field definition:
http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html

To add header:
Go to the /etc/httpd/conf/httpd.conf
For e.g:
Add the information on headers
Header set Author "Senthil"

Language Feature: Source code encoding
--------------------------------------

 * With that declaration, all characters in the source file will be treated as having the encoding *encoding*, and it will be possible to directly write Unicode string literals in the selected encoding.
 * The list of possible encodings can be found in the Python Library Reference, in the section on 
[http://docs.python.org/library/codecs.html#module-codecs codecs]
* By using UTF-8, most languages in the world can be used simultaneously in string literals and the comments.


Language Feature: Unicode
-------------------------

 * Starting with Python 2.0 a new data type for storing text data is available to the programmer: the Unicode object.  _>>> u'Hello World !'_
 * Python unicode escape encoding: _>>> u'Hello\u0020World !'_
 * built-in function unicode() , default encoding is ASCII
 * To convert unicode to a 8-bit string using a specified encoding.

::
        >>> u"Ã¤Ã¶Ã¼".encode('utf-8')
        '\xc3\xa4\xc3\xb6\xc3\xbc'


 * From a data in a specific encoding to a unicode string.

::
        >>> unicode('\xc3\xa4\xc3\xb6\xc3\xbc', 'utf-8')
        u'\xe4\xf6\xfc'


Language Feature: Unicode

* understanding unicode is easy, when we accept the need to explicitly convert
  between the bytestring and unicode string.

* More examples:

   german_ae = unicode('\xc3\xa4','utf8')

::
        >>> german_ae = unicode("\xc3\xa4",'utf8')
        >>> sentence = "this is a " + german_ae
        >>> sentece2 = "Easy!"
        >>> sentence2 = "Easy!"
        >>> para = ".".join([sentence, sentence2])
        >>> para
        u'this is a \xe4.Easy!'
        >>> print para
        this is a ä.Easy!
        >>> 

* Without an encoding, the bytestring is essentially meaningless. 
* The default encoding assumed by Python is ASCII


Python Specialities: else clauses on loops 
------------------------------------------

* Loop statements may have an else clause; 
* It is executed when the loop terminates through exhaustion of the list (with for).
* Or when the condition becomes false (with while), 
* But not when the loop is terminated by a break statement.

::
        >>> for n in range(2, 10):
        ...     for x in range(2, n):
        ...         if n % x == 0:
        ...             print n, 'equals', x, '*', n/x
        ...             break
        ...     else:
        ...         # loop fell through without finding a factor
        ...         print n, 'is a prime number'
        ...
        2 is a prime number
        3 is a prime number
        4 equals 2 * 2
        5 is a prime number
        6 equals 2 * 3
        7 is a prime number
        8 equals 2 * 4
        9 equals 3 * 3

Control Flow: function execution
--------------------------------

The execution of a function introduces a new symbol table used for the local
variables of the function. More precisely, all variable assignments in a
function store the value in the local symbol table; whereas variable references
first look in the local symbol table, then in the local symbol tables of
enclosing functions, then in the global symbol table, and finally in the table
of built-in names. Thus, global variables cannot be directly assigned a value
within a function (unless named in a global statement), although they may be
referenced.

The actual parameters (arguments) to a function call are introduced in the
local symbol table of the called function when it is called; thus, arguments
are passed using call by value (where the value is always an object reference,
not the value of the object). [1] When a function calls another function, a new
local symbol table is created for that call.

A function definition introduces the function name in the current symbol table.
The value of the function name has a type that is recognized by the interpreter
as a user-defined function. This value can be assigned to another name which
can then also be used as a function.

Control Flow: functions
-----------------------

* What is the output?

:: 
        i = 5

        def f(arg=i):
            print arg

        i = 6
        f()


        def f(a, L=[]):
            L.append(a)
            return L

        print f(1)
        print f(2)
        print f(3)

* first one will print 5, because default values are evaluated at the point of
  function definition in the defining scope.

* The default value is evaluated only once. This makes a difference when the
  default value is a mutatable object. In order to prevent argument sharing.

::
          def f(a, L=None):
            if L is None:
                L = []
            L.append(a)
            return L

Data Structures: Functional Programming Tools 
---------------------------------------------

* There are three built-in functions that are very useful when used with lists:
  filter(), map() and reduce()
* filter(function, sequence)
* map(function, sequence)
* More than one sequence may be passed; the function must then have as many
  arguments as there are sequences and is called with the corresponding item
  from each sequence. 
* reduce(function, sequence)
* function in reduce is a binary function

::

        >>> def f(x): return x % 2 != 0 and x % 3 != 0
        ...
        >>> filter(f, range(2, 25))
        [5, 7, 11, 13, 17, 19, 23]

        >>> def cube(x): return x*x*x
        ...
        >>> map(cube, range(1, 11))
        [1, 8, 27, 64, 125, 216, 343, 512, 729, 1000]

        >>> seq = range(8)
        >>> def add(x, y): return x+y
        ...
        >>> map(add, seq, seq)
        [0, 2, 4, 6, 8, 10, 12, 14]

        >>> def sum(seq):
        ...     def add(x,y): return x+y
        ...     return reduce(add, seq, 0)
        ...
        >>> sum(range(1, 11))
        55
        >>> sum([])
        0

Data Structures: List comprehensions 
------------------------------------

* Each list comprehension consists of an expression followed by a for clause, then zero or more for or if clauses.
* If the expression would evaluate to a tuple, it must be parenthesized.


::

        >>> freshfruit = ['  banana', '  loganberry ', 'passion fruit  ']
        >>> [weapon.strip() for weapon in freshfruit]
        ['banana', 'loganberry', 'passion fruit']
        >>> vec = [2, 4, 6]
        >>> [3*x for x in vec]
        [6, 12, 18]
        >>> [3*x for x in vec if x > 3]
        [12, 18]
        >>> [3*x for x in vec if x < 2]
        []
        >>> [[x,x**2] for x in vec]
        [[2, 4], [4, 16], [6, 36]]
        >>> [x, x**2 for x in vec]  # error - parens required for tuples
          File "<stdin>", line 1, in ?
            [x, x**2 for x in vec]
                       ^
        SyntaxError: invalid syntax
        >>> [(x, x**2) for x in vec]
        [(2, 4), (4, 16), (6, 36)]
        >>> vec1 = [2, 4, 6]
        >>> vec2 = [4, 3, -9]
        >>> [x*y for x in vec1 for y in vec2]
        [8, 6, -18, 16, 12, -36, 24, 18, -54]
        >>> [x+y for x in vec1 for y in vec2]
        [6, 5, -7, 8, 7, -5, 10, 9, -3]
        >>> [vec1[i]*vec2[i] for i in range(len(vec1))]
        [8, 12, -54]
        
Python IAQ
----------

::

        mat = [[1,2,3],
               [4,5,6],
               [7,8,9]
               ]

How would you transpose the matrix?

:: 
        result = [[1,4,7],
                  [2,5,8],
                  [3,6,9]
                  ]

        Answer:
        >>>zip(\*mat)



Comparing Sequences and Other Types 
-----------------------------------

* lexicographic comparision between the same types.
* comparing objects of different types is legal.
* types are ordered by their name ( list < string < tuple). *this must not be relied upon however*
* mixed numeric types are compared according to numeric value.

::
        (1, 2, 3)              < (1, 2, 4)
        [1, 2, 3]              < [1, 2, 4]
        'ABC' < 'C' < 'Pascal' < 'Python'
        (1, 2, 3, 4)           < (1, 2, 4)
        (1, 2)                 < (1, 2, -1)
        (1, 2, 3)             == (1.0, 2.0, 3.0)
        (1, 2, ('aa', 'ab'))   < (1, 2, ('abc', 'a'), 4)



Handling Exceptions
-------------------

* A try statement may have more than one except clause, to specify handlers for

::

  different exceptions.

          ... except (RuntimeError, TypeError, NameError):

          ...     pass

* The last except clause may omit the exception name(s), to serve as a
  wildcard. Use this with extreme caution, since it is easy to mask a real
  programming error in this way! 

*  It can also be used to print an error message and then re-raise the
  exception (allowing a caller to handle the exception as well)

* The try ... except statement has an optional else clause, executed when the
  try clause does not raise an exception.

::

        for arg in sys.argv[1:]:
            try:
                f = open(arg, 'r')
            except IOError:
                print 'cannot open', arg
            else:
                print arg, 'has', len(f.readlines()), 'lines'
                f.close()

Defining Clean-up Actions 
-------------------------

* A finally clause is always executed before leaving the try statement, whether
an exception has occurred or not.

* In real world applications, the finally clause is useful for releasing
  external resources (such as files or network connections), regardless of
  whether the use of the resource was successful.

Pre-defined Clean-up actions
----------------------------

* with statement

* Some objects define standard clean-up actions to be undertaken when the
  object is no longer needed, regardless of whether or not the operation using
  the object succeeded or failed. 

::

        with open("myfile.txt") as f:
            for line in f:
                print line

* After the statement is executed, the file f is always closed, even if a
  problem was encountered while processing the lines. 

Classes in Python 
-----------------

* In C++ terminology, all class members (including the data members) are
  public, and all member functions are virtual. There are no special
  constructors or destructors.  
* Python Scopes and Namespaces
* A namespace is a mapping from names to objects. Most namespaces are currently
  implemented as Python dictionaries.

Classs in Python
----------------

* When a class definition is entered, a new namespace is created, and used as
  the local scope and thus, all assignments to local variables go into this new
  namespace. In particular, function definitions bind the name of the new
  function here.
* When a class definition is left normally (via the end), a class object is
  created. This is basically a wrapper around the contents of the namespace
  created by the class definition;The original local scope (the one in effect
  just before the class definition was entered) is reinstated, and the class
  object is bound here to the class name given in the class definition header
* Class Objects support attribute notation and instantiation.
* Class instantiation creates instance objects.
* Instance Objects supports attribute references, which are of two kinds data
  attributes and methods.


Inheritance in Python 
---------------------

* Old style classes it is depth first, left to right.
* For new style classes to support super(), it follows a diamond inheritance.


Iterators
---------

* The use of iterators pervades and unifies Python.
* Behind the scenes, the iterator statement calls iter() on the container
  object. 
* The function returns an iterator object that defines the method next() which
  accesses elements in the container one at a time.  
* StopIterationException terminates
* In your classes, define __iter__ which will return self and the next method.

Generators
----------

* Just like regular function, but instead of return they use yield.
* Generators are used to return iterators.
* Generator expressions which are very similar to list comprehensions.

 * Python Standard Library. 
 * Explore!

 
Explain Classmethods, Staticmethods and Decorators in Python.
=============================================================

In Object Oriented Programming, you can create a method which can get
associated either with a class or with an instance of the class, namely an
object. 

And most often in our regular practice, we always create methods to be
associated with an object. Those are called instance methods.

For e.g.
::

        class Car:
                def cartype(self):
                        self.model = "Audi"

        mycar = Car()
        mycar.cartype()
        print mycar.model

Here cartype() is an instance method, it associates itself with an instance
(mycar) of the class (Car) and that is defined by the first argument ('self').

When you want a method not to be associated with an instance, you call that as
a staticmethod.

How can you do such a thing in Python?

The following would never work:

::

        >>> class Car:
        ... 	def getmodel():
        ... 		return "Audi"
        ... 	def type(self):
        ... 		self.model = getmodel()

Because, getmodel() is defined inside the class, Python binds it to the Class
Object.  You cannot call it by the following way also, namely: Car.getmodel()
or Car().getmodel() , because in this case we are passing it through an
instance ( Class Object or a Instance Object) as one of the argument while our
definition does not take any argument.

As you can see, there is a conflict here and in effect the case is, It is an
"unbound local **method**" inside the class.

Now comes Staticmethod.

Now, in order to call getmodel(), you can to change it to a static method.

::

        >>> class Car:
        ... 	def getmodel():
        ... 		return "Audi"
        ...     getmodel = staticmethod(getmodel)
        ... 	def cartype(self):
        ... 		self.model = Car.getmodel()
        ... 		
        >>> mycar = Car()
        >>> mycar.cartype()
        >>> mycar.model
        'Audi'

Now, I have called it as Car.getmodel() even though my definition of getmodel
did not take any argument. This is what staticmethod function did.  getmodel()
is a method which does not need an instance now, but still you do it as
Car.getmodel() because getmodel() is still bound to the Class object. 

Decorators
----------

getmodel = staticmethod(getmodel)

If you look at the previous code example, the function staticmethod took a
function name as a argument and the return value was a function which we
assigned to the same name.

staticmethod() function thus wrapped our getmodel function with some extra
features and this wrapping is called as Decorator.

The same code can be written like this.

::

        >>> class Car:
        ... 	@staticmethod
        ... 	def getmodel():
        ... 		return "Audi"
        ... 	def cartype(self):
        ... 		self.model = Car.getmodel()
        ... 		
        >>> mycar = Car()
        >>> mycar.cartype()
        >>> mycar.model
        'Audi'

For a better explaination on what is decorator:

http://personalpages.tds.net/~kent37/kk/00001.html

Please remember that this concept of Decorator is independent of staticmethod
and classmethod.  Now, what is a difference between staticmethod and
classmethod?

In languages like Java,C++, both the terms denote the same :- methods for which
we do not require instances. But there is a difference in Python. A class
method receives the class it was called on as the first argument. This can be
useful with subclasses.

We can see the above example with the classmethod and a decorator as:

::

        >>>
        >>> class Car:
        ... 	@classmethod
        ... 	def getmodel(cls):
        ... 		return "Audi"
        ... 	def gettype(self):
        ... 		self.model = Car.getmodel()
        ... 		
        >>> mycar = Car()
        >>> mycar.gettype()
        >>> mycar.model
        'Audi'


The following are the references in order to understand further:
1) Alex-Martelli explaining it with code: http://code.activestate.com/recipes/52304/
2)  Decorators: http://personalpages.tds.net/~kent37/kk/00001.html

Good Article on Decorators

http://personalpages.tds.net/~kent37/kk/00001.html

Static Methods and Class Methods
--------------------------------

A class method receives the class it was called on as the first
argument. This can be useful with subclasses. A staticmethod doesn't get a
class or instance argument. It is just a way to put a plain function into the
scope of a class.

And that's the definition of the difference in Python.
In the wider world of OOP they are two names for the same concept.
Smalltalk and Lisp etc used the term "class method" to mean a
method that applied to the class as a whole.

C++ introduced the term "static method" to reflect the fact that it
was loaded in the static area of memory and thus could be called
without instantiating an object. This meant it could effectively be
used as a class method.

[In C it is possible to prefix a normal function definition with
the word static to get the compiler to load the function into
static memory - this often gives a performance improvement.]

Python started off implementing "static methods" then later
developed the sligtly more powerful and flexible "class methods" and
rather than lose backward compatibility called them classmethod.
So in Python we have two ways of doing more or less the same
(conceptual) thing.  // Alan

Conceptually they are both ways of defining a method that
applies at the class level and could be used to implement
class wide behavior. Thats what I mean. If you want to build
a method to determine how many instances are active at
any time then you could use either a staticmethod or a
classmethod to do it. Most languages only give you one
way. Python, despite its mantra, actually gives 2 ways to
do it in this case. // Alan

http://code.activestate.com/recipes/52304/

http://stackoverflow.com/questions/136097/what-is-the-difference-between-staticmethod-and-classmethod-in-python

Method (Computer Science)

In object-oriented programming, a method is a subroutine that is exclusively
associated either with a class (called class methods or static methods) or with
an object (called instance methods). Like a procedure in procedural programming
languages, a method usually consists of a sequence of statements to perform an
action, a set of input parameters to customize those actions, and possibly an
output value (called the return value) of some kind. Methods can provide a
mechanism for accessing (for both reading and writing) the encapsulated data
stored in an object or a class.

Instance methods are associated with a particular object, while class or static
methods are associated with a class. In all typical implementations, instance
methods are passed a hidden reference (e.g. this, self or Me) to the object
(whether a class or class instance) they belong to, so that they can access the
data associated with it. 

For class/static methods this may or may not happen according to the language;
A typical example of a class method would be one that keeps count of the number
of created objects within a given class.

A method may be declared as static, meaning that it acts at the class level
rather than at the instance level. Therefore, a static method cannot refer to a
specific instance of the class (i.e. it cannot refer to this, self, Me, etc.),
unless such references are made through a parameter referencing an instance of
the class, although in such cases they must be accessed through the parameter's
identifier instead of this. An example of a static member and its consumption
in C# code:

::

        public class ExampleClass
        {
          public static void StaticExample()
          {
             // static method code
          }
         
          public void InstanceExample()
          {
             // instance method code here
             // can use THIS
          }   
        }
         
        /// Consumer of the above class:
         
        // Static method is called -- no instance is involved
        ExampleClass.StaticExample();
         
        // Instance method is called
        ExampleClass objMyExample = new ExampleClass();
        objMyExample.InstanceExample();


Python method can create an instance of Dict or of any subclass of it, because
it receives a reference to a class object as cls:

::

        class Dict:
           @classmethod
           def fromkeys(cls, iterable, value=None):
               d = cls()
               for key in iterable:
                   d[key] = value
               return d


http://en.wikipedia.org/wiki/Method_(computer_science)


Question:
What is metaclass attributes?
Look a bit into property.
Usage of Ellipses

What is the difference between process and a thread?

Both threads and processes are methods of parallelizing an application.
However, processes are independent execution units that contain their own state
information, use their own address spaces, and only interact with each other
via interprocess communication mechanisms (generally managed by the operating
system). Applications are typically divided into processes during the design
phase, and a master process explicitly spawns sub-processes when it makes sense
to logically separate significant application functionality. Processes, in
other words, are an architectural construct.

By contrast, a thread is a coding construct that doesn't affect the
architecture of an application. A single process might contains multiple
threads; all threads within a process share the same state and same memory
space, and can communicate with each other directly, because they share the
same variables.

Threads typically are spawned for a short-term benefit that is usually
visualized as a serial task, but which doesn't have to be performed in a linear
manner (such as performing a complex mathematical computation using
parallelism, or initializing a large matrix), and then are absorbed when no
longer required. The scope of a thread is within a specific code module—which
is why we can bolt-on threading without affecting the broader application.

Global Interpreter Lock:

The GIL is a single lock inside of the Python interpreter, which effectively
prevents multiple threads from being executed in parallel, even on multi-core
or multi-CPU systems!

* All threads within a single process share memory; this includes Python's
  internal structures (such as reference counts for each variable).  Course
  grained locking.
* fine grained locking.
* @synchronized decorator
* technically speaking, threads have shared heaps but separate stacks.
* Interpreter of a language is said to be stackless if the function calls in
  the language do not use the C Stack. In effect, the entire interpretor has to
  run as a giant loop.

What is Global Interpretor Lock in Python?

The Global Interpreter Lock (GIL) is used to protect Python objects from being
modified from multiple threads at once. Only the thread that has the lock may
safely access objects.

To keep multiple threads running, the interpreter automatically releases and
reacquires the lock at regular intervals (controlled by the
sys.setcheckinterval function). It also does this around potentially slow or
blocking low-level operations, such as file and network I/O.

Indeed the GIL prevents the *interpreter* to run two threads of bytecodes
concurrently.

But it allows two or more threadsafe C library to run at the same time.

The net effect of this brilliant design decision are:

1. it makes the interpreter simpler and faster

2. when speed does not matter (ie: bytecode is interpreted) there’s not too
much to worry about threads.

3. when speed does matter (ie: when C code is run) Python applications is not
hampered by a brain dead VM that is so ’screwed’ up that it must pause
to collect its garbage.

Python Standard Library
-----------------------

Python's standard library is very extensive, offering a wide range of
facilities. The library contains built-in modules (written in C) that provide
access to system functionality such as file I/O that would otherwise be
inaccessible to Python programmers, as well as modules written in Python that
provide standardized solutions for many problems that occur in everyday
programming. Some of these modules are explicitly designed to encourage and
enhance the portability of Python programs by abstracting away
platform-specifics into platform-neutral APIS.

In addition to the standard library, there is a growing collection of several
thousand components (from individual programs and modules to packages and
entire application development frameworks), available from the Python Package
Index.

4.21   How do you specify and enforce an interface spec in Python?

An interface specification for a module as provided by languages such as C++
and Java describes the prototypes for the methods and functions of the module.
Many feel that compile-time enforcement of interface specifications helps in
the construction of large programs.

Python 2.6 adds an abc module that lets you define Abstract Base Classes (ABC).
You can then use isinstance() and issubclass to check whether an instance or a
class implements a particular ABC. The collections modules defines a set of
useful ABC s such as Iterable, Container, and Mutablemapping.

For Python, many of the advantages of interface specifications can be obtained
by an appropriate test discipline for components. There is also a tool,
PyChecker, which can be used to find problems due to subclassing.

A good test suite for a module can both provide a regression test and serve as
a module interface specification and a set of examples. Many Python modules can
be run as a script to provide a simple "self test." Even modules which use
complex external interfaces can often be tested in isolation using trivial
"stub" emulations of the external interface. The doctest and unittest modules
or third-party test frameworks can be used to construct exhaustive test suites
that exercise every line of code in a module.

An appropriate testing discipline can help build large complex applications in
Python as well as having interface specifications would. In fact, it can be
better because an interface specification cannot test certain properties of a
program. For example, the append() method is expected to add new elements to
the end of some internal list; an interface specification cannot test that your
append() implementation will actually do this correctly, but it's trivial to
check this property in a test suite.

Writing test suites is very helpful, and you might want to design your code
with an eye to making it easily tested. One increasingly popular technique,
test-directed development, calls for writing parts of the test suite first,
before you write any of the actual code. Of course Python allows you to be
sloppy and not write test cases at all.


Coroutines

Coroutines are subroutines that allow multiple entry points for suspending and
resuming execution at certain locations.  Subroutine are subprograms, methods,
functions for performing a subtask and it is relatively independent of other
task.  Coroutines are usful for implementing cooperative tasks, iterators,
infinite lists and pipes.  Cooperative Tasks - Similar programs, CPU is yielded
to each program coperatively.  Iterators - an object that allows the programmer
to traverse all the elements of a collection.  Lazy Evaluation is the technique
for delaying the computation till the result is required. Why Infite Lists and
Lazy evaluation are given together?  Coroutines in which subsequent calls can
be yield more results are called as generators.  Subroutines are implemented
using stacks and coroutines are implemented using continuations.  continuation
are an abstract representation of a control state, or the rest of the
computation, or rest of the code to be executed.

Multithreading

Multithreading computers have hardware support to efficiently execute multiple
threads.  Threads of program results from fork of a computer program into two
or more concurrently running tasks.  In multi-threading the threads have to
share a single core,cache and TLB unlike the multiprocessing machines.

Twisted Framework

Asynchronous, Event-Driven Applications for Distributed Network Environment.
At the core of Twisted Framework is its Network Layer, which can used to
integrate any existing  protocol as well as model new ones.  Twisted is a pure
python framework.  As a platform, twisted should be focussed on integration.
Twisted supports Asynchronous programming and deferred abstraction, which
symbolizes a promised result and which can pass eventual result to  handler
functions.  Document will give you a high-level overview of concurrent
programming and Twisted's concurrency model: non-blocking code and asynchronous
code.  Concurrent programming - Need. It is either computationally intensive;
or it has to wait for the data to be available as a result.  A fundamental
feature of Network Programming is waiting for data.  Not waiting on data:-
handle each connection in a separate OS process; so that OS will take of
letting other process run while one is waiting.  Handle each connection in a
separate thread; threading framework takes care of the details.  Use
non-blocking system calls to handle all connections in one thread.  The Normal
Model when using twisted framework is by using Non-Blocking Calls.  When
dealing with many connections in one thread, the scheduling is the
responsiblity of the application, not the operating system, and is usually
implemented by calling a registered function when each function is ready to go
for reading or writing - commonly known as asynchronous, event based, callback
based programming.  In synchrnous programming, a function requests data, waits
for the data, and then processes it. In asynchronous programming, a function
requests the data, and lets the library call the callback function when the
data is ready.

It is the second class of concurrency problems, non-computationally intensive
tasks that involve an appreciable delay that deferreds are designed to help
solve.  They do this by giving a simple management interface for callbacks and
applications.  blocking - means, if one tasks is waiting for data, the other
task cannot get CPU but also waits until the first tasks finishes.  The typical
asynchronous model to notify can application that some data is ready is called
as callback.  Twisted uses Deferred objects to managed callback sequence.
Libraries know that they make their results available by using
Deferred.callback and errors by Deferred.errback.  How does the parent function
or its controlling program know that connection does not exist and when it will
know, when the connection becomes alive?  Twisted has an object that signals
this situation, it is called twisted.internet.defer.Deferred Deferred has two
purposes; first is saying that I am a signal, of whatever you wanted me to do
is still pending; second you can ask differed to run things when the data
arrives.  the way to tell the deffered what to do when the data arrives is by
defining a callback - asking the deferred to call a function once the data
arrives.  28.  One Twisted library function that returns a Deferred is
twisted.web.client.getPage.

If nothing else is understood, please understand that you create a differed object, add a callback function to that object and add an errorback function to that object. Differed will get called after a particular period of time or some data is avaiable.
30. Differed Objects are signals that the function that you have called does not have the data, you want available.
31. What Differeds dont do: Make your code asynchronous!.
32. Differeds are the signals for asynchronous functions to use to pass results onto the callbacks, but using them does not guarantee that you have asynchronous functions.
33. Twisted provides a facility to run the blocking function in a separate thread instead of blocking them.
34. Evolution of finger. By the end of this tutorial; the finger service will answer the TCP finger requests on port 1079 and will read data from the web.
35. Install http://www.zope.org/Products/ZopeInterface before installing twisted from source. 
36. What is a Factory design pattern? What is a Protocol when the term is used in Twisted?
37. A Twisted Protocol handles code in an asynchronous manner. What this means is that the Protocol does not wait for an event, but rather handles the event as they arrive from network.
38. In the Twisted client, an instance of the Protocol class will be instantiated with you connect to the Server and will go away when the connection is finished.
39. Deferreds are an object which represent a promise of something; 
40. Like getPage() returned a Deferred object, which means that when the getPage is called ( It may not be called sequentially, because it is  asynchronous); a callback may be attached to the defered object which will ask it do whatever with the data, in our case, the callback was to print the data.

41. [http://pig.slug.org.au/talks/Twisted2/slides.html Good Tutorial]

42. There is reactor.callLater(time,callback,value) and there is task.deferLater(reactor,time,func)

43. twisted.internet.task.coiterate might be helpful to write a fibonacci series function in a asynchronous way.

44. twisted multiprocessing using ampoule.

45. spawning externally processes asynchrnously using twisted. twisted.internet.utils.getProcessValue('/usr/bin/sftp',['remote_machine','local_machine'])

46. Why is the twisted package which essentially deals with asynchronous I/O and events named internet. It is confusing with the general and difficult to remember for the newbie. Documentation update might be desirable. The internet in this documentation means internetworking.

47. Twisted is a platform for developing Internet applications.

48. Deferred abstraction symbolises a promised result and which can pass on an eventual result to a handler functions.

49. I dont get the howto/plugin.html page at all? How do I implement plugin for the IMaterial Interface?



Callbacks
=========
* twisted.internet.defer.Deferred is a promise that the function at some point
  in time will have a result.
* The Deferred mechanism, standardizes the application programmers inferface
  with all sort of blocking and delayed operations.
* Understanding reactor.callLater(2, d.callback, x*3) // What is the purpose of
  the second argument in this case?
* considered the deferred returned by twisted.enterprise.adbapi
* failure is typically an instance of twisted.python.failure.Failure instance.
* You can typically get away by not adding errbacks and still get the errors logged.
* Be careful though; if you keep a reference to the Deferred around, preventing
  it from being garbage-collected. How do I?
* It is possible to adapt, synchronous functions to return Deferred.
* Sometimes you want to be notified after several different events have all
  happened, rather than waiting for each one individually.
* You may want to wait for all connections in a list to close.
* Generating Deferreds is a Document introducing writing of Asynchronous
  functions generating deferreds.
* twisted.internet.defer.AlreadyCalledError 
* deferreds are not a non-blocking talisman; they are a signal for asynchronous
  functions to use to pass results to callback once the results are available.
* Returning Deferreds from synchronous functions; reasons :- API compatiblity
  with another function which returns deferred or making the function
  asynchronous in the future.

* Integrating blocking code with Twisted.

twisted.internet.threads.deferToThread will setup a thread to run your blocking
function, return a deferred and do the callback when the thread completes.

Firing Deferreds more than once is impossible. You can only call
Deferred.callback() or Deferred.errback() once.

Event Loop, Message Dispatcher, Message Loop or Message Pump is an event
construct that waits for and dispatches events in a program.

* event: Event Driven programming or Event Based Programming is where program
  flow happens based on events like mouse movement or key press or signal from
  another thread.

* Event Driven Programming is paradigm, in which there is a main-loop, which
  does event-detection and event-handling.

Comment: In the question I asked, everyone thought that my main requirement was
event detection of new file arrival. 

Whereas my main event is request for logs from data-source; and based on the
data-source, I want to pass it to the event-handler.

It works by polling an internal or external event provider which generally
*blocks* until an event has arrived and then calls the relevant event handler
in order to handle the event.

The event loop may be used in conjuction with a reactor, if the event provider
follows a file interface, which can be select(ed) or poll(ed).

* reactor:  The reactor design pattern is a concurrent programming pattern, for
  handling service requests delivered concurrently to a service handler by one
  or more inputs.

* The service handler then demultiplexes the incoming requests and dispatches
  them synchronously to associated request handlers.

The event loop almost always operates asynchronously with the message
originator.  The event loop forms the central constuct flow of the program, is
the highest level of control within the program. It is often termed as the
main-loop or the main-event loop.

The event loop is the specific implementation techniques of system which does
message passing.

Under Unix, everything is a file-paradigm naturally leads to a file based
event-loop. select and poll system calls monitor a set of file-descriptors for
events.

Handling Signals:

One of few things in Unix that do not confirm to file descriptors are
asynchronous events (signals); signals are received in signal handlers, small,
limited piece of code that run while rest of the task is suspended. 

* In Computing, Network Programming is essentially identified as socket
  programming or client-server programming, involves writing computer programs
  that communicate with other programs across the Computer Network.  The
  program initiating the communication is called the client and the program
  waiting for the communication to get initiated is called the server.
  The client and the server process together form the distributed system. The
  connection between the client and the server process may be connection
  oriented (TCP/IP or session) or connectionless (UDP)

The program that can act both as server and client is based on peer-to-peer
communication. Sockets are usually implemented by an API library such a
Berkeley sockets, first introduced in 1983. The example functions provided by
the API library include:

* socket() - creates a new socket of certain type, identified by the integer
  number and allocates system resources to it.
* bind() is used at the server side; associates a socket with a socket adddress
  structure, typically a IP Address and a Port number.
* listen() is used again on the server side, causes a bound TCP socket to
  listen to enter a listening state.
* connect() is used on the client side; used to assign a free local port number
  to the socket. It causes an attempt to establish a new TCP Connection.
* accept() is used on the server side; It accepts a received incoming connect()
  request and creates a new socket associated with the socket address pair for
  this connection.
* send(), recv(), write(), read() or recvfrom() and sendto() are used for
  sending and receiving data.
* close() is used to terminate the connection and release the resources
  allocated to the socket. 

Twisted project supports TCP, UDP, SSL/TLS and IP Multicast, Unix Domain
Sockets, a large number of protocols such  as HTTP, XMPP, NNTP, IMAP, SSH, IRC,
FTP.

Deferred is a value which has not been computed yet; because it needs data from
remote peer.

Requesting method requests a data; and gets a Deferred object.
Requesting method attaches callbacks to the Deferred object, 

Interface classes are a way of specifying what methods and attributes an 

* In the Twisted, internet term actually denotes internetworking.

External Training Presentations 

Alex Martelli's Tutorials
-------------------------

1) http://www.aleax.it/python_mat_en.html

2) http://www.strakt.com/dev_talks.html

Norman Matloff's Python Tutorials
---------------------------------

1) http://heather.cs.ucdavis.edu/~matloff/python.html 

Python Books
------------

http://www.rexx.com/~dkuhlman/python_book_01.html

Python and Vim
--------------

http://henry.precheur.org/2008/4/18/Indenting_Python_with_VIM.html
 
http://blog.sontek.net/2008/05/11/python-with-a-modular-ide-vim/ 

How is the Dictionary keys assigned in Python? 
----------------------------------------------

Tutorials

* Alex Martellis Callback tutorial: http://www.youtube.com/watch?v=LCZRJStwkKM


Interfaces

* In Java World, interfaces form the contract between the class and the outside
  world, and this contract is enforced at the build time by the compiler.

Essay:

A programming language should equip us with structures that help us to reason more effectively.
Smalltalk and Scheme have powerful influence on language designers.

Caught an exception while rendering: The model BlogPost is already registered

http://adil.2scomplement.com/2008/09/django-the-model-mymodel-is-already-registered/

Object Oriented Programming
---------------------------

Factory Method Pattern 
----------------------

* Object Oriented Design Pattern.
* It is a creational pattern, dealing with creation of objects (products)
  without specifying the exact class.
* The creational patterns abstract the concept of instantiating objects.
* It handles this case by defining a separate method for creation objects.
* The subclasses of that method or object (??)can override to specify the
  derived type of the product that will be created.
* Factory method is used to refer to any method whose main purpose is to create
  objects. 
* The Factory pattern in c++ wraps the usual object creation syntax new
  someclass() in a function or a method which can control the creation.
* Advantages is that, code using the class no longer needs to know all the
  details of creation. It may not even know the exact type of object
  created.
* Abstract Factory provides additional indirection to let the type of object
  which is created to vary.
* Factory pattern is fundamental in python; while languages like C++ use
  ClassName class; to create classes python uses function class syntax to
  create objects. Even builtin types str, int provide factory pattern.

References
----------

* [http://code.activestate.com/recipes/86900/ Factory Example]
* [http://www.suttoncourtenay.org.uk/duncan/accu/pythonpatterns.html Python Patterns]

* SAX - Simple API for XML - serial access parser API for XML.

* SAX provides a mechanism for reading data from an XML document. Its popular
  alternative is DOM.

Unlike DOM there is no formal specification of SAX. The Java implementation of
SAX is considered to be normative, and implementations in other languages
attempt to follow the rules laid down in that implementation, adjusting for
differences in the language when necessary.

Benefits of SAX - less memory, it is serial.  DOM requires to load the entire
XML tree.

Drawbacks:

Certain kind of XML validation requires to read the complete XML.

I do not know how to use HTMLParser module in Python Standard Library. There is
not a good example in the Python docs also.  HTMLParser implementation supports
HTML 2.0 language as described in RFC 1866.

xml.etree.ElementTree

First of all understand that Element Tree is a tree datastructure. It
represents the XML document as a Tree. The XML Nodes are Elements. (Thus Element Tree)
Now, if I were to structure an html document as a element tree.

::


                <html>
                  |
                <head> -------
                /   \        |
             <title> <meta> <body>
                           /   |  \
                        <h1>  <h2> <para>
                                   /   \
                                  <li> <li>


The Element type is a flexible container object, designed to store hierarchical
data structures in memory. The type can be described as a cross between a list
and a dictionary.  The C implementation of xml.etree.ElementTree is available
as xml.etree.cElementTree


.. _Joel's article on Unicode: http://www.joelonsoftware.com/articles/Unicode.html 
