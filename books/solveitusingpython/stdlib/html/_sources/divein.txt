=========
Diving In
=========
Lets dissect a working Python Program and try to understand various aspects of it.

.. literalinclude::        socket_irclogger.py

In the above program, you have

* modules
* function definitions
* try and finally block
* socket calls.
* print statement


===============================
Py3K, what to look for in brief
===============================


* Simpler built-in types.  Instead of having a built-in type for int and then
  for long as in Py26, have a single built-in type int in py3k, which will
  behave like long and serve for int as well.

* In py26, you and str and unicode. Now Its just str, which is internally
  unicode. So all strings are unicode in py3k.  There is a separate bytes type
  for bytes of characters.

* 1/5 will be 0.2 in Python3k. If you want the result to be 0, like in
  Python26, do 1//5

* No comparisons supported between incompatible types. Documents from time
  immemorial advised the users to not to rely and it can change anytime. Well
  the change has happened.

* Its print() function for output now, just like input() function input.  
  Two things here. Previously in py2x, input() expected an object and raw_input()
  was actually used to input. Now in py3k, its just input() which will behave
  just like raw_input() before.


* Everything is a new style class. All classes that you define will implicitly
  be derived from the object class.


* There is refactoring tool developed by python hackers which can be used to
  port your py2x code to py3k.  Everyones resounding advice is Use It!. This
  will help in migration as well fix any issues with the refactoring tool. 

================
Diving Into Py3K
================

Lets look at the same program in Python 3k

.. literalinclude::        py3k/socket_irclogger.py


* Note the change in print function.
* Sending bytes instead ( encoded)

