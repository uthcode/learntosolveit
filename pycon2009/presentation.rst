=================================
A Tour of Python Standard Library
=================================

:Conference: `PyCon 2009`_

:Presentor: O.R.Senthil Kumaran <orsenthil@gmail.com>

.. _`PyCon 2009`: http://us.pycon.org/2009/


Have you watched Ratatouille?
=============================

* Anyone can cook. ~ Gusteau

* Computer Programming for Everybody. ~ Guido.


Python Standard Library
=======================

Python's standard library is very extensive, offering a wide range of
facilities. The library contains built-in modules (written in C) that provide
access to system functionality as well as modules written in Python that
provide standardized solutions for many problems that occur in everyday
programming. 

Some of these modules are explicitly designed to encourage and enhance the
portability of Python programs by abstracting away platform-specifics into
platform-neutral APIs.

Many large projects, both student level projects and industrial projects can be
quickly accomplished by effective usage of the Python Standard Library modules.


::

        Question: Where do I get the built-in module names in Python?
        >>> import sys
        >>> print sys.builtin_module_names

Python Standard library defines the builtin functions and exceptions.

::

        >>>import __builtin__
        >>>dir(__builtin__)

        >>> all([True,True,True,True])
        True
        >>> all([False,True,True,True])
        False
        >>> any([False,False,False,True])
        True
        >>> any([False,False,False,False])
        False

callable(object)
    Return True if the object argument appears callable, False if not. If this
    returns true, it is still possible that a call fails, but if it is false,
    calling object will never succeed. Note that classes are callable (calling
    a class returns a new instance); class instances are callable if they have
    a __call__() method.

What are staticmethod and classmethods?

Example of Code Inline
======================

.. literalinclude:: ex1_asyncore.py


TODO:
1) collections module
2) What are the mapping object other than the dictionary?
3) Discuss super() properly.

Notes
=====

A new style class is one that is derived, either directly or indirectly, from a built-in type. (Something that was not possible at all before python 2.2) Built-in types include types such as:

* int
* list
* tuple
* dict
* str
* and others

The base class for new style class is called object.
Here is what the new style classes have to offer:
* Properties: Attributes that are defined by get/set methods.
* staticmethods and classmethods
* The __getattribute__ hook, which unlike __getattr__, is called for every attribute access, not just when the attribute can't be found in the instance.
* Descriptors: A protocol to define the behavior of attribute access through objects.
* Overriding the constructor __new__
* Metaclasses.


What exactly is a descriptor?

In general, a descriptor is an object attribute with "binding behavior", one whose attribute access has been overridden by methods in the descriptor protocol. Those methods are __get__, __set__, and __delete__. If any of those methods are defined for an object, it is said to be a descriptor.


==========
Exceptions
==========

* Exceptions are Classes and are __builtin__ to the interpreter.
* Until 1.5, simple string messages were exceptions.
* The exception classes are defined in a hierarchy, related exceptions can be caught by catching their base classes.

*BaseException*
Baseclass for all exceptions. Implements logic for creating the string
representation of the exception using the str() from the arguments passed to
the constructor.

*Exception*
Baseclass for the exception that do not result in quitting the running application. All user-defined exceptions should use Exception as a base class.
*StandardError*
Baseclass for builtin exceptions used in Standard Library.
*ArthimeticError*
Baseclass for math related errors.
*LookupError*
When something cannot be found.

*EnvironmentError*
Base class for errors that come from outside of Python (the operating system, filesystem, etc.).

*AssertionError*

An AssertionError is raised by a failed assert statement.

::
        >>>assert False, 'The assertion failed'
        >>># This should throw a simple AssertionError

*AttributeError*

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

*EOFError*
An EOFError is raised when a builtin function like input() or raw_input() do
not read any data before encountering the end of their input stream. 

*IOError*

Raised when input or output fails, for example if a disk fills up or an input file does not exist.

::
        f = open('/does/not/exist', 'r')

*ImportError*

Raised when a module, or member of a module, cannot be imported.

*IndexError*

An IndexError is raised when a sequence reference is out of range.

::

        my_seq = [ 0, 1, 2 ]
        print my_seq[3]

*KeyError*
a KeyError is raised when a value is not found as a key of a dictionary.

::
        d = { 'a':1, 'b':2 }
        print d['c']

*KeyboardInterrupt*

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

*MemoryError*

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

NameErrors are raised when your code refers to a name that does not exist in
the current scope. For example, an unqualified variable name.

NotImplementedError

User-defined base classes can raise NotImplementedError to indicate that a
method or behavior needs to be defined by a subclass, simulating an interface.
