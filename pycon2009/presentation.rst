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

__builtin__ 
===========

Let us start with the __builtin__ functions and exceptions which Python Standard Library defines.

::

        >>>import __builtin__
        >>>dir(__builtin__)


all 
^^^
This would list the various functions and exceptions that are available to the interpreter.
Let us look into certain important ones::

        >>> all([True,True,True,True])
        True
        >>> all([False,True,True,True])
        False
any
^^^
::
        >>> any([False,False,False,True])
        True
        >>> any([False,False,False,False])
        False

callable(object)
^^^^^^^^^^^^^^^^
    Return True if the object argument appears callable, False if not. If this
    returns true, it is still possible that a call fails, but if it is false,
    calling object will never succeed. Note that classes are callable (calling
    a class returns a new instance); class instances are callable if they have
    a __call__() method.

staticmethod
^^^^^^^^^^^^


In Object Oriented Programming, you create a method which gets associated
either with  a class or with an instance of the class, namely an object.  This
is concept is the first thing to understand.

And most often in our regular practice, we always create methods to be
associated with an object. Those are called instance methods.

For e.g::

        class Car:
                def cartype(self):
                        self.model = "Audi"
        mycar = Car()
        mycar.cartype()
        print mycar.model

Here cartype() is an instance method, it associates itself with an instance
(mycar) of the class (Car) and that is defined by the first argument ('self').

When you want a method not to be associated with an instance, you call that as
a staticmethod.

How can you do such a thing in Python?

The following would never work::

        >>> class Car:
        ... 	def getmodel():
        ... 		return "Audi"
        ... 	def type(self):
        ... 		self.model = getmodel()

Because, getmodel() is defined inside the class, Python binds it to the Class Object. 
You cannot call it by the following way also, namely: Car.getmodel()  or
Car().getmodel() , because in this case we are passing it through an instance (
Class Object or a Instance Object) as one of the argument while our definition
does not take any argument.

As you can see, there is a conflict here and in effect the case is, It is an
"unbound local method" inside the class.

Now comes Staticmethod.

Now, in order to call getmodel(), you can to change it to a static method.

::
        >>> class Car:
        ... 	def getmodel():
        ... 		return "Audi"
        ...     getmodel = staticmethod(getmodel)
        ... 	def cartype(self):
        ... 		self.model = Car.getmodel()
        ... 		
        >>> mycar = Car()
        >>> mycar.cartype()
        >>> mycar.model
        'Audi'

Now, I have called it as Car.getmodel() even though my definition of getmodel
did not take any argument. This is what staticmethod function did.  getmodel()
is a method which does not need an instance now, but still you do it as
Car.getmodel() because getmodel() is still bound to the Class object. 

Decorators
^^^^^^^^^^
getmodel = staticmethod(getmodel)

If you look at the previous code example, the function staticmethod took a
function as a argument and returned a function which we assigned to a variable
(named as SAME functionname) and made it a function. Correct?

staticmethod() function thus wrapped our getmodel function with some extra
features and this wrapping is called as Decorator.

The same code can be written like this.

::

        >>> class Car:
        ... 	@staticmethod
        ... 	def getmodel():
        ... 		return "Audi"
        ... 	def cartype(self):
        ... 		self.model = Car.getmodel()
        ... 		
        >>> mycar = Car()
        >>> mycar.cartype()
        >>> mycar.model
        'Audi'

Good reference on Decorators would be:
http://personalpages.tds.net/~kent37/kk/00001.html

Please remember that this concept of Decorator is independent of staticmethod
and classmethod.

classmethod
^^^^^^^^^^^

Now, what is a difference between staticmethod and classmethod?

In languages like Java,C++, both the terms denote the same :- methods for which
we do not require instances. But there is a difference in Python. A class
method receives the class it was called on as the first argument. This can be
useful with subclasses.

We can see the above example with the classmethod and a decorator as:

::

        >>>
        >>> class Car:
        ... 	@classmethod
        ... 	def getmodel(cls):
        ... 		return "Audi"
        ... 	def gettype(self):
        ... 		self.model = Car.getmodel()
        ... 		
        >>> mycar = Car()
        >>> mycar.gettype()
        >>> mycar.model
        'Audi'

The following are the references in order to understand further:
1) Alex-Martelli explaining it with code: http://code.activestate.com/recipes/52304/
2)  Decorators: http://personalpages.tds.net/~kent37/kk/00001.html


BaseHTTPServer
==============

.. literalinclude::        BaseHTTPServer_GET.py
.. literalinclude::        BaseHTTPServer_POST.py
.. literalinclude::        BaseHTTPServer_errors.py
.. literalinclude::        BaseHTTPServer_threads.py

anydbm
======

.. literalinclude::        anydbm_usage.py

asyncore
========

.. literalinclude::        asyncore_1.py

basehttpsever
=============

.. literalinclude::        basehttpserver-example-1.py

compile
=======

.. literalinclude::        compile_1.py

configparser
============

.. literalinclude::        configparser_example.py

doctest
=======

.. literalinclude::        doctest_demo.py
.. literalinclude::        doctest_fromtxt.py

snippet
=======

.. literalinclude::        download_url_1.py

ellipsis
========

.. literalinclude::        ellipsis_usage.py

glob
====

.. literalinclude::        glob_all.py
.. literalinclude::        glob_charrange.py
.. literalinclude::        glob_maketestdata.py
.. literalinclude::        glob_singlewildchar.py
.. literalinclude::        glob_subdir.py

logging
=======

.. literalinclude::        logging_default.py
.. literalinclude::        logging_levels.py
.. literalinclude::        logging_modules_example.py
.. literalinclude::        logging_rotatinglogfile.py

os module
=========

.. literalinclude::        os_chmod_11.py
.. literalinclude::        os_directories_12.py
.. literalinclude::        os_module_1.py
.. literalinclude::        os_module_2.py
.. literalinclude::        os_module_3.py
.. literalinclude::        os_module_4.py
.. literalinclude::        os_module_ex5.py
.. literalinclude::        os_module_popen2_8.py
.. literalinclude::        os_module_popen3_6.py
.. literalinclude::        os_module_popen4_7.py
.. literalinclude::        os_permissions_9.py
.. literalinclude::        os_stat_10.py
.. literalinclude::        os_symlink_13.py

property
========

.. literalinclude::        property_1.py

shortcuts
=========

.. literalinclude::        shortcut_copy.py
.. literalinclude::        shortcut_shorten.py

shutil
======

.. literalinclude::        list_of_files.py
.. literalinclude::        shutil_copy.py
.. literalinclude::        shutil_copy2.py
.. literalinclude::        shutil_copyfile.py
.. literalinclude::        shutil_copyfileobj.py
.. literalinclude::        shutil_copymode.py
.. literalinclude::        shutil_copystat.py
.. literalinclude::        shutil_copytree.py
.. literalinclude::        shutil_move.py
.. literalinclude::        shutil_rmtree.py

simplexmlprcserver
==================

.. literalinclude::        simplexmlrpcserver.py
.. literalinclude::        simplexmlrpcserver_dottednames.py
.. literalinclude::        simplexmlrpcserver_introspection.py

smtpd and smtplib
=================
.. literalinclude::        smtpd_custom.py
.. literalinclude::        smtplib_senddata.py

socket
======
.. literalinclude::        socket_echo_client.py
.. literalinclude::        socket_echo_server.py
.. literalinclude::        socket_irclogger.py

string
======
.. literalinclude::        string_1.py

subprocess
==========
.. literalinclude::        subprocess_1.py
.. literalinclude::        subprocess_2.py
.. literalinclude::        subprocess_3.py

super
=====
.. literalinclude::        super_mro_3.py
.. literalinclude::        super_mro_4.py
.. literalinclude::        super_type_1.py
.. literalinclude::        super_type_2.py

threading
=========
.. literalinclude::        threadin_1.py
.. literalinclude::        threadin_2.py
.. literalinclude::        threadin_2_14.py
.. literalinclude::        threading_1_12.py
.. literalinclude::        threading_3.py
.. literalinclude::        threading_4.py
.. literalinclude::        threading_4_client.py
.. literalinclude::        threading_alive_8.py
.. literalinclude::        threading_bankexample_15.py
.. literalinclude::        threading_client_5.py
.. literalinclude::        threading_function_as_thread_11.py
.. literalinclude::        threading_join_9.py
.. literalinclude::        threading_names_7.py
.. literalinclude::        threading_server_6.py
.. literalinclude::        threading_setdaemon_10.py
.. literalinclude::        threading_simplest_thread_13.py

time
====
.. literalinclude::        time_1.py
.. literalinclude::        time_2.py
.. literalinclude::        time_ex2.py
.. literalinclude::        time_parsing_time.py
.. literalinclude::        time_struct_time.py
.. literalinclude::        time_timezone.py

unittest
========
.. literalinclude::        unittest_howto.py

urllib
======
.. literalinclude::        urllib_encoded_args.py
.. literalinclude::        urllib_filelike.py
.. literalinclude::        urllib_get.py
.. literalinclude::        urllib_pathname.py
.. literalinclude::        urllib_post.py
.. literalinclude::        urllib_quote_unquote.py
.. literalinclude::        urllib_urlretrieve.py

xmlrpclib
=========
.. literalinclude::        xmlrpclib_client.py
.. literalinclude::        xmlrpclib_dottednames_client.py
.. literalinclude::        xmlrpclib_introspection.py

=====
TODO:
=====
1) collections module
2) What are the mapping object other than the dictionary?
3) Discuss super() properly.
4) regex module examples - Howto/



Notes
=====

A new style class is one that is derived, either directly or indirectly, from a built-in type. (Something that was not possible at all before python 2.2) Built-in types include types such as:

* int
* list
* tuple
* dict
* str
* and others

The base class for new style class is called object.
Here is what the new style classes have to offer:
* Properties: Attributes that are defined by get/set methods.
* staticmethods and classmethods
* The __getattribute__ hook, which unlike __getattr__, is called for every attribute access, not just when the attribute can't be found in the instance.
* Descriptors: A protocol to define the behavior of attribute access through objects.
* Overriding the constructor __new__
* Metaclasses.


What exactly is a descriptor?

In general, a descriptor is an object attribute with "binding behavior", one whose attribute access has been overridden by methods in the descriptor protocol. Those methods are __get__, __set__, and __delete__. If any of those methods are defined for an object, it is said to be a descriptor.


==========
Exceptions
==========

* Exceptions are Classes and are __builtin__ to the interpreter.
* Until 1.5, simple string messages were exceptions.
* The exception classes are defined in a hierarchy, related exceptions can be caught by catching their base classes.

*BaseException*
Baseclass for all exceptions. Implements logic for creating the string
representation of the exception using the str() from the arguments passed to
the constructor.

*Exception*
Baseclass for the exception that do not result in quitting the running application. All user-defined exceptions should use Exception as a base class.
*StandardError*
Baseclass for builtin exceptions used in Standard Library.
*ArthimeticError*
Baseclass for math related errors.
*LookupError*
When something cannot be found.

*EnvironmentError*
Base class for errors that come from outside of Python (the operating system, filesystem, etc.).

*AssertionError*

An AssertionError is raised by a failed assert statement.

::
        >>>assert False, 'The assertion failed'
        >>># This should throw a simple AssertionError

*AttributeError*

When an attribute reference or assignment fails, AttributeError is raised.

::
        >>> x = "PyCon 2009"
        >>> x.imag
        >>> # This would throw AttributeError


AttributeError will also be raised when trying to modify a read-only attribute.

::

        class MyClass(object):
            
            @property
                def attribute(self):
                        return 'This is the attribute value'

                        o = MyClass()
                        print o.attribute
                        o.attribute = 'New value'

*EOFError*
An EOFError is raised when a builtin function like input() or raw_input() do
not read any data before encountering the end of their input stream. 

*IOError*

Raised when input or output fails, for example if a disk fills up or an input file does not exist.

::
        f = open('/does/not/exist', 'r')

*ImportError*

Raised when a module, or member of a module, cannot be imported.

*IndexError*

An IndexError is raised when a sequence reference is out of range.

::

        my_seq = [ 0, 1, 2 ]
        print my_seq[3]

*KeyError*
a KeyError is raised when a value is not found as a key of a dictionary.

::
        d = { 'a':1, 'b':2 }
        print d['c']

*KeyboardInterrupt*

A KeyboardInterrupt occurs whenever the user presses Ctrl-C (or Delete) to stop
a running program. Unlike most of the other exceptions, KeyboardInterrupt
inherits directly from BaseException to avoid being caught by global exception
handlers that catch Exception.

::

        try:
            print 'Press Return or Ctrl-C:',
            ignored = raw_input()
        except Exception, err:
            print 'Caught exception:', err
        except KeyboardInterrupt, err:
            print 'Caught KeyboardInterrupt'
        else:
            print 'No exception'

*MemoryError*

If your program runs out of memory and it is possible to recover (by deleting
some objects, for example), a MemoryError is raised.

::

        import itertools

        # Try to create a MemoryError by allocating a lot of memory
        l = []
        for i in range(3):
            try:
                for j in itertools.count(1):
                    print i, j
                    l.append('*' * (2**30))
            except MemoryError:
                print '(error, discarding existing list)'
                l = []

NameError

NameErrors are raised when your code refers to a name that does not exist in
the current scope. For example, an unqualified variable name.

NotImplementedError

User-defined base classes can raise NotImplementedError to indicate that a
method or behavior needs to be defined by a subclass, simulating an interface.


== os module ==

File Descriptors

The os module includes the standard set of functions for working with low-level
file descriptors (integers representing open files owned by the current
process). This is a lower-level API than is provided by file() objects. I am
going to skip over describing them here, since it is generally easier to work
directly with file() objects. Refer to the library documentation for details if
you do need to use file descriptors.

