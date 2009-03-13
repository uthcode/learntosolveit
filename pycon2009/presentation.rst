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

