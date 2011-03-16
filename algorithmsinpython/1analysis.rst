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
