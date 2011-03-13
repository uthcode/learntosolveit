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
------------------------------------------------------------------------
