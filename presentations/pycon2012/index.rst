.. -*- coding: utf-8 -*-
.. include:: <s5defs.txt>
.. |==>| unicode:: U+02794 .. thick rightwards arrow

================
Standard Library
================

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

CPython
=======

**At the moment**

::

    ./python -q
    >>> import sys; sys.version.split(" ")[0]
    '3.3.0a1+'
    ...
    '3.2.3rc1'
     ...
    ./python
    '3.2.3rc1'


faulthandler
============

* New **faulthandler** module.

This module contains functions to dump Python tracebacks explicitly, on a
fault, after a timeout, or on a user signal. Call faulthandler.enable() to
install fault handlers for the SIGSEGV, SIGFPE, SIGABRT, SIGBUS, and SIGILL
signals. 

* It is version 3.3 and was contributed by Victor Stinner.

.. class:: handout

    More information available at 

    http://blog.python.org/2011/05/new-faulthandler-module-in-python-33.html

lzma
====

* The newly-added lzma module provides data compression and decompression using
  the LZMA algorithm, including support for the .xz and .lzma file formats.
* lzma compression is usually better than bz2.
* Python 3.3
* Per Øyvind Karlsen, Nadeem Vawda and others.

.. class:: handout

    * http://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Markov_chain_algorithm
    * http://bugs.python.org/issue6715
    * http://docs.python.org/dev/library/lzma.html#examples

bz2 module
==========

* **bz2.BZ2File** can now read from and write to arbitrary file-like objects,
  by means of its constructor’s fileobj argument. (Nadeem Vawda)

* **bz2.BZ2File** and **bz2.decompress()** can now decompress multi-stream inputs.
  bz2.BZ2File can now also be used to create this type of file, using the 'a'
  (append) mode. (Nir Aides)


.. class:: handout

    * http://bugs.python.org/issue5863
    * http://bugs.python.org/issue1625


    Behavior is similar to bunzip2 utility. Like gzip, you can concatenate two
    bzip2 files.

    bzip2 -c /etc/passwd >/tmp/pass.bz2
    bzip2 -c /etc/passwd >>/tmp/pass.bz2

    bunzip2 will output both parts, generating two copies of the file.

    So nothing needs to be done on compression, but uncompression needs to
    look for another chunk of compressed data after finishing one chunk.


os module
=========

* sendfile() function which provides an efficent “zero-copy” way for copying
  data from one file (or socket) descriptor to another. ( Ross Lagerwall and
  Giampaolo Rodola')

* Use of sendfile instead of send provides 1.5x speed up!

* fwalk() function similar to walk() except that it also yields file
  descriptors referring to the directories visited. (Interesting!)


.. class:: handout

        Some benchmarks - 

        http://code.google.com/p/pyftpdlib/issues/detail?id=152#c5


packaging
=========

* distutils module is called packaging, helper functions for building,
  packaging, distributing and installing additional projects into a Python
  installation.

* distutils is still provided in the standard library, but users are encouraged
  to transition to packaging.

* New features from packaging will be available under distutils2 in PyPI.


.. class:: handout

    http://docs.python.org/dev/library/packaging.html#module-packaging


signal module
=============

* signal.signal() and signal.siginterrupt() raise an OSError, instead of a
  RuntimeError: OSError has an errno attribute.

* signal module has functions such as pthread_sigmask , pthread_kill,
  sigpending, sigwait, sigwaitinfo.

* Jean-Paul Calderone, Antoine Pitrou and others.

.. class:: handout

        http://docs.python.org/dev/library/signal.html
        man sigprocmask
        man pthread_sigmask
        man sigwait
        man sigwaitinfo


socket module
=============

* The socket class now supports the PF_CAN protocol family. (Matthias Fuchs,
  Tiago Gonçalves) - Control Area Network Bus Drivers.

* The socket class now supports the PF_RDS protocol family - Reliable High
  performance, low latency reliable connectioness protocol for delivering
  datagrams.

ssl module
==========

* RAND_bytes(): generate cryptographically strong pseudo-random bytes.
* RAND_pseudo_bytes(): generate pseudo-random bytes. (Both by Victor Stinner)
* Query the SSL compression algorithm used by an SSL socket, thanks to its new compression() method. You can also supress Compression. ( Antoine Pitrou)

.. class:: handout

    http://bugs.python.org/issue13634

sys module
==========

* The sys module has a new `thread_info` struct sequence holding informations
  about the thread implementation.

::

    >>> sys.thread_info
    sys.thread_info(name='pthread', lock='semaphore', version='NPTL 2.13')


urllib module
=============

* The Request class, now accepts a method argument used by get_method() to
  determine what HTTP method should be used. For example, this will send a 'HEAD'
  request.

::

    >>> urlopen(Request('http://www.python.org', method='HEAD'))

argparse
========

* Included in 3.2
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

* All these features were added by Raymond Hettinger

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


unittest
========

* improvements supporting test discovery for packages, easier experimentation at the interactive prompt

::
    python -m unittest discover -s my_proj_dir -p _test.py

* Interactivity!
    
::

    >>> TestCase().assertEqual(pow(2, 3), 8)

array module
============

* array module takes long long type.


shutil
======

* shutil.disk_usage() - total, used and free disk space statistics.

pyc directories
===============
* Multiple implementations can refer to their own .pyc files.
* mymodule.cpython-32.pyc, mymodule.cpython-33.pyc, and mymodule.unladen10.pyc
* pyc files are now collected in a **__pycache__** directory stored under the package directory
* Imported modules now have a __cached__ attribute which stores the name of the actual file that was imported
* tag that is unique to each interpreter is accessible from the **imp** module

WSGI 1.1.1
==========

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



urllib
======

* The urlparse() function now supports IPv6 addresses as described in RFC 2732:
* urlopen can take POST which can be an iterable. 
* http.client.HTTPSConnection, urllib.request.HTTPSHandler and urllib.request.urlopen() now take optional arguments to allow for server certificate checking against a set of Certificate Authorities, as recommended in public uses of HTTPS.

Deprecation Warnings
====================

* DeprecationWarning and its descendants are now ignored unless otherwise
  requested, preventing users from seeing warnings triggered by an application. 

* Previous Python 2.x releases had `DeprecationWarning` ON by default. Now,
  since the path to upgrade is 3.x, those have been silenced unless explictly
  requested.

* You can re-enable display of DeprecationWarning messages by running Python
  with the -Wdefault (short form: -Wd) switch, or by setting the PYTHONWARNINGS
  environment variable to "default" (or "d") before running Python.

3.x Backported Features
=======================

* The syntax for set literals ({1,2,3} is a mutable set).
* Dictionary and set comprehensions ({i: i*2 for i in range(3)}).
* Multiple context managers in a single with statement.
* A new version of the io library, rewritten in C for performance.
* The ordered-dictionary type described in PEP 372
* The new "," format specifier for Thousands Separator PEP 378
* The memoryview object.
* A small subset of the importlib module, described below.

Dictionary Views
================

* viewkeys(), viewvalues(), and viewitems() return an object called views.


Bug fixes in  modules
=====================

* http://docs.python.org/whatsnew/2.7.html#new-and-improved-modules
* 2.7.x is the maintained bug fix release. All bug reports which have been
  reported have found it's way to 2.7.x
* Only new features do not make it to 2.7.
* It's a stable release which can you to upgrade to Python 3.x

There is more
=============

* http://docs.python.org/dev/whatsnew/3.3.html
* http://docs.python.org/dev/whatsnew/3.2.html
* http://docs.python.org/dev/whatsnew/2.7.html
* **Misc/NEWS** file.

::

        print('{0} {1}'.format('Thank',' you!'))

