=================================
A Tour of Python Standard Library
=================================

:Conference: `PyCon 2009`_

:Presentor: O.R.Senthil Kumaran <orsenthil@gmail.com>

.. _`PyCon 2009`: http://us.pycon.org/2009/


======================
Something about Python
======================

Have you watched Ratatouille?
=============================

* Anyone can cook. ~ Gusteau

* Computer Programming for Everybody. ~ Guido.


What is Python?
===============

* Middle-layer between shell and system
* Easy to use for end programmers.
* Also convenient for library programmers.
* Multiple implementations: CPython, Jython, IronPython, PyPy
* Designed by Implementation, but still a very much designed languaged.
* Feature releases happen every 18 months and bug fix releases once in 3 months.
* Active Developer and User community.
* Python 2.x and Python 3k

Python Standard Library
=======================

Python's standard library is very extensive and it offers a wide range of
facilities. The library contains built-in modules (written in C) that provide
access to system functionality and also modules written in Python that
provide standardized solutions for many problems that occur in everyday
programming. 

Some of these modules are explicitly designed to encourage and enhance the
portability of Python programs by abstracting away platform-specifics into
platform-neutral APIs.

Many large projects, both student level projects and industrial projects can be
quickly accomplished by effective usage of the Python Standard Library modules.

Certain modules, which are written in C, are built into the interpreter.
You can find the builtin modules in the following way::

        >>> import sys
        >>> print sys.builtin_module_names

