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

6. Why does MAC OS not able to connect to wifi?

7. What is the difference between - 

    require 'something'

    vs

    require "something"


    Note the change in single quote and double quote.
