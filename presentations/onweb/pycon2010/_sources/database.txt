Dealing with Databases
======================

There are only two kinds of computer programs: toy programs and programs that
interact with some kind of persistent databases.

* sqllite database is included as part of Python's standard library.
* Python provides a number of built-in facilities for storing and retrieving data. pickle module should be used always and marshal exists for the purposes of 'pyc' files.


using sqlite3
-------------

SQLite is a C library that provides a lightweight disk-based database that
doesn't require a separate server process and allows accessing the database
using a nonstandard variant of the SQL query language. Some applications can use
SQLite for internal data storage.  It's also possible to prototype an
application using SQLite and then port the code to a larger database such as
PostgreSQL or Oracle.

To use the module, you must first create a :class:`Connection` object that
represents the database.  Here the data will be stored in the
:file:`/tmp/example` file::

   conn = sqlite3.connect('/tmp/example')

You can also supply the special name ``:memory:`` to create a database in RAM.

Once you have a :class:`Connection`, you can create a :class:`Cursor`  object
and call its :meth:`Cursor.execute` method to perform SQL commands


.. literalinclude:: py31/howto13_sqlite_example.py

pickle module
-------------

In python3, The pickle module has an transparent optimizer (_pickle) written in
C. It is used whenever available. Otherwise the pure Python implementation is
used. 

In python2, there is a pure python pickle and a C implementation cPickle.

There are currently 4 different protocols which can be used for pickling.

    * Protocol version 0 is the original human-readable protocol and is backwards compatible with earlier versions of Python.
    * Protocol version 1 is the old binary format which is also compatible with earlier versions of Python.
    * Protocol version 2 was introduced in Python 2.3. It provides much more efficient pickling of new-style classes.
    * Protocol version 3 was added in Python 3.0. It has explicit support for bytes and cannot be unpickled by Python 2.x pickle modules. This is the current recommended protocol, use it whenever it is possible.

Refer to PEP 307 for information about improvements brought by protocol 2. See pickletools‘s source code for extensive comments about opcodes used by pickle protocols.

The following can be pickled.

    * None, True, and False
    * integers, floating point numbers, complex numbers
    * strings, bytes, bytearrays
    * tuples, lists, sets, and dictionaries containing only picklable objects
    * functions defined at the top level of a module
    * built-in functions defined at the top level of a module
    * classes that are defined at the top level of a module
    * instances of such classes whose __dict__ or __setstate__() is picklable (see section Pickling Class Instances for details)
 

For the simplest code, use the :func:`dump` and :func:`load` functions.

.. literalinclude:: py31/howto14_pickle_example.py
