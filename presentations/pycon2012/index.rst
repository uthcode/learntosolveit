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


abc module
==========

* abc.abstractproperty has been deprecated, use `property` with
  abc.abstractmethod() instead.
* abc.abstractclassmethod has been deprecated, use `classmethod` with
  abc.abstractmethod() instead.
* abc.abstractstaticmethod has been deprecated, use `staticmethod` with
  abc.abstractmethod() instead.

array module
============

* array module takes long long type.

bz2 module
==========

* `bz2.BZ2File` can now read from and write to arbitrary file-like objects, by
  means of its constructor’s fileobj argument.

* `bz2.BZ2File` and `bz2.decompress()` can now decompress multi-stream inputs.
  bz2.BZ2File can now also be used to create this type of file, using the 'a'
  (append) mode.


faulthandler
============

* New `faulthandler` module.

This module contains functions to dump Python tracebacks explicitly, on a
fault, after a timeout, or on a user signal. Call faulthandler.enable() to
install fault handlers for the SIGSEGV, SIGFPE, SIGABRT, SIGBUS, and SIGILL
signals. 

lzma
====

* The newly-added lzma module provides data compression and decompression using
  the LZMA algorithm, including support for the .xz and .lzma file formats.

os module
=========

* sendfile() function which provides an efficent “zero-copy” way for copying
  data from one file (or socket) descriptor to another.

* fwalk() function similar to walk() except that it also yields file
  descriptors referring to the directories visited. 


packaging
=========

* distutils module is called packaging, helper functions for building,
  packaging, distributing and installing additional projects into a Python
  installation.

shutil
======

* shutil.disk_usage() - total, used and free disk space statistics.

signal module
=============

* signal module has functions such as pthread_sigmask, pthread_kill, sigpending, sigwait, sigwaitinfo.
* The signal handler writes the signal number as a single byte instead of a nul
  byte into the wakeup file descriptor.
* signal.signal() and signal.siginterrupt() raise an OSError, instead of a RuntimeError: OSError has an errno attribute.

ssl module
==========

* RAND_bytes(): generate cryptographically strong pseudo-random bytes.
* RAND_pseudo_bytes(): generate pseudo-random bytes.
* Query the SSL compression algorithm used by an SSL socket, thanks to its new compression() method.

sys module
==========

* The sys module has a new `thread_info` struct sequence holding informations
  about the thread implementation.

urllib module
=============

* The Request class, now accepts a method argument used by get_method() to
  determine what HTTP method should be used. For example, this will send a 'HEAD'
  request.

::

    >>> urlopen(Request('http://www.python.org', method='HEAD'))


There is more
=============

* http://docs.python.org/dev/whatsnew/3.3.html
* http://docs.python.org/dev/whatsnew/3.2.html
* http://docs.python.org/dev/whatsnew/2.7.html
* **Misc/NEWS** file.

::

        print('{0} {1}'.format('Thank',' you!'))

