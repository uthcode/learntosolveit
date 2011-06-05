Python3
-------

Python3 is notable because it intentionally breaks backwards compatiblity.  You
must have heard that it breaks even on beginner level print statement too.  And
there are many more changes that no automatic conversion program can help you
to migrate. This tutorial will help you to decide on Python3 for yourself and
help you plan your migration strategy, plan and understand the changes in
Python3. This tutorial will help you write Python3 code.

C Programming Roots
-------------------

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

Some of it's blemishs
---------------------

* Truncation of integer diviion is confusing to beginners and leads to unintended errors.
* Byte Oriented I/O is a source of confusion when handling Unicode characters.


Python3 - Breaking free from it's past
--------------------------------------

* One of the major changes in Python3, is it's change in focus from C/Unix oriented language.
* Fixes a number of subtle design problems associated with Original implementation.

Python3 does not break backwards compatibility on a whim, but there were
certain warts in the language, which Guido wanted to correct.

Also, it does not give you a picture, that Python 3 exists because "Guido
wanted it that way or want to fix some mistakes". People throwing this argument
will definitely not be able to convince many folks to use Python 3. Instead it
portrays in a nice way as how the old python had its strong roots in C, and as
Python matured as a language, useful for writing frameworks and being used by
framework authors for various different purposes, it needs some good features
and needs to adopt from other major languages such as Java or C#.

Here are some important points from that.

1. Change in print stmt is acknowledged. (I have got used to writing print() as of 2011)
2. Layered IO. Explains how it mimics Java's IO to certain extent.
3. String formatting features. I really did not know that it was inspired from .Net framework. News to me.
4. Function annotations - And a way to write contract style programming using
function annotations and decorators. I shall write an example in the next post.
5. metaclass using metaclass keyword and does its processing before the class
definition execution as opposed later.
6. Unicode handling - Yes, the 'bite of python3'.

The article mentions that handling of Unicode is forced upon the programmer who
never had to deal with it so far. This is true. I hope when major frameworks
start using Python3, this gets abstracted away or rather we learn as how Java
crowd does it without any fuss.

As it was written during 3.0 release, it had written about IO layer being slow
as major drawback, this is no longer a case, where 3.1 had IO written in C and
is fast again.

On whole, it is really a good one to give a comprehensive and an objective
'Introduction to Python3'.
