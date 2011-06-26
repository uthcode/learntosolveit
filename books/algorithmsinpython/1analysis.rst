################
Basic Algorithms
################


******************
Algorithm Analysis
******************

Basic Idea
==========

Algorithm is a series of steps for solving a specified computational problem.
The computational problem describes the desired input/output relationship and
algorithm orovides the steps to acheive that desired relationship.

Example
=======

Finding the largest number in a list.

**Problem**

Given a series of numbers find the largest number in the series.

**Solution**

1. Consider the first number as the largest.
2. Take the second number, compare if it is larger than the first number, if yes, store it as largest otherwise move to the next number.
3. Repeat step 2 till the series is exhausted.

**Example Run**

Find the largest number is - 53, 2, 5, 90, 1, 99, 10

1. Let 53 be the largest and store it is *largestnum*.
2. Take 2, 2 is lesser than 53. Keep 53.
3. Take 5, 5 is lesser than 53. Keep 53.
4. Take 90, 90 is **greater** than 54. Store 90 as *largestnum*.
5. Take 1, 1 is lesser than 90. Keep 90.
6. Take 99, 99 is **greater** than 90. Store 99 as *largestnum*.
7. Take 10, 10 is lesser than 99. Keep 99.
8. Series is exhausted.

The largest is available in *largestnum* which is 99.

Iterative formulation
---------------------

.. literalinclude:: source/1analysis-1.py

Recursive formulation
---------------------


Measuring time Complexity
=========================

In mathematics we come across the concept of measuing a complex function in
terms of a simpler function which is easy to understand and get hold.  Let us
consider some simpler functions, like a function which draws a straight line,
with it value increasing by a double at each point. That kind of a function is
n2. This is much easier to understand than a function of business problem which
after some analysis we can say in terms of a polynomial equation.

So, we come across the concept of expressing the complexity of a function in
terms of a simpler function.

1. If the simpler function is the upper cut-off for the growth of function
   after some-point in time, we say that the easier function is the Big O limit
   of the complex function. By upper cut-off, you can understand that the
   function will wont get past this, but it will never be less than this below
   that cut-off.

2. Opposite is for the Theta notation. The function will not go lower than the
   simpler one after the cut-off and it is called Theta notation.

3. For everything in between these 2 ranges, it is called as Phi notation.

The following video gives a good overview of the time-complexity.

.. raw:: html

        <iframe title="Uthcode Algorithms" width="480" height="390"
        src="http://www.youtube.com/embed/6Ol2JbwoJp0" frameborder="0"
        allowfullscreen></iframe>

O notation
----------

Theta notation
--------------

Phi notation
------------

Compare different time complexities : 0(n) vs 0(lg n)
-----------------------------------------------------

Applying O() to memory/space complexity
---------------------------------------

Time Complexity of Various Python bultin-in Operations - Dicts and Lists
========================================================================

Take for example, 'n' is the number of elements currently in the container. 'k'
is either the value of a parameter or the number of elements in the parameter.

list
----

The Average Case assumes parameters generated uniformly at random.

Internally, a list is represented as an array; the largest costs come from
growing beyond the current allocation size (because everything must move), or
from inserting or deleting somewhere near the beginning (because everything
after that must move). If you need to add/remove at both ends, consider using a
collections.deque instead

+---------------------+------------------------+----------------------+
| Operation           |   Average Case         | Amortized Worst Case |
+---------------------+------------------------+----------------------+
| Copy                |       O(n)             |         O(n)         |
+---------------------+------------------------+----------------------+
| Append[1]           |       O(1)             |         O(1)         |
+---------------------+------------------------+----------------------+
| Insert              |       O(n)             |         O(n)         |
+---------------------+------------------------+----------------------+
| Get Item            |       O(1)             |         O(1)         |
+---------------------+------------------------+----------------------+
| set Item            |       O(1)             |         O(1)         |
+---------------------+------------------------+----------------------+
| Delete Item         |       O(n)             |         O(n)         |
+---------------------+------------------------+----------------------+
| Iteration           |       O(n)             |         O(n)         |
+---------------------+------------------------+----------------------+
| Get Slice           |       O(k)             |         O(k)         |
+---------------------+------------------------+----------------------+
| Del Slice           |       O(n)             |         O(n)         |
+---------------------+------------------------+----------------------+
| Set Slice           |       O(k+n)           |         O(k+n)       |
+---------------------+------------------------+----------------------+
| Extend[1]           |       O(k)             |         O(k)         |
+---------------------+------------------------+----------------------+
| Sort                |       O(n log n)       |         O(n log n)   |
+---------------------+------------------------+----------------------+
| Multiply            |       O(nk)            |         O(nk)        |
+---------------------+------------------------+----------------------+
| x in s              |       O(n)             |                      |
+---------------------+------------------------+----------------------+
| min(s), max(s)      |       O(n)             |                      |
+---------------------+------------------------+----------------------+
| Get Length          |       O(1)             |         O(1)         |
+---------------------+------------------------+----------------------+

Collections.deque     
----------------

It is mostly useful when doing at the end operations. Even looking at the middle element is costly.


Operation               Average Case                    Amortized Worst Case

Copy                        O(n)                                O(n)

append                      O(1)                                O(1)

appendleft                  O(1)                                O(1)

pop                         O(1)                                O(1)

popleft                     O(1)                                O(1)

extend                      O(k)                                O(k)

extendleft                  O(k)                                O(k)

rotate                      O(k)                                O(k)

remove                      O(n)                                O(n)



set
---

See dict -- the implementation is intentionally very similar.


Operation                       Average case                    Worst Case

x in s                               O(1)                           O(n)

Union s|t                       O(len(s)+len(t))

Intersection s&t                O(min(len(s), len(t))          O(len(s) * len(t))

Difference s-t                  O(len(s))                      -

s.difference_update(t)          O(len(t))                      -

Symmetric Difference s^t        -                              -


* As seen in the source code the complexities for set difference s-t or
  s.difference(t) (set_difference()) and in-place set difference
  s.difference_update(t) (set_difference_update_internal()) are different! The
  first one is O(len(s)) (for every element in s add it to the new set, if not
  in t). The second one is O(len(t)) (for every element in t remove it from s).
  So care must be taken as to which is preferred, depending on which one is the
  longest set and whether a new set is needed.

* To perform set operations like s-t, both s and t need to be sets. However you
  can do the method equivalents even if t is any iterable, for example
  s.difference(l), where l is a list.

dict
----

The Average Case times listed for dict objects assume that the hash function
for the objects is sufficiently robust to make collisions uncommon. The Average
Case assumes the keys used in parameters are selected uniformly at random from
the set of all keys.

Note that there is a fast-path for dicts that (in practice) only deal with str
keys; this doesn't affect the algorithmic complexity, but it can significantly
affect the constant factors: how quickly a typical program finishes.

Operation               Average Case            Amortized Worst Case

Copy[2]                      O(n)                       O(n)

Get Item                     O(1)                       O(n)

Set Item[1]                  O(1)                        -

Delete Item                  O(1)                       O(n)

Iteration[2]                 O(n)                       O(n)

Notes

[1] = These operations rely on the "Amortized" part of "Amortized Worst Case".
Individual actions may take surprisingly long, depending on the history of the
container.

[2] = For these operations, the worst case n is the maximum size the container
ever achieved, rather than just the current size. For example, if N objects are
added to a dictionary, then N-1 are deleted, the dictionary will still be sized
for N objects (at least) until another insertion is made
