========
TopCoder
========

Resources for Solving Topcoder Problems 
=======================================

* `TopCoder C++ for C Programmers`_

C++ is an object oriented extension to the C programming language. C++ provides
many benefits over traditional C while still maintaining C compatibility,
allowing people to use C and C++ program in the same program. Within a
competition, you'll be required to use some basic C++ functionality to solve
problems. What follows is a basic explanation for programmers who are currently
familiar with C. ::


    Class: CellTower
    Method: best
    Parameters: vector <string>, int, int
    Returns: int
    Method signature: int best(vector <string> towers, int x, int y)


To solve the problem you'll need to create a class named CellTower containing a
method best that takes three arguements (vector<string>, int, and int), and
returns an int. 

Classes are defined using the class keyword. The definition follows a similar
pattern as the C struct keyword. To define the class above we'd use the
following code.::

    class CellTower {
    public:
    int best(vector<string> towers, int x, int y) {
    //your code here
    }
    };

Note how the method is defined like you would define a standard C function. The
public keyword tells the compiler that the method we're defining is accessable
to any object, allowing the testing process to properly execute your code. 

The STL

Many of the classes and functions used in competition come from the Standard
Type Library, also known as the STL. The STL provides a set of common libraries
to perform everything from basic string work to complicated sorting algorithms. 

To be able to compete, you'll need to be familiar with two classes: vector and string. 

Includes

Before you can use any of the STL classes, you'll need to include the
appropriate header files. The vector class comes from the header "vector" and
the string class comes from the header "string". In addition, you'll need to
add the line::

    using namespace std;

to your code to tell the compiler to look for objects in the std namespace. 

Vector
------

A vector is the C++ replacement for arrays. Vectors solve many of the problems
of traditional C arrays by allowing dynamic resizing and providing methods to
inspect the current size of the array. You declare a vector as vector<type>
where type is the type of variable stored in the array. To create a vector of
ints, you'd write::

    vector<int> myVar;

Newly created vectors are of size 0. To declare a vector with a specific size,
you can use::

    vector<int> myVar(10);

In this case the newly created vector has a size of 10. 

To set / retrieve the elements in a vector, you can use the same syntax you'd
use to work with a C array.::

    vector<int> myVar(10);

    myVar[0] = 1; //sets the first element to 1
    printf("%i", myVar[0]); //prints 1

One of the major problems with C arrays is that there is no way at runtime to
know how large the array is, making looping over the contents of the array
difficult. Using vectors, this task becomes simple. The size() method will
return the current size of the vector.

    for(int i = 0; i < myVar.size(); i++) {
    printf("%i", myVar[i]); //prints element i
    }

To resize a vector, use the resize method.::

    myVar.resize(15); //sets the size of myVar to 15

The vector class contains many additional useful functions, which you can read
more about by following the reference links below. 


.. _TopCoder C++ for C Programmers: http://www.topcoder.com/pl/?&module=Static&d1=gicj05&d2=cpp 

C++ Notes
---------

To use the string in a function that expects a char*, use the c_str() method.

string s = "Hello";
printf("%s", s.c_str()); //outputs "Hello"

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
etc.) to string, you can use.::

    #include <sstream>

    int i = 5;
    std::string s;
    std::stringstream out;
    out << i;
    s = out.str();

http://wwwasd.web.cern.ch/wwwasd/lhc++/RW/stdlibcr/classref.htm

http://www.sgi.com/tech/stl/

http://www.cplusplus.com/reference/

General Advice by Steven Skeina
-------------------------------

My Advice for Your Future You are all awesome and will be successful – but
follow my advice to maximize your success:

* Look out for yourself and your career, since no one else is going to do it
for you.

* Look for where the big challenges are happening, and then focus on setting
the agenda.

* Avoid self-destructive behavior/career-limiting moves.

* Learn to communicate.

* Always keep learning and growing.


If you are interested in algorithms and advanced computer science, you should
consider graduate school.  Advanced course work is an important part of the
program, but the most important part of a Ph.D is research.



http://www.cs.sunysb.edu/~skiena/talks/topcoder.pdf
