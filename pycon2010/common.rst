Lets recollect certain common Programming Paradigms
===================================================

Regular Expressions
-------------------

* Regular Expressions are pattern that specify the matching rule.
* foo.*  # matches everything that starts with foo
* \d*    # matches all digits.
* [a-zA-Z]* # matches sequence of letters.
* text - match the literal text.
* .
* ^
* $
* *
* +
* ?
* \*?
* +?
* {m,n}
* {m,n}?
* [...]
* [^...]
* A|B
* (...)

Special characters

\number  - any text matched by previous group.
\A       - matches the start of the string.
\b       - matches empty string at the beginning or end of the string.
\B       - matches empty string not at the begining or end of the string.
\d       - matches a decimal digit.
\D       - matches any non-digit.
\s       - matches any whitespace.
\S      
\w      - matches alpha-numeric character.
\W      - matches non alpha-numeric character.
\Z      - End of string.

To Avoid the backslash plague, a raw string is used.
prefix the string with r''

* use re module to create a Regex Object.
* do a match or search on the regex object.

Interesting example:


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

*  with statement
* Some objects define standard clean-up actions to be undertaken when the
  object is no longer needed, regardless of whether or not the operation using
  the object succeeded or failed. 

::

        with open("myfile.txt") as f:
            for line in f:
                print line

* After the statement is executed, the file f is always closed, even if a
  problem was encountered while processing the lines. 

* Exceptions are Classes and are __builtin__ to the interpreter.
* Until 1.5, simple string messages were exceptions.
* The exception classes are defined in a hierarchy, related exceptions can be caught by catching their base classes.

BaseException
^^^^^^^^^^^^^

Baseclass for all exceptions. Implements logic for creating the string
representation of the exception using the str() from the arguments passed to
the constructor.

Exception
^^^^^^^^^

Baseclass for the exception that do not result in quitting the running
application. All user-defined exceptions should use Exception as a base class.

StandardError
^^^^^^^^^^^^^
Baseclass for builtin exceptions used in Standard Library.

ArthimeticError
^^^^^^^^^^^^^^^

Baseclass for math related errors.

LookupError
^^^^^^^^^^^

When something cannot be found.

EnvironmentError
^^^^^^^^^^^^^^^^

Base class for errors that come from outside of Python (the operating system,
filesystem, etc.).

AssertionError
^^^^^^^^^^^^^^

An AssertionError is raised by a failed assert statement.

::
        >>>assert False, 'The assertion failed'
        >>># This should throw a simple AssertionError

AttributeError
^^^^^^^^^^^^^^

When an attribute reference or assignment fails, AttributeError is raised.

::
        >>> x = "PyCon 2009"
        >>> x.imag
        >>> # This would throw AttributeError


AttributeError will also be raised when trying to modify a read-only attribute.

::

        class MyClass(object):
            
            @property
                def attribute(self):
                        return 'This is the attribute value'

                        o = MyClass()
                        print o.attribute
                        o.attribute = 'New value'

EOFError
^^^^^^^^

An EOFError is raised when a builtin function like input() or raw_input() do
not read any data before encountering the end of their input stream. 

IOError
^^^^^^^

Raised when input or output fails, for example if a disk fills up or an input file does not exist.

::
        f = open('/does/not/exist', 'r')

importError
^^^^^^^^^^^

Raised when a module, or member of a module, cannot be imported.

IndexError
^^^^^^^^^^

An IndexError is raised when a sequence reference is out of range.

::

        my_seq = [ 0, 1, 2 ]
        print my_seq[3]

KeyError
^^^^^^^^
A KeyError is raised when a value is not found as a key of a dictionary.

::
        d = { 'a':1, 'b':2 }
        print d['c']

KeyboardInterrupt
^^^^^^^^^^^^^^^^^

A KeyboardInterrupt occurs whenever the user presses Ctrl-C (or Delete) to stop
a running program. Unlike most of the other exceptions, KeyboardInterrupt
inherits directly from BaseException to avoid being caught by global exception
handlers that catch Exception.

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

MemoryError
^^^^^^^^^^^

If your program runs out of memory and it is possible to recover (by deleting
some objects, for example), a MemoryError is raised.

::

        import itertools

        # Try to create a MemoryError by allocating a lot of memory
        l = []
        for i in range(3):
            try:
                for j in itertools.count(1):
                    print i, j
                    l.append('*' * (2**30))
            except MemoryError:
                print '(error, discarding existing list)'
                l = []

NameError
^^^^^^^^^

NameErrors are raised when your code refers to a name that does not exist in
the current scope. For example, an unqualified variable name.

NotImplementedError
^^^^^^^^^^^^^^^^^^^

User-defined base classes can raise NotImplementedError to indicate that a
method or behavior needs to be defined by a subclass, simulating an interface.

Iterators
----------

An iterator is an object representing a stream of data; this object returns the
data one element at a time.  A Python iterator must support a method called
``next()`` that takes no arguments and always returns the next element of the
stream.  If there are no more elements in the stream, ``next()`` must raise the
``StopIteration`` exception.  Iterators don't have to be finite, though; it's
perfectly reasonable to write an iterator that produces an infinite stream of
data.

The built-in :func:`iter` function takes an arbitrary object and tries to
return an iterator that will return the object's contents or elements, raising
:exc:`TypeError` if the object doesn't support iteration.  Several of Python's
built-in data types support iteration, the most common being lists and
dictionaries.  An object is called an **iterable** object if you can get an
iterator for it.

Note that you can only go forward in an iterator; there's no way to get the
previous element, reset the iterator, or make a copy of it.  Iterator objects
can optionally provide these additional capabilities, but the iterator protocol
only specifies the ``next()`` method.  Functions may therefore consume all of
the iterator's output, and if you need to do something different with the same
stream, you'll have to create a new iterator.

List Comprehensions
-------------------
Two common operations on an iterator's output are 1) performing some operation
for every element, 2) selecting a subset of elements that meet some condition.
For example, given a list of strings, you might want to strip off trailing
whitespace from each line or extract all the strings containing a given
substring.

List comprehensions and generator expressions (short form: "listcomps" and
"genexps") are a concise notation for such operations, borrowed from the
functional programming language Haskell (http://www.haskell.org).  You can strip
all the whitespace from a stream of strings with the following code::

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

Example of List Comprehension

>>> seq1 = 'abc'
>>> seq2 = (1,2,3)
>>> [(x,y) for x in seq1 for y in seq2]
[('a', 1), ('a', 2), ('a', 3),
('b', 1), ('b', 2), ('b', 3),
('c', 1), ('c', 2), ('c', 3)]


To avoid introducing an ambiguity into Python's grammar, if ``expression`` is
creating a tuple, it must be surrounded with parentheses.  The first list
comprehension below is a syntax error, while the second one is correct::

    # Syntax error
    [ x,y for x in seq1 for y in seq2]
    # Correct
    [ (x,y) for x in seq1 for y in seq2]


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


Generators
----------

Generators are a special class of functions that simplify the task of writing
iterators.  Regular functions compute a value and return it, but generators
return an iterator that returns a stream of values.  Generators can they can be
thought of as resumable functions.

Here's the simplest example of a generator function:

    def generate_ints(N):
        for i in range(N):
            yield i

Any function containing a ``yield`` keyword is a generator function; this is
detected by Python's :term:`bytecode` compiler which compiles the function
specially as a result.

Inside a generator function, the ``return`` statement can only be used without a
value, and signals the end of the procession of values; after executing a
``return`` the generator cannot return any further values.  ``return`` with a
value, such as ``return 5``, is a syntax error inside a generator function.  The
end of the generator's results can also be indicated by raising
``StopIteration`` manually, or by just letting the flow of execution fall off
the bottom of the function.

