============
Python Notes
============

.. warning:: 

        Work in Progress.

CPython Development Process
---------------------------

#) **What are the steps involved while using hg.python.org?**

    * update all codelines.
    * Start working on 3.2 codeline and fix and commit and push. It will push
      it cpython. 
    * hg pull -u ../3.2
    * hg merge 3.2
    * resolve any conflicts.
    * do the same for cpython
    * hg push will commit your changes.

#) **How to bring your sandbox repo upto sync with main line?**

    * hg pull ../cpython (-u wont work)
    * hg merge
    * hg commit
    * hg push

#) **How to create and applying Patches to the tree?**

    * Create a patch
    * Run make patchcheck before creating it.
    * hg diff > issue1234.diff
    * Apply it: 
      * patch -p1 < issue4321.diff, or
      * hg import --no-commit < issue4321.diff

#) **Running the Test Suite**

    Different ways to run the tests with regrtest, the runner of the Python
    test suite which lives in ``Lib/test/regrtest.py.``

    * ./python -m test.regrtest to run the test suite
    * ./python -m test.regrtest -uall to run all the tests
    * ./python -m test.regrtest -j4 to run the tests in 4 processes
    * ./python -m test.regrtest test_foo to run test_foo
    * ./python -m test.regrtest -R 3:2 to check for refleaks
    * ./python -m test.regrtest --help to see all the options
    * ./python -m test -m testSourceAddress -Fv -j3 test_smtplib                                                                                          

#) **Using coverage with python**

    Download coveragepy and make a symlink within the python directory ``ln -s coveragepy/coverage``.
    The execute coverage like this.::
        
        ./python -m coverage run --pylib Lib/test/regrtest.py

     To get the html report.::

        ./python -m coverage html -i --omit="*/test/*,*/tests/*"

                                                              
Python Programming
------------------

#) **How will trace Python Programs?**

    * python -m trace --trace programname.py
    * vim with pycscope
    * pychecker (bug detection)
    * PyMetrics (identify complexity)
    * pylint
    * cProfile and Hotspot.
    * Cyclops
    * UML Diagram with PyNSource
    * Pyut
    * gaphor
    * ddd 
    * pudb
    * Refactoring - Rope IDE
    * Bicycle Repair man
    * Python Call Graph
    * Pydoc and pydoctor
    * Leo (Literate Programming Tool)


#) **How will you use Python C-API ?**

    The Python API is incorporated in a C source file by including the header
    "Python.h". Do note that if your use case is calling C library functions or
    system calls, you should consider using the ctypes module rather than
    writing custom C code.  Not only does ctypes let you write Python code to
    interface with C code, but it is more portable between implementations of
    Python than writing and compiling an extension module which typically ties
    you to CPython.


#) **What is the Statement Separator in Python?**

    Python uses carriage returns to separate statements and a colon and
    indentation to separate code blocks. C++ and Java use semicolons to
    separate statements and curly braces to separate code blocks.

#) **Can you do inline assignment in Python?**

    Like c, Python uses == for comparison and = for assignment. Unlike c,
    Python does not support in-line assignment, so there’s no chance of
    accidentally assigning the value you thought you were comparing.

#) **How does python int truncate**

    The int() function truncates negative numbers towards 0. It’s a true
    truncate function, not a floor function.

#) **How are lists implemented in Python**

    For lists in python, a better analogy would be the ArrayList class in Java,
    which can hold arbitrary objects and can expand dynamically as new items
    are added.

#) **What is the best way to remember negative slice indexing?**

    If the negative index is confusing to you, think of it this way: a_list[-n]
    == a_list[len(a_list) - n]. So in this list of length 5, a_list[-3] ==
    a_list[5 - 3] == a_list[2].  For list representation, If it helps, you can
    think of it this way: reading the list from left to right, the first slice
    index specifies the first item you want, and the second slice index
    specifies the first item you don’t want.  The return value is everything in
    between.

#) **In Python3 can you create a set with {}**

    Due to historical quirks carried over from Python 2, you can not create an
    empty set with two curly brackets. This actually creates an empty
    dictionary, not an empty set.

#) **Behavior of Index on empty list and discard on emtpy set**
    
    If you call index() method with a value that does not exist in a list, an
    IndexError exception is raised. If you call the discard() method with a
    value that doesn’t exist in the set, it does nothing. No error; it’s just a
    no-op.  Here’s the difference: if the value doesn’t exist in the set, the
    remove() method raises a KeyError exception.

#) **Compare Python dictionary to perls**

    A dictionary in Python is like a hash in Perl 5. In Perl 5, variables that
    store hashes always start with a % character. In Python, variables can be
    named anything, and Python keeps track of the datatype internally.

#) **Can you create NoneType objects?**

    No. You can assign None to any variable, but you can not create other
    NoneType objects.

#) **What is a memoryview object?**

    A memoryview object exposes the C level buffer interface as a Python object
    which can then be passed around like any other object.  
    class memoryview(obj) - Create a memoryview that references obj. obj must
    support the buffer protocol.  Built-in objects that support the buffer
    protocol include bytes and bytearray.

#) **What does the trace.py module do?**

    It helps in tracing the python program or function execution. It helps in
    determining the coverage of code.  Like trace through the program execution
    details, determine how many times a particular line was visited, etc.  The
    usage is simple, do python ``trace.py --trace hello.py``

#) **If I want to build python from source in Ubuntu, what packages will make it build completely?**

    These are the packages which will help you build python completely, that is
    dependencies satisfied for all the modules.:: 

        sudo apt-get install libssl-dev libreadline-dev libgdbm-dev \ 
        tk-dev tk-tile libsqlite3-dev libdb4.7-dev libbz2-dev

#) **How do I see the System Calls when a Python program is executed?**

    By using strace. strace is a Linux command line utility that traces the
    system calls.::

            $strace python 1.py

    What is spitted out is an enormous amout of details on the system calls
    which are executed when running this program.

#) **What is a defaultdict?**

    A defaultdict is a dictionary which will return default values for missing
    keys. When you create a defaultdict, you provide a factory function, which will
    be called for returning the default value::

        >>> from collections import defaultdict
        >>> d = defaultdict(lambda: 42)
        >>> d[10]
        42
        >>> d[100]
        42
        >>> d
        defaultdict(<function <lambda> at 0x7fc5616c8500>, {10: 42, 100: 42})
        >>>

#) **How would implement the defaultdict's behavior using the normal dict?**

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

#) **What is special with `and` and `or` operators in python?.**

    ``and`` returns the right operand if the left is true. 
    ``or`` returns the right operand if the left is false.

    Otherwise they both return the left operand. They are said to coalesce One
    way to remember is to consider the binary truth tables.

    ::

        A and B
        0 0 -> 0
        0 1 -> 0
        1 0 -> 0
        1 1 -> 1

    So, when A is False, the value of B is irrelevant, so Python skips it
    completely. Otherwise, Python has to evaluate B to find out the overall
    value of the expression.    

    ::

        A or B
        0 0 -> 0
        0 1 -> 1
        1 0 -> 1
        1 1 -> 1

    Here, the truth table shows clearly that B is now irrelevant when A is
    *True*, so that is the case that short circuits. Only if A is False does
    the value of B matter.

#) **What is the difference between a bytes string and a unicode?**

    Byte string is the 8 bit string. Unicode is not a 8 bit string. Unicode
    strings are a new generation of strings in themselves.

#) **What is difference between the terms iterable and iterator?**

    Iterator generally points to a single instance in a collection.  Iterable
    implies that one may obtain an iterator from an object to traverse over its
    elements - and there's no need to iterate over a single instance, which is
    what an iterator represents.

    Behind the scenes, the iterator statement calls iter() on the container
    object.  The function returns an iterator object that defines the method
    next() which accesses elements in the container one at a time.
    StopIterationException terminates

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

    A string is a sequence (isinstance('', Sequence) == True) and as any
    sequence it is iterable (isinstance('', Iterable)). Though hasattr('',
    '__iter__') == False and it might be confusing. 

#) **How do you extending Python?**

    To support extensions, the Python API (Application Programmers Interface)
    defines a set of functions, macros and variables that provide access to
    most aspects of the Python run-time system. The Python API is incorporated
    in a C source file by including the header "Python.h".

#) **How is the Python Private methods and Attributes handled?**

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

#) **What is Global Interpretor Lock?**

    Global Interpretor lock is used to protect the Python Objects from being
    modified by multiple threads at once. To keep multiple threads running, the
    interpretor automatically releases and reaquires the lock at regular
    intervals.  It also does this around potentially slow or blocking low level
    operations, such a file and network I/O.  This is used internally to ensure
    that only one thread runs in the Python VM at a time. Python offers to
    switch amongst threads only between bytecode instructions. Each bytecode
    instruction and all C implemented function is atomic from Python program's
    point of view.

#) **Different types of concurrency models?**

    * Java and C# uses shared memory concurrency model with locking provided by
      monitors. Message passing concurrency model have been implemented on top of
      the existing shared memory concurrency model.
    * Erlang uses message passing concurrency model.
    * Alice Extensions to Standard ML supports concurrency via Futures.
    * Cilk is concurrent C.
    * The Actor Model.
    * Petri Net Model.


#) **How would you represent unicode in python2?**

    In python 2.x, the a string starting with u'' is a unicode object. It might
    contain unicode code-point in the hexadecimal notation. If your terminal
    supports it, then printing that unicode object will print the proper
    character.  `chr` - Gives the characters of length 1 from in the range 0 to
    256. That is \x00 to \xff. It should be known that It borders the ASCII and
    it is the Latin-1 character set.It should also be known that \u00ff and 
    \xff are both same.

#) **What are the important properties of Python objects?**

    All Python Objects have:

    * A Unique identifier (returned by id())
    * A Type (returned by type())
    * And a content.

    The Identifier and the type of the object cannot be changed. Only under
    limited circumstances, user defined types can be changed.

    Some objects allow you to change their content, while some objects will not
    allow you to change the content.  The type is represented by type object
    which knows more obout the objects of this type, like how much memory they
    occupy, what methods they have.

    * Objects have 0 or more methods.
    * Objects have 0 or more names.

    There is no variable in python. They are just names and that too within
    namespaces. The names refer to a particular object on assignment. Even if
    the objects have methods, you can never change its type or identity.
    Things like attribute assignments and item references are just syntactic
    sugar.


#) **Summarize PEP-8 Coding Style standards of Python.**

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

#) **Why do named strings do not concatenate?**

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


#) **Example of the dictionary's setdefault method.**

    We have to initialize mutable dictionary values.  Each dictionary value
    will be a list.  This is the naïve way.::

        equities = {}
        for (portfolio, equity) in data:
            if portfolio in equities:
                equities[portfolio].append(equity)
            else:
                equities[portfolio] = [equity]


   ``dict.setdefault(key, default)`` does the job much more efficiently::

        equities = {}
        for (portfolio, equity) in data:
           equities.setdefault(portfolio, []).append( equity)

    ``dict.setdefault()`` is equivalent to "get, or set & get".  Or "set if
    necessary, then get".  It's especially efficient if your dictionary key is
    expensive to compute or long to type.

    The only problem with ``dict.setdefault()`` is that the default value is always
    evaluated, whether needed or not.  That only matters if the default value is
    expensive to compute.

    If the default value **is** expensive to compute, you may want to use the
    ``defaultdict`` class.


#) **Example of constructing a dictionary from two lists of key and values.**

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

#) **Example of enumerate function in Python.**

    The ``enumerate`` function takes a list and returns (index, item) pairs.::

        >>> print list(enumerate(items))
        [(0, 'zero'), (1, 'one'), (2, 'two'), (3, 'three')]

    We need use a ``list`` wrapper to print the result because ``enumerate`` is
    a lazy function: it generates one item, a pair, at a time, only when
    required.  A ``for`` loop is one place that requires one result at a time.
    ``enumerate`` is an example of a *generator*. ``print`` does not take one
    result at a time -- we want the entire result, so we have to explicitly
    convert the generator into a list when we print it.

    An example showing how the ``enumerate`` function actually returns an
    iterator (a generator is a kind of iterator).::

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

#) **What is special about variables in Python?**

    In many other languages, assigning to a variable puts a value into a box.
    Python has "names" In Python, a "name" or "identifier" is like a parcel tag
    (or nametag) attached to an object.

    Here, an integer 1 object has a tag labelled "a".  If we reassign to "a",
    we just move the tag to another object:

    Now the name "a" is attached to an integer 2 object.

    The original integer 1 object no longer has a tag "a".  It may live on, but
    we can't get to it through the name "a".  (When an object has no more
    references or tags, it is removed from memory.)

    If we assign one name to another, we're just attaching another nametag to
    an existing object::

           b = a

    The name "b" is just a second tag bound to the same object as "a". Although
    we commonly refer to "variables" even in Python (because it's common
    terminology), we really mean "names" or "identifiers".  In Python,
    "variables" are nametags for values, not labelled boxes.


    Function parameters are evaluated at definition time. How does it affect in
    an unexpected manner during program evaluation?

    This is a common mistake that beginners often make.  Even more advanced
    programmers make this mistake if they don't understand Python names.::

        def bad_append(new_item, a_list=[]):
            a_list.append(new_item)
            return a_list

    The problem here is that the default value of ``a_list``, an empty list, is
    evaluated at function definition time.  So every time you call the
    function, you get the **same** default value.  Try it several times::

       >>> print bad_append('one')
       ['one']

   ::

       >>> print bad_append('two')
       ['one', 'two']

    Lists are a mutable objects; you can change their contents.  The correct
    way to get a default list (or dictionary, or set) is to create it at run
    time instead, **inside the function**.::

       def good_append(new_item, a_list=None):
           if a_list is None:
               a_list = []
           a_list.append(new_item)
           return a_list

#) **How do you use advanced string formatting features?**

    By name with a dictionary::

       values = {'name': name, 'messages': messages}
       print ('Hello %(name)s, you have %(messages)i '
              'messages' % values)

    Here we specify the names of interpolation values, which are looked up in
    the supplied dictionary. Notice any redundancy?  The names "name" and
    "messages" are already defined in the local namespace.  We can take
    advantage of this.

    By name using the local namespace::

       print ('Hello %(name)s, you have %(messages)i '
              'messages' % locals())


    The namespace of an object's instance attributes is just a dictionary,
    ``self.__dict__``. By name using the instance namespace::

       print ("We found %(error_count)d errors"
              % self.__dict__)

#) **What is list comprehension?**

    List comprehensions are syntax shortcuts for construction of lists. As a
    list comprehension::

       new_list = [fn(item) for item in a_list
                   if condition(item)]

    Listcomps are clear & concise, up to a point.  You can have multiple
    ``for``-loops and ``if``-conditions in a listcomp, but beyond two or three
    total, or if the conditions are complex, I suggest that regular ``for``
    loops should be used.  Applying the Zen of Python, choose the more readable
    way.::

       For example, a list of the squares of 0–9:

       >>> [n ** 2 for n in range(10)]
       [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

       A list of the squares of odd 0–9:

       >>> [n ** 2 for n in range(10) if n % 2]
       [1, 9, 25, 49, 81]

#) **What is the difference between list comprehension and generator expression?**

    Generator expressions ("genexps") are just like list comprehensions, except
    that where listcomps are greedy, generator expressions are lazy.  Listcomps
    compute the entire result list all at once, as a list.  Generator
    expressions compute one value at a time, when needed, as individual values.
    This is especially useful for long sequences where the computed list is
    just an intermediate step and not the final result.

    For example, if we were summing the squares of several billion integers,
    we'd run out of memory with list comprehensions, but generator expressions
    have no problem.  This does take time, though!  

    ::
       total = sum(num * num
                   for num in xrange(1, 1000000000))

    The difference in syntax is that listcomps have square brackets, but
    generator expressions don't.  Generator expressions sometimes do not
    require enclosing parentheses though, so you should always use them.

    Rule of thumb

    * Use a list comprehension when a computed list is the desired end result.
    * Use a generator expression when the computed list is just an intermediate step.


#) **How Generators are different from Generator Expressions?**

    We've already seen generator expressions.  We can devise our own
    arbitrarily complex generators, as functions: ::

        def my_range_generator(stop):
            value = 0
            while value < stop:
                yield value
                value += 1

        for i in my_range_generator(10):
            do_something(i)

    The ``yield`` keyword turns a function into a generator.  When you call a
    generator function, instead of running the code immediately Python returns
    a generator object, which is an iterator; it has a ``next`` method.
    ``for`` loops just call the ``next`` method on the iterator, until a
    ``StopIteration`` exception is raised.  You can raise ``StopIteration``
    explicitly, or implicitly by falling off the end of the generator code as
    above.

    Generators can simplify sequence/iterator handling, because we don't need
    to build concrete lists; just compute one value at a time.  The generator
    function maintains state.

    This is how a ``for`` loop really works.  Python looks at the sequence
    supplied after the ``in`` keyword.  If it's a simple container (such as a
    list, tuple, dictionary, set, or user-defined container) Python converts it
    into an iterator.  If it's already an iterator, Python uses it directly.

    Then Python repeatedly calls the iterator's ``next`` method, assigns the
    return value to the loop counter (``i`` in this case), and executes the
    indented code.  This is repeated over and over, until ``StopIteration`` is
    raised, or a ``break`` statement is executed in the code.

    A ``for`` loop can have an ``else`` clause, whose code is executed after
    the iterator runs dry, but **not** after a ``break`` statement is executed.
    This distinction allows for some elegant uses.  ``else`` clauses are not
    always or often used on ``for`` loops, but they can come in handy.
    Sometimes an ``else`` clause perfectly expresses the logic you need.

    For example, if we need to check that a condition holds on some item, any
    item, in a sequence::

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


#) **Sorting a list in Python?**

    ::

        a_list.sort()

    sort methods on a  list sorts it in-place. That is the original list is
    sorted, and the ``sort`` method does **not** return the list or a copy. But
    what if you have a list of data that you need to sort, but it doesn't sort
    naturally (i.e., sort on the length of strings)? ``sort`` method has an
    optional argument called "key", which specifies a function of one argument
    that is used to compute a comparison key from each list element.For example::

       def my_key(item):
           return (item[1], item[3])

       to_sort.sort(key=my_key)

    The function ``my_key`` will be called once for each item in the
    ``to_sort`` list. You can make your own key function, or use any existing
    one-argument function if applicable:

   * ``str.lower`` to sort alphabetically regardless of case.
   * ``len`` to sort on the length of the items (strings or containers).
   * ``int`` or ``float`` to sort numerically, as with numeric strings
     like "2", "123", "35".

#) **What are the various different ways to import modules in Python?**

    There is a wildcard ``*`` style module importing::

        from module import *

    The ``from module import *`` wild-card style leads to namespace pollution.
    You'll get things in your local namespace that you didn't expect to get.
    You may see imported names obscuring module-defined local names.  You won't
    be able to figure out where certain names come from.  Although a convenient
    shortcut, this should not be in production code.

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

#) **How to make a Python module work as a script?**

    To make a simultaneously importable module and executable script::

        if __name__ == '__main__':
            # script code here

    When imported, a module's ``__name__`` attribute is set to the module's
    file name, without ".py".  So the code guarded by the ``if`` statement
    above will not run when imported.  When executed as a script though, the
    ``__name__`` attribute is set to "__main__", and the script code *will*
    run. Except for special cases, you shouldn't put any major executable code
    at the top-level.  Put code in functions, classes, methods, and guard it
    with ``if __name__ == '__main__'``.

#) **What is a good way to structure the python programs or modules and packages?**

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

#) **How would you transpose a Matrix in Python?**

    ::
            mat = [[1,2,3],
                   [4,5,6],
                   [7,8,9]
                   ]

    If we want to transpose the about matrix, that is change the rows into
    columns and columns into rows, the result will be::

        result = [[1,4,7],
                  [2,5,8],
                  [3,6,9]
                  ]

    Answer Is::

        >>>zip(*mat)

#) **How would you write unicode strings in Python2?**

    * Python2 supports Unicode by a special kind of string, called the Unicode
      object.  `>>> u'Hello World !'`
    * You can have unicode by using the special python escape encoding: `>>> u'Hello\u0020World !'`
    * built-in function unicode() , default encoding is ASCII
    * To convert unicode to a 8-bit bytes using a specified encoding::

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

#) **How does else conditions on loops work in Python?**

    Loop statements in Python may have an else clause. It is executed when the
    loop terminates through exhaustion of the list (with for).  Or when the
    condition becomes false (with while), But not when the loop is terminated
    by a break statement::

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

#) **How does a function execution control flows in Python?**

    The execution of a function introduces a new symbol table used for the
    local variables of the function. More precisely, all variable assignments
    in a function store the value in the local symbol table; whereas variable
    references first look in the local symbol table, then in the local symbol
    tables of enclosing functions, then in the global symbol table, and finally
    in the table of built-in names. Thus, global variables cannot be directly
    assigned a value within a function (unless named in a global statement),
    although they may be referenced.

    The actual parameters (arguments) to a function call are introduced in the
    local symbol table of the called function when it is called; thus,
    arguments are passed using call by value (where the value is always an
    object reference, not the value of the object). When a function calls
    another function, a new local symbol table is created for that call.

    A function definition introduces the function name in the current symbol
    table.  The value of the function name has a type that is recognized by the
    interpreter as a user-defined function. This value can be assigned to
    another name which can then also be used as a function.

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

    First one will print 5, because default values are evaluated at the point
    of function definition in the defining scope. The default value is
    evaluated only once. This makes a difference when the default value is a
    mutatable object. In order to prevent argument sharing.::

          def f(a, L=None):
            if L is None:
                L = []
            L.append(a)
            return L


#) **What are the different functional programming tools available in Python?**

    There are three built-in functions that are very useful when used with
    lists: filter(), map() and reduce()

        * filter(function, sequence) - Takes the elements of the sequence and
          filters them with the condition specified in the function.
        * map(function, sequence) - sends each element to the function and
          returns the result.More than one sequence may be passed; the function
          must then have as many arguments as there are sequences and is called
          with the corresponding item from each sequence. 
        * reduce(function, sequence) -  function in reduce is a binary
          function::

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

#) **How do you handle Exceptions in Python2?**

    A try statement may have more than one except clause, to specify handlers
    for different exceptions::

          ... except (RuntimeError, TypeError, NameError):

          ...     pass

    The last except clause may omit the exception name(s), to serve as a
    wildcard.  Use this with extreme caution, since it is easy to mask a real
    programming error in this way! It can also be used to print an error
    message and then re-raise the exception (allowing a caller to handle the
    exception as well)

    The try ... except statement has an optional else clause, executed when the
    try clause does not raise an exception.::

        for arg in sys.argv[1:]:
            try:
                f = open(arg, 'r')
            except IOError:
                print 'cannot open', arg
            else:
                print arg, 'has', len(f.readlines()), 'lines'
                f.close()


    A finally clause is available to handle cleaup actions in Python.  A
    finally clause is always executed before leaving the try statement, whether
    an exception has occurred or not. In real world applications, the finally
    clause is useful for releasing external resources (such as files or network
    connections), regardless of whether the use of the resource was successful.

#) **What is a with statement in Python?**

    Some objects define standard clean-up actions to be undertaken when the
    object is no longer needed, regardless of whether or not the operation
    using the object succeeded or failed::

        with open("myfile.txt") as f:
            for line in f:
                print line

    After the statement is executed, the file f is always closed, even if a
    problem was encountered while processing the lines. 

#) **How does Python class statement works?**

    When a class definition is entered, a new namespace is created, and used as
    the local scope and thus, all assignments to local variables go into this
    new namespace. In particular, function definitions bind the name of the new
    function here. When a class definition is left normally, a class object is
    created. This is basically a wrapper around the contents of the namespace
    created by the class definition;The original local scope (the one in effect
    just before the class definition was entered) is reinstated, and the class
    object is bound here to the class name given in the class definition header

    In C++ terminology, all class members (including the data members) are
    public, and all member functions are virtual. There are no special
    constructors or destructors.  Python Scopes and Namespaces A namespace is a
    mapping from names to objects.  Most namespaces are currently implemented
    as Python dictionaries.

    Class Objects support attribute notation and instantiation.  Class
    instantiation creates instance objects. Instance Objects supports attribute
    references, which are of two kinds data attributes and methods.

    Old style classes support Inheritance in depth first, left to right.  New
    style classes to support super(), it follows a diamond inheritance.

#) **Explain Classmethods, Staticmethods and Decorators in Python.**

    In Object Oriented Programming, you can create a method which can get
    associated either with a class or with an instance of the class, namely an
    object. 

    And most often in our regular practice, we always create methods to be
    associated with an object. Those are called instance methods.For e.g::

        class Car:
                def cartype(self):
                        self.model = "Audi"

        mycar = Car()
        mycar.cartype()
        print mycar.model

    Here cartype() is an instance method, it associates itself with an instance
    (mycar) of the class (Car) and that is defined by the first argument
    ('self'). When you want a method not to be associated with an instance, you
    call that as a staticmethod.

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


#) **Explain the terms methods, staticmethods and classmethods in terms of general programming principles.**

    In object-oriented programming, a method is a subroutine that is
    exclusively associated either with a class (called class methods or static
    methods) or with an object (called instance methods). Like a procedure in
    procedural programming languages, a method usually consists of a sequence
    of statements to perform an action, a set of input parameters to customize
    those actions, and possibly an output value (called the return value) of
    some kind. Methods can provide a mechanism for accessing (for both reading
    and writing) the encapsulated data stored in an object or a class.

    Instance methods are associated with a particular object, while class or
    static methods are associated with a class. In all typical implementations,
    instance methods are passed a hidden reference (e.g. this, self or Me) to
    the object (whether a class or class instance) they belong to, so that they
    can access the data associated with it. 

    For class/static methods this may or may not happen according to the
    language; A typical example of a class method would be one that keeps count
    of the number of created objects within a given class.

    A method may be declared as static, meaning that it acts at the class level
    rather than at the instance level. Therefore, a static method cannot refer
    to a specific instance of the class (i.e. it cannot refer to this, self,
    Me, etc.), unless such references are made through a parameter referencing
    an instance of the class, although in such cases they must be accessed
    through the parameter's identifier instead of this. An example of a static
    member and its consumption in C# code.::

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

    Python method can create an instance of Dict or of any subclass of it,
    because it receives a reference to a class object as cls.::

        class Dict:
            @classmethod
                def fromkeys(cls, iterable, value=None):
                   d = cls()
                   for key in iterable:
                       d[key] = value
                   return d

    A class method receives the class it was called on as the first argument.
    This can be useful with subclasses. A staticmethod doesn't get a class or
    instance argument. It is just a way to put a plain function into the scope
    of a class.  In the wider world of OOP they are two names for the same
    concept.  Smalltalk and Lisp etc used the term "class method" to mean a
    method that applied to the class as a whole.

    C++ introduced the term "static method" to reflect the fact that it was
    loaded in the static area of memory and thus could be called without
    instantiating an object. This meant it could effectively be used as a class
    method.

    In C it is possible to prefix a normal function definition with the word
    static to get the compiler to load the function into static memory - this
    often gives a performance improvement.

    Python started off implementing "static methods" then later developed the
    sligtly more powerful and flexible "class methods" and rather than lose
    backward compatibility called them classmethod.  So in Python we have two
    ways of doing more or less the same (conceptual) thing.

    http://code.activestate.com/recipes/52304/ the recipe here shows a way to
    make a function within a class as callable by using wrapping techniques.
    This was later generalized to staticmethods.

    Conceptually they are both ways of defining a method that applies at the
    class level and could be used to implement class wide behavior. Thats what
    I mean. If you want to build a method to determine how many instances are
    active at any time then you could use either a staticmethod or a
    classmethod to do it. Most languages only give you one way. Python, despite
    its mantra, actually gives 2 ways to do it in this case.

#) **What is the difference between process and a thread?**

    Both threads and processes are methods of parallelizing an application.
    However, processes are independent execution units that contain their own
    state information, use their own address spaces, and only interact with
    each other via interprocess communication mechanisms (generally managed by
    the operating system). Applications are typically divided into processes
    during the design phase, and a master process explicitly spawns
    sub-processes when it makes sense to logically separate significant
    application functionality. Processes, in other words, are an architectural
    construct.

    By contrast, a thread is a coding construct that doesn't affect the
    architecture of an application. A single process might contains multiple
    threads; all threads within a process share the same state and same memory
    space, and can communicate with each other directly, because they share the
    same variables.

    Threads typically are spawned for a short-term benefit that is usually
    visualized as a serial task, but which doesn't have to be performed in a
    linear manner (such as performing a complex mathematical computation using
    parallelism, or initializing a large matrix), and then are absorbed when no
    longer required. The scope of a thread is within a specific code
    module—which is why we can bolt-on threading without affecting the broader
    application.

    Multithreading computers have hardware support to efficiently execute
    multiple threads.  Threads of program results from fork of a computer
    program into two or more concurrently running tasks.  In multi-threading
    the threads have to share a single core,cache and TLB unlike the
    multiprocessing machines.

    *Some History of Inter Process Communication*

    By the early 60s computer control software had evolved from Monitor control
    software, e.g., IBSYS, to Executive control software. Computers got
    "faster" and computer time was still neither "cheap" nor fully used. It
    made multiprogramming possible and necessary.

    Multiprogramming means that several programs run "at the same time"
    (concurrently). At first they ran on a single processor (i.e.,
    uniprocessor) and shared scarce resources. Multiprogramming is also basic
    form of multiprocessing, a much broader term.

    Programs consist of sequence of instruction for processor. Single processor
    can run only one instruction at a time. Therefore it is impossible to run
    more programs at the same time. Program might need some resource (input
    ...) which has "big" delay. Program might start some slow operation (output
    to printer ...). This all leads to processor being "idle" (unused). To use
    processor at all time the execution of such program was halted. At that
    point, a second (or nth) program was started or restarted. User perceived
    that programs run "at the same time" (hence the term, concurrent).

    Shortly thereafter, the notion of a 'program' was expanded to the notion of
    an 'executing program and its context'. The concept of a process was born.

    This became necessary with the invention of re-entrant code.  Threads came
    somewhat later. However, with the advent of time-sharing; computer
    networks; multiple-CPU, shared memory computers; etc., the old
    "multiprogramming" gave way to true multitasking, multiprocessing and,
    later, multithreading.

#) **What are Coroutines?**

    Coroutines are subroutines that allow multiple entry points for suspending
    and resuming execution at certain locations.  Subroutine are subprograms,
    methods, functions for performing a subtask and it is relatively
    independent of other task.  Coroutines are useful for implementing
    cooperative tasks, iterators, infinite lists and pipes.  Cooperative Tasks
    Similar programs, CPU is yielded to each program coperatively.  Iterators
    of an object that allows the programmer to traverse all the elements of a
    collection.  Lazy Evaluation is the technique for delaying the computation
    till the result is required. Why Infite Lists and Lazy evaluation are given
    together?  Coroutines in which subsequent calls can be yield more results
    are called as generators.  Subroutines are implemented using stacks and
    coroutines are implemented using continuations.  continuation are an
    abstract representation of a control state, or the rest of the computation,
    or rest of the code to be executed.

#) **What is a Global Interpreter Lock?**

    The GIL is a single lock inside of the Python interpreter, which
    effectively prevents multiple threads from being executed in parallel, even
    on multi-core or multi-CPU systems!

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

#) **How do you specify and enforce an interface spec in Python?**

    An interface specification for a module as provided by languages such as
    C++ and Java describes the prototypes for the methods and functions of the
    module.  Many feel that compile-time enforcement of interface
    specifications helps in the construction of large programs. In Java World,
    interfaces form the contract between the class and the outside world, and
    this contract is enforced at the build time by the compiler.

    Python 2.6 adds an abc module that lets you define Abstract Base Classes
    (ABC).  You can then use isinstance() and issubclass to check whether an
    instance or a class implements a particular ABC. The collections modules
    defines a set of useful ABC s such as Iterable, Container, and
    Mutablemapping.

    For Python, many of the advantages of interface specifications can be
    obtained by an appropriate test discipline for components. There is also a
    tool, PyChecker, which can be used to find problems due to subclassing.

    A good test suite for a module can both provide a regression test and serve
    as a module interface specification and a set of examples. Many Python
    modules can be run as a script to provide a simple "self test." Even
    modules which use complex external interfaces can often be tested in
    isolation using trivial "stub" emulations of the external interface. The
    doctest and unittest modules or third-party test frameworks can be used to
    construct exhaustive test suites that exercise every line of code in a
    module.

    An appropriate testing discipline can help build large complex applications
    in Python as well as having interface specifications would. In fact, it can
    be better because an interface specification cannot test certain properties
    of a program. For example, the append() method is expected to add new
    elements to the end of some internal list; an interface specification
    cannot test that your append() implementation will actually do this
    correctly, but it's trivial to check this property in a test suite.

    Writing test suites is very helpful, and you might want to design your code
    with an eye to making it easily tested. One increasingly popular technique,
    test-directed development, calls for writing parts of the test suite first,
    before you write any of the actual code. Of course Python allows you to be
    sloppy and not write test cases at all.

#) **What is the difference between string, bytes and buffer from Python2 and Python3 perspective?**

    In Python 2.0, the normal strings were of 8 bit characters and for
    representing Characters from foreign languages, a special kind of class was
    provided, which was called Unicode String.

    The string object when they had to be stored or transfered over the wire,
    they had to be encoded into bytes. As normal string character was 8 bits,
    they directly corresponded to one byte and Python2.0 had an implicit ascii
    encoding which conveniently encoded them to 8-bit bytes.  The Unicode
    object had to have an encoding specified, which encoded the unicoded
    strings into sequence of bytes.

    Just as string object had an encode method, to convert to bytes, the bytes
    object had a decode method, that takes a character encoding an returns a
    string.

    In Python 3.0, the normal string was made the Unicode String. However, the
    8bit character datatype was still retained and it was called as bytes.

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

#) **What is the bytearray class in Python3?**

   A Byte is 8 bits and array is a sequence. A Bytearray object can be
   constructed using integers only or text string along with an encoding or
   using another bytes or bytearray or any other object implementing a buffer
   API. More importantly, it is mutable.


#) **How to do convert int to hex in Python?**

    Q:Convert a Hexadecimal Strings ("FF","FFFF") to Decimal
    A: int("FF",16) and int("FFFF",16)

    Q: Represent 255 in Hexadecimal.
    A: print '%X' % 255

    If you want to encode a string in base16, base32 or base64 encoding, the python
    standard library provides base64 module which is based on the RFC 3564.

#) **What are the different XML parsers in Python?**

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

    Now, if I were to structure an html document as a element tree.
    
    ::

                    <html>
                      |
                    <head> ----------
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

#) **What is a factory method design pattern?**

    Factory method design pattern is used quite often in Python. It is a
    creational pattern, dealing with creation of objects (products) without
    specifying the exact class. The creational patterns abstract the concept of
    instantiating objects and it handles this case by defining a separate
    method for creation objects. The subclasses of that method or object can
    override to specify the derived type of the product that will be created.
    Factory method is used to refer to any method whose main purpose is to
    create objects. 

    The Factory pattern in c++ wraps the usual object creation syntax new
    someclass() in a function or a method which can control the creation.
    Advantages is that, code using the class no longer needs to know all the
    details of creation. It may not even know the exact type of object created.

    Abstract Factory provides additional indirection to let the type of object
    which is created to vary.

    Factory pattern is fundamental in python; while languages like C++ use
    ClassName class; to create classes python uses function class syntax to
    create objects. Even builtin types str, int provide factory pattern.

#) **How does the simplejson.dumps useful in webapps?**

    json


#) **Explain Lazy Import.**

    http://peak.telecommunity.com/DevCenter/Importing

#) **dispatch**

  """Multiple/Predicate Dispatch Framework                                                                                                
                                                                                                                                          
    This framework refines the algorithms of Chambers and Chen in their 1999
    paper, "Efficient Multiple and Predicate Dispatching", to make them suitable
    for Python, while adding a few other enhancements like incremental index
    building and lazy expansion of the dispatch DAG.   Also, their algorithm was
    designed only for class selection and true/false tests, while this framework
    can be used with any kind of test, such as numeric ranges, or custom tests such
    as categorization/hierarchy membership.                                                                                     


#) **Metaclassing**

    I saw an example like this. ::

        import attr

        class MetaInterface(type): 
            """Interface meta class."""

        class Interface(object): 
            """Interface base class."""
             __metaclass__ = MetaInterface 

    I am not sure of it's utility.

#) How to use static class variable in Python?

    http://stackoverflow.com/questions/68645/static-class-variables-in-python

#) What would filter(None, iterable) would return?
   
    It would return only the elements from the iterable which are true.

#) How is OrderedDict implemented in Python?

   It maintains a doubly-linked list of keys, appending new keys to the list as
   they’re inserted. A secondary dictionary maps keys to their corresponding
   list node, so deletion doesn’t have to traverse the entire linked list and
   therefore remains O(1).

#) Include this is 3.3

    http://pypi.python.org/pypi/MultipartPostHandler/0.1.0

#) How to make Python's standard output non-buffered?

    sys.stdout = os.fdopen(sys.stdout.fileno(), 'a', 0)                                                                                     


#) What is the purpose of Zope Interfaces?


    You can actually test if your object or class implements your interface. For
    that you can use verify module (you would normally use it in your tests).

    ::


        >>> from zope.interface import Interface, Attribute, implements
        >>> class IFoo(Interface):
        ...     x = Attribute("The X attribute")
        ...     y = Attribute("The Y attribute")

        >>> class Foo(object):
        ...     implements(IFoo)
        ...     x = 1
        ...     def __init__(self):
        ...         self.y = 2

        >>> from zope.interface.verify import verifyObject
        >>> verifyObject(IFoo, Foo())
        True

        >>> from zope.interface.verify import verifyClass
        >>> verifyClass(IFoo, Foo)
        True

#) Write about Lazy Evaluation the process as described in PEAK.


    "In other words, the typical Python class library is *not* a "component". It is
    not configurable and composable with other components because it is a single
    instance, and its connection points are hidden, rather than exposed."

    The difference between an object and a component is component takes
    configuration and is composable out of other components.


    PEAK

    PEAK is the "Python Enterprise Application Kit". If you develop "enterprise"
    applications with Python, or indeed almost any sort of application with Python,
    PEAK may help you do it faster, easier, on a larger scale, and with fewer
    defects than ever before. The key is component-based development, on a reliable
    infrastructure.

    PEAK is an application kit, and applications are made from components. PEAK
    provides you with a component architecture, component infrastructure, and
    various general-purpose components and component frameworks for building
    applications. As with J2EE, the idea is to let you stop reinventing
    architectural and infrastructure wheels, so you can put more time into your
    actual application.

    But PEAK is different from J2EE: it's a single, free implementation of simpler
    API's based on an easier-to-use language that can nonetheless scale with better
    performance than J2EE.


#) What is Inversion of Control?

    http://stackoverflow.com/questions/3058/what-is-inversion-of-control

    Inversion of Control is what you get when you program callbacks, e.g. like a
    gui program.

    For example, in an old school menu, you might have:

    print "enter your name"
    read name
    print "enter your address"
    read address
    etc...
    store in database

    thereby controlling the flow of user interaction.

    In a GUI program or somesuch, instead we say

    when the user types in field a, store it in NAME
    when the user types in field b, store it in ADDRESS
    when the user clicks the save button, call StoreInDatabase

    So now control is inverted... instead of the computer accepting user input in a
    fixed order, the user controls the order in which the data is entered, and when
    the data is saved in the database.

    Basically, anything with an event loop, callbacks, or execute triggers falls
    into this category.

    Other articles on Dependency Injection and Inversion of Control include

    http://code.google.com/p/snake-guice/

    http://www.voidspace.org.uk/python/articles/introduction-to-unittest.shtml#dependency-injection

    http://code.activestate.com/recipes/413268-dependency-injection-the-python-way/

    http://pypi.python.org/pypi/mext.context

    http://en.wikipedia.org/wiki/Dependency_inversion_principle


#) What is the mechanism to distribute Python packages?

    distutils was the mechanism to distribute python packages and extensions
    since Python 1.6.  Introduced new version control comparision algorithm in
    distutil.  PEP-376 standardize the egg-info directories and provide APIs
    PEP-345 PKG-INFO content.

    Refer to http://distutils2.notmyidea.org/

#) In Python3, Dict returns a view object. What is that?

   Dict views are nothing by a internal state of the list. As sometimes called
   Window or view of the list.  It is not returning lists because creating list
   could be a costly operation and you most often use dict.keys and dict.values
   to just look at them. So creating a view object was sufficient. 

   This concept was borrowed from Java's implementation of views.

#) What is the difference between linefeed and a newline?

    newline is composed of Linefeed character. 

#) What is metaclass attributes?

#) What are class properties?

#) Where do we use ellipses in Python?

#) Why cannot a python package be imported like -m flag.

#) Python Memory Model

   During a Python program execution, the stack is utilized. Stack pushes grow
   upward. 1 Python stack frame == 1 C stack frame. Memory problems occur when
   stack meets the heap.

#) What is meant by interning objects in Python?


Links
=====

* Python Tutorial
  
  http://people.csail.mit.edu/pgbovine/python/

* "Python Objects", Fredrik Lundh,
  http://www.effbot.org/zone/python-objects.htm

* "Sorting Mini-HOWTO", Andrew Dalke,
  http://wiki.python.org/moin/HowTo/Sorting

* Python performance improvements

  http://www.huyng.com/posts/python-performance-analysis/
