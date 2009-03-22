===============
builtin modules
===============

Let us start with the __builtin__ functions and exceptions which Python
Standard Library defines.::

        >>>import __builtin__
        >>>dir(__builtin__)


all 
===

This would list the various functions and exceptions that are available to the interpreter.
Let us look into certain important ones::

        >>> all([True,True,True,True])
        True
        >>> all([False,True,True,True])
        False
any
===
::
        >>> any([False,False,False,True])
        True
        >>> any([False,False,False,False])
        False

callable(object)
================

Return True if the object argument appears callable, False if not. If this
returns true, it is still possible that a call fails, but if it is false,
calling object will never succeed. Note that classes are callable (calling a
class returns a new instance); class instances are callable if they have a
__call__() method.

staticmethod
============

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
==========

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
===========

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

ellipsis
========

* ellipsis is another builtin. It is only used in slicing.

property
========

.. literalinclude::        property_1.py

super
=====
.. literalinclude::        super_mro_3.py
.. literalinclude::        super_mro_4.py
.. literalinclude::        super_type_1.py
.. literalinclude::        super_type_2.py


compile
=======

.. literalinclude::        compile_1.py

Exceptions
==========

* Exceptions are Classes and are __builtin__ to the interpreter.
* Until 1.5, simple string messages were exceptions.
* The exception classes are defined in a hierarchy, related exceptions can be caught by catching their base classes.

BaseException
^^^^^^^^^^^^^

Baseclass for all exceptions. Implements logic for creating the string
representation of the exception using the str() from the arguments passed to
the constructor.

Exception
^^^^^^^^^

Baseclass for the exception that do not result in quitting the running
application. All user-defined exceptions should use Exception as a base class.

StandardError
^^^^^^^^^^^^^
Baseclass for builtin exceptions used in Standard Library.

ArthimeticError
^^^^^^^^^^^^^^^

Baseclass for math related errors.

LookupError
^^^^^^^^^^^

When something cannot be found.

EnvironmentError
^^^^^^^^^^^^^^^^

Base class for errors that come from outside of Python (the operating system,
filesystem, etc.).

AssertionError
^^^^^^^^^^^^^^

An AssertionError is raised by a failed assert statement.

::
        >>>assert False, 'The assertion failed'
        >>># This should throw a simple AssertionError

AttributeError
^^^^^^^^^^^^^^

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

EOFError
^^^^^^^^

An EOFError is raised when a builtin function like input() or raw_input() do
not read any data before encountering the end of their input stream. 

IOError
^^^^^^^

Raised when input or output fails, for example if a disk fills up or an input file does not exist.

::
        f = open('/does/not/exist', 'r')

importError
^^^^^^^^^^^

Raised when a module, or member of a module, cannot be imported.

IndexError
^^^^^^^^^^

An IndexError is raised when a sequence reference is out of range.

::

        my_seq = [ 0, 1, 2 ]
        print my_seq[3]

KeyError
^^^^^^^^
A KeyError is raised when a value is not found as a key of a dictionary.

::
        d = { 'a':1, 'b':2 }
        print d['c']

KeyboardInterrupt
^^^^^^^^^^^^^^^^^

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

MemoryError
^^^^^^^^^^^

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
^^^^^^^^^

NameErrors are raised when your code refers to a name that does not exist in
the current scope. For example, an unqualified variable name.

NotImplementedError
^^^^^^^^^^^^^^^^^^^

User-defined base classes can raise NotImplementedError to indicate that a
method or behavior needs to be defined by a subclass, simulating an interface.
