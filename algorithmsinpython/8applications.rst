============
Applications
============

Sorting
=======

Computers spend more time sorting than anything else. It makes sense to know
the sorting algorithms we have as part of our tools repertorire when doing any
algorithm intensive work or participating in any programming contest.

Let's take an example of bogosort, just for it's performance analysis. 

.. literalinclude:: source/bogosort.py

It is an example of **acheiving something** relying on luck. What are worst
case chance? In infinite years in your limited lifetime.  Do remember that as
interested people, we will optimistically consider only the worst case scenario
and we won't trust the other scenarios.

+--------------------+-------------------+
|Scenario            |       Complexity  |
+--------------------+-------------------+
|Worst case          |         O(∞)      |
+--------------------+-------------------+
|Best case           |         O(n)      |
+--------------------+-------------------+
|Average case        |         O(n.n!)   |
+--------------------+-------------------+
|Worst case space    |         O(n)      |
+--------------------+-------------------+

So, the conclusion that acheiving something by sheer luck is possible 1 out of
infinite trials.

Basic Concepts
--------------

Comparing
---------

Stability
---------

Simple Algorithms
=================

Here are some simple explainations of Sorting Algorithms.

Bubble Sort
-----------

Let's just recollect Donald Knuth's quote about Bubble sort.

        "the bubble sort seems to have nothing to recommend it, except a catchy name and
        the fact that it leads to some interesting theoretical problems"


And instead of seeing how bubble sort works, let's instead look at its
theoretical problems.

Insertion Sort
--------------

Start with the second element as the key and compare it with the elements
preceding it. If you find the elements greater than key, shift the list one by
one and when you find the element is lesser than key, insert the key at that
position.

.. literalinclude:: source/8applications-insersion-1.py

 
Here is Insertion Sort's asymptotic analysis

+----------------------+------------------------------+
| *Scenario*           |   *Complexity*               |
+----------------------+------------------------------+
| Worst Case           |   O(n\ :sup:`2`\ )           |
+----------------------+------------------------------+
| Best  Case           |   O(n)                       |
+----------------------+------------------------------+
| Average Case         |   O(n\ :sup:`2`\ )           |
+----------------------+------------------------------+
| Worst Case Space     |   O(n) total, O(1) auxillary |
+----------------------+------------------------------+

Merge Sort
----------

.. literalinclude:: source/mergesort.py


Here is mergesort's asymptotic analysis.

+----------------------+------------------------------+
| *Scenario*           |   *Complexity*               |
+----------------------+------------------------------+
| Worst Case           |   O(nlogn )                  |
+----------------------+------------------------------+
| Best  Case           |   O(nlogn)/ O(n)             |
+----------------------+------------------------------+
| Average Case         |   O(n logn )                 |
+----------------------+------------------------------+
| Worst Case Space     |   O(n)                       |
+----------------------+------------------------------+

Quick Sort
==========

.. literalinclude:: source/quicksort.py


This is quicksort's algorithm analysis.
 
+----------------------+------------------------------+
| *Scenario*           |   *Complexity*               |
+----------------------+------------------------------+
| Worst Case           |   O(n\ :sup:`2`\ )           |
+----------------------+------------------------------+
| Best  Case           |   O(n\ :sup:`2`\ )           |
+----------------------+------------------------------+
| Average Case         |   O(n\ :sup:`2`\ )           |
+----------------------+------------------------------+
| Worst Case Space     |   O(n) total, O(1) auxillary |
+----------------------+------------------------------+

Implementation
--------------

Issues
------

Time-Complexity
---------------

Time Complexity of Sorting
==========================

Proof of O(nlgn) bound
----------------------

Breaking assumptions - Parallelism
----------------------------------

Spaghetti Sort
--------------

