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


Python 3.2
==========

* At the moment *

::
    python
    >>> import sys; sys.version


import argparse
===============

* There is an argparse command line parsing module included in stdlib.
* argparse will be the future and optparse will slowly be deprecated.
* Support for positional args, sub-commands, **'required options'**, pattern for specifying and validating options.
* argparse has the ability to define subparsers, each with their own argument patterns and help displays:


.. class:: handout


        import argparse

        parser = argparse.ArgumentParser(
                    description = 'Manage servers',         # main description for help
                    epilog = 'Tested on Solaris and Linux') # displayed after help
        parser.add_argument('action',                       # argument name
                    choices = ['deploy', 'start', 'stop'],  # three allowed values
                    help = 'action on each target')         # help msg
        parser.add_argument('targets',
                    metavar = 'HOSTNAME',                   # var name used in help msg
                    nargs = '+',                            # require one or more targets
                    help = 'url for target machines')       # help msg explanation
        parser.add_argument('-u', '--user',                 # -u or --user option
                    required = True,                        # make it a required argument
                    help = 'login as user')

        print(parser.parse_args('-h'.split()))

logging module - Configuration Dictionary.
==========================================

* The logging documentation has been augmented by a basic tutorial, an advanced tutorial, and a cookbook of logging recipes.
* **logging.config.dictConfig()** - logging configuration with plain Python dictionaries.

::

        with open('conf.json', 'r') as f:
                conf = json.load(f)
        logging.config.dictConfig(conf)


from concurrent import futures
==============================

* Code for creating and managing concurrency is being collected in a new top-level namespace, concurrent
* first package is **futures** high level interface for managing threads and processes.
* Inspired by java.utils.concurrent and Future Object.
* status checks (running or done), timeouts, cancellations, adding callbacks, and access to results or exceptions


.. class:: handout

        The primary offering of the new module is a pair of executor classes
        for launching and managing calls. The goal of the executors is to make
        it easier to use existing tools for making parallel calls. They save
        the effort needed to setup a pool of resources, launch the calls,
        create a results queue, add time-out handling, and limit the total
        number of threads, processes, or remote procedure calls.

        Ideally, each application should share a single executor across
        multiple components so that process and thread limits can be centrally
        managed. This solves the design challenge that arises when each
        component has its own competing strategy for resource management.

        Both classes share a common interface with three methods: submit() for
        scheduling a callable and returning a Future object; map() for
        scheduling many asynchronous calls at a time, and shutdown() for
        freeing resources. The class is a context manager and can be used in a
        with statement to assure that resources are automatically released when
        currently pending futures are done executing.


pyc directories
===============
* Multiple implementations can refer to their own .pyc files.
* mymodule.cpython-32.pyc, mymodule.cpython-33.pyc, and mymodule.unladen10.pyc
* pyc files are now collected in a **__pycache__** directory stored under the package directory
* Imported modules now have a __cached__ attribute which stores the name of the actual file that was imported
* tag that is unique to each interpreter is accessible from the **imp** module

WSGI 1.1
========

* Well Intentioned Upgrade for WSGI to support Python3.
* Informational PEP clarifies how bytes/text issues are to be handled by the WGSI protocol


New string formatting methods
=============================

* **str.format_map** 
* It can take dictionaries from defaultdict, shelve, ConfigParser, dbm.

::

        >>> import shelve
        >>> d = shelve.open('tmp.shl')
        >>> 'The {project_name} status is {status} as of {date}'.format_map(d)
        'The testing project status is green as of February 15, 2011'

        >>> class PlaceholderDict(dict):
                def __missing__(self, key):
                    return '<{}>'.format(key)
        >>> 'Hello {name}, welcome to {location}'.format_map(PlaceholderDict())
        'Hello <name>, welcome to <location>'


functools
=========

* The functools module includes a new decorator for caching function calls.
  **functools.lru_cache()** can save repeated queries to an external resource
  whenever the results are expected to be the same.

::

        >>> import functools
        >>> @functools.lru_cache(maxsize=300)
        >>> def get_phone_number(name):
                c = conn.cursor()
                c.execute('SELECT phonenumber FROM phonelist WHERE name=?', (name,))
                return c.fetchone()[0]
        ...
        >>> get_phone_number(name)        # cached lookup

functools
=========

* We have cache stats

::

        >>> get_phone_number.cache_info()
        CacheInfo(hits=4805, misses=980, maxsize=300, currsize=300)

* OMG! Way to get unwrapped function.

::

        >>> get_phone_number = get_phone_number.__wrapped__    # uncached function

functools
=========

* functools.total_ordering - rich comparison methods, a new decorator functools.total_ordering() will use a existing equality and inequality methods to fill in the remaining methods.

::

        @total_ordering
        class Student:
            def __eq__(self, other):
                return ((self.lastname.lower(), self.firstname.lower()) ==
                        (other.lastname.lower(), other.firstname.lower()))
            def __lt__(self, other):
                return ((self.lastname.lower(), self.firstname.lower()) <
                        (other.lastname.lower(), other.firstname.lower()))


* Magic happens.


itertools
=========

::

        >>> from itertools import accumulate
        >>> list(accumulate([8, 2, 50]))
        [8, 10, 60]


collections
===========

* The collections.Counter class now has two forms of in-place subtraction, the existing -= operator for saturating subtraction and the new subtract() method for regular subtraction

* http://en.wikipedia.org/wiki/Saturation_arithmetic


collections
===========

::

        >>> tally = Counter(dogs=5, cat=3)
        >>> tally -= Counter(dogs=2, cats=8)    # saturating subtraction
        >>> tally
        Counter({'dogs': 3})

        >>> tally = Counter(dogs=5, cats=3)
        >>> tally.subtract(dogs=2, cats=8)      # regular subtraction
        >>> tally
        Counter({'dogs': 3, 'cats': -5})


threading
=========

* The threading module has a new Barrier synchronization class for making
  multiple threads wait until all of them have reached a common barrier point. 

::

        from threading import Barrier, Thread

        def get_votes(site):
            ballots = conduct_election(site)
            all_polls_closed.wait()        # do not count until all polls are closed
            totals = summarize(ballots)
            publish(site, totals)

        all_polls_closed = Barrier(len(sites))
        for site in sites:
            Thread(target=get_votes, args=(site,)).start()


ast module
==========

* The ast.literal_eval() function serves as a secure alternative to the builtin eval() function which is easily abused.

::

        >>> from ast import literal_eval
        >>> request = "{'req': 3, 'func': 'pow', 'args': (2, 0.5)}"
        >>> literal_eval(request)
        {'args': (2, 0.5), 'req': 3, 'func': 'pow'}

        >>> request = "os.system('do something harmful')"
        >>> literal_eval(request)
        Traceback (most recent call last):
          ...
        ValueError: malformed node or string: <_ast.Call object at 0x101739a10>

unicode - os module
===================

* The os module provides two new functions, fsencode() and fsdecode(), for encoding and decoding filenames based on file-system encoding.


unittest
========

* improvements supporting test discovery for packages, easier experimentation at the interactive prompt

::
    python -m unittest discover -s my_proj_dir -p _test.py

* Interactivity!
    
::

    >>> TestCase().assertEqual(pow(2, 3), 8)


urllib
======

* The urlparse() function now supports IPv6 addresses as described in RFC 2732:
* urlopen can take POST which can be an iterable. 
* http.client.HTTPSConnection, urllib.request.HTTPSHandler and urllib.request.urlopen() now take optional arguments to allow for server certificate checking against a set of Certificate Authorities, as recommended in public uses of HTTPS.



There is more
=============

* http://docs.python.org/dev/whatsnew/3.3.html
* http://docs.python.org/dev/whatsnew/3.2.html
* http://docs.python.org/dev/whatsnew/2.7.html
* **Misc/NEWS** file.

::

        print('{0} {1}'.format('Thank',' you!'))

