===============
Exercise 1.13.2
===============

Question
--------


Write a program to print a histogram of the lengths of words in its input.  Draw
the histogram with the bars vertical.

Solution
--------

.. literalinclude:: ../../languages/cprogs/Ex_1.13.2_His_vertical.c
   :language: c
   :tab-width: 2

Explaination
------------

---- 

The objective of this program is the print a vertical histogram.
For e.g. if the same input as the previous program is given.

Input **I love C programming**

The desired output is::

          *
          *
          *
          *
          *
          *
          *
      *   *
      *   *
      *   *
    * * * *

Printing the vertical histogram is tricky for number of reasons.

*Printing usually happens from top to botton and left to right.*

We have to know this limitation when we write the output. In the program, we
predetermine and store maximum number of words in a sentence (MAXNO 25) and
maximum length of the word (MAXWL 25). So, if our input exceeds those, our
above program may give incorrect output.

Then we go about finding the word length of each word and store it in a WORD
Array. The way we do this is, initialize all the word lengths to 0 first, and
then count each word length using a while loop. Use a variable, nc to count the
number of characters in a word and store it in **WORD[nw]**  and if we find a
space character, then we say it is the next word and start counting the length
of the next (by resetting nc back to 0)

So for the above example input, we will have.

First step: WORD[0, 0, 0, 0]

And then we we count the words and store their lengths.

We would have got: WORD[1,4,1, 11]

Next we use the WORD array above and we go about printing from left to right. We
we start left, we can see if our left position (j) is <=  WORD value in that
position, WORD[j]. This is accomplished in the for loop `if j <= word[j]` if it
is, then we print * otherwise we print space ''.

Like in the first line above, when j == 11,. we will print ' ' for position 1,
' ' for position 2, and ' ' for position 3 but '*' for position 4.

So our output will look like::

    ' '' '' ''*'
    ' '' '' ''*'
    ' '' '' ''*'
    ' '' '' ''*'

We will keep going for this till we get j == 4 and at that moment, our output
will be::

    ' ''*''' '*'

And when j hits 1 (for all one character words like *I* and *C* in the input),
we will have hit the bottom of the histogram::


    '*''*''*''*'

Combing them all, we would have drawn the horizontal histogram like above.












This document was updated on |today|
