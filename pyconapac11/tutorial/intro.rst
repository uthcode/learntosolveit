Introduction
------------

Python3 is notable because it intentionally breaks backwards compatiblity.  You
must have heard that it breaks even on beginner level print statement too.  And
there are many more changes that no automatic conversion program can help you
to migrate. This tutorial will help you to decide on Python3 for yourself and
help you plan your migration strategy, plan and understand the changes in
Python3. This tutorial will help you write Python3 code.

C programming language is a one of the foremost influencers of Python's basic
design, including the fundamental operators, identifiers and keywords.

The interpreter itself is written in C and special names such as ``__init__``,
``__str__`` and ``__repr__`` are inspired from the similar conventions in the C
Pre-processor. Remember the C Pre Processor Macro - __FILE__ ?

Influence of C is no accident. Python was originally envisioned as a Very High
Level System programming language, sitting somewhere between Shell and C and
Python is used for those purposes, replacing the programs written in Shell and
C.

Number of C like features are still present in Python.


* integer math operation is taken directly from C.
* truncating division is similar to C.

::

	>>> 5/4
	1
	>>>

* Python's print is modelled after C's printf statement.

::
	>>> print '%s %s' % ('hello,'world')
        hello, world

* The File Input/Output in Python is a thin layer over the operating system provided , C stdio functionality.

::
       >>> f = open('somefile')
       >>> dir(f)
       # ... read, seek, tell ...

* The methods such as read, seek, tell as same as C's stdio functions for doing file operations.

* os module providing all the posix functions.
* sockets, signals, fcntl, memory mapped files etc are all reflecting it's C past.

Python3 - New Stuff
-------------------

* One of the major changes in Python3, is it's change in focus from C/Unix oriented language. This is influenced by the change that currently the language used for developing complex frameworks and powerful programming environments.
* Fixes a number of subtle design problems associated with Original implementation.
* Python 3 fully embraces Unicode text, a change that affects almost every part of the language and library. For instance, all text strings are now Unicode, as is Python source code.
* File I/O, which is similar to Java

::
	>>> f = open(“foo”)
	>>> f
	<io.TextIOWrapper object at 0x383950>

* FileIO -> BufferedReader -> TextIOWrapper object.
* String Formatting which is similar to .Net's.

There are no “old-style” classes, string exceptions, or features that have
plagued Python developers since its very beginning, but which could not be
removed because of backwards compatibility concerns.

Python 3 builds upon list comprehension idea and adds support for set and
dictionary comprehensions. 

With new and improved, Metaclasses changes, Python 3 adds the ability to carry
out processing before any part of the class body is processed and to
incrementally perform work as each method is defined

The most significant aspect of Python 3 is that it sheds a huge number of
deprecated features and programming idioms in order to lay the groundwork for a
whole new class of advanced programming techniques. Python 3 is that the entire
language is more logically consistent, entirely customizable, and filled with
advanced features that provide an almost mind-boggling amount of power to
framework builders.
