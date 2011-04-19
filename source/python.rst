============
Python Notes
============

.. warning:: 
        Rough Notes.

Python's mercurial process
==========================

* update all codelines using your script.
* start working on 3.1 codeline and fix and commit and push. It will push it 3.2
* hg pull -u ../3.1
* hg merge 3.1
* resolve any conflicts.
* do the same for cpython
* hg push will commit your changes.


Bring your Repo in sync with main
=================================

* hg pull ../cpython (-u wont work)
* hg merge
* hg commit
* hg push


Discussion on Bugs
==================

* ZipFile with encoded file name has some problems. 
* peephole optimizer to reverse store/unstore instead of pack/unpack. 
* Wrong powerpc defined in ceval. 
* unittest should have assertChanges context manager. 
* shutil behaves improperly on Windows, changing the case of the folder, deletes the old folder. 
* Unknown charset for headers in email module. 
* zipfile.py end of central directory detection not robust.
* test_threadsignals was failing on freebsd old version.
* REMOTE_USER collision in wsgiref, the bug was withdrawn. 
* What is a _weakref.proxy?  
* os.getpriority and os.setpriority ? 
* When to use the PY_BEGIN_THREAD and PY_END_THREAD. 
* parser should store the file name as unicode object. 
* What is the difference between UTF-8 and Unicode. 
* test_concurrent futures was failing on FreeBSD, a reboot can help if it has
  old semaphores hanging around. 
* print trace_back throws AttributeError when the exception is None. 
* Subprocess fds when they are closed throw an error. 
* complex builtin help wrongly says that it support NaN and InF. 
* Add a new set of functions to the posixmodule, well written and quick for
  receiving comments and modifying the code. 
* Decimal Module with some dot specific usage. 
* There is  misbehavior in the ContentTooShort Exception from the
  urllib.request. I had assigned it to myself.
* There is cleaning up of pydoc module, a patch by Ron Adam is in the tracker.  
* The filesystem check can be done using os.rename itself.
* Import dbm module http://bugs.python.org/issue9523
* zlib crc32 and alder32 fix in Python27 http://bugs.python.org/issue10276
* Wrapping TextIOWrapper around gzip files
* subprocess.getoutput fails on win32.
* [issue11109] socketserver.ForkingMixIn leaves zombies, also fails to reap all zombies in one pass 
* Get on with this getpass.getpass issue quickly. Fix it in all versions.

Notes from Python3 article
==========================

* Python uses carriage returns to separate statements and a colon and
  indentation to separate code blocks. c++ and Java use semicolons to separate
  statements and curly braces to separate code blocks.

* Python uses try...except blocks to handle exceptions, and the raise statement
  to generate them. Java and c++ use try...catch blocks to handle exceptions,
  and the throw statement to generate them.

* Like c, Python uses == for comparison and = for assignment. Unlike c, Python
  does not support in-line assignment, so there’s no chance of accidentally
  assigning the value you thought you were comparing.

* Due to some legacy issues left over from Python 2, booleans can be treated as
  numbers. True is 1; False is 0.

* The int() function truncates negative numbers towards 0. It’s a true truncate
  function, not a floor function.

* Floating point numbers are accurate to 15 decimal places.

* For lists in python, a better analogy would be the ArrayList class, which can
  hold arbitrary objects and can expand dynamically as new items are added.

* If the negative index is confusing to you, think of it this way: a_list[-n]
  == a_list[len(a_list) - n]. So in this list, a_list[-3] == a_list[5 - 3] ==
  a_list[2].

* For list representation, If it helps, you can think of it this way: reading
  the list from left to right, the first slice index specifies the first item
  you want, and the second slice index specifies the first item you don’t want.
  The return value is everything in between.

* As you might not expect, if the value is not found in the list, the index()
  method will raise an exception.

* Due to historical quirks carried over from Python 2, you can not create an
  empty set with two curly brackets. This actually creates an empty dictionary,
  not an empty set.

* If you call the discard() method with a value that doesn’t exist in the set,
  it does nothing. No error; it’s just a no-op.

* Here’s the difference: if the value doesn’t exist in the set, the remove()
  method raises a KeyError exception.

* A dictionary in Python is like a hash in Perl 5. In Perl 5, variables that
  store hashes always start with a % character. In Python, variables can be
  named anything, and Python keeps track of the datatype internally.

* You can assign None to any variable, but you can not create other NoneType
  objects.

Python Internals
================

Notes from the documentation at
http://tech.blog.aknin.name/category/my-projects/pythons-innards/

* Trying to explain Python's bytecode evaluation.

* What happens when you do ``python -c "print('hello,world')"``

* Python’s binary is executed, the standard C library initialization which
  pretty much any process does happens and then the main function starts
  executing (see its source, ``./Modules/python.c: main``, which soon calls
  ``./Modules/main.c: Py_Main``

* After some mundane initialization stuff (parse arguments, see if environment
  variables should affect behaviour, assess the situation of the standard
  streams and act accordingly, etc), ``./Python/pythonrun.c: Py_Initialize`` is
  called.

* In many ways, this function is what ‘builds’ and assembles together the
  pieces needed to run the CPython machine and makes ‘a process’ into ‘a
  process with a Python interpreter in it’. 

* Among other things, it creates two very important Python data-structures: the
  interpreter state and thread state. It also creates the built-in module sys
  and the module which hosts all builtins. 

* It will execute a single string, since we invoked it with -c. To execute this
  single string, ``./Python/pythonrun.c: PyRun_SimpleStringFlags`` is called.
  This function creates the ``__main__`` namespace, which is ‘where’ our string
  will be executed. After the namespace is created, the string is executed in
  it (or rather, interpreted or evaluated in it). To do that, you must first
  transform the string into something that machine can work on.

* The parser/compiler stage of ``PyRun_SimpleStringFlags`` goes largely like
  this: tokenize and create a Concrete Syntax Tree (CST) from the code,
  transform the CST into an Abstract Syntax Tree (AST) and finally compile the
  AST into a code object using ``./Python/ast.c: PyAST_FromNode``.

* The code object as a binary string of machine code that Python VM’s
  ‘machinary’ can operate on – so now we’re ready to do interpretation (again,
  evaluation in Python’s parlance).

* We have an empty ``__main__``, we have a code object, we want to evaluate it.
  Now what? Now this line: ``Python/pythonrun.c: run_mod, v =
  PyEval_EvalCode(co, globals, locals);`` does the trick. It receives a code
  object and a namespace for globals and for locals (in this case, both of them
  will be the newly created ``__main__`` namespace), creates a frame object
  from these and executes it.

* You remember previously that I mentioned that ``Py_Initialize`` creates a
  thread state, and that we’ll talk about it later? Well, back to that for a
  bit: each Python thread is represented by its own thread state, which (among
  other things) points to the stack of currently executing frames. After the
  frame object is created and placed at the top of the thread state stack, it
  (or rather, the byte code pointed by it) is evaluated, opcode by opcode, by
  means of the (rather lengthy) ``./Python/ceval.c: PyEval_EvalFrameEx``.

* ``PyEval_EvalFrameEx`` takes the frame, extracts opcode (and operands, if
  any,) after opcode, and executes a short piece of C code matching the opcode. 

Opcode looks like this.::

        >>> from dis import dis
        >>> co = compile("spam = eggs - 1", "<string>", "exec")
        >>> dis(co)
          1           0 LOAD_NAME                0 (eggs)
                      3 LOAD_CONST               0 (1)
                      6 BINARY_SUBTRACT
                      7 STORE_NAME               1 (spam)
                     10 LOAD_CONST               1 (None)
                     13 RETURN_VALUE
        >>>


* You “load” the name eggs (where do you load it from? where do you load it
  to?), and also load a constant value (1), then you do a ``“binary subtract”``
  (what do you mean ‘binary’ in this context? between which operands?), and so
  on and so forth.

* As you might have guessed, the names are “loaded” from the globals and locals
  namespaces we’ve seen earlier, and they’re loaded onto an operand stack (not
  to be confused with the stack of running frames), which is exactly where the
  binary subtract will pop them from, subtract one from the other, and put the
  result back on that stack. 

* Look at ``PyEval_EvalFrameEx at ./Python/ceval.c``

* The following piece of code is run when BINARY_SUBTRACT opcode is found.::

        TARGET(BINARY_SUBTRACT)
            w = POP();
            v = TOP();
            x = PyNumber_Subtract(v, w);
            Py_DECREF(v);
            Py_DECREF(w);
            SET_TOP(x);
            if (x != NULL) DISPATCH();
            break;

* After the frame is executed and ``PyRun_SimpleStringFlags`` returns, the main
  function does some cleanup (notably, ``Py_Finalize``), the standard C library
  deinitialization stuff is done (``atexit``), and the process exits.

* Objects are fundamental to the innards of python and Objects are not very
  tightly coupled with anything else in Python.

* Look at the implementation of objects as if they’re unrelated to the ‘rest’,
  as if they’re a general purpose C API for creating an object subsystem. 

* Maybe you will benefit from that line of thought, too: remember these are
  just a bunch of structures and some functions to manipulate them.

* Mostly everything in Python is an object, from integer to dictionaries, from
  user defined classes to built-in ones, from stack frames to code objects. 

* Given a pointer to a piece of memory, the very least you must expect of it to
  treat it as an object are just a couple of fields defined in a C structure
  called ``./Objects/object.h: PyObject.``::

        typedef struct _object {
            Py_ssize_t ob_refcnt;
            struct _typeobject *ob_type;
        } PyObject;

* Many objects extend this structure to accommodate other variables required to
  represent the object’s value, but these two fields must always exist: a
  reference count and type (in special debug builds, a couple other esoteric
  fields are added to track references).

* The reference count is an integer which counts how many times the object is
  referenced. ``>>> a = b = c = object()`` instantiates an empty object and
  binds it to three different names: a, b and c.

* Each of these names creates another reference to it even though the object is
  allocated only once. Binding the object to yet another name or adding the
  object to a list will create another reference – but will not create another
  object!

* There is much more to say about reference counting, but that’s less central
  to the overall object system and more related to Garbage Collection. 

* We can now better understand the ``./Objects/object.h: Py_DECREF`` macro
  we’ve seen used in the introduction and didn’t know how to explain: It simply
  decrements ``ob_refcnt`` (and initiates deallocation, if ``ob_refcnt`` hit
  zero).  That’s all we’ll say about reference counting for now.

* ``ob_type``, a pointer to an object’s type, a central piece of Python’s
  object model.

* Every object has exactly one type, which never changes during the lifetime of the object.

* Possibly most importantly, the type of an object (and only the type of an
  object) determines what can be done with an object.

* When the interpreter evaluates the subtraction opcode, a single C function
  ``(PyNumber_Subtract)`` will be called regardless of whether its operands are
  an integer and an integer, an integer and a float or even something
  nonsensical (subtract an exception from a dictionary).::

        # n2w: the type, not the instance, determines what can be done with an instance
        >>> class Foo(object):
        ...     "I don't have __call__, so I can't be called"
        ...
        >>> class Bar(object):
        ...     __call__ = lambda *a, **kw: 42
        ...
        >>> foo = Foo()
        >>> bar = Bar()
        >>> foo()
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        TypeError: 'Foo' object is not callable
        >>> bar()
        42
        # will adding __call__ to foo help?
        >>> foo.__call__ = lambda *a, **kw: 42
        >>> foo()
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        TypeError: 'Foo' object is not callable
        # how about adding it to Foo?
        >>> Foo.__call__ = lambda *a, **kw: 42
        >>> foo()
        42
        >>>

* How can a single C function be used to handle any kind of object that is
  thrown at it? 

* It can receive a ``void * pointer`` (actually it receives a ``PyObject *``
  pointer, which is also opaque insofar as the object’s data is concerned), but
  how will it know how to manipulate the object it is given? 

* In the object’s type lies the answer. A type is in itself a Python object (it
  also has a reference count and a type of its own, the type of almost all
  types is type), but in addition to the refcount and the type of the type,
  there are many more fields in the C structure describing type objects.

* This page has some information about types as well as type‘s structure’s
  definition, which you can also find it at ``./Include/object.h:
  PyTypeObject``, I suggest you refer to the definition occasionally as you
  read this post.

* Many of the fields a type object has are called slots and they point to
  functions (or to structures that point to a bunch of related functions).

* These functions are what will actually be called when Python C-API functions
  are invoked to operate on an object instantiated from that type.

* So while you think you’re calling ``PyNumber_Subtract`` on both a, say, ``int
  and a float``, in reality what happens is that the types of it operands are
  ``dereferenced`` and the type-specific subtraction function in the
  ‘subtraction’ slot is used. 

* So we see that the C-API functions aren’t generic, but rather rely on types
  to abstract the details away and appear as if they can work on anything
  (valid work is also just to raise a TypeError).

* ``PyNumber_Subtract`` calls a generic two-argument function called
  ``./Object/abstract.c: binary_op``, and tells it to operate on the
  number-like ``slot nb_subtract`` (similar slots exists for other
  functionality, like, say, the number-like slot ``nb_negative`` or the
  sequence-like slot ``sq_length``).  ``binary_op`` is an error-checking
  wrapper around ``binary_op1``, the real ‘do work’ function.
  ``./Objects/abstract.c: binary_op1`` receives
  ``BINARY_SUBTRACT‘s`` operands as v and w, and then tries to dereference
  ``v->ob_type->tp_as_number``, a structure pointing to many numeric slots
  which represents how v can be used as a number.

* ``binary_op1`` will expect to find at ``tp_as_number->nb_subtract`` a C
  function that will either do the subtraction or return the special value
  ``Py_NotImplemented``, to signal that these operands are ‘insubtracticable’ in
  relation to one another (this will cause a TypeError exception to be raised).

* If you want to change how objects behave, you can write an extension in C
  which will statically define its own ``PyObjectType`` structure in code and
  fill the slots away as you see fit. 

* But when we create our own types in Python (make no mistake, ``>>> class
  Foo(list): pass`` creates a new type, class and type are the same thing), we
  don’t manually allocate a C structure and we don’t fill up its slots. 

* How come these types behave just like built-in types? The answer is
  inheritance, where typing plays a significant role. See, Python arrives with
  some built-in types, like ``list or dict``. As we said, these types have a
  certain set of functions populating their slots and thus objects instantiated
  from them behave in a certain way, like a mutable sequence of values or like
  a mapping of keys to values.

* When you define a new type in Python, a new C structure for that type is
  dynamically allocated on the ``heap`` (like any other object) and its slots
  are filled from whichever type it is inheriting, which is also called its
  base

* Since the slots are copied over, the newly created sub-type has mostly
  identical functionality to its base. Python also arrives with a featureless
  base object type called object (``PyBaseObject_Type`` in C), which has mostly
  null slots and which you can extend without inheriting any particular
  functionality.

* You never really ‘create’ a type in pure Python, you always inherit one (if
  you define a class without inheriting anything explicitly, you will
  implicitly inherit object; in Python 2.x, not inheriting anything explicitly
  leads to the creation of a so called ‘classic class’, which is out of our
  scope).

* Of course, you don’t have to inherit everything. You can, obviously, mutate
  the behaviour of a type created in pure Python, as I’ve demonstrated in the
  code snippet earlier in this post. By setting the special method ``__call__``
  on our class Bar, I made instances of that class callable. Someone, sometime
  during the creation of our class, noticed this ``__call__`` method exists and
  wired it into our newly created type’s ``tp_call`` slot.

* ``./Objects/typeobject.c: type_new``, an elaborate and central function, is that
  function. Let’s look at a small line right at the end after the new type has
  been fully created and just before returning ``fixup_slot_dispatchers(type);``. 
 
* This function iterates over the correctly named methods defined for the newly
  created type and wires them to the correct slots in the type’s structure,
  based on their particular name.

* Another thing remains unanswered in the sea of small details: we’ve
  demonstrated already that setting the method ``__call__`` on a type after
  it’s created will also make objects instantiated from that type callable
  (even objects already instantiated from that type)

* Recall that a type is an object, and that the type of a type is type (if your
  head is spinning, try: ``>>> class Foo(list): pass ; type(Foo))``. 

* So when we do stuff to a class, like calling a class, or subtracting a class,
  or, indeed, setting an attribute on a class, what happens is that the ``class’
  object’s ob_type`` member is dereferenced, finding that the class’ type is
  type. 

* Then the ``type->tp_setattro`` slot is used to do the actual attribute
  setting.  So a class, like an integer or a list can have its own
  attribute-setting function. And the type-specific attribute-setting function
  (``./Objects/typeobject.c: type_setattro``) calls the very same function that
  ``fixup_slot_dispatchers`` uses to actually do the fixup work
  (update_one_slot) after it has set a new attribute on a class. 

* How does this code work?::

        >>> a = object()
        >>> class C(object): pass
        ...
        >>> b = C()
        >>> a.foo = 5
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        AttributeError: 'object' object has no attribute 'foo'
        >>> b.foo = 5
        >>>

* How I can set an arbitrary attribute to b, which is an instance of C, which
  is a class inheriting object and not changing anything, and yet I can’t do
  the same with a, an instance of that very same object?

* Some wise crackers can say: b has a ``__dict__`` and a doesn’t, and that’s
  true, but how did this new (and totally non-trivial!) functionality come from
  if I didn’t inherit it?!

* attributes of an object.

* An object’s attributes are other objects related to it and accessible by
  invoking the . (dot) operator, like so: ``>>> my_object.attribute_name``. 

* A type can define one (or more) specially named methods that will customize
  attribute access to its instances and they will be wired into the type’s
  slots using ``fixup_slot_dispatchers`` when the type is created.

* These methods simply store the attribute as a key/value pair (attribute
  name/attribute value) in some object-specific dictionary when an attribute is
  set and retrieve the attribute from that dictionary when an attribute is get
  (or raise an AttributeError if the dictionary doesn’t have a key matching the
  requested attribute’s name).

* Here is an example snippet which presents a particularly surprising behavior of attribute access.::

        >>> print(object.__dict__)
        {'__ne__': <slot wrapper '__ne__' of 'object' objects>, ... , 
        '__ge__': <slot wrapper '__ge__' of 'object' objects>}
        >>> object.__ne__ is object.__dict__['__ne__']
        True
        >>> o = object()
        >>> o.__class__
        <class 'object'>
        >>> o.a = 1
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        AttributeError: 'object' object has no attribute 'a'
        >>> o.__dict__
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        AttributeError: 'object' object has no attribute '__dict__'
        >>> class C:
        ...     A = 1
        ...
        >>> C.__dict__['A']
        1
        >>> C.A
        1
        >>> o2 = C()
        >>> o2.a = 1
        >>> o2.__dict__
        {'a': 1}
        >>> o2.__dict__['a2'] = 2
        >>> o2.a2
        2
        >>> C.__dict__['A2'] = 2
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
        TypeError: 'dict_proxy' object does not support item assignment
        >>> C.A2 = 2
        >>> C.__dict__['A2'] is C.A2
        True
        >>> type(C.__dict__) is type(o2.__dict__)
        False
        >>> type(C.__dict__)
        <class 'dict_proxy'>
        >>> type(o2.__dict__)
        <class 'dict'>
        >>>

* We can see that object (as in, the most basic built-in type which we’ve
  discussed before) has a private dictionary, and we see that stuff we access
  on object as an attribute is identical to what we find in
  ``object.__dict__``.

* Instances of object (o, in the example) don’t support arbitrary attribute
  assignment and don’t have a __dict__ at all, though they do support some
  attribute access (try ``o.__class__, o.__hash__``, etc; these do return things).

* After that we created our own class, C, derived from object and adding an
  attribute A, and saw that A was accessible via ``C.A`` and ``C.__dict__['A']`` just
  the same, as expected.

* We then instantiated o2 from C, and demonstrated that as expected, attribute
  assignment on it indeed mutates its __dict__ and vice versa (i.e., mutations
  to its __dict__ are exposed as attributes).

* We were then probably more surprised to learn that even though attribute
  assignment on the class (C.A2) worked fine, our class’ __dict__ is actually
  read-only. 

* Finally, we saw that our class __dict__ is not of the same type as our
  object’s ``__dict__``, but rather an unfamiliar beast called dict_proxy. And if
  all that wasn’t enough, recall the mystery from the end of Objects 101: if
  plain object instances like o have no __dict__, and C extends object without
  adding anything significant, why do instances of C like o2 suddenly do have a
  ``__dict__``?

* First, we shall look at the implementation of a ``type’s __dict__``. Looking
  at the definition of ``PyObjectType`` (a zesty and highly recommended
  exercise), we see a slot called ``tp_dict``, ready to accept a pointer to a
  dictionary. All types must have this slot, and all types have a dictionary
  placed there when ``./Objects/typeobject.c: PyType_Ready`` is called on them,
  either when the interpreter is first initialized (remember ``Py_Initialize``?
  It invokes ``_Py_ReadyTypes`` which calls ``PyType_Ready`` on all known
  types) or when the type is created dynamically by the user (``type_new``
  calls ``PyType_Ready`` on the newborn type before returning).  
  
* In fact, every name you bind within a class statement will turn up in the
  newly created type’s __dict__ (see ``./Objects/typeobject.c: type_new:
  type->tp_dict = dict = PyDict_Copy(dict);``). 

* These functions use the dictionary each type has and pointed to by tp_dict to
  store/retrieve the attributes, that is, getting attributes on a type is
  directly wired to dictionary assignment for the type instance’s private
  dictionary pointed to by the type’s structure.

* So far I hope it’s been rather simple, and explains types’ attribute
  retrieval.

* Descriptors play a special role in instances’ attribute access.

* An object is said to be a descriptor if it’s type has one or two slots
  (tp_descr_get and/or tp_descr_set) filled with non-NULL value. These slots
  are wired to the special method names __get__, __set__ and __delete__, when
  the type is defined in pure Python (i.e., if you create a class which has a
  __get__ method it will be wired to its tp_descr_get slot, and if you
  instantiate an object from that class, the object is a descriptor).  

* An object is said to be a data descriptor if its type has a non-NULL
  tp_descr_set slot (there’s no particularly special term for a non-data
  descriptor). 

* We’ve defined descriptors, and we know how types’ dictionaries and attribute
  access work.

* Most objects aren’t types, that is to say, their type isn’t type, it’s
  something more mundane like int or dict or a user defined class.

* All these rely on generic attribute access functions, which are either set on
  the type explicitly or inherited from the type’s base when the type is
  created.

* The generic attribute-getting function (``PyObject_GenericGetAttr``) and its
  algorithm is like so: (a) search the accessed instance’s type’s dictionary,
  and then all the type’s bases’ dictionaries. If a data descriptor was found,
  invoke it’s ``tp_desr_get`` function and return the results. If something else is
  found, set it aside (we’ll call it X). (b) Now search the object’s
  dictionary, and if something is found, return it. (c) If nothing was found in
  the object’s dictionary, inspect X, if one was set aside at all; if X is a
  non-data descriptor, invoke it’s ``tp_descr_get`` function and return the result,
  and if it’s a plain object it returns it. (d) Finally, if nothing was found,
  it raise an ``AttributeError`` exception.  
  
* So we learn that descriptors can execute code when they’re accessed as an
  attribute (so when you do ``foo = o.a or o.a = foo``, a runs code).  A powerful
  notion, that, and it’s used in several cases to implement some of Python’s
  more ‘magical’ features. 

* Data-descriptors are even more powerful, as they take precedence over
  instance attributes (if you have an ``object o of class C``, class C has a foo
  data-descriptor and o has a foo instance attribute, when you do o.foo the
  descriptor will take precedence).

* While descriptors are really important and you’re advised to take the time to
  understand them, for brevity and due to the well written resources I’ve just
  mentioned I will explain them no further, other than show you how they behave
  in the interpreter (super simple example!)::

        >>> class ShoutingInteger(int):
        ...     # __get__ implements the tp_descr_get slot
        ...     def __get__(self, instance, owner):
        ...             print('I was gotten from %s (instance of %s)'
        ...                   % (instance, owner))
        ...             return self
        ...
        >>> class Foo:
        ...     Shouting42 = ShoutingInteger(42)
        ...
        >>> foo = Foo()
        >>> 100 - foo.Shouting42
        I was gotten from <__main__.Foo object at 0xb7583c8c> (instance of <class __main__.'foo'>)
        58
        # Remember: descriptors are only searched on types!
        >>> foo.Silent666 = ShoutingInteger(666)
        >>> 100 - foo.Silent666
        -566
        >>>

* We now understand that accessing attribute A on object O instantiated from
  class C1 which inherits C2 which inherits C3 can return A either from O, C1,
  C2 or C3, depending on something called the ``method resolution order``.

* This way of resolving attributes, when coupled with slot inheritance, is
  enough to explain most of Python’s inheritance functionality.

* We’ve seen the definition of ``PyObject``, and it most definitely didn’t have a
  pointer to a dictionary, so where is the reference the object’s dictionary
  stored?

* If you look closely at the definition of ``PyTypeObject``, you will see a
  field called ``tp_dictoffset``.

* This field provides a byte offset into the C-structure allocated for objects
  instantiated from this type; at this offset, a pointer to a regular Python
  dictionary should be found.

* Under normal circumstances, when creating a new type, the size of the memory
  region necessary to allocate objects of that type will be calculated, and
  that size will be larger than the size of vanilla ``PyObject``. 

* The extra room will typically be used (among other things) to store the
  pointer to the dictionary (all this happens in ``./Objects/typeobject.c``:
  ``type_new, see may_add_dict = base->tp_dictoffset == 0``; onwards).::

        >>> class C: pass
        ...
        >>> o = C()
        >>> o.foo = 'bar'
        >>> o
        <__main__.C object at 0x846b06c>
        >>>
        # break into GDB, see 'metablogging'->'tools' above
        Program received signal SIGTRAP, Trace/breakpoint trap.
        0x0012d422 in __kernel_vsyscall ()
        (gdb) p ((PyObject *)(0x846b06c))->ob_type->tp_dictoffset
        $1 = 16
        (gdb) p *((PyObject **)(((char *)0x846b06c)+16))
        $3 = {u'foo': u'bar'}
        (gdb)

* We have created a new class, instantiated an object from it and set some
  attribute on the object (o.foo = 'bar'), broke into gdb, dereferenced the
  object’s type (C) and checked its ``tp_dictoffset`` (it was 16), and then
  checked what’s to be found at the address pointed to by the pointer located
  at 16 bytes’ offset from the object’s C-structure, and indeed we found there
  a dictionary object with the key foo pointing to the value bar.  

* Of course, if you check ``tp_dictoffset`` on a type which doesn’t have a
  __dict__, like object, you will find that it is zero. You sure have a warm
  fuzzy feeling now, don’t you.

* I define a class C inheriting object and doing nothing much else in Python,
  and then I instantiate o from that class, causing the extra memory for the
  dictionary pointer to be allocated at ``tp_dictoffset``.

* I then type in my interpreter ``o.__dict__``, which byte-compiles to the
  ``LOAD_ATTR`` opcode, which causes the ``PyObject_GetAttr`` function to be
  called, which dereferences the type of o and finds the ``slot tp_getattro``,
  which causes the default attribute searching mechanism described earlier in
  this post and implemented in ``PyObject_GenericGetAttr``.

* So when all that happens, what returns my object’s dictionary? I know where
  the dictionary is stored, but I can see that __dict__ isn’t recursively
  inside itself, so there’s a chicken and egg problem here; who gives me my
  dictionary when I access __dict__ if it is not in my dictionary?

* Someone who has precedence over the object’s dictionary – a descriptor. Check
  this out::

        >>> class C: pass
        ...
        >>> o = C()
        >>> o.__dict__
        {}
        >>> C.__dict__['__dict__']
        <attribute '__dict__' of 'C' objects>
        >>> type(C.__dict__['__dict__'])
        <class 'getset_descriptor'>
        >>> C.__dict__['__dict__'].__get__(o, C)
        {}
        >>> C.__dict__['__dict__'].__get__(o, C) is o.__dict__
        True
        >>>

* Seems like there’s something called ``getset_descriptor`` (it’s in
  ``./Objects/typeobject.c``), which are groups of functions implementing the
  descriptor protocol and meant to be attached to an object placed in type’s
  __dict__.

* This descriptor will intercept all attribute access to ``o.__dict__`` on
  instances of this type, and will return whatever it wants, in our case, a
  reference to the dictionary found at the ``tp_dictoffset`` of o. 

* This is also the explanation of the dict_proxy business we’ve seen earlier.
  If in ``tp_dict`` there’s a pointer to a plain dictionary, what causes it to be
  returned wrapped in this read only proxy, and why? The __dict__ descriptor of
  the type’s type type does it.::

        >>> type(C)
        <class 'type'>
        >>> type(C).__dict__['__dict__']
        <attribute '__dict__' of 'type' objects>
        >>> type(C).__dict__['__dict__'].__get__(C, type)
        <dict_proxy object at 0xb767e494>

* This descriptor is a function that wraps the dictionary in a simple object
  that mimics regular dictionaries’ behaviour but only allows read only access
  to the dictionary it wraps.

* And why is it so important to prevent people from messing with a ``type’s
  __dict__``? Because a type’s namespace might hold them specially named
  methods, like ``__sub__``. 

* When you create a type with these specially named methods or when you set
  them on the type as an attribute, the function ``update_one_slot`` will patch
  these methods into one of the type’s slots, as we’ve seen in 101 for the
  subtraction operation.

* If you were to add these methods straight into the type’s __dict__, they
  won’t be wired to any slot, and you’ll have a type that looks like it has a
  certain behaviour (say, has __sub__ in its dictionary), but doesn’t behave
  that way.

* ``__slots__`` are important construct when dealing with attributes access.

* descriptors are objects whose type has their tp_descr_get and/or tp_descr_set
  slots set to non-NULL. However, I also wrote, incorrectly, that descriptors
  take precedence over regular instance attributes (i.e., attributes in the
  object’s __dict__).  This is partly correct but misleading, as it doesn’t
  distinguish non-data descriptors from data-descriptors. An object is said to
  be a data descriptor if its type has its tp_descr_set slot implemented
  (there’s no particularly special term for a non-data descriptor). Only data
  descriptors override regular object attributes, non-data descriptors do not. 

* Look into the Interpreter State and the Thread State structures both
  implemented in `./Python/pystate.c`

* In many operating systems user-space code is executed by an abstraction
  called threads that run inside another abstraction called processes.

* The kernel is in charge of setting up and tearing down these processes and
  execution threads, as well as deciding which thread will run on which logical
  CPU at any given time. 

* When a process invokes Py_Initialize another abstraction comes into play, and
  that is the interpreter.

* Any Python code that runs in a process is tied to an interpreter, you can
  think of the interpreter as the root of all other concepts we’ll discuss.

* Python’s code base supports initializing two (or more) completely separate
  interpreters that share little state with one another. This is rather rarely
  done (never in the vanilla executable), because too much subtly shared state
  of the interpreter core and of C extensions exists between these ‘insulated’
  interpreters. 

* Anyhow, we said all execution of code occurs in a thread (or threads), and
  Python’s Virtual Machine is no exception. 

* However, Python’s Virtual Machine itself is something which supports the
  notion of threading, so Python has its own abstraction to represent Python
  threads. This abstraction’s implementation is fully reliant on the kernel’s
  threading mechanisms, so both the kernel and Python are aware of each Python
  thread and Python threads execute as separate kernel-managed threads, running
  in parallel with all other threads in the system. Uhm, almost.

* Many aspects of Python’s CPython implementation are not thread safe. This is
  has some benefits, like simplifying the implementation of easy-to-screw-up
  pieces of code and guaranteed atomicity of many Python operations, but it
  also means that a mechanism must be put in place to prevent two (or more)
  Pythonic threads from executing in parallel, lest they corrupt each other’s
  data. 

* The GIL is a process-wide lock which must be held by a thread if it wants to
  do anything Pythonic – effectively limiting all such work to a single thread
  running on a single logical CPU at a time. 

* Threads in Python multitask cooperatively by relinquishing the GIL
  voluntarily so other threads can do Pythonic work; this cooperation is
  built-in to the evaluation loop, so ordinarily authors of Python code and
  some extensions don’t need to do something special to make cooperation work
  (from their point of view, they are preempted).

* Do note that while a thread doesn’t use any of Python’s APIs it can (and many
  threads do) run in parallel to another Pythonic thread. 
 
* With the concepts of a process (OS abstraction), interpreter(s) (Python
  abstraction) and threads (an OS abstraction and a Python abstraction) in
  mind, let’s go inside-out by zooming out from a single opcode outwards to the
  whole process. 

* Let’s look again at the disassembly of the bytecode generated for the simple
  statement spam = eggs - 1::

        # what's 'diss'? see 'tools' under 'metablogging' above!
        >>> diss("spam = eggs - 1")
          1           0 LOAD_NAME                0 (eggs)
                      3 LOAD_CONST               0 (1)
                      6 BINARY_SUBTRACT
                      7 STORE_NAME               1 (spam)
                     10 LOAD_CONST               1 (None)
                     13 RETURN_VALUE
        >>>

* In addition to the actual ‘do work’ opcode BINARY_SUBTRACT, we see opcodes
  like LOAD_NAME (eggs) and STORE_NAME (spam).

* It seems obvious that evaluating such opcodes requires some storage room:
  eggs has to be loaded from somewhere, spam has to be stored somewhere.

* The inner-most data structures in which evaluation occurs are the frame
  object and the code object, and they point to this storage room.

* When you’re “running” Python code, you’re actually evaluating frames (recall
  ceval.c: PyEval_EvalFrameEx). 

*  In this code-structure-oriented post, the main thing we care about is the
  ``f_back`` field of the frame object (though many others exist). In ``frame
  n`` this field points to frame n-1, i.e., the frame that called us (the first
  frame that was called in any particular thread, the top frame, points to
  NULL).

* This stack of frames is unique to every thread and is anchored to the
  thread-specific structure ``./Include.h/pystate.h: PyThreadState``, which
  includes a pointer to the currently executing frame in that thread (the most
  recently called frame, the bottom of the stack).

* PyThreadState is allocated and initialized for every Python thread in a
  process by ``_PyThreadState_Prealloc`` just before new thread creation is
  actually requested from the underlying OS (see ``./Modules/_threadmodule.c:
  thread_PyThread_start_new_thread`` and ``>>> from _thread import
  start_new_thread``). 

* Threads can be created which will not be under the interpreter’s control;
  these threads won’t have a ``PyThreadState`` structure and must never call a
  Python API.

* This isn’t so common in a Python application but is more common when Python
  is embedded into another application. It is possible to ‘Pythonize’ such
  foreign threads that weren’t originally created by Python code in order to
  allow them to run Python code (PyThreadState will have to be allocated for
  them). 

* Finally, a bit like all frames are tied together in a backward-going stack of
  previous-frame pointers, so are all thread states tied together in a linked
  list of ``PyThreadState *next`` pointers.

* The list of thread states is anchored to the interpreter state structure
  which owns these threads. The interpreter state structure is defined at
  ./Include.h/pystate.h: PyInterpreterState, and it is created when you call
  Py_Initialize to initialize the Python VM in a process or Py_NewInterpreter
  to create a new interpreter state for multi-interpreter processes.

* Note carefully that Py_NewInterpreter does not return an interpreter state –
  it returns a (newly created) PyThreadState for the single automatically
  created thread of the newly created interpreter. 

* There’s no sense in creating a new interpreter state without at least one
  thread in it, much like there’s no sense in creating a new process with no
  threads in it.

* Similarly to the list of threads anchored to its interpreter, so does the
  interpreter structure have a next field which forms a list by linking the
  interpreters to one another.

* This pretty much sums up our zooming out from the resolution of a single
  opcode to the whole process: opcodes belong to currently evaluating code
  objects (currently evaluating is specified as opposed to code objects which
  are just lying around as data, waiting for the opportunity to be called),
  which belong to currently evaluating frames, which belong to Pythonic
  threads, which belong to interpreters. 

* The anchor which holds the root of this structure is the static variable
  ./Python/pystate.c: interp_head, which points to the first interpreter state
  (through that all interpreters are reachable, through each of them all thread
  states are reachable, and so fourth). 

* The mutex head_mutex protects interp_head and the lists it points to so they
  won’t be corrupt by concurrent modifications from multiple threads (I want it
  to be clear that this lock is not the GIL, it’s just the mutex for
  interpreter and thread states). 

* The macros HEAD_LOCK and HEAD_UNLOCK control this lock. interp_head is
  typically used when one wishes to add/remove interpreters or threads and for
  special purposes. That’s because accessing an interpreter or a thread through
  the head variable would get you an interpreter state rather than the
  interpreter state owning the currently running thread (just in case there’s
  more than one interpreter state).

* A more useful variable similar to interp_head is ./Python/pystate.c:
  _PyThreadState_Current which points to the currently running thread state
  (important terms and conditions apply, see soon).

* This is how code typically accesses the correct interpreter state for itself:
  first find its your own thread’s thread state, then dereference its interp
  field to get to your interpreter.

* There are a couple of functions that let you access this variable (get its
  current value or swap it with a new one while retaining the old one) and they
  require that you hold the GIL to be used.

* This is important, and serves as an example of CPython’s lack of thread
  safety (a rather simple one, others are hairier). If two threads are running
  and there was no GIL, to which thread would this variable point? “The thread
  that holds the GIL” is an easy answer, and indeed, the one that’s used. _

*  _PyThreadState_Current is set during Python’s initialization or during a new
  thread’s creation to the thread state structure that was just created. When a
  Pythonic thread is bootstrapped and starts running for the very first time it
  can assume two things: (a) it holds the GIL and (b) it will find a correct
  value in _PyThreadState_Current. 

* As of that moment the Pythonic thread should not relinquish the GIL and let
  other threads run without first storing _PyThreadState_Current somewhere, and
  should immediately re-acquire the GIL and restore _PyThreadState_Current to
  its old value when it wants to resume running Pythonic code.

* This behaviour is what keeps _PyThreadState_Current correct for GIL-holding
  threads and is so common that macros exist to do the
  save-release/acquire-restore idioms (Py_BEGIN_ALLOW_THREADS and
  Py_END_ALLOW_THREADS). 

* There’s much more to say about the GIL and additional APIs to handle it and
  it’s probably also interesting to contrast it with other Python
  implementation (Jython and IronPython are thread safe and do run Pythonic
  threads concurrently). 

* Diagram shows the relation between the state structures within a single
  process hosting Python as described so far. We have in this example two
  interpreters with two threads each, you can see each of these threads points
  to its own call stack of frames.

.. image:: http://niltowrite.files.wordpress.com/2010/05/states4.png?w=440&h=314

* Interpreter states contain several fields dealing with imported modules of
  that particular interpreter, so we can talk about that when we talk about
  importing.

* In addition to managing imports they hold bunch of pointers related to
  handling Unicode codecs, a field to do with dynamic linking flags and a field
  to do with TSC usage for profiling.

* Thread states have more fields but to me they were more easily understood.
  Not too surprisingly, they have fields that deal with things that relate to
  the execution flow of a particular thread and are of too broad a scope to fit
  particular frame.

* Take for example the fields recursion_depth, overflow and recursion_critical,
  which are meant to trap and raise a RuntimeError during overly deep
  recursions before the stack of the underlying platform is exhausted and the
  whole process crashes. 

* In addition to these fields, this structure accommodates fields related to
  profiling and tracing, exception handling (exceptions can be thrown across
  frames), a general purpose per-thread dictionary for extensions to store
  arbitrary stuff in and counters to do with deciding when a thread ran too
  much and should voluntarily relinquish the GIL to let other threads run.

* Discuss naming, which is the ability to bind names to an object, like we can
  see in the statement a = 1 (in other words, this article is roughly about
  what many languages call variables). 

* Naturally, naming is central to Python's behaviour and understanding both its
  semantics and mechanics are important precursors to our quickly approaching
  discussions of code evaluation, code objects and stack frames.

* That said, it is also a delicate subject because anyone with some programming
  experience knows something about it, at least instinctively (you’ve done
  something like a = 1 before, now haven’t you?).

* When we evaluate a = b = c = [], we create one list and give it three
  different names. In formal terms, we’d say that the newly instantiated list
  object is now bound to three identifiers that refer to it.

* This distinction between names and the objects bound to them is important. If
  we evaluate a.append(1), we will see that b and c are also affected; we
  didn’t mutate a, we mutated its referent, so the mutation is uniformly
  visible via any name the object was referred to.

* On the other hand, if we will now do a b = [], a and c will not change, since
  we didn’t actually change the object which b referred to but rather did a
  re-binding of the name b to a (newly created and empty) list object.

* Also recall that binding is one of the ways to increase the referent’s
  reference count, this is worthy of noting even though reference counting
  isn’t our subject at the moment.

* A name binding is commonly created by use of the assignment statement, which
  is a statement that has an ‘equals’ symbol (=) in the middle, “stuff to
  assign to” or targets on the left, and “stuff to be assigned” (an expression)
  on the right. 

* A target can be a name (more formally called an identifier) or a more complex
  construct, like a sequence of names, an attribute reference
  (primary_name.attribute) or a subscript (primary_name[subscript])

* Name binding is undone with the deletion statement del, which is roughly “del
  followed by comma-separated targets to unbind” 

* Finally, note that name binding can be done without an assignment as bindings
  are also created by def, class, import (and others), this is also of less
  importance to us now.

* Scope is a term relating to the visibility of an identifier throughout a
  block, or a piece of Python code executed as a unit: a module, a function
  body and a class definition are blocks (control-blocks like those of if and
  while are not code blocks in Python).

* A namespace is an abstract environment where the mapping between names and
  the objects they refer to is made (incidentally, in current CPython, this is
  indeed implemented with the dict mapping type).

* The rules of scoping determine in which namespace will a name be sought after
  when it is used, or rather resolved. 

* You probably know instinctively that a name bound in function foo isn’t
  visible in an unrelated function bar, this is because by default names
  created in a function will be stored in a namespace that will not be looked
  at when name resolution happens in another, unrelated function. 

* Scope determines not just when a name will be visible as it is resolved or
  ‘read’ (i.e., if you do spam = eggs, where will eggs come from) but also as
  it is bound or ‘written’ (i.e., in the same example, where will spam go to). 

* When a namespace will no longer be used (for example, the private namespace
  of a function which returns) all the names in it are unbound (this triggers
  reference count decrease and possibly deallocation, but this doesn’t concern
  us now).

* Scoping rules change based on the lexical context in which code is compiled.
  For example, in simpler terms, code compiled as a plain function’s body will
  resolve names slightly differently when evaluated when compared with code
  compiled as part of a module’s initialization code (the module top-level
  code).

* Special statements like global and nonlocal exist and can be applied to names
  thus that resolution rules for these names will change in the current code
  block, we’ll look into that later. 

* When Python code is evaluated, it is evaluated within three namespaces:
  locals, globals and builtins. When we resolve a name, it will be sought after
  in the local scope, then the global scope, then the builtin scope (then a
  NameError will be raised).

* When we bind a name with a name binding statement (i.e., an assignment, an
  import, a def, etc) the name will be bound in the local scope, and hide any
  existing names in the global or builtin scope.

* This hiding does not mean the hidden name was changed (formally: the hidden
  name was not re-bound), it just means it is no longer visible in the current
  block’s scope because the newly created binding in the local namespace
  overshadows it.

* We said scoping changes according to context, and one such case is when
  functions are lexically nested within one another (that is, a function
  defined inside the body of another function): resolution of a name from
  within a nested function will first search in that function’s scope, then in
  the local scopes of its outer function(s) and only then proceed normally (in
  the globals and builtins) scope.

* Lexical scoping is an interesting behaviour, let’s look at it closely::

        $ cat scoping.py ; python3.1
        def outer():
            a = 1
            # creating a lexically nested function bar
            def inner():
                # a is visible from outer's locals
                return a
            b = 2 # b is here for an example later on
            return inner

        # inner_nonlexical will be called from within
        #  outer_nonlexical but it is not lexically nested
        def inner_nonlexical():
            return a # a is not visible
        def outer_nonlexical():
            a = 1
            inner = inner_nonlexical
            b = 2 # b is here for an example later on
            return inner_nonlexical
        >>> from scoping import *
        >>> outer()()
        1
        >>> outer_nonlexical()()
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
          File "scoping.py", line 13, in inner_nonlexical
            return a # a is not visible
        >>>

* As the example demonstrates, a is visible in the lexically nested inner but
  not in the call-stack nested but not lexically nested inner_nonlexical.

* I mean, Python is dynamic, everything is runtime, how does inner_nonlexical
  fail if it has the same Python code and is called in a similar fashion from
  within a similar environment as the original inner was called? 

* Further more, we can see that inner is actually called after outer has
  terminated: how can it use a value from a namespace that was already
  destroyed? 

* Once again, let’s look at the bytecode emitted for the simple statement spam
  = eggs - 1::

        >>> diss("spam = eggs - 1")
          1           0 LOAD_NAME                0 (eggs)
                      3 LOAD_CONST               0 (1)
                      6 BINARY_SUBTRACT
                      7 STORE_NAME               1 (spam)
                     10 LOAD_CONST               1 (None)
                     13 RETURN_VALUE
        >>>

* Recall that BINARY_SUBTRACT will pop two arguments from the value-stack and
  feed them to PyNumber_Subtract, which is a C function that accepts two
  PyObject * pointers and certainly doesn’t know anything about scoping.

* What gets the arguments onto the stack are the LOAD_NAME and LOAD_CONST
  opcodes, and what will take the result out of the stack and into wherever it
  is heading is the STORE_NAME ocopde.

* It is opcodes like this that implement the rules of naming and scoping, since
  the C code implementing them is what will actually look into the dictionaries
  representing the relevant namespaces trying to resolve the name and bring the
  resulting object unto the stack, or store whatever object is to be stored
  into the relevant namespace.

* For example, take LOAD_CONST; this opcode loads a constant value unto the
  value stack, but it isn’t about scoping (constants don’t have a scope, by
  definition they aren’t variables and they’re never ‘hidden’).

* Fortunately for you, I’ve already grepped the sources for ‘suspect’ opcodes
  ($ egrep -o '(LOAD|STORE)(_[A-Z]+)+' Include/opcode.h | sort) and believe
  I’ve mapped out the opcodes that actually implement scoping, so we can
  concentrate on the ones that really implement scoping 

* Note that among the list of opcodes I chose not to address are the ones that
  handles attribute reference and subscripting; I chose so since these opcodes
  rely on a different opcode to get the primary reference (the name before the
  dot or the square brackets) on the value stack and thus aren’t really about
  scoping. 

* We should discuss four pairs of opcode::

        LOAD_NAME and STORE_NAME
        LOAD_FAST and STORE_FAST
        LOAD_GLOBAL and STORE_GLOBAL
        LOAD_DEREF and STORE_DEREF

* I suggest we discuss each pair along with the situations in which the
  compiler chooses to emit an opcode of that pair in order to satisfy the
  semantics of scoping.

* This is not necessarily an exhaustive listing of these opcodes’ uses (it
  might be, I’m not checking if it is or isn’t), but it should develop an
  understanding of these opcodes’ behaviour and allow us to figure out other
  cases where the compiler chooses the emit them on our own; so if you ever see
  any of these in a disassembly, you’ll be covered.

* I’d like to begin with the obvious pair, ``*_NAME``; it is simple to understand
  (and I suspect it was the first to be implemented). Explaining the ``*_NAME``
  pair of opcodes is easiest by writing rough versions of them in Python-like
  psuedocode (you can and should read the actual implementation in
  ``./Python/ceval.c: PyEval_EvalFrameEx``)::

        def LOAD_NAME(name):
            try:
                return current_stack_frame.locals[name]
            except KeyError:
                try:
                    return current_stack_frame.globals[name]
                except KeyError:
                    try:
                        return current_stack_frame.builtins[name]
                    except KeyError:
                        raise NameError('name %r is not defined'
                                         % name)

        def STORE_NAME(name, value):
            current_stack_frame.locals[name] = value

* While they are the ‘vanilla’ case, ``*_NAME``, in some cases they are not
  emitted at all as more specialized opcodes can achieve the same functionality
  in a faster manner. As we explore the other scoping-related opcodes, we will
  see why.

* A commonly used pair of scoping related opcodes is the ``*_FAST`` pair, which
  were originally implemented a long time ago as a speed enhancement over the
  ``*_NAME`` pair. 

* These opcodes are used in cases where compile time analysis can infer that a
  variable is used strictly in the local namespace.

* This is possible when compiling code which is a part of a function, rather
  than, say, at the module level (some subtleties apply about the meaning of
  ‘function’ in this context, a class’ body may also use these opcodes under
  some circumstances, but this is of no interest to us at the moment; also see
  the comments below).

* If we can decide at compile time which names are used in precisely one
  namespace, and that namespace is private to one code block, it may be easy to
  implement a namespace with cheaper machinery than dictionaries.

* Indeed, these opcodes rely on a local namespace implemented with a statically
  sized array, which is far faster than a dictionary lookup as in the global
  namespace and other namespaces.

* In Python 2.x it was possible to confuse the compiler thus that it will not
  be able to use these opcodes in a particular function and have to revert to
  ``*_NAME``, this is no longer possible in Python 3.x (also see the comments).

* Let’s look at the two ``*_GLOBAL`` opcodes. LOAD_GLOBAL (but not
  STORE_GLOBAL) is also generated when the compiler can infer that a name is
  resolved in a function’s body but was never bound inside that body. 

* This behaviour is conceptually similar to the ability to decide when a name
  is both bound and resolved in a function’s body, causing the generation of
  the ``*_FAST`` opcodes as we’ve seen above::

        >>> def func():
        ...     a = 1
        ...     a = b
        ...     return a
        ...
        >>> diss(func)
          2           0 LOAD_CONST               1 (1)
                      3 STORE_FAST               0 (a)
          3           6 LOAD_GLOBAL              0 (b)
                      9 STORE_FAST               0 (a)
          4          12 LOAD_FAST                0 (a)
                     15 RETURN_VALUE
        >>>

* As described for ``*_FAST``, we can see that a was bound within the function,
  which places it in the local scope private to this function, which means the
  ``*_FAST`` opcodes can and are used for a. 

* On the other hand, we can see (and the compiler could also see…) that b was
  resolved before it was ever bound in the function. 

* The compiler figured it must either exist elsewhere or not exist at all,
  which is exactly what LOAD_GLOBAL does: it bypasses the local namespace and
  searches only the global and builtin namespaces (and then raises a
  NameError).

* This explanation leaves us with missing functionality: what if you’d like to
  re-bind a variable in the global scope?

* Recall that binding a new name normally binds it locally, so if you have a
  module defining foo = 1, a function setting foo = 2 locally “hides” the
  global foo. 

* But what if you want to re-bind the global foo? Note this is not to mutate
  object referred to by foo but rather to bind the name foo in the global scope
  to a different referent; if you’re not clear on the distinction between the
  two, skim back in this post until we’re on the same page.

* To do so, we can use the global statement which we mentioned in passing
  before; this statement lets you tell the compiler to treat a name always as a
  global both for resolving and for binding within a particular code block,
  generating only ``*_GLOBAL`` opcodes for manipulation of that name. 

* When binding is required, STORE_GLOBAL performs the new binding (or a
  re-binding) in the global namespace, thus allowing Python code to explicitly
  state which variables should be stored and manipulated in the global scope. 

* What happens if you use a variable locally, and then use the global statement
  to make it global? Let’s look (slightly edited)::

        >>> def func():
        ...     a = 1
        ...     global a
        ...
        <stdin>:3: SyntaxWarning: name 'a' is assigned to before global declaration
        >>> diss(func)
          2           0 LOAD_CONST               1 (1)
                      3 STORE_GLOBAL             0 (a)
          3           6 LOAD_CONST               0 (None)
                      9 RETURN_VALUE
        >>>

* The compiler still treats the name as a global all through the code block,
  but warns you not to shoot yourself (and other maintainers of the code) in
  the foot. Sensible.

* We are left only with LOAD_DEREF and STORE_DEREF. To explain these, we have
  to revisit the notion of lexical scoping, which is what started our
  inspection of the implementation.

* Recall that we said that nested functions’ resolution of names tries the
  namespaces’ of all lexically enclosing functions (in order, innermost
  outwards) before it hits the global namespace, we also saw an example of that
  in code.

* So how did inner return a value resolved from this no-longer-existing
  namespace of outer? When resolution of names is attempted in the global
  namespace (or in builtins), the name may or may not be there, but for sure we
  know that the scope is still there! How do we resolve a name in a scope which
  doesn’t exist?

* The answer is quite nifty, and becomes apparent with a disassembly (slightly
  edited) of both functions::

        # see the example above for the contents of scoping.py
        >>> from scoping import *
        # recursion added to 'diss'; you can see metablogging->tools above
        >>> diss(outer, recurse=True)
          2           0 LOAD_CONST               1 (1)
                      3 STORE_DEREF              0 (a)
          3           6 LOAD_CLOSURE             0 (a)
                      9 BUILD_TUPLE              1
                     12 LOAD_CONST               2 (<code object inner ...)
                     15 MAKE_CLOSURE             0
                     18 STORE_FAST               0 (inner)
          5          21 LOAD_CONST               3 (2)
                     24 STORE_FAST               1 (b)
          6          27 LOAD_FAST                0 (inner)
                     30 RETURN_VALUE
         
        recursing into <code object inner ...>:
          4           0 LOAD_DEREF               0 (a)
                      3 RETURN_VALUE
        >>>

* We can see that outer (the outer function!) already treats a, the variable
  which will be used outside of its scope, differently than it treats b, a
  ‘simple’ variable in its local scope.

* ``a`` is loaded and stored using the ``*_DEREF`` variants of the loading and
  storing opcodes, in both the outer and inner functions. The secret sauce here
  is that at compilation time, if a variable is seen to be resolved from a
  lexically nested function, it will not be stored and will not be accessed
  using the regular naming opcodes.

* Instead, a special object called a cell is created to store the value of the
  object. When various code objects (the outer function, the inner function,
  etc) will access this variable, the use of the ``*_DEREF`` opcodes will cause
  the cell to be accessed rather than the namespace of the accessing code
  object.

* Since the cell is actually accessed only after outer has finished executing,
  you could even define inner before a was defined, and it would still work
  just the same (!).

* This is automagical for name resolution, but for outer scope rebinding the
  nonlocal statement exists. nonlocal was decreed by PEP 3014 and it is
  somewhat similar to the global statement

* ``nonlocal`` explicitly declares a variable to be used from an outer scope
  rather than locally, both for resolution and re-binding. It is illegal to use
  nonlocal outside of a lexically nested function, and it must be nested inside
  a function that defines the identifiers listed by nonlocal. 

* There are several small gotchas about lexical scoping, but overall things
  behave as you would probably expect (for example, you can’t cause a name to
  be used locally and as a lexically nested name in the same code block, as the
  collapsed snippet below demonstrates)::

        >>> def outer():
        ...     a = 1
        ...     def inner():
        ...             b = a
        ...             a = 1
        ...             return a,b
        ...     return inner
        ...
        >>> outer()()
        Traceback (most recent call last):
          File "<stdin>", line 1, in <module>
          File "<stdin>", line 4, in inner
        UnboundLocalError: local variable 'a' referenced before assignment
        >>>

* This sums up the mechanics of naming and scoping. 

* The compilation of Python source code emits Python bytecode, which is
  evaluated at runtime to produce whatever behaviour the programmer
  implemented.

* I guess you can think of bytecode as ‘machine code for the Python virtual
  machine’, and indeed if you look at some binary x86 machine code (like this
  one: 0x55 0x89 0xe5 0xb8 0x2a 0x0 0x0 0x0 0x5d) and some Python bytecode
  (like that one: 0x64 0x1 0x0 0x53) they look more or less like the same sort
  of gibberish. 

* The bytecode and these fields are lumped together in an object called a code
  object, our subject for this article.

* You might initially confuse function objects with code objects, but
  shouldn’t. Functions are higher level creatures that execute code by relying
  on a lower level primitive, the code object, but adding more functionality on
  top of that (in other words, every function has precisely one code object
  directly associated with it, this is the function’s __code__ attribute, or
  f_code in Python 2.x).

* For example, among other things, a function keeps a reference to the global
  namespace (remember that?) in which it was originally defined, and knows the
  default values of arguments it receives. 

* You can sometimes execute a code objects without a function (see eval and
  exec), but then you will have to provide it with a namespace or two to work
  in. 

* Finally, just for accuracy’s sake, please note that tp_call of a function
  object isn’t exactly like exec or eval; the latter don’t pass in arguments or
  provide free argument binding (more below on these).

* If this doesn’t sit well with you yet, don’t panic, it just means functions’
  code objects won’t necessarily be executable using eval or exec. I hope we
  have that settled.

* A piece of Python program text that is executed as a unit. The following are
  blocks: a module, a function body, and a class definition.

* As usual, I don’t want to dig too deeply into compilation, but basically when
  a code block is encountered, it has to be successfully transformed into an
  AST (which requires mostly that its syntax will be correct), which is then
  passed to ./Python/compile.c: PyAST_Compile, the entry point into Python’s
  compilation machinary. 

* You absolutely can’t run this code meaningfully without its constants, and
  indeed 42 is referred to by one of the extra fields of the code object. We
  will best see the interaction between the actual bytecode and the
  accompanying fields as we do a manual disassembly::

        # the opcode module has a mapping of opcode
        #  byte values to their symbolic names
        >>> import opcode
        >>> def return42(): return 42
        ...
        # this is the function's code object
        >>> return42.__code__
        <code object return42 ... >
        # this is the actual bytecode
        >>> return42.__code__.co_code
        b'd\x01\x00S'
        # this is the field holding constants
        >>> return42.__code__.co_consts
        (None, 42)
        # the first opcode is LOAD_CONST
        >>> opcode.opname[return42.__code__.co_code[0]]
        'LOAD_CONST'
        # LOAD_CONST has one word as an operand
        #  let's get its value
        >>> return42.__code__.co_code[1] + \
        ... 256 * return42.__code__.co_code[2]
        1
        # and which constant can we find in offset 1?
        >>> return42.__code__.co_consts[1]
        42
        # finally, the next opcode
        >>> opcode.opname[return42.__code__.co_code[3]]
        'RETURN_VALUE'
        >>>

* In addition to dis, the function show_code from the same module is useful to
  look at code objects::

        >>> diss(return42)
          1           0 LOAD_CONST               1 (42)
                      3 RETURN_VALUE
        >>> ssc(return42)
        Name:              return42
        Filename:          <stdin>
        Argument count:    0
        Kw-only arguments: 0
        Number of locals:  0
        Stack size:        1
        Flags:             OPTIMIZED, NEWLOCALS, NOFREE
        Constants:
           0: None
           1: 42
        >>>

* We see diss and ssc generally agree with our disassembly, though ssc further
  parsed all sorts of other fields of the code object which we didn’t handle so
  far (you can run dir on a code object to see them yourself).

* Code objects are immutable and their fields don’t hold any references
  (directly or indirectly) to mutable objects.

* This immutability is useful in simplifying many things, one of which is the
  handling of nested code blocks.

* An example of a nested code block is a class with two methods: the class is
  built using a code block, and this code block nests two inner code blocks,
  one for each method. 

* This situation is recursively handled by creating the innermost code objects
  first and treating them as constants for the enclosing code object (much like
  an integer or a string literal would be treated). 

* Now that we have seen the relation between the bytecode and a code object
  field (co_consts), let’s take a look at the myriad of other fields in a code
  object.

* Many of these fields are just integer counters or tuples of strings
  representing how many or which variables of various sorts are used in a code
  object. But looking to the horizon where ceval.c and frame object evaluation
  is waiting for us, I can tell you that we need an immediate and crisp
  understanding of all these fields and their exact meaning, subtleties
  included.

* Identity or origin (strings)

co_name
        A name (a string) for this code object; for a function this would be
        the function’s name, for a class this would be the class’ name, etc.
        The compile builtin doesn’t let you specify this, so all code objects
        generated with it carry the name <module>.

co_filename

        The filename from which the code was compiled. Will be <stdin> for code
        entered in the interactive interpreter or whatever name is given as the
        second argument to compile for code objects created with compile.

* Different types of names (string tuples)

co_varnames

        A tuple containing the names of the local variables (including
        arguments). To parse this tuple properly you need to look at co_flags
        and the counter fields listed below, so you’ll know which item in the
        tuple is what kind of variable. In the ‘richest’ case, co_varnames
        contains (in order): positional argument names (including optional
        ones), keyword only argument names (again, both required and optional),
        varargs argument name (i.e., ``*args``), kwds argument name (i.e.,
        ``**kwargs``), and then any other local variable names. So you need to
        look at co_argcount, co_kwonlyargcount and co_flags to fully interpret
        this tuple.

co_cellvars

        A tuple containing the names of local variables that are stored in
        cells (discussed in the previous article) because they are referenced
        by lexically nested functions.

co_freevars

        A tuple containing the names of free variables. Generally, a free
        variable means a variable which is referenced by an expression but
        isn’t defined in it. In our case, it means a variable that is
        referenced in this code object but was defined and will be dereferenced
        to a cell in another code object (also see co_cellvars above and,
        again, the previous article).

co_names

        A tuple containing the names which aren’t covered by any of the other
        fields (they are not local variables, they are not free variables, etc)
        used by the bytecode. This includes names deemed to be in the global or
        builtin namespace as well as attributes (i.e., if you do foo.bar in a
        function, bar will be listed in its code object’s names).


* Counters and indexes (integers)

co_argcount

        The number of positional arguments the code object expects to receive,
        including those with default values. For example, def foo(a, b, c=3):
        pass would have a code object with this value set to three. The code
        object of classes accept one argument which we will explore when we
        discuss class creation.

co_kwonlyargcount

        The number of keyword arguments the code object can receive.

co_nlocals

        The number of local variables used in the code object (including
        arguments).

co_firstlineno

        The line offset where the code object’s source code began, relative to
        the module it was defined in, starting from one. In this (and some but
        not all other regards), each input line typed in the interactive
        interpreter is a module of its own.

co_stacksize

        The maximum size required of the value stack when running this object.
        This size is statically computed by the compiler (./Python/compile.c:
        stackdepth when the code object is created, by looking at all possible
        flow paths searching for the one that requires the deepest value stack.
        To illustrate this, look at the diss and ssc outputs for a = 1 and a =
        [1,2,3]. The former has at most one value on the value stack at a time,
        the latter has three, because it needs to put all three integer
        literals on the stack before building the list.

* Other stuff (various)

co_code
        A string representing the sequence of bytecode instructions, contains a
        stream of opcodes and their operands (or rather, indexes which are used
        with other code object fields to represent their operands, as we saw
        above).

co_consts
        A tuple containing the literals used by the bytecode. Remember
        everything in a code object must be immutable, running diss and ssc on
        the code snippets a=(1,2,3) versus [1,2,3] and yet again versus
        a=(1,2,3,[4,5,6]) recommended to dig this field.

co_lnotab
        A string encoding the mapping from bytecode offsets to line numbers. If
        you happen to really care how this is encoded you can either look at
        ./Python/compile.c or ./Lib/dis.py: findlinestarts.

co_flags
        An integer encoding a number of flags regarding the way this code
        object was created (which says something about how it should be
        evaluated). The list of possible flags is listed in ./Include/code.h,
        as a small example I can give CO_NESTED, which marks a code object
        which was compiled from a lexically nested function. Flags also have an
        important role in the implementation of the __future__ mechanism, which
        is still unused in Python 3.1 at the time of this writing, as no
        “future syntax” exists in Python 3.1. However, even when thinking in
        Python 3.x terms co_flags is still important as it facilitates the
        migration from the 2.x branch. In 2.x, __future__ is used when enabling
        Python 3.x like behaviour (i.e., from __future__ import print_function
        in Python 2.7 will disable the print statement and add a print function
        to the builtins module, just like in Python 3.x). If we come across
        flags from now on (in future posts), I’ll try to mention their
        relevance in the particular scenario.

co_zombieframe
        This field of the PyCodeObject struct is not exposed in the Python
        object; it (optionally) points to a stack frame object. This can aid
        performance by maintaining an association between a code object and a
        stack frame object, so as to avoid reallocation of frames by recycling
        the frame object used for a code object. There’s a detailed comment in
        ./Objects/frameobject.c explaining zombie frames and their reanimation,
        we may mention this issue again when we discuss stack frames.

* The above codeobjects list is not exhaustive. More can be added based on need
  and usage.

* This completes the codeobjects explaination, next will be frameobjects.

* Core of Python’s Virtual Machine, the “actually do work function”
  ./Python/ceval.c: PyEval_EvalFrameEx

* Last hurdle on our way there is to understand the three significant stack
  data structures used for CPython’s code evaluation: the call stack, the value
  stack and the block stack.

* All three stacks are tightly coupled with the frame object, which will also
  be discussed today.

* In computer science, a call stack is a stack data structure that stores
  information about the active subroutines of a computer program… A call stack
  is composed of stack frames (…). These are machine dependent data structures
  containing subroutine state information. Each stack frame corresponds to a
  call to a subroutine which has not yet terminated with a return.

* Since CPython implements a virtual machine, its call stack and stack frames
  are dependant on this virtual machine, not on the physical machine it’s
  running on.

* Python tends to do, this internal implementation detail is exposed to Python
  code, either via the C-API or pure Python, as frame objects
  (./Include/frameobject.h: PyFrameObject). 

* We know that code execution in CPython is really the evaluation
  (interpretation) of a code object, so every frame represents a
  currently-being-evaluated code object. 

* We’ll see (and already saw before) that frame objects are linked to one
  another, thus forming a call stack of frames. 

* Finally, inside each frame object in the call stack there’s a reference to
  two frame-specific stacks (not directly related to the call stack), they are
  the value stack and the block stack.

* The value stack (you may know this term as an ‘evaluation stack’) is where
  manipulation of objects happens when object-manipulating opcodes are
  evaluated

* We have seen the value stack before on various occasions, like in the
  introduction and during our discussion of namespaces. 

* Recalling an example we used before, BINARY_SUBTRACT is an opcode that
  effectively pops the two top objects in the value stack, performs
  PyNumber_Subtract on them and sets the new top of the value stack to the
  result. 

* Namespace related opcodes, like LOAD_FAST or STORE_GLOBAL, load values from a
  namespace to the stack or store values from the stack to a namespace.

* Each frame has a value stack of its own (this makes sense in several ways,
  possibly the most prominent is simplicity of implementation), we’ll see later
  where in the frame object the value stack is stored.

* Python has a notion called a code block, which we have discussed in the
  article about code objects and which is also explained here. Completely
  unrelatedly, Python also has a notion of compound statements, which are
  statements that contain other statements (the language reference defines
  compound statements here). Compound statements consist of one or more
  clauses, each made of a header and a suite. Even if the terminology wasn’t
  known to you until now, I expect this is all instinctively clear to you if
  you have almost any Python experience: for, try and while are a few compound
  statements.

* In various places throughout the code, a block (sometimes “frame block”,
  sometimes “basic block”) is used as a loose synonym for a clause or a suite,
  making it easier to confuse suites and clauses with what’s actually a code
  block or vice versa. 

* Both the compilation code (./Python/compile.c) and the evaluation code
  (./Python/ceval.c) are aware of various suites and have (ill-named) data
  structures to deal with them; but since we’re more interested in evaluation
  in this series, we won’t discuss the compilation-related details much (or at
  all). 

* Whenever I’ll think wording might get confusing, I’ll mention the formal
  terms of clause or suite alongside whatever code term we’re discussing.

* With all this terminology in mind we can look at what’s contained in a frame
  object. 

* Looking at the declaration of ./Include/frameobject.h: PyFrameObject, we find
  (comments were trimmed and edited for your viewing pleasure)::

        typedef struct _frame {
           PyObject_VAR_HEAD
           struct _frame *f_back;   /* previous frame, or NULL */
           PyCodeObject *f_code;    /* code segment */
           PyObject *f_builtins;    /* builtin symbol table */
           PyObject *f_globals;     /* global symbol table */
           PyObject *f_locals;      /* local symbol table */
           PyObject **f_valuestack; /* points after the last local */
           PyObject **f_stacktop;   /* current top of valuestack */
           PyObject *f_trace;       /* trace function */
         
           /* used for swapping generator exceptions */
           PyObject *f_exc_type, *f_exc_value, *f_exc_traceback;
         
           PyThreadState *f_tstate; /* call stack's thread state */
           int f_lasti;             /* last instruction if called */
           int f_lineno;            /* current line # (if tracing) */
           int f_iblock;            /* index in f_blockstack */
         
           /* for try and loop blocks */
           PyTryBlock f_blockstack[CO_MAXBLOCKS];
         
           /* dynamically: locals, free vars, cells and valuestack */
           PyObject *f_localsplus[1]; /* dynamic portion */
        } PyFrameObject;



* We see various fields used to store the state of this invocation of the code
  object as well as maintain the call stack’s structure. 

* Both in the C-API and in Python these fields are all prefixed by ``f_``, though
  not all the fields of the C structure PyFrameObject are exposed in the
  pythonic representation.

* We already mentioned the relation between frame and code objects, so the
  f_code field of every frame points to precisely one code object.

* Insofar as structure goes, frames point backwards thus that they create a
  stack (f_back) as well as point “root-wards” in the interpreter state/thread
  state/call stack structure by pointing to their thread state (f_tstate), as
  explained here. Finally, since you always execute Python code in the context
  of three namespaces (as discussed there), frames have the f_builtins,
  f_globals and f_locals fields to point to these namespaces. 

* Before we dig into the other fields of a frame object, please notice frames
  are a variable size Python object (they are a PyObject_VAR_HEAD). 

* The reason is that when a frame object is created it should be dynamically
  allocated to be large enough to contain references (pointers, really) to the
  locals, cells and free variables used by its code object, as well as the
  value stack needed by the code objects ‘deepest’ branch. 

* Indeed, the last field of the frame object, f_localsplus (locals plus cells
  plus free variables plus value stack…) is a dynamic array where all these
  references are stored. 

* PyFrame_New will show you exactly how the size of this array is computed.

* co_nlocals, co_cellvars, co_freevars and co_stacksize – during evaluation,
  all these ‘dead’ parts of the inert code object come to ‘life’ in space
  allocated at the end of the frame

* As we’ll probably see in the next article, when the frame is evaluated, these
  references at the end of the frame will be used to get (or set) “fast” local
  variables, free variables and cell variables, as well as to the variables on
  the value stack (“fast” locals was explained when we discussed namespaces). 

* Looking back at the commented declaration above and given what I said here, I
  believe you should now understand f_valuestack, f_stacktop and f_localsplus.

* As you can maybe imagine, compound statements sometimes require state to be
  evaluated.

* If we’re in a loop, we need to know where to go in case of a break or a
  continue.

* If we’re raising an exception, we need to know where is the innermost
  enclosing handler (the suite of the closest except header, in more formal
  terms).

* This state is stored in f_blockstack, a fixed size stack of PyTryBlock
  structures which keeps the current compound statement state for us
  (PyTryBlock is not just for try blocks; it has a b_type field to let it
  handle various types of compound statements’ suites). 

* f_iblock is an offset to the last allocated PyTryBlock in the stack. 

* If we need to bail out of the current “block” (that is, the current clause),
  we can pop the block stack and find the new offset in the bytecode from which
  we should resume evaluation in the popped PyTryBlock (look at its b_handler
  and b_level fields). 

* A somewhat special case is a raised exception which exhausts the block stack
  without being caught, as you can imagine, in that case a handler will be
  sought in the block stack of the previous frames on the call stack.

* All this should easily click into place now if you read three code snippets.
  First, look at this disassembly of a for statement (this would look
  strikingly similar for a try statement)::

        >>> def f():
        ...     for c in 'string':
        ...             my_global_list.append(c)
        ...
        >>> diss(f)
         2           0 SETUP_LOOP              27 (to 30)
                     3 LOAD_CONST               1 ('string')
                     6 GET_ITER
               >>    7 FOR_ITER                19 (to 29)
                    10 STORE_FAST               0 (c)
         
         3          13 LOAD_GLOBAL              0 (my_global_list)
                    16 LOAD_ATTR                1 (append)
                    19 LOAD_FAST                0 (c)
                    22 CALL_FUNCTION            1
                    25 POP_TOP
                    26 JUMP_ABSOLUTE            7
               >>   29 POP_BLOCK
               >>   30 LOAD_CONST               0 (None)
                    33 RETURN_VALUE
        >>>

* look at how the opcodes SETUP_LOOP and POP_BLOCK are implemented in
  ./Python/ceval.c.

* Notice that SETUP_LOOP and SETUP_EXCEPT or SETUP_FINALLY are rather similar,
  they all push a block matching the relevant suite unto the block stack, and
  they all utilize the same POP_BLOCK::

        TARGET_WITH_IMPL(SETUP_LOOP, _setup_finally)
        TARGET_WITH_IMPL(SETUP_EXCEPT, _setup_finally)
        TARGET(SETUP_FINALLY)
        _setup_finally:
            PyFrame_BlockSetup(f, opcode, INSTR_OFFSET() + oparg,
                       STACK_LEVEL());
            DISPATCH();
         
        TARGET(POP_BLOCK)
            {
                PyTryBlock *b = PyFrame_BlockPop(f);
                UNWIND_BLOCK(b);
            }
            DISPATCH();

* Finally, look at the actual implementation of ./Object/frameobject.c:
  PyFrame_BlockSetup and ./Object/frameobject.c::

        PyFrame_BlockPop:

        void
        PyFrame_BlockSetup(PyFrameObject *f, int type, int handler, int level)
        {
           PyTryBlock *b;
           if (f->f_iblock >= CO_MAXBLOCKS)
               Py_FatalError("XXX block stack overflow");
           b = &f->f_blockstack[f->f_iblock++];
           b->b_type = type;
           b->b_level = level;
           b->b_handler = handler;
        }
         
        PyTryBlock *
        PyFrame_BlockPop(PyFrameObject *f)
        {
           PyTryBlock *b;
           if (f->f_iblock <= 0)
               Py_FatalError("XXX block stack underflow");
           b = &f->f_blockstack[--f->f_iblock];
           return b;
        }

* If you keep the terminology straight, f_blockstack turns out to be rather
  simple.

* We’re left with the rather esoteric fields, some simpler, some a bit more
  arcane. In the ‘simpler’ range we have f_lasti, an integer offset into the
  bytecode of the last instructions executed (initialized to -1, i.e., we
  didn’t execute any instruction yet).

* This index lets us iterate over the opcodes in the bytecode stream. Heading
  towards the ‘more arcane’ area we see f_trace and f_lineno. f_trace is a
  pointer to a tracing function (see sys.settrace; think implementation of a
  tracer or a debugger). 

* f_lineno contains the line number of the line which caused the generation of
  the current opcode; it is valid only when tracing (otherwise use
  PyCode_Addr2Line).

* Last but not least, we have three exception fields (f_exc_type, f_exc_value
  and f_exc_traceback), which are rather particular to generators so we’ll
  discuss them when we discuss that beast (there’s a longer comment about these
  fields in ./Include/frameobject.h if you’re curious right now).

* On a parting note, we can mention when frames are created. This happens in
  ./Objects/frameobject.c: PyFrame_New, usually called from ./Python/ceval.c:
  PyEval_EvalCodeEx (and ./Python/ceval.c: fast_function, a specialized
  optimization of PyEval_EvalCodeEx).

* Frame creation occurs whenever a code object should be evaluated, which is to
  say when a function is called, when a module is imported (the module’s
  top-level code is executed), whenever a class is defined, for every discrete
  command entered in the interactive interpreter, when the builtins eval or
  exec are used and when the -c switch is used (I didn’t absolutely verify this
  is a 100% exhaustive list, but it think it’s rather complete).

* Looking at the list in the previous paragraph, you probably realized frames
  are created very often, so two optimizations are implemented to make frame
  creation fast: first, code objects have a field (co_zombieframe) which allows
  them to remain associated with a ‘zombie’ (dead, unused) frame object even
  when they’re not evaluated. If a code object was already evaluated once,
  chances are it will have a zombie frame ready to be reanimated by PyFrame_New
  and returned instead of a newly allocated frame (trading some memory to
  reduce the number of allocations). 

* Second, allocated and entirely unused stack frames are kept in a special
  free-list (./Objects/frameobject.c: free_list), frames from this list will be
  used if possible, instead of actually allocating a brand new frame. This is
  all kindly commented in ./Objects/frameobject.c.

* ./Python/ceval.c: PyEval_EvalFrameEx is important function in the Python
  interpreter.

* Well, as I said, this switch can be found in the rather lengthy file ceval.c,
  in the rather lengthy function PyEval_EvalFrameEx, which takes more than half
  the file’s lines (it’s roughly 2,250 lines, the file is about 4,400). 

* PyEval_EvalFrameEx implements CPython’s evaluation loop, which is to say that
  it’s a function that takes a frame object and iterates over each of the
  opcodes in its associated code object, evaluating (interpreting, executing)
  each opcode within the context of the given frame (this context is chiefly
  the associated namespaces and interpreter/thread states). 

* There’s more to ceval.c than PyEval_EvalFrameEx, and we may discuss some of
  the other bits later in this post (or perhaps a follow-up post), but
  PyEval_EvalFrameEx is obviously the most important part of it.

* Having described the evaluation loop in the previous paragraph, let’s see
  what it looks like in C (edited)::

        PyEval_EvalFrameEx(PyFrameObject *f, int throwflag)
        {
            /* variable declaration and initialization stuff */
            for (;;) {
                /* do periodic housekeeping once in a few opcodes */
                opcode = NEXTOP();
                if (HAS_ARG(opcode)) oparg = NEXTARG();
                switch (opcode) {
                    case NOP:
                        goto fast_next_opcode;
                    /* lots of more complex opcode implementations */
                    default:
                        /* become rather unhappy */
                }
                /* handle exceptions or runtime errors, if any */
            }
            /* we are finished, pop the frame stack */
            tstate->frame = f->f_back;
            return retval;
        }

* As you can see, iteration over opcodes is infinite (forever: fetch next
  opcode, do stuff), breaking out of the loop must be done explicitly.

* CPython (reasonably) assumes that evaluated bytecode is correct in the sense
  that it terminates itself by raising an exception, returning a value, etc.
  Indeed, if you were to synthesize a code object without a RETURN_VALUE at its
  end and execute it (exercise to reader: how?1), you’re likely to execute
  rubbish, reach the default handler (raises a SystemError) or maybe even
  segfault the interpreter (I didn’t check this thoroughly, but it looks
  plausible).

* In order for you to be able to get a feel for what more serious opcode
  implementations look like, here’s the (edited) implementation of three more
  opcodes, illustrating a few more principles::

        case BINARY_SUBTRACT:
            w = *--stack_pointer; /* value stack POP */
            v = stack_pointer[-1];
            x = PyNumber_Subtract(v, w);
            stack_pointer[-1] = x; /* value stack SET_TOP */
            if (x != NULL) continue;
            break;
        case LOAD_CONST:
            x = PyTuple_GetItem(f->f_code->co_consts, oparg);
            *stack_pointer++ = x; /* value stack PUSH */
            goto fast_next_opcode;
        case SETUP_LOOP:
        case SETUP_EXCEPT:
        case SETUP_FINALLY:
            PyFrame_BlockSetup(f, opcode, INSTR_OFFSET() + oparg,
                       STACK_LEVEL());
            continue;

* We see several things. First, we see a typical value manipulation opcode,
  BINARY_SUBTRACT. This opcode (and many others) works with values on the value
  stack as well as with a few temporary variables, using CPython’s C-API
  abstract object layer (in our case, a function from the number-like object
  abstraction) to replace the two top values on the value stack with the single
  value resulting from subtraction. 

* As you can see, a small set of temporary variables, such as v, w and x are
  used (and reused, and reused…) as the registers of the CPython VM.

* The variable stack_pointer represents the current bottom of the stack (the
  next free pointer in the stack). This variable is initialized at the
  beginning of the function like so: stack_pointer = f->f_stacktop;

* In essence, together with the room reserved in the frame object for that
  purpose, the value stack is this pointer. To make things simpler and more
  readable, the real (unedited by me) code of ceval.c defines several value
  stack manipulation/observation macros, like PUSH, TOP or EMPTY. 

* Next, we see a very simple opcode that loads values from somewhere into the
  valuestack. I chose to quote LOAD_CONST because it’s very brief and simple,
  although it’s not really a namespace related opcode.

* “Real” namespace opcodes load values into the value stack from a namespace
  and store values from the value stack into a namespace; LOAD_CONST loads
  constants, but doesn’t fetch them from a namespace and has no STORE_CONST
  counterpart (we explored all this at length in the article about namespaces).

* The final opcode I chose to show is actually the single implementation of
  several different control-flow related opcodes (SETUP_LOOP, SETUP_EXCEPT and
  SETUP_FINALLY), which offload all details of their implementation to the
  block stack manipulation function PyFrame_BlockSetup; we discussed the block
  stack in our discussion of interpreter stacks.

* Something we can observe looking at these implementations is that different
  opcodes exit the switch statement differently. Some simply break, and let the
  code after the switch resume. 

* Some use continue to start the for loop from the beginning. Some goto various
  labels in the function. Each exit has different semantic meaning. 

* If you break out of the switch (the ‘normal’ route), various checks will be
  made to see if some special behaviour should be performed – maybe a code
  block has ended, maybe an exception was raised, maybe we’re ready to return a
  value. 

* Continuing the loop or going to a label lets certain opcodes take various
  shortcuts; no use checking for an exception after a NOP or a LOAD_CONST, for
  instance.

* If you look at the code itself, you will see that none of the case
  expressions for the big switch are really there. The code for the NOP opcode
  is actually (remember this series is about Python 3.x unless noted otherwise,
  so this snippet is from Python 3.1.2)::

        TARGET(NOP)
            FAST_DISPATCH();

* TARGET? FAST_DISPATCH? What are these? Let me explain. Things may become
  clearer if we’d look for a moment at the implementation of the NOP opcode in
  ceval.c of Python 2.x.

* Over there the code for NOP looks more like the samples I’ve shown you so
  far, and it actually seems to me that the code of ceval.c gets simpler and
  simpler as we look backwards at older revisions of it.

* The reason is that although I think PyEval_EvalFrameEx was originally written
  as a really exceptionally straightforward piece of code, over the years some
  necessary complexity crept into it as various optimizations and improvements
  were implemented (I’ll collectively call them ‘additions’ from now on, for
  lack of a better term).

* To further complicate matters, many of these additions are compiled
  conditionally with preprocessor directives, so several things are implemented
  in more than one way in the same source file.

* I can understand trading simplicity to optimize a tight loop which is used
  very often, and the evaluation loop is probably one of the more used loops in
  CPython (and probably as tight as its contributors could make it). So while
  this is all very warranted, it doesn’t help the readability of the code.

* Anyway, I’d like to enumerate these additions here explicitly (some in more
  depth than others); this should aid future discussion of ceval.c, as well as
  prevent me from feeling like I’m hiding too many important things with my
  free spirited editing of quoted code.

* Fortunately, most if not all these additions are very well commented
  -actually, some of the explanations below will be just summaries or even
  taken verbatim from these comments, as I believe that they’re accurate
  (eek!). So, as you read PyEval_EvalFrameEx (and indeed ceval.c in general),
  you’re likely to run into any of these

* “Threaded Code” (Computed-GOTOs)

* Let’s start with the addition that gave us TARGET, FAST_DISPATCH and a few
  other macros. The evaluation loop uses a “switch” statement, which decent
  compilers optimize as a single indirect branch instruction with a lookup
  table of addresses.

* Alas, since we’re switching over rapidly changing opcodes (it’s uncommon to
  have the same opcode repeat), this would have an adverse effect on the
  success rate of CPU branch prediction. 

* Fortunately gcc supports the use of C-goto labels as values, which you can
  generally pass around and place in an array (restrictions apply!). 

* Using an array of adresses in memory obtained from labels, as you can see in
  ./Python/opcode_targets.h, we create an explicit jump table and place an
  explicit indirect jump instruction at the end of each opcode. 

* This improves the success rate of CPU prediction and can yield as much as 20%
  boost in performance.

* Thus, for example, the NOP opcode is implemented in the code like so::

        TARGET(NOP)
            FAST_DISPATCH();

* In the simpler scenario, this would expand to a plain case statement and a goto, like so::

        case NOP:
            goto fast_next_opcode;

* But when threaded code is in use, that snippet would expand to (I highlighted
  the lines where we actually move on to the next opcode, using the dispatch
  table of label-values)::

        TARGET_NOP:
            opcode = NOP;
            if (HAS_ARG(NOP))
                oparg = NEXTARG();
        case NOP:
            {
                if (!_Py_TracingPossible) {
                    f->f_lasti = INSTR_OFFSET();
                    goto *opcode_targets[*next_instr++];
                }
                goto fast_next_opcode;
            }


* Same behaviour, somewhat more complicated implementation, up to 20% faster
  Python. Nifty.

* Opcode Prediction

* Some opcodes tend to come in pairs. For example, COMPARE_OP is often followed
  by JUMP_IF_FALSE or JUMP_IF_TRUE, themselves often followed by a POP_TOP. 

* What’s more, there are situations where you can determine that a particular
  next-opcode can be run immediately after the execution of the current opcode,
  without going through the ‘outer’ (and expensive) parts of the evaluation
  loop.

* PREDICT (and a few others) are a set of macros that explicitly peek at the
  next opcode and jump to it if possible, shortcutting most of the loop in this
  fashion (i.e., ``if (*next_instr == op) goto PRED_##op)``.

* Note that there is no relation to real hardware here, these are simply
  hardcoded conditional jumps, not an exploitation of some mechanism in the
  underlying CPU (in particular, it has nothing to do with “Threaded Code”
  described above).

* Low Level Tracing

* An addition primarily geared towards those developing CPython (or suffering
  from a horrible, horrible bug)

* Low Level Tracing is controlled by the LLTRACE preprocessor name, which is
  enabled by default on debug builds of CPython (see --with-pydebug). As
  explained in ./Misc/SpecialBuilds.txt: when this feature is compiled-in,
  PyEval_EvalFrameEx checks the frame’s global namespace for the variable
  __lltrace__. 

* If such a variable is found, mounds of information about what the interpreter
  is doing are sprayed to stdout, such as every opcode and opcode argument and
  values pushed onto and popped off the value stack. Not useful very often, but
  very useful when needed.

* This is the what the low level trace output looks like (slightly edited)::

        >>> def f():
        ...     global a
        ...     return a - 5
        ...
        >>> dis(f)
          3           0 LOAD_GLOBAL              0 (a)
                      3 LOAD_CONST               1 (5)
                      6 BINARY_SUBTRACT
                      7 RETURN_VALUE
        >>> exec(f.__code__, {'__lltrace__': 'foo', 'a': 10})
        0: 116, 0
        push 10
        3: 100, 1
        push 5
        6: 24
        pop 5
        7: 83
        pop 5
        # trace of the end of exec() removed
        >>>

* As you can guess, you’re seeing a real-time disassembly of what’s going
  through the VM as well as stack operations. For example, the first line says:
  line 0, do opcode 116 (LOAD_GLOBAL) with the operand 0 (expands to the global
  variable a), and so on, and so forth. This is a bit like (well, little more
  than) adding a bunch of printf calls to the heart of VM.

* Advanced Profiling

* Under this heading I’d like to briefly discuss several profiling related
  additions. The first relies on the fact that some processors (notably Pentium
  descendants and at least some PowerPCs) have built-in wall time measurement
  capabilities which are cheap and precise (correct me if I’m wrong).

* As an aid in the development of a high-performance CPython implementation,
  Python 2.4′s ceval.c was instrumented with the ability to collect per-opcode
  profiling statistics using these counters.

* This instrumentation is controlled by the somewhat misnamed --with-tsc
  configuration flag (TSC is an Intel Pentium specific name, and this feature
  is more general than that). Calling sys.settscdump(True) on an instrumented
  interpreter will cause the function ./Python/ceval.c: dump_tsc to print these
  statistics every time the evaluation loop loops.

* The second advanced profiling feature is Dynamic Execution Profiling. This is
  only available if Python was built with the DYNAMIC_EXECUTION_PROFILE
  preprocessor name. 

* As ./Tools/scripts/analyze_dxp.py says, [this] will tell you which opcodes
  have been executed most frequently in the current process, and, if Python was
  also built with -DDXPAIRS, will tell you which instruction _pairs_ were
  executed most frequently, which may help in choosing new instructions. 

* One last thing to add here is that enabling Dynamic Execution Profiling
  implicitly disables the “Threaded Code” addition.

* The third and last addition in this category is function call profiling,
  controlled by the preprocessor name CALL_PROFILE. Quoting
  ./Misc/SpecialBuilds.txt again: When this name is defined, the ceval mainloop
  and helper functions count the number of function calls made. It keeps
  detailed statistics about what kind of object was called and whether the call
  hit any of the special fast paths in the code.

* Extra Safety Valves

* Two preprocessor names, USE_STACKCHECK and CHECKEXC include extra assertions.
  Testing an interpreter with these enabled may catch a subtle bug or
  regression, but they are usually disabled as they’re too expensive.

* That's the end of how eval loop operates.

Python Questions (With Answers)
===============================

**1.What is a memoryview object?**

        A memoryview object exposes the C level buffer interface as a Python object
        which can then be passed around like any other object.  

        class memoryview(obj) - Create a memoryview that references obj. obj must
        support the buffer protocol.  Built-in objects that support the buffer protocol
        include bytes and bytearray.


**2. What does the trace.py module do?**

        It helps in tracing the python program or function execution. It helps in
        determining the coverage of code.  Like trace through the program execution
        details, determine how many times a particular line was visited, etc.
        The usage is simple, do python trace.py --trace hello.py


**3. If I want to build python from source in Ubuntu, what packages will make it
build completely?**

        These are the packages which will help you build python completely, that is
        dependencies satisfied for all the modules.

        :: 

                sudo apt-get install libssl-dev libreadline-dev libgdbm-dev \
                tk-dev tk-tile libsqlite3-dev libdb4.7-dev libbz2-dev


**4. How do I see the System Calls when a Python program is executed?**

        By using strace. strace is a Linux command line utility that traces the
        system calls.::

                $strace python 1.py

        What is spitted out is an enormous amout of details on the system calls
        which are executed when running this program.

**5. What is a defaultdict?**

        A defaultdict is a dictionary which will return default values for missing
        keys. When you create a defaultdict, you provide a factory function, which will
        be called for returning the default value.::

        >>> from collections import defaultdict
        >>> d = defaultdict(lambda: 42)
        >>> d[10]
        42
        >>> d[100]
        42
        >>> d
        defaultdict(<function <lambda> at 0x7fc5616c8500>, {10: 42, 100: 42})
        >>>

**6. How would implement the defaultdict's behavior using the normal dict?**

        By overriding the ``__missing__`` method of the class which inherits from
        ``dict``:: 

                >>> class Counter(dict):
                ...     def __missing__(self, key):
                ...         return 0
                >>> c = Counter()
                >>> c['red']
                0
                >>> c['red'] += 1
                >>> c['red']
                1


**7. What is special with and and or operators in python?.**

        ``and`` returns the right operand if the left is true. 
        ``or`` returns the right operand if the left is false.
        Otherwise they both return the left operand. They are said to coalesce


**8. What is the difference between a bytes string and a unicode?**

        Byte string is the 8 bit string. Unicode is not a 8 bit string. Unicode
        strings are a new generation of strings in themselves.


**9. What is difference between the terms iterable and iterator?**


        Iterator generally points to a single instance in a collection.
        Iterable implies that one may obtain an iterator from an object to traverse
        over its elements - and there's no need to iterate over a single instance,
        which is what an iterator represents.

        Behind the scenes, the iterator statement calls iter() on the container object.
        The function returns an iterator object that defines the method next() which
        accesses elements in the container one at a time.  StopIterationException
        terminates

        A collection is iterable. An iterator is not iterable because it's not a
        collection.::

                >>> hasattr('lol','__next__')
                False
                >>> import collections
                >>> isinstance('lol',collections.Iterable)
                True
                >>> for i in 'lol':
                ...     print(i)
                ...
                l
                o
                l
                >>> hasattr('lol','__iter__')
                True

        A string is a sequence (isinstance('', Sequence) == True) and as any sequence
        it is iterable (isinstance('', Iterable)). Though hasattr('', '__iter__') ==
        False and it might be confusing. 

**10. How do you extending Python?**

        To support extensions, the Python API (Application Programmers Interface)
        defines a set of functions, macros and variables that provide access to most
        aspects of the Python run-time system. The Python API is incorporated in a C
        source file by including the header "Python.h".

**11. How is the Python Private methods and Attributes handled?**

        They are handled by name mangling::

                >>> class Foo(object):
                ...     def __init__(self):
                ...         self.__baz = 42
                ...     def foo(self):
                ...         print self.__baz
                ...     
                >>> class Bar(Foo):
                ...     def __init__(self):
                ...         super(Bar, self).__init__()
                ...         self.__baz = 21
                ...     def bar(self):
                ...         print self.__baz
                ...
                >>> x = Bar()
                >>> x.foo()
                42
                >>> x.bar()
                21
                >>> print x.__dict__
                {'_Bar__baz': 21, '_Foo__baz': 42}


**12. What is Global Interpretor Lock?**

        Global Interpretor lock is used to protect the Python Objects from being
        modified by multiple threads at once. To keep multiple threads running, the
        interpretor automatically releases and reaquires the lock at regular intervals.
        It also does this around potentially slow or blocking low level operations,
        such a file and network I/O.  This is used internally to ensure that only one
        thread runs in the Python VM at a time. Python offers to switch amongst threads
        only between bytecode instructions. Each bytecode instruction and all C
        implemented function is atomic from Python program's point of view.

**13. Different types of concurrency models?**

        * Java and C# uses shared memory concurrency model with locking provided by
          monitors. Message passing concurrency model have been implemented on top of
          the existing shared memory concurrency model.
        * Erlang uses message passing concurrency model.
        * Alice Extensions to Standard ML supports concurrency via Futures.
        * Cilk is concurrent C.
        * The Actor Model.
        * Petri Net Model.


**14. How would you represent unicode in python2?**

        In python 2.x, the a string starting with u'' is a unicode object. It might
        contain unicode code-point in the hexadecimal notation. If your terminal
        supports it, then printing that unicode object will print the proper character.
        `chr` - Gives the characters of length 1 from in the range 0 to 256. That is
        \x00 to \xff. It should be known that It borders the ASCII and it is the
        Latin-1 character set.It should also be known that \u00ff and \xff are both
        same.


**15. What are the important properties of Python objects?**

        All Python Objects have:

        * A Unique identifier (returned by id())
        * A Type (returned by type())
        * And a content.

        The Identifier and the type of the object cannot be changed. Only under limited
        circumstances, user defined types can be changed.

        Some objects allow you to change their content, while some objects will not
        allow you to change the content.  The type is represented by type object which
        knows more obout the objects of this type, like how many memory they occupy,
        what methods they have.

        * Objects have 0 or more methods.
        * Objects have 0 or more names.

        There is no variable in python. They are just names and that too within
        namespaces. The names refer to a particular object on assignment.

        Even if the objects have methods, you can never change its type or identity.
        Things like attribute assignments and item references are just syntactic sugar.


**16. Summarize PEP-8 Coding Style standards of Python.**

        * One blank line between functions.
        * Two blank lines between classes.
        * Add a space after "," in dicts, lists, tuples, & argument lists, and after
          ":" in dicts, but not before.
        * Put spaces around assignments & comparisons (except in argument lists).
        * No spaces just inside parentheses or just before argument lists.
        * No spaces just inside docstrings.
        * ``joined_lower`` for functions, methods, attributes
        * ``joined_lower`` or ``ALL_CAPS`` for constants
        * ``StudlyCaps`` for classes
        * ``camelCase`` **only** to conform to pre-existing conventions
        * Attributes: ``interface``, ``_internal``, ``__private``
        * Keep lines below 80 characters in length.
        * Use implied line continuation inside parentheses/brackets/braces::

               def __init__(self, first, second, third,
                            fourth, fifth, sixth):
                   output = (first + second + third
                             + fourth + fifth + sixth)

        * Use backslashes as a last resort::

               VeryLong.left_hand_side \
                   = even_longer.right_hand_side()

        * Backslashes are fragile; they must end the line they're on.  If you add a
          space after the backslash, it won't work any more.  Also, they're ugly.

**17. Why do named strings do not concatenate?**

        named string objects *do not* concatenate::

           >>> a = 'three'
           >>> b = 'four'
           >>> a b
             File "<stdin>", line 1
               a b
                 ^
           SyntaxError: invalid syntax

        That's because this automatic concatenation is a feature of the Python
        parser/compiler, not the interpreter.  You must use the "+" operator to
        concatenate strings at run time.


**18. Example of the dictionary's setdefault method.**

        We have to initialize mutable dictionary values.  Each dictionary value will be
        a list.  This is the naïve way.::

            equities = {}
            for (portfolio, equity) in data:
                if portfolio in equities:
                    equities[portfolio].append(equity)
                else:
                    equities[portfolio] = [equity]


        ``dict.setdefault(key, default)`` does the job much more efficiently::

               equities = {}
               for (portfolio, equity) in data:
                   equities.setdefault(portfolio, []).append(
                                                        equity)

        ``dict.setdefault()`` is equivalent to "get, or set & get".  Or "set if
        necessary, then get".  It's especially efficient if your dictionary key is
        expensive to compute or long to type.

        The only problem with ``dict.setdefault()`` is that the default value is always
        evaluated, whether needed or not.  That only matters if the default value is
        expensive to compute.

        If the default value **is** expensive to compute, you may want to use the
        ``defaultdict`` class.


**19. Example of constructing a dictionary from two lists of key and values.**

        Here's a useful technique to build a dictionary from two lists (or sequences):
        one list of keys, another list of values.::

               given = ['John', 'Eric', 'Terry', 'Michael']
               family = ['Cleese', 'Idle', 'Gilliam', 'Palin']
               pythons = dict(zip(given, family))
               >>> pprint.pprint(pythons)
               {'John': 'Cleese',
                'Michael': 'Palin',
                'Eric': 'Idle',
                'Terry': 'Gilliam'}

        Note that the order of the results of .keys() and .values() is different from
        the order of items when constructing the dictionary.  The order going in is
        different from the order coming out.  This is because a dictionary is
        inherently unordered.  However, the order is guaranteed to be consistent (in
        other words, the order of keys will correspond to the order of values), as long
        as the dictionary isn't changed between calls.


**20. Example of enumerate function in Python.**

        The ``enumerate`` function takes a list and returns (index, item)
        pairs:

        >>> print list(enumerate(items))
        [(0, 'zero'), (1, 'one'), (2, 'two'), (3, 'three')]

        We need use a ``list`` wrapper to print the result because ``enumerate`` is a
        lazy function: it generates one item, a pair, at a time, only when required.  A
        ``for`` loop is one place that requires one result at a time.  ``enumerate`` is
        an example of a *generator*. ``print`` does not take one result at a time -- we
        want the entire result, so we have to explicitly convert the generator into a
        list when we print it.

        An example showing how the ``enumerate`` function actually returns an iterator
        (a generator is a kind of iterator).::

           >>> enumerate(items)
           <enumerate object at 0x011EA1C0>
           >>> e = enumerate(items)
           >>> e.next()
           (0, 'zero')
           >>> e.next()
           (1, 'one')
           >>> e.next()
           (2, 'two')
           >>> e.next()
           (3, 'three')
           >>> e.next()
           Traceback (most recent call last):
             File "<stdin>", line 1, in ?
           StopIteration


**21. What is special about variables in Python?**


        In many other languages, assigning to a variable puts a value into a
        box.  Python has "names" In Python, a "name" or "identifier" is like a
        parcel tag (or nametag) attached to an object.

        Here, an integer 1 object has a tag labelled "a".  If we reassign to "a", we
        just move the tag to another object:

        Now the name "a" is attached to an integer 2 object.

        The original integer 1 object no longer has a tag "a".  It may live on, but we
        can't get to it through the name "a".  (When an object has no more references
        or tags, it is removed from memory.)

        If we assign one name to another, we're just attaching another nametag to an
        existing object:

                   b = a

        The name "b" is just a second tag bound to the same object as "a".

        Although we commonly refer to "variables" even in Python (because it's common
        terminology), we really mean "names" or "identifiers".  In Python, "variables"
        are nametags for values, not labelled boxes.


**22. Function parameters are evaluated at definition time. How does it affect
in an unexpected manner during program evaluation?**

        This is a common mistake that beginners often make.  Even more advanced
        programmers make this mistake if they don't understand Python names.

        ::

            def bad_append(new_item, a_list=[]):
                a_list.append(new_item)
                return a_list


        The problem here is that the default value of ``a_list``, an empty list, is
        evaluated at function definition time.  So every time you call the function,
        you get the **same** default value.  Try it several times:

           ::

               >>> print bad_append('one')
               ['one']

           ::

               >>> print bad_append('two')
               ['one', 'two']

        Lists are a mutable objects; you can change their contents.  The correct way to
        get a default list (or dictionary, or set) is to create it at run time instead,
        **inside the function**.::

               def good_append(new_item, a_list=None):
                   if a_list is None:
                       a_list = []
                   a_list.append(new_item)
                   return a_list


**23. How do you use advanced string formatting features?**

        By name with a dictionary::

               values = {'name': name, 'messages': messages}
               print ('Hello %(name)s, you have %(messages)i '
                      'messages' % values)

        Here we specify the names of interpolation values, which are looked up in the
        supplied dictionary.

        Notice any redundancy?  The names "name" and "messages" are already defined in
        the local namespace.  We can take advantage of this.

        By name using the local namespace::

               print ('Hello %(name)s, you have %(messages)i '
                      'messages' % locals())


        The namespace of an object's instance attributes is just a dictionary,
        ``self.__dict__``.

        By name using the instance namespace::

               print ("We found %(error_count)d errors"
                      % self.__dict__)


**24. What is list comprehension?**

        List comprehensions are syntax shortcuts for construction of lists.

        As a list comprehension::

               new_list = [fn(item) for item in a_list
                           if condition(item)]

        Listcomps are clear & concise, up to a point.  You can have multiple
        ``for``-loops and ``if``-conditions in a listcomp, but beyond two or three
        total, or if the conditions are complex, I suggest that regular ``for`` loops
        should be used.  Applying the Zen of Python, choose the more readable way.::

           For example, a list of the squares of 0–9:

           >>> [n ** 2 for n in range(10)]
           [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

           A list of the squares of odd 0–9:

           >>> [n ** 2 for n in range(10) if n % 2]
           [1, 9, 25, 49, 81]


**25. What is the difference between list comprehension and generator expression?**

        Generator expressions ("genexps") are just like list comprehensions, except
        that where listcomps are greedy, generator expressions are lazy.  Listcomps
        compute the entire result list all at once, as a list.  Generator expressions
        compute one value at a time, when needed, as individual values.  This is
        especially useful for long sequences where the computed list is just an
        intermediate step and not the final result.

        For example, if we were summing the squares of several billion integers, we'd
        run out of memory with list comprehensions, but generator expressions have no
        problem.  This does take time, though!  

        ::
               total = sum(num * num
                           for num in xrange(1, 1000000000))

        The difference in syntax is that listcomps have square brackets, but generator
        expressions don't.  Generator expressions sometimes do not require enclosing
        parentheses though, so you should always use them.

        Rule of thumb:

        * Use a list comprehension when a computed list is the desired end result.
        * Use a generator expression when the computed list is just an intermediate
          step.


**26. How Generators are different from Generator Expressions?**

        We've already seen generator expressions.  We can devise our own arbitrarily
        complex generators, as functions: ::

            def my_range_generator(stop):
                value = 0
                while value < stop:
                    yield value
                    value += 1

            for i in my_range_generator(10):
                do_something(i)

        The ``yield`` keyword turns a function into a generator.  When you call a
        generator function, instead of running the code immediately Python returns a
        generator object, which is an iterator; it has a ``next`` method.  ``for``
        loops just call the ``next`` method on the iterator, until a ``StopIteration``
        exception is raised.  You can raise ``StopIteration`` explicitly, or implicitly
        by falling off the end of the generator code as above.

        Generators can simplify sequence/iterator handling, because we don't need to
        build concrete lists; just compute one value at a time.  The generator function
        maintains state.

        This is how a ``for`` loop really works.  Python looks at the sequence supplied
        after the ``in`` keyword.  If it's a simple container (such as a list, tuple,
        dictionary, set, or user-defined container) Python converts it into an
        iterator.  If it's already an iterator, Python uses it directly.

        Then Python repeatedly calls the iterator's ``next`` method, assigns the return
        value to the loop counter (``i`` in this case), and executes the indented code.
        This is repeated over and over, until ``StopIteration`` is raised, or a
        ``break`` statement is executed in the code.

        A ``for`` loop can have an ``else`` clause, whose code is executed after the
        iterator runs dry, but **not** after a ``break`` statement is executed.  This
        distinction allows for some elegant uses.  ``else`` clauses are not always or
        often used on ``for`` loops, but they can come in handy.  Sometimes an ``else``
        clause perfectly expresses the logic you need.

        For example, if we need to check that a condition holds on some item, any item,
        in a sequence::

               for item in sequence:
                   if condition(item):
                       break
               else:
                   raise Exception('Condition not satisfied.')

        Here is an example Generator to Filter out blank rows from a CSV reader (or
        items from a list)::

            def filter_rows(row_iterator):
                for row in row_iterator:
                    if row:
                        yield row

            data_file = open(path, 'rb')
            irows = filter_rows(csv.reader(data_file))


**27. Sorting a list in Python?**

        ::

            a_list.sort()

        sort methods on a  list sorts it in-place. That is the original list is sorted,
        and the ``sort`` method does **not** return the list or a copy.

        But what if you have a list of data that you need to sort, but it doesn't sort
        naturally (i.e., sort on the length of strings)?

        ``sort`` method has an optional argument called "key", which specifies a
        function of one argument that is used to compute a comparison key from each
        list element.  For example: ::

               def my_key(item):
                   return (item[1], item[3])

               to_sort.sort(key=my_key)

        The function ``my_key`` will be called once for each item in the ``to_sort``
        list.

        You can make your own key function, or use any existing one-argument function
        if applicable:

           * ``str.lower`` to sort alphabetically regarless of case.
           * ``len`` to sort on the length of the items (strings or containers).
           * ``int`` or ``float`` to sort numerically, as with numeric strings
             like "2", "123", "35".


**28. What are the various different ways to import modules in Python?**


        There is a wildcard ``*`` style module importing::

                from module import *

        The ``from module import *`` wild-card style leads to namespace pollution.
        You'll get things in your local namespace that you didn't expect to get.  You
        may see imported names obscuring module-defined local names.  You won't be able
        to figure out where certain names come from.  Although a convenient shortcut,
        this should not be in production code.

        It's much better to:

        * reference names through their module (fully qualified identifiers),
        * import a long module using a shorter name (alias; recommended),
        * or explicitly import just the names you need.


        Namespace pollution alert!  ::

               import module
               module.name

        Or import a long module using a shorter name (alias): ::

               import long_module_name as mod
               mod.name


        Or explicitly import just the names you need: ::

               from module import name
               name


        Note that this form doesn't lend itself to use in the interactive interpreter,
        where you may want to edit and "reload()" a module.


**29. How to make a Python module work as a script?**

        To make a simultaneously importable module and executable script::

            if __name__ == '__main__':
                # script code here


        When imported, a module's ``__name__`` attribute is set to the module's file
        name, without ".py".  So the code guarded by the ``if`` statement above will
        not run when imported.  When executed as a script though, the ``__name__``
        attribute is set to "__main__", and the script code *will* run.

        Except for special cases, you shouldn't put any major executable code at the
        top-level.  Put code in functions, classes, methods, and guard it with ``if
        __name__ == '__main__'``.


**30. What is a good way to structure the python programs or modules and packages?**

        This is how a module should be structured.::

            """module docstring"""

            # imports
            # constants
            # exception classes
            # interface functions
            # classes
            # internal functions & classes

            def main(...):
                ...

            if __name__ == '__main__':
                status = main()
                sys.exit(status)

        This is how the packages should be structured::

            package/
                __init__.py
                module1.py
                subpackage/
                    __init__.py
                    module2.py


        * Packages are used to organize your project.
        * They Reduce the entries in load-path.
        * They Reduce the import name conflicts.

        Example::

                import package.module1
                from package.subpackage import module2
                from package.subpackage.module2 import name


**31. How would you transpose a Matrix in Python?**

        ::

                mat = [[1,2,3],
                       [4,5,6],
                       [7,8,9]
                       ]


        If we want to transpose the about matrix, that is change the rows into columns
        and columns into rows, the result will be::

                result = [[1,4,7],
                          [2,5,8],
                          [3,6,9]
                          ]

        Answer Is::

                >>>zip(*mat)

**32. How would you write unicode strings in Python2?**

        * Python2 supports Unicode by a special kind of string, called the Unicode object.  _>>> u'Hello World !'_
        * You can have unicode by using the special python escape encoding: _>>> u'Hello\u0020World !'_
        * built-in function unicode() , default encoding is ASCII
        * To convert unicode to a 8-bit string using a specified encoding::

                >>> u"쎤쎶쎼".encode('utf-8')
                '\xc3\xa4\xc3\xb6\xc3\xbc'

        * From a data in a specific encoding to a unicode string::

                >>> unicode('\xc3\xa4\xc3\xb6\xc3\xbc', 'utf-8')
                u'\xe4\xf6\xfc'

        * Understanding unicode is easy, when we accept the need to explicitly convert
          between the bytestring (which is a 8bit string) and unicode string.

        * More examples::

                >>> german_ae = unicode("\xc3\xa4",'utf8')
                >>> sentence = "this is a " + german_ae
                >>> sentece2 = "Easy!"
                >>> sentence2 = "Easy!"
                >>> para = ".".join([sentence, sentence2])
                >>> para
                u'this is a \xe4.Easy!'
                >>> print para
                this is a ä.Easy!
                >>> 

        * Without an encoding, the bytestring is essentially meaningless. 

        * The default encoding assumed by Python2 is ASCII and Python3 is UTF-8 For the
          Python2, source code to have a encoding other than ascii, you need to declare
          the encoding at the top of file, using a construct such as 
          ``# -*- coding: utf-8 -*-`` this is many a times referred to as coding-cookie
          as it denotes the type of encoding being used for the source file.  With that
          declaration, all characters in the source file will be treated as having the
          encoding *encoding*, and it will be possible to directly write Unicode string
          literals in the selected encoding.  The list of possible encodings can be
          found in the Python Library Reference, in the section on codecs.  By using
          UTF-8, most languages in the world can be used simultaneously in string
          literals and the comments.

**33. How does else conditions on loops work in Python?**

        Loop statements in Python may have an else clause. It is executed when the loop
        terminates through exhaustion of the list (with for).  Or when the condition
        becomes false (with while), But not when the loop is terminated by a break
        statement::

                >>> for n in range(2, 10):
                ...     for x in range(2, n):
                ...         if n % x == 0:
                ...             print n, 'equals', x, '*', n/x
                ...             break
                ...     else:
                ...         # loop fell through without finding a factor
                ...         print n, 'is a prime number'
                ...
                2 is a prime number
                3 is a prime number
                4 equals 2 * 2
                5 is a prime number
                6 equals 2 * 3
                7 is a prime number
                8 equals 2 * 4
                9 equals 3 * 3

**33. How does a function execution control flows in Python?**

        The execution of a function introduces a new symbol table used for the local
        variables of the function. More precisely, all variable assignments in a
        function store the value in the local symbol table; whereas variable references
        first look in the local symbol table, then in the local symbol tables of
        enclosing functions, then in the global symbol table, and finally in the table
        of built-in names. Thus, global variables cannot be directly assigned a value
        within a function (unless named in a global statement), although they may be
        referenced.

        The actual parameters (arguments) to a function call are introduced in the
        local symbol table of the called function when it is called; thus, arguments
        are passed using call by value (where the value is always an object reference,
        not the value of the object). When a function calls another function, a new
        local symbol table is created for that call.

        A function definition introduces the function name in the current symbol table.
        The value of the function name has a type that is recognized by the interpreter
        as a user-defined function. This value can be assigned to another name which
        can then also be used as a function.

        To illustrate the function execution control flow, have a look at this
        snippet.:: 

                i = 5

                def f(arg=i):
                    print arg

                i = 6
                f()


                def f(a, L=[]):
                    L.append(a)
                    return L

                print f(1)
                print f(2)
                print f(3)

        First one will print 5, because default values are evaluated at the point of
        function definition in the defining scope.

        The default value is evaluated only once. This makes a difference when the
        default value is a mutatable object. In order to prevent argument sharing.::

                  def f(a, L=None):
                    if L is None:
                        L = []
                    L.append(a)
                    return L


**34. What are the different functional programming tools available in Python?**

        There are three built-in functions that are very useful when used with lists:
        filter(), map() and reduce()

        * filter(function, sequence) - Takes the elements of the sequence and filters
          them with the condition specified in the function.
        * map(function, sequence) - sends each element to the function and returns the
          result.More than one sequence may be passed; the function must then have as
          many arguments as there are sequences and is called with the corresponding item
          from each sequence. 
        * reduce(function, sequence) -  function in reduce is a binary function::

                >>> def f(x): return x % 2 != 0 and x % 3 != 0
                ...
                >>> filter(f, range(2, 25))
                [5, 7, 11, 13, 17, 19, 23]

                >>> def cube(x): return x*x*x
                ...
                >>> map(cube, range(1, 11))
                [1, 8, 27, 64, 125, 216, 343, 512, 729, 1000]

                >>> seq = range(8)
                >>> def add(x, y): return x+y
                ...
                >>> map(add, seq, seq)
                [0, 2, 4, 6, 8, 10, 12, 14]

                >>> def sum(seq):
                ...     def add(x,y): return x+y
                ...     return reduce(add, seq, 0)
                ...
                >>> sum(range(1, 11))
                55
                >>> sum([])
                0

**35. How do you handle Exceptions in Python2?**

        A try statement may have more than one except clause, to specify
        handlers for different exceptions::


                  ... except (RuntimeError, TypeError, NameError):

                  ...     pass

        The last except clause may omit the exception name(s), to serve as a wildcard.
        Use this with extreme caution, since it is easy to mask a real programming
        error in this way! It can also be used to print an error message and then
        re-raise the exception (allowing a caller to handle the exception as well)

        The try ... except statement has an optional else clause, executed when the try
        clause does not raise an exception.::

                for arg in sys.argv[1:]:
                    try:
                        f = open(arg, 'r')
                    except IOError:
                        print 'cannot open', arg
                    else:
                        print arg, 'has', len(f.readlines()), 'lines'
                        f.close()


         A finally clause is available to handle cleaup actions in Python.  A
         finally clause is always executed before leaving the try statement,
         whether an exception has occurred or not. In real world applications,
         the finally clause is useful for releasing external resources (such as
         files or network connections), regardless of whether the use of the
         resource was successful.

**36. What is a with statement in Python?**

        Some objects define standard clean-up actions to be undertaken when the object
        is no longer needed, regardless of whether or not the operation using the
        object succeeded or failed::

                with open("myfile.txt") as f:
                    for line in f:
                        print line

        After the statement is executed, the file f is always closed, even if a problem
        was encountered while processing the lines. 

**37. How does Python class statement works?**

        When a class definition is entered, a new namespace is created, and used as the
        local scope and thus, all assignments to local variables go into this new
        namespace. In particular, function definitions bind the name of the new
        function here. When a class definition is left normally, a class object is
        created. This is basically a wrapper around the contents of the namespace
        created by the class definition;The original local scope (the one in effect
        just before the class definition was entered) is reinstated, and the class
        object is bound here to the class name given in the class definition header

        In C++ terminology, all class members (including the data members) are public,
        and all member functions are virtual. There are no special constructors or
        destructors.  Python Scopes and Namespaces A namespace is a mapping from names
        to objects.  Most namespaces are currently implemented as Python dictionaries.

        Class Objects support attribute notation and instantiation.  Class
        instantiation creates instance objects. Instance Objects supports attribute
        references, which are of two kinds data attributes and methods.

        Old style classes support Inheritance in depth first, left to right.
        New style classes to support super(), it follows a diamond inheritance.

**38. Explain Classmethods, Staticmethods and Decorators in Python.**

        In Object Oriented Programming, you can create a method which can get
        associated either with a class or with an instance of the class, namely an
        object. 

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

        The following would never work.::

                >>> class Car:
                ... 	def getmodel():
                ... 		return "Audi"
                ... 	def type(self):
                ... 		self.model = getmodel()

        Because, getmodel() is defined inside the class, Python binds it to the Class
        Object.  You cannot call it by the following way also, namely: Car.getmodel()
        or Car().getmodel() , because in this case we are passing it through an
        instance ( Class Object or a Instance Object) as one of the argument while our
        definition does not take any argument.

        As you can see, there is a conflict here and in effect the case is, It is an
        "**unbound local method**" inside the class.

        Now comes Staticmethod.

        Now, in order to call getmodel(), you can to change it to a static method::

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

        **Decorators**

        ``getmodel = staticmethod(getmodel)``

        If you look at the previous code example, the function staticmethod took a
        function name as a argument and the return value was a function which we
        assigned to the same name.

        staticmethod() function thus wrapped our getmodel function with some extra
        features and this wrapping is called as Decorator.

        The same code can be written like this::

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

        Please remember that this concept of Decorator is independent of staticmethod
        and classmethod.  Now, what is a difference between staticmethod and
        classmethod?

        In languages like Java,C++, both the terms denote the same :- methods for which
        we do not require instances. But there is a difference in Python. A class
        method receives the class it was called on as the first argument. This can be
        useful with subclasses.

        We can see the above example with the classmethod and a decorator as.::

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


**39. Explain the terms methods, staticmethods and classmethods in terms of general programming principles.**

        In object-oriented programming, a method is a subroutine that is exclusively
        associated either with a class (called class methods or static methods) or with
        an object (called instance methods). Like a procedure in procedural programming
        languages, a method usually consists of a sequence of statements to perform an
        action, a set of input parameters to customize those actions, and possibly an
        output value (called the return value) of some kind. Methods can provide a
        mechanism for accessing (for both reading and writing) the encapsulated data
        stored in an object or a class.

        Instance methods are associated with a particular object, while class or static
        methods are associated with a class. In all typical implementations, instance
        methods are passed a hidden reference (e.g. this, self or Me) to the object
        (whether a class or class instance) they belong to, so that they can access the
        data associated with it. 

        For class/static methods this may or may not happen according to the language;
        A typical example of a class method would be one that keeps count of the number
        of created objects within a given class.

        A method may be declared as static, meaning that it acts at the class level
        rather than at the instance level. Therefore, a static method cannot refer to a
        specific instance of the class (i.e. it cannot refer to this, self, Me, etc.),
        unless such references are made through a parameter referencing an instance of
        the class, although in such cases they must be accessed through the parameter's
        identifier instead of this. An example of a static member and its consumption
        in C# code.::

                public class ExampleClass
                {
                  public static void StaticExample()
                  {
                     // static method code
                  }
                 
                  public void InstanceExample()
                  {
                     // instance method code here
                     // can use THIS
                  }   
                }
                 
                /// Consumer of the above class:
                 
                // Static method is called -- no instance is involved
                ExampleClass.StaticExample();
                 
                // Instance method is called
                ExampleClass objMyExample = new ExampleClass();
                objMyExample.InstanceExample();


        Python method can create an instance of Dict or of any subclass of it, because
        it receives a reference to a class object as cls.::

                class Dict:
                   @classmethod
                   def fromkeys(cls, iterable, value=None):
                       d = cls()
                       for key in iterable:
                           d[key] = value
                       return d


        A class method receives the class it was called on as the first argument. This
        can be useful with subclasses. A staticmethod doesn't get a class or instance
        argument. It is just a way to put a plain function into the scope of a class.
        In the wider world of OOP they are two names for the same concept.  Smalltalk
        and Lisp etc used the term "class method" to mean a method that applied to the
        class as a whole.

        C++ introduced the term "static method" to reflect the fact that it was loaded
        in the static area of memory and thus could be called without instantiating an
        object. This meant it could effectively be used as a class method.

        In C it is possible to prefix a normal function definition with the word static
        to get the compiler to load the function into static memory - this often gives
        a performance improvement.

        Python started off implementing "static methods" then later developed the
        sligtly more powerful and flexible "class methods" and rather than lose
        backward compatibility called them classmethod.  So in Python we have two ways
        of doing more or less the same (conceptual) thing.

        http://code.activestate.com/recipes/52304/ the recipe here shows a way to make
        a funtion within a class as callable by using wrapping techniques. This was
        later generalized to staticmethods.

        Conceptually they are both ways of defining a method that applies at the class
        level and could be used to implement class wide behavior. Thats what I mean. If
        you want to build a method to determine how many instances are active at any
        time then you could use either a staticmethod or a classmethod to do it. Most
        languages only give you one way. Python, despite its mantra, actually gives 2
        ways to do it in this case.


**40. What is the difference between process and a thread?**

        Both threads and processes are methods of parallelizing an application.
        However, processes are independent execution units that contain their own state
        information, use their own address spaces, and only interact with each other
        via interprocess communication mechanisms (generally managed by the operating
        system). Applications are typically divided into processes during the design
        phase, and a master process explicitly spawns sub-processes when it makes sense
        to logically separate significant application functionality. Processes, in
        other words, are an architectural construct.

        By contrast, a thread is a coding construct that doesn't affect the
        architecture of an application. A single process might contains multiple
        threads; all threads within a process share the same state and same memory
        space, and can communicate with each other directly, because they share the
        same variables.

        Threads typically are spawned for a short-term benefit that is usually
        visualized as a serial task, but which doesn't have to be performed in a linear
        manner (such as performing a complex mathematical computation using
        parallelism, or initializing a large matrix), and then are absorbed when no
        longer required. The scope of a thread is within a specific code module—which
        is why we can bolt-on threading without affecting the broader application.

        Multithreading computers have hardware support to efficiently execute multiple
        threads.  Threads of program results from fork of a computer program into two
        or more concurrently running tasks.  In multi-threading the threads have to
        share a single core,cache and TLB unlike the multiprocessing machines.

        *Some History of Inter Process Communication*

        By the early 60s computer control software had evolved from Monitor control
        software, e.g., IBSYS, to Executive control software. Computers got "faster"
        and computer time was still neither "cheap" nor fully used. It made
        multiprogramming possible and necessary.

        Multiprogramming means that several programs run "at the same time"
        (concurrently). At first they ran on a single processor (i.e., uniprocessor)
        and shared scarce resources. Multiprogramming is also basic form of
        multiprocessing, a much broader term.

        Programs consist of sequence of instruction for processor. Single processor can
        run only one instruction at a time. Therefore it is impossible to run more
        programs at the same time. Program might need some resource (input ...) which
        has "big" delay. Program might start some slow operation (output to printer
        ...). This all leads to processor being "idle" (unused). To use processor at
        all time the execution of such program was halted. At that point, a second (or
        nth) program was started or restarted. User perceived that programs run "at the
        same time" (hence the term, concurrent).

        Shortly thereafter, the notion of a 'program' was expanded to the notion of an
        'executing program and its context'. The concept of a process was born.

        This became necessary with the invention of re-entrant code.  Threads came
        somewhat later. However, with the advent of time-sharing; computer networks;
        multiple-CPU, shared memory computers; etc., the old "multiprogramming" gave
        way to true multitasking, multiprocessing and, later, multithreading.

**41. What are Coroutines?**

        Coroutines are subroutines that allow multiple entry points for suspending and
        resuming execution at certain locations.  Subroutine are subprograms, methods,
        functions for performing a subtask and it is relatively independent of other
        task.  Coroutines are usful for implementing cooperative tasks, iterators,
        infinite lists and pipes.  Cooperative Tasks - Similar programs, CPU is yielded
        to each program coperatively.  Iterators - an object that allows the programmer
        to traverse all the elements of a collection.  Lazy Evaluation is the technique
        for delaying the computation till the result is required. Why Infite Lists and
        Lazy evaluation are given together?  Coroutines in which subsequent calls can
        be yield more results are called as generators.  Subroutines are implemented
        using stacks and coroutines are implemented using continuations.  continuation
        are an abstract representation of a control state, or the rest of the
        computation, or rest of the code to be executed.

**41. What is a Global Interpreter Lock?**

        The GIL is a single lock inside of the Python interpreter, which effectively
        prevents multiple threads from being executed in parallel, even on multi-core
        or multi-CPU systems!

        * All threads within a single process share memory; this includes Python's
          internal structures (such as reference counts for each variable).  Course
          grained locking.
        * fine grained locking.
        * @synchronized decorator
        * technically speaking, threads have shared heaps but separate stacks.
        * Interpreter of a language is said to be stackless if the function calls in
          the language do not use the C Stack. In effect, the entire interpretor has to
          run as a giant loop.

        The Global Interpreter Lock (GIL) is used to protect Python objects from being
        modified from multiple threads at once. Only the thread that has the lock may
        safely access objects.

        To keep multiple threads running, the interpreter automatically releases and
        reacquires the lock at regular intervals (controlled by the
        sys.setcheckinterval function). It also does this around potentially slow or
        blocking low-level operations, such as file and network I/O.

        Indeed the GIL prevents the* **interpreter** to run two threads of bytecodes
        concurrently.

        But it allows two or more threadsafe C library to run at the same time.
        The net effect of this brilliant design decision are:

        1. It makes the interpreter simpler and faster
        2. When speed does not matter (ie: bytecode is interpreted) there’s not too
           much to worry about threads.
        3. when speed does matter (ie: when C code is run) Python applications is not
           hampered by a brain dead VM that is so ’screwed’ up that it must pause to
           collect its garbage.

**42. How do you specify and enforce an interface spec in Python?**

        An interface specification for a module as provided by languages such as C++
        and Java describes the prototypes for the methods and functions of the module.
        Many feel that compile-time enforcement of interface specifications helps in
        the construction of large programs. In Java World, interfaces form the
        contract between the class and the outside world, and this contract is
        enforced at the build time by the compiler.

        Python 2.6 adds an abc module that lets you define Abstract Base Classes (ABC).
        You can then use isinstance() and issubclass to check whether an instance or a
        class implements a particular ABC. The collections modules defines a set of
        useful ABC s such as Iterable, Container, and Mutablemapping.

        For Python, many of the advantages of interface specifications can be obtained
        by an appropriate test discipline for components. There is also a tool,
        PyChecker, which can be used to find problems due to subclassing.

        A good test suite for a module can both provide a regression test and serve as
        a module interface specification and a set of examples. Many Python modules can
        be run as a script to provide a simple "self test." Even modules which use
        complex external interfaces can often be tested in isolation using trivial
        "stub" emulations of the external interface. The doctest and unittest modules
        or third-party test frameworks can be used to construct exhaustive test suites
        that exercise every line of code in a module.

        An appropriate testing discipline can help build large complex applications in
        Python as well as having interface specifications would. In fact, it can be
        better because an interface specification cannot test certain properties of a
        program. For example, the append() method is expected to add new elements to
        the end of some internal list; an interface specification cannot test that your
        append() implementation will actually do this correctly, but it's trivial to
        check this property in a test suite.

        Writing test suites is very helpful, and you might want to design your code
        with an eye to making it easily tested. One increasingly popular technique,
        test-directed development, calls for writing parts of the test suite first,
        before you write any of the actual code. Of course Python allows you to be
        sloppy and not write test cases at all.

**43. What is the difference between string, bytes and buffer from Python2 and Python3 perspective?**

        In Python 2.0, the normal strings were of 8 bit characters and for representing
        Characters from foreign languages, a special kind of class was provided, which
        was called Unicode String.

        The string object when they had to be stored or transfered over the wire, they
        had to be encoded into bytes. As normal string character was 8 bits, they
        directly corresponded to one byte and Python2.0 had an implicit ascii encoding
        which conveniently encoded them to 8-bit bytes.  The Unicode object had to have
        an encoding specified, which encoded the unicoded strings into sequence of
        bytes.

        Just as string object had an encode method, to convert to bytes, the bytes
        object had a decode method, that takes a character encoding an returns a
        string.

        In Python 3.0, the normal string was made the Unicode String. However, the 8bit
        character datatype was still retained and it was called as bytes.

        In other words. Python2.6 supports both simple text and binary data in its
        normal string type and provides an alternative string type for non-ASCII type
        called the Unicode text. Whereas Python3.0 supports Unicode text in its normal
        string type, with ASCII being treated a simple type of unicode and provides an
        alternative string type for binary data called bytes.

        Python3 comes with 3 types of string objects, one for textual data and two for
        binary data.

        * str - for representing Unicode text.
        * bytes - for representing Binary data.
        * bytearray - a mutable flavor of bytes type.

        3.0 str type defined an immutable sequence of characters (not neccesarily
        bytes), which may be either normal text such as ASCII or multi byte UTF-8.  A
        new type called bytes was introduced to support truly binary data.

        In 2.x; the general string type filled this binary data role, because strings
        were just a sequence of bytes. In 3.0, the bytes type is defined as an
        immutable sequence of 8-bit integers representing absolute byte values.  A 3.0
        bytes object really is a sequence of small integers, each of which is in the
        range 0 through 255; indexing a bytes returns int, slicing one returns another
        bytes and running list() on one returns a list of integers, not characters.
        While they were at it, the Python developers also added bytearray type in 3.0,
        a variant of bytes, which is mutable and also supports in-place changes. The
        bytearray type supports the usual string operations that str and bytes do, but
        has inplace change operations also.

        Because str and bytes are sharply differentiated by the language, the net
        effect is that you must decide whether your data is text or binary in nature
        and use 'str' or 'bytes' objects to represent its content in your script
        respectively.

        Image or audio file or packed data processed with the struct module is an
        exmaple of bytes object. Python3.0 has a sharp distinction between text, binary
        data and files.::

                $ python
                Python 2.6.2 (release26-maint, Apr 19 2009, 01:58:18) [GCC 4.3.3] on linux2
                >>> import sys
                >>> print sys.getdefaultencoding()
                ascii
                >>> 
                07:56 PM:senthil@:~/uthcode/source
                $ python3.1
                Python 3.1a2+ (py3k:71811, Apr 22 2009, 20:47:22) [GCC 4.3.2] on linux2
                >>> import sys
                >>> print(sys.getdefaultencoding())
                utf-8
                >>> 

        Ultimately, the mode in which you open a file will dictate which type of object
        your script will use to represent its contents.

        * bytes or binary mode files.
        * bytearray to update data without making copies of it in memory.
        * If you are processing something that is textual in nature, such as program
          output, HTML, internationalized text, and CSV or XML files, you probably want
          to use str or text mode files.

**44. What is the bytearray class in Python3?**

        A Byte is 8 bits and array is a sequence. A Bytearray object can be constructed
        using integers only or text string along with an encoding or using another
        bytes or bytearray or any other object implementing a buffer API. More
        importantly, it is mutable.


**45. How to do convert int to hex in Python?**

        Q:Convert a Hexadecimal Strings ("FF","FFFF") to Decimal
        A: int("FF",16) and int("FFFF",16)

        Q: Represent 255 in Hexadecimal.
        A: print '%X' % 255

        If you want to encode a string in base16, base32 or base64 encoding, the python
        standard library provides base64 module which is based on the RFC 3564.


**46. What are the different XML parsers in Python?**

        There are two different kinds of XML parsing methods. SAX and DOM.

        SAX - Simple API for XML - serial access parser API for XML.  SAX provides a
        mechanism for reading data from an XML document. Its popular alternative is
        DOM.  Unlike DOM there is no formal specification of SAX. The Java
        implementation of SAX is considered to be normative, and implementations in
        other languages attempt to follow the rules laid down in that implementation,
        adjusting for differences in the language when necessary.

        Benefits of SAX - less memory, it is serial.  DOM requires to load the entire
        XML tree.  Drawbacks of XML include, Certain kind of XML validation requires to
        read the complete XML.

        xml.etree.ElementTree as DOM parser. First of all understand that Element Tree
        is a tree datastructure. It represents the XML document as a Tree. The XML
        Nodes are Elements. (Thus the name Element Tree)

        Now, if I were to structure an html document as a element tree.::

                        <html>
                          |
                        <head> -------
                        /   \        |
                     <title> <meta> <body>
                                   /   |  \
                                <h1>  <h2> <para>
                                           /   \
                                          <li> <li>


        The Element type is a flexible container object, designed to store hierarchical
        data structures in memory. The type can be described as a cross between a list
        and a dictionary.  The C implementation of xml.etree.ElementTree is available
        as xml.etree.cElementTree

**47. What is a factory method design pattern?**

        Factory method design pattern is used quite often in Python. It is a creational
        pattern, dealing with creation of objects (products) without specifying the
        exact class. The creational patterns abstract the concept of instantiating
        objects.  and It handles this case by defining a separate method for creation
        objects.

        The subclasses of that method or object can override to specify the derived
        type of the product that will be created. Factory method is used to refer to
        any method whose main purpose is to create objects. 

        The Factory pattern in c++ wraps the usual object creation syntax new
        someclass() in a function or a method which can control the creation.
        Advantages is that, code using the class no longer needs to know all the
        details of creation. It may not even know the exact type of object created.

        Abstract Factory provides additional indirection to let the type of object
        which is created to vary.

        Factory pattern is fundamental in python; while languages like C++ use
        ClassName class; to create classes python uses function class syntax to create
        objects. Even builtin types str, int provide factory pattern.

Bytes in API
------------

# Is ASCII with surrogateescape OK?

# Non Decodable Bytes in System Character Interfaces.

# PEP - 383 seems pretty cool. ( C-API allows reading of bytes whether it is a character or not).

# Issue4661

# What is the difference between dict proxy and a dict.

# What is the difference between linefeed and a newline?

# newline is composed of Linefeed character. 


Web Services Gateway Interface
------------------------------

It is easy to build **a web application framework in Python.** WSGI is Python
PEP 333, the Web Server Gateway Interface. It's a protocol for communicating
with Python web applications WSGI works by callbacks. 
     
The application provides a function which the server calls for each request::

        application(environ, start_response)

`environ` is a Python dictionary containing the CGI-defined environment
variables plus a few extras. One of the extras is `wsgi.input`, the file object
from which to read the POST variables. `start_response` is a callback by which
the application returns the HTTP header::

        start_response(status, response_headers, exc_info=None)

`status` is an HTTP status string (e.g., "200 OK"). `response_headers` is a
list of 2-tuples, the HTTP headers in key-value format. `exc_info` is used in
exception handling; we won't cover it here.

The application function then returns an iterable of body chunks. In the
simplest case this can be::

        ["<html>Hello, world!</html>"]

Getting slightly more elaborate, here's the second-smallest WSGI application in
the world::

        def app2(environ, start_response):
            start_response("200 OK", [])
            s = "<html>You requested <strong>%s</strong></html>"
            s %= environ['PATH_INFO']
            return [s]

The protocol may look strange, but it's designed to meet the needs of the
widest possible variety of existing and potential frameworks and servers and
middleware. 

Middleware are reusable components providing generic services normally handled
by frameworks; e.g., a Session object, a Request object, error handling.
They're implemented as wrapper functions; i.e., decorators. Inbound they can
add keys to the dictionary (e.g., quixote.request for a Quixote-style Request
object). Outbound they can modify HTTP headers or translate the body into Latin
or Marklar. Here's a small middleware.::

        class LowercaseMiddleware:
            def __init__(self, application):
                self.application = application   # A WSGI application callable.

            def __call__(self, environ, start_response):
                pass  # We could set an item in 'environ' or a local variable.
                for chunk in self.application(environ, start_response):
                    yield chunk.lower()

Assuming we had a Server Constructor Server, we could do::

        app = LowercaseMiddleware(app2)
        server = Server(app)

Since it's so easy to write a WSGI application, you may wonder, "Who needs a
framework?" That's a legitimate question, although the answer is, "It's tedious
without one." 

Your application is responsible for every URL under it; e.g., if it's installed
as http://localhost:8080/, it would have to do something intelligent with
http://localhost:8080/foo/bar/baz. Code to parse the URL and switch to an
appropriate function is... **a framework!** So you may as well use an existing
framework and save yourself the tedium.

Writing a WSGI server interface is more complex. There's an example in PEP 333.

WSGI opens the way for a lot of interesting possibilities. Simple frameworks
can be turned completely into middleware. Some frameworks might be able to run
on top of other frameworks or even be emulated by them. Ideally, existing
applications would run unchanged or with minimal changes. But this is also a
time for framework developers to rethink how they're doing things and perhaps
switch to more middleware-friendly APIs.

web.py ( http://webpy.org/ ) is a single module (~1000 lines) that does WSGI
and an extremely simple O-R mapping, with Cheetah for (non-XML) templates. 

With respect to WSGI, its original purpose wasn't to do "middleware"; it was
just a way to connect an application to arbitrary web servers, so the same
application can be run under mod_python, CGI, FastCGI, SCGI, in a Twisted or
other Python HTTP server, etc. That was and is the main point of WSGI. 

The existence of middleware is just a natural side-effect of having a way to
connect an app to a server, in the same way that proxy servers and caches are a
side-effect of having HTTP.

But just as it was a good idea to specify some of the allowed behaviors of
proxies and caches in the HTTP spec, so too it was a good idea to address
middleware in the WSGI spec. Basically, WSGI in itself is just a Python
encoding of HTTP and nothing more.

WSGI PEP is basically a port of the Java servlet API, implemented in terms of
simple callables and built-in data types rather than having an object/method
interface. 

Thus, any framework that's WSGI compliant support should give you the "server
independence" you're looking for. You just need a WSGI "gateway" for the
server, and find out how the framework exposes an "application" object to be
run by the gateway.

Twisted Framework
-----------------

Twisted framework provides the facility to build an asynchronous, event-driven
applications for Distributed Network Environment. You will understand all these
terminologies if you just find reason to go ahead and build one.  Twisted is a
platform for developing Internet applications.In the Twisted, internet term
actually denotes internetworking.

At the core of Twisted Framework is its network layer, which can be used to
integrate any existing  protocol as well as model new ones.  Twisted is a pure
python framework. 

Twisted supports Asynchronous programming and deferred abstraction, which
symbolizes a promised result and which can pass eventual result to  handler
functions.  

A fundamental feature of Network Programming is waiting for data. The Normal
Model when using twisted framework is by using Non-Blocking Calls.  When
dealing with many connections in one thread, the scheduling is the
responsiblity of the application, not the operating system, and is usually
implemented by calling a registered function when each function is ready to go
for reading or writing - commonly known as asynchronous, event based, callback
based programming.  

In synchrnous programming, a function requests data, waits for the data, and
then processes it. In asynchronous programming, a function requests the data,
and lets the library call the callback function when the data is ready.

It is the class of concurrency problems, non-computationally intensive tasks
that involve an appreciable delay that deferreds are designed to help solve.
They do this by giving a simple management interface for callbacks and
applications.  blocking - means, if one tasks is waiting for data, the other
task cannot get CPU but also waits until the first tasks finishes.  The typical
asynchronous model to notify can application that some data is ready is called
as callback.

Twisted uses Deferred objects to managed callback sequence.  Libraries know
that they make their results available by using Deferred.callback and errors by
Deferred.errback.  

How does the parent function or its controlling program know that connection
does not exist and when it will know, when the connection becomes alive?

Twisted has an object that signals this situation, it is called
twisted.internet.defer.Deferred. Deferred has two purposes; first is saying
that I am a signal, of whatever you wanted me to do is still pending; second
you can ask differed to run things when the data arrives.  The way to tell the
deffered what to do when the data arrives is by defining a callback - asking
the deferred to call a function once the data arrives.  

Deferreds are an object which represent a promise of something; 
Like getPage() returned a Deferred object, which means that when the getPage is
called ( It may not be called sequentially, because it is  asynchronous); a
callback may be attached to the defered object which will ask it do whatever
with the data, in our case, the callback was to print the data.

If nothing else is understood, please understand that you create a differed
object, add a callback function to that object and add an errorback function to
that object. Differed will get called after a particular period of time or some
data is avaiable.Differeds are the signals for asynchronous functions to use to
pass results onto the callbacks, but using them does not guarantee that you
have asynchronous functions.What Differeds dont do: Make your code
asynchronous!.

twisted.internet.defer.Deferred is a promise that the function at some point in
time will have a result.

The Deferred mechanism, standardizes the application programmers inferface with
all sort of blocking and delayed operations.

It is possible to adapt, synchronous functions to return Deferred. Sometimes
you want to be notified after several different events have all happened,
rather than waiting for each one individually.

You may want to wait for all connections in a list to close.

Generating Deferreds is a Document introducing writing of Asynchronous
functions generating deferreds.

deferreds are not a non-blocking talisman; they are a signal for asynchronous
functions to use to pass results to callback once the results are available.

Returning Deferreds from synchronous functions; reasons :- API compatiblity
with another function which returns deferred or making the function
asynchronous in the future.

Requesting method requests a data; and gets a Deferred object.
Requesting method attaches callbacks to the Deferred object, 

Twisted also provides facility to run the blocking function in a separate
thread instead of blocking them.

A Twisted Protocol handles code in an asynchronous manner. What this means is
that the Protocol does not wait for an event, but rather handles the event as
they arrive from network.In the Twisted client, an instance of the Protocol
class will be instantiated when you connect to the Server and will go away when
the connection is finished.

Interface classes are a way of specifying what methods and attributes a
Protocol provides.

* event: Event Driven programming or Event Based Programming is where program
  flow happens based on events like mouse movement or key press or signal from
  another thread.

* Event Driven Programming is paradigm, in which there is a main-loop, which
  does event-detection and event-handling.

* Reactor:  The reactor design pattern is a concurrent programming pattern, for
  handling service requests delivered concurrently to a service handler by one
  or more inputs.

* The service handler then demultiplexes the incoming requests and dispatches
  them synchronously to associated request handlers.

The event loop almost always operates asynchronously with the message
originator.  The event loop forms the central constuct flow of the program, is
the highest level of control within the program. It is often termed as the
main-loop or the main-event loop.

The event loop is the specific implementation techniques of system which does
message passing.

Under Unix, everything is a file-paradigm naturally leads to a file based
event-loop. select and poll system calls monitor a set of file-descriptors for
events.

One of few things in Unix that do not confirm to file descriptors are
asynchronous events (signals); signals are received in signal handlers, small,
limited piece of code that run while rest of the task is suspended. 

Twisted project supports TCP, UDP, SSL/TLS and IP Multicast, Unix Domain
Sockets, a large number of protocols such  as HTTP, XMPP, NNTP, IMAP, SSH, IRC,
FTP.

Network Programming
-------------------

In Computing, Network Programming is essentially identified as socket
programming or client-server programming, involves writing computer programs
that communicate with other programs across the Computer Network.  The program
initiating the communication is called the client and the program waiting for
the communication to get initiated is called the server.  The client and the
server process together form the distributed system. The connection between the
client and the server process may be connection oriented (TCP/IP or session) or
connectionless (UDP)

The program that can act both as server and client is based on peer-to-peer
communication. Sockets are usually implemented by an API library such a
Berkeley sockets, first introduced in 1983. The example functions provided by
the API library include:

* socket() - creates a new socket of certain type, identified by the integer
  number and allocates system resources to it.
* bind() is used at the server side; associates a socket with a socket adddress
  structure, typically a IP Address and a Port number.
* listen() is used again on the server side, causes a bound TCP socket to
  listen to enter a listening state.
* connect() is used on the client side; used to assign a free local port number
  to the socket. It causes an attempt to establish a new TCP Connection.
* accept() is used on the server side; It accepts a received incoming connect()
  request and creates a new socket associated with the socket address pair for
  this connection.
* send(), recv(), write(), read() or recvfrom() and sendto() are used for
  sending and receiving data.
* close() is used to terminate the connection and release the resources
  allocated to the socket. 

Unicode Notes
-------------

A good introductory document for getting started with Unicode is, 
`Joel's article on Unicode`_

*Trivia: In ASCII when you press CNTL, you subtract 64 from the value of the
next character.  So BELL is ASCII 7, which is CNTL+G, (CNTL is 64) and G is
71.*

IN ASCII, the Codes below 32 were called unprintable. The space was 32 and
letter A was 65.  This could conveniently be stored in 7 bits.  Most computers
in those days were using 8 bit bytes, so not only you could store all the ASCII
characters, you had a whole bit to spare.  Because bytes have room for upto
eight bits, lots of people got into thinking, "gosh, we can use codes 128-255
for our own purposes." :) Eventually, this OEM free-for-all got codified in the
ANSI standard.  In the ANSI standard, everyone agreed for bottom 128 but not
the upper limits.  Asian alphabets have thousands of letters, which were never
going to fit into 8 bits.  This was actually solved by a messy system called
DBCS, the "double byte character set" in which some letters were stored in one
byte and others took two bytes.It was easy to move forward in a string, but it
was impossible to move backwards in the string.  Programmers were encouraged
not to use s++ or s-- but instead rely on Windows' AnsiNext and AnsiPrev
functions which knew how to deal with that mess.

**Unicode**

Unicode was a brave effort to create a single character set that included every
reasonable writing system on the planet.  Some people are under the
mis-conception that unicode is simply a 16-bit code where each character takes
16 bits and therefore there are 65,536 possible characters, which is incorrect.

In Unicode, every alphabet is assigned a magic number by the Unicode consortium
which is written like this: U+0639. This number is called the code-point. The
U+ means "Unicode" and the numbers are in hexadecimal notation. U+0639 is the
arabic letter Ain (ع).

There is no real limit on the number of letters that Unicode can define and in
fact, they have gone beyond 65,536 so not every unicode letter can really be
squeezed into two bytes. That was a myth anyways.

OK, so we have a string: Hello which, in Unicode, corresponds to these five
code-points: U+0048 U+0065 U+006C U+006C U+006F 

It was U- before 3.0 and then it became U+. If you look at the release notes of
Unicode 3.0, you might find the reason for the change.

How do we store those numbers?  That is where encoding comes in.

The earliest idea was, that to store the numbers in two bytes each:

	00 48 00 65 00 6C 00 6C 00 6F.

Why not it be stored like this:

	48 00 65 00 6C 00 6C 00 6F 00

Well, it could be stored in that way too. Early implementors wanted to store
the numbers in either big-endian or little-endian, in whichever way their
particular CPU  was fastest at. So, people came up with Byte Order Mark, where
FEFF denoted Little Endian and FFFE denoted big endian.

FEFF - Little Endian
FFFE - Big Endian

*nmemonic - Three F's together is BIG.*

For a while, it seemed like that might be good enough, but programmers were
complaining. "Look at all those zeros!", they said, since they were Americans
and they were looking at English text which rarely used code points above
U+OOFF.  People decided to ignore Unicode and things got worse.  And thus was
invented the brilliant concept of UTF-8. (Read Rob Pike's mail)

In UTF-8, every code point from 0-127 is stored in a single byte. Only code
points 128 and above are stored using 2, 3, in fact upto 6 bytes.  This has the
neat side-effect that English text looks exactly the same in UTF-8 as it did in
ASCII, so Americans don't even notice anything wrong.  Specifically, Hello
which was "0048, 0065, 006C, 006C and 006F" would simply be stored as
48,65,6C,6C and 6F.

So, here we have ways such as UCS-2 (UTF-16), which had its own UCS-2 little
endian or UCS-2 big endian and then UTF-8 encoding method.  There are also a
bunch of other ways of encoding Unicode. There is something called UTF-7, which
is lot like UTF-8 but guarantees that the high bit will always be zero.  It was
for systems which can recognize only 7 bits. UCS-4 which stores each code point
in 4 bytes, which has a nice property that every single code point can be
stored in same number of bytes. But that is memory hungry.

There are hundreds of traditional encodings, which can only store some
code-points correctly and change all other code points into question marks.
Some popular encodings of the English text are, Windows 1252 and ISO-8859-1,
aka Latin-1 (also useful for any western european languages). But try to store
Russian, or Hebrew letters in those encodings and you will get a bunch of
question marks. UTF 7, UTF 8, UTF 16 and UTF 32 all have the nice property of
being able to store any code point correctly.

If you have a string in memory, in a file, or in an email message, you have to
know what encoding it is in or you cannot interpret it or display to your users
correctly.  All the problems of ????, comes down to the fact that if you don't
tell me whether a particular string is encoded using UTF-8 or ASCII or ISO
8859-1 (Latin 1) or Western 1252 (Western European), you simply cannot display
it correctly or even figure it out where it actually ends.  There are over 100
encodings, and above code point 127, all the bets are off.

How do we preserve this information about what encoding a string uses?  Email,
Content-Type: text/plain; charset="UTF-8" For a web page, the original idea was
that the web server would return a similar Content-Type http header along with
the web page itself -- not in the HTML itself, but as one of the response
headers that are sent before the HTML page.

Relying on webserver to send Content-Type was problematic, because many
different people could use the same web-server for different types of web
pages.  It would be convenient, if you could put the Content-Type of the HTML
file right in the HTML file itself, using some kind of a special tag.  All
encoding uses same character between 32 and 127, so you could get to the point
wherein you could read the <meta> header.

The RFC which explains UTF-8::

        http://www.ietf.org/rfc/rfc3629.txt

        The most interesting part of the RFC, which is leading me to understand the
        system better is explained here:

           The table below summarizes the format of these different octet types.
           The letter x indicates bits available for encoding bits of the
           character number.

           Char. number range  |        UTF-8 octet sequence
              (hexadecimal)    |              (binary)
           --------------------+---------------------------------------------
           0000 0000-0000 007F | 0xxxxxxx
           0000 0080-0000 07FF | 110xxxxx 10xxxxxx
           0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
           0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

           Encoding a character to UTF-8 proceeds as follows:

           1.  Determine the number of octets required from the character number
               and the first column of the table above.  It is important to note
               that the rows of the table are mutually exclusive, i.e., there is
               only one valid way to encode a given character.

           2.  Prepare the high-order bits of the octets as per the second
               column of the table.

           3.  Fill in the bits marked x from the bits of the character number,
               expressed in binary.  Start by putting the lowest-order bit of
               the character number in the lowest-order position of the last
               octet of the sequence, then put the next higher-order bit of the
               character number in the next higher-order position of that octet,
               etc.  When the x bits of the last octet are filled in, move on to
               the next to last octet, then to the preceding one, etc. until all
               x bits are filled in.

           The definition of UTF-8 prohibits encoding character numbers between
           U+D800 and U+DFFF, which are reserved for use with the UTF-16
           encoding form (as surrogate pairs) and do not directly represent
           characters.  When encoding in UTF-8 from UTF-16 data, it is necessary
           to first decode the UTF-16 data to obtain character numbers, which
           are then encoded in UTF-8 as described above.  This contrasts with
           CESU-8 [CESU-8], which is a UTF-8-like encoding that is not meant for
           use on the Internet.  CESU-8 operates similarly to UTF-8 but encodes
           the UTF-16 code values (16-bit quantities) instead of the character
           number (code point).  This leads to different results for character
           numbers above 0xFFFF; the CESU-8 encoding of those characters is NOT
           valid UTF-8.

           Decoding a UTF-8 character proceeds as follows:

           1.  Initialize a binary number with all bits set to 0.  Up to 21 bits
               may be needed.

           2.  Determine which bits encode the character number from the number
               of octets in the sequence and the second column of the table
               above (the bits marked x).

           3.  Distribute the bits from the sequence to the binary number, first
               the lower-order bits from the last octet of the sequence and
               proceeding to the left until no x bits are left.  The binary
               number is now equal to the character number.

           Implementations of the decoding algorithm above MUST protect against
           decoding invalid sequences.  For instance, a naive implementation may
           decode the overlong UTF-8 sequence C0 80 into the character U+0000,
           or the surrogate pair ED A1 8C ED BE B4 into U+233B4.  Decoding
           invalid sequences may have security consequences or cause other
           problems.  See Security Considerations (Section 10) below.

        4.  Syntax of UTF-8 Byte Sequences

           For the convenience of implementors using ABNF, a definition of UTF-8
           in ABNF syntax is given here.

           A UTF-8 string is a sequence of octets representing a sequence of UCS
           characters.  An octet sequence is valid UTF-8 only if it matches the
           following syntax, which is derived from the rules for encoding UTF-8
           and is expressed in the ABNF of [RFC2234].

           UTF8-octets = \*( UTF8-char )
           UTF8-char   = UTF8-1 / UTF8-2 / UTF8-3 / UTF8-4
           UTF8-1      = %x00-7F
           UTF8-2      = %xC2-DF UTF8-tail
           UTF8-3      = %xE0 %xA0-BF UTF8-tail / %xE1-EC 2( UTF8-tail )/ 
                         %xED %x80-9F UTF8-tail / %xEE-EF 2( UTF8-tail )
           UTF8-4      = %xF0 %x90-BF 2( UTF8-tail ) / %xF1-F3 3( UTF8-tail )/
                         %xF4 %x80-8F 2( UTF8-tail )
           UTF8-tail   = %x80-BF

           NOTE -- The authoritative definition of UTF-8 is in [UNICODE].  This
           grammar is believed to describe the same thing Unicode describes, but
           does not claim to be authoritative.  Implementors are urged to rely
           on the authoritative source, rather than on this ABNF.


The official name of the encoding is UTF-8, where UTF stands for UCS
Transformation Format 8.  Write it as UTF-8 only.  There is no limit on the
number of the characters that Unicode could define.  and it has definiely
exceeded beyond, 65536 characters.

Exercise 1:

Convert the following to Unicode:
1) "Hello, World"
2) नमसूऐर दुनयि॥

Answer:

1)"Hello, World" is present in 

U0000 and U+0048 U+0065 U+006C U+006C U+006F U+002C U+0057 U+006F U+0072 U+006C
U+0064

2) नमसूऐर दुनयि॥

Is the devnagari script that starts with U0900 U+0928 U+092E U+0938 U+0942
U+0915 U+090 U+0930 U+0926 U+0941 U+0928 U+092F U+093F U+0965

The above was just a bunch of code points. We have not said anything about how
to store them in memory or represent them in email messages yet.

Encodings

English meaning of encoding is is wrapping it in a cipher code.  The earlier
method was to store those codepoints which are 4 hexadecimal digits as 2 bytes.

Convert Unicode to Hexadecimals::
http://ln.hixie.ch/?start=1064324988&count=1

Typing Unicode and maths symbols on gnome-terminal

1) Hold CTRL+SHIFT + U + codepoint + SPACE
2) For e.g. CTRL+SHIFT+U+2201+SPACE will give Unicode Maths Symbol 

Unicode code point chart:
http://inamidst.com/stuff/unidata/

urllib 
------

**functions**

* urlopen
* install_opener
* build_opener
* request_host
* _parse_proxy
* randombytes
* parse_keqv_list
* parse_http_list

**class**

* Request
* OpenerDirector
* BaseHandler
  * HTTPErrorProcessor
  * HTTPCookieProcessor
  * HTTPDefaultErrorHandler
  * HTTPRedirectHandler
  * ProxyHandler
  * AbstractHTTPHandler
  * UnknownHandler
  * FileHandler
  * FTPHandler
  * CacheFTPHandler

* AbstractHTTPHandler
  * HTTPHandler
  * HTTPSHandler

* HTTPPasswordMgr
  * HTTPPasswordMgrWithDefaultRealm

* AbstractBasicAuthHandler

* AbstractBasicAuthHandler, BaseHandler
  * HTTPBasicAuthHandler
  * ProxyBasicAuthHandler

* AbstractDigestAuthHandler

* BaseHandler, AbstractDigestAuthHandler
  * HTTPDigestAuthHandler
  * ProxyDigestAuthHandler


urlopen -> build_opener -> OpenerDirector() -> OpenerDirector.add_handler for
each class and handler -> OpenerDirector.open() method on the composite object.
-> Request -> returns stateful url -> protocol_request is called -> _open ->
and protocol_response is called and returned. The handler is invoked in the
specific order as specified by the Handler attribute.

**OpenerDirector**

handlers is a list.
handle_open is a dictionary.
handle_error is a dictionary.
process_request is a dictionary.
process_response is a dictionary.

When handlers are getting added, it should not have attribute called
add_parent.

For each handler don't add the methods redirect_request, do_open, proxy_open

The methods which are like _error, _open, _request, _response are handled in a
special manner.  The error, open and response are called conditions.  And the
terms preceding them are called protocol.

When it is an error condition, some magic is done to find it's kind. The error
kind could have been got from the error_XXX, but instead, it the position is
determined and then it is extraced from the method name. Surprisingly, kind is
not used in the error block. Instead, in the OpenerDirector's handle_error
dictionary, for the protocol, which got an _error, a key is added, the value is
initially {}.

If the condition is _open, the kind is the protocol and the lookup is handle_open dictionary.
If the condition is _request, the kind is the protocol and the lookup process_request dictionary.
If the condition is _response, the kind is the protocol and the lookup is process_response.

Why is it that redirect_request, do_open and proxy_open are not handled.

Because it is a for loop on the methods of the handler, the kind and the lookup
is set at the end and it could be either for error, open, request or response.
But within the for loop, the handler having those methods is added. It is
bisect.insorted and then, again, it is bisect.insorted for all the handlers.

So, it seems that for that portion of the code, the appropriate handlers are
added. That is all.

What happens is, for any of these dictionaries, if it is an error, open,
request or response, dictionary method's setdefault is called for that protocol

There is a doubt when added=True comes in, handlers is list of all handlers is
added. What's an add_unredirectedheader doing and what is it's purpose?  What
is self._call_chain's behavior?  The redirect_cache was not setting in, because
the object's parent method was calling and entirely new request, forgetting
about the current request. When made a change that request object is carrying
the information about the redirect, the cache hit was observed. Something along
the same lines would be good.


Apache setup and URL RFCs
-------------------------

In order to setup a password for your apache based site, in the
/var/www/.htaccess file specify the username and password as senthil:senthil

Some clients support the no_proxy environment variable that specifies a set of
domains for which the proxy should not be consulted; the contents is a
comma-separated list of domain names, with an optional :port part.

WWW-Authenticate

The WWW-Authenticate response-header field must be included in 401
(unauthorized) response messages. The field value consists of at least one
challenge that indicates the authentication scheme(s) and parameters applicable
to the Request-URI.

       WWW-Authenticate = "WWW-Authenticate" ":" 1#challenge

The HTTP access authentication process is described in Section 11. User agents
must take special care in parsing the WWW-Authenticate field value if it
contains more than one challenge, or if more than one WWW-Authenticate header
field is provided, since the contents of a challenge may itself contain a
comma-separated list of authentication parameters. 

Following are some of the notes I took, while working on urllib patches.  It
should be a handy reference when working on bugs again.

RFC 3986 Notes:

A URI is a sequence of characters that is not always represented as a sequence
of octets.Percent-encoded octets may be used within a URI to represent
characters outside the range of the US-ASCII coded character set.

Specification uses Augmented Backus-Naur Form (ABNF) notation of RFC2234,
including the following core ABNF syntax rules defined by that specification:
ALPHA (letters), CR ( carriage return), DIGIT (decimal digits), DQUOTE (double
quote), HEXDIG (hexadecimal digits), LF (line feed) and SP (space).

Section 1 of RFC3986 is very generic. Understand that URI should be
transferable and single generic syntax should denote the whole range of URI
schemes.URI Characters are, in turn, frequently encoded as octets for transport
or presentation. This specification does not mandate any character encoding for
mapping between URI characters and the octets used to store or transmit those
characters.

pct-encoded = "%" HEXDIG HEXDIG

For consistency, uri producers and normalizers should use uppercase
hexadecimal digits, for all percent - encodings.

reserved = gen-delims / sub-delims
gen-delims = ":" / "/" / "?" / "#" / "[" / "]" / "@"
sub-delims = "!" / "$" / "&" / "'" / "(" / ")"
/ "*" / "+" / "," / ";" / "="

unreserved = ALPHA / DIGIT / "-" / "." / "_" / "~"

When a new URI scheme defines a component that represents textual data
consisting of characters from the Universal Character Set, the data should
first be encoded as octets according to the UTF-8 character encoding [STD63];
then only those octets that do not correspond to characters in the unreserved
set should be percent- encoded. For example, the character A would be
represented as "A", the character LATIN CAPITAL LETTER A WITH GRAVE would be
represented as "%C3%80", and the character KATAKANA LETTER A would be
represented as "%E3%82%A2".

How that is being used encoding reservered characters within data. Transmission
of url from local to public when using a different encoding - translate at the
interface level.

URI = scheme ":" hier-part [ "?" query ] [ "#" fragment ]

hier-part = "//" authority path-abempty
/ path-absolute
/ path-rootless
/ path-empty

Many URI schemes include a hierarchical element for a naming
authority so that governance of the name space defined by the
remainder of the URI is delegated to that authority (which may, in
turn, delegate it further):: 

        userinfo = *( unreserved / pct-encoded / sub-delims / ":" )
        host = IP-literal / IPv4address / reg-name

In order to disambiguate the syntax host between IPv4address and reg-name, we
apply the "first-match-wins" algorithm. A host identified by an Internet
Protocol literal address, version 6 [RFC3513] or later, is distinguished by
enclosing the IP literal within square brackets ("[" and "]"). This is the only
place where square bracket characters are allowed in the URI syntax::

        IP-literal = "[" ( IPv6address / IPvFuture ) "]"

        IPvFuture = "v" 1*HEXDIG "." 1*( unreserved / sub-delims / ":" )

        IPv6address = 6( h16 ":" ) ls32
        / "::" 5( h16 ":" ) ls32
        / [ h16 ] "::" 4( h16 ":" ) ls32
        / [ *1( h16 ":" ) h16 ] "::" 3( h16 ":" ) ls32
        / [ *2( h16 ":" ) h16 ] "::" 2( h16 ":" ) ls32
        / [ *3( h16 ":" ) h16 ] "::" h16 ":" ls32
        / [ *4( h16 ":" ) h16 ] "::" ls32
        / [ *5( h16 ":" ) h16 ] "::" h16
        / [ *6( h16 ":" ) h16 ] "::"

        ls32 = ( h16 ":" h16 ) / IPv4address
        ; least-significant 32 bits of address

        h16 = 1*4HEXDIG
        ; 16 bits of address represented in hexadecimal

        IPv4address = dec-octet "." dec-octet "." dec-octet "." dec-octet

        dec-octet = DIGIT ; 0-9
        / %x31-39 DIGIT ; 10-99
        / "1" 2DIGIT ; 100-199
        / "2" %x30-34 DIGIT ; 200-249
        / "25" %x30-35 ; 250-255

        reg-name = *( unreserved / pct-encoded / sub-delims )


Non-ASCII characters must first be encoded according to UTF-8 [STD63], and then
each octet of the corresponding UTF-8 sequence must be percent-encoded to be
represented as URI characters.  When a non-ASCII registered name represents an
internationalized domain name intended for resolution via the DNS, the name
must be transformed to the IDNA encoding [RFC3490] prior to name lookup.

Section 3 was about sub-components and their structure and if they are
represented in NON ASCII how to go about with encoding/decoding that::

        path = path-abempty ; begins with "/" or is empty
        / path-absolute ; begins with "/" but not "//"
        / path-noscheme ; begins with a non-colon segment
        / path-rootless ; begins with a segment
        / path-empty ; zero characters

        path-abempty = *( "/" segment )
        path-absolute = "/" [ segment-nz *( "/" segment ) ]
        path-noscheme = segment-nz-nc *( "/" segment )
        path-rootless = segment-nz *( "/" segment )
        path-empty = 0<pchar>
        segment = *pchar
        segment-nz = 1*pchar
        segment-nz-nc = 1*( unreserved / pct-encoded / sub-delims / "@" )
        ; non-zero-length segment without any colon ":"

        pchar = unreserved / pct-encoded / sub-delims / ":" / "@"

        relative-ref = relative-part [ "?" query ] [ "#" fragment ]

        relative-part = "//" authority path-abempty
        / path-absolute
        / path-noscheme
        / path-empty

Section 4 was on the usage aspects and heuristics used in determining in the
scheme in the normal usages where scheme is not given.  Base uri must be
stripped of any fragment components prior to it being used as a Base URI.

Section 5 was on relative reference implementation algorithm. I had covered
them practically in the Python urlparse module.Section 6 was on Normalization
of URIs for comparision and various normalization practices that are used.

Dissecting urlparse:
--------------------

* __all__ methods provides the public interfaces to all the methods like
urlparse, urlunparse, urljoin, urldefrag, urlsplit and urlunsplit.

* then there is classification of schemes like uses_relative, uses_netloc,
non_hierarchical, uses_params, uses_query, uses_fragment

- there should be defined in an rfc most probably 1808.

- there is a special '' blank string, in certain classifications, which
means that apply by default.

* valid characters in scheme name should be defined in 1808.

* class ResultMixin is defined to provide username, password, hostname and
port.

* The behaviour of the public methods urlparse, urlunparse, urlsplit and
urlunsplit and urldefrag matter most.

urlparse - scheme, netloc, path, params, query and fragment.
urlunparse will take those parameters and construct the url back.

urlsplit - scheme, netloc, path, query and fragment.
urlunsplit - takes these parameters (scheme, netloc, path, query and fragment)
and returns a url.

As per the RFC3986, the url is split into: 

scheme, authority, path, query, frag = url

The authority part in turn can be split into the sections:
user, passwd, host, port = authority

The following line is the regular expression for breaking-down a
well-formed URI reference into its components.

:: 

        ^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?
        12 3 4 5 6 7 8 9

        scheme = $2
        authority = $4
        path = $5
        query = $7
        fragment = $9


The urlsplit functionality in the urllib can be moved to new regular
expression based parsing mechanism.

From man uri, which confirms to rfc2396 and HTML 4.0 specs.

* An absolute identifier refers to a resource independent of context, while a
  relative identifier refers to a resource by describing the difference from
  the current context.

* A path segment while contains a colon character ':' can't be used as the
  first segment of a relative URI path. Use it like this './file:path'

* A query can be given in the archaic "isindex" format, consisting of a word or
  a phrase and not including an equal sign (=). If = is there, then it must be
  after & like &key=value format.

Character Encodings:

* Reserved characters: ;/?:@&=+$,
* Unreserved characters: ALPHA, DIGITS, -_.!~*'()

An escaped octet is encoded as a character triplet consisting of the percent
character '%' followed by the two hexadecimal digits representing the octet
code.HTML 4.0 specification section B.2 recommends the following, which should
be considered best available current guidance:

1) Represent each non-ASCII character as UTF-8
2) Escape those bytes with the URI escaping mechanism, converting each byte to
   %HH where HH is the hexadecimal notation of the byte value.

One of the important changes when adhering to RFC3986 is parsing of IPv6
addresses.

CacheFTPHandler testcases are hard to write. 

Here's how the control goes.

1) There is an url with two '//'s in the path.
2) The call is data = urllib2.urlopen(url).read()
3) urlopen calls the build_opener. build_opener builds the opener using (tuple)
of handlers.
4) opener is an instance of OpenerDirector() and has default HTTPHandler and
HTTPSHandler.
5) When the Request call is made and the request has 'http' protocol, then
http_request method is called.

::
         HTTPHandler has http_request method which is
         AbstractHTTPHandler.do_request_ Now, for this issue we get to the
         do_request_ method and see that host is set in the do_request_ method
         in the get_host() call.

         request.get_selector() is the call which is causing this particular
         issue of "urllib2 getting confused with path containing //".
         .get_selector() method returns self.__r_host.

Now, when proxy is set using set_proxy(), self.__r_host is self.__original (
The original complete url itself), so the get_selector() call is returns the
sel_url properly and we can get the host from the splithost() call on the
sel_url.

When proxy is not set, and the url contains '//' in the path segment, then
.get_host() (step 7) call would have seperated the self.host and self.__r_host
(it pointing to the rest of the url) and .get_selector() simply returns this
(self.__r_host, rest of the url expect host. Thus causing call to fail.

9) Before the fix, request.add_unredirected_header('Host', sel_host or host)
had the escape mechanism set for proper urls wherein with sel_host is not set
and the host is used. Unfortunately, that failed when this bug caused sel_host
to be set to self.__r_host and Host in the headers was being setup wrongly (
rest of the url).

The patch which was attached appropriately fixed the issue. I modified and
included for py3k.

* urllib2 in python 3k was divided into urllib.request and urllib.error. I was
  thinking if the urllib.response class is included; but no, response object is
  nothing but a addinfourl object.

Example of  Smart Redirect Handler 
----------------------------------

::

        import urllib2

        class SmartRedirectHandler(urllib2.HTTPRedirectHandler):
            def http_error_302(self, req, fp, code, msg, headers):
                result = urllib2.HTTPRedirectHandler.http_error_302(self, req, fp,
                                                                         code, msg,
                                                                         headers)
                result.status = code
                return result

        request = urllib2.Request("http://localhost/index.html")
        opener = urllib2.build_opener(SmartRedirectHandler())
        obj = opener.open(request)
        print 'I capture the http redirect code:', obj.status
        print 'Its been redirected to:', obj.url

* Apache 2.0 supports IPv6.

::
        phoe6:  I want to setup a test server which will do a redirect ( I know
        how to do that), but with a delay. So that when I am testing my client,
        I can test the clients timeout. Can someone give me suggestions as how
        can i go about this?

        jMCg: phoe6: http://httpd.apache.org/docs/2.2/mod/mod_ext_filter.html#examples

* apache is configured by placing directives in configuration files. the main configuration file is called apache2.conf
* Other configuration files are added by Include directive.

How is the HTTP response given by the urllib?
GetRequestHandler which takes the responses as the parameter and returns a handler.
What does the GetRequestHandler do?
It takes responses as one of its argument.
Implements a FakeHTTPRequestHandler which is extending BaseHTTPRequestHandler.
BaseHTTPRequestHandler implements do_GET, do_POST and send_head
The send_head method when it is returning the body it is sending it properly.

Why is that the response is getting trimmed to 49042?


Having a construct like::

        def __init__(self, *args, **kwargs):
        BaseClass.__init__(self, *args, **kwargs)

But in the base class, I find that it is not taking the tuple and dict as
arguments.

* What is an addrinfo struct.

The getaddrinfo() function returns a list of 5-tuples with the following
structure: (family, socktype, proto, canonname, sockaddr)

family, socktype, proto are all integer and are meant to be passed to the
socket() function. canonname is a string representing the canonical name of the
host. It can be a numeric IPv4/v6 address when AI_CANONNAME is specified for a
numeric host.

socket.gethostbyname(hostname)

Translate a host name to IPv4 address format. The IPv4 address is returned as a
string, such as '100.50.200.5'. If the host name is an IPv4 address itself it
is returned unchanged. See gethostbyname_ex() for a more complete interface.
gethostbyname() does not support IPv6 name resolution, and getaddrinfo() should
be used instead for IPv4/v6 dual stack support.

We need to replace the gethostbyname socket call. Because it is only IPv4
specific. using the getaddrinfo() function can include the IPv4/v6 dual stack
support.

import socket
print socket.gethostbyname(hostname)

def gethostbyname(hostname)
family, socktype, proto, canonname, sockaddr = socket.getaddrinfo(hostname)
return canonname

RFC 1123 date format:
Thu, 01 Dec 1994 16:00:00 GMT

::

        >>> datereturned = "Thu, 01 Dec 1994 16:00:00 GMT"
        >>> dateexpired = "Sun, 05 Aug 2007 03:25:42 GMT"
        >>> obj1 = datetime.datetime(*time.strptime(datereturned, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
        >>> obj2 = datetime.datetime(*time.strptime(dateexpired, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
        >>> if obj1 == obj2:
        print "Equal"
        elif obj1 > obj2:
        print datereturned
        elif obj1 < obj2:
        print dateexpired


Header field definition:
http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html

To add header:
Go to the /etc/httpd/conf/httpd.conf
For e.g:
Add the information on headers
Header set Author "Senthil"

Question:
What is metaclass attributes?
Look a bit into property.
Usage of Ellipses


Alex Martelli's Tutorials
-------------------------

1) http://www.aleax.it/python_mat_en.html

2) http://www.strakt.com/dev_talks.html


Python and Vim
--------------

http://henry.precheur.org/2008/4/18/Indenting_Python_with_VIM.html
 
http://blog.sontek.net/2008/05/11/python-with-a-modular-ide-vim/ 

References
----------

* [http://code.activestate.com/recipes/86900/ Factory Example]
* [http://www.suttoncourtenay.org.uk/duncan/accu/pythonpatterns.html Python Patterns]

Links
=====
http://stockrt.github.com/p/emulating-a-browser-in-python-with-mechanize/

* "Python Objects", Fredrik Lundh,
  http://www.effbot.org/zone/python-objects.htm

* "Python main() functions", Guido van Rossum,
  http://www.artima.com/weblogs/viewpost.jsp?thread=4829

* "Sorting Mini-HOWTO", Andrew Dalke,
  http://wiki.python.org/moin/HowTo/Sorting

.. _Joel's article on Unicode: http://www.joelonsoftware.com/articles/Unicode.html 
