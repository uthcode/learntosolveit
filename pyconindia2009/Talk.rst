To sort, or not to Sort. That is the question. Isnt it?

Computers spend more time sorting data than anything else. So, it definitely
makes sense to have ideas about the sorting methodologies.

Other sorting libraries:
C- qsort.
C++ std::sort
C++ std::psort

What are the problems in using standard library sorting algorithms.
- They are generic and are designed to work well for as many cases as possible.
- This may not be suitable for your case.


Any sorting algorithm that sorts by comparision will have a minimum lower
bound of 

Python lists has a built-in sort method that modifies the list in-place and a
sorted() built-in function that builds a new sorted list from an iterable.

- A simple ascending sort is very easy. Just call sorted() function. It returns
  a new sorted list.

- sort() method on a list, modifies the list in-place (and returns None to
  avoid confusion). If you don't need the original list, it is slightly more
  efficient.
 
>>>help(sorted)
Help on built-in function sorted in module __builtin__:

sorted(...)
    sorted(iterable, cmp=None, key=None, reverse=False) --> new sorted list
(END) 


>>>help([].sort)
Help on built-in function sort:

sort(...)
    L.sort(cmp=None, key=None, reverse=False) -- stable sort *IN PLACE*;
    cmp(x, y) -> -1, 0, 1


>>>help(cmp)
Help on built-in function cmp in module __builtin__:

cmp(...)
    cmp(x, y) -> integer
    
    Return negative if x<y, zero if x==y, positive if x>y.

- Sort takes an optional function which can be called for doing the comparisions.
- We can define our own function or comparision.

def numeric_compare(x, y):
        if x > y:
                return 1
        elif x == y:
                return 0
        else: # x < y
                return -1

timeit module

On either platform, the default timer
functions measure wall clock time, not the CPU time.  This means that
other processes running on the same computer may interfere with the
timing.  The best thing to do when accurate timing is necessary is to
repeat the timing a few times and use the best time.  The -r option is
good for this; the default of 3 repetitions is probably enough in most
cases.  On Unix, you can use clock() to measure CPU time.


Python sort's key parameter lets you derive a sorting key for each element of
the list and then sort using that key.

Unfortunately, the use of traditional programming languages forces students to
deal with details of data structures and supporting routines, rather than
algorithm design. Python represents an algorithm-oriented language that has
been sorely needed in education. The advantages of Python include its
textbook-like syntax and interactivity that encourages experimentation. More
importantly, we report our novel use of Python for representing aggregate data
structures such as graphs and flow networks in a concise textual form, which
not only encourages students to experiment with the algorithms but also
dramatically cuts development time.

Prescience of Donald Knuth

From "Structured Programming with go to Statements", written in 1974 (appeard
in Computing Surveys, Vo. 6, No. 4, December 1974).

The Future

It seems clear that languages somewhat different from those in existence today
would enhance the preparation of structured programs.  We will perhaps
eventually be writing only small modules which are identified by name as they
are used to build larger ones, so that devices like indentation, rather than
delimiters, might become feasible for expressing local structure in the source
language.

Yep! I also recommend using python -mtimeit from a command line instead of
timeit as a module -- the command line version has just too many handy little
things you don't get from the module (repeating a varying number of times
depending on how slow/fast is what you're measuring, for example: a great
microbenchmarking technique, pity the module doesn't offer it -- etc, etc;-). –
Alex Martelli

"the bubble sort seems to have nothing to recommend it, except a catchy name and
the fact that it leads to some interesting theoretical problems". Donald Knuth.
