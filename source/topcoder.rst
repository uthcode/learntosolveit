========
TopCoder
========

Resources for Solving Topcoder Problems 
=======================================

* `TopCoder C++ for C Programmers`_
* `Programming Bookmarks`_

Worst Case Run-time is the more frequently used benchmark for a given algorithm.

.. _TopCoder C++ for C Programmers: http://www.topcoder.com/pl/?&module=Static&d1=gicj05&d2=cpp 
.. _Programming Bookmarks: http://delicious.com/orsenthil/Programming

* A Desktop PC can do a little over pow(10, 9) operations per second.

      +-------------+-----------------------+
      | *N=100*     |  *Time Taken*         |
      +=============+=======================+
      | O(Log(N)    |  pow(10,-7) seconds   |
      +-------------+-----------------------+
      | O(N)        |  pow(10,-6) seconds   |
      +-------------+-----------------------+
      | O(N Log(N)) |  pow(10, -5) seconds  |
      +-------------+-----------------------+
      | O(N pow 2)  |  pow(10, -4) seconds  |
      +-------------+-----------------------+
      | O(N pow 6)  |  3 minutes            |
      +-------------+-----------------------+
      | O(2 pow N)  |  pow(10, 14) years    |
      +-------------+-----------------------+
      | O(N!)       |  pow(10, 142) years   |
      +-------------+-----------------------+

Sorting
-------

Insertion Sort O(N^2) And for 1000000000 items that would take 10^18
operations; If 10^9 operations can be done in a second; then 10^9 seconds is
required to do that; which would easily be in years.  Quick Sort, Heap Sort and
Merge Sort is better; O(N Log N) operations.

Shortest Path Algorithms
------------------------

Finding the shortest path from A to B; would not be possible.
O(C^N).
O(E*V(logV)) = Dikstra's algorihm. Uses Priority Queues.

Stable Matching Algorithm for sending data.
Maximum Flow Problem. Ford and Fulkerson problem. SRM 200.
Dynamic Programming.

Minimum number of insertions, deletions required to transform sequence A into sequence B.
Dynamic programming makes the algorithm run in O(N*M) only.

MatchMaking problem, SRM 203 problem.
BettingMoney problem.

Notes
-----

* The median finding algorithm using random numbers seem intesting.
* Graduation Problem is SRM 200 is the example of Max Flow property.
* In Combination, the number of times a particular letter appears is (n!/n!*(n-r)!) * r/n
* It is not sufficient to know how to use an algorithm in the default sense;
  always strive to know any algorithms you have memorized inside and out
