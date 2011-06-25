Interesting Modules that ease our tasks
=======================================

Collections module
------------------

collections module provides a high performance container datatype.

Collections module implements high-performance container datatypes.  Currently,
there are four datatypes, :class:`Counter`, :class:`deque`, :class:`OrderedDict` and
:class:`defaultdict`, and one datatype factory function, :func:`namedtuple`.

The specialized containers provided in this module provide alternatives
to Python's general purpose built-in containers, :class:`dict`,
:class:`list`, :class:`set`, and :class:`tuple`.

In addition to containers, the collections module provides some ABCs
(abstract base classes) that can be used to test whether a class
provides a particular interface, for example, whether it is hashable or
a mapping.

A counter tool is provided to support convenient and rapid tallies.
For example::

    >>> # Tally occurrences of words in a list
    >>> cnt = Counter()
    >>> for word in ['red', 'blue', 'red', 'green', 'blue', 'blue']:
    ...     cnt[word] += 1
    >>> cnt
    Counter({'blue': 3, 'red': 2, 'green': 1})

    >>> # Find the ten most common words in Hamlet
    >>> import re
    >>> words = re.findall('\w+', open('hamlet.txt').read().lower())
    >>> Counter(words).most_common(10)
    [('the', 1143), ('and', 966), ('to', 762), ('of', 669), ('i', 631),
     ('you', 554),  ('a', 546), ('my', 514), ('hamlet', 471), ('in', 451)]


deque([iterable[, maxlen]])

   Returns a new deque object initialized left-to-right (using :meth:`append`) with
   data from *iterable*.  If *iterable* is not specified, the new deque is empty.

   Deques are a generalization of stacks and queues (the name is pronounced "deck"
   and is short for "double-ended queue").  Deques support thread-safe, memory
   efficient appends and pops from either side of the deque with approximately the
   same O(1) performance in either direction.

   Though :class:`list` objects support similar operations, they are optimized for
   fast fixed-length operations and incur O(n) memory movement costs for
   ``pop(0)`` and ``insert(0, v)`` operations which change both the size and
   position of the underlying data representation.

   .. versionadded:: 2.4

   If *maxlen* is not specified or is *None*, deques may grow to an
   arbitrary length.  Otherwise, the deque is bounded to the specified maximum
   length.  Once a bounded length deque is full, when new items are added, a
   corresponding number of items are discarded from the opposite end.  Bounded
   length deques provide functionality similar to the ``tail`` filter in
   Unix. They are also useful for tracking transactions and other pools of data
   where only the most recent activity is of interest.::

    def moving_average(iterable, n=3):
        # moving_average([40, 30, 50, 46, 39, 44]) --> 40.0 42.0 45.0 43.0
        # http://en.wikipedia.org/wiki/Moving_average
        it = iter(iterable)
        d = deque(itertools.islice(it, n-1))
        d.appendleft(0)
        s = sum(d)
        for elem in it:
            s += elem - d.popleft()
            d.append(elem)
            yield s / float(n)

Default Dict
------------

ing :class:`list` as the :attr:`default_factory`, it is easy to group a
sequence of key-value pairs into a dictionary of lists::

   >>> s = [('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]
   >>> d = defaultdict(list)
   >>> for k, v in s:
   ...     d[k].append(v)
   ...
   >>> d.items()
   [('blue', [2, 4]), ('red', [1]), ('yellow', [1, 3])]


Namedtuple
----------

imed tuples assign meaning to each position in a tuple and allow for more readable,
self-documenting code.  They can be used wherever regular tuples are used, and
they add the ability to access fields by name instead of position index.
tertools module::

>>> from collections import namedtuple
>>> Point = namedtuple('Point', 'x y', verbose=True)


Ordered Dictionary
------------------

Ordered dictionaries are just like regular dictionaries but they remember the
order that items were inserted.  When iterating over an ordered dictionary,
the items are returned in the order their keys were first added.

itertools
---------

The :mod:`itertools` module contains a number of commonly-used iterators as well
as functions for combining several iterators.  This section will introduce the
module's contents by showing small examples.

The module's functions fall into a few broad classes:

* Functions that create a new iterator based on an existing iterator.
* Functions for treating an iterator's elements as function arguments.
* Functions for selecting portions of an iterator's output.
* A function for grouping an iterator's output.

Creating new iterators
----------------------

``itertools.count(n)`` returns an infinite stream of integers, increasing by 1
each time.  You can optionally supply the starting number, which defaults to 0::

    itertools.count() =>
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ...
    itertools.count(10) =>
      10, 11, 12, 13, 14, 15, 16, 17, 18, 19, ...

``itertools.cycle(iter)`` saves a copy of the contents of a provided iterable
and returns a new iterator that returns its elements from first to last.  The
new iterator will repeat these elements infinitely. ::

    itertools.cycle([1,2,3,4,5]) =>
      1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...

``itertools.repeat(elem, [n])`` returns the provided element ``n`` times, or
returns the element endlessly if ``n`` is not provided. ::

    itertools.repeat('abc') =>
      abc, abc, abc, abc, abc, abc, abc, abc, abc, abc, ...
    itertools.repeat('abc', 5) =>
      abc, abc, abc, abc, abc

``itertools.chain(iterA, iterB, ...)`` takes an arbitrary number of iterables as
input, and returns all the elements of the first iterator, then all the elements
of the second, and so on, until all of the iterables have been exhausted. ::

    itertools.chain(['a', 'b', 'c'], (1, 2, 3)) =>
      a, b, c, 1, 2, 3

``itertools.izip(iterA, iterB, ...)`` takes one element from each iterable and
returns them in a tuple::

    itertools.izip(['a', 'b', 'c'], (1, 2, 3)) =>
      ('a', 1), ('b', 2), ('c', 3)

It's similar to the built-in :func:`zip` function, but doesn't construct an
in-memory list and exhaust all the input iterators before returning; instead
tuples are constructed and returned only if they're requested.  (The technical
term for this behaviour is `lazy evaluation
<http://en.wikipedia.org/wiki/Lazy_evaluation>`__.)

This iterator is intended to be used with iterables that are all of the same
length.  If the iterables are of different lengths, the resulting stream will be
the same length as the shortest iterable. ::

    itertools.izip(['a', 'b'], (1, 2, 3)) =>
      ('a', 1), ('b', 2)

You should avoid doing this, though, because an element may be taken from the
longer iterators and discarded.  This means you can't go on to use the iterators
further because you risk skipping a discarded element.

``itertools.islice(iter, [start], stop, [step])`` returns a stream that's a
slice of the iterator.  With a single ``stop`` argument, it will return the
first ``stop`` elements.  If you supply a starting index, you'll get
``stop-start`` elements, and if you supply a value for ``step``, elements will
be skipped accordingly.  Unlike Python's string and list slicing, you can't use
negative values for ``start``, ``stop``, or ``step``. ::

    itertools.islice(range(10), 8) =>
      0, 1, 2, 3, 4, 5, 6, 7
    itertools.islice(range(10), 2, 8) =>
      2, 3, 4, 5, 6, 7
    itertools.islice(range(10), 2, 8, 2) =>
      2, 4, 6

``itertools.tee(iter, [n])`` replicates an iterator; it returns ``n``
independent iterators that will all return the contents of the source iterator.
If you don't supply a value for ``n``, the default is 2.  Replicating iterators
requires saving some of the contents of the source iterator, so this can consume
significant memory if the iterator is large and one of the new iterators is
consumed more than the others. ::

        itertools.tee( itertools.count() ) =>
           iterA, iterB

        where iterA ->
           0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ...

        and   iterB ->
           0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ...
  


Calling functions on elements
-----------------------------

Two functions are used for calling other functions on the contents of an
iterable.

``itertools.imap(f, iterA, iterB, ...)`` returns a stream containing
``f(iterA[0], iterB[0]), f(iterA[1], iterB[1]), f(iterA[2], iterB[2]), ...``::

    itertools.imap(operator.add, [5, 6, 5], [1, 2, 3]) =>
      6, 8, 8

The ``operator`` module contains a set of functions corresponding to Python's
operators.  Some examples are ``operator.add(a, b)`` (adds two values),
``operator.ne(a, b)`` (same as ``a!=b``), and ``operator.attrgetter('id')``
(returns a callable that fetches the ``"id"`` attribute).

``itertools.starmap(func, iter)`` assumes that the iterable will return a stream
of tuples, and calls ``f()`` using these tuples as the arguments::

    itertools.starmap(os.path.join,
                      [('/usr', 'bin', 'java'), ('/bin', 'python'),
                       ('/usr', 'bin', 'perl'),('/usr', 'bin', 'ruby')])
    =>
      /usr/bin/java, /bin/python, /usr/bin/perl, /usr/bin/ruby


Selecting elements
------------------

Another group of functions chooses a subset of an iterator's elements based on a
predicate.

``itertools.ifilter(predicate, iter)`` returns all the elements for which the
predicate returns true::

    def is_even(x):
        return (x % 2) == 0

    itertools.ifilter(is_even, itertools.count()) =>
      0, 2, 4, 6, 8, 10, 12, 14, ...

``itertools.ifilterfalse(predicate, iter)`` is the opposite, returning all
elements for which the predicate returns false::

    itertools.ifilterfalse(is_even, itertools.count()) =>
      1, 3, 5, 7, 9, 11, 13, 15, ...

``itertools.takewhile(predicate, iter)`` returns elements for as long as the
predicate returns true.  Once the predicate returns false, the iterator will
signal the end of its results.

::

    def less_than_10(x):
        return (x < 10)

    itertools.takewhile(less_than_10, itertools.count()) =>
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9

    itertools.takewhile(is_even, itertools.count()) =>
      0

``itertools.dropwhile(predicate, iter)`` discards elements while the predicate
returns true, and then returns the rest of the iterable's results.

::

    itertools.dropwhile(less_than_10, itertools.count()) =>
      10, 11, 12, 13, 14, 15, 16, 17, 18, 19, ...

    itertools.dropwhile(is_even, itertools.count()) =>
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ...


Grouping elements
-----------------

The last function I'll discuss, ``itertools.groupby(iter, key_func=None)``, is
the most complicated.  ``key_func(elem)`` is a function that can compute a key
value for each element returned by the iterable.  If you don't supply a key
function, the key is simply each element itself.

``groupby()`` collects all the consecutive elements from the underlying iterable
that have the same key value, and returns a stream of 2-tuples containing a key
value and an iterator for the elements with that key.

::

    city_list = [('Decatur', 'AL'), ('Huntsville', 'AL'), ('Selma', 'AL'),
                 ('Anchorage', 'AK'), ('Nome', 'AK'),
                 ('Flagstaff', 'AZ'), ('Phoenix', 'AZ'), ('Tucson', 'AZ'),
                 ...
                ]

    def get_state ((city, state)):
        return state

    itertools.groupby(city_list, get_state) =>
      ('AL', iterator-1),
      ('AK', iterator-2),
      ('AZ', iterator-3), ...

    where
    iterator-1 =>
      ('Decatur', 'AL'), ('Huntsville', 'AL'), ('Selma', 'AL')
    iterator-2 =>
      ('Anchorage', 'AK'), ('Nome', 'AK')
    iterator-3 =>
      ('Flagstaff', 'AZ'), ('Phoenix', 'AZ'), ('Tucson', 'AZ')

``groupby()`` assumes that the underlying iterable's contents will already be
sorted based on the key.  Note that the returned iterators also use the
underlying iterable, so you have to consume the results of iterator-1 before
requesting iterator-2 and its corresponding key.

