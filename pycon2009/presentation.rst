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


Question: Where do I get the built-in module names in Python?
>>> import sys
>>> print sys.builtin_module_names
