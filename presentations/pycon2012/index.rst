.. -*- coding: utf-8 -*-
.. include:: <s5defs.txt>
.. |==>| unicode:: U+02794 .. thick rightwards arrow

=======================================
New and Interesting in Standard Library
=======================================

.. sidebar:: Contents
   :class: handout

   .. contents:: :local:

.. class:: center small

   | What's new and interesting in Python Standard Library 2.7, 3.2 and 3.3

.. class:: center small

   | **Senthil Kumaran**
   | Python Core Developer
   | senthil@uthcode.com
   | http://www.uthcode.com

.. class:: handout

        What is coming up new in Python 2.7, 3.2 and 3.3 versions

        There are 3 versions of this presentation:

        * `S5 presentation <index.html>`__
        * `Handout <handout.html>`__
        * `reStructuredText source <index.rst>`__

        ©2010, licensed under a `Creative Commons
        Attribution/Share-Alike (BY-SA) license
        <http://creativecommons.org/licenses/by-sa/3.0/>`__.

Python 3.3 
==========

*At the moment* 

::

        $python -q
        >>> import sys;sys.version
        '3.3.0a0 (default:a92e73dfbff6, Mar 1 2012, 20:54:21)'


Language Changes in 3.3
=======================

*Memory View and Buffer Protocol*

* Improvements in MemoryView and Buffer Protocol.
* MemoryView and Buffer Protocol is used extensively by SciPy Community and had
  seen crashes and unpredictable behaviors.
* Fixes issues with dynamically allocated items in `Py_Buffer` struct

.. class:: handout
        
        http://bugs.python.org/issue10181

Flexible Unicode String
=======================

* Unicode string is changed to support multiple internal representation,
  depending on character with the largest Unicode ordinal (1, 2, 4).
* Space efficient representation and gives access to UCS-4 on all cases.
* Python now supports full unicode code points. Including non-BMP ones (i.e.
  from U+0000 to U+10FFFF).
* No narrow or wide builds. It's all wide builds.
* memory usage of string storage should decrease significantly for all
  applications.

.. class:: handout
      
         http://www.python.org/dev/peps/pep-0393/


IO and OS Exception Hierarchy
=============================

* The hierarchy of exceptions raised by OS and IO is simplified and
  fine-grained.
* It is just `OSError` for OSError, IOError, EnvironmentError, WindowsError,
  mmap.error, socket.error or select.error.
* Fine-grained subclasses for `OSError` like BlockingIOError and different File and Directory operation errors are exposed.
* ConnectionError has fine-grained subclasses like BrokenPipeError, ConnectionAbortedError, ConnectionRefusedError, ConnectionResetError.

.. class:: handout
      
         http://www.python.org/dev/peps/pep-3151/


Using new Exceptions
====================

* Previously you had to look at `errno` attribute, now you can do.

::

    try:
        with open("document.txt") as f:
            content = f.read()
    except FileNotFoundError:
        print("document.txt file is missing")
    except PermissionError:
        print("You are not allowed to read document.txt")

yield from
==========

* Syntax for delegating to a sub-generator.
* yield from expression, allowing a generator to delegate part of its operations to another generator
* yield from expression actually allows delegation to arbitrary subiterators.


Suppressing Exception Context
=============================

* `raise AttributeError(attr) from None...`
* Supresses the Expression of Context of a Nested Exception without  supressing
  the cause.


.. class:: handout

            >>> class C:
            ...     def __init__(self, extra):
            ...         self._extra_attributes = extra
            ...     def __getattr__(self, attr):
            ...         try:
            ...             return self._extra_attributes[attr]
            ...         except KeyError:
            ...             raise AttributeError(attr)
            ...
            >>> C({}).x
            Traceback (most recent call last):
              File "<stdin>", line 6, in __getattr__
            KeyError: 'x'

            During handling of the above exception, another exception occurred:

            Traceback (most recent call last):
            File "<stdin>", line 1, in <module>
            File "<stdin>", line 8, in __getattr__
            AttributeError: x

            With new syntax

            >>> class D:
            ...     def __init__(self, extra):
            ...         self._extra_attributes = extra
            ...     def __getattr__(self, attr):
            ...         try:
            ...             return self._extra_attributes[attr]
            ...         except KeyError:
            ...             raise AttributeError(attr) from None...
            >>> 
            D({}).x
            Traceback (most recent call last):
              File "<stdin>", line 1, in <module>
              File "<stdin>", line 8, in __getattr__
            AttributeError: x


Qualified names 
===============

* Functions and class objects have a new __qualname__ attribute representing
  the “path” from the module top-level to their definition.


::

    >>> class C:
    ...     def meth(self):
    ...         pass
    >>> C.meth.__name__
    'meth'
    >>> C.meth.__qualname__
    'C.meth'


There is more
=============

* http://docs.python.org/dev/whatsnew/3.3.html
* http://docs.python.org/dev/whatsnew/3.2.html
* http://docs.python.org/dev/whatsnew/2.7.html
* **Misc/NEWS** file.

::

        print('{0} {1}'.format('Thank',' you!'))

