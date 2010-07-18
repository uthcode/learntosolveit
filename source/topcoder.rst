========
TopCoder
========

Resources for Solving Topcoder Problems 
=======================================

* `TopCoder C++ for C Programmers`_
* `Programming Bookmarks`_

.. _TopCoder C++ for C Programmers: http://www.topcoder.com/pl/?&module=Static&d1=gicj05&d2=cpp 
.. _Programming Bookmarks: http://delicious.com/orsenthil/Programming


Rough Data on Execution Times
-----------------------------

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

* Source: TopCoder Algorithms Tutorial.


This table is extending that run time to a Billion times.

    +--------------------+----------------------+
    |  1000000000        | Time Taken           |
    +====================+======================+
    |  O(log\ *n* )      | 1 second             |
    +--------------------+----------------------+
    |  O(n)              | 10 seconds           |
    +--------------------+----------------------+
    |  O( *n* log\ *n* ) |  1.5 minutes         |
    +--------------------+----------------------+
    |  O(n\ :sup:`2` )   |  16 minutes          |
    +--------------------+----------------------+
    |  O(n\ :sup:`6` )   |  7 days              |
    +--------------------+----------------------+
    |  O(2\ :sup:`n` )   |  10\ :sup:`21` years |     
    +--------------------+----------------------+
    |  O(n *!* )         |  10:sup:149 years    |
    +--------------------+----------------------+


* Dikstra's algorithm for shortest path takes *O(E\*V(logV))*

* Using an Randomized algorithm, the median could be found in O(n) times.

* `Stable Matching Algorithm`_ for sending data.

.. _Stable Matching Algorithm: http://en.wikipedia.org/wiki/Stable_marriage_problem

* Maximum Flow Problem. Ford and Fulkerson algorithm. Graduation in SRM 200.
* Good chances that Akamai might be using Ford Fulkerson algorithm for sureroute.

Dynamic Programming.
--------------------

Minimum number of insertions, deletions required to transform sequence A into sequence B.
Dynamic programming makes the algorithm run in O(N*M) only.

MatchMaking problem, SRM 203 problem.
BettingMoney problem.

References for Dikstra's algorithm

* http://optlab-server.sce.carleton.ca/POAnimations2007/DijkstrasAlgo.html

Notes
-----

* The median finding algorithm using random numbers seem intesting.
* Graduation Problem is SRM 200 is the example of Max Flow property.
* In Combination, the number of times a particular letter appears is (n!/n!*(n-r)!) * r/n
* It is not sufficient to know how to use an algorithm in the default sense;
  always strive to know any algorithms you have memorized inside and out

In order to convert an int (or any other numeric type, e.g., float, double,
etc.) to string, you can use:

#include <sstream>

int i = 5;
std::string s;
std::stringstream out;
out << i;
s = out.str();
