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

Exception-Handling Changes
--------------------------

One error that Python programmers occasionally make
is writing the following code::

    try:
        ...
    except TypeError, ValueError:  # Wrong!
        ...

The author is probably trying to catch both :exc:`TypeError` and
:exc:`ValueError` exceptions, but this code actually does something
different: it will catch :exc:`TypeError` and bind the resulting
exception object to the local name ``"ValueError"``.  The
:exc:`ValueError` exception will not be caught at all.  The correct
code specifies a tuple of exceptions::

    try:
        ...
    except (TypeError, ValueError):
        ...

This error happens because the use of the comma here is ambiguous:
does it indicate two different nodes in the parse tree, or a single
node that's a tuple?

Python 3.0 makes this unambiguous by replacing the comma with the word
"as".  To catch an exception and store the exception object in the
variable ``exc``, you must write::

    try:
        ...
    except TypeError as exc:
        ...

Python 3.0 will only support the use of "as", and therefore interprets
the first example as catching two different exceptions.  Python 2.6
supports both the comma and "as", so existing code will continue to
work.  We therefore suggest using "as" when writing new Python code
that will only be executed with 2.6.


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
return an iterator that returns a stream of values.  Generators can then can be
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
