.. How to Solve it using Python documentation master file, created by
   sphinx-quickstart on Wed Feb  3 09:03:51 2010.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

How to Solve it using Python
============================

Hello!
======

Welcome to the tutorial - "How to Solve it using Python". This is an
intermediate to advanced level tutorial, wherein we will discuss commonly
occuring programming problems and solutions. My aim is to help you to get
started into development path and start writing the building blocks of python
applications.

The tutorial slides and source code will be available at
http://uthcode.sarovar.org

**Tutorial Notes** serve as a handy reference material and is a sub-set of the
deck. The complete deck of slides along with the source code can downloaded
from http://uthcode.sarovar.org

**Happy Learning!**

Senthil Kumaran



Lets recollect certain common Programming Paradigms
===================================================

Regular Expressions
-------------------

**Compiling Regular Expressions**

Regular expressions are compiled into pattern objects, which have
methods for various operations such as searching for pattern matches or
performing string substitutions. ::

   >>> import re
   >>> p = re.compile('ab*')
   >>> print p
   <_sre.SRE_Pattern object at 80b4150>

:func:`re.compile` also accepts an optional *flags* argument, used to enable
various special features and syntax variations.::

   >>> p = re.compile('ab*', re.IGNORECASE)


**Methods for searching and matching on RegexObject.**

+------------------+-----------------------------------------------+
| Method/Attribute | Purpose                                       |
+==================+===============================================+
| ``match()``      | Determine if the RE matches at the beginning  |
|                  | of the string.                                |
+------------------+-----------------------------------------------+
| ``search()``     | Scan through a string, looking for any        |
|                  | location where this RE matches.               |
+------------------+-----------------------------------------------+
| ``findall()``    | Find all substrings where the RE matches, and |
|                  | returns them as a list.                       |
+------------------+-----------------------------------------------+
| ``finditer()``   | Find all substrings where the RE matches, and |
|                  | returns them as an :term:`iterator`.          |
+------------------+-----------------------------------------------+

ToAvoid the backslash plague, a raw string is used.  prefix the string with r''

You can also do search and replacement using the sub method.  In the following
example, the replacement function translates  decimals into hexadecimal::

   >>> def hexrepl( match ):
   ...     "Return the hex string for a decimal number"
   ...     value = int( match.group() )
   ...     return hex(value)
   ...
   >>> p = re.compile(r'\d+')
   >>> p.sub(hexrepl, 'Call 65490 for printing, 49152 for user code.')
   'Call 0xffd2 for printing, 0xc000 for user code.'


Exception Handling
------------------

::

        try:
            print 'Press Return or Ctrl-C:',
            ignored = raw_input()
        except Exception, err:
            print 'Caught exception:', err
        except KeyboardInterrupt, err:
            print 'Caught KeyboardInterrupt'
        else:
            print 'No exception'

Iterators
----------

An iterator is an object representing a stream of data; this object returns the
data one element at a time.  A Python iterator must support a method called
``next()`` (Python2) and ``__next__()`` (Python3) that takes no arguments and
always returns the next element of the stream.  If there are no more elements
in the stream, ``next()``/ ``__next__()`` must raise the ``StopIteration``
exception.  Iterators don't have to be finite, though; it's perfectly
reasonable to write an iterator that produces an infinite stream of data.  You
can only go forward in an iterator; there's no way to get the previous element,
reset the iterator, or make a copy of it.  

List Comprehensions
-------------------
Two common operations on an iterator's output are 1) performing some operation
for every element, 2) selecting a subset of elements that meet some condition.
List comprehensions and generator expressions (short form: "listcomps" and
"genexps") 

You can strip all the whitespace from a stream of strings with the following
code::

    line_list = ['  line 1\n', 'line 2  \n', ...]
    # Generator expression -- returns iterator
    stripped_iter = (line.strip() for line in line_list)
    # List comprehension -- returns list
    stripped_list = [line.strip() for line in line_list]

You can select only certain elements by adding an ``"if"`` condition::

    stripped_list = [line.strip() for line in line_list
                     if line != ""]

With a list comprehension, you get back a Python list; ``stripped_list`` is a
list containing the resulting lines, not an iterator.  Generator expressions
return an iterator that computes the values as necessary, not needing to
materialize all the values at once.  This means that list comprehensions aren't
useful if you're working with iterators that return an infinite stream or a very
large amount of data.  Generator expressions are preferable in these situations.

To avoid introducing an ambiguity into Python's grammar, if ``expression`` is
creating a tuple, it must be surrounded with parentheses.  The first list
comprehension below is a syntax error, while the second one is correct::

    # Syntax error
    [ x,y for x in seq1 for y in seq2]
    # Correct
    [ (x,y) for x in seq1 for y in seq2]


Generators
----------

Generators are a special class of functions that simplify the task of writing
iterators.  Regular functions compute a value and return it, but generators
return an iterator that returns a stream of values.  Generators can they can be
thought of as resumable functions.

Here's the simplest example of a generator function::

    def generate_ints(N):
        for i in range(N):
            yield i

Any function containing a ``yield`` keyword is a generator function; this is
detected by Python's ``bytecode`` compiler which compiles the function
specially as a result.

Inside a generator function, the ``return`` statement can only be used without a
value, and signals the end of the procession of values; after executing a
``return`` the generator cannot return any further values.  ``return`` with a
value, such as ``return 5``, is a syntax error inside a generator function.  The
end of the generator's results can also be indicated by raising
``StopIteration`` manually, or by just letting the flow of execution fall off
the bottom of the function.


Interesting Modules that ease our tasks
=======================================

Collections module
------------------

Collections module implements high-performance container datatypes.  Currently,
there are four datatypes, :class:`Counter`, :class:`deque`, :class:`OrderedDict` and
:class:`defaultdict`, and one datatype factory function, :func:`namedtuple`.

The specialized containers provided in this module provide alternatives
to Python's general purpose built-in containers, :class:`dict`,
:class:`list`, :class:`set`, and :class:`tuple`.

In addition to containers, the collections module provides some ABCs
(abstract base classes) that can be used to test whether a class
provides a particular interface, for example, whether it is hashable or
a mapping.

A counter tool is provided to support convenient and rapid tallies.
For example::

    >>> # Tally occurrences of words in a list
    >>> cnt = Counter()
    >>> for word in ['red', 'blue', 'red', 'green', 'blue', 'blue']:
    ...     cnt[word] += 1
    >>> cnt
    Counter({'blue': 3, 'red': 2, 'green': 1})

    >>> # Find the ten most common words in Hamlet
    >>> import re
    >>> words = re.findall('\w+', open('hamlet.txt').read().lower())
    >>> Counter(words).most_common(10)
    [('the', 1143), ('and', 966), ('to', 762), ('of', 669), ('i', 631),
     ('you', 554),  ('a', 546), ('my', 514), ('hamlet', 471), ('in', 451)]


**deque([iterable[, maxlen]])**

   Deques are a generalization of stacks and queues (the name is pronounced "deck"
   and is short for "double-ended queue").  Deques support thread-safe, memory
   efficient appends and pops from either side of the deque with approximately the
   same O(1) performance in either direction.

::

    def moving_average(iterable, n=3):
        # moving_average([40, 30, 50, 46, 39, 44]) --> 40.0 42.0 45.0 43.0
        # http://en.wikipedia.org/wiki/Moving_average
        it = iter(iterable)
        d = deque(itertools.islice(it, n-1))
        d.appendleft(0)
        s = sum(d)
        for elem in it:
            s += elem - d.popleft()
            d.append(elem)
            yield s / float(n)

**Default Dict**

Using :class:`list` as the :attr:`default_factory`, it is easy to group a
sequence of key-value pairs into a dictionary of lists::

   >>> s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
   >>> d = defaultdict(list)
   >>> for k, v in s:
   ...     d[k].append(v)
   ...
   >>> d.items()
   [('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]


**Namedtuple**

named tuples assign meaning to each position in a tuple and allow for more
readable, self-documenting code.  They can be used wherever regular tuples are
used, and they add the ability to access fields by name instead of position
index.::

        >>> from collections import namedtuple
        >>> Point = namedtuple('Point', 'x y', verbose=True)


**Ordered Dictionary**

Ordered dictionaries are just like regular dictionaries but they remember the
order that items were inserted.  When iterating over an ordered dictionary,
the items are returned in the order their keys were first added.


itertools module
----------------

The :mod:`itertools` module contains a number of commonly-used iterators as
well as functions for combining several iterators.The module's functions fall
into a few broad classes:

* Functions that create a new iterator based on an existing iterator.
* Functions for treating an iterator's elements as function arguments.
* Functions for selecting portions of an iterator's output.
* A function for grouping an iterator's output.

Creating new iterators
----------------------

``itertools.count(n)`` returns an infinite stream of integers, increasing by 1
each time.  You can optionally supply the starting number, which defaults to 0::

    itertools.count() =>
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ...
    itertools.count(10) =>
      10, 11, 12, 13, 14, 15, 16, 17, 18, 19, ...

``itertools.cycle(iter)`` saves a copy of the contents of a provided iterable
and returns a new iterator that returns its elements from first to last.  The
new iterator will repeat these elements infinitely. ::

    itertools.cycle([1,2,3,4,5]) =>
      1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...

``itertools.repeat(elem, [n])`` returns the provided element ``n`` times, or
returns the element endlessly if ``n`` is not provided. ::

    itertools.repeat('abc') =>
      abc, abc, abc, abc, abc, abc, abc, abc, abc, abc, ...
    itertools.repeat('abc', 5) =>
      abc, abc, abc, abc, abc

``itertools.chain(iterA, iterB, ...)`` takes an arbitrary number of iterables as
input, and returns all the elements of the first iterator, then all the elements
of the second, and so on, until all of the iterables have been exhausted. ::

    itertools.chain(['a', 'b', 'c'], (1, 2, 3)) =>
      a, b, c, 1, 2, 3

``itertools.izip(iterA, iterB, ...)`` takes one element from each iterable and
returns them in a tuple::

    itertools.izip(['a', 'b', 'c'], (1, 2, 3)) =>
      ('a', 1), ('b', 2), ('c', 3)

Selecting elements
------------------

Another group of functions chooses a subset of an iterator's elements based on a
predicate.

``itertools.ifilter(predicate, iter)`` returns all the elements for which the
predicate returns true::

    def is_even(x):
        return (x % 2) == 0
    itertools.ifilter(is_even, itertools.count()) =>
      0, 2, 4, 6, 8, 10, 12, 14, ...

``itertools.ifilterfalse(predicate, iter)`` is the opposite, returning all
elements for which the predicate returns false::

    itertools.ifilterfalse(is_even, itertools.count()) =>
      1, 3, 5, 7, 9, 11, 13, 15, ...

``itertools.takewhile(predicate, iter)`` returns elements for as long as the
predicate returns true.  Once the predicate returns false, the iterator will
signal the end of its results.

::

    def less_than_10(x):
        return (x < 10)

    itertools.takewhile(less_than_10, itertools.count()) =>
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9

    itertools.takewhile(is_even, itertools.count()) =>
      0

``itertools.dropwhile(predicate, iter)`` discards elements while the predicate
returns true, and then returns the rest of the iterable's results.

::

    itertools.dropwhile(less_than_10, itertools.count()) =>
      10, 11, 12, 13, 14, 15, 16, 17, 18, 19, ...

    itertools.dropwhile(is_even, itertools.count()) =>
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ...

* There is more magic in both collections and itertools. Please refer to the
  standard library documentation.

Let's start with strings
========================

The main tool Python gives us to process text is strings - immutable sequence
of characters.In Python2, there are two kinds of strings: plain strings, which
contain 8-bit (ASCII) characters; and Unicode Strings, which contain Unicode
characters.In Python3, there is only one string - which is unicode string.
Strings are immutable, which means that no matter what operations you do on a
string, you will always produce a new string object, rather than mutating the
existing string. In general, you can do anything to a string that you can do to
any other sequence, as long as it doesn't require changing the sequence, since
the strings are immutable.

:: 

	list_of_lines = one_large.string.splitlines()
	one_large_string = '\n'.join(list_of_lines)


**Characters of a string.**

::

	list("python")
	map(somefunc,"python")
	map(lambda x:x,"python")
	sets.Set("python")

**Reversing**

For sequences, the extended slicing with negative step can be used for
reversing. [::-1] There is reversed built-in function which can also be used
for reversing the words in a sentence.  But for reversing the characters in a
string, if reversed is used, then a ''.join needs to be called.  The reversed
returns an iterator, suitable for looping on or for passing to some
"accumulator" callable such as ''.join. It does not return a ready made string.

**string functions**

string.translate(s, table[, deletechars])

   Delete all characters from *s* that are in *deletechars* (if
   present), and then translate the characters using *table*, which
   must be a 256-character string giving the translation for each
   character value, indexed by its ordinal.  If *table* is ``None``,
   then only the character deletion step is performed.

string.maketrans(from, to)

   Return a translation table suitable for passing to ``translate()``, that
   will map each character in *from* into the character at the same position in
   *to*; *from* and *to* must have the same length.  Note: Don't use strings
   derived from ``lowercase`` and ``uppercase`` as arguments; in some locales,
   these don't have the same length.  For case conversions, always use
   ``str.lower()`` and ``str.upper()``.

* Look at the string examples for scripts that demonstrate these functions.


**Examples of string.Template method**

:: 

        import string

        # make a template from  string where some identifiers are marked with $

        template = string.Template('this is a $template')
        print template.substitute({'template':5})
        print template.substitute({'template':'five'})

        # even keyword arguments is possible

        print template.substitute(template=5)
        print template.substitute(template='five')


+---------+-----------------------------+---------------------------------------------+
| builtin |  *python2*                  |  *python3*                                  |
+=========+=============================+=============================================+
| repr    |   obj to str                |   obj to str                                |
+---------+-----------------------------+---------------------------------------------+
| ord     |   c to int                  |   c to int, valid surrogate pair accepted.  |
+---------+-----------------------------+---------------------------------------------+
| chr     |   i to c, 0 <= i < 256,     |   i to u , 0 <= i < 0x10ffff                |
+---------+-----------------------------+---------------------------------------------+
| unichr  |   i to u, 0 <= i < 0x10ffff |      NA                                     |
+---------+-----------------------------+---------------------------------------------+

**string, unicode string, bytes, bytestring**

Strings are sequence of characters (ascii in python2 and unicode - python3),
e.g. an HTML Document.Bytes are not characters an JPEG Document.

A general rule of thumb is Bytesting contains encoded data and a unicode
object contains unencoded data.

* bytes object have a decode() method that takes a character encoding and returns a string.
* string object has a encode method that takes a a character encoding and returns a bytes object.

Python 2.0 had strings and Unicode Strings.
Python 3.0 has strings. That is it.But you wont miss 8 bit strings which acted
as bytes in python2, because there is a separate bytes datatype.

**Reindent a particular string**

.. literalinclude:: strings_reindent.py

Files - we handle them often
============================

* The builtin function ``open`` opens the file and returns a stream. It raises
  an IOError upon failure.

* A variant of 'r' that is sometimes precious is 'rU', which tells Python to
  read the file in text mode with "universal newlines": mode 'rU' can read text
  files independently of the line termination convention the files are using,
  be it the Unix way, the Windows way or even the (Old) Mac way. (Mac OS X
  today uses Unix for all intents and purposes, but releases of Mac OS 9 and
  earlier were different).

* When read is called with an integer argument N, it reads and returns the next
  N bytes (or all the remaining bytes if less than N bytes remain)

* Files have other writing related methods such as flush, to send any data
  being buffered, and writelines, to write a sequence of strings in a single
  call.  However, write is by far the most commonly used method.

* Other methods worth mentioning are seek and tell, which support random access
  to files. These methods are normally used with binary files made up of
  fixed-length records.

* StringIO objects are plug-and-play compatible with file objects, so scanner
  takes its three lines of text from an in-memory string object, rather than a
  true external file.This shows that Everywhere in Python, object interfaces,
  rather than specific data types are units of coupling.



* Often the data you want to write is not in one bit string, but in a list (or
  other sequence) of strings. In this case, you should use the writelines
  method (which despite its name, is not limited to lines and works just as
  well with binary data as well as text files). Calling writelines is much
  faster than the alternatives of joining the strings into one big string (e.g,
  with the ''.join) and then calling write or calling write repeatedly in a
  loop.  Calling close is even more advisable when you are writing to a file
  than you are reading from a file.

* With ZipFile, the flag is not used the same way when opening a file, and rb
  is not recognized. The r flag handles the inherently binary nature of all zip
  files on all platforms.

**StringIO object as a fileobject**

.. literalinclude:: files_StringIO.py

Date and time related
=====================

* One of the most used function is from the module time which is `time.time`.
  This returns the number of seconds passed since a fixed instant called the
  epoch, it is usually the midnight of 1 Jan 1970.
 

To find out which epoch, your platform uses::

        >>> import time
        >>> print time.asctime(time.gmtime(0))

* `time.gmtime` - converts any timestamp into a tuple without TZ convertion.
* `time.asctime`- represents it in human readable way.

Here is a way to unpack the tuple representing the current local time::

        >>> time.localtime()
        time.struct_time(tm_year=2010, tm_mon=2, tm_mday=10, tm_hour=20, tm_min=43,
        tm_sec=38, tm_wday=2, tm_yday=41, tm_isdst=0)

        >>> year, month, mday, hour, minute, sec, wday, yday, isdst = time.localtime()

        >>> time.localtime().tm_mday, time.localtime().tm_mon, time.localtime().tm_year
        (10, 2, 2010)


* calling `time.localtime`, `time.gmtime`, `time.asctime` without any argument,
  each of them conveniently defaults to using the current time.
* `time.strftime` - builds a string from a time tuple.
* `time.strptime` - produces a time tuple from a string.
* `time.sleep` - helps you introduce delays in your python programs. 

The POSIX sleep accepts only the seconds delay, i.e. the integer value, but
Python version accepts float and allows for sub-second delays.

* The `datetime` module provides better abstractions to deal with dates and
  times.::

        >>> today = datetime.date.today()
        >>> print(today)
        2010-02-10
        >>> birthday = datetime.date(1987,3,9)
        >>> print(birthday)
        1987-03-09
        >>> currenttime = datetime.datetime.now().time()
        >>> lunchtime = datetime.time(13,00)
        >>> now = datetime.datetime.now()
        >>> epoch = datetime.datetime(1970,1,1)
        >>> meeting = datetime.datetime(2010,2,17,15,30)
        >>> print(meeting)
        2010-02-17 15:30:00


**Parse the RFC 1123 date format**

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

* The datetime objects are immutable. Useful when using in sets and
  dictionaries.::

        >>> today = datetime.date.today()
        >>> next_year = today.replace(year=today.year+1)
        SyntaxError: invalid syntax
        >>> print(next_year)
        2011-02-10

* dateutil and mxDatetime are two third party utils that are worth looking at
  too.


Processing XML
==============

* XML is the open standards way of exchanging information.
* Dealing with XML is not very seamless, there is always a requirement to write
  code that reads (i.e, deserializes or parses) and writes (i.e, serializes)
  XML.
* It is important to note that modules in the xml package require that there be
at least one SAX-compliant XML parser available. Starting with Python 2.3, the
Expat parser is included with Python, so the xml.parsers.expat module will
always be available. 
* xml.dom and xml.sax packages are the definition of the Python bindings for the DOM and SAX interfaces.

**Parsing XML using xml.etree module**

First of all understand that Element Tree is a tree datastructure. It
represents the XML document as a Tree. The XML Nodes are Elements. (Thus Element Tree)
Now, if I were to structure an html document as a element tree.:: 

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
as xml.etree.cElementTree::


    <html>
        <head>
            <title>Example page</title>
        </head>
        <body>
            <p>Moved to <a href="http://example.org/">example.org</a>
            or <a href="http://example.com/">example.com</a>.</p>
        </body>
    </html>

Example of changing the attribute "target" of every link in first paragraph::

    >>> from xml.etree.ElementTree import ElementTree
    >>> tree = ElementTree()
    >>> tree.parse("index.xhtml")
    <Element html at b7d3f1ec>
    >>> p = tree.find("body/p")     # Finds first occurrence of tag p in body
    >>> p
    <Element p at 8416e0c>
    >>> links = p.getiterator("a")  # Returns list of all links
    >>> links
    [<Element a at b7d4f9ec>, <Element a at b7d4fb0c>]
    >>> for i in links:             # Iterates through all found links
    ...     i.attrib["target"] = "blank"
    >>> tree.write("output.xhtml")

Dealing with Databases
======================

There are only two kinds of computer programs: toy programs and programs that
interact with some kind of persistent databases.

* sqllite database is included as part of Python's standard library.
* Python provides a number of built-in facilities for storing and retrieving data. pickle module should be used always and marshal exists for the purposes of 'pyc' files.


**using sqlite3**

SQLite is a C library that provides a lightweight disk-based database that
doesn't require a separate server process and allows accessing the database
using a nonstandard variant of the SQL query language. Some applications can use
SQLite for internal data storage.  It's also possible to prototype an
application using SQLite and then port the code to a larger database such as
PostgreSQL or Oracle.

To use the module, you must first create a :class:`Connection` object that
represents the database.  Here the data will be stored in the
:file:`/tmp/example` file::

   conn = sqlite3.connect('/tmp/example')

You can also supply the special name ``:memory:`` to create a database in RAM.

Once you have a :class:`Connection`, you can create a :class:`Cursor`  object
and call its :meth:`~Cursor.execute` method to perform SQL commands::

   c = conn.cursor()

   # Create table
   c.execute('''create table stocks
   (date text, trans text, symbol text,
    qty real, price real)''')

   # Insert a row of data
   c.execute("""insert into stocks
             values ('2006-01-05','BUY','RHAT',100,35.14)""")

   # Save (commit) the changes
   conn.commit()

   # We can also close the cursor if we are done with it
   c.close()

pickle module
-------------

In python3, The pickle module has an transparent optimizer (_pickle) written in
C. It is used whenever available. Otherwise the pure Python implementation is
used. 

In python2, there is a pure python pickle and a C implementation cPickle.

There are currently 4 different protocols which can be used for pickling.

    * Protocol version 0 is the original human-readable protocol and is backwards compatible with earlier versions of Python.
    * Protocol version 1 is the old binary format which is also compatible with earlier versions of Python.
    * Protocol version 2 was introduced in Python 2.3. It provides much more efficient pickling of new-style classes.
    * Protocol version 3 was added in Python 3.0. It has explicit support for bytes and cannot be unpickled by Python 2.x pickle modules. This is the current recommended protocol, use it whenever it is possible.

Refer to PEP 307 for information about improvements brought by protocol 2. See pickletools‘s source code for extensive comments about opcodes used by pickle protocols.

The following can be pickled.

    * None, True, and False
    * integers, floating point numbers, complex numbers
    * strings, bytes, bytearrays
    * tuples, lists, sets, and dictionaries containing only picklable objects
    * functions defined at the top level of a module
    * built-in functions defined at the top level of a module
    * classes that are defined at the top level of a module
    * instances of such classes whose __dict__ or __setstate__() is picklable (see section Pickling Class Instances for details)
 

For the simplest code, use the :func:`dump` and :func:`load` functions. ::

   #!/usr/bin/python3.1

   import pickle

   # An arbitrary collection of objects supported by pickle.
   data = {
       'a': [1, 2.0, 3, 4+6j],
       'b': ("character string", b"byte string"),
       'c': set([None, True, False])
   }

   with open('data.pickle', 'wb') as f:
       # Pickle the 'data' dictionary using the highest protocol available.
       pickle.dump(data, f, pickle.HIGHEST_PROTOCOL)


The following example reads the resulting pickled data. ::

   #!/usr/bin/python3.1

   import pickle

   with open('data.pickle', 'rb') as f:
       # The protocol version used is detected automatically, so we do not
       # have to specify it.
       data = pickle.load(f)



Process Handling
================

subprocess module
-----------------

The `subprocess` module allows you to spawn new processes, connect to their
input/output/error pipes, and obtain their return codes.

``subprocess.call(*popenargs, **kwargs)``
-----------------------------------------
This is convenience function provided by subprocess module which executes the command given by the argument, when shell=True is the shell variables are expanded in the command line.

.. literalinclude::        subprocess_1.py

Popen method
------------

**subprocess** module defines a class called **Popen**.

::
        class subprocess.Popen(args, bufsize=0, executable=None, stdin=None,
        stdout=None, stderr=None, preexec_fn=None, close_fds=False,
        shell=False, cwd=None, env=None, universal_newlines=False,
        startupinfo=None, creationflags=0)

* ``subprocess.PIPE``: Special value that can be used as the stdin, stdout or
  stderr argument to Popen and indicates that a pipe to the standard stream
  should be opened.

* ``subprocess.STDOUT``: Special value that can be used as the stderr argument
  to Popen and indicates that standard error should go into the same handle as
  standard output.

.. literalinclude::        subprocess_2.py

Writing a Task Scheduler
------------------------

.. literalinclude:: datetime2.py


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

Web Programming
===============

urllib module is available for doing a variety of web-related stuff.

:: 

        urllib.request - request an url.
        urllib.parse   - parse an url.
        urllib.error   - handle errors
        urllib.robotparser - handles robots.txt file.


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



Unit test - Super Cool stuff
============================

How to write Unit tests
-----------------------

The :mod:`unittest` module provides a rich set of tools for constructing and
running tests.  This section demonstrates that a small subset of the tools
suffice to meet the needs of most users.

Here is a short script to test three functions from the :mod:`random` module::

   import random
   import unittest

   class TestSequenceFunctions(unittest.TestCase):

       def setUp(self):
           self.seq = list(range(10))

       def test_shuffle(self):
           # make sure the shuffled sequence does not lose any elements
           random.shuffle(self.seq)
           self.seq.sort()
           self.assertEqual(self.seq, list(range(10)))

       def test_choice(self):
           element = random.choice(self.seq)
           self.assert_(element in self.seq)

       def test_sample(self):
           self.assertRaises(ValueError, random.sample, self.seq, 20)
           for element in random.sample(self.seq, 5):
               self.assert_(element in self.seq)

   if __name__ == '__main__':
       unittest.main()


The unittest module can be used from the command line to run tests from
modules, classes or even individual test methods::

   python -m unittest test_module1 test_module2
   python -m unittest test_module.TestClass
   python -m unittest test_module.TestClass.test_method

You can pass in a list with any combination of module names, and fully
qualified class or method names.

You can run tests with more detail (higher verbosity) by passing in the -v flag::

   python-m unittest -v test_module

For a list of all the command line options::

   python -m unittest -h

The command line can also be used for test discovery, for running all of the
tests in a project or just a subset.

Test Discovery
--------------

unittest supports simple test discovery. For a project's tests to be
compatible with test discovery they must all be importable from the top level
directory of the project; i.e. they must all be in Python packages.

Test discovery is implemented in :meth:`TestLoader.discover`, but can also be
used from the command line. The basic command line usage is::

   cd project_directory
   python -m unittest discover

The ``discover`` sub-command has the following options:

   -v, --verbose    Verbose output
   -s directory     Directory to start discovery ('.' default)
   -p pattern       Pattern to match test files ('test*.py' default)
   -t directory     Top level directory of project (default to
                    start directory)

The -s, -p, & -t options can be passsed in as positional arguments. The
following two command lines are equivalent::

   python -m unittest -s project_directory -p '*_test.py'
   python -m unittest project_directory '*_test.py'



Useful modules
==============

Performance measurements using timeit module
--------------------------------------------

::

        $ python -mtimeit -s'import random; x=range(1000); random.shuffle(x)' 'y=list(x); y.sort()'
        1000 loops, best of 3: 452 usec per loop
        $ python -mtimeit -s'import random; x=range(1000); random.shuffle(x)' 'x.sort()'
        10000 loops, best of 3: 37.4 usec per loop
        $ python -mtimeit -s'import random; x=range(1000); random.shuffle(x)' 'sorted(x)'
        1000 loops, best of 3: 462 usec per loop
        $


2to3 tool
---------

Run ``./2to3`` to convert stdin (``-``), files or directories given as
arguments.

2to3 must be run with at least Python 2.6. The intended path for migrating to
Python 3.x is to first migrate to 2.6 (in order to take advantage of Python
2.6's runtime compatibility checks).

* In the tutorial source files, run 2to3 example_for_2to3.py and analyze the
  output.

References
==========

* http://docs.python.org - Python Tutorial and Library Documentations 
* Python Cookbook - by Alex Martelli, Anna Martelli and David Ascher.
* Python Community Recipes at ActiveState.
