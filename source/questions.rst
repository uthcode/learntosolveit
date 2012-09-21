HG
==

1. How to get a set of defaults to hg when you clone?

   Create your .hgrc file.

2. How to switch between different patch queues.
   hg qpop -a
   hg qqueue <another_queue>
   # start working.
   hg qrefresh
   hg qpop -a
   hg qqueue orig-queue
   hg qpush -a

3. In hg. the patches grow from the bottom.

    $ hg qseries
    0 A patch1
    1 A patch2
    $ hg qnew patch3
    $ hg qseries
    0 A patch1
    1 A patch2
    2 A patch3

4. You can add a file in hg queue and then push and pop it?

5. Where does mercurial store it's extension files? 

   /usr/share/pyshared/hgext


6. Why does MAC OS not able to connect to wifi?

7. What is the difference between - 

    require 'something'

    vs

    require "something"


    Note the change in single quote and double quote.

8. How to I fold and unfold in vim.
=======

8. What is a macro in C?

9. Explain pointers in such a way that you will never forget.

10. What could be objectimpl.h?

    Object implementation details.

11. Program using malloc.

12. What does ifdef __cplusplus do?

13. How to have vimrc with 2 space tabs for python?
