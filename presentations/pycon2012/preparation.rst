What's New In Python 3.3
========================

.. _pep-393:

PEP 393: Flexible String Representation
=======================================

The Unicode string type is changed to support multiple internal
representations, depending on the character with the largest Unicode ordinal
(1, 2, or 4 bytes) in the represented string.  This allows a space-efficient
representation in common cases, but gives access to full UCS-4 on all
systems.  For compatibility with existing APIs, several representations may
exist in parallel; over time, this compatibility should be phased out.

On the Python side, there should be no downside to this change.

On the C API side, PEP 393 is fully backward compatible.  The legacy API
should remain available at least five years.  Applications using the legacy
API will not fully benefit of the memory reduction, or - worse - may use
a bit more memory, because Python may have to maintain two versions of each
string (in the legacy format and in the new efficient storage).

Functionality
-------------

Changes introduced by :pep:`393` are the following:

* Python now always supports the full range of Unicode codepoints, including
  non-BMP ones (i.e. from ``U+0000`` to ``U+10FFFF``).  The distinction between
  narrow and wide builds no longer exists and Python now behaves like a wide
  build, even under Windows.

* With the death of narrow builds, the problems specific to narrow builds have
  also been fixed, for example:

  * :func:`len` now always returns 1 for non-BMP characters,
    so ``len('\U0010FFFF') == 1``;

  * surrogate pairs are not recombined in string literals,
    so ``'\uDBFF\uDFFF' != '\U0010FFFF'``;

  * indexing or slicing non-BMP characters returns the expected value,
    so ``'\U0010FFFF'[0]`` now returns ``'\U0010FFFF'`` and not ``'\uDBFF'``;

  * all other functions in the standard library now correctly handle
    non-BMP codepoints.

* The value of :data:`sys.maxunicode` is now always ``1114111`` (``0x10FFFF``
  in hexadecimal).  The :c:func:`PyUnicode_GetMax` function still returns
  either ``0xFFFF`` or ``0x10FFFF`` for backward compatibility, and it should
  not be used with the new Unicode API (see :issue:`13054`).

* The :file:`./configure` flag ``--with-wide-unicode`` has been removed.

Performance and resource usage
------------------------------

The storage of Unicode strings now depends on the highest codepoint in the string:

* pure ASCII and Latin1 strings (``U+0000-U+00FF``) use 1 byte per codepoint;

* BMP strings (``U+0000-U+FFFF``) use 2 bytes per codepoint;

* non-BMP strings (``U+10000-U+10FFFF``) use 4 bytes per codepoint.

The net effect is that for most applications, memory usage of string storage
should decrease significantly - especially compared to former wide unicode
builds - as, in many cases, strings will be pure ASCII even in international
contexts (because many strings store non-human language data, such as XML
fragments, HTTP headers, JSON-encoded data, etc.).  We also hope that it
will, for the same reasons, increase CPU cache efficiency on non-trivial
applications.

.. The memory usage of Python 3.3 is two to three times smaller than Python 3.2,
   and a little bit better than Python 2.7, on a `Django benchmark
   <http://mail.python.org/pipermail/python-dev/2011-September/113714.html>`_.
   XXX The result should be moved in the PEP and a link to the PEP should
   be added here.


PEP 3151: Reworking the OS and IO exception hierarchy
=====================================================

:pep:`3151` - Reworking the OS and IO exception hierarchy
 PEP written and implemented by Antoine Pitrou.

The hierarchy of exceptions raised by operating system errors is now both
simplified and finer-grained.

You don't have to worry anymore about choosing the appropriate exception
type between :exc:`OSError`, :exc:`IOError`, :exc:`EnvironmentError`,
:exc:`WindowsError`, :exc:`mmap.error`, :exc:`socket.error` or
:exc:`select.error`.  All these exception types are now only one:
:exc:`OSError`.  The other names are kept as aliases for compatibility
reasons.

Also, it is now easier to catch a specific error condition.  Instead of
inspecting the ``errno`` attribute (or ``args[0]``) for a particular
constant from the :mod:`errno` module, you can catch the adequate
:exc:`OSError` subclass.  The available subclasses are the following:

* :exc:`BlockingIOError`
* :exc:`ChildProcessError`
* :exc:`ConnectionError`
* :exc:`FileExistsError`
* :exc:`FileNotFoundError`
* :exc:`InterruptedError`
* :exc:`IsADirectoryError`
* :exc:`NotADirectoryError`
* :exc:`PermissionError`
* :exc:`ProcessLookupError`
* :exc:`TimeoutError`

And the :exc:`ConnectionError` itself has finer-grained subclasses:

* :exc:`BrokenPipeError`
* :exc:`ConnectionAbortedError`
* :exc:`ConnectionRefusedError`
* :exc:`ConnectionResetError`

Thanks to the new exceptions, common usages of the :mod:`errno` can now be
avoided.  For example, the following code written for Python 3.2::

    from errno import ENOENT, EACCES, EPERM

    try:
        with open("document.txt") as f:
            content = f.read()
    except IOError as err:
        if err.errno == ENOENT:
            print("document.txt file is missing")
        elif err.errno in (EACCES, EPERM):
            print("You are not allowed to read document.txt")
        else:
            raise

can now be written without the :mod:`errno` import and without manual
inspection of exception attributes::

    try:
        with open("document.txt") as f:
            content = f.read()
    except FileNotFoundError:
        print("document.txt file is missing")
    except PermissionError:
        print("You are not allowed to read document.txt")


PEP 380: Syntax for Delegating to a Subgenerator
================================================

PEP 380 adds the ``yield from`` expression, allowing a generator to delegate
part of its operations to another generator. This allows a section of code
containing 'yield' to be factored out and placed in another generator.
Additionally, the subgenerator is allowed to return with a value, and the
value is made available to the delegating generator.
While designed primarily for use in delegating to a subgenerator, the ``yield
from`` expression actually allows delegation to arbitrary subiterators.

(Implementation by Greg Ewing, integrated into 3.3 by Renaud Blanch, Ryan
Kelly and Nick Coghlan, documentation by Zbigniew Jędrzejewski-Szmek and
Nick Coghlan)


PEP 3155: Qualified name for classes and functions
==================================================

:pep:`3155` - Qualified name for classes and functions
 PEP written and implemented by Antoine Pitrou.

Functions and class objects have a new ``__qualname__`` attribute representing
the "path" from the module top-level to their definition.  For global functions
and classes, this is the same as ``__name__``.  For other functions and classes,
it provides better information about where they were actually defined, and
how they might be accessible from the global scope.

Example with (non-bound) methods::

   >>> class C:
   ...     def meth(self):
   ...         pass
   >>> C.meth.__name__
   'meth'
   >>> C.meth.__qualname__
   'C.meth'

Example with nested classes::

   >>> class C:
   ...     class D:
   ...         def meth(self):
   ...             pass
   ...
   >>> C.D.__name__
   'D'
   >>> C.D.__qualname__
   'C.D'
   >>> C.D.meth.__name__
   'meth'
   >>> C.D.meth.__qualname__
   'C.D.meth'

Example with nested functions::

   >>> def outer():
   ...     def inner():
   ...         pass
   ...     return inner
   ...
   >>> outer().__name__
   'inner'
   >>> outer().__qualname__
   'outer.<locals>.inner'

The string representation of those objects is also changed to include the
new, more precise information::

   >>> str(C.D)
   "<class '__main__.C.D'>"
   >>> str(C.D.meth)
   '<function C.D.meth at 0x7f46b9fe31e0>'


Other Language Changes
======================

Some smaller changes made to the core Python language are:

* Added support for Unicode name aliases and named sequences.
  Both :func:`unicodedata.lookup()` and ``'\N{...}'`` now resolve name aliases,
  and :func:`unicodedata.lookup()` resolves named sequences too.

  (Contributed by Ezio Melotti in :issue:`12753`)

* Equality comparisons on :func:`range` objects now return a result reflecting
  the equality of the underlying sequences generated by those range objects.

  (:issue:`13201`)

* The ``count()``, ``find()``, ``rfind()``, ``index()`` and ``rindex()``
  methods of :class:`bytes` and :class:`bytearray` objects now accept an
  integer between 0 and 255 as their first argument.

  (:issue:`12170`)

* Memoryview objects are now hashable when the underlying object is hashable.

  (Contributed by Antoine Pitrou in :issue:`13411`)


New and Improved Modules
========================

array
-----

The :mod:`array` module supports the :c:type:`long long` type using ``q`` and
``Q`` type codes.

(Contributed by Oren Tirosh and Hirokazu Yamamoto in :issue:`1172711`)


codecs
------

The :mod:`~encodings.mbcs` codec has be rewritten to handle correclty
``replace`` and ``ignore`` error handlers on all Windows versions. The
:mod:`~encodings.mbcs` codec is now supporting all error handlers, instead of
only ``replace`` to encode and ``ignore`` to decode.

A new Windows-only codec has been added: ``cp65001`` (:issue:`13216`). It is
the Windows code page 65001 (Windows UTF-8, ``CP_UTF8``). For example, it is
used by ``sys.stdout`` if the console output code page is set to cp65001 (e.g.
using ``chcp 65001`` command).

Multibyte CJK decoders now resynchronize faster. They only ignore the first
byte of an invalid byte sequence. For example, ``b'\xff\n'.decode('gb2312',
'replace')`` now returns a ``\n`` after the replacement character.

(:issue:`12016`)

Don't reset incremental encoders of CJK codecs at each call to their encode()
method anymore. For example::

    $ ./python -q
    >>> import codecs
    >>> encoder = codecs.getincrementalencoder('hz')('strict')
    >>> b''.join(encoder.encode(x) for x in '\u52ff\u65bd\u65bc\u4eba\u3002 Bye.')
    b'~{NpJ)l6HK!#~} Bye.'

This example gives ``b'~{Np~}~{J)~}~{l6~}~{HK~}~{!#~} Bye.'`` with older Python
versions.

(:issue:`12100`)

The ``unicode_internal`` codec has been deprecated.

crypt
-----

Addition of salt and modular crypt format and the :func:`~crypt.mksalt`
function to the :mod:`crypt` module.

(:issue:`10924`)

curses
------

 * If the :mod:`curses` module is linked to the ncursesw library, use Unicode
   functions when Unicode strings or characters are passed (e.g.
   :c:func:`waddwstr`), and bytes functions otherwise (e.g. :c:func:`waddstr`).
 * Use the locale encoding instead of ``utf-8`` to encode Unicode strings.
 * :class:`curses.window` has a new :attr:`curses.window.encoding` attribute.
 * The :class:`curses.window` class has a new :meth:`~curses.window.get_wch`
   method to get a wide character
 * The :mod:`curses` module has a new :meth:`~curses.unget_wch` function to
   push a wide character so the next :meth:`~curses.window.get_wch` will return
   it

(Contributed by Iñigo Serna in :issue:`6755`)

abc
---

Improved support for abstract base classes containing descriptors composed with
abstract methods. The recommended approach to declaring abstract descriptors is
now to provide :attr:`__isabstractmethod__` as a dynamically updated
property. The built-in descriptors have been updated accordingly.

  * :class:`abc.abstractproperty` has been deprecated, use :class:`property`
    with :func:`abc.abstractmethod` instead.
  * :class:`abc.abstractclassmethod` has been deprecated, use
    :class:`classmethod` with :func:`abc.abstractmethod` instead.
  * :class:`abc.abstractstaticmethod` has been deprecated, use
    :class:`staticmethod` with :func:`abc.abstractmethod` instead.

(Contributed by Darren Dale in :issue:`11610`)

faulthandler
------------

New module: :mod:`faulthandler`.

 * :envvar:`PYTHONFAULTHANDLER`
 * :option:`-X` ``faulthandler``

time
----

The :mod:`time` module has new functions:

* :func:`~time.clock_getres` and :func:`~time.clock_gettime` functions and
  ``CLOCK_xxx`` constants.  :func:`~time.clock_gettime` can be used with
  :data:`time.CLOCK_MONOTONIC` to get a monotonic clock.
* :func:`~time.wallclock`: monotonic clock.

(Contributed by Victor Stinner in :issue:`10278`)


ftplib
------

The :class:`~ftplib.FTP_TLS` class now provides a new
:func:`~ftplib.FTP_TLS.ccc` function to revert control channel back to
plaintext.  This can be useful to take advantage of firewalls that know how to
handle NAT with non-secure FTP without opening fixed ports.

(Contributed by Giampaolo Rodolà in :issue:`12139`)


imaplib
-------

The :class:`~imaplib.IMAP4_SSL` constructor now accepts an SSLContext
parameter to control parameters of the secure channel.

(Contributed by Sijin Joseph in :issue:`8808`)


io
--

The :func:`~io.open` function has a new ``'x'`` mode that can be used to
exclusively create a new file, and raise a :exc:`FileExistsError` if the file
already exists. It is based on the C11 'x' mode to fopen().

(Contributed by David Townshend in :issue:`12760`)


lzma
----

The newly-added :mod:`lzma` module provides data compression and decompression
using the LZMA algorithm, including support for the ``.xz`` and ``.lzma``
file formats.

(Contributed by Nadeem Vawda and Per Øyvind Karlsen in :issue:`6715`)


math
----

The :mod:`math` module has a new function:

  * :func:`~math.log2`: return the base-2 logarithm of *x*
    (Written by Mark Dickinson in :issue:`11888`).


nntplib
-------

The :class:`nntplib.NNTP` class now supports the context manager protocol to
unconditionally consume :exc:`socket.error` exceptions and to close the NNTP
connection when done::

  >>> from nntplib import NNTP
  >>> with NNTP('news.gmane.org') as n:
  ...     n.group('gmane.comp.python.committers')
  ...
  ('211 1755 1 1755 gmane.comp.python.committers', 1755, 1, 1755, 'gmane.comp.python.committers')
  >>>

(Contributed by Giampaolo Rodolà in :issue:`9795`)


os
--

* The :mod:`os` module has a new :func:`~os.pipe2` function that makes it
  possible to create a pipe with :data:`~os.O_CLOEXEC` or
  :data:`~os.O_NONBLOCK` flags set atomically. This is especially useful to
  avoid race conditions in multi-threaded programs.

* The :mod:`os` module has a new :func:`~os.sendfile` function which provides
  an efficent "zero-copy" way for copying data from one file (or socket)
  descriptor to another. The phrase "zero-copy" refers to the fact that all of
  the copying of data between the two descriptors is done entirely by the
  kernel, with no copying of data into userspace buffers. :func:`~os.sendfile`
  can be used to efficiently copy data from a file on disk to a network socket,
  e.g. for downloading a file.

  (Patch submitted by Ross Lagerwall and Giampaolo Rodolà in :issue:`10882`.)

* The :mod:`os` module has two new functions: :func:`~os.getpriority` and
  :func:`~os.setpriority`. They can be used to get or set process
  niceness/priority in a fashion similar to :func:`os.nice` but extended to all
  processes instead of just the current one.

  (Patch submitted by Giampaolo Rodolà in :issue:`10784`.)

* "at" functions (:issue:`4761`):

  * :func:`~os.faccessat`
  * :func:`~os.fchmodat`
  * :func:`~os.fchownat`
  * :func:`~os.fstatat`
  * :func:`~os.futimesat`
  * :func:`~os.futimesat`
  * :func:`~os.linkat`
  * :func:`~os.mkdirat`
  * :func:`~os.mkfifoat`
  * :func:`~os.mknodat`
  * :func:`~os.openat`
  * :func:`~os.readlinkat`
  * :func:`~os.renameat`
  * :func:`~os.symlinkat`
  * :func:`~os.unlinkat`
  * :func:`~os.utimensat`
  * :func:`~os.utimensat`

* extended attributes (:issue:`12720`):

  * :func:`~os.fgetxattr`
  * :func:`~os.flistxattr`
  * :func:`~os.fremovexattr`
  * :func:`~os.fsetxattr`
  * :func:`~os.getxattr`
  * :func:`~os.lgetxattr`
  * :func:`~os.listxattr`
  * :func:`~os.llistxattr`
  * :func:`~os.lremovexattr`
  * :func:`~os.lsetxattr`
  * :func:`~os.removexattr`
  * :func:`~os.setxattr`

* Scheduler functions (:issue:`12655`):

  * :func:`~os.sched_get_priority_max`
  * :func:`~os.sched_get_priority_min`
  * :func:`~os.sched_getaffinity`
  * :func:`~os.sched_getparam`
  * :func:`~os.sched_getscheduler`
  * :func:`~os.sched_rr_get_interval`
  * :func:`~os.sched_setaffinity`
  * :func:`~os.sched_setparam`
  * :func:`~os.sched_setscheduler`
  * :func:`~os.sched_yield`

* Add some extra posix functions to the os module (:issue:`10812`):

  * :func:`~os.fexecve`
  * :func:`~os.futimens`
  * :func:`~os.futimens`
  * :func:`~os.futimes`
  * :func:`~os.futimes`
  * :func:`~os.lockf`
  * :func:`~os.lutimes`
  * :func:`~os.lutimes`
  * :func:`~os.posix_fadvise`
  * :func:`~os.posix_fallocate`
  * :func:`~os.pread`
  * :func:`~os.pwrite`
  * :func:`~os.readv`
  * :func:`~os.sync`
  * :func:`~os.truncate`
  * :func:`~os.waitid`
  * :func:`~os.writev`

* Other new functions:

  * :func:`~os.fdlistdir` (:issue:`10755`)
  * :func:`~os.getgrouplist` (:issue:`9344`)


packaging
---------

:mod:`distutils` has undergone additions and refactoring under a new name,
:mod:`packaging`, to allow developers to break backward compatibility.
:mod:`distutils` is still provided in the standard library, but users are
encouraged to transition to :mod:`packaging`.  For older versions of Python, a
backport compatible with 2.4+ and 3.1+ will be made available on PyPI under the
name :mod:`distutils2`.

.. TODO add examples and howto to the packaging docs and link to them


pydoc
-----

The Tk GUI and the :func:`~pydoc.serve` function have been removed from the
:mod:`pydoc` module: ``pydoc -g`` and :func:`~pydoc.serve` have been deprecated
in Python 3.2.


sys
---

* The :mod:`sys` module has a new :data:`~sys.thread_info` :term:`struct
  sequence` holding informations about the thread implementation.

  (:issue:`11223`)


signal
------

* The :mod:`signal` module has new functions:

  * :func:`~signal.pthread_sigmask`: fetch and/or change the signal mask of the
    calling thread (Contributed by Jean-Paul Calderone in :issue:`8407`) ;
  * :func:`~signal.pthread_kill`: send a signal to a thread ;
  * :func:`~signal.sigpending`: examine pending functions ;
  * :func:`~signal.sigwait`: wait a signal.
  * :func:`~signal.sigwaitinfo`: wait for a signal, returning detailed
    information about it.
  * :func:`~signal.sigtimedwait`: like :func:`~signal.sigwaitinfo` but with a
    timeout.

* The signal handler writes the signal number as a single byte instead of
  a nul byte into the wakeup file descriptor. So it is possible to wait more
  than one signal and know which signals were raised.

* :func:`signal.signal` and :func:`signal.siginterrupt` raise an OSError,
  instead of a RuntimeError: OSError has an errno attribute.

socket
------

* The :class:`~socket.socket` class now exposes additional methods to process
  ancillary data when supported by the underlying platform:

  * :func:`~socket.socket.sendmsg`
  * :func:`~socket.socket.recvmsg`
  * :func:`~socket.socket.recvmsg_into`

  (Contributed by David Watson in :issue:`6560`, based on an earlier patch by
  Heiko Wundram)

* The :class:`~socket.socket` class now supports the PF_CAN protocol family
  (http://en.wikipedia.org/wiki/Socketcan), on Linux
  (http://lwn.net/Articles/253425).

  (Contributed by Matthias Fuchs, updated by Tiago Gonçalves in :issue:`10141`)

* The :class:`~socket.socket` class now supports the PF_RDS protocol family
  (http://en.wikipedia.org/wiki/Reliable_Datagram_Sockets and
  http://oss.oracle.com/projects/rds/).

ssl
---

* The :mod:`ssl` module has two new random generation functions:

  * :func:`~ssl.RAND_bytes`: generate cryptographically strong
    pseudo-random bytes.
  * :func:`~ssl.RAND_pseudo_bytes`: generate pseudo-random bytes.

  (Contributed by Victor Stinner in :issue:`12049`)

* The :mod:`ssl` module now exposes a finer-grained exception hierarchy
  in order to make it easier to inspect the various kinds of errors.

  (Contributed by Antoine Pitrou in :issue:`11183`)

* :meth:`~ssl.SSLContext.load_cert_chain` now accepts a *password* argument
  to be used if the private key is encrypted.

  (Contributed by Adam Simpkins in :issue:`12803`)

* Diffie-Hellman key exchange, both regular and Elliptic Curve-based, is
  now supported through the :meth:`~ssl.SSLContext.load_dh_params` and
  :meth:`~ssl.SSLContext.set_ecdh_curve` methods.

  (Contributed by Antoine Pitrou in :issue:`13626` and :issue:`13627`)

* SSL sockets have a new :meth:`~ssl.SSLSocket.get_channel_binding` method
  allowing the implementation of certain authentication mechanisms such as
  SCRAM-SHA-1-PLUS.

  (Contributed by Jacek Konieczny in :issue:`12551`)

* You can query the SSL compression algorithm used by an SSL socket, thanks
  to its new :meth:`~ssl.SSLSocket.compression` method.

  (Contributed by Antoine Pitrou in :issue:`13634`)


shutil
------

* The :mod:`shutil` module has these new fuctions:

  * :func:`~shutil.disk_usage`: provides total, used and free disk space
    statistics. (Contributed by Giampaolo Rodolà in :issue:`12442`)
  * :func:`~shutil.chown`: allows one to change user and/or group of the given
    path also specifying the user/group names and not only their numeric
    ids. (Contributed by Sandro Tosi in :issue:`12191`)

smtplib
-------

The :class:`~smtplib.SMTP_SSL` constructor and the :meth:`~smtplib.SMTP.starttls`
method now accept an SSLContext parameter to control parameters of the secure
channel.

(Contributed by Kasun Herath in :issue:`8809`)

urllib
------

The :class:`~urllib.request.Request` class, now accepts a *method* argument
used by :meth:`~urllib.request.Request.get_method` to determine what HTTP method
should be used.  For example, this will send a ``'HEAD'`` request::

   >>> urlopen(Request('http://www.python.org', method='HEAD'))

(:issue:`1673007`)

sched
-----

* :meth:`~sched.scheduler.run` now accepts a *blocking* parameter which when
  set to False makes the method execute the scheduled events due to expire
  soonest (if any) and then return immediately.
  This is useful in case you want to use the :class:`~sched.scheduler` in
  non-blocking applications.  (Contributed by Giampaolo Rodolà in :issue:`13449`)

* :class:`~sched.scheduler` class can now be safely used in multi-threaded
  environments.  (Contributed by Josiah Carlson and Giampaolo Rodolà in
  :issue:`8684`)

* *timefunc* and *delayfunct* parameters of :class:`~sched.scheduler` class
  constructor are now optional and defaults to :func:`time.time` and
  :func:`time.sleep` respectively.  (Contributed by Chris Clark in
  :issue:`13245`)

* :meth:`~sched.scheduler.enter` and :meth:`~sched.scheduler.enterabs`
  *argument* parameter is now optional.  (Contributed by Chris Clark in
  :issue:`13245`)

* :meth:`~sched.scheduler.enter` and :meth:`~sched.scheduler.enterabs`
  now accept a *kwargs* parameter.  (Contributed by Chris Clark in
  :issue:`13245`)

Optimizations
=============

Major performance enhancements have been added:

* Thanks to the :pep:`393`, some operations on Unicode strings has been optimized:

  * the memory footprint is divided by 2 to 4 depending on the text
  * encode an ASCII string to UTF-8 doesn't need to encode characters anymore,
    the UTF-8 representation is shared with the ASCII representation
  * the UTF-8 encoder has been optimized
  * repeating a single ASCII letter and getting a substring of a ASCII strings
    is 4 times faster


Build and C API Changes
=======================

Changes to Python's build process and to the C API include:

* The :pep:`393` added new Unicode types, macros and functions:

  * High-level API:

    * :c:func:`PyUnicode_CopyCharacters`
    * :c:func:`PyUnicode_FindChar`
    * :c:func:`PyUnicode_GetLength`, :c:macro:`PyUnicode_GET_LENGTH`
    * :c:func:`PyUnicode_New`
    * :c:func:`PyUnicode_Substring`
    * :c:func:`PyUnicode_ReadChar`, :c:func:`PyUnicode_WriteChar`

  * Low-level API:

    * :c:type:`Py_UCS1`, :c:type:`Py_UCS2`, :c:type:`Py_UCS4` types
    * :c:type:`PyASCIIObject` and :c:type:`PyCompactUnicodeObject` structures
    * :c:macro:`PyUnicode_READY`
    * :c:func:`PyUnicode_FromKindAndData`
    * :c:func:`PyUnicode_AsUCS4`, :c:func:`PyUnicode_AsUCS4Copy`
    * :c:macro:`PyUnicode_DATA`, :c:macro:`PyUnicode_1BYTE_DATA`,
      :c:macro:`PyUnicode_2BYTE_DATA`, :c:macro:`PyUnicode_4BYTE_DATA`
    * :c:macro:`PyUnicode_KIND` with :c:type:`PyUnicode_Kind` enum:
      :c:data:`PyUnicode_WCHAR_KIND`, :c:data:`PyUnicode_1BYTE_KIND`,
      :c:data:`PyUnicode_2BYTE_KIND`, :c:data:`PyUnicode_4BYTE_KIND`
    * :c:macro:`PyUnicode_READ`, :c:macro:`PyUnicode_READ_CHAR`, :c:macro:`PyUnicode_WRITE`
    * :c:macro:`PyUnicode_MAX_CHAR_VALUE`



Deprecated
==========

Unsupported Operating Systems
-----------------------------

OS/2 and VMS are no longer supported due to the lack of a maintainer.

Windows 2000 and Windows platforms which set ``COMSPEC`` to ``command.com``
are no longer supported due to maintenance burden.


Deprecated Python modules, functions and methods
------------------------------------------------

* The :mod:`packaging` module replaces the :mod:`distutils` module
* The ``unicode_internal`` codec has been deprecated because of the
  :pep:`393`, use UTF-8, UTF-16 (``utf-16-le`` or ``utf-16-be``), or UTF-32
  (``utf-32-le`` or ``utf-32-be``)
* :meth:`ftplib.FTP.nlst` and :meth:`ftplib.FTP.dir`: use
  :meth:`ftplib.FTP.mlsd`
* :func:`platform.popen`: use the :mod:`subprocess` module. Check especially
  the :ref:`subprocess-replacements` section.
* :issue:`13374`: The Windows bytes API has been deprecated in the :mod:`os`
  module. Use Unicode filenames, instead of bytes filenames, to not depend on
  the ANSI code page anymore and to support any filename.


Deprecated functions and types of the C API
-------------------------------------------

The :c:type:`Py_UNICODE` has been deprecated by the :pep:`393` and will be
removed in Python 4. All functions using this type are deprecated:

Unicode functions and methods using :c:type:`Py_UNICODE` and
:c:type:`Py_UNICODE*` types:

 * :c:macro:`PyUnicode_FromUnicode`: use :c:func:`PyUnicode_FromWideChar` or
   :c:func:`PyUnicode_FromKindAndData`
 * :c:macro:`PyUnicode_AS_UNICODE`, :c:func:`PyUnicode_AsUnicode`,
   :c:func:`PyUnicode_AsUnicodeAndSize`: use :c:func:`PyUnicode_AsWideCharString`
 * :c:macro:`PyUnicode_AS_DATA`: use :c:macro:`PyUnicode_DATA` with
   :c:macro:`PyUnicode_READ` and :c:macro:`PyUnicode_WRITE`
 * :c:macro:`PyUnicode_GET_SIZE`, :c:func:`PyUnicode_GetSize`: use
   :c:macro:`PyUnicode_GET_LENGTH` or :c:func:`PyUnicode_GetLength`
 * :c:macro:`PyUnicode_GET_DATA_SIZE`: use
   ``PyUnicode_GET_LENGTH(str) * PyUnicode_KIND(str)`` (only work on ready
   strings)
 * :c:func:`PyUnicode_AsUnicodeCopy`: use :c:func:`PyUnicode_AsUCS4Copy` or
   :c:func:`PyUnicode_AsWideCharString`
 * :c:func:`PyUnicode_GetMax`


Functions and macros manipulating Py_UNICODE* strings:

 * :c:macro:`Py_UNICODE_strlen`: use :c:func:`PyUnicode_GetLength` or
   :c:macro:`PyUnicode_GET_LENGTH`
 * :c:macro:`Py_UNICODE_strcat`: use :c:func:`PyUnicode_CopyCharacters` or
   :c:func:`PyUnicode_FromFormat`
 * :c:macro:`Py_UNICODE_strcpy`, :c:macro:`Py_UNICODE_strncpy`,
   :c:macro:`Py_UNICODE_COPY`: use :c:func:`PyUnicode_CopyCharacters` or
   :c:func:`PyUnicode_Substring`
 * :c:macro:`Py_UNICODE_strcmp`: use :c:func:`PyUnicode_Compare`
 * :c:macro:`Py_UNICODE_strncmp`: use :c:func:`PyUnicode_Tailmatch`
 * :c:macro:`Py_UNICODE_strchr`, :c:macro:`Py_UNICODE_strrchr`: use
   :c:func:`PyUnicode_FindChar`
 * :c:macro:`Py_UNICODE_FILL`: use :c:func:`PyUnicode_Fill`
 * :c:macro:`Py_UNICODE_MATCH`

Encoders:

 * :c:func:`PyUnicode_Encode`: use :c:func:`PyUnicode_AsEncodedObject`
 * :c:func:`PyUnicode_EncodeUTF7`
 * :c:func:`PyUnicode_EncodeUTF8`: use :c:func:`PyUnicode_AsUTF8` or
   :c:func:`PyUnicode_AsUTF8String`
 * :c:func:`PyUnicode_EncodeUTF32`
 * :c:func:`PyUnicode_EncodeUTF16`
 * :c:func:`PyUnicode_EncodeUnicodeEscape:` use
   :c:func:`PyUnicode_AsUnicodeEscapeString`
 * :c:func:`PyUnicode_EncodeRawUnicodeEscape:` use
   :c:func:`PyUnicode_AsRawUnicodeEscapeString`
 * :c:func:`PyUnicode_EncodeLatin1`: use :c:func:`PyUnicode_AsLatin1String`
 * :c:func:`PyUnicode_EncodeASCII`: use :c:func:`PyUnicode_AsASCIIString`
 * :c:func:`PyUnicode_EncodeCharmap`
 * :c:func:`PyUnicode_TranslateCharmap`
 * :c:func:`PyUnicode_EncodeMBCS`: use :c:func:`PyUnicode_AsMBCSString` or
   :c:func:`PyUnicode_EncodeCodePage` (with ``CP_ACP`` code_page)
 * :c:func:`PyUnicode_EncodeDecimal`,
   :c:func:`PyUnicode_TransformDecimalToASCII`


Porting to Python 3.3
=====================

This section lists previously described changes and other bugfixes
that may require changes to your code.

Porting Python code
-------------------

* :issue:`12326`: On Linux, sys.platform doesn't contain the major version
  anymore. It is now always 'linux', instead of 'linux2' or 'linux3' depending
  on the Linux version used to build Python. Replace sys.platform == 'linux2'
  with sys.platform.startswith('linux'), or directly sys.platform == 'linux' if
  you don't need to support older Python versions.

Porting C code
--------------

* Due to :ref:`PEP 393 <pep-393>`, the :c:type:`Py_UNICODE` type and all
  functions using this type are deprecated (but will stay available for
  at least five years).  If you were using low-level Unicode APIs to
  construct and access unicode objects and you want to benefit of the
  memory footprint reduction provided by the PEP 393, you have to convert
  your code to the new :doc:`Unicode API <../c-api/unicode>`.

  However, if you only have been using high-level functions such as
  :c:func:`PyUnicode_Concat()`, :c:func:`PyUnicode_Join` or
  :c:func:`PyUnicode_FromFormat()`, your code will automatically take
  advantage of the new unicode representations.

Other issues
------------

.. Issue #11591: When :program:`python` was started with :option:`-S`,
   ``import site`` will not add site-specific paths to the module search
   paths.  In previous versions, it did.  See changeset for doc changes in
   various files.  Contributed by Carl Meyer with editions by Éric Araujo.

.. Issue #10998: the -Q command-line flag and related artifacts have been
   removed.  Code checking sys.flags.division_warning will need updating.
   Contributed by Éric Araujo.


****************************
  What's New In Python 3.2
****************************


.. seealso::

   :pep:`392` - Python 3.2 Release Schedule


PEP 384: Defining a Stable ABI
==============================

In the past, extension modules built for one Python version were often
not usable with other Python versions. Particularly on Windows, every
feature release of Python required rebuilding all extension modules that
one wanted to use. This requirement was the result of the free access to
Python interpreter internals that extension modules could use.

With Python 3.2, an alternative approach becomes available: extension
modules which restrict themselves to a limited API (by defining
Py_LIMITED_API) cannot use many of the internals, but are constrained
to a set of API functions that are promised to be stable for several
releases. As a consequence, extension modules built for 3.2 in that
mode will also work with 3.3, 3.4, and so on. Extension modules that
make use of details of memory structures can still be built, but will
need to be recompiled for every feature release.

.. seealso::

   :pep:`384` - Defining a Stable ABI
      PEP written by Martin von Löwis.


PEP 389: Argparse Command Line Parsing Module
=============================================

A new module for command line parsing, :mod:`argparse`, was introduced to
overcome the limitations of :mod:`optparse` which did not provide support for
positional arguments (not just options), subcommands, required options and other
common patterns of specifying and validating options.

This module has already had widespread success in the community as a
third-party module.  Being more fully featured than its predecessor, the
:mod:`argparse` module is now the preferred module for command-line processing.
The older module is still being kept available because of the substantial amount
of legacy code that depends on it.

Here's an annotated example parser showing features like limiting results to a
set of choices, specifying a *metavar* in the help screen, validating that one
or more positional arguments is present, and making a required option::

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

Example of calling the parser on a command string::

    >>> cmd  = 'deploy sneezy.example.com sleepy.example.com -u skycaptain'
    >>> result = parser.parse_args(cmd.split())
    >>> result.action
    'deploy'
    >>> result.targets
    ['sneezy.example.com', 'sleepy.example.com']
    >>> result.user
    'skycaptain'

Example of the parser's automatically generated help::

    >>> parser.parse_args('-h'.split())

    usage: manage_cloud.py [-h] -u USER
                           {deploy,start,stop} HOSTNAME [HOSTNAME ...]

    Manage servers

    positional arguments:
      {deploy,start,stop}   action on each target
      HOSTNAME              url for target machines

    optional arguments:
      -h, --help            show this help message and exit
      -u USER, --user USER  login as user

    Tested on Solaris and Linux

An especially nice :mod:`argparse` feature is the ability to define subparsers,
each with their own argument patterns and help displays::

    import argparse
    parser = argparse.ArgumentParser(prog='HELM')
    subparsers = parser.add_subparsers()

    parser_l = subparsers.add_parser('launch', help='Launch Control')   # first subgroup
    parser_l.add_argument('-m', '--missiles', action='store_true')
    parser_l.add_argument('-t', '--torpedos', action='store_true')

    parser_m = subparsers.add_parser('move', help='Move Vessel',        # second subgroup
                                     aliases=('steer', 'turn'))         # equivalent names
    parser_m.add_argument('-c', '--course', type=int, required=True)
    parser_m.add_argument('-s', '--speed', type=int, default=0)

    $ ./helm.py --help                         # top level help (launch and move)
    $ ./helm.py launch --help                  # help for launch options
    $ ./helm.py launch --missiles              # set missiles=True and torpedos=False
    $ ./helm.py steer --course 180 --speed 5   # set movement parameters

.. seealso::

   :pep:`389` - New Command Line Parsing Module
      PEP written by Steven Bethard.

   :ref:`upgrading-optparse-code` for details on the differences from :mod:`optparse`.


PEP 391:  Dictionary Based Configuration for Logging
====================================================

The :mod:`logging` module provided two kinds of configuration, one style with
function calls for each option or another style driven by an external file saved
in a :mod:`ConfigParser` format.  Those options did not provide the flexibility
to create configurations from JSON or YAML files, nor did they support
incremental configuration, which is needed for specifying logger options from a
command line.

To support a more flexible style, the module now offers
:func:`logging.config.dictConfig` for specifying logging configuration with
plain Python dictionaries.  The configuration options include formatters,
handlers, filters, and loggers.  Here's a working example of a configuration
dictionary::

   {"version": 1,
    "formatters": {"brief": {"format": "%(levelname)-8s: %(name)-15s: %(message)s"},
                   "full": {"format": "%(asctime)s %(name)-15s %(levelname)-8s %(message)s"}
                   },
    "handlers": {"console": {
                      "class": "logging.StreamHandler",
                      "formatter": "brief",
                      "level": "INFO",
                      "stream": "ext://sys.stdout"},
                 "console_priority": {
                      "class": "logging.StreamHandler",
                      "formatter": "full",
                      "level": "ERROR",
                      "stream": "ext://sys.stderr"}
                 },
    "root": {"level": "DEBUG", "handlers": ["console", "console_priority"]}}


If that dictionary is stored in a file called :file:`conf.json`, it can be
loaded and called with code like this::

   >>> import json, logging.config
   >>> with open('conf.json') as f:
           conf = json.load(f)
   >>> logging.config.dictConfig(conf)
   >>> logging.info("Transaction completed normally")
   INFO    : root           : Transaction completed normally
   >>> logging.critical("Abnormal termination")
   2011-02-17 11:14:36,694 root            CRITICAL Abnormal termination

.. seealso::

   :pep:`391` - Dictionary Based Configuration for Logging
      PEP written by Vinay Sajip.


PEP 3148:  The ``concurrent.futures`` module
============================================

Code for creating and managing concurrency is being collected in a new top-level
namespace, *concurrent*.  Its first member is a *futures* package which provides
a uniform high-level interface for managing threads and processes.

The design for :mod:`concurrent.futures` was inspired by the
*java.util.concurrent* package.  In that model, a running call and its result
are represented by a :class:`~concurrent.futures.Future` object that abstracts
features common to threads, processes, and remote procedure calls.  That object
supports status checks (running or done), timeouts, cancellations, adding
callbacks, and access to results or exceptions.

The primary offering of the new module is a pair of executor classes for
launching and managing calls.  The goal of the executors is to make it easier to
use existing tools for making parallel calls. They save the effort needed to
setup a pool of resources, launch the calls, create a results queue, add
time-out handling, and limit the total number of threads, processes, or remote
procedure calls.

Ideally, each application should share a single executor across multiple
components so that process and thread limits can be centrally managed.  This
solves the design challenge that arises when each component has its own
competing strategy for resource management.

Both classes share a common interface with three methods:
:meth:`~concurrent.futures.Executor.submit` for scheduling a callable and
returning a :class:`~concurrent.futures.Future` object;
:meth:`~concurrent.futures.Executor.map` for scheduling many asynchronous calls
at a time, and :meth:`~concurrent.futures.Executor.shutdown` for freeing
resources.  The class is a :term:`context manager` and can be used in a
:keyword:`with` statement to assure that resources are automatically released
when currently pending futures are done executing.

A simple of example of :class:`~concurrent.futures.ThreadPoolExecutor` is a
launch of four parallel threads for copying files::

  import concurrent.futures, shutil
  with concurrent.futures.ThreadPoolExecutor(max_workers=4) as e:
      e.submit(shutil.copy, 'src1.txt', 'dest1.txt')
      e.submit(shutil.copy, 'src2.txt', 'dest2.txt')
      e.submit(shutil.copy, 'src3.txt', 'dest3.txt')
      e.submit(shutil.copy, 'src3.txt', 'dest4.txt')

.. seealso::

   :pep:`3148` - Futures -- Execute Computations Asynchronously
      PEP written by Brian Quinlan.

   :ref:`Code for Threaded Parallel URL reads<threadpoolexecutor-example>`, an
   example using threads to fetch multiple web pages in parallel.

   :ref:`Code for computing prime numbers in
   parallel<processpoolexecutor-example>`, an example demonstrating
   :class:`~concurrent.futures.ProcessPoolExecutor`.


PEP 3147:  PYC Repository Directories
=====================================

Python's scheme for caching bytecode in *.pyc* files did not work well in
environments with multiple Python interpreters.  If one interpreter encountered
a cached file created by another interpreter, it would recompile the source and
overwrite the cached file, thus losing the benefits of caching.

The issue of "pyc fights" has become more pronounced as it has become
commonplace for Linux distributions to ship with multiple versions of Python.
These conflicts also arise with CPython alternatives such as Unladen Swallow.

To solve this problem, Python's import machinery has been extended to use
distinct filenames for each interpreter.  Instead of Python 3.2 and Python 3.3 and
Unladen Swallow each competing for a file called "mymodule.pyc", they will now
look for "mymodule.cpython-32.pyc", "mymodule.cpython-33.pyc", and
"mymodule.unladen10.pyc".  And to prevent all of these new files from
cluttering source directories, the *pyc* files are now collected in a
"__pycache__" directory stored under the package directory.

Aside from the filenames and target directories, the new scheme has a few
aspects that are visible to the programmer:

* Imported modules now have a :attr:`__cached__` attribute which stores the name
  of the actual file that was imported:

   >>> import collections
   >>> collections.__cached__
   'c:/py32/lib/__pycache__/collections.cpython-32.pyc'

* The tag that is unique to each interpreter is accessible from the :mod:`imp`
  module:

   >>> import imp
   >>> imp.get_tag()
   'cpython-32'

* Scripts that try to deduce source filename from the imported file now need to
  be smarter.  It is no longer sufficient to simply strip the "c" from a ".pyc"
  filename.  Instead, use the new functions in the :mod:`imp` module:

  >>> imp.source_from_cache('c:/py32/lib/__pycache__/collections.cpython-32.pyc')
  'c:/py32/lib/collections.py'
  >>> imp.cache_from_source('c:/py32/lib/collections.py')
  'c:/py32/lib/__pycache__/collections.cpython-32.pyc'

* The :mod:`py_compile` and :mod:`compileall` modules have been updated to
  reflect the new naming convention and target directory.  The command-line
  invocation of *compileall* has new options: ``-i`` for
  specifying a list of files and directories to compile and ``-b`` which causes
  bytecode files to be written to their legacy location rather than
  *__pycache__*.

* The :mod:`importlib.abc` module has been updated with new :term:`abstract base
  classes <abstract base class>` for loading bytecode files.  The obsolete
  ABCs, :class:`~importlib.abc.PyLoader` and
  :class:`~importlib.abc.PyPycLoader`, have been deprecated (instructions on how
  to stay Python 3.1 compatible are included with the documentation).

.. seealso::

   :pep:`3147` - PYC Repository Directories
      PEP written by Barry Warsaw.


PEP 3149: ABI Version Tagged .so Files
======================================

The PYC repository directory allows multiple bytecode cache files to be
co-located.  This PEP implements a similar mechanism for shared object files by
giving them a common directory and distinct names for each version.

The common directory is "pyshared" and the file names are made distinct by
identifying the Python implementation (such as CPython, PyPy, Jython, etc.), the
major and minor version numbers, and optional build flags (such as "d" for
debug, "m" for pymalloc, "u" for wide-unicode).  For an arbitrary package "foo",
you may see these files when the distribution package is installed::

   /usr/share/pyshared/foo.cpython-32m.so
   /usr/share/pyshared/foo.cpython-33md.so

In Python itself, the tags are accessible from functions in the :mod:`sysconfig`
module::

   >>> import sysconfig
   >>> sysconfig.get_config_var('SOABI')    # find the version tag
   'cpython-32mu'
   >>> sysconfig.get_config_var('SO')       # find the full filename extension
   '.cpython-32mu.so'

.. seealso::

   :pep:`3149` - ABI Version Tagged .so Files
      PEP written by Barry Warsaw.


PEP 3333: Python Web Server Gateway Interface v1.0.1
=====================================================

This informational PEP clarifies how bytes/text issues are to be handled by the
WSGI protocol.  The challenge is that string handling in Python 3 is most
conveniently handled with the :class:`str` type even though the HTTP protocol
is itself bytes oriented.

The PEP differentiates so-called *native strings* that are used for
request/response headers and metadata versus *byte strings* which are used for
the bodies of requests and responses.

The *native strings* are always of type :class:`str` but are restricted to code
points between *U+0000* through *U+00FF* which are translatable to bytes using
*Latin-1* encoding.  These strings are used for the keys and values in the
environment dictionary and for response headers and statuses in the
:func:`start_response` function.  They must follow :rfc:`2616` with respect to
encoding. That is, they must either be *ISO-8859-1* characters or use
:rfc:`2047` MIME encoding.

For developers porting WSGI applications from Python 2, here are the salient
points:

* If the app already used strings for headers in Python 2, no change is needed.

* If instead, the app encoded output headers or decoded input headers, then the
  headers will need to be re-encoded to Latin-1.  For example, an output header
  encoded in utf-8 was using ``h.encode('utf-8')`` now needs to convert from
  bytes to native strings using ``h.encode('utf-8').decode('latin-1')``.

* Values yielded by an application or sent using the :meth:`write` method
  must be byte strings.  The :func:`start_response` function and environ
  must use native strings.  The two cannot be mixed.

For server implementers writing CGI-to-WSGI pathways or other CGI-style
protocols, the users must to be able access the environment using native strings
even though the underlying platform may have a different convention.  To bridge
this gap, the :mod:`wsgiref` module has a new function,
:func:`wsgiref.handlers.read_environ` for transcoding CGI variables from
:attr:`os.environ` into native strings and returning a new dictionary.

.. seealso::

   :pep:`3333` - Python Web Server Gateway Interface v1.0.1
      PEP written by Phillip Eby.


Other Language Changes
======================

Some smaller changes made to the core Python language are:

* String formatting for :func:`format` and :meth:`str.format` gained new
  capabilities for the format character **#**.  Previously, for integers in
  binary, octal, or hexadecimal, it caused the output to be prefixed with '0b',
  '0o', or '0x' respectively.  Now it can also handle floats, complex, and
  Decimal, causing the output to always have a decimal point even when no digits
  follow it.

  >>> format(20, '#o')
  '0o24'
  >>> format(12.34, '#5.0f')
  '  12.'

  (Suggested by Mark Dickinson and implemented by Eric Smith in :issue:`7094`.)

* There is also a new :meth:`str.format_map` method that extends the
  capabilities of the existing :meth:`str.format` method by accepting arbitrary
  :term:`mapping` objects.  This new method makes it possible to use string
  formatting with any of Python's many dictionary-like objects such as
  :class:`~collections.defaultdict`, :class:`~shelve.Shelf`,
  :class:`~configparser.ConfigParser`, or :mod:`dbm`.  It is also useful with
  custom :class:`dict` subclasses that normalize keys before look-up or that
  supply a :meth:`__missing__` method for unknown keys::

    >>> import shelve
    >>> d = shelve.open('tmp.shl')
    >>> 'The {project_name} status is {status} as of {date}'.format_map(d)
    'The testing project status is green as of February 15, 2011'

    >>> class LowerCasedDict(dict):
            def __getitem__(self, key):
                return dict.__getitem__(self, key.lower())
    >>> lcd = LowerCasedDict(part='widgets', quantity=10)
    >>> 'There are {QUANTITY} {Part} in stock'.format_map(lcd)
    'There are 10 widgets in stock'

    >>> class PlaceholderDict(dict):
            def __missing__(self, key):
                return '<{}>'.format(key)
    >>> 'Hello {name}, welcome to {location}'.format_map(PlaceholderDict())
    'Hello <name>, welcome to <location>'

 (Suggested by Raymond Hettinger and implemented by Eric Smith in
 :issue:`6081`.)

* The interpreter can now be started with a quiet option, ``-q``, to prevent
  the copyright and version information from being displayed in the interactive
  mode.  The option can be introspected using the :attr:`sys.flags` attribute::

    $ python -q
    >>> sys.flags
    sys.flags(debug=0, division_warning=0, inspect=0, interactive=0,
    optimize=0, dont_write_bytecode=0, no_user_site=0, no_site=0,
    ignore_environment=0, verbose=0, bytes_warning=0, quiet=1)

  (Contributed by Marcin Wojdyr in :issue:`1772833`).

* The :func:`hasattr` function works by calling :func:`getattr` and detecting
  whether an exception is raised.  This technique allows it to detect methods
  created dynamically by :meth:`__getattr__` or :meth:`__getattribute__` which
  would otherwise be absent from the class dictionary.  Formerly, *hasattr*
  would catch any exception, possibly masking genuine errors.  Now, *hasattr*
  has been tightened to only catch :exc:`AttributeError` and let other
  exceptions pass through::

    >>> class A:
            @property
            def f(self):
                return 1 // 0

    >>> a = A()
    >>> hasattr(a, 'f')
    Traceback (most recent call last):
      ...
    ZeroDivisionError: integer division or modulo by zero

  (Discovered by Yury Selivanov and fixed by Benjamin Peterson; :issue:`9666`.)

* The :func:`str` of a float or complex number is now the same as its
  :func:`repr`. Previously, the :func:`str` form was shorter but that just
  caused confusion and is no longer needed now that the shortest possible
  :func:`repr` is displayed by default:

   >>> import math
   >>> repr(math.pi)
   '3.141592653589793'
   >>> str(math.pi)
   '3.141592653589793'

  (Proposed and implemented by Mark Dickinson; :issue:`9337`.)

* :class:`memoryview` objects now have a :meth:`~memoryview.release()` method
  and they also now support the context manager protocol.  This allows timely
  release of any resources that were acquired when requesting a buffer from the
  original object.

  >>> with memoryview(b'abcdefgh') as v:
          print(v.tolist())
  [97, 98, 99, 100, 101, 102, 103, 104]

  (Added by Antoine Pitrou; :issue:`9757`.)

* Previously it was illegal to delete a name from the local namespace if it
  occurs as a free variable in a nested block::

       def outer(x):
           def inner():
              return x
           inner()
           del x

  This is now allowed.  Remember that the target of an :keyword:`except` clause
  is cleared, so this code which used to work with Python 2.6, raised a
  :exc:`SyntaxError` with Python 3.1 and now works again::

       def f():
           def print_error():
              print(e)
           try:
              something
           except Exception as e:
              print_error()
              # implicit "del e" here

  (See :issue:`4617`.)

* The internal :c:type:`structsequence` tool now creates subclasses of tuple.
  This means that C structures like those returned by :func:`os.stat`,
  :func:`time.gmtime`, and :attr:`sys.version_info` now work like a
  :term:`named tuple` and now work with functions and methods that
  expect a tuple as an argument.  This is a big step forward in making the C
  structures as flexible as their pure Python counterparts:

  >>> isinstance(sys.version_info, tuple)
  True
  >>> 'Version %d.%d.%d %s(%d)' % sys.version_info
  'Version 3.2.0 final(0)'

  (Suggested by Arfrever Frehtes Taifersar Arahesis and implemented
  by Benjamin Peterson in :issue:`8413`.)

* Warnings are now easier to control using the :envvar:`PYTHONWARNINGS`
  environment variable as an alternative to using ``-W`` at the command line::

    $ export PYTHONWARNINGS='ignore::RuntimeWarning::,once::UnicodeWarning::'

  (Suggested by Barry Warsaw and implemented by Philip Jenvey in :issue:`7301`.)

* A new warning category, :exc:`ResourceWarning`, has been added.  It is
  emitted when potential issues with resource consumption or cleanup
  are detected.  It is silenced by default in normal release builds but
  can be enabled through the means provided by the :mod:`warnings`
  module, or on the command line.

  A :exc:`ResourceWarning` is issued at interpreter shutdown if the
  :data:`gc.garbage` list isn't empty, and if :attr:`gc.DEBUG_UNCOLLECTABLE` is
  set, all uncollectable objects are printed.  This is meant to make the
  programmer aware that their code contains object finalization issues.

  A :exc:`ResourceWarning` is also issued when a :term:`file object` is destroyed
  without having been explicitly closed.  While the deallocator for such
  object ensures it closes the underlying operating system resource
  (usually, a file descriptor), the delay in deallocating the object could
  produce various issues, especially under Windows.  Here is an example
  of enabling the warning from the command line::

      $ python -q -Wdefault
      >>> f = open("foo", "wb")
      >>> del f
      __main__:1: ResourceWarning: unclosed file <_io.BufferedWriter name='foo'>

  (Added by Antoine Pitrou and Georg Brandl in :issue:`10093` and :issue:`477863`.)

* :class:`range` objects now support *index* and *count* methods. This is part
  of an effort to make more objects fully implement the
  :class:`collections.Sequence` :term:`abstract base class`.  As a result, the
  language will have a more uniform API.  In addition, :class:`range` objects
  now support slicing and negative indices, even with values larger than
  :attr:`sys.maxsize`.  This makes *range* more interoperable with lists::

      >>> range(0, 100, 2).count(10)
      1
      >>> range(0, 100, 2).index(10)
      5
      >>> range(0, 100, 2)[5]
      10
      >>> range(0, 100, 2)[0:5]
      range(0, 10, 2)

  (Contributed by Daniel Stutzbach in :issue:`9213`, by Alexander Belopolsky
  in :issue:`2690`, and by Nick Coghlan in :issue:`10889`.)

* The :func:`callable` builtin function from Py2.x was resurrected.  It provides
  a concise, readable alternative to using an :term:`abstract base class` in an
  expression like ``isinstance(x, collections.Callable)``:

  >>> callable(max)
  True
  >>> callable(20)
  False

  (See :issue:`10518`.)

* Python's import mechanism can now load modules installed in directories with
  non-ASCII characters in the path name.  This solved an aggravating problem
  with home directories for users with non-ASCII characters in their usernames.

 (Required extensive work by Victor Stinner in :issue:`9425`.)


New, Improved, and Deprecated Modules
=====================================

Python's standard library has undergone significant maintenance efforts and
quality improvements.

The biggest news for Python 3.2 is that the :mod:`email` package, :mod:`mailbox`
module, and :mod:`nntplib` modules now work correctly with the bytes/text model
in Python 3.  For the first time, there is correct handling of messages with
mixed encodings.

Throughout the standard library, there has been more careful attention to
encodings and text versus bytes issues.  In particular, interactions with the
operating system are now better able to exchange non-ASCII data using the
Windows MBCS encoding, locale-aware encodings, or UTF-8.

Another significant win is the addition of substantially better support for
*SSL* connections and security certificates.

In addition, more classes now implement a :term:`context manager` to support
convenient and reliable resource clean-up using a :keyword:`with` statement.

email
-----

The usability of the :mod:`email` package in Python 3 has been mostly fixed by
the extensive efforts of R. David Murray.  The problem was that emails are
typically read and stored in the form of :class:`bytes` rather than :class:`str`
text, and they may contain multiple encodings within a single email.  So, the
email package had to be extended to parse and generate email messages in bytes
format.

* New functions :func:`~email.message_from_bytes` and
  :func:`~email.message_from_binary_file`, and new classes
  :class:`~email.parser.BytesFeedParser` and :class:`~email.parser.BytesParser`
  allow binary message data to be parsed into model objects.

* Given bytes input to the model, :meth:`~email.message.Message.get_payload`
  will by default decode a message body that has a
  :mailheader:`Content-Transfer-Encoding` of *8bit* using the charset
  specified in the MIME headers and return the resulting string.

* Given bytes input to the model, :class:`~email.generator.Generator` will
  convert message bodies that have a :mailheader:`Content-Transfer-Encoding` of
  *8bit* to instead have a *7bit* :mailheader:`Content-Transfer-Encoding`.

  Headers with unencoded non-ASCII bytes are deemed to be :rfc:`2047`\ -encoded
  using the *unknown-8bit* character set.

* A new class :class:`~email.generator.BytesGenerator` produces bytes as output,
  preserving any unchanged non-ASCII data that was present in the input used to
  build the model, including message bodies with a
  :mailheader:`Content-Transfer-Encoding` of *8bit*.

* The :mod:`smtplib` :class:`~smtplib.SMTP` class now accepts a byte string
  for the *msg* argument to the :meth:`~smtplib.SMTP.sendmail` method,
  and a new method, :meth:`~smtplib.SMTP.send_message` accepts a
  :class:`~email.message.Message` object and can optionally obtain the
  *from_addr* and *to_addrs* addresses directly from the object.

(Proposed and implemented by R. David Murray, :issue:`4661` and :issue:`10321`.)

elementtree
-----------

The :mod:`xml.etree.ElementTree` package and its :mod:`xml.etree.cElementTree`
counterpart have been updated to version 1.3.

Several new and useful functions and methods have been added:

* :func:`xml.etree.ElementTree.fromstringlist` which builds an XML document
  from a sequence of fragments
* :func:`xml.etree.ElementTree.register_namespace` for registering a global
  namespace prefix
* :func:`xml.etree.ElementTree.tostringlist` for string representation
  including all sublists
* :meth:`xml.etree.ElementTree.Element.extend` for appending a sequence of zero
  or more elements
* :meth:`xml.etree.ElementTree.Element.iterfind` searches an element and
  subelements
* :meth:`xml.etree.ElementTree.Element.itertext` creates a text iterator over
  an element and its subelements
* :meth:`xml.etree.ElementTree.TreeBuilder.end` closes the current element
* :meth:`xml.etree.ElementTree.TreeBuilder.doctype` handles a doctype
  declaration

Two methods have been deprecated:

* :meth:`xml.etree.ElementTree.getchildren` use ``list(elem)`` instead.
* :meth:`xml.etree.ElementTree.getiterator` use ``Element.iter`` instead.

For details of the update, see `Introducing ElementTree
<http://effbot.org/zone/elementtree-13-intro.htm>`_ on Fredrik Lundh's website.

(Contributed by Florent Xicluna and Fredrik Lundh, :issue:`6472`.)

functools
---------

* The :mod:`functools` module includes a new decorator for caching function
  calls.  :func:`functools.lru_cache` can save repeated queries to an external
  resource whenever the results are expected to be the same.

  For example, adding a caching decorator to a database query function can save
  database accesses for popular searches:

  >>> import functools
  >>> @functools.lru_cache(maxsize=300)
  >>> def get_phone_number(name):
          c = conn.cursor()
          c.execute('SELECT phonenumber FROM phonelist WHERE name=?', (name,))
          return c.fetchone()[0]

  >>> for name in user_requests:
          get_phone_number(name)        # cached lookup

  To help with choosing an effective cache size, the wrapped function is
  instrumented for tracking cache statistics:

  >>> get_phone_number.cache_info()
  CacheInfo(hits=4805, misses=980, maxsize=300, currsize=300)

  If the phonelist table gets updated, the outdated contents of the cache can be
  cleared with:

  >>> get_phone_number.cache_clear()

  (Contributed by Raymond Hettinger and incorporating design ideas from Jim
  Baker, Miki Tebeka, and Nick Coghlan; see `recipe 498245
  <http://code.activestate.com/recipes/498245>`_\, `recipe 577479
  <http://code.activestate.com/recipes/577479>`_\, :issue:`10586`, and
  :issue:`10593`.)

* The :func:`functools.wraps` decorator now adds a :attr:`__wrapped__` attribute
  pointing to the original callable function.  This allows wrapped functions to
  be introspected.  It also copies :attr:`__annotations__` if defined.  And now
  it also gracefully skips over missing attributes such as :attr:`__doc__` which
  might not be defined for the wrapped callable.

  In the above example, the cache can be removed by recovering the original
  function:

  >>> get_phone_number = get_phone_number.__wrapped__    # uncached function

  (By Nick Coghlan and Terrence Cole; :issue:`9567`, :issue:`3445`, and
  :issue:`8814`.)

* To help write classes with rich comparison methods, a new decorator
  :func:`functools.total_ordering` will use a existing equality and inequality
  methods to fill in the remaining methods.

  For example, supplying *__eq__* and *__lt__* will enable
  :func:`~functools.total_ordering` to fill-in *__le__*, *__gt__* and *__ge__*::

    @total_ordering
    class Student:
        def __eq__(self, other):
            return ((self.lastname.lower(), self.firstname.lower()) ==
                    (other.lastname.lower(), other.firstname.lower()))
        def __lt__(self, other):
            return ((self.lastname.lower(), self.firstname.lower()) <
                    (other.lastname.lower(), other.firstname.lower()))

  With the *total_ordering* decorator, the remaining comparison methods
  are filled in automatically.

  (Contributed by Raymond Hettinger.)

* To aid in porting programs from Python 2, the :func:`functools.cmp_to_key`
  function converts an old-style comparison function to
  modern :term:`key function`:

  >>> # locale-aware sort order
  >>> sorted(iterable, key=cmp_to_key(locale.strcoll))

  For sorting examples and a brief sorting tutorial, see the `Sorting HowTo
  <http://wiki.python.org/moin/HowTo/Sorting/>`_ tutorial.

  (Contributed by Raymond Hettinger.)

itertools
---------

* The :mod:`itertools` module has a new :func:`~itertools.accumulate` function
  modeled on APL's *scan* operator and Numpy's *accumulate* function:

  >>> from itertools import accumulate
  >>> list(accumulate([8, 2, 50]))
  [8, 10, 60]

  >>> prob_dist = [0.1, 0.4, 0.2, 0.3]
  >>> list(accumulate(prob_dist))      # cumulative probability distribution
  [0.1, 0.5, 0.7, 1.0]

  For an example using :func:`~itertools.accumulate`, see the :ref:`examples for
  the random module <random-examples>`.

  (Contributed by Raymond Hettinger and incorporating design suggestions
  from Mark Dickinson.)

collections
-----------

* The :class:`collections.Counter` class now has two forms of in-place
  subtraction, the existing *-=* operator for `saturating subtraction
  <http://en.wikipedia.org/wiki/Saturation_arithmetic>`_ and the new
  :meth:`~collections.Counter.subtract` method for regular subtraction.  The
  former is suitable for `multisets <http://en.wikipedia.org/wiki/Multiset>`_
  which only have positive counts, and the latter is more suitable for use cases
  that allow negative counts:

  >>> tally = Counter(dogs=5, cat=3)
  >>> tally -= Counter(dogs=2, cats=8)    # saturating subtraction
  >>> tally
  Counter({'dogs': 3})

  >>> tally = Counter(dogs=5, cats=3)
  >>> tally.subtract(dogs=2, cats=8)      # regular subtraction
  >>> tally
  Counter({'dogs': 3, 'cats': -5})

  (Contributed by Raymond Hettinger.)

* The :class:`collections.OrderedDict` class has a new method
  :meth:`~collections.OrderedDict.move_to_end` which takes an existing key and
  moves it to either the first or last position in the ordered sequence.

  The default is to move an item to the last position.  This is equivalent of
  renewing an entry with ``od[k] = od.pop(k)``.

  A fast move-to-end operation is useful for resequencing entries.  For example,
  an ordered dictionary can be used to track order of access by aging entries
  from the oldest to the most recently accessed.

  >>> d = OrderedDict.fromkeys(['a', 'b', 'X', 'd', 'e'])
  >>> list(d)
  ['a', 'b', 'X', 'd', 'e']
  >>> d.move_to_end('X')
  >>> list(d)
  ['a', 'b', 'd', 'e', 'X']

  (Contributed by Raymond Hettinger.)

* The :class:`collections.deque` class grew two new methods
  :meth:`~collections.deque.count` and :meth:`~collections.deque.reverse` that
  make them more substitutable for :class:`list` objects:

  >>> d = deque('simsalabim')
  >>> d.count('s')
  2
  >>> d.reverse()
  >>> d
  deque(['m', 'i', 'b', 'a', 'l', 'a', 's', 'm', 'i', 's'])

  (Contributed by Raymond Hettinger.)

threading
---------

The :mod:`threading` module has a new :class:`~threading.Barrier`
synchronization class for making multiple threads wait until all of them have
reached a common barrier point.  Barriers are useful for making sure that a task
with multiple preconditions does not run until all of the predecessor tasks are
complete.

Barriers can work with an arbitrary number of threads.  This is a generalization
of a `Rendezvous <http://en.wikipedia.org/wiki/Synchronous_rendezvous>`_ which
is defined for only two threads.

Implemented as a two-phase cyclic barrier, :class:`~threading.Barrier` objects
are suitable for use in loops.  The separate *filling* and *draining* phases
assure that all threads get released (drained) before any one of them can loop
back and re-enter the barrier.  The barrier fully resets after each cycle.

Example of using barriers::

    from threading import Barrier, Thread

    def get_votes(site):
        ballots = conduct_election(site)
        all_polls_closed.wait()        # do not count until all polls are closed
        totals = summarize(ballots)
        publish(site, totals)

    all_polls_closed = Barrier(len(sites))
    for site in sites:
        Thread(target=get_votes, args=(site,)).start()

In this example, the barrier enforces a rule that votes cannot be counted at any
polling site until all polls are closed.  Notice how a solution with a barrier
is similar to one with :meth:`threading.Thread.join`, but the threads stay alive
and continue to do work (summarizing ballots) after the barrier point is
crossed.

If any of the predecessor tasks can hang or be delayed, a barrier can be created
with an optional *timeout* parameter.  Then if the timeout period elapses before
all the predecessor tasks reach the barrier point, all waiting threads are
released and a :exc:`~threading.BrokenBarrierError` exception is raised::

    def get_votes(site):
        ballots = conduct_election(site)
        try:
            all_polls_closed.wait(timeout = midnight - time.now())
        except BrokenBarrierError:
            lockbox = seal_ballots(ballots)
            queue.put(lockbox)
        else:
            totals = summarize(ballots)
            publish(site, totals)

In this example, the barrier enforces a more robust rule.  If some election
sites do not finish before midnight, the barrier times-out and the ballots are
sealed and deposited in a queue for later handling.

See `Barrier Synchronization Patterns
<http://parlab.eecs.berkeley.edu/wiki/_media/patterns/paraplop_g1_3.pdf>`_ for
more examples of how barriers can be used in parallel computing.  Also, there is
a simple but thorough explanation of barriers in `The Little Book of Semaphores
<http://greenteapress.com/semaphores/downey08semaphores.pdf>`_, *section 3.6*.

(Contributed by Kristján Valur Jónsson with an API review by Jeffrey Yasskin in
:issue:`8777`.)

datetime and time
-----------------

* The :mod:`datetime` module has a new type :class:`~datetime.timezone` that
  implements the :class:`~datetime.tzinfo` interface by returning a fixed UTC
  offset and timezone name. This makes it easier to create timezone-aware
  datetime objects::

    >>> from datetime import datetime, timezone

    >>> datetime.now(timezone.utc)
    datetime.datetime(2010, 12, 8, 21, 4, 2, 923754, tzinfo=datetime.timezone.utc)

    >>> datetime.strptime("01/01/2000 12:00 +0000", "%m/%d/%Y %H:%M %z")
    datetime.datetime(2000, 1, 1, 12, 0, tzinfo=datetime.timezone.utc)

* Also, :class:`~datetime.timedelta` objects can now be multiplied by
  :class:`float` and divided by :class:`float` and :class:`int` objects.
  And :class:`~datetime.timedelta` objects can now divide one another.

* The :meth:`datetime.date.strftime` method is no longer restricted to years
  after 1900.  The new supported year range is from 1000 to 9999 inclusive.

* Whenever a two-digit year is used in a time tuple, the interpretation has been
  governed by :attr:`time.accept2dyear`.  The default is *True* which means that
  for a two-digit year, the century is guessed according to the POSIX rules
  governing the ``%y`` strptime format.

  Starting with Py3.2, use of the century guessing heuristic will emit a
  :exc:`DeprecationWarning`.  Instead, it is recommended that
  :attr:`time.accept2dyear` be set to *False* so that large date ranges
  can be used without guesswork::

    >>> import time, warnings
    >>> warnings.resetwarnings()      # remove the default warning filters

    >>> time.accept2dyear = True      # guess whether 11 means 11 or 2011
    >>> time.asctime((11, 1, 1, 12, 34, 56, 4, 1, 0))
    Warning (from warnings module):
      ...
    DeprecationWarning: Century info guessed for a 2-digit year.
    'Fri Jan  1 12:34:56 2011'

    >>> time.accept2dyear = False     # use the full range of allowable dates
    >>> time.asctime((11, 1, 1, 12, 34, 56, 4, 1, 0))
    'Fri Jan  1 12:34:56 11'

  Several functions now have significantly expanded date ranges.  When
  :attr:`time.accept2dyear` is false, the :func:`time.asctime` function will
  accept any year that fits in a C int, while the :func:`time.mktime` and
  :func:`time.strftime` functions will accept the full range supported by the
  corresponding operating system functions.

(Contributed by Alexander Belopolsky and Victor Stinner in :issue:`1289118`,
:issue:`5094`, :issue:`6641`, :issue:`2706`, :issue:`1777412`, :issue:`8013`,
and :issue:`10827`.)

.. XXX http://bugs.python.org/issue?%40search_text=datetime&%40sort=-activity

math
----

The :mod:`math` module has been updated with six new functions inspired by the
C99 standard.

The :func:`~math.isfinite` function provides a reliable and fast way to detect
special values.  It returns *True* for regular numbers and *False* for *Nan* or
*Infinity*:

>>> [isfinite(x) for x in (123, 4.56, float('Nan'), float('Inf'))]
[True, True, False, False]

The :func:`~math.expm1` function computes ``e**x-1`` for small values of *x*
without incurring the loss of precision that usually accompanies the subtraction
of nearly equal quantities:

>>> expm1(0.013671875)   # more accurate way to compute e**x-1 for a small x
0.013765762467652909

The :func:`~math.erf` function computes a probability integral or `Gaussian
error function <http://en.wikipedia.org/wiki/Error_function>`_.  The
complementary error function, :func:`~math.erfc`, is ``1 - erf(x)``:

>>> erf(1.0/sqrt(2.0))   # portion of normal distribution within 1 standard deviation
0.682689492137086
>>> erfc(1.0/sqrt(2.0))  # portion of normal distribution outside 1 standard deviation
0.31731050786291404
>>> erf(1.0/sqrt(2.0)) + erfc(1.0/sqrt(2.0))
1.0

The :func:`~math.gamma` function is a continuous extension of the factorial
function.  See http://en.wikipedia.org/wiki/Gamma_function for details.  Because
the function is related to factorials, it grows large even for small values of
*x*, so there is also a :func:`~math.lgamma` function for computing the natural
logarithm of the gamma function:

>>> gamma(7.0)           # six factorial
720.0
>>> lgamma(801.0)        # log(800 factorial)
4551.950730698041

(Contributed by Mark Dickinson.)

abc
---

The :mod:`abc` module now supports :func:`~abc.abstractclassmethod` and
:func:`~abc.abstractstaticmethod`.

These tools make it possible to define an :term:`abstract base class` that
requires a particular :func:`classmethod` or :func:`staticmethod` to be
implemented::

    class Temperature(metaclass=abc.ABCMeta):
        @abc.abstractclassmethod
        def from_fahrenheit(cls, t):
            ...
        @abc.abstractclassmethod
        def from_celsius(cls, t):
            ...

(Patch submitted by Daniel Urban; :issue:`5867`.)

io
--

The :class:`io.BytesIO` has a new method, :meth:`~io.BytesIO.getbuffer`, which
provides functionality similar to :func:`memoryview`.  It creates an editable
view of the data without making a copy.  The buffer's random access and support
for slice notation are well-suited to in-place editing::

    >>> REC_LEN, LOC_START, LOC_LEN = 34, 7, 11

    >>> def change_location(buffer, record_number, location):
            start = record_number * REC_LEN + LOC_START
            buffer[start: start+LOC_LEN] = location

    >>> import io

    >>> byte_stream = io.BytesIO(
        b'G3805  storeroom  Main chassis    '
        b'X7899  shipping   Reserve cog     '
        b'L6988  receiving  Primary sprocket'
    )
    >>> buffer = byte_stream.getbuffer()
    >>> change_location(buffer, 1, b'warehouse  ')
    >>> change_location(buffer, 0, b'showroom   ')
    >>> print(byte_stream.getvalue())
    b'G3805  showroom   Main chassis    '
    b'X7899  warehouse  Reserve cog     '
    b'L6988  receiving  Primary sprocket'

(Contributed by Antoine Pitrou in :issue:`5506`.)

reprlib
-------

When writing a :meth:`__repr__` method for a custom container, it is easy to
forget to handle the case where a member refers back to the container itself.
Python's builtin objects such as :class:`list` and :class:`set` handle
self-reference by displaying "..." in the recursive part of the representation
string.

To help write such :meth:`__repr__` methods, the :mod:`reprlib` module has a new
decorator, :func:`~reprlib.recursive_repr`, for detecting recursive calls to
:meth:`__repr__` and substituting a placeholder string instead::

        >>> class MyList(list):
                @recursive_repr()
                def __repr__(self):
                    return '<' + '|'.join(map(repr, self)) + '>'

        >>> m = MyList('abc')
        >>> m.append(m)
        >>> m.append('x')
        >>> print(m)
        <'a'|'b'|'c'|...|'x'>

(Contributed by Raymond Hettinger in :issue:`9826` and :issue:`9840`.)

logging
-------

In addition to dictionary-based configuration described above, the
:mod:`logging` package has many other improvements.

The logging documentation has been augmented by a :ref:`basic tutorial
<logging-basic-tutorial>`\, an :ref:`advanced tutorial
<logging-advanced-tutorial>`\, and a :ref:`cookbook <logging-cookbook>` of
logging recipes.  These documents are the fastest way to learn about logging.

The :func:`logging.basicConfig` set-up function gained a *style* argument to
support three different types of string formatting.  It defaults to "%" for
traditional %-formatting, can be set to "{" for the new :meth:`str.format` style, or
can be set to "$" for the shell-style formatting provided by
:class:`string.Template`.  The following three configurations are equivalent::

    >>> from logging import basicConfig
    >>> basicConfig(style='%', format="%(name)s -> %(levelname)s: %(message)s")
    >>> basicConfig(style='{', format="{name} -> {levelname} {message}")
    >>> basicConfig(style='$', format="$name -> $levelname: $message")

If no configuration is set-up before a logging event occurs, there is now a
default configuration using a :class:`~logging.StreamHandler` directed to
:attr:`sys.stderr` for events of ``WARNING`` level or higher.  Formerly, an
event occurring before a configuration was set-up would either raise an
exception or silently drop the event depending on the value of
:attr:`logging.raiseExceptions`.  The new default handler is stored in
:attr:`logging.lastResort`.

The use of filters has been simplified.  Instead of creating a
:class:`~logging.Filter` object, the predicate can be any Python callable that
returns *True* or *False*.

There were a number of other improvements that add flexibility and simplify
configuration.  See the module documentation for a full listing of changes in
Python 3.2.

csv
---

The :mod:`csv` module now supports a new dialect, :class:`~csv.unix_dialect`,
which applies quoting for all fields and a traditional Unix style with ``'\n'`` as
the line terminator.  The registered dialect name is ``unix``.

The :class:`csv.DictWriter` has a new method,
:meth:`~csv.DictWriter.writeheader` for writing-out an initial row to document
the field names::

    >>> import csv, sys
    >>> w = csv.DictWriter(sys.stdout, ['name', 'dept'], dialect='unix')
    >>> w.writeheader()
    "name","dept"
    >>> w.writerows([
            {'name': 'tom', 'dept': 'accounting'},
            {'name': 'susan', 'dept': 'Salesl'}])
    "tom","accounting"
    "susan","sales"

(New dialect suggested by Jay Talbot in :issue:`5975`, and the new method
suggested by Ed Abraham in :issue:`1537721`.)

contextlib
----------

There is a new and slightly mind-blowing tool
:class:`~contextlib.ContextDecorator` that is helpful for creating a
:term:`context manager` that does double duty as a function decorator.

As a convenience, this new functionality is used by
:func:`~contextlib.contextmanager` so that no extra effort is needed to support
both roles.

The basic idea is that both context managers and function decorators can be used
for pre-action and post-action wrappers.  Context managers wrap a group of
statements using a :keyword:`with` statement, and function decorators wrap a
group of statements enclosed in a function.  So, occasionally there is a need to
write a pre-action or post-action wrapper that can be used in either role.

For example, it is sometimes useful to wrap functions or groups of statements
with a logger that can track the time of entry and time of exit.  Rather than
writing both a function decorator and a context manager for the task, the
:func:`~contextlib.contextmanager` provides both capabilities in a single
definition::

    from contextlib import contextmanager
    import logging

    logging.basicConfig(level=logging.INFO)

    @contextmanager
    def track_entry_and_exit(name):
        logging.info('Entering: {}'.format(name))
        yield
        logging.info('Exiting: {}'.format(name))

Formerly, this would have only been usable as a context manager::

    with track_entry_and_exit('widget loader'):
        print('Some time consuming activity goes here')
        load_widget()

Now, it can be used as a decorator as well::

    @track_entry_and_exit('widget loader')
    def activity():
        print('Some time consuming activity goes here')
        load_widget()

Trying to fulfill two roles at once places some limitations on the technique.
Context managers normally have the flexibility to return an argument usable by
a :keyword:`with` statement, but there is no parallel for function decorators.

In the above example, there is not a clean way for the *track_entry_and_exit*
context manager to return a logging instance for use in the body of enclosed
statements.

(Contributed by Michael Foord in :issue:`9110`.)

decimal and fractions
---------------------

Mark Dickinson crafted an elegant and efficient scheme for assuring that
different numeric datatypes will have the same hash value whenever their actual
values are equal (:issue:`8188`)::

   assert hash(Fraction(3, 2)) == hash(1.5) == \
          hash(Decimal("1.5")) == hash(complex(1.5, 0))

Some of the hashing details are exposed through a new attribute,
:attr:`sys.hash_info`, which describes the bit width of the hash value, the
prime modulus, the hash values for *infinity* and *nan*, and the multiplier
used for the imaginary part of a number:

>>> sys.hash_info
sys.hash_info(width=64, modulus=2305843009213693951, inf=314159, nan=0, imag=1000003)

An early decision to limit the inter-operability of various numeric types has
been relaxed.  It is still unsupported (and ill-advised) to have implicit
mixing in arithmetic expressions such as ``Decimal('1.1') + float('1.1')``
because the latter loses information in the process of constructing the binary
float.  However, since existing floating point value can be converted losslessly
to either a decimal or rational representation, it makes sense to add them to
the constructor and to support mixed-type comparisons.

* The :class:`decimal.Decimal` constructor now accepts :class:`float` objects
  directly so there in no longer a need to use the :meth:`~decimal.Decimal.from_float`
  method (:issue:`8257`).

* Mixed type comparisons are now fully supported so that
  :class:`~decimal.Decimal` objects can be directly compared with :class:`float`
  and :class:`fractions.Fraction` (:issue:`2531` and :issue:`8188`).

Similar changes were made to :class:`fractions.Fraction` so that the
:meth:`~fractions.Fraction.from_float()` and :meth:`~fractions.Fraction.from_decimal`
methods are no longer needed (:issue:`8294`):

>>> Decimal(1.1)
Decimal('1.100000000000000088817841970012523233890533447265625')
>>> Fraction(1.1)
Fraction(2476979795053773, 2251799813685248)

Another useful change for the :mod:`decimal` module is that the
:attr:`Context.clamp` attribute is now public.  This is useful in creating
contexts that correspond to the decimal interchange formats specified in IEEE
754 (see :issue:`8540`).

(Contributed by Mark Dickinson and Raymond Hettinger.)

ftp
---

The :class:`ftplib.FTP` class now supports the context manager protocol to
unconditionally consume :exc:`socket.error` exceptions and to close the FTP
connection when done::

 >>> from ftplib import FTP
 >>> with FTP("ftp1.at.proftpd.org") as ftp:
         ftp.login()
         ftp.dir()

 '230 Anonymous login ok, restrictions apply.'
 dr-xr-xr-x   9 ftp      ftp           154 May  6 10:43 .
 dr-xr-xr-x   9 ftp      ftp           154 May  6 10:43 ..
 dr-xr-xr-x   5 ftp      ftp          4096 May  6 10:43 CentOS
 dr-xr-xr-x   3 ftp      ftp            18 Jul 10  2008 Fedora

Other file-like objects such as :class:`mmap.mmap` and :func:`fileinput.input`
also grew auto-closing context managers::

    with fileinput.input(files=('log1.txt', 'log2.txt')) as f:
        for line in f:
            process(line)

(Contributed by Tarek Ziadé and Giampaolo Rodolà in :issue:`4972`, and
by Georg Brandl in :issue:`8046` and :issue:`1286`.)

The :class:`~ftplib.FTP_TLS` class now accepts a *context* parameter, which is a
:class:`ssl.SSLContext` object allowing bundling SSL configuration options,
certificates and private keys into a single (potentially long-lived) structure.

(Contributed by Giampaolo Rodolà; :issue:`8806`.)

popen
-----

The :func:`os.popen` and :func:`subprocess.Popen` functions now support
:keyword:`with` statements for auto-closing of the file descriptors.

(Contributed by Antoine Pitrou and Brian Curtin in :issue:`7461` and
:issue:`10554`.)

select
------

The :mod:`select` module now exposes a new, constant attribute,
:attr:`~select.PIPE_BUF`, which gives the minimum number of bytes which are
guaranteed not to block when :func:`select.select` says a pipe is ready
for writing.

>>> import select
>>> select.PIPE_BUF
512

(Available on Unix systems. Patch by Sébastien Sablé in :issue:`9862`)

gzip and zipfile
----------------

:class:`gzip.GzipFile` now implements the :class:`io.BufferedIOBase`
:term:`abstract base class` (except for ``truncate()``).  It also has a
:meth:`~gzip.GzipFile.peek` method and supports unseekable as well as
zero-padded file objects.

The :mod:`gzip` module also gains the :func:`~gzip.compress` and
:func:`~gzip.decompress` functions for easier in-memory compression and
decompression.  Keep in mind that text needs to be encoded as :class:`bytes`
before compressing and decompressing:

>>> s = 'Three shall be the number thou shalt count, '
>>> s += 'and the number of the counting shall be three'
>>> b = s.encode()                        # convert to utf-8
>>> len(b)
89
>>> c = gzip.compress(b)
>>> len(c)
77
>>> gzip.decompress(c).decode()[:42]      # decompress and convert to text
'Three shall be the number thou shalt count,'

(Contributed by Anand B. Pillai in :issue:`3488`; and by Antoine Pitrou, Nir
Aides and Brian Curtin in :issue:`9962`, :issue:`1675951`, :issue:`7471` and
:issue:`2846`.)

Also, the :class:`zipfile.ZipExtFile` class was reworked internally to represent
files stored inside an archive.  The new implementation is significantly faster
and can be wrapped in a :class:`io.BufferedReader` object for more speedups.  It
also solves an issue where interleaved calls to *read* and *readline* gave the
wrong results.

(Patch submitted by Nir Aides in :issue:`7610`.)

tarfile
-------

The :class:`~tarfile.TarFile` class can now be used as a context manager.  In
addition, its :meth:`~tarfile.TarFile.add` method has a new option, *filter*,
that controls which files are added to the archive and allows the file metadata
to be edited.

The new *filter* option replaces the older, less flexible *exclude* parameter
which is now deprecated.  If specified, the optional *filter* parameter needs to
be a :term:`keyword argument`.  The user-supplied filter function accepts a
:class:`~tarfile.TarInfo` object and returns an updated
:class:`~tarfile.TarInfo` object, or if it wants the file to be excluded, the
function can return *None*::

    >>> import tarfile, glob

    >>> def myfilter(tarinfo):
           if tarinfo.isfile():             # only save real files
                tarinfo.uname = 'monty'     # redact the user name
                return tarinfo

    >>> with tarfile.open(name='myarchive.tar.gz', mode='w:gz') as tf:
            for filename in glob.glob('*.txt'):
                tf.add(filename, filter=myfilter)
            tf.list()
    -rw-r--r-- monty/501        902 2011-01-26 17:59:11 annotations.txt
    -rw-r--r-- monty/501        123 2011-01-26 17:59:11 general_questions.txt
    -rw-r--r-- monty/501       3514 2011-01-26 17:59:11 prion.txt
    -rw-r--r-- monty/501        124 2011-01-26 17:59:11 py_todo.txt
    -rw-r--r-- monty/501       1399 2011-01-26 17:59:11 semaphore_notes.txt

(Proposed by Tarek Ziadé and implemented by Lars Gustäbel in :issue:`6856`.)

hashlib
-------

The :mod:`hashlib` module has two new constant attributes listing the hashing
algorithms guaranteed to be present in all implementations and those available
on the current implementation::

    >>> import hashlib

    >>> hashlib.algorithms_guaranteed
    {'sha1', 'sha224', 'sha384', 'sha256', 'sha512', 'md5'}

    >>> hashlib.algorithms_available
    {'md2', 'SHA256', 'SHA512', 'dsaWithSHA', 'mdc2', 'SHA224', 'MD4', 'sha256',
    'sha512', 'ripemd160', 'SHA1', 'MDC2', 'SHA', 'SHA384', 'MD2',
    'ecdsa-with-SHA1','md4', 'md5', 'sha1', 'DSA-SHA', 'sha224',
    'dsaEncryption', 'DSA', 'RIPEMD160', 'sha', 'MD5', 'sha384'}

(Suggested by Carl Chenet in :issue:`7418`.)

ast
---

The :mod:`ast` module has a wonderful a general-purpose tool for safely
evaluating expression strings using the Python literal
syntax.  The :func:`ast.literal_eval` function serves as a secure alternative to
the builtin :func:`eval` function which is easily abused.  Python 3.2 adds
:class:`bytes` and :class:`set` literals to the list of supported types:
strings, bytes, numbers, tuples, lists, dicts, sets, booleans, and None.

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

(Implemented by Benjamin Peterson and Georg Brandl.)

os
--

Different operating systems use various encodings for filenames and environment
variables.  The :mod:`os` module provides two new functions,
:func:`~os.fsencode` and :func:`~os.fsdecode`, for encoding and decoding
filenames:

>>> filename = 'Sehenswürdigkeiten'
>>> os.fsencode(filename)
b'Sehensw\xc3\xbcrdigkeiten'

Some operating systems allow direct access to encoded bytes in the
environment.  If so, the :attr:`os.supports_bytes_environ` constant will be
true.

For direct access to encoded environment variables (if available),
use the new :func:`os.getenvb` function or use :data:`os.environb`
which is a bytes version of :data:`os.environ`.

(Contributed by Victor Stinner.)

shutil
------

The :func:`shutil.copytree` function has two new options:

* *ignore_dangling_symlinks*: when ``symlinks=False`` so that the function
  copies a file pointed to by a symlink, not the symlink itself. This option
  will silence the error raised if the file doesn't exist.

* *copy_function*: is a callable that will be used to copy files.
  :func:`shutil.copy2` is used by default.

(Contributed by Tarek Ziadé.)

In addition, the :mod:`shutil` module now supports :ref:`archiving operations
<archiving-operations>` for zipfiles, uncompressed tarfiles, gzipped tarfiles,
and bzipped tarfiles.  And there are functions for registering additional
archiving file formats (such as xz compressed tarfiles or custom formats).

The principal functions are :func:`~shutil.make_archive` and
:func:`~shutil.unpack_archive`.  By default, both operate on the current
directory (which can be set by :func:`os.chdir`) and on any sub-directories.
The archive filename needs to be specified with a full pathname.  The archiving
step is non-destructive (the original files are left unchanged).

::

    >>> import shutil, pprint

    >>> os.chdir('mydata')                               # change to the source directory
    >>> f = shutil.make_archive('/var/backup/mydata',
                                'zip')                   # archive the current directory
    >>> f                                                # show the name of archive
    '/var/backup/mydata.zip'
    >>> os.chdir('tmp')                                  # change to an unpacking
    >>> shutil.unpack_archive('/var/backup/mydata.zip')  # recover the data

    >>> pprint.pprint(shutil.get_archive_formats())      # display known formats
    [('bztar', "bzip2'ed tar-file"),
     ('gztar', "gzip'ed tar-file"),
     ('tar', 'uncompressed tar file'),
     ('zip', 'ZIP file')]

    >>> shutil.register_archive_format(                  # register a new archive format
            name = 'xz',
            function = xz.compress,                      # callable archiving function
            extra_args = [('level', 8)],                 # arguments to the function
            description = 'xz compression'
    )

(Contributed by Tarek Ziadé.)

sqlite3
-------

The :mod:`sqlite3` module was updated to pysqlite version 2.6.0.  It has two new capabilities.

* The :attr:`sqlite3.Connection.in_transit` attribute is true if there is an
  active transaction for uncommitted changes.

* The :meth:`sqlite3.Connection.enable_load_extension` and
  :meth:`sqlite3.Connection.load_extension` methods allows you to load SQLite
  extensions from ".so" files.  One well-known extension is the fulltext-search
  extension distributed with SQLite.

(Contributed by R. David Murray and Shashwat Anand; :issue:`8845`.)

html
----

A new :mod:`html` module was introduced with only a single function,
:func:`~html.escape`, which is used for escaping reserved characters from HTML
markup:

>>> import html
>>> html.escape('x > 2 && x < 7')
'x &gt; 2 &amp;&amp; x &lt; 7'

socket
------

The :mod:`socket` module has two new improvements.

* Socket objects now have a :meth:`~socket.socket.detach()` method which puts
  the socket into closed state without actually closing the underlying file
  descriptor.  The latter can then be reused for other purposes.
  (Added by Antoine Pitrou; :issue:`8524`.)

* :func:`socket.create_connection` now supports the context manager protocol
  to unconditionally consume :exc:`socket.error` exceptions and to close the
  socket when done.
  (Contributed by Giampaolo Rodolà; :issue:`9794`.)

ssl
---

The :mod:`ssl` module added a number of features to satisfy common requirements
for secure (encrypted, authenticated) internet connections:

* A new class, :class:`~ssl.SSLContext`, serves as a container for persistent
  SSL data, such as protocol settings, certificates, private keys, and various
  other options. It includes a :meth:`~ssl.SSLContext.wrap_socket` for creating
  an SSL socket from an SSL context.

* A new function, :func:`ssl.match_hostname`, supports server identity
  verification for higher-level protocols by implementing the rules of HTTPS
  (from :rfc:`2818`) which are also suitable for other protocols.

* The :func:`ssl.wrap_socket` constructor function now takes a *ciphers*
  argument.  The *ciphers* string lists the allowed encryption algorithms using
  the format described in the `OpenSSL documentation
  <http://www.openssl.org/docs/apps/ciphers.html#CIPHER_LIST_FORMAT>`__.

* When linked against recent versions of OpenSSL, the :mod:`ssl` module now
  supports the Server Name Indication extension to the TLS protocol, allowing
  multiple "virtual hosts" using different certificates on a single IP port.
  This extension is only supported in client mode, and is activated by passing
  the *server_hostname* argument to :meth:`ssl.SSLContext.wrap_socket`.

* Various options have been added to the :mod:`ssl` module, such as
  :data:`~ssl.OP_NO_SSLv2` which disables the insecure and obsolete SSLv2
  protocol.

* The extension now loads all the OpenSSL ciphers and digest algorithms.  If
  some SSL certificates cannot be verified, they are reported as an "unknown
  algorithm" error.

* The version of OpenSSL being used is now accessible using the module
  attributes :data:`ssl.OPENSSL_VERSION` (a string),
  :data:`ssl.OPENSSL_VERSION_INFO` (a 5-tuple), and
  :data:`ssl.OPENSSL_VERSION_NUMBER` (an integer).

(Contributed by Antoine Pitrou in :issue:`8850`, :issue:`1589`, :issue:`8322`,
:issue:`5639`, :issue:`4870`, :issue:`8484`, and :issue:`8321`.)

nntp
----

The :mod:`nntplib` module has a revamped implementation with better bytes and
text semantics as well as more practical APIs.  These improvements break
compatibility with the nntplib version in Python 3.1, which was partly
dysfunctional in itself.

Support for secure connections through both implicit (using
:class:`nntplib.NNTP_SSL`) and explicit (using :meth:`nntplib.NNTP.starttls`)
TLS has also been added.

(Contributed by Antoine Pitrou in :issue:`9360` and Andrew Vant in :issue:`1926`.)

certificates
------------

:class:`http.client.HTTPSConnection`, :class:`urllib.request.HTTPSHandler`
and :func:`urllib.request.urlopen` now take optional arguments to allow for
server certificate checking against a set of Certificate Authorities,
as recommended in public uses of HTTPS.

(Added by Antoine Pitrou, :issue:`9003`.)

imaplib
-------

Support for explicit TLS on standard IMAP4 connections has been added through
the new :mod:`imaplib.IMAP4.starttls` method.

(Contributed by Lorenzo M. Catucci and Antoine Pitrou, :issue:`4471`.)

http.client
-----------

There were a number of small API improvements in the :mod:`http.client` module.
The old-style HTTP 0.9 simple responses are no longer supported and the *strict*
parameter is deprecated in all classes.

The :class:`~http.client.HTTPConnection` and
:class:`~http.client.HTTPSConnection` classes now have a *source_address*
parameter for a (host, port) tuple indicating where the HTTP connection is made
from.

Support for certificate checking and HTTPS virtual hosts were added to
:class:`~http.client.HTTPSConnection`.

The :meth:`~http.client.HTTPConnection.request` method on connection objects
allowed an optional *body* argument so that a :term:`file object` could be used
to supply the content of the request.  Conveniently, the *body* argument now
also accepts an :term:`iterable` object so long as it includes an explicit
``Content-Length`` header.  This extended interface is much more flexible than
before.

To establish an HTTPS connection through a proxy server, there is a new
:meth:`~http.client.HTTPConnection.set_tunnel` method that sets the host and
port for HTTP Connect tunneling.

To match the behavior of :mod:`http.server`, the HTTP client library now also
encodes headers with ISO-8859-1 (Latin-1) encoding.  It was already doing that
for incoming headers, so now the behavior is consistent for both incoming and
outgoing traffic. (See work by Armin Ronacher in :issue:`10980`.)

unittest
--------

The unittest module has a number of improvements supporting test discovery for
packages, easier experimentation at the interactive prompt, new testcase
methods, improved diagnostic messages for test failures, and better method
names.

* The command-line call ``python -m unittest`` can now accept file paths
  instead of module names for running specific tests (:issue:`10620`).  The new
  test discovery can find tests within packages, locating any test importable
  from the top-level directory.  The top-level directory can be specified with
  the `-t` option, a pattern for matching files with ``-p``, and a directory to
  start discovery with ``-s``::

    $ python -m unittest discover -s my_proj_dir -p _test.py

  (Contributed by Michael Foord.)

* Experimentation at the interactive prompt is now easier because the
  :class:`unittest.case.TestCase` class can now be instantiated without
  arguments:

  >>> TestCase().assertEqual(pow(2, 3), 8)

  (Contributed by Michael Foord.)

* The :mod:`unittest` module has two new methods,
  :meth:`~unittest.TestCase.assertWarns` and
  :meth:`~unittest.TestCase.assertWarnsRegex` to verify that a given warning type
  is triggered by the code under test::

      with self.assertWarns(DeprecationWarning):
          legacy_function('XYZ')

  (Contributed by Antoine Pitrou, :issue:`9754`.)

  Another new method, :meth:`~unittest.TestCase.assertCountEqual` is used to
  compare two iterables to determine if their element counts are equal (whether
  the same elements are present with the same number of occurrences regardless
  of order)::

     def test_anagram(self):
         self.assertCountEqual('algorithm', 'logarithm')

  (Contributed by Raymond Hettinger.)

* A principal feature of the unittest module is an effort to produce meaningful
  diagnostics when a test fails.  When possible, the failure is recorded along
  with a diff of the output.  This is especially helpful for analyzing log files
  of failed test runs. However, since diffs can sometime be voluminous, there is
  a new :attr:`~unittest.TestCase.maxDiff` attribute that sets maximum length of
  diffs displayed.

* In addition, the method names in the module have undergone a number of clean-ups.

  For example, :meth:`~unittest.TestCase.assertRegex` is the new name for
  :meth:`~unittest.TestCase.assertRegexpMatches` which was misnamed because the
  test uses :func:`re.search`, not :func:`re.match`.  Other methods using
  regular expressions are now named using short form "Regex" in preference to
  "Regexp" -- this matches the names used in other unittest implementations,
  matches Python's old name for the :mod:`re` module, and it has unambiguous
  camel-casing.

  (Contributed by Raymond Hettinger and implemented by Ezio Melotti.)

* To improve consistency, some long-standing method aliases are being
  deprecated in favor of the preferred names:

   ===============================   ==============================
   Old Name                          Preferred Name
   ===============================   ==============================
   :meth:`assert_`                   :meth:`.assertTrue`
   :meth:`assertEquals`              :meth:`.assertEqual`
   :meth:`assertNotEquals`           :meth:`.assertNotEqual`
   :meth:`assertAlmostEquals`        :meth:`.assertAlmostEqual`
   :meth:`assertNotAlmostEquals`     :meth:`.assertNotAlmostEqual`
   ===============================   ==============================

  Likewise, the ``TestCase.fail*`` methods deprecated in Python 3.1 are expected
  to be removed in Python 3.3.  Also see the :ref:`deprecated-aliases` section in
  the :mod:`unittest` documentation.

  (Contributed by Ezio Melotti; :issue:`9424`.)

* The :meth:`~unittest.TestCase.assertDictContainsSubset` method was deprecated
  because it was misimplemented with the arguments in the wrong order.  This
  created hard-to-debug optical illusions where tests like
  ``TestCase().assertDictContainsSubset({'a':1, 'b':2}, {'a':1})`` would fail.

  (Contributed by Raymond Hettinger.)

random
------

The integer methods in the :mod:`random` module now do a better job of producing
uniform distributions.  Previously, they computed selections with
``int(n*random())`` which had a slight bias whenever *n* was not a power of two.
Now, multiple selections are made from a range up to the next power of two and a
selection is kept only when it falls within the range ``0 <= x < n``.  The
functions and methods affected are :func:`~random.randrange`,
:func:`~random.randint`, :func:`~random.choice`, :func:`~random.shuffle` and
:func:`~random.sample`.

(Contributed by Raymond Hettinger; :issue:`9025`.)

poplib
------

:class:`~poplib.POP3_SSL` class now accepts a *context* parameter, which is a
:class:`ssl.SSLContext` object allowing bundling SSL configuration options,
certificates and private keys into a single (potentially long-lived)
structure.

(Contributed by Giampaolo Rodolà; :issue:`8807`.)

asyncore
--------

:class:`asyncore.dispatcher` now provides a
:meth:`~asyncore.dispatcher.handle_accepted()` method
returning a `(sock, addr)` pair which is called when a connection has actually
been established with a new remote endpoint. This is supposed to be used as a
replacement for old :meth:`~asyncore.dispatcher.handle_accept()` and avoids
the user  to call :meth:`~asyncore.dispatcher.accept()` directly.

(Contributed by Giampaolo Rodolà; :issue:`6706`.)

tempfile
--------

The :mod:`tempfile` module has a new context manager,
:class:`~tempfile.TemporaryDirectory` which provides easy deterministic
cleanup of temporary directories::

    with tempfile.TemporaryDirectory() as tmpdirname:
        print('created temporary dir:', tmpdirname)

(Contributed by Neil Schemenauer and Nick Coghlan; :issue:`5178`.)

inspect
-------

* The :mod:`inspect` module has a new function
  :func:`~inspect.getgeneratorstate` to easily identify the current state of a
  generator-iterator::

    >>> from inspect import getgeneratorstate
    >>> def gen():
            yield 'demo'
    >>> g = gen()
    >>> getgeneratorstate(g)
    'GEN_CREATED'
    >>> next(g)
    'demo'
    >>> getgeneratorstate(g)
    'GEN_SUSPENDED'
    >>> next(g, None)
    >>> getgeneratorstate(g)
    'GEN_CLOSED'

  (Contributed by Rodolpho Eckhardt and Nick Coghlan, :issue:`10220`.)

* To support lookups without the possibility of activating a dynamic attribute,
  the :mod:`inspect` module has a new function, :func:`~inspect.getattr_static`.
  Unlike :func:`hasattr`, this is a true read-only search, guaranteed not to
  change state while it is searching::

    >>> class A:
            @property
            def f(self):
                print('Running')
                return 10

    >>> a = A()
    >>> getattr(a, 'f')
    Running
    10
    >>> inspect.getattr_static(a, 'f')
    <property object at 0x1022bd788>

 (Contributed by Michael Foord.)

pydoc
-----

The :mod:`pydoc` module now provides a much-improved Web server interface, as
well as a new command-line option ``-b`` to automatically open a browser window
to display that server::

    $ pydoc3.2 -b

(Contributed by Ron Adam; :issue:`2001`.)

dis
---

The :mod:`dis` module gained two new functions for inspecting code,
:func:`~dis.code_info` and :func:`~dis.show_code`.  Both provide detailed code
object information for the supplied function, method, source code string or code
object.  The former returns a string and the latter prints it::

    >>> import dis, random
    >>> dis.show_code(random.choice)
    Name:              choice
    Filename:          /Library/Frameworks/Python.framework/Versions/3.2/lib/python3.2/random.py
    Argument count:    2
    Kw-only arguments: 0
    Number of locals:  3
    Stack size:        11
    Flags:             OPTIMIZED, NEWLOCALS, NOFREE
    Constants:
       0: 'Choose a random element from a non-empty sequence.'
       1: 'Cannot choose from an empty sequence'
    Names:
       0: _randbelow
       1: len
       2: ValueError
       3: IndexError
    Variable names:
       0: self
       1: seq
       2: i

In addition, the :func:`~dis.dis` function now accepts string arguments
so that the common idiom ``dis(compile(s, '', 'eval'))`` can be shortened
to ``dis(s)``::

    >>> dis('3*x+1 if x%2==1 else x//2')
      1           0 LOAD_NAME                0 (x)
                  3 LOAD_CONST               0 (2)
                  6 BINARY_MODULO
                  7 LOAD_CONST               1 (1)
                 10 COMPARE_OP               2 (==)
                 13 POP_JUMP_IF_FALSE       28
                 16 LOAD_CONST               2 (3)
                 19 LOAD_NAME                0 (x)
                 22 BINARY_MULTIPLY
                 23 LOAD_CONST               1 (1)
                 26 BINARY_ADD
                 27 RETURN_VALUE
            >>   28 LOAD_NAME                0 (x)
                 31 LOAD_CONST               0 (2)
                 34 BINARY_FLOOR_DIVIDE
                 35 RETURN_VALUE

Taken together, these improvements make it easier to explore how CPython is
implemented and to see for yourself what the language syntax does
under-the-hood.

(Contributed by Nick Coghlan in :issue:`9147`.)

dbm
---

All database modules now support the :meth:`get` and :meth:`setdefault` methods.

(Suggested by Ray Allen in :issue:`9523`.)

ctypes
------

A new type, :class:`ctypes.c_ssize_t` represents the C :c:type:`ssize_t` datatype.

site
----

The :mod:`site` module has three new functions useful for reporting on the
details of a given Python installation.

* :func:`~site.getsitepackages` lists all global site-packages directories.

* :func:`~site.getuserbase` reports on the user's base directory where data can
  be stored.

* :func:`~site.getusersitepackages` reveals the user-specific site-packages
  directory path.

::

    >>> import site
    >>> site.getsitepackages()
    ['/Library/Frameworks/Python.framework/Versions/3.2/lib/python3.2/site-packages',
     '/Library/Frameworks/Python.framework/Versions/3.2/lib/site-python',
     '/Library/Python/3.2/site-packages']
    >>> site.getuserbase()
    '/Users/raymondhettinger/Library/Python/3.2'
    >>> site.getusersitepackages()
    '/Users/raymondhettinger/Library/Python/3.2/lib/python/site-packages'

Conveniently, some of site's functionality is accessible directly from the
command-line::

    $ python -m site --user-base
    /Users/raymondhettinger/.local
    $ python -m site --user-site
    /Users/raymondhettinger/.local/lib/python3.2/site-packages

(Contributed by Tarek Ziadé in :issue:`6693`.)

sysconfig
---------

The new :mod:`sysconfig` module makes it straightforward to discover
installation paths and configuration variables that vary across platforms and
installations.

The module offers access simple access functions for platform and version
information:

* :func:`~sysconfig.get_platform` returning values like *linux-i586* or
  *macosx-10.6-ppc*.
* :func:`~sysconfig.get_python_version` returns a Python version string
  such as "3.2".

It also provides access to the paths and variables corresponding to one of
seven named schemes used by :mod:`distutils`.  Those include *posix_prefix*,
*posix_home*, *posix_user*, *nt*, *nt_user*, *os2*, *os2_home*:

* :func:`~sysconfig.get_paths` makes a dictionary containing installation paths
  for the current installation scheme.
* :func:`~sysconfig.get_config_vars` returns a dictionary of platform specific
  variables.

There is also a convenient command-line interface::

  C:\Python32>python -m sysconfig
  Platform: "win32"
  Python version: "3.2"
  Current installation scheme: "nt"

  Paths:
          data = "C:\Python32"
          include = "C:\Python32\Include"
          platinclude = "C:\Python32\Include"
          platlib = "C:\Python32\Lib\site-packages"
          platstdlib = "C:\Python32\Lib"
          purelib = "C:\Python32\Lib\site-packages"
          scripts = "C:\Python32\Scripts"
          stdlib = "C:\Python32\Lib"

  Variables:
          BINDIR = "C:\Python32"
          BINLIBDEST = "C:\Python32\Lib"
          EXE = ".exe"
          INCLUDEPY = "C:\Python32\Include"
          LIBDEST = "C:\Python32\Lib"
          SO = ".pyd"
          VERSION = "32"
          abiflags = ""
          base = "C:\Python32"
          exec_prefix = "C:\Python32"
          platbase = "C:\Python32"
          prefix = "C:\Python32"
          projectbase = "C:\Python32"
          py_version = "3.2"
          py_version_nodot = "32"
          py_version_short = "3.2"
          srcdir = "C:\Python32"
          userbase = "C:\Documents and Settings\Raymond\Application Data\Python"

(Moved out of Distutils by Tarek Ziadé.)

pdb
---

The :mod:`pdb` debugger module gained a number of usability improvements:

* :file:`pdb.py` now has a ``-c`` option that executes commands as given in a
  :file:`.pdbrc` script file.
* A :file:`.pdbrc` script file can contain ``continue`` and ``next`` commands
  that continue debugging.
* The :class:`Pdb` class constructor now accepts a *nosigint* argument.
* New commands: ``l(list)``, ``ll(long list)`` and ``source`` for
  listing source code.
* New commands: ``display`` and ``undisplay`` for showing or hiding
  the value of an expression if it has changed.
* New command: ``interact`` for starting an interactive interpreter containing
  the global and local  names found in the current scope.
* Breakpoints can be cleared by breakpoint number.

(Contributed by Georg Brandl, Antonio Cuni and Ilya Sandler.)

configparser
------------

The :mod:`configparser` module was modified to improve usability and
predictability of the default parser and its supported INI syntax.  The old
:class:`ConfigParser` class was removed in favor of :class:`SafeConfigParser`
which has in turn been renamed to :class:`~configparser.ConfigParser`. Support
for inline comments is now turned off by default and section or option
duplicates are not allowed in a single configuration source.

Config parsers gained a new API based on the mapping protocol::

    >>> parser = ConfigParser()
    >>> parser.read_string("""
    [DEFAULT]
    location = upper left
    visible = yes
    editable = no
    color = blue

    [main]
    title = Main Menu
    color = green

    [options]
    title = Options
    """)
    >>> parser['main']['color']
    'green'
    >>> parser['main']['editable']
    'no'
    >>> section = parser['options']
    >>> section['title']
    'Options'
    >>> section['title'] = 'Options (editable: %(editable)s)'
    >>> section['title']
    'Options (editable: no)'

The new API is implemented on top of the classical API, so custom parser
subclasses should be able to use it without modifications.

The INI file structure accepted by config parsers can now be customized. Users
can specify alternative option/value delimiters and comment prefixes, change the
name of the *DEFAULT* section or switch the interpolation syntax.

There is support for pluggable interpolation including an additional interpolation
handler :class:`~configparser.ExtendedInterpolation`::

  >>> parser = ConfigParser(interpolation=ExtendedInterpolation())
  >>> parser.read_dict({'buildout': {'directory': '/home/ambv/zope9'},
                        'custom': {'prefix': '/usr/local'}})
  >>> parser.read_string("""
      [buildout]
      parts =
        zope9
        instance
      find-links =
        ${buildout:directory}/downloads/dist

      [zope9]
      recipe = plone.recipe.zope9install
      location = /opt/zope

      [instance]
      recipe = plone.recipe.zope9instance
      zope9-location = ${zope9:location}
      zope-conf = ${custom:prefix}/etc/zope.conf
      """)
  >>> parser['buildout']['find-links']
  '\n/home/ambv/zope9/downloads/dist'
  >>> parser['instance']['zope-conf']
  '/usr/local/etc/zope.conf'
  >>> instance = parser['instance']
  >>> instance['zope-conf']
  '/usr/local/etc/zope.conf'
  >>> instance['zope9-location']
  '/opt/zope'

A number of smaller features were also introduced, like support for specifying
encoding in read operations, specifying fallback values for get-functions, or
reading directly from dictionaries and strings.

(All changes contributed by Łukasz Langa.)

.. XXX consider showing a difflib example

urllib.parse
------------

A number of usability improvements were made for the :mod:`urllib.parse` module.

The :func:`~urllib.parse.urlparse` function now supports `IPv6
<http://en.wikipedia.org/wiki/IPv6>`_ addresses as described in :rfc:`2732`:

    >>> import urllib.parse
    >>> urllib.parse.urlparse('http://[dead:beef:cafe:5417:affe:8FA3:deaf:feed]/foo/')
    ParseResult(scheme='http',
                netloc='[dead:beef:cafe:5417:affe:8FA3:deaf:feed]',
                path='/foo/',
                params='',
                query='',
                fragment='')

The :func:`~urllib.parse.urldefrag` function now returns a :term:`named tuple`::

    >>> r = urllib.parse.urldefrag('http://python.org/about/#target')
    >>> r
    DefragResult(url='http://python.org/about/', fragment='target')
    >>> r[0]
    'http://python.org/about/'
    >>> r.fragment
    'target'

And, the :func:`~urllib.parse.urlencode` function is now much more flexible,
accepting either a string or bytes type for the *query* argument.  If it is a
string, then the *safe*, *encoding*, and *error* parameters are sent to
:func:`~urllib.parse.quote_plus` for encoding::

    >>> urllib.parse.urlencode([
             ('type', 'telenovela'),
             ('name', '¿Dónde Está Elisa?')],
             encoding='latin-1')
    'type=telenovela&name=%BFD%F3nde+Est%E1+Elisa%3F'

As detailed in :ref:`parsing-ascii-encoded-bytes`, all the :mod:`urllib.parse`
functions now accept ASCII-encoded byte strings as input, so long as they are
not mixed with regular strings.  If ASCII-encoded byte strings are given as
parameters, the return types will also be an ASCII-encoded byte strings:

    >>> urllib.parse.urlparse(b'http://www.python.org:80/about/')
    ParseResultBytes(scheme=b'http', netloc=b'www.python.org:80',
                     path=b'/about/', params=b'', query=b'', fragment=b'')

(Work by Nick Coghlan, Dan Mahn, and Senthil Kumaran in :issue:`2987`,
:issue:`5468`, and :issue:`9873`.)

mailbox
-------

Thanks to a concerted effort by R. David Murray, the :mod:`mailbox` module has
been fixed for Python 3.2.  The challenge was that mailbox had been originally
designed with a text interface, but email messages are best represented with
:class:`bytes` because various parts of a message may have different encodings.

The solution harnessed the :mod:`email` package's binary support for parsing
arbitrary email messages.  In addition, the solution required a number of API
changes.

As expected, the :meth:`~mailbox.Mailbox.add` method for
:class:`mailbox.Mailbox` objects now accepts binary input.

:class:`~io.StringIO` and text file input are deprecated.  Also, string input
will fail early if non-ASCII characters are used.  Previously it would fail when
the email was processed in a later step.

There is also support for binary output.  The :meth:`~mailbox.Mailbox.get_file`
method now returns a file in the binary mode (where it used to incorrectly set
the file to text-mode).  There is also a new :meth:`~mailbox.Mailbox.get_bytes`
method that returns a :class:`bytes` representation of a message corresponding
to a given *key*.

It is still possible to get non-binary output using the old API's
:meth:`~mailbox.Mailbox.get_string` method, but that approach
is not very useful.  Instead, it is best to extract messages from
a :class:`~mailbox.Message` object or to load them from binary input.

(Contributed by R. David Murray, with efforts from Steffen Daode Nurpmeso and an
initial patch by Victor Stinner in :issue:`9124`.)

turtledemo
----------

The demonstration code for the :mod:`turtle` module was moved from the *Demo*
directory to main library.  It includes over a dozen sample scripts with
lively displays.  Being on :attr:`sys.path`, it can now be run directly
from the command-line::

    $ python -m turtledemo

(Moved from the Demo directory by Alexander Belopolsky in :issue:`10199`.)

Multi-threading
===============

* The mechanism for serializing execution of concurrently running Python threads
  (generally known as the :term:`GIL` or :term:`Global Interpreter Lock`) has
  been rewritten.  Among the objectives were more predictable switching
  intervals and reduced overhead due to lock contention and the number of
  ensuing system calls.  The notion of a "check interval" to allow thread
  switches has been abandoned and replaced by an absolute duration expressed in
  seconds.  This parameter is tunable through :func:`sys.setswitchinterval()`.
  It currently defaults to 5 milliseconds.

  Additional details about the implementation can be read from a `python-dev
  mailing-list message
  <http://mail.python.org/pipermail/python-dev/2009-October/093321.html>`_
  (however, "priority requests" as exposed in this message have not been kept
  for inclusion).

  (Contributed by Antoine Pitrou.)

* Regular and recursive locks now accept an optional *timeout* argument to their
  :meth:`~threading.Lock.acquire` method.  (Contributed by Antoine Pitrou;
  :issue:`7316`.)

* Similarly, :meth:`threading.Semaphore.acquire` also gained a *timeout*
  argument.  (Contributed by Torsten Landschoff; :issue:`850728`.)

* Regular and recursive lock acquisitions can now be interrupted by signals on
  platforms using Pthreads.  This means that Python programs that deadlock while
  acquiring locks can be successfully killed by repeatedly sending SIGINT to the
  process (by pressing :kbd:`Ctrl+C` in most shells).
  (Contributed by Reid Kleckner; :issue:`8844`.)


Optimizations
=============

A number of small performance enhancements have been added:

* Python's peephole optimizer now recognizes patterns such ``x in {1, 2, 3}`` as
  being a test for membership in a set of constants.  The optimizer recasts the
  :class:`set` as a :class:`frozenset` and stores the pre-built constant.

  Now that the speed penalty is gone, it is practical to start writing
  membership tests using set-notation.  This style is both semantically clear
  and operationally fast::

      extension = name.rpartition('.')[2]
      if extension in {'xml', 'html', 'xhtml', 'css'}:
          handle(name)

  (Patch and additional tests contributed by Dave Malcolm; :issue:`6690`).

* Serializing and unserializing data using the :mod:`pickle` module is now
  several times faster.

  (Contributed by Alexandre Vassalotti, Antoine Pitrou
  and the Unladen Swallow team in :issue:`9410` and :issue:`3873`.)

* The `Timsort algorithm <http://en.wikipedia.org/wiki/Timsort>`_ used in
  :meth:`list.sort` and :func:`sorted` now runs faster and uses less memory
  when called with a :term:`key function`.  Previously, every element of
  a list was wrapped with a temporary object that remembered the key value
  associated with each element.  Now, two arrays of keys and values are
  sorted in parallel.  This saves the memory consumed by the sort wrappers,
  and it saves time lost to delegating comparisons.

  (Patch by Daniel Stutzbach in :issue:`9915`.)

* JSON decoding performance is improved and memory consumption is reduced
  whenever the same string is repeated for multiple keys.  Also, JSON encoding
  now uses the C speedups when the ``sort_keys`` argument is true.

  (Contributed by Antoine Pitrou in :issue:`7451` and by Raymond Hettinger and
  Antoine Pitrou in :issue:`10314`.)

* Recursive locks (created with the :func:`threading.RLock` API) now benefit
  from a C implementation which makes them as fast as regular locks, and between
  10x and 15x faster than their previous pure Python implementation.

  (Contributed by Antoine Pitrou; :issue:`3001`.)

* The fast-search algorithm in stringlib is now used by the :meth:`split`,
  :meth:`rsplit`, :meth:`splitlines` and :meth:`replace` methods on
  :class:`bytes`, :class:`bytearray` and :class:`str` objects. Likewise, the
  algorithm is also used by :meth:`rfind`, :meth:`rindex`, :meth:`rsplit` and
  :meth:`rpartition`.

  (Patch by Florent Xicluna in :issue:`7622` and :issue:`7462`.)


* Integer to string conversions now work two "digits" at a time, reducing the
  number of division and modulo operations.

  (:issue:`6713` by Gawain Bolton, Mark Dickinson, and Victor Stinner.)

There were several other minor optimizations. Set differencing now runs faster
when one operand is much larger than the other (patch by Andress Bennetts in
:issue:`8685`).  The :meth:`array.repeat` method has a faster implementation
(:issue:`1569291` by Alexander Belopolsky). The :class:`BaseHTTPRequestHandler`
has more efficient buffering (:issue:`3709` by Andrew Schaaf).  The
:func:`operator.attrgetter` function has been sped-up (:issue:`10160` by
Christos Georgiou).  And :class:`ConfigParser` loads multi-line arguments a bit
faster (:issue:`7113` by Łukasz Langa).


Unicode
=======

Python has been updated to `Unicode 6.0.0
<http://unicode.org/versions/Unicode6.0.0/>`_.  The update to the standard adds
over 2,000 new characters including `emoji <http://en.wikipedia.org/wiki/Emoji>`_
symbols which are important for mobile phones.

In addition, the updated standard has altered the character properties for two
Kannada characters (U+0CF1, U+0CF2) and one New Tai Lue numeric character
(U+19DA), making the former eligible for use in identifiers while disqualifying
the latter.  For more information, see `Unicode Character Database Changes
<http://www.unicode.org/versions/Unicode6.0.0/#Database_Changes>`_.


Codecs
======

Support was added for *cp720* Arabic DOS encoding (:issue:`1616979`).

MBCS encoding no longer ignores the error handler argument. In the default
strict mode, it raises an :exc:`UnicodeDecodeError` when it encounters an
undecodable byte sequence and an :exc:`UnicodeEncodeError` for an unencodable
character.

The MBCS codec supports ``'strict'`` and ``'ignore'`` error handlers for
decoding, and ``'strict'`` and ``'replace'`` for encoding.

To emulate Python3.1 MBCS encoding, select the ``'ignore'`` handler for decoding
and the ``'replace'`` handler for encoding.

On Mac OS X, Python decodes command line arguments with ``'utf-8'`` rather than
the locale encoding.

By default, :mod:`tarfile` uses ``'utf-8'`` encoding on Windows (instead of
``'mbcs'``) and the ``'surrogateescape'`` error handler on all operating
systems.


Documentation
=============

The documentation continues to be improved.

* A table of quick links has been added to the top of lengthy sections such as
  :ref:`built-in-funcs`.  In the case of :mod:`itertools`, the links are
  accompanied by tables of cheatsheet-style summaries to provide an overview and
  memory jog without having to read all of the docs.

* In some cases, the pure Python source code can be a helpful adjunct to the
  documentation, so now many modules now feature quick links to the latest
  version of the source code.  For example, the :mod:`functools` module
  documentation has a quick link at the top labeled:

    **Source code** :source:`Lib/functools.py`.

  (Contributed by Raymond Hettinger; see
  `rationale <http://rhettinger.wordpress.com/2011/01/28/open-your-source-more/>`_.)

* The docs now contain more examples and recipes.  In particular, :mod:`re`
  module has an extensive section, :ref:`re-examples`.  Likewise, the
  :mod:`itertools` module continues to be updated with new
  :ref:`itertools-recipes`.

* The :mod:`datetime` module now has an auxiliary implementation in pure Python.
  No functionality was changed.  This just provides an easier-to-read alternate
  implementation.

  (Contributed by Alexander Belopolsky in :issue:`9528`.)

* The unmaintained :file:`Demo` directory has been removed.  Some demos were
  integrated into the documentation, some were moved to the :file:`Tools/demo`
  directory, and others were removed altogether.

  (Contributed by Georg Brandl in :issue:`7962`.)


IDLE
====

* The format menu now has an option to clean source files by stripping
  trailing whitespace.

  (Contributed by Raymond Hettinger; :issue:`5150`.)

* IDLE on Mac OS X now works with both Carbon AquaTk and Cocoa AquaTk.

  (Contributed by Kevin Walzer, Ned Deily, and Ronald Oussoren; :issue:`6075`.)

Code Repository
===============

In addition to the existing Subversion code repository at http://svn.python.org
there is now a `Mercurial <http://mercurial.selenic.com/>`_ repository at
http://hg.python.org/ .

After the 3.2 release, there are plans to switch to Mercurial as the primary
repository.  This distributed version control system should make it easier for
members of the community to create and share external changesets.  See
:pep:`385` for details.

To learn to use the new version control system, see the `tutorial by Joel
Spolsky <http://hginit.com>`_ or the `Guide to Mercurial Workflows
<http://mercurial.selenic.com/guide/>`_.


Build and C API Changes
=======================

Changes to Python's build process and to the C API include:

* The *idle*, *pydoc* and *2to3* scripts are now installed with a
  version-specific suffix on ``make altinstall`` (:issue:`10679`).

* The C functions that access the Unicode Database now accept and return
  characters from the full Unicode range, even on narrow unicode builds
  (Py_UNICODE_TOLOWER, Py_UNICODE_ISDECIMAL, and others).  A visible difference
  in Python is that :func:`unicodedata.numeric` now returns the correct value
  for large code points, and :func:`repr` may consider more characters as
  printable.

  (Reported by Bupjoe Lee and fixed by Amaury Forgeot D'Arc; :issue:`5127`.)

* Computed gotos are now enabled by default on supported compilers (which are
  detected by the configure script).  They can still be disabled selectively by
  specifying ``--without-computed-gotos``.

  (Contributed by Antoine Pitrou; :issue:`9203`.)

* The option ``--with-wctype-functions`` was removed.  The built-in unicode
  database is now used for all functions.

  (Contributed by Amaury Forgeot D'Arc; :issue:`9210`.)

* Hash values are now values of a new type, :c:type:`Py_hash_t`, which is
  defined to be the same size as a pointer.  Previously they were of type long,
  which on some 64-bit operating systems is still only 32 bits long.  As a
  result of this fix, :class:`set` and :class:`dict` can now hold more than
  ``2**32`` entries on builds with 64-bit pointers (previously, they could grow
  to that size but their performance degraded catastrophically).

  (Suggested by Raymond Hettinger and implemented by Benjamin Peterson;
  :issue:`9778`.)

* A new macro :c:macro:`Py_VA_COPY` copies the state of the variable argument
  list.  It is equivalent to C99 *va_copy* but available on all Python platforms
  (:issue:`2443`).

* A new C API function :c:func:`PySys_SetArgvEx` allows an embedded interpreter
  to set :attr:`sys.argv` without also modifying :attr:`sys.path`
  (:issue:`5753`).

* :c:macro:`PyEval_CallObject` is now only available in macro form.  The
  function declaration, which was kept for backwards compatibility reasons, is
  now removed -- the macro was introduced in 1997 (:issue:`8276`).

* There is a new function :c:func:`PyLong_AsLongLongAndOverflow` which
  is analogous to :c:func:`PyLong_AsLongAndOverflow`.  They both serve to
  convert Python :class:`int` into a native fixed-width type while providing
  detection of cases where the conversion won't fit (:issue:`7767`).

* The :c:func:`PyUnicode_CompareWithASCIIString` function now returns *not
  equal* if the Python string is *NUL* terminated.

* There is a new function :c:func:`PyErr_NewExceptionWithDoc` that is
  like :c:func:`PyErr_NewException` but allows a docstring to be specified.
  This lets C exceptions have the same self-documenting capabilities as
  their pure Python counterparts (:issue:`7033`).

* When compiled with the ``--with-valgrind`` option, the pymalloc
  allocator will be automatically disabled when running under Valgrind.  This
  gives improved memory leak detection when running under Valgrind, while taking
  advantage of pymalloc at other times (:issue:`2422`).

* Removed the ``O?`` format from the *PyArg_Parse* functions.  The format is no
  longer used and it had never been documented (:issue:`8837`).

There were a number of other small changes to the C-API.  See the
:source:`Misc/NEWS` file for a complete list.

Also, there were a number of updates to the Mac OS X build, see
:source:`Mac/BuildScript/README.txt` for details.  For users running a 32/64-bit
build, there is a known problem with the default Tcl/Tk on Mac OS X 10.6.
Accordingly, we recommend installing an updated alternative such as
`ActiveState Tcl/Tk 8.5.9 <http://www.activestate.com/activetcl/downloads>`_\.
See http://www.python.org/download/mac/tcltk/ for additional details.

Porting to Python 3.2
=====================

This section lists previously described changes and other bugfixes that may
require changes to your code:

* The :mod:`configparser` module has a number of clean-ups.  The major change is
  to replace the old :class:`ConfigParser` class with long-standing preferred
  alternative :class:`SafeConfigParser`.  In addition there are a number of
  smaller incompatibilities:

  * The interpolation syntax is now validated on
    :meth:`~configparser.ConfigParser.get` and
    :meth:`~configparser.ConfigParser.set` operations. In the default
    interpolation scheme, only two tokens with percent signs are valid: ``%(name)s``
    and ``%%``, the latter being an escaped percent sign.

  * The :meth:`~configparser.ConfigParser.set` and
    :meth:`~configparser.ConfigParser.add_section` methods now verify that
    values are actual strings.  Formerly, unsupported types could be introduced
    unintentionally.

  * Duplicate sections or options from a single source now raise either
    :exc:`~configparser.DuplicateSectionError` or
    :exc:`~configparser.DuplicateOptionError`.  Formerly, duplicates would
    silently overwrite a previous entry.

  * Inline comments are now disabled by default so now the **;** character
    can be safely used in values.

  * Comments now can be indented.  Consequently, for **;** or **#** to appear at
    the start of a line in multiline values, it has to be interpolated.  This
    keeps comment prefix characters in values from being mistaken as comments.

  * ``""`` is now a valid value and is no longer automatically converted to an
    empty string. For empty strings, use ``"option ="`` in a line.

* The :mod:`nntplib` module was reworked extensively, meaning that its APIs
  are often incompatible with the 3.1 APIs.

* :class:`bytearray` objects can no longer be used as filenames; instead,
  they should be converted to :class:`bytes`.

* The :meth:`array.tostring` and :meth:`array.fromstring` have been renamed to
  :meth:`array.tobytes` and :meth:`array.frombytes` for clarity.  The old names
  have been deprecated. (See :issue:`8990`.)

* ``PyArg_Parse*()`` functions:

  * "t#" format has been removed: use "s#" or "s*" instead
  * "w" and "w#" formats has been removed: use "w*" instead

* The :c:type:`PyCObject` type, deprecated in 3.1, has been removed.  To wrap
  opaque C pointers in Python objects, the :c:type:`PyCapsule` API should be used
  instead; the new type has a well-defined interface for passing typing safety
  information and a less complicated signature for calling a destructor.

* The :func:`sys.setfilesystemencoding` function was removed because
  it had a flawed design.

* The :func:`random.seed` function and method now salt string seeds with an
  sha512 hash function.  To access the previous version of *seed* in order to
  reproduce Python 3.1 sequences, set the *version* argument to *1*,
  ``random.seed(s, version=1)``.

* The previously deprecated :func:`string.maketrans` function has been removed
  in favor of the static methods :meth:`bytes.maketrans` and
  :meth:`bytearray.maketrans`.  This change solves the confusion around which
  types were supported by the :mod:`string` module.  Now, :class:`str`,
  :class:`bytes`, and :class:`bytearray` each have their own **maketrans** and
  **translate** methods with intermediate translation tables of the appropriate
  type.

  (Contributed by Georg Brandl; :issue:`5675`.)

* The previously deprecated :func:`contextlib.nested` function has been removed
  in favor of a plain :keyword:`with` statement which can accept multiple
  context managers.  The latter technique is faster (because it is built-in),
  and it does a better job finalizing multiple context managers when one of them
  raises an exception::

    with open('mylog.txt') as infile, open('a.out', 'w') as outfile:
        for line in infile:
            if '<critical>' in line:
                outfile.write(line)

  (Contributed by Georg Brandl and Mattias Brändström;
  `appspot issue 53094 <http://codereview.appspot.com/53094>`_.)

* :func:`struct.pack` now only allows bytes for the ``s`` string pack code.
  Formerly, it would accept text arguments and implicitly encode them to bytes
  using UTF-8.  This was problematic because it made assumptions about the
  correct encoding and because a variable-length encoding can fail when writing
  to fixed length segment of a structure.

  Code such as ``struct.pack('<6sHHBBB', 'GIF87a', x, y)`` should be rewritten
  with to use bytes instead of text, ``struct.pack('<6sHHBBB', b'GIF87a', x, y)``.

  (Discovered by David Beazley and fixed by Victor Stinner; :issue:`10783`.)

* The :class:`xml.etree.ElementTree` class now raises an
  :exc:`xml.etree.ElementTree.ParseError` when a parse fails. Previously it
  raised a :exc:`xml.parsers.expat.ExpatError`.

* The new, longer :func:`str` value on floats may break doctests which rely on
  the old output format.

* In :class:`subprocess.Popen`, the default value for *close_fds* is now
  ``True`` under Unix; under Windows, it is ``True`` if the three standard
  streams are set to ``None``, ``False`` otherwise.  Previously, *close_fds*
  was always ``False`` by default, which produced difficult to solve bugs
  or race conditions when open file descriptors would leak into the child
  process.

* Support for legacy HTTP 0.9 has been removed from :mod:`urllib.request`
  and :mod:`http.client`.  Such support is still present on the server side
  (in :mod:`http.server`).

  (Contributed by Antoine Pitrou, :issue:`10711`.)

* SSL sockets in timeout mode now raise :exc:`socket.timeout` when a timeout
  occurs, rather than a generic :exc:`~ssl.SSLError`.

  (Contributed by Antoine Pitrou, :issue:`10272`.)

* The misleading functions :c:func:`PyEval_AcquireLock()` and
  :c:func:`PyEval_ReleaseLock()` have been officially deprecated.  The
  thread-state aware APIs (such as :c:func:`PyEval_SaveThread()`
  and :c:func:`PyEval_RestoreThread()`) should be used instead.

* Due to security risks, :func:`asyncore.handle_accept` has been deprecated, and
  a new function, :func:`asyncore.handle_accepted`, was added to replace it.

  (Contributed by Giampaolo Rodola in :issue:`6706`.)

* Due to the new :term:`GIL` implementation, :c:func:`PyEval_InitThreads()`
  cannot be called before :c:func:`Py_Initialize()` anymore.


****************************
  What's New In Python 3.1
****************************


PEP 372: Ordered Dictionaries
=============================

Regular Python dictionaries iterate over key/value pairs in arbitrary order.
Over the years, a number of authors have written alternative implementations
that remember the order that the keys were originally inserted.  Based on
the experiences from those implementations, a new
:class:`collections.OrderedDict` class has been introduced.

The OrderedDict API is substantially the same as regular dictionaries
but will iterate over keys and values in a guaranteed order depending on
when a key was first inserted.  If a new entry overwrites an existing entry,
the original insertion position is left unchanged.  Deleting an entry and
reinserting it will move it to the end.

The standard library now supports use of ordered dictionaries in several
modules.  The :mod:`configparser` module uses them by default.  This lets
configuration files be read, modified, and then written back in their original
order.  The *_asdict()* method for :func:`collections.namedtuple` now
returns an ordered dictionary with the values appearing in the same order as
the underlying tuple indicies.  The :mod:`json` module is being built-out with
an *object_pairs_hook* to allow OrderedDicts to be built by the decoder.
Support was also added for third-party tools like `PyYAML <http://pyyaml.org/>`_.

.. seealso::

   :pep:`372` - Ordered Dictionaries
      PEP written by Armin Ronacher and Raymond Hettinger.  Implementation
      written by Raymond Hettinger.


PEP 378: Format Specifier for Thousands Separator
=================================================

The built-in :func:`format` function and the :meth:`str.format` method use
a mini-language that now includes a simple, non-locale aware way to format
a number with a thousands separator.  That provides a way to humanize a
program's output, improving its professional appearance and readability::

    >>> format(1234567, ',d')
    '1,234,567'
    >>> format(1234567.89, ',.2f')
    '1,234,567.89'
    >>> format(12345.6 + 8901234.12j, ',f')
    '12,345.600000+8,901,234.120000j'
    >>> format(Decimal('1234567.89'), ',f')
    '1,234,567.89'

The supported types are :class:`int`, :class:`float`, :class:`complex`
and :class:`decimal.Decimal`.

Discussions are underway about how to specify alternative separators
like dots, spaces, apostrophes, or underscores.  Locale-aware applications
should use the existing *n* format specifier which already has some support
for thousands separators.

.. seealso::

   :pep:`378` - Format Specifier for Thousands Separator
      PEP written by Raymond Hettinger and implemented by Eric Smith and
      Mark Dickinson.


Other Language Changes
======================

Some smaller changes made to the core Python language are:

* Directories and zip archives containing a :file:`__main__.py`
  file can now be executed directly by passing their name to the
  interpreter. The directory/zipfile is automatically inserted as the
  first entry in sys.path.  (Suggestion and initial patch by Andy Chu;
  revised patch by Phillip J. Eby and Nick Coghlan; :issue:`1739468`.)

* The :func:`int` type gained a ``bit_length`` method that returns the
  number of bits necessary to represent its argument in binary::

      >>> n = 37
      >>> bin(37)
      '0b100101'
      >>> n.bit_length()
      6
      >>> n = 2**123-1
      >>> n.bit_length()
      123
      >>> (n+1).bit_length()
      124

  (Contributed by Fredrik Johansson, Victor Stinner, Raymond Hettinger,
  and Mark Dickinson; :issue:`3439`.)

* The fields in :func:`format` strings can now be automatically
  numbered::

    >>> 'Sir {} of {}'.format('Gallahad', 'Camelot')
    'Sir Gallahad of Camelot'

  Formerly, the string would have required numbered fields such as:
  ``'Sir {0} of {1}'``.

  (Contributed by Eric Smith; :issue:`5237`.)

* The :func:`string.maketrans` function is deprecated and is replaced by new
  static methods, :meth:`bytes.maketrans` and :meth:`bytearray.maketrans`.
  This change solves the confusion around which types were supported by the
  :mod:`string` module. Now, :class:`str`, :class:`bytes`, and
  :class:`bytearray` each have their own **maketrans** and **translate**
  methods with intermediate translation tables of the appropriate type.

  (Contributed by Georg Brandl; :issue:`5675`.)

* The syntax of the :keyword:`with` statement now allows multiple context
  managers in a single statement::

    >>> with open('mylog.txt') as infile, open('a.out', 'w') as outfile:
    ...     for line in infile:
    ...         if '<critical>' in line:
    ...             outfile.write(line)

  With the new syntax, the :func:`contextlib.nested` function is no longer
  needed and is now deprecated.

  (Contributed by Georg Brandl and Mattias Brändström;
  `appspot issue 53094 <http://codereview.appspot.com/53094>`_.)

* ``round(x, n)`` now returns an integer if *x* is an integer.
  Previously it returned a float::

    >>> round(1123, -2)
    1100

  (Contributed by Mark Dickinson; :issue:`4707`.)

* Python now uses David Gay's algorithm for finding the shortest floating
  point representation that doesn't change its value.  This should help
  mitigate some of the confusion surrounding binary floating point
  numbers.

  The significance is easily seen with a number like ``1.1`` which does not
  have an exact equivalent in binary floating point.  Since there is no exact
  equivalent, an expression like ``float('1.1')`` evaluates to the nearest
  representable value which is ``0x1.199999999999ap+0`` in hex or
  ``1.100000000000000088817841970012523233890533447265625`` in decimal. That
  nearest value was and still is used in subsequent floating point
  calculations.

  What is new is how the number gets displayed.  Formerly, Python used a
  simple approach.  The value of ``repr(1.1)`` was computed as ``format(1.1,
  '.17g')`` which evaluated to ``'1.1000000000000001'``. The advantage of
  using 17 digits was that it relied on IEEE-754 guarantees to assure that
  ``eval(repr(1.1))`` would round-trip exactly to its original value.  The
  disadvantage is that many people found the output to be confusing (mistaking
  intrinsic limitations of binary floating point representation as being a
  problem with Python itself).

  The new algorithm for ``repr(1.1)`` is smarter and returns ``'1.1'``.
  Effectively, it searches all equivalent string representations (ones that
  get stored with the same underlying float value) and returns the shortest
  representation.

  The new algorithm tends to emit cleaner representations when possible, but
  it does not change the underlying values.  So, it is still the case that
  ``1.1 + 2.2 != 3.3`` even though the representations may suggest otherwise.

  The new algorithm depends on certain features in the underlying floating
  point implementation.  If the required features are not found, the old
  algorithm will continue to be used.  Also, the text pickle protocols
  assure cross-platform portability by using the old algorithm.

  (Contributed by Eric Smith and Mark Dickinson; :issue:`1580`)

New, Improved, and Deprecated Modules
=====================================

* Added a :class:`collections.Counter` class to support convenient
  counting of unique items in a sequence or iterable::

      >>> Counter(['red', 'blue', 'red', 'green', 'blue', 'blue'])
      Counter({'blue': 3, 'red': 2, 'green': 1})

  (Contributed by Raymond Hettinger; :issue:`1696199`.)

* Added a new module, :mod:`tkinter.ttk` for access to the Tk themed widget set.
  The basic idea of ttk is to separate, to the extent possible, the code
  implementing a widget's behavior from the code implementing its appearance.

  (Contributed by Guilherme Polo; :issue:`2983`.)

* The :class:`gzip.GzipFile` and :class:`bz2.BZ2File` classes now support
  the context manager protocol::

        >>> # Automatically close file after writing
        >>> with gzip.GzipFile(filename, "wb") as f:
        ...     f.write(b"xxx")

  (Contributed by Antoine Pitrou.)

* The :mod:`decimal` module now supports methods for creating a
  decimal object from a binary :class:`float`.  The conversion is
  exact but can sometimes be surprising::

      >>> Decimal.from_float(1.1)
      Decimal('1.100000000000000088817841970012523233890533447265625')

  The long decimal result shows the actual binary fraction being
  stored for *1.1*.  The fraction has many digits because *1.1* cannot
  be exactly represented in binary.

  (Contributed by Raymond Hettinger and Mark Dickinson.)

* The :mod:`itertools` module grew two new functions.  The
  :func:`itertools.combinations_with_replacement` function is one of
  four for generating combinatorics including permutations and Cartesian
  products.  The :func:`itertools.compress` function mimics its namesake
  from APL.  Also, the existing :func:`itertools.count` function now has
  an optional *step* argument and can accept any type of counting
  sequence including :class:`fractions.Fraction` and
  :class:`decimal.Decimal`::

    >>> [p+q for p,q in combinations_with_replacement('LOVE', 2)]
    ['LL', 'LO', 'LV', 'LE', 'OO', 'OV', 'OE', 'VV', 'VE', 'EE']

    >>> list(compress(data=range(10), selectors=[0,0,1,1,0,1,0,1,0,0]))
    [2, 3, 5, 7]

    >>> c = count(start=Fraction(1,2), step=Fraction(1,6))
    >>> [next(c), next(c), next(c), next(c)]
    [Fraction(1, 2), Fraction(2, 3), Fraction(5, 6), Fraction(1, 1)]

  (Contributed by Raymond Hettinger.)

* :func:`collections.namedtuple` now supports a keyword argument
  *rename* which lets invalid fieldnames be automatically converted to
  positional names in the form _0, _1, etc.  This is useful when
  the field names are being created by an external source such as a
  CSV header, SQL field list, or user input::

    >>> query = input()
    SELECT region, dept, count(*) FROM main GROUPBY region, dept

    >>> cursor.execute(query)
    >>> query_fields = [desc[0] for desc in cursor.description]
    >>> UserQuery = namedtuple('UserQuery', query_fields, rename=True)
    >>> pprint.pprint([UserQuery(*row) for row in cursor])
    [UserQuery(region='South', dept='Shipping', _2=185),
     UserQuery(region='North', dept='Accounting', _2=37),
     UserQuery(region='West', dept='Sales', _2=419)]

  (Contributed by Raymond Hettinger; :issue:`1818`.)

* The :func:`re.sub`, :func:`re.subn` and :func:`re.split` functions now
  accept a flags parameter.

  (Contributed by Gregory Smith.)

* The :mod:`logging` module now implements a simple :class:`logging.NullHandler`
  class for applications that are not using logging but are calling
  library code that does.  Setting-up a null handler will suppress
  spurious warnings such as "No handlers could be found for logger foo"::

    >>> h = logging.NullHandler()
    >>> logging.getLogger("foo").addHandler(h)

  (Contributed by Vinay Sajip; :issue:`4384`).

* The :mod:`runpy` module which supports the ``-m`` command line switch
  now supports the execution of packages by looking for and executing
  a ``__main__`` submodule when a package name is supplied.

  (Contributed by Andi Vajda; :issue:`4195`.)

* The :mod:`pdb` module can now access and display source code loaded via
  :mod:`zipimport` (or any other conformant :pep:`302` loader).

  (Contributed by Alexander Belopolsky; :issue:`4201`.)

*  :class:`functools.partial` objects can now be pickled.

  (Suggested by Antoine Pitrou and Jesse Noller.  Implemented by
  Jack Diederich; :issue:`5228`.)

* Add :mod:`pydoc` help topics for symbols so that ``help('@')``
  works as expected in the interactive environment.

  (Contributed by David Laban; :issue:`4739`.)

* The :mod:`unittest` module now supports skipping individual tests or classes
  of tests. And it supports marking a test as a expected failure, a test that
  is known to be broken, but shouldn't be counted as a failure on a
  TestResult::

    class TestGizmo(unittest.TestCase):

        @unittest.skipUnless(sys.platform.startswith("win"), "requires Windows")
        def test_gizmo_on_windows(self):
            ...

        @unittest.expectedFailure
        def test_gimzo_without_required_library(self):
            ...

  Also, tests for exceptions have been builtout to work with context managers
  using the :keyword:`with` statement::

      def test_division_by_zero(self):
          with self.assertRaises(ZeroDivisionError):
              x / 0

  In addition, several new assertion methods were added including
  :func:`assertSetEqual`, :func:`assertDictEqual`,
  :func:`assertDictContainsSubset`, :func:`assertListEqual`,
  :func:`assertTupleEqual`, :func:`assertSequenceEqual`,
  :func:`assertRaisesRegexp`, :func:`assertIsNone`,
  and :func:`assertIsNotNone`.

  (Contributed by Benjamin Peterson and Antoine Pitrou.)

* The :mod:`io` module has three new constants for the :meth:`seek`
  method :data:`SEEK_SET`, :data:`SEEK_CUR`, and :data:`SEEK_END`.

* The :attr:`sys.version_info` tuple is now a named tuple::

    >>> sys.version_info
    sys.version_info(major=3, minor=1, micro=0, releaselevel='alpha', serial=2)

  (Contributed by Ross Light; :issue:`4285`.)

* The :mod:`nntplib` and :mod:`imaplib` modules now support IPv6.

  (Contributed by Derek Morr; :issue:`1655` and :issue:`1664`.)

* The :mod:`pickle` module has been adapted for better interoperability with
  Python 2.x when used with protocol 2 or lower.  The reorganization of the
  standard library changed the formal reference for many objects.  For
  example, ``__builtin__.set`` in Python 2 is called ``builtins.set`` in Python
  3. This change confounded efforts to share data between different versions of
  Python.  But now when protocol 2 or lower is selected, the pickler will
  automatically use the old Python 2 names for both loading and dumping. This
  remapping is turned-on by default but can be disabled with the *fix_imports*
  option::

    >>> s = {1, 2, 3}
    >>> pickle.dumps(s, protocol=0)
    b'c__builtin__\nset\np0\n((lp1\nL1L\naL2L\naL3L\natp2\nRp3\n.'
    >>> pickle.dumps(s, protocol=0, fix_imports=False)
    b'cbuiltins\nset\np0\n((lp1\nL1L\naL2L\naL3L\natp2\nRp3\n.'

  An unfortunate but unavoidable side-effect of this change is that protocol 2
  pickles produced by Python 3.1 won't be readable with Python 3.0. The latest
  pickle protocol, protocol 3, should be used when migrating data between
  Python 3.x implementations, as it doesn't attempt to remain compatible with
  Python 2.x.

  (Contributed by Alexandre Vassalotti and Antoine Pitrou, :issue:`6137`.)

* A new module, :mod:`importlib` was added.  It provides a complete, portable,
  pure Python reference implementation of the :keyword:`import` statement and its
  counterpart, the :func:`__import__` function.  It represents a substantial
  step forward in documenting and defining the actions that take place during
  imports.

  (Contributed by Brett Cannon.)

Optimizations
=============

Major performance enhancements have been added:

* The new I/O library (as defined in :pep:`3116`) was mostly written in
  Python and quickly proved to be a problematic bottleneck in Python 3.0.
  In Python 3.1, the I/O library has been entirely rewritten in C and is
  2 to 20 times faster depending on the task at hand. The pure Python
  version is still available for experimentation purposes through
  the ``_pyio`` module.

  (Contributed by Amaury Forgeot d'Arc and Antoine Pitrou.)

* Added a heuristic so that tuples and dicts containing only untrackable objects
  are not tracked by the garbage collector. This can reduce the size of
  collections and therefore the garbage collection overhead on long-running
  programs, depending on their particular use of datatypes.

  (Contributed by Antoine Pitrou, :issue:`4688`.)

* Enabling a configure option named ``--with-computed-gotos``
  on compilers that support it (notably: gcc, SunPro, icc), the bytecode
  evaluation loop is compiled with a new dispatch mechanism which gives
  speedups of up to 20%, depending on the system, the compiler, and
  the benchmark.

  (Contributed by Antoine Pitrou along with a number of other participants,
  :issue:`4753`).

* The decoding of UTF-8, UTF-16 and LATIN-1 is now two to four times
  faster.

  (Contributed by Antoine Pitrou and Amaury Forgeot d'Arc, :issue:`4868`.)

* The :mod:`json` module now has a C extension to substantially improve
  its performance.  In addition, the API was modified so that json works
  only with :class:`str`, not with :class:`bytes`.  That change makes the
  module closely match the `JSON specification <http://json.org/>`_
  which is defined in terms of Unicode.

  (Contributed by Bob Ippolito and converted to Py3.1 by Antoine Pitrou
  and Benjamin Peterson; :issue:`4136`.)

* Unpickling now interns the attribute names of pickled objects.  This saves
  memory and allows pickles to be smaller.

  (Contributed by Jake McGuire and Antoine Pitrou; :issue:`5084`.)

IDLE
====

* IDLE's format menu now provides an option to strip trailing whitespace
  from a source file.

  (Contributed by Roger D. Serwy; :issue:`5150`.)

Build and C API Changes
=======================

Changes to Python's build process and to the C API include:

* Integers are now stored internally either in base 2**15 or in base
  2**30, the base being determined at build time.  Previously, they
  were always stored in base 2**15.  Using base 2**30 gives
  significant performance improvements on 64-bit machines, but
  benchmark results on 32-bit machines have been mixed.  Therefore,
  the default is to use base 2**30 on 64-bit machines and base 2**15
  on 32-bit machines; on Unix, there's a new configure option
  ``--enable-big-digits`` that can be used to override this default.

  Apart from the performance improvements this change should be invisible to
  end users, with one exception: for testing and debugging purposes there's a
  new :attr:`sys.int_info` that provides information about the
  internal format, giving the number of bits per digit and the size in bytes
  of the C type used to store each digit::

     >>> import sys
     >>> sys.int_info
     sys.int_info(bits_per_digit=30, sizeof_digit=4)

  (Contributed by Mark Dickinson; :issue:`4258`.)

* The :c:func:`PyLong_AsUnsignedLongLong()` function now handles a negative
  *pylong* by raising :exc:`OverflowError` instead of :exc:`TypeError`.

  (Contributed by Mark Dickinson and Lisandro Dalcrin; :issue:`5175`.)

* Deprecated :c:func:`PyNumber_Int`.  Use :c:func:`PyNumber_Long` instead.

  (Contributed by Mark Dickinson; :issue:`4910`.)

* Added a new :c:func:`PyOS_string_to_double` function to replace the
  deprecated functions :c:func:`PyOS_ascii_strtod` and :c:func:`PyOS_ascii_atof`.

  (Contributed by Mark Dickinson; :issue:`5914`.)

* Added :c:type:`PyCapsule` as a replacement for the :c:type:`PyCObject` API.
  The principal difference is that the new type has a well defined interface
  for passing typing safety information and a less complicated signature
  for calling a destructor.  The old type had a problematic API and is now
  deprecated.

  (Contributed by Larry Hastings; :issue:`5630`.)

Porting to Python 3.1
=====================

This section lists previously described changes and other bugfixes
that may require changes to your code:

* The new floating point string representations can break existing doctests.
  For example::

    def e():
        '''Compute the base of natural logarithms.

        >>> e()
        2.7182818284590451

        '''
        return sum(1/math.factorial(x) for x in reversed(range(30)))

    doctest.testmod()

    **********************************************************************
    Failed example:
        e()
    Expected:
        2.7182818284590451
    Got:
        2.718281828459045
    **********************************************************************

* The automatic name remapping in the pickle module for protocol 2 or lower can
  make Python 3.1 pickles unreadable in Python 3.0.  One solution is to use
  protocol 3.  Another solution is to set the *fix_imports* option to **False**.
  See the discussion above for more details.


****************************
  What's New in Python 2.7
****************************

This article explains the new features in Python 2.7.  The final
release of 2.7 is currently scheduled for July 2010; the detailed
schedule is described in :pep:`373`.

Numeric handling has been improved in many ways, for both
floating-point numbers and for the :class:`Decimal` class.  There are
some useful additions to the standard library, such as a greatly
enhanced :mod:`unittest` module, the :mod:`argparse` module for
parsing command-line options, convenient ordered-dictionary and
:class:`Counter` classes in the :mod:`collections` module, and many
other improvements.

Python 2.7 is planned to be the last of the 2.x releases, so we worked
on making it a good release for the long term.  To help with porting
to Python 3, several new features from the Python 3.x series have been
included in 2.7.

This article doesn't attempt to provide a complete specification of
the new features, but instead provides a convenient overview.  For
full details, you should refer to the documentation for Python 2.7 at
http://docs.python.org. If you want to understand the rationale for
the design and implementation, refer to the PEP for a particular new
feature or the issue on http://bugs.python.org in which a change was
discussed.  Whenever possible, "What's New in Python" links to the
bug/patch item for each change.

.. _whatsnew27-python31:

The Future for Python 2.x
=========================

Python 2.7 is intended to be the last major release in the 2.x series.
The Python maintainers are planning to focus their future efforts on
the Python 3.x series.

This means that 2.7 will remain in place for a long time, running
production systems that have not been ported to Python 3.x.
Two consequences of the long-term significance of 2.7 are:

* It's very likely the 2.7 release will have a longer period of
  maintenance compared to earlier 2.x versions.  Python 2.7 will
  continue to be maintained while the transition to 3.x continues, and
  the developers are planning to support Python 2.7 with bug-fix
  releases beyond the typical two years.

* A policy decision was made to silence warnings only of interest to
  developers.  :exc:`DeprecationWarning` and its
  descendants are now ignored unless otherwise requested, preventing
  users from seeing warnings triggered by an application.  This change
  was also made in the branch that will become Python 3.2. (Discussed
  on stdlib-sig and carried out in :issue:`7319`.)

  In previous releases, :exc:`DeprecationWarning` messages were
  enabled by default, providing Python developers with a clear
  indication of where their code may break in a future major version
  of Python.

  However, there are increasingly many users of Python-based
  applications who are not directly involved in the development of
  those applications.  :exc:`DeprecationWarning` messages are
  irrelevant to such users, making them worry about an application
  that's actually working correctly and burdening application developers
  with responding to these concerns.

  You can re-enable display of :exc:`DeprecationWarning` messages by
  running Python with the :option:`-Wdefault` (short form:
  :option:`-Wd`) switch, or by setting the :envvar:`PYTHONWARNINGS`
  environment variable to ``"default"`` (or ``"d"``) before running
  Python.  Python code can also re-enable them
  by calling ``warnings.simplefilter('default')``.


Python 3.1 Features
=======================

Much as Python 2.6 incorporated features from Python 3.0,
version 2.7 incorporates some of the new features
in Python 3.1.  The 2.x series continues to provide tools
for migrating to the 3.x series.

A partial list of 3.1 features that were backported to 2.7:

* The syntax for set literals (``{1,2,3}`` is a mutable set).
* Dictionary and set comprehensions (``{ i: i*2 for i in range(3)}``).
* Multiple context managers in a single :keyword:`with` statement.
* A new version of the :mod:`io` library, rewritten in C for performance.
* The ordered-dictionary type described in :ref:`pep-0372`.
* The new ``","`` format specifier described in :ref:`pep-0378`.
* The :class:`memoryview` object.
* A small subset of the :mod:`importlib` module,
  `described below <#importlib-section>`__.
* The :func:`repr` of a float ``x`` is shorter in many cases: it's now
  based on the shortest decimal string that's guaranteed to round back
  to ``x``.  As in previous versions of Python, it's guaranteed that
  ``float(repr(x))`` recovers ``x``.
* Float-to-string and string-to-float conversions are correctly rounded.
  The :func:`round` function is also now correctly rounded.
* The :c:type:`PyCapsule` type, used to provide a C API for extension modules.
* The :c:func:`PyLong_AsLongAndOverflow` C API function.

Other new Python3-mode warnings include:

* :func:`operator.isCallable` and :func:`operator.sequenceIncludes`,
  which are not supported in 3.x, now trigger warnings.
* The :option:`-3` switch now automatically
  enables the :option:`-Qwarn` switch that causes warnings
  about using classic division with integers and long integers.



.. ========================================================================
.. Large, PEP-level features and changes should be described here.
.. ========================================================================

.. _pep-0372:

PEP 372: Adding an Ordered Dictionary to collections
====================================================

Regular Python dictionaries iterate over key/value pairs in arbitrary order.
Over the years, a number of authors have written alternative implementations
that remember the order that the keys were originally inserted.  Based on
the experiences from those implementations, 2.7 introduces a new
:class:`~collections.OrderedDict` class in the :mod:`collections` module.

The :class:`~collections.OrderedDict` API provides the same interface as regular
dictionaries but iterates over keys and values in a guaranteed order
depending on when a key was first inserted::

    >>> from collections import OrderedDict
    >>> d = OrderedDict([('first', 1),
    ...                  ('second', 2),
    ...                  ('third', 3)])
    >>> d.items()
    [('first', 1), ('second', 2), ('third', 3)]

If a new entry overwrites an existing entry, the original insertion
position is left unchanged::

    >>> d['second'] = 4
    >>> d.items()
    [('first', 1), ('second', 4), ('third', 3)]

Deleting an entry and reinserting it will move it to the end::

    >>> del d['second']
    >>> d['second'] = 5
    >>> d.items()
    [('first', 1), ('third', 3), ('second', 5)]

The :meth:`~collections.OrderedDict.popitem` method has an optional *last*
argument that defaults to True.  If *last* is True, the most recently
added key is returned and removed; if it's False, the
oldest key is selected::

    >>> od = OrderedDict([(x,0) for x in range(20)])
    >>> od.popitem()
    (19, 0)
    >>> od.popitem()
    (18, 0)
    >>> od.popitem(last=False)
    (0, 0)
    >>> od.popitem(last=False)
    (1, 0)

Comparing two ordered dictionaries checks both the keys and values,
and requires that the insertion order was the same::

    >>> od1 = OrderedDict([('first', 1),
    ...                    ('second', 2),
    ...                    ('third', 3)])
    >>> od2 = OrderedDict([('third', 3),
    ...                    ('first', 1),
    ...                    ('second', 2)])
    >>> od1 == od2
    False
    >>> # Move 'third' key to the end
    >>> del od2['third']; od2['third'] = 3
    >>> od1 == od2
    True

Comparing an :class:`~collections.OrderedDict` with a regular dictionary
ignores the insertion order and just compares the keys and values.

How does the :class:`~collections.OrderedDict` work?  It maintains a
doubly-linked list of keys, appending new keys to the list as they're inserted.
A secondary dictionary maps keys to their corresponding list node, so
deletion doesn't have to traverse the entire linked list and therefore
remains O(1).

The standard library now supports use of ordered dictionaries in several
modules.

* The :mod:`ConfigParser` module uses them by default, meaning that
  configuration files can now be read, modified, and then written back
  in their original order.

* The :meth:`~collections.somenamedtuple._asdict()` method for
  :func:`collections.namedtuple` now returns an ordered dictionary with the
  values appearing in the same order as the underlying tuple indices.

* The :mod:`json` module's :class:`~json.JSONDecoder` class
  constructor was extended with an *object_pairs_hook* parameter to
  allow :class:`OrderedDict` instances to be built by the decoder.
  Support was also added for third-party tools like
  `PyYAML <http://pyyaml.org/>`_.

.. seealso::

   :pep:`372` - Adding an ordered dictionary to collections
     PEP written by Armin Ronacher and Raymond Hettinger;
     implemented by Raymond Hettinger.

.. _pep-0378:

PEP 378: Format Specifier for Thousands Separator
=================================================

To make program output more readable, it can be useful to add
separators to large numbers, rendering them as
18,446,744,073,709,551,616 instead of 18446744073709551616.

The fully general solution for doing this is the :mod:`locale` module,
which can use different separators ("," in North America, "." in
Europe) and different grouping sizes, but :mod:`locale` is complicated
to use and unsuitable for multi-threaded applications where different
threads are producing output for different locales.

Therefore, a simple comma-grouping mechanism has been added to the
mini-language used by the :meth:`str.format` method.  When
formatting a floating-point number, simply include a comma between the
width and the precision::

   >>> '{:20,.2f}'.format(18446744073709551616.0)
   '18,446,744,073,709,551,616.00'

When formatting an integer, include the comma after the width:

   >>> '{:20,d}'.format(18446744073709551616)
   '18,446,744,073,709,551,616'

This mechanism is not adaptable at all; commas are always used as the
separator and the grouping is always into three-digit groups.  The
comma-formatting mechanism isn't as general as the :mod:`locale`
module, but it's easier to use.

.. seealso::

   :pep:`378` - Format Specifier for Thousands Separator
     PEP written by Raymond Hettinger; implemented by Eric Smith.

PEP 389: The argparse Module for Parsing Command Lines
======================================================

The :mod:`argparse` module for parsing command-line arguments was
added as a more powerful replacement for the
:mod:`optparse` module.

This means Python now supports three different modules for parsing
command-line arguments: :mod:`getopt`, :mod:`optparse`, and
:mod:`argparse`.  The :mod:`getopt` module closely resembles the C
library's :c:func:`getopt` function, so it remains useful if you're writing a
Python prototype that will eventually be rewritten in C.
:mod:`optparse` becomes redundant, but there are no plans to remove it
because there are many scripts still using it, and there's no
automated way to update these scripts.  (Making the :mod:`argparse`
API consistent with :mod:`optparse`'s interface was discussed but
rejected as too messy and difficult.)

In short, if you're writing a new script and don't need to worry
about compatibility with earlier versions of Python, use
:mod:`argparse` instead of :mod:`optparse`.

Here's an example::

    import argparse

    parser = argparse.ArgumentParser(description='Command-line example.')

    # Add optional switches
    parser.add_argument('-v', action='store_true', dest='is_verbose',
                        help='produce verbose output')
    parser.add_argument('-o', action='store', dest='output',
                        metavar='FILE',
                        help='direct output to FILE instead of stdout')
    parser.add_argument('-C', action='store', type=int, dest='context',
                        metavar='NUM', default=0,
                        help='display NUM lines of added context')

    # Allow any number of additional arguments.
    parser.add_argument(nargs='*', action='store', dest='inputs',
                        help='input filenames (default is stdin)')

    args = parser.parse_args()
    print args.__dict__

Unless you override it, :option:`-h` and :option:`--help` switches
are automatically added, and produce neatly formatted output::

    -> ./python.exe argparse-example.py --help
    usage: argparse-example.py [-h] [-v] [-o FILE] [-C NUM] [inputs [inputs ...]]

    Command-line example.

    positional arguments:
      inputs      input filenames (default is stdin)

    optional arguments:
      -h, --help  show this help message and exit
      -v          produce verbose output
      -o FILE     direct output to FILE instead of stdout
      -C NUM      display NUM lines of added context

As with :mod:`optparse`, the command-line switches and arguments
are returned as an object with attributes named by the *dest* parameters::

    -> ./python.exe argparse-example.py -v
    {'output': None,
     'is_verbose': True,
     'context': 0,
     'inputs': []}

    -> ./python.exe argparse-example.py -v -o /tmp/output -C 4 file1 file2
    {'output': '/tmp/output',
     'is_verbose': True,
     'context': 4,
     'inputs': ['file1', 'file2']}

:mod:`argparse` has much fancier validation than :mod:`optparse`; you
can specify an exact number of arguments as an integer, 0 or more
arguments by passing ``'*'``, 1 or more by passing ``'+'``, or an
optional argument with ``'?'``.  A top-level parser can contain
sub-parsers to define subcommands that have different sets of
switches, as in ``svn commit``, ``svn checkout``, etc.  You can
specify an argument's type as :class:`~argparse.FileType`, which will
automatically open files for you and understands that ``'-'`` means
standard input or output.

.. seealso::

   `argparse module documentation <http://docs.python.org/dev/library/argparse.html>`__

   `Upgrading optparse code to use argparse <http://docs.python.org/dev/library/argparse.html#upgrading-optparse-code>`__
     Part of the Python documentation, describing how to convert
     code that uses :mod:`optparse`.

   :pep:`389` - argparse - New Command Line Parsing Module
     PEP written and implemented by Steven Bethard.

PEP 391: Dictionary-Based Configuration For Logging
====================================================

.. XXX not documented in library reference yet; add link here once it's added.

The :mod:`logging` module is very flexible; applications can define
a tree of logging subsystems, and each logger in this tree can filter
out certain messages, format them differently, and direct messages to
a varying number of handlers.

All this flexibility can require a lot of configuration.  You can
write Python statements to create objects and set their properties,
but a complex set-up requires verbose but boring code.
:mod:`logging` also supports a :func:`~logging.config.fileConfig`
function that parses a file, but the file format doesn't support
configuring filters, and it's messier to generate programmatically.

Python 2.7 adds a :func:`~logging.config.dictConfig` function that
uses a dictionary to configure logging.  There are many ways to
produce a dictionary from different sources: construct one with code;
parse a file containing JSON; or use a YAML parsing library if one is
installed.

The following example configures two loggers, the root logger and a
logger named "network".   Messages sent to the root logger will be
sent to the system log using the syslog protocol, and messages
to the "network" logger will be written to a :file:`network.log` file
that will be rotated once the log reaches 1Mb.

::

    import logging
    import logging.config

    configdict = {
     'version': 1,    # Configuration schema in use; must be 1 for now
     'formatters': {
         'standard': {
             'format': ('%(asctime)s %(name)-15s '
                        '%(levelname)-8s %(message)s')}},

     'handlers': {'netlog': {'backupCount': 10,
                         'class': 'logging.handlers.RotatingFileHandler',
                         'filename': '/logs/network.log',
                         'formatter': 'standard',
                         'level': 'INFO',
                         'maxBytes': 1024*1024},
                  'syslog': {'class': 'logging.handlers.SysLogHandler',
                             'formatter': 'standard',
                             'level': 'ERROR'}},

     # Specify all the subordinate loggers
     'loggers': {
                 'network': {
                             'handlers': ['netlog']
                 }
     },
     # Specify properties of the root logger
     'root': {
              'handlers': ['syslog']
     },
    }

    # Set up configuration
    logging.config.dictConfig(configdict)

    # As an example, log two error messages
    logger = logging.getLogger('/')
    logger.error('Database not found')

    netlogger = logging.getLogger('network')
    netlogger.error('Connection failed')

Three smaller enhancements to the :mod:`logging` module, all
implemented by Vinay Sajip, are:

.. rev79293

* The :class:`~logging.handlers.SysLogHandler` class now supports
  syslogging over TCP.  The constructor has a *socktype* parameter
  giving the type of socket to use, either :const:`socket.SOCK_DGRAM`
  for UDP or :const:`socket.SOCK_STREAM` for TCP.  The default
  protocol remains UDP.

* :class:`Logger` instances gained a :meth:`getChild` method that retrieves a
  descendant logger using a relative path.  For example,
  once you retrieve a logger by doing ``log = getLogger('app')``,
  calling ``log.getChild('network.listen')`` is equivalent to
  ``getLogger('app.network.listen')``.

* The :class:`LoggerAdapter` class gained a :meth:`isEnabledFor` method
  that takes a *level* and returns whether the underlying logger would
  process a message of that level of importance.

.. seealso::

   :pep:`391` - Dictionary-Based Configuration For Logging
     PEP written and implemented by Vinay Sajip.

PEP 3106: Dictionary Views
====================================================

The dictionary methods :meth:`keys`, :meth:`values`, and :meth:`items`
are different in Python 3.x.  They return an object called a :dfn:`view`
instead of a fully materialized list.

It's not possible to change the return values of :meth:`keys`,
:meth:`values`, and :meth:`items` in Python 2.7 because too much code
would break.  Instead the 3.x versions were added under the new names
:meth:`viewkeys`, :meth:`viewvalues`, and :meth:`viewitems`.

::

    >>> d = dict((i*10, chr(65+i)) for i in range(26))
    >>> d
    {0: 'A', 130: 'N', 10: 'B', 140: 'O', 20: ..., 250: 'Z'}
    >>> d.viewkeys()
    dict_keys([0, 130, 10, 140, 20, 150, 30, ..., 250])

Views can be iterated over, but the key and item views also behave
like sets.  The ``&`` operator performs intersection, and ``|``
performs a union::

    >>> d1 = dict((i*10, chr(65+i)) for i in range(26))
    >>> d2 = dict((i**.5, i) for i in range(1000))
    >>> d1.viewkeys() & d2.viewkeys()
    set([0.0, 10.0, 20.0, 30.0])
    >>> d1.viewkeys() | range(0, 30)
    set([0, 1, 130, 3, 4, 5, 6, ..., 120, 250])

The view keeps track of the dictionary and its contents change as the
dictionary is modified::

    >>> vk = d.viewkeys()
    >>> vk
    dict_keys([0, 130, 10, ..., 250])
    >>> d[260] = '&'
    >>> vk
    dict_keys([0, 130, 260, 10, ..., 250])

However, note that you can't add or remove keys while you're iterating
over the view::

    >>> for k in vk:
    ...     d[k*2] = k
    ...
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    RuntimeError: dictionary changed size during iteration

You can use the view methods in Python 2.x code, and the 2to3
converter will change them to the standard :meth:`keys`,
:meth:`values`, and :meth:`items` methods.

.. seealso::

   :pep:`3106` - Revamping dict.keys(), .values() and .items()
     PEP written by Guido van Rossum.
     Backported to 2.7 by Alexandre Vassalotti; :issue:`1967`.


PEP 3137: The memoryview Object
====================================================

The :class:`memoryview` object provides a view of another object's
memory content that matches the :class:`bytes` type's interface.

    >>> import string
    >>> m = memoryview(string.letters)
    >>> m
    <memory at 0x37f850>
    >>> len(m)           # Returns length of underlying object
    52
    >>> m[0], m[25], m[26]   # Indexing returns one byte
    ('a', 'z', 'A')
    >>> m2 = m[0:26]         # Slicing returns another memoryview
    >>> m2
    <memory at 0x37f080>

The content of the view can be converted to a string of bytes or
a list of integers:

    >>> m2.tobytes()
    'abcdefghijklmnopqrstuvwxyz'
    >>> m2.tolist()
    [97, 98, 99, 100, 101, 102, 103, ... 121, 122]
    >>>

:class:`memoryview` objects allow modifying the underlying object if
it's a mutable object.

    >>> m2[0] = 75
    Traceback (most recent call last):
      File "<stdin>", line 1, in <module>
    TypeError: cannot modify read-only memory
    >>> b = bytearray(string.letters)  # Creating a mutable object
    >>> b
    bytearray(b'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ')
    >>> mb = memoryview(b)
    >>> mb[0] = '*'         # Assign to view, changing the bytearray.
    >>> b[0:5]              # The bytearray has been changed.
    bytearray(b'*bcde')
    >>>

.. seealso::

   :pep:`3137` - Immutable Bytes and Mutable Buffer
     PEP written by Guido van Rossum.
     Implemented by Travis Oliphant, Antoine Pitrou and others.
     Backported to 2.7 by Antoine Pitrou; :issue:`2396`.



Other Language Changes
======================

Some smaller changes made to the core Python language are:

* The syntax for set literals has been backported from Python 3.x.
  Curly brackets are used to surround the contents of the resulting
  mutable set; set literals are
  distinguished from dictionaries by not containing colons and values.
  ``{}`` continues to represent an empty dictionary; use
  ``set()`` for an empty set.

    >>> {1,2,3,4,5}
    set([1, 2, 3, 4, 5])
    >>> set() # empty set
    set([])
    >>> {}    # empty dict
    {}

  Backported by Alexandre Vassalotti; :issue:`2335`.

* Dictionary and set comprehensions are another feature backported from
  3.x, generalizing list/generator comprehensions to use
  the literal syntax for sets and dictionaries.

    >>> {x: x*x for x in range(6)}
    {0: 0, 1: 1, 2: 4, 3: 9, 4: 16, 5: 25}
    >>> {('a'*x) for x in range(6)}
    set(['', 'a', 'aa', 'aaa', 'aaaa', 'aaaaa'])

  Backported by Alexandre Vassalotti; :issue:`2333`.

* The :keyword:`with` statement can now use multiple context managers
  in one statement.  Context managers are processed from left to right
  and each one is treated as beginning a new :keyword:`with` statement.
  This means that::

   with A() as a, B() as b:
       ... suite of statements ...

  is equivalent to::

   with A() as a:
       with B() as b:
           ... suite of statements ...

  The :func:`contextlib.nested` function provides a very similar
  function, so it's no longer necessary and has been deprecated.

  (Proposed in http://codereview.appspot.com/53094; implemented by
  Georg Brandl.)

* Conversions between floating-point numbers and strings are
  now correctly rounded on most platforms.  These conversions occur
  in many different places: :func:`str` on
  floats and complex numbers; the :class:`float` and :class:`complex`
  constructors;
  numeric formatting; serializing and
  deserializing floats and complex numbers using the
  :mod:`marshal`, :mod:`pickle`
  and :mod:`json` modules;
  parsing of float and imaginary literals in Python code;
  and :class:`~decimal.Decimal`-to-float conversion.

  Related to this, the :func:`repr` of a floating-point number *x*
  now returns a result based on the shortest decimal string that's
  guaranteed to round back to *x* under correct rounding (with
  round-half-to-even rounding mode).  Previously it gave a string
  based on rounding x to 17 decimal digits.

  .. maybe add an example?

  The rounding library responsible for this improvement works on
  Windows and on Unix platforms using the gcc, icc, or suncc
  compilers.  There may be a small number of platforms where correct
  operation of this code cannot be guaranteed, so the code is not
  used on such systems.  You can find out which code is being used
  by checking :data:`sys.float_repr_style`,  which will be ``short``
  if the new code is in use and ``legacy`` if it isn't.

  Implemented by Eric Smith and Mark Dickinson, using David Gay's
  :file:`dtoa.c` library; :issue:`7117`.

* Conversions from long integers and regular integers to floating
  point now round differently, returning the floating-point number
  closest to the number.  This doesn't matter for small integers that
  can be converted exactly, but for large numbers that will
  unavoidably lose precision, Python 2.7 now approximates more
  closely.  For example, Python 2.6 computed the following::

    >>> n = 295147905179352891391
    >>> float(n)
    2.9514790517935283e+20
    >>> n - long(float(n))
    65535L

  Python 2.7's floating-point result is larger, but much closer to the
  true value::

    >>> n = 295147905179352891391
    >>> float(n)
    2.9514790517935289e+20
    >>> n - long(float(n))
    -1L

  (Implemented by Mark Dickinson; :issue:`3166`.)

  Integer division is also more accurate in its rounding behaviours.  (Also
  implemented by Mark Dickinson; :issue:`1811`.)

* Implicit coercion for complex numbers has been removed; the interpreter
  will no longer ever attempt to call a :meth:`__coerce__` method on complex
  objects.  (Removed by Meador Inge and Mark Dickinson; :issue:`5211`.)

* The :meth:`str.format` method now supports automatic numbering of the replacement
  fields.  This makes using :meth:`str.format` more closely resemble using
  ``%s`` formatting::

    >>> '{}:{}:{}'.format(2009, 04, 'Sunday')
    '2009:4:Sunday'
    >>> '{}:{}:{day}'.format(2009, 4, day='Sunday')
    '2009:4:Sunday'

  The auto-numbering takes the fields from left to right, so the first ``{...}``
  specifier will use the first argument to :meth:`str.format`, the next
  specifier will use the next argument, and so on.  You can't mix auto-numbering
  and explicit numbering -- either number all of your specifier fields or none
  of them -- but you can mix auto-numbering and named fields, as in the second
  example above.  (Contributed by Eric Smith; :issue:`5237`.)

  Complex numbers now correctly support usage with :func:`format`,
  and default to being right-aligned.
  Specifying a precision or comma-separation applies to both the real
  and imaginary parts of the number, but a specified field width and
  alignment is applied to the whole of the resulting ``1.5+3j``
  output.  (Contributed by Eric Smith; :issue:`1588` and :issue:`7988`.)

  The 'F' format code now always formats its output using uppercase characters,
  so it will now produce 'INF' and 'NAN'.
  (Contributed by Eric Smith; :issue:`3382`.)

  A low-level change: the :meth:`object.__format__` method now triggers
  a :exc:`PendingDeprecationWarning` if it's passed a format string,
  because the :meth:`__format__` method for :class:`object` converts
  the object to a string representation and formats that.  Previously
  the method silently applied the format string to the string
  representation, but that could hide mistakes in Python code.  If
  you're supplying formatting information such as an alignment or
  precision, presumably you're expecting the formatting to be applied
  in some object-specific way.  (Fixed by Eric Smith; :issue:`7994`.)

* The :func:`int` and :func:`long` types gained a ``bit_length``
  method that returns the number of bits necessary to represent
  its argument in binary::

      >>> n = 37
      >>> bin(n)
      '0b100101'
      >>> n.bit_length()
      6
      >>> n = 2**123-1
      >>> n.bit_length()
      123
      >>> (n+1).bit_length()
      124

  (Contributed by Fredrik Johansson and Victor Stinner; :issue:`3439`.)

* The :keyword:`import` statement will no longer try an absolute import
  if a relative import (e.g. ``from .os import sep``) fails.  This
  fixes a bug, but could possibly break certain :keyword:`import`
  statements that were only working by accident.  (Fixed by Meador Inge;
  :issue:`7902`.)

* It's now possible for a subclass of the built-in :class:`unicode` type
  to override the :meth:`__unicode__` method.  (Implemented by
  Victor Stinner; :issue:`1583863`.)

* The :class:`bytearray` type's :meth:`~bytearray.translate` method now accepts
  ``None`` as its first argument.  (Fixed by Georg Brandl;
  :issue:`4759`.)

  .. bytearray doesn't seem to be documented

* When using ``@classmethod`` and ``@staticmethod`` to wrap
  methods as class or static methods, the wrapper object now
  exposes the wrapped function as their :attr:`__func__` attribute.
  (Contributed by Amaury Forgeot d'Arc, after a suggestion by
  George Sakkis; :issue:`5982`.)

* When a restricted set of attributes were set using ``__slots__``,
  deleting an unset attribute would not raise :exc:`AttributeError`
  as you would expect.  Fixed by Benjamin Peterson; :issue:`7604`.)

* Two new encodings are now supported: "cp720", used primarily for
  Arabic text; and "cp858", a variant of CP 850 that adds the euro
  symbol.  (CP720 contributed by Alexander Belchenko and Amaury
  Forgeot d'Arc in :issue:`1616979`; CP858 contributed by Tim Hatch in
  :issue:`8016`.)

* The :class:`file` object will now set the :attr:`filename` attribute
  on the :exc:`IOError` exception when trying to open a directory
  on POSIX platforms (noted by Jan Kaliszewski; :issue:`4764`), and
  now explicitly checks for and forbids writing to read-only file objects
  instead of trusting the C library to catch and report the error
  (fixed by Stefan Krah; :issue:`5677`).

* The Python tokenizer now translates line endings itself, so the
  :func:`compile` built-in function now accepts code using any
  line-ending convention.  Additionally, it no longer requires that the
  code end in a newline.

* Extra parentheses in function definitions are illegal in Python 3.x,
  meaning that you get a syntax error from ``def f((x)): pass``.  In
  Python3-warning mode, Python 2.7 will now warn about this odd usage.
  (Noted by James Lingard; :issue:`7362`.)

* It's now possible to create weak references to old-style class
  objects.  New-style classes were always weak-referenceable.  (Fixed
  by Antoine Pitrou; :issue:`8268`.)

* When a module object is garbage-collected, the module's dictionary is
  now only cleared if no one else is holding a reference to the
  dictionary (:issue:`7140`).

.. ======================================================================

.. _new-27-interpreter:

Interpreter Changes
-------------------------------

A new environment variable, :envvar:`PYTHONWARNINGS`,
allows controlling warnings.  It should be set to a string
containing warning settings, equivalent to those
used with the :option:`-W` switch, separated by commas.
(Contributed by Brian Curtin; :issue:`7301`.)

For example, the following setting will print warnings every time
they occur, but turn warnings from the :mod:`Cookie` module into an
error.  (The exact syntax for setting an environment variable varies
across operating systems and shells.)

::

  export PYTHONWARNINGS=all,error:::Cookie:0

.. ======================================================================


Optimizations
-------------

Several performance enhancements have been added:

.. * A new :program:`configure` option, :option:`--with-computed-gotos`,
   compiles the main bytecode interpreter loop using a new dispatch
   mechanism that gives speedups of up to 20%, depending on the system
   and benchmark.  The new mechanism is only supported on certain
   compilers, such as gcc, SunPro, and icc.

* A new opcode was added to perform the initial setup for
  :keyword:`with` statements, looking up the :meth:`__enter__` and
  :meth:`__exit__` methods.  (Contributed by Benjamin Peterson.)

* The garbage collector now performs better for one common usage
  pattern: when many objects are being allocated without deallocating
  any of them.  This would previously take quadratic
  time for garbage collection, but now the number of full garbage collections
  is reduced as the number of objects on the heap grows.
  The new logic only performs a full garbage collection pass when
  the middle generation has been collected 10 times and when the
  number of survivor objects from the middle generation exceeds 10% of
  the number of objects in the oldest generation.  (Suggested by Martin
  von Löwis and implemented by Antoine Pitrou; :issue:`4074`.)

* The garbage collector tries to avoid tracking simple containers
  which can't be part of a cycle. In Python 2.7, this is now true for
  tuples and dicts containing atomic types (such as ints, strings,
  etc.). Transitively, a dict containing tuples of atomic types won't
  be tracked either. This helps reduce the cost of each
  garbage collection by decreasing the number of objects to be
  considered and traversed by the collector.
  (Contributed by Antoine Pitrou; :issue:`4688`.)

* Long integers are now stored internally either in base 2**15 or in base
  2**30, the base being determined at build time.  Previously, they
  were always stored in base 2**15.  Using base 2**30 gives
  significant performance improvements on 64-bit machines, but
  benchmark results on 32-bit machines have been mixed.  Therefore,
  the default is to use base 2**30 on 64-bit machines and base 2**15
  on 32-bit machines; on Unix, there's a new configure option
  :option:`--enable-big-digits` that can be used to override this default.

  Apart from the performance improvements this change should be
  invisible to end users, with one exception: for testing and
  debugging purposes there's a new structseq :data:`sys.long_info` that
  provides information about the internal format, giving the number of
  bits per digit and the size in bytes of the C type used to store
  each digit::

     >>> import sys
     >>> sys.long_info
     sys.long_info(bits_per_digit=30, sizeof_digit=4)

  (Contributed by Mark Dickinson; :issue:`4258`.)

  Another set of changes made long objects a few bytes smaller: 2 bytes
  smaller on 32-bit systems and 6 bytes on 64-bit.
  (Contributed by Mark Dickinson; :issue:`5260`.)

* The division algorithm for long integers has been made faster
  by tightening the inner loop, doing shifts instead of multiplications,
  and fixing an unnecessary extra iteration.
  Various benchmarks show speedups of between 50% and 150% for long
  integer divisions and modulo operations.
  (Contributed by Mark Dickinson; :issue:`5512`.)
  Bitwise operations are also significantly faster (initial patch by
  Gregory Smith; :issue:`1087418`).

* The implementation of ``%`` checks for the left-side operand being
  a Python string and special-cases it; this results in a 1-3%
  performance increase for applications that frequently use ``%``
  with strings, such as templating libraries.
  (Implemented by Collin Winter; :issue:`5176`.)

* List comprehensions with an ``if`` condition are compiled into
  faster bytecode.  (Patch by Antoine Pitrou, back-ported to 2.7
  by Jeffrey Yasskin; :issue:`4715`.)

* Converting an integer or long integer to a decimal string was made
  faster by special-casing base 10 instead of using a generalized
  conversion function that supports arbitrary bases.
  (Patch by Gawain Bolton; :issue:`6713`.)

* The :meth:`split`, :meth:`replace`, :meth:`rindex`,
  :meth:`rpartition`, and :meth:`rsplit` methods of string-like types
  (strings, Unicode strings, and :class:`bytearray` objects) now use a
  fast reverse-search algorithm instead of a character-by-character
  scan.  This is sometimes faster by a factor of 10.  (Added by
  Florent Xicluna; :issue:`7462` and :issue:`7622`.)

* The :mod:`pickle` and :mod:`cPickle` modules now automatically
  intern the strings used for attribute names, reducing memory usage
  of the objects resulting from unpickling.  (Contributed by Jake
  McGuire; :issue:`5084`.)

* The :mod:`cPickle` module now special-cases dictionaries,
  nearly halving the time required to pickle them.
  (Contributed by Collin Winter; :issue:`5670`.)

.. ======================================================================

New and Improved Modules
========================

As in every release, Python's standard library received a number of
enhancements and bug fixes.  Here's a partial list of the most notable
changes, sorted alphabetically by module name. Consult the
:file:`Misc/NEWS` file in the source tree for a more complete list of
changes, or look through the Subversion logs for all the details.

* The :mod:`bdb` module's base debugging class :class:`~bdb.Bdb`
  gained a feature for skipping modules.  The constructor
  now takes an iterable containing glob-style patterns such as
  ``django.*``; the debugger will not step into stack frames
  from a module that matches one of these patterns.
  (Contributed by Maru Newby after a suggestion by
  Senthil Kumaran; :issue:`5142`.)

* The :mod:`binascii` module now supports the buffer API, so it can be
  used with :class:`memoryview` instances and other similar buffer objects.
  (Backported from 3.x by Florent Xicluna; :issue:`7703`.)

* Updated module: the :mod:`bsddb` module has been updated from 4.7.2devel9
  to version 4.8.4 of
  `the pybsddb package <http://www.jcea.es/programacion/pybsddb.htm>`__.
  The new version features better Python 3.x compatibility, various bug fixes,
  and adds several new BerkeleyDB flags and methods.
  (Updated by Jesús Cea Avión; :issue:`8156`.  The pybsddb
  changelog can be read at http://hg.jcea.es/pybsddb/file/tip/ChangeLog.)

* The :mod:`bz2` module's :class:`~bz2.BZ2File` now supports the context
  management protocol, so you can write ``with bz2.BZ2File(...) as f:``.
  (Contributed by Hagen Fürstenau; :issue:`3860`.)

* New class: the :class:`~collections.Counter` class in the :mod:`collections`
  module is useful for tallying data.  :class:`~collections.Counter` instances
  behave mostly like dictionaries but return zero for missing keys instead of
  raising a :exc:`KeyError`:

  .. doctest::
     :options: +NORMALIZE_WHITESPACE

     >>> from collections import Counter
     >>> c = Counter()
     >>> for letter in 'here is a sample of english text':
     ...   c[letter] += 1
     ...
     >>> c
     Counter({' ': 6, 'e': 5, 's': 3, 'a': 2, 'i': 2, 'h': 2,
     'l': 2, 't': 2, 'g': 1, 'f': 1, 'm': 1, 'o': 1, 'n': 1,
     'p': 1, 'r': 1, 'x': 1})
     >>> c['e']
     5
     >>> c['z']
     0

  There are three additional :class:`~collections.Counter` methods.
  :meth:`~collections.Counter.most_common` returns the N most common
  elements and their counts.  :meth:`~collections.Counter.elements`
  returns an iterator over the contained elements, repeating each
  element as many times as its count.
  :meth:`~collections.Counter.subtract` takes an iterable and
  subtracts one for each element instead of adding; if the argument is
  a dictionary or another :class:`Counter`, the counts are
  subtracted. ::

    >>> c.most_common(5)
    [(' ', 6), ('e', 5), ('s', 3), ('a', 2), ('i', 2)]
    >>> c.elements() ->
       'a', 'a', ' ', ' ', ' ', ' ', ' ', ' ',
       'e', 'e', 'e', 'e', 'e', 'g', 'f', 'i', 'i',
       'h', 'h', 'm', 'l', 'l', 'o', 'n', 'p', 's',
       's', 's', 'r', 't', 't', 'x'
    >>> c['e']
    5
    >>> c.subtract('very heavy on the letter e')
    >>> c['e']    # Count is now lower
    -1

  Contributed by Raymond Hettinger; :issue:`1696199`.

  .. revision 79660

  New class: :class:`~collections.OrderedDict` is described in the earlier
  section :ref:`pep-0372`.

  New method: The :class:`~collections.deque` data type now has a
  :meth:`~collections.deque.count` method that returns the number of
  contained elements equal to the supplied argument *x*, and a
  :meth:`~collections.deque.reverse` method that reverses the elements
  of the deque in-place.  :class:`deque` also exposes its maximum
  length as the read-only :attr:`~collections.deque.maxlen` attribute.
  (Both features added by Raymond Hettinger.)

  The :class:`~collections.namedtuple` class now has an optional *rename* parameter.
  If *rename* is true, field names that are invalid because they've
  been repeated or aren't legal Python identifiers will be
  renamed to legal names that are derived from the field's
  position within the list of fields:

     >>> from collections import namedtuple
     >>> T = namedtuple('T', ['field1', '$illegal', 'for', 'field2'], rename=True)
     >>> T._fields
     ('field1', '_1', '_2', 'field2')

  (Added by Raymond Hettinger; :issue:`1818`.)

  Finally, the :class:`~collections.Mapping` abstract base class now
  returns :const:`NotImplemented` if a mapping is compared to
  another type that isn't a :class:`Mapping`.
  (Fixed by Daniel Stutzbach; :issue:`8729`.)

* Constructors for the parsing classes in the :mod:`ConfigParser` module now
  take a *allow_no_value* parameter, defaulting to false; if true,
  options without values will be allowed.  For example::

    >>> import ConfigParser, StringIO
    >>> sample_config = """
    ... [mysqld]
    ... user = mysql
    ... pid-file = /var/run/mysqld/mysqld.pid
    ... skip-bdb
    ... """
    >>> config = ConfigParser.RawConfigParser(allow_no_value=True)
    >>> config.readfp(StringIO.StringIO(sample_config))
    >>> config.get('mysqld', 'user')
    'mysql'
    >>> print config.get('mysqld', 'skip-bdb')
    None
    >>> print config.get('mysqld', 'unknown')
    Traceback (most recent call last):
      ...
    NoOptionError: No option 'unknown' in section: 'mysqld'

  (Contributed by Mats Kindahl; :issue:`7005`.)

* Deprecated function: :func:`contextlib.nested`, which allows
  handling more than one context manager with a single :keyword:`with`
  statement, has been deprecated, because the :keyword:`with` statement
  now supports multiple context managers.

* The :mod:`cookielib` module now ignores cookies that have an invalid
  version field, one that doesn't contain an integer value.  (Fixed by
  John J. Lee; :issue:`3924`.)

* The :mod:`copy` module's :func:`~copy.deepcopy` function will now
  correctly copy bound instance methods.  (Implemented by
  Robert Collins; :issue:`1515`.)

* The :mod:`ctypes` module now always converts ``None`` to a C NULL
  pointer for arguments declared as pointers.  (Changed by Thomas
  Heller; :issue:`4606`.)  The underlying `libffi library
  <http://sourceware.org/libffi/>`__ has been updated to version
  3.0.9, containing various fixes for different platforms.  (Updated
  by Matthias Klose; :issue:`8142`.)

* New method: the :mod:`datetime` module's :class:`~datetime.timedelta` class
  gained a :meth:`~datetime.timedelta.total_seconds` method that returns the
  number of seconds in the duration.  (Contributed by Brian Quinlan; :issue:`5788`.)

* New method: the :class:`~decimal.Decimal` class gained a
  :meth:`~decimal.Decimal.from_float` class method that performs an exact
  conversion of a floating-point number to a :class:`~decimal.Decimal`.
  This exact conversion strives for the
  closest decimal approximation to the floating-point representation's value;
  the resulting decimal value will therefore still include the inaccuracy,
  if any.
  For example, ``Decimal.from_float(0.1)`` returns
  ``Decimal('0.1000000000000000055511151231257827021181583404541015625')``.
  (Implemented by Raymond Hettinger; :issue:`4796`.)

  Comparing instances of :class:`Decimal` with floating-point
  numbers now produces sensible results based on the numeric values
  of the operands.  Previously such comparisons would fall back to
  Python's default rules for comparing objects, which produced arbitrary
  results based on their type.  Note that you still cannot combine
  :class:`Decimal` and floating-point in other operations such as addition,
  since you should be explicitly choosing how to convert between float and
  :class:`Decimal`.
  (Fixed by Mark Dickinson; :issue:`2531`.)

  The constructor for :class:`~decimal.Decimal` now accepts
  floating-point numbers (added by Raymond Hettinger; :issue:`8257`)
  and non-European Unicode characters such as Arabic-Indic digits
  (contributed by Mark Dickinson; :issue:`6595`).

  Most of the methods of the :class:`~decimal.Context` class now accept integers
  as well as :class:`~decimal.Decimal` instances; the only exceptions are the
  :meth:`~decimal.Context.canonical` and :meth:`~decimal.Context.is_canonical`
  methods.  (Patch by Juan José Conti; :issue:`7633`.)

  When using :class:`~decimal.Decimal` instances with a string's
  :meth:`~str.format` method, the default alignment was previously
  left-alignment.  This has been changed to right-alignment, which is
  more sensible for numeric types.  (Changed by Mark Dickinson; :issue:`6857`.)

  Comparisons involving a signaling NaN value (or ``sNAN``) now signal
  :const:`InvalidOperation` instead of silently returning a true or
  false value depending on the comparison operator.  Quiet NaN values
  (or ``NaN``) are now hashable.  (Fixed by Mark Dickinson;
  :issue:`7279`.)

* The :mod:`difflib` module now produces output that is more
  compatible with modern :command:`diff`/:command:`patch` tools
  through one small change, using a tab character instead of spaces as
  a separator in the header giving the filename.  (Fixed by Anatoly
  Techtonik; :issue:`7585`.)

* The Distutils ``sdist`` command now always regenerates the
  :file:`MANIFEST` file, since even if the :file:`MANIFEST.in` or
  :file:`setup.py` files haven't been modified, the user might have
  created some new files that should be included.
  (Fixed by Tarek Ziadé; :issue:`8688`.)

* The :mod:`doctest` module's :const:`IGNORE_EXCEPTION_DETAIL` flag
  will now ignore the name of the module containing the exception
  being tested.  (Patch by Lennart Regebro; :issue:`7490`.)

* The :mod:`email` module's :class:`~email.message.Message` class will
  now accept a Unicode-valued payload, automatically converting the
  payload to the encoding specified by :attr:`output_charset`.
  (Added by R. David Murray; :issue:`1368247`.)

* The :class:`~fractions.Fraction` class now accepts a single float or
  :class:`~decimal.Decimal` instance, or two rational numbers, as
  arguments to its constructor.  (Implemented by Mark Dickinson;
  rationals added in :issue:`5812`, and float/decimal in
  :issue:`8294`.)

  Ordering comparisons (``<``, ``<=``, ``>``, ``>=``) between
  fractions and complex numbers now raise a :exc:`TypeError`.
  This fixes an oversight, making the :class:`Fraction` match the other
  numeric types.

  .. revision 79455

* New class: :class:`~ftplib.FTP_TLS` in
  the :mod:`ftplib` module provides secure FTP
  connections using TLS encapsulation of authentication as well as
  subsequent control and data transfers.
  (Contributed by Giampaolo Rodola; :issue:`2054`.)

  The :meth:`~ftplib.FTP.storbinary` method for binary uploads can now restart
  uploads thanks to an added *rest* parameter (patch by Pablo Mouzo;
  :issue:`6845`.)

* New class decorator: :func:`total_ordering` in the :mod:`functools`
  module takes a class that defines an :meth:`__eq__` method and one of
  :meth:`__lt__`, :meth:`__le__`, :meth:`__gt__`, or :meth:`__ge__`,
  and generates the missing comparison methods.  Since the
  :meth:`__cmp__` method is being deprecated in Python 3.x,
  this decorator makes it easier to define ordered classes.
  (Added by Raymond Hettinger; :issue:`5479`.)

  New function: :func:`cmp_to_key` will take an old-style comparison
  function that expects two arguments and return a new callable that
  can be used as the *key* parameter to functions such as
  :func:`sorted`, :func:`min` and :func:`max`, etc.  The primary
  intended use is to help with making code compatible with Python 3.x.
  (Added by Raymond Hettinger.)

* New function: the :mod:`gc` module's :func:`~gc.is_tracked` returns
  true if a given instance is tracked by the garbage collector, false
  otherwise. (Contributed by Antoine Pitrou; :issue:`4688`.)

* The :mod:`gzip` module's :class:`~gzip.GzipFile` now supports the context
  management protocol, so you can write ``with gzip.GzipFile(...) as f:``
  (contributed by Hagen Fürstenau; :issue:`3860`), and it now implements
  the :class:`io.BufferedIOBase` ABC, so you can wrap it with
  :class:`io.BufferedReader` for faster processing
  (contributed by Nir Aides; :issue:`7471`).
  It's also now possible to override the modification time
  recorded in a gzipped file by providing an optional timestamp to
  the constructor.  (Contributed by Jacques Frechet; :issue:`4272`.)

  Files in gzip format can be padded with trailing zero bytes; the
  :mod:`gzip` module will now consume these trailing bytes.  (Fixed by
  Tadek Pietraszek and Brian Curtin; :issue:`2846`.)

* New attribute: the :mod:`hashlib` module now has an :attr:`~hashlib.hashlib.algorithms`
  attribute containing a tuple naming the supported algorithms.
  In Python 2.7, ``hashlib.algorithms`` contains
  ``('md5', 'sha1', 'sha224', 'sha256', 'sha384', 'sha512')``.
  (Contributed by Carl Chenet; :issue:`7418`.)

* The default :class:`~httplib.HTTPResponse` class used by the :mod:`httplib` module now
  supports buffering, resulting in much faster reading of HTTP responses.
  (Contributed by Kristján Valur Jónsson; :issue:`4879`.)

  The :class:`~httplib.HTTPConnection` and :class:`~httplib.HTTPSConnection` classes
  now support a *source_address* parameter, a ``(host, port)`` 2-tuple
  giving the source address that will be used for the connection.
  (Contributed by Eldon Ziegler; :issue:`3972`.)

* The :mod:`ihooks` module now supports relative imports.  Note that
  :mod:`ihooks` is an older module for customizing imports,
  superseded by the :mod:`imputil` module added in Python 2.0.
  (Relative import support added by Neil Schemenauer.)

  .. revision 75423

* The :mod:`imaplib` module now supports IPv6 addresses.
  (Contributed by Derek Morr; :issue:`1655`.)

* New function: the :mod:`inspect` module's :func:`~inspect.getcallargs`
  takes a callable and its positional and keyword arguments,
  and figures out which of the callable's parameters will receive each argument,
  returning a dictionary mapping argument names to their values.  For example::

    >>> from inspect import getcallargs
    >>> def f(a, b=1, *pos, **named):
    ...     pass
    >>> getcallargs(f, 1, 2, 3)
    {'a': 1, 'b': 2, 'pos': (3,), 'named': {}}
    >>> getcallargs(f, a=2, x=4)
    {'a': 2, 'b': 1, 'pos': (), 'named': {'x': 4}}
    >>> getcallargs(f)
    Traceback (most recent call last):
    ...
    TypeError: f() takes at least 1 argument (0 given)

  Contributed by George Sakkis; :issue:`3135`.

* Updated module: The :mod:`io` library has been upgraded to the version shipped with
  Python 3.1.  For 3.1, the I/O library was entirely rewritten in C
  and is 2 to 20 times faster depending on the task being performed.  The
  original Python version was renamed to the :mod:`_pyio` module.

  One minor resulting change: the :class:`io.TextIOBase` class now
  has an :attr:`errors` attribute giving the error setting
  used for encoding and decoding errors (one of ``'strict'``, ``'replace'``,
  ``'ignore'``).

  The :class:`io.FileIO` class now raises an :exc:`OSError` when passed
  an invalid file descriptor.  (Implemented by Benjamin Peterson;
  :issue:`4991`.)  The :meth:`~io.IOBase.truncate` method now preserves the
  file position; previously it would change the file position to the
  end of the new file.  (Fixed by Pascal Chambon; :issue:`6939`.)

* New function: ``itertools.compress(data, selectors)`` takes two
  iterators.  Elements of *data* are returned if the corresponding
  value in *selectors* is true::

    itertools.compress('ABCDEF', [1,0,1,0,1,1]) =>
      A, C, E, F

  .. maybe here is better to use >>> list(itertools.compress(...)) instead

  New function: ``itertools.combinations_with_replacement(iter, r)``
  returns all the possible *r*-length combinations of elements from the
  iterable *iter*.  Unlike :func:`~itertools.combinations`, individual elements
  can be repeated in the generated combinations::

    itertools.combinations_with_replacement('abc', 2) =>
      ('a', 'a'), ('a', 'b'), ('a', 'c'),
      ('b', 'b'), ('b', 'c'), ('c', 'c')

  Note that elements are treated as unique depending on their position
  in the input, not their actual values.

  The :func:`itertools.count` function now has a *step* argument that
  allows incrementing by values other than 1.  :func:`~itertools.count` also
  now allows keyword arguments, and using non-integer values such as
  floats or :class:`~decimal.Decimal` instances.  (Implemented by Raymond
  Hettinger; :issue:`5032`.)

  :func:`itertools.combinations` and :func:`itertools.product`
  previously raised :exc:`ValueError` for values of *r* larger than
  the input iterable.  This was deemed a specification error, so they
  now return an empty iterator.  (Fixed by Raymond Hettinger; :issue:`4816`.)

* Updated module: The :mod:`json` module was upgraded to version 2.0.9 of the
  simplejson package, which includes a C extension that makes
  encoding and decoding faster.
  (Contributed by Bob Ippolito; :issue:`4136`.)

  To support the new :class:`collections.OrderedDict` type, :func:`json.load`
  now has an optional *object_pairs_hook* parameter that will be called
  with any object literal that decodes to a list of pairs.
  (Contributed by Raymond Hettinger; :issue:`5381`.)

* The :mod:`mailbox` module's :class:`Maildir` class now records the
  timestamp on the directories it reads, and only re-reads them if the
  modification time has subsequently changed.  This improves
  performance by avoiding unneeded directory scans.  (Fixed by
  A.M. Kuchling and Antoine Pitrou; :issue:`1607951`, :issue:`6896`.)

* New functions: the :mod:`math` module gained
  :func:`~math.erf` and :func:`~math.erfc` for the error function and the complementary error function,
  :func:`~math.expm1` which computes ``e**x - 1`` with more precision than
  using :func:`~math.exp` and subtracting 1,
  :func:`~math.gamma` for the Gamma function, and
  :func:`~math.lgamma` for the natural log of the Gamma function.
  (Contributed by Mark Dickinson and nirinA raseliarison; :issue:`3366`.)

* The :mod:`multiprocessing` module's :class:`Manager*` classes
  can now be passed a callable that will be called whenever
  a subprocess is started, along with a set of arguments that will be
  passed to the callable.
  (Contributed by lekma; :issue:`5585`.)

  The :class:`~multiprocessing.Pool` class, which controls a pool of worker processes,
  now has an optional *maxtasksperchild* parameter.  Worker processes
  will perform the specified number of tasks and then exit, causing the
  :class:`~multiprocessing.Pool` to start a new worker.  This is useful if tasks may leak
  memory or other resources, or if some tasks will cause the worker to
  become very large.
  (Contributed by Charles Cazabon; :issue:`6963`.)

* The :mod:`nntplib` module now supports IPv6 addresses.
  (Contributed by Derek Morr; :issue:`1664`.)

* New functions: the :mod:`os` module wraps the following POSIX system
  calls: :func:`~os.getresgid` and :func:`~os.getresuid`, which return the
  real, effective, and saved GIDs and UIDs;
  :func:`~os.setresgid` and :func:`~os.setresuid`, which set
  real, effective, and saved GIDs and UIDs to new values;
  :func:`~os.initgroups`, which initialize the group access list
  for the current process.  (GID/UID functions
  contributed by Travis H.; :issue:`6508`.  Support for initgroups added
  by Jean-Paul Calderone; :issue:`7333`.)

  The :func:`os.fork` function now re-initializes the import lock in
  the child process; this fixes problems on Solaris when :func:`~os.fork`
  is called from a thread.  (Fixed by Zsolt Cserna; :issue:`7242`.)

* In the :mod:`os.path` module, the :func:`~os.path.normpath` and
  :func:`~os.path.abspath` functions now preserve Unicode; if their input path
  is a Unicode string, the return value is also a Unicode string.
  (:meth:`~os.path.normpath` fixed by Matt Giuca in :issue:`5827`;
  :meth:`~os.path.abspath` fixed by Ezio Melotti in :issue:`3426`.)

* The :mod:`pydoc` module now has help for the various symbols that Python
  uses.  You can now do ``help('<<')`` or ``help('@')``, for example.
  (Contributed by David Laban; :issue:`4739`.)

* The :mod:`re` module's :func:`~re.split`, :func:`~re.sub`, and :func:`~re.subn`
  now accept an optional *flags* argument, for consistency with the
  other functions in the module.  (Added by Gregory P. Smith.)

* New function: :func:`~runpy.run_path` in the :mod:`runpy` module
  will execute the code at a provided *path* argument.  *path* can be
  the path of a Python source file (:file:`example.py`), a compiled
  bytecode file (:file:`example.pyc`), a directory
  (:file:`./package/`), or a zip archive (:file:`example.zip`).  If a
  directory or zip path is provided, it will be added to the front of
  ``sys.path`` and the module :mod:`__main__` will be imported.  It's
  expected that the directory or zip contains a :file:`__main__.py`;
  if it doesn't, some other :file:`__main__.py` might be imported from
  a location later in ``sys.path``.  This makes more of the machinery
  of :mod:`runpy` available to scripts that want to mimic the way
  Python's command line processes an explicit path name.
  (Added by Nick Coghlan; :issue:`6816`.)

* New function: in the :mod:`shutil` module, :func:`~shutil.make_archive`
  takes a filename, archive type (zip or tar-format), and a directory
  path, and creates an archive containing the directory's contents.
  (Added by Tarek Ziadé.)

  :mod:`shutil`'s :func:`~shutil.copyfile` and :func:`~shutil.copytree`
  functions now raise a :exc:`~shutil.SpecialFileError` exception when
  asked to copy a named pipe.  Previously the code would treat
  named pipes like a regular file by opening them for reading, and
  this would block indefinitely.  (Fixed by Antoine Pitrou; :issue:`3002`.)

* The :mod:`signal` module no longer re-installs the signal handler
  unless this is truly necessary, which fixes a bug that could make it
  impossible to catch the EINTR signal robustly.  (Fixed by
  Charles-Francois Natali; :issue:`8354`.)

* New functions: in the :mod:`site` module, three new functions
  return various site- and user-specific paths.
  :func:`~site.getsitepackages` returns a list containing all
  global site-packages directories,
  :func:`~site.getusersitepackages` returns the path of the user's
  site-packages directory, and
  :func:`~site.getuserbase` returns the value of the :envvar:`USER_BASE`
  environment variable, giving the path to a directory that can be used
  to store data.
  (Contributed by Tarek Ziadé; :issue:`6693`.)

  The :mod:`site` module now reports exceptions occurring
  when the :mod:`sitecustomize` module is imported, and will no longer
  catch and swallow the :exc:`KeyboardInterrupt` exception.  (Fixed by
  Victor Stinner; :issue:`3137`.)

* The :func:`~socket.create_connection` function
  gained a *source_address* parameter, a ``(host, port)`` 2-tuple
  giving the source address that will be used for the connection.
  (Contributed by Eldon Ziegler; :issue:`3972`.)

  The :meth:`~socket.socket.recv_into` and :meth:`~socket.socket.recvfrom_into`
  methods will now write into objects that support the buffer API, most usefully
  the :class:`bytearray` and :class:`memoryview` objects.  (Implemented by
  Antoine Pitrou; :issue:`8104`.)

* The :mod:`SocketServer` module's :class:`~SocketServer.TCPServer` class now
  supports socket timeouts and disabling the Nagle algorithm.
  The :attr:`~SocketServer.TCPServer.disable_nagle_algorithm` class attribute
  defaults to False; if overridden to be True,
  new request connections will have the TCP_NODELAY option set to
  prevent buffering many small sends into a single TCP packet.
  The :attr:`~SocketServer.TCPServer.timeout` class attribute can hold
  a timeout in seconds that will be applied to the request socket; if
  no request is received within that time, :meth:`handle_timeout`
  will be called and :meth:`handle_request` will return.
  (Contributed by Kristján Valur Jónsson; :issue:`6192` and :issue:`6267`.)

* Updated module: the :mod:`sqlite3` module has been updated to
  version 2.6.0 of the `pysqlite package <http://code.google.com/p/pysqlite/>`__. Version 2.6.0 includes a number of bugfixes, and adds
  the ability to load SQLite extensions from shared libraries.
  Call the ``enable_load_extension(True)`` method to enable extensions,
  and then call :meth:`~sqlite3.Connection.load_extension` to load a particular shared library.
  (Updated by Gerhard Häring.)

* The :mod:`ssl` module's :class:`ssl.SSLSocket` objects now support the
  buffer API, which fixed a test suite failure (fix by Antoine Pitrou;
  :issue:`7133`) and automatically set
  OpenSSL's :c:macro:`SSL_MODE_AUTO_RETRY`, which will prevent an error
  code being returned from :meth:`recv` operations that trigger an SSL
  renegotiation (fix by Antoine Pitrou; :issue:`8222`).

  The :func:`ssl.wrap_socket` constructor function now takes a
  *ciphers* argument that's a string listing the encryption algorithms
  to be allowed; the format of the string is described
  `in the OpenSSL documentation
  <http://www.openssl.org/docs/apps/ciphers.html#CIPHER_LIST_FORMAT>`__.
  (Added by Antoine Pitrou; :issue:`8322`.)

  Another change makes the extension load all of OpenSSL's ciphers and
  digest algorithms so that they're all available.  Some SSL
  certificates couldn't be verified, reporting an "unknown algorithm"
  error.  (Reported by Beda Kosata, and fixed by Antoine Pitrou;
  :issue:`8484`.)

  The version of OpenSSL being used is now available as the module
  attributes :data:`ssl.OPENSSL_VERSION` (a string),
  :data:`ssl.OPENSSL_VERSION_INFO` (a 5-tuple), and
  :data:`ssl.OPENSSL_VERSION_NUMBER` (an integer).  (Added by Antoine
  Pitrou; :issue:`8321`.)

* The :mod:`struct` module will no longer silently ignore overflow
  errors when a value is too large for a particular integer format
  code (one of ``bBhHiIlLqQ``); it now always raises a
  :exc:`struct.error` exception.  (Changed by Mark Dickinson;
  :issue:`1523`.)  The :func:`~struct.pack` function will also
  attempt to use :meth:`__index__` to convert and pack non-integers
  before trying the :meth:`__int__` method or reporting an error.
  (Changed by Mark Dickinson; :issue:`8300`.)

* New function: the :mod:`subprocess` module's
  :func:`~subprocess.check_output` runs a command with a specified set of arguments
  and returns the command's output as a string when the command runs without
  error, or raises a :exc:`~subprocess.CalledProcessError` exception otherwise.

  ::

    >>> subprocess.check_output(['df', '-h', '.'])
    'Filesystem     Size   Used  Avail Capacity  Mounted on\n
    /dev/disk0s2    52G    49G   3.0G    94%    /\n'

    >>> subprocess.check_output(['df', '-h', '/bogus'])
      ...
    subprocess.CalledProcessError: Command '['df', '-h', '/bogus']' returned non-zero exit status 1

  (Contributed by Gregory P. Smith.)

  The :mod:`subprocess` module will now retry its internal system calls
  on receiving an :const:`EINTR` signal.  (Reported by several people; final
  patch by Gregory P. Smith in :issue:`1068268`.)

* New function: :func:`~symtable.is_declared_global` in the :mod:`symtable` module
  returns true for variables that are explicitly declared to be global,
  false for ones that are implicitly global.
  (Contributed by Jeremy Hylton.)

* The :mod:`syslog` module will now use the value of ``sys.argv[0]`` as the
  identifier instead of the previous default value of ``'python'``.
  (Changed by Sean Reifschneider; :issue:`8451`.)

* The ``sys.version_info`` value is now a named tuple, with attributes
  named :attr:`major`, :attr:`minor`, :attr:`micro`,
  :attr:`releaselevel`, and :attr:`serial`.  (Contributed by Ross
  Light; :issue:`4285`.)

  :func:`sys.getwindowsversion` also returns a named tuple,
  with attributes named :attr:`major`, :attr:`minor`, :attr:`build`,
  :attr:`platform`, :attr:`service_pack`, :attr:`service_pack_major`,
  :attr:`service_pack_minor`, :attr:`suite_mask`, and
  :attr:`product_type`.  (Contributed by Brian Curtin; :issue:`7766`.)

* The :mod:`tarfile` module's default error handling has changed, to
  no longer suppress fatal errors.  The default error level was previously 0,
  which meant that errors would only result in a message being written to the
  debug log, but because the debug log is not activated by default,
  these errors go unnoticed.  The default error level is now 1,
  which raises an exception if there's an error.
  (Changed by Lars Gustäbel; :issue:`7357`.)

  :mod:`tarfile` now supports filtering the :class:`~tarfile.TarInfo`
  objects being added to a tar file.  When you call :meth:`~tarfile.TarFile.add`,
  you may supply an optional *filter* argument
  that's a callable.  The *filter* callable will be passed the
  :class:`~tarfile.TarInfo` for every file being added, and can modify and return it.
  If the callable returns ``None``, the file will be excluded from the
  resulting archive.  This is more powerful than the existing
  *exclude* argument, which has therefore been deprecated.
  (Added by Lars Gustäbel; :issue:`6856`.)
  The :class:`~tarfile.TarFile` class also now supports the context manager protocol.
  (Added by Lars Gustäbel; :issue:`7232`.)

* The :meth:`~threading.Event.wait` method of the :class:`threading.Event` class
  now returns the internal flag on exit.  This means the method will usually
  return true because :meth:`~threading.Event.wait` is supposed to block until the
  internal flag becomes true.  The return value will only be false if
  a timeout was provided and the operation timed out.
  (Contributed by Tim Lesher; :issue:`1674032`.)

* The Unicode database provided by the :mod:`unicodedata` module is
  now used internally to determine which characters are numeric,
  whitespace, or represent line breaks.  The database also
  includes information from the :file:`Unihan.txt` data file (patch
  by Anders Chrigström and Amaury Forgeot d'Arc; :issue:`1571184`)
  and has been updated to version 5.2.0 (updated by
  Florent Xicluna; :issue:`8024`).

* The :mod:`urlparse` module's :func:`~urlparse.urlsplit` now handles
  unknown URL schemes in a fashion compliant with :rfc:`3986`: if the
  URL is of the form ``"<something>://..."``, the text before the
  ``://`` is treated as the scheme, even if it's a made-up scheme that
  the module doesn't know about.  This change may break code that
  worked around the old behaviour.  For example, Python 2.6.4 or 2.5
  will return the following:

    >>> import urlparse
    >>> urlparse.urlsplit('invented://host/filename?query')
    ('invented', '', '//host/filename?query', '', '')

  Python 2.7 (and Python 2.6.5) will return:

    >>> import urlparse
    >>> urlparse.urlsplit('invented://host/filename?query')
    ('invented', 'host', '/filename?query', '', '')

  (Python 2.7 actually produces slightly different output, since it
  returns a named tuple instead of a standard tuple.)

  The :mod:`urlparse` module also supports IPv6 literal addresses as defined by
  :rfc:`2732` (contributed by Senthil Kumaran; :issue:`2987`). ::

    >>> urlparse.urlparse('http://[1080::8:800:200C:417A]/foo')
    ParseResult(scheme='http', netloc='[1080::8:800:200C:417A]',
                path='/foo', params='', query='', fragment='')

* New class: the :class:`~weakref.WeakSet` class in the :mod:`weakref`
  module is a set that only holds weak references to its elements; elements
  will be removed once there are no references pointing to them.
  (Originally implemented in Python 3.x by Raymond Hettinger, and backported
  to 2.7 by Michael Foord.)

* The ElementTree library, :mod:`xml.etree`, no longer escapes
  ampersands and angle brackets when outputting an XML processing
  instruction (which looks like ``<?xml-stylesheet href="#style1"?>``)
  or comment (which looks like ``<!-- comment -->``).
  (Patch by Neil Muller; :issue:`2746`.)

* The XML-RPC client and server, provided by the :mod:`xmlrpclib` and
  :mod:`SimpleXMLRPCServer` modules, have improved performance by
  supporting HTTP/1.1 keep-alive and by optionally using gzip encoding
  to compress the XML being exchanged.  The gzip compression is
  controlled by the :attr:`encode_threshold` attribute of
  :class:`SimpleXMLRPCRequestHandler`, which contains a size in bytes;
  responses larger than this will be compressed.
  (Contributed by Kristján Valur Jónsson; :issue:`6267`.)

* The :mod:`zipfile` module's :class:`~zipfile.ZipFile` now supports the context
  management protocol, so you can write ``with zipfile.ZipFile(...) as f:``.
  (Contributed by Brian Curtin; :issue:`5511`.)

  :mod:`zipfile` now also supports archiving empty directories and
  extracts them correctly.  (Fixed by Kuba Wieczorek; :issue:`4710`.)
  Reading files out of an archive is faster, and interleaving
  :meth:`~zipfile.ZipFile.read` and :meth:`~zipfile.ZipFile.readline` now works correctly.
  (Contributed by Nir Aides; :issue:`7610`.)

  The :func:`~zipfile.is_zipfile` function now
  accepts a file object, in addition to the path names accepted in earlier
  versions.  (Contributed by Gabriel Genellina; :issue:`4756`.)

  The :meth:`~zipfile.ZipFile.writestr` method now has an optional *compress_type* parameter
  that lets you override the default compression method specified in the
  :class:`~zipfile.ZipFile` constructor.  (Contributed by Ronald Oussoren;
  :issue:`6003`.)


.. ======================================================================
.. whole new modules get described in subsections here


.. _importlib-section:

New module: importlib
------------------------------

Python 3.1 includes the :mod:`importlib` package, a re-implementation
of the logic underlying Python's :keyword:`import` statement.
:mod:`importlib` is useful for implementors of Python interpreters and
to users who wish to write new importers that can participate in the
import process.  Python 2.7 doesn't contain the complete
:mod:`importlib` package, but instead has a tiny subset that contains
a single function, :func:`~importlib.import_module`.

``import_module(name, package=None)`` imports a module.  *name* is
a string containing the module or package's name.  It's possible to do
relative imports by providing a string that begins with a ``.``
character, such as ``..utils.errors``.  For relative imports, the
*package* argument must be provided and is the name of the package that
will be used as the anchor for
the relative import.  :func:`~importlib.import_module` both inserts the imported
module into ``sys.modules`` and returns the module object.

Here are some examples::

    >>> from importlib import import_module
    >>> anydbm = import_module('anydbm')  # Standard absolute import
    >>> anydbm
    <module 'anydbm' from '/p/python/Lib/anydbm.py'>
    >>> # Relative import
    >>> file_util = import_module('..file_util', 'distutils.command')
    >>> file_util
    <module 'distutils.file_util' from '/python/Lib/distutils/file_util.pyc'>

:mod:`importlib` was implemented by Brett Cannon and introduced in
Python 3.1.


New module: sysconfig
---------------------------------

The :mod:`sysconfig` module has been pulled out of the Distutils
package, becoming a new top-level module in its own right.
:mod:`sysconfig` provides functions for getting information about
Python's build process: compiler switches, installation paths, the
platform name, and whether Python is running from its source
directory.

Some of the functions in the module are:

* :func:`~sysconfig.get_config_var` returns variables from Python's
  Makefile and the :file:`pyconfig.h` file.
* :func:`~sysconfig.get_config_vars` returns a dictionary containing
  all of the configuration variables.
* :func:`~sysconfig.getpath` returns the configured path for
  a particular type of module: the standard library,
  site-specific modules, platform-specific modules, etc.
* :func:`~sysconfig.is_python_build` returns true if you're running a
  binary from a Python source tree, and false otherwise.

Consult the :mod:`sysconfig` documentation for more details and for
a complete list of functions.

The Distutils package and :mod:`sysconfig` are now maintained by Tarek
Ziadé, who has also started a Distutils2 package (source repository at
http://hg.python.org/distutils2/) for developing a next-generation
version of Distutils.


ttk: Themed Widgets for Tk
--------------------------

Tcl/Tk 8.5 includes a set of themed widgets that re-implement basic Tk
widgets but have a more customizable appearance and can therefore more
closely resemble the native platform's widgets.  This widget
set was originally called Tile, but was renamed to Ttk (for "themed Tk")
on being added to Tcl/Tck release 8.5.

To learn more, read the :mod:`ttk` module documentation.  You may also
wish to read the Tcl/Tk manual page describing the
Ttk theme engine, available at
http://www.tcl.tk/man/tcl8.5/TkCmd/ttk_intro.htm. Some
screenshots of the Python/Ttk code in use are at
http://code.google.com/p/python-ttk/wiki/Screenshots.

The :mod:`ttk` module was written by Guilherme Polo and added in
:issue:`2983`.  An alternate version called ``Tile.py``, written by
Martin Franklin and maintained by Kevin Walzer, was proposed for
inclusion in :issue:`2618`, but the authors argued that Guilherme
Polo's work was more comprehensive.


.. _unittest-section:

Updated module: unittest
---------------------------------

The :mod:`unittest` module was greatly enhanced; many
new features were added.  Most of these features were implemented
by Michael Foord, unless otherwise noted.  The enhanced version of
the module is downloadable separately for use with Python versions 2.4 to 2.6,
packaged as the :mod:`unittest2` package, from
http://pypi.python.org/pypi/unittest2.

When used from the command line, the module can automatically discover
tests.  It's not as fancy as `py.test <http://pytest.org>`__ or
`nose <http://code.google.com/p/python-nose/>`__, but provides a simple way
to run tests kept within a set of package directories.  For example,
the following command will search the :file:`test/` subdirectory for
any importable test files named ``test*.py``::

   python -m unittest discover -s test

Consult the :mod:`unittest` module documentation for more details.
(Developed in :issue:`6001`.)

The :func:`main` function supports some other new options:

* :option:`-b` or :option:`--buffer` will buffer the standard output
  and standard error streams during each test.  If the test passes,
  any resulting output will be discarded; on failure, the buffered
  output will be displayed.

* :option:`-c` or :option:`--catch` will cause the control-C interrupt
  to be handled more gracefully.  Instead of interrupting the test
  process immediately, the currently running test will be completed
  and then the partial results up to the interruption will be reported.
  If you're impatient, a second press of control-C will cause an immediate
  interruption.

  This control-C handler tries to avoid causing problems when the code
  being tested or the tests being run have defined a signal handler of
  their own, by noticing that a signal handler was already set and
  calling it.  If this doesn't work for you, there's a
  :func:`removeHandler` decorator that can be used to mark tests that
  should have the control-C handling disabled.

* :option:`-f` or :option:`--failfast` makes
  test execution stop immediately when a test fails instead of
  continuing to execute further tests.  (Suggested by Cliff Dyer and
  implemented by Michael Foord; :issue:`8074`.)

The progress messages now show 'x' for expected failures
and 'u' for unexpected successes when run in verbose mode.
(Contributed by Benjamin Peterson.)

Test cases can raise the :exc:`~unittest.SkipTest` exception to skip a
test (:issue:`1034053`).

The error messages for :meth:`~unittest.TestCase.assertEqual`,
:meth:`~unittest.TestCase.assertTrue`, and :meth:`~unittest.TestCase.assertFalse`
failures now provide more information.  If you set the
:attr:`~unittest.TestCase.longMessage` attribute of your :class:`~unittest.TestCase` classes to
True, both the standard error message and any additional message you
provide will be printed for failures.  (Added by Michael Foord; :issue:`5663`.)

The :meth:`~unittest.TestCase.assertRaises` method now
returns a context handler when called without providing a callable
object to run.  For example, you can write this::

  with self.assertRaises(KeyError):
      {}['foo']

(Implemented by Antoine Pitrou; :issue:`4444`.)

.. rev 78774

Module- and class-level setup and teardown fixtures are now supported.
Modules can contain :func:`~unittest.setUpModule` and :func:`~unittest.tearDownModule`
functions.  Classes can have :meth:`~unittest.TestCase.setUpClass` and
:meth:`~unittest.TestCase.tearDownClass` methods that must be defined as class methods
(using ``@classmethod`` or equivalent).  These functions and
methods are invoked when the test runner switches to a test case in a
different module or class.

The methods :meth:`~unittest.TestCase.addCleanup` and
:meth:`~unittest.TestCase.doCleanups` were added.
:meth:`~unittest.TestCase.addCleanup` lets you add cleanup functions that
will be called unconditionally (after :meth:`~unittest.TestCase.setUp` if
:meth:`~unittest.TestCase.setUp` fails, otherwise after :meth:`~unittest.TestCase.tearDown`). This allows
for much simpler resource allocation and deallocation during tests
(:issue:`5679`).

A number of new methods were added that provide more specialized
tests.  Many of these methods were written by Google engineers
for use in their test suites; Gregory P. Smith, Michael Foord, and
GvR worked on merging them into Python's version of :mod:`unittest`.

* :meth:`~unittest.TestCase.assertIsNone` and :meth:`~unittest.TestCase.assertIsNotNone` take one
  expression and verify that the result is or is not ``None``.

* :meth:`~unittest.TestCase.assertIs` and :meth:`~unittest.TestCase.assertIsNot`
  take two values and check whether the two values evaluate to the same object or not.
  (Added by Michael Foord; :issue:`2578`.)

* :meth:`~unittest.TestCase.assertIsInstance` and
  :meth:`~unittest.TestCase.assertNotIsInstance` check whether
  the resulting object is an instance of a particular class, or of
  one of a tuple of classes.  (Added by Georg Brandl; :issue:`7031`.)

* :meth:`~unittest.TestCase.assertGreater`, :meth:`~unittest.TestCase.assertGreaterEqual`,
  :meth:`~unittest.TestCase.assertLess`, and :meth:`~unittest.TestCase.assertLessEqual` compare
  two quantities.

* :meth:`~unittest.TestCase.assertMultiLineEqual` compares two strings, and if they're
  not equal, displays a helpful comparison that highlights the
  differences in the two strings.  This comparison is now used by
  default when Unicode strings are compared with :meth:`~unittest.TestCase.assertEqual`.

* :meth:`~unittest.TestCase.assertRegexpMatches` and
  :meth:`~unittest.TestCase.assertNotRegexpMatches` checks whether the
  first argument is a string matching or not matching the regular
  expression provided as the second argument (:issue:`8038`).

* :meth:`~unittest.TestCase.assertRaisesRegexp` checks whether a particular exception
  is raised, and then also checks that the string representation of
  the exception matches the provided regular expression.

* :meth:`~unittest.TestCase.assertIn` and :meth:`~unittest.TestCase.assertNotIn`
  tests whether *first* is or is not in  *second*.

* :meth:`~unittest.TestCase.assertItemsEqual` tests whether two provided sequences
  contain the same elements.

* :meth:`~unittest.TestCase.assertSetEqual` compares whether two sets are equal, and
  only reports the differences between the sets in case of error.

* Similarly, :meth:`~unittest.TestCase.assertListEqual` and :meth:`~unittest.TestCase.assertTupleEqual`
  compare the specified types and explain any differences without necessarily
  printing their full values; these methods are now used by default
  when comparing lists and tuples using :meth:`~unittest.TestCase.assertEqual`.
  More generally, :meth:`~unittest.TestCase.assertSequenceEqual` compares two sequences
  and can optionally check whether both sequences are of a
  particular type.

* :meth:`~unittest.TestCase.assertDictEqual` compares two dictionaries and reports the
  differences; it's now used by default when you compare two dictionaries
  using :meth:`~unittest.TestCase.assertEqual`.  :meth:`~unittest.TestCase.assertDictContainsSubset` checks whether
  all of the key/value pairs in *first* are found in *second*.

* :meth:`~unittest.TestCase.assertAlmostEqual` and :meth:`~unittest.TestCase.assertNotAlmostEqual` test
  whether *first* and *second* are approximately equal.  This method
  can either round their difference to an optionally-specified number
  of *places* (the default is 7) and compare it to zero, or require
  the difference to be smaller than a supplied *delta* value.

* :meth:`~unittest.TestLoader.loadTestsFromName` properly honors the
  :attr:`~unittest.TestLoader.suiteClass` attribute of
  the :class:`~unittest.TestLoader`. (Fixed by Mark Roddy; :issue:`6866`.)

* A new hook lets you extend the :meth:`~unittest.TestCase.assertEqual` method to handle
  new data types.  The :meth:`~unittest.TestCase.addTypeEqualityFunc` method takes a type
  object and a function. The function will be used when both of the
  objects being compared are of the specified type.  This function
  should compare the two objects and raise an exception if they don't
  match; it's a good idea for the function to provide additional
  information about why the two objects aren't matching, much as the new
  sequence comparison methods do.

:func:`unittest.main` now takes an optional ``exit`` argument.  If
False, :func:`~unittest.main` doesn't call :func:`sys.exit`, allowing
:func:`main` to be used from the interactive interpreter.
(Contributed by J. Pablo Fernández; :issue:`3379`.)

:class:`~unittest.TestResult` has new :meth:`~unittest.TestResult.startTestRun` and
:meth:`~unittest.TestResult.stopTestRun` methods that are called immediately before
and after a test run.  (Contributed by Robert Collins; :issue:`5728`.)

With all these changes, the :file:`unittest.py` was becoming awkwardly
large, so the module was turned into a package and the code split into
several files (by Benjamin Peterson).  This doesn't affect how the
module is imported or used.

.. seealso::

  http://www.voidspace.org.uk/python/articles/unittest2.shtml
    Describes the new features, how to use them, and the
    rationale for various design decisions.  (By Michael Foord.)

.. _elementtree-section:

Updated module: ElementTree 1.3
---------------------------------

The version of the ElementTree library included with Python was updated to
version 1.3.  Some of the new features are:

* The various parsing functions now take a *parser* keyword argument
  giving an :class:`~xml.etree.ElementTree.XMLParser` instance that will
  be used.  This makes it possible to override the file's internal encoding::

    p = ET.XMLParser(encoding='utf-8')
    t = ET.XML("""<root/>""", parser=p)

  Errors in parsing XML now raise a :exc:`ParseError` exception, whose
  instances have a :attr:`position` attribute
  containing a (*line*, *column*) tuple giving the location of the problem.

* ElementTree's code for converting trees to a string has been
  significantly reworked, making it roughly twice as fast in many
  cases.  The :meth:`ElementTree.write() <xml.etree.ElementTree.ElementTree.write>`
  and :meth:`Element.write` methods now have a *method* parameter that can be
  "xml" (the default), "html", or "text".  HTML mode will output empty
  elements as ``<empty></empty>`` instead of ``<empty/>``, and text
  mode will skip over elements and only output the text chunks.  If
  you set the :attr:`tag` attribute of an element to ``None`` but
  leave its children in place, the element will be omitted when the
  tree is written out, so you don't need to do more extensive rearrangement
  to remove a single element.

  Namespace handling has also been improved.  All ``xmlns:<whatever>``
  declarations are now output on the root element, not scattered throughout
  the resulting XML.  You can set the default namespace for a tree
  by setting the :attr:`default_namespace` attribute and can
  register new prefixes with :meth:`~xml.etree.ElementTree.register_namespace`.  In XML mode,
  you can use the true/false *xml_declaration* parameter to suppress the
  XML declaration.

* New :class:`~xml.etree.ElementTree.Element` method:
  :meth:`~xml.etree.ElementTree.Element.extend` appends the items from a
  sequence to the element's children.  Elements themselves behave like
  sequences, so it's easy to move children from one element to
  another::

    from xml.etree import ElementTree as ET

    t = ET.XML("""<list>
      <item>1</item> <item>2</item>  <item>3</item>
    </list>""")
    new = ET.XML('<root/>')
    new.extend(t)

    # Outputs <root><item>1</item>...</root>
    print ET.tostring(new)

* New :class:`Element` method:
  :meth:`~xml.etree.ElementTree.Element.iter` yields the children of the
  element as a generator.  It's also possible to write ``for child in
  elem:`` to loop over an element's children.  The existing method
  :meth:`getiterator` is now deprecated, as is :meth:`getchildren`
  which constructs and returns a list of children.

* New :class:`Element` method:
  :meth:`~xml.etree.ElementTree.Element.itertext` yields all chunks of
  text that are descendants of the element.  For example::

    t = ET.XML("""<list>
      <item>1</item> <item>2</item>  <item>3</item>
    </list>""")

    # Outputs ['\n  ', '1', ' ', '2', '  ', '3', '\n']
    print list(t.itertext())

* Deprecated: using an element as a Boolean (i.e., ``if elem:``) would
  return true if the element had any children, or false if there were
  no children.  This behaviour is confusing -- ``None`` is false, but
  so is a childless element? -- so it will now trigger a
  :exc:`FutureWarning`.  In your code, you should be explicit: write
  ``len(elem) != 0`` if you're interested in the number of children,
  or ``elem is not None``.

Fredrik Lundh develops ElementTree and produced the 1.3 version;
you can read his article describing 1.3 at
http://effbot.org/zone/elementtree-13-intro.htm.
Florent Xicluna updated the version included with
Python, after discussions on python-dev and in :issue:`6472`.)

.. ======================================================================


Build and C API Changes
=======================

Changes to Python's build process and to the C API include:

* The latest release of the GNU Debugger, GDB 7, can be `scripted
  using Python
  <http://sourceware.org/gdb/current/onlinedocs/gdb/Python.html>`__.
  When you begin debugging an executable program P, GDB will look for
  a file named ``P-gdb.py`` and automatically read it.  Dave Malcolm
  contributed a :file:`python-gdb.py` that adds a number of
  commands useful when debugging Python itself.  For example,
  ``py-up`` and ``py-down`` go up or down one Python stack frame,
  which usually corresponds to several C stack frames.  ``py-print``
  prints the value of a Python variable, and ``py-bt`` prints the
  Python stack trace.  (Added as a result of :issue:`8032`.)

* If you use the :file:`.gdbinit` file provided with Python,
  the "pyo" macro in the 2.7 version now works correctly when the thread being
  debugged doesn't hold the GIL; the macro now acquires it before printing.
  (Contributed by Victor Stinner; :issue:`3632`.)

* :c:func:`Py_AddPendingCall` is now thread-safe, letting any
  worker thread submit notifications to the main Python thread.  This
  is particularly useful for asynchronous IO operations.
  (Contributed by Kristján Valur Jónsson; :issue:`4293`.)

* New function: :c:func:`PyCode_NewEmpty` creates an empty code object;
  only the filename, function name, and first line number are required.
  This is useful for extension modules that are attempting to
  construct a more useful traceback stack.  Previously such
  extensions needed to call :c:func:`PyCode_New`, which had many
  more arguments.  (Added by Jeffrey Yasskin.)

* New function: :c:func:`PyErr_NewExceptionWithDoc` creates a new
  exception class, just as the existing :c:func:`PyErr_NewException` does,
  but takes an extra ``char *`` argument containing the docstring for the
  new exception class.  (Added by 'lekma' on the Python bug tracker;
  :issue:`7033`.)

* New function: :c:func:`PyFrame_GetLineNumber` takes a frame object
  and returns the line number that the frame is currently executing.
  Previously code would need to get the index of the bytecode
  instruction currently executing, and then look up the line number
  corresponding to that address.  (Added by Jeffrey Yasskin.)

* New functions: :c:func:`PyLong_AsLongAndOverflow` and
  :c:func:`PyLong_AsLongLongAndOverflow`  approximates a Python long
  integer as a C :c:type:`long` or :c:type:`long long`.
  If the number is too large to fit into
  the output type, an *overflow* flag is set and returned to the caller.
  (Contributed by Case Van Horsen; :issue:`7528` and :issue:`7767`.)

* New function: stemming from the rewrite of string-to-float conversion,
  a new :c:func:`PyOS_string_to_double` function was added.  The old
  :c:func:`PyOS_ascii_strtod` and :c:func:`PyOS_ascii_atof` functions
  are now deprecated.

* New function: :c:func:`PySys_SetArgvEx` sets the value of
  ``sys.argv`` and can optionally update ``sys.path`` to include the
  directory containing the script named by ``sys.argv[0]`` depending
  on the value of an *updatepath* parameter.

  This function was added to close a security hole for applications
  that embed Python.  The old function, :c:func:`PySys_SetArgv`, would
  always update ``sys.path``, and sometimes it would add the current
  directory.  This meant that, if you ran an application embedding
  Python in a directory controlled by someone else, attackers could
  put a Trojan-horse module in the directory (say, a file named
  :file:`os.py`) that your application would then import and run.

  If you maintain a C/C++ application that embeds Python, check
  whether you're calling :c:func:`PySys_SetArgv` and carefully consider
  whether the application should be using :c:func:`PySys_SetArgvEx`
  with *updatepath* set to false.

  Security issue reported as `CVE-2008-5983
  <http://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2008-5983>`_;
  discussed in :issue:`5753`, and fixed by Antoine Pitrou.

* New macros: the Python header files now define the following macros:
  :c:macro:`Py_ISALNUM`,
  :c:macro:`Py_ISALPHA`,
  :c:macro:`Py_ISDIGIT`,
  :c:macro:`Py_ISLOWER`,
  :c:macro:`Py_ISSPACE`,
  :c:macro:`Py_ISUPPER`,
  :c:macro:`Py_ISXDIGIT`,
  and :c:macro:`Py_TOLOWER`, :c:macro:`Py_TOUPPER`.
  All of these functions are analogous to the C
  standard macros for classifying characters, but ignore the current
  locale setting, because in
  several places Python needs to analyze characters in a
  locale-independent way.  (Added by Eric Smith;
  :issue:`5793`.)

  .. XXX these macros don't seem to be described in the c-api docs.

* Removed function: :c:macro:`PyEval_CallObject` is now only available
  as a macro.  A function version was being kept around to preserve
  ABI linking compatibility, but that was in 1997; it can certainly be
  deleted by now.  (Removed by Antoine Pitrou; :issue:`8276`.)

* New format codes: the :c:func:`PyFormat_FromString`,
  :c:func:`PyFormat_FromStringV`, and :c:func:`PyErr_Format` functions now
  accept ``%lld`` and ``%llu`` format codes for displaying
  C's :c:type:`long long` types.
  (Contributed by Mark Dickinson; :issue:`7228`.)

* The complicated interaction between threads and process forking has
  been changed.  Previously, the child process created by
  :func:`os.fork` might fail because the child is created with only a
  single thread running, the thread performing the :func:`os.fork`.
  If other threads were holding a lock, such as Python's import lock,
  when the fork was performed, the lock would still be marked as
  "held" in the new process.  But in the child process nothing would
  ever release the lock, since the other threads weren't replicated,
  and the child process would no longer be able to perform imports.

  Python 2.7 acquires the import lock before performing an
  :func:`os.fork`, and will also clean up any locks created using the
  :mod:`threading` module.  C extension modules that have internal
  locks, or that call :c:func:`fork()` themselves, will not benefit
  from this clean-up.

  (Fixed by Thomas Wouters; :issue:`1590864`.)

* The :c:func:`Py_Finalize` function now calls the internal
  :func:`threading._shutdown` function; this prevents some exceptions from
  being raised when an interpreter shuts down.
  (Patch by Adam Olsen; :issue:`1722344`.)

* When using the :c:type:`PyMemberDef` structure to define attributes
  of a type, Python will no longer let you try to delete or set a
  :const:`T_STRING_INPLACE` attribute.

  .. rev 79644

* Global symbols defined by the :mod:`ctypes` module are now prefixed
  with ``Py``, or with ``_ctypes``.  (Implemented by Thomas
  Heller; :issue:`3102`.)

* New configure option: the :option:`--with-system-expat` switch allows
  building the :mod:`pyexpat` module to use the system Expat library.
  (Contributed by Arfrever Frehtes Taifersar Arahesis; :issue:`7609`.)

* New configure option: the
  :option:`--with-valgrind` option will now disable the pymalloc
  allocator, which is difficult for the Valgrind memory-error detector
  to analyze correctly.
  Valgrind will therefore be better at detecting memory leaks and
  overruns. (Contributed by James Henstridge; :issue:`2422`.)

* New configure option: you can now supply an empty string to
  :option:`--with-dbmliborder=` in order to disable all of the various
  DBM modules.  (Added by Arfrever Frehtes Taifersar Arahesis;
  :issue:`6491`.)

* The :program:`configure` script now checks for floating-point rounding bugs
  on certain 32-bit Intel chips and defines a :c:macro:`X87_DOUBLE_ROUNDING`
  preprocessor definition.  No code currently uses this definition,
  but it's available if anyone wishes to use it.
  (Added by Mark Dickinson; :issue:`2937`.)

  :program:`configure` also now sets a :envvar:`LDCXXSHARED` Makefile
  variable for supporting C++ linking.  (Contributed by Arfrever
  Frehtes Taifersar Arahesis; :issue:`1222585`.)

* The build process now creates the necessary files for pkg-config
  support.  (Contributed by Clinton Roy; :issue:`3585`.)

* The build process now supports Subversion 1.7.  (Contributed by
  Arfrever Frehtes Taifersar Arahesis; :issue:`6094`.)


.. _whatsnew27-capsules:

Capsules
-------------------

Python 3.1 adds a new C datatype, :c:type:`PyCapsule`, for providing a
C API to an extension module.  A capsule is essentially the holder of
a C ``void *`` pointer, and is made available as a module attribute; for
example, the :mod:`socket` module's API is exposed as ``socket.CAPI``,
and :mod:`unicodedata` exposes ``ucnhash_CAPI``.  Other extensions
can import the module, access its dictionary to get the capsule
object, and then get the ``void *`` pointer, which will usually point
to an array of pointers to the module's various API functions.

There is an existing data type already used for this,
:c:type:`PyCObject`, but it doesn't provide type safety.  Evil code
written in pure Python could cause a segmentation fault by taking a
:c:type:`PyCObject` from module A and somehow substituting it for the
:c:type:`PyCObject` in module B.   Capsules know their own name,
and getting the pointer requires providing the name::

   void *vtable;

   if (!PyCapsule_IsValid(capsule, "mymodule.CAPI") {
           PyErr_SetString(PyExc_ValueError, "argument type invalid");
           return NULL;
   }

   vtable = PyCapsule_GetPointer(capsule, "mymodule.CAPI");

You are assured that ``vtable`` points to whatever you're expecting.
If a different capsule was passed in, :c:func:`PyCapsule_IsValid` would
detect the mismatched name and return false.  Refer to
:ref:`using-capsules` for more information on using these objects.

Python 2.7 now uses capsules internally to provide various
extension-module APIs, but the :c:func:`PyCObject_AsVoidPtr` was
modified to handle capsules, preserving compile-time compatibility
with the :c:type:`CObject` interface.  Use of
:c:func:`PyCObject_AsVoidPtr` will signal a
:exc:`PendingDeprecationWarning`, which is silent by default.

Implemented in Python 3.1 and backported to 2.7 by Larry Hastings;
discussed in :issue:`5630`.


.. ======================================================================

Port-Specific Changes: Windows
-----------------------------------

* The :mod:`msvcrt` module now contains some constants from
  the :file:`crtassem.h` header file:
  :data:`CRT_ASSEMBLY_VERSION`,
  :data:`VC_ASSEMBLY_PUBLICKEYTOKEN`,
  and :data:`LIBRARIES_ASSEMBLY_NAME_PREFIX`.
  (Contributed by David Cournapeau; :issue:`4365`.)

* The :mod:`_winreg` module for accessing the registry now implements
  the :func:`CreateKeyEx` and :func:`DeleteKeyEx` functions, extended
  versions of previously-supported functions that take several extra
  arguments.  The :func:`DisableReflectionKey`,
  :func:`EnableReflectionKey`, and :func:`QueryReflectionKey` were also
  tested and documented.
  (Implemented by Brian Curtin: :issue:`7347`.)

* The new :c:func:`_beginthreadex` API is used to start threads, and
  the native thread-local storage functions are now used.
  (Contributed by Kristján Valur Jónsson; :issue:`3582`.)

* The :func:`os.kill` function now works on Windows.  The signal value
  can be the constants :const:`CTRL_C_EVENT`,
  :const:`CTRL_BREAK_EVENT`, or any integer.  The first two constants
  will send Control-C and Control-Break keystroke events to
  subprocesses; any other value will use the :c:func:`TerminateProcess`
  API.  (Contributed by Miki Tebeka; :issue:`1220212`.)

* The :func:`os.listdir` function now correctly fails
  for an empty path.  (Fixed by Hirokazu Yamamoto; :issue:`5913`.)

* The :mod:`mimelib` module will now read the MIME database from
  the Windows registry when initializing.
  (Patch by Gabriel Genellina; :issue:`4969`.)

.. ======================================================================

Port-Specific Changes: Mac OS X
-----------------------------------

* The path ``/Library/Python/2.7/site-packages`` is now appended to
  ``sys.path``, in order to share added packages between the system
  installation and a user-installed copy of the same version.
  (Changed by Ronald Oussoren; :issue:`4865`.)

Port-Specific Changes: FreeBSD
-----------------------------------

* FreeBSD 7.1's :const:`SO_SETFIB` constant, used with
  :func:`~socket.getsockopt`/:func:`~socket.setsockopt` to select an
  alternate routing table, is now available in the :mod:`socket`
  module.  (Added by Kyle VanderBeek; :issue:`8235`.)

Other Changes and Fixes
=======================

* Two benchmark scripts, :file:`iobench` and :file:`ccbench`, were
  added to the :file:`Tools` directory.  :file:`iobench` measures the
  speed of the built-in file I/O objects returned by :func:`open`
  while performing various operations, and :file:`ccbench` is a
  concurrency benchmark that tries to measure computing throughput,
  thread switching latency, and IO processing bandwidth when
  performing several tasks using a varying number of threads.

* The :file:`Tools/i18n/msgfmt.py` script now understands plural
  forms in :file:`.po` files.  (Fixed by Martin von Löwis;
  :issue:`5464`.)

* When importing a module from a :file:`.pyc` or :file:`.pyo` file
  with an existing :file:`.py` counterpart, the :attr:`co_filename`
  attributes of the resulting code objects are overwritten when the
  original filename is obsolete.  This can happen if the file has been
  renamed, moved, or is accessed through different paths.  (Patch by
  Ziga Seilnacht and Jean-Paul Calderone; :issue:`1180193`.)

* The :file:`regrtest.py` script now takes a :option:`--randseed=`
  switch that takes an integer that will be used as the random seed
  for the :option:`-r` option that executes tests in random order.
  The :option:`-r` option also reports the seed that was used
  (Added by Collin Winter.)

* Another :file:`regrtest.py` switch is :option:`-j`, which
  takes an integer specifying how many tests run in parallel. This
  allows reducing the total runtime on multi-core machines.
  This option is compatible with several other options, including the
  :option:`-R` switch which is known to produce long runtimes.
  (Added by Antoine Pitrou, :issue:`6152`.)  This can also be used
  with a new :option:`-F` switch that runs selected tests in a loop
  until they fail.  (Added by Antoine Pitrou; :issue:`7312`.)

* When executed as a script, the :file:`py_compile.py` module now
  accepts ``'-'`` as an argument, which will read standard input for
  the list of filenames to be compiled.  (Contributed by Piotr
  Ożarowski; :issue:`8233`.)

.. ======================================================================

Porting to Python 2.7
=====================

This section lists previously described changes and other bugfixes
that may require changes to your code:

* The :func:`range` function processes its arguments more
  consistently; it will now call :meth:`__int__` on non-float,
  non-integer arguments that are supplied to it.  (Fixed by Alexander
  Belopolsky; :issue:`1533`.)

* The string :meth:`format` method changed the default precision used
  for floating-point and complex numbers from 6 decimal
  places to 12, which matches the precision used by :func:`str`.
  (Changed by Eric Smith; :issue:`5920`.)

* Because of an optimization for the :keyword:`with` statement, the special
  methods :meth:`__enter__` and :meth:`__exit__` must belong to the object's
  type, and cannot be directly attached to the object's instance.  This
  affects new-style classes (derived from :class:`object`) and C extension
  types.  (:issue:`6101`.)

* Due to a bug in Python 2.6, the *exc_value* parameter to
  :meth:`__exit__` methods was often the string representation of the
  exception, not an instance.  This was fixed in 2.7, so *exc_value*
  will be an instance as expected.  (Fixed by Florent Xicluna;
  :issue:`7853`.)

* When a restricted set of attributes were set using ``__slots__``,
  deleting an unset attribute would not raise :exc:`AttributeError`
  as you would expect.  Fixed by Benjamin Peterson; :issue:`7604`.)

In the standard library:

* Operations with :class:`datetime` instances that resulted in a year
  falling outside the supported range didn't always raise
  :exc:`OverflowError`.  Such errors are now checked more carefully
  and will now raise the exception. (Reported by Mark Leander, patch
  by Anand B. Pillai and Alexander Belopolsky; :issue:`7150`.)

* When using :class:`Decimal` instances with a string's
  :meth:`format` method, the default alignment was previously
  left-alignment.  This has been changed to right-alignment, which might
  change the output of your programs.
  (Changed by Mark Dickinson; :issue:`6857`.)

  Comparisons involving a signaling NaN value (or ``sNAN``) now signal
  :const:`InvalidOperation` instead of silently returning a true or
  false value depending on the comparison operator.  Quiet NaN values
  (or ``NaN``) are now hashable.  (Fixed by Mark Dickinson;
  :issue:`7279`.)

* The ElementTree library, :mod:`xml.etree`, no longer escapes
  ampersands and angle brackets when outputting an XML processing
  instruction (which looks like `<?xml-stylesheet href="#style1"?>`)
  or comment (which looks like `<!-- comment -->`).
  (Patch by Neil Muller; :issue:`2746`.)

* The :meth:`readline` method of :class:`StringIO` objects now does
  nothing when a negative length is requested, as other file-like
  objects do.  (:issue:`7348`).

* The :mod:`syslog` module will now use the value of ``sys.argv[0]`` as the
  identifier instead of the previous default value of ``'python'``.
  (Changed by Sean Reifschneider; :issue:`8451`.)

* The :mod:`tarfile` module's default error handling has changed, to
  no longer suppress fatal errors.  The default error level was previously 0,
  which meant that errors would only result in a message being written to the
  debug log, but because the debug log is not activated by default,
  these errors go unnoticed.  The default error level is now 1,
  which raises an exception if there's an error.
  (Changed by Lars Gustäbel; :issue:`7357`.)

* The :mod:`urlparse` module's :func:`~urlparse.urlsplit` now handles
  unknown URL schemes in a fashion compliant with :rfc:`3986`: if the
  URL is of the form ``"<something>://..."``, the text before the
  ``://`` is treated as the scheme, even if it's a made-up scheme that
  the module doesn't know about.  This change may break code that
  worked around the old behaviour.  For example, Python 2.6.4 or 2.5
  will return the following:

    >>> import urlparse
    >>> urlparse.urlsplit('invented://host/filename?query')
    ('invented', '', '//host/filename?query', '', '')

  Python 2.7 (and Python 2.6.5) will return:

    >>> import urlparse
    >>> urlparse.urlsplit('invented://host/filename?query')
    ('invented', 'host', '/filename?query', '', '')

  (Python 2.7 actually produces slightly different output, since it
  returns a named tuple instead of a standard tuple.)

For C extensions:

* C extensions that use integer format codes with the ``PyArg_Parse*``
  family of functions will now raise a :exc:`TypeError` exception
  instead of triggering a :exc:`DeprecationWarning` (:issue:`5080`).

* Use the new :c:func:`PyOS_string_to_double` function instead of the old
  :c:func:`PyOS_ascii_strtod` and :c:func:`PyOS_ascii_atof` functions,
  which are now deprecated.

For applications that embed Python:

* The :c:func:`PySys_SetArgvEx` function was added, letting
  applications close a security hole when the existing
  :c:func:`PySys_SetArgv` function was used.  Check whether you're
  calling :c:func:`PySys_SetArgv` and carefully consider whether the
  application should be using :c:func:`PySys_SetArgvEx` with
  *updatepath* set to false.
