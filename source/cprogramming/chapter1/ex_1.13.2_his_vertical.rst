=========================
1.13.2 Vertical Histogram
=========================

Question
--------


Write a program to print a histogram of the lengths of words in its input.  Draw
the histogram with the bars vertical.

Solution
--------

.. coderun:: cprogs/ex_1.13.2_his_vertical.c
   :language: c


Explanation
===========

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
Visualize the Concept
---------------------

.. raw:: html

   <iframe width="800" height="500" frameborder="0" src="https://pythontutor.com/iframe-embed.html#code=%2F%2A%20Concept%3A%20vertical%20histogram%20of%20word%20lengths%20%2A%2F%0A%23include%20%3Cstdio.h%3E%0Aint%20main%28void%29%20%7B%0A%20%20%20%20int%20word%5B2%5D%20%3D%20%7B0%7D%3B%0A%20%20%20%20char%20s%5B%5D%20%3D%20%22ab%20cd%5Cn%22%3B%0A%20%20%20%20int%20nc%20%3D%200%2C%20nw%20%3D%200%2C%20i%2C%20j%3B%0A%20%20%20%20for%20%28i%20%3D%200%3B%20s%5Bi%5D%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20%20%20%20%20%2B%2Bnc%3B%0A%20%20%20%20%20%20%20%20if%20%28s%5Bi%5D%20%3D%3D%20%27%20%27%20%7C%7C%20s%5Bi%5D%20%3D%3D%20%27%5Cn%27%29%20%7B%20word%5Bnw%2B%2B%5D%20%3D%20nc-1%3B%20nc%20%3D%200%3B%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20for%20%28i%20%3D%202%3B%20i%20%3E%3D%201%3B%20--i%29%20%7B%0A%20%20%20%20%20%20%20%20for%20%28j%20%3D%200%3B%20j%20%3C%20nw%3B%20%2B%2Bj%29%20putchar%28i%20%3C%3D%20word%5Bj%5D%20%3F%20%27%2A%27%20%3A%20%27%20%27%29%3B%0A%20%20%20%20%20%20%20%20putchar%28%27%5Cn%27%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%200%3B%0A%7D%0A&codeDivHeight=400&codeDivWidth=350&curInstr=0&origin=opt-frontend.js&py=c_gcc9.3.0"> </iframe>
