=====================================
Exercise 1.2 - Experiment with printf
=====================================

Question
========

Experiment to find out what happens when prints's argument string contains \c,
where c is some character not listed above.

Solution
========

.. literalinclude:: ../../languages/cprogs/Ex_1.2_exp_printf_c.c
   :language: c
   :tab-width: 4


Explanation
===========

For the invalid characters, the compiler will output a warning statement.

::

    warning: unknown escape sequence \d

The other interesting warning statements are mentioned beside in the program.
The rest of the control characters took effect and this is the output from the
program.

::

        a:b:c:cd:de:f:g:gh:hi:ij:jk:kl:lm:mn:
        o:op:pq:qr:
        s:st:	u:☃v:w:wx:
        y:yz:zA:AB:BC:CD:DE:F:FG:GH:HI:IJ:JK:KL:LM:MN:NO:OP:PQ:QR:RS:ST:RU:☃V:VW:WX:XY:YZ:Z0:1:2:3:4:5:6:7:8:89:9~:~`:`!:!@:@#:#$:$%^:^&:&*:*(:():)_:_-:-+:+{:{[:[}:}]:]|:|:\a::::;:;":"':'<:<,:,>:>.:.?:?/:/


References
==========

* `Discussion on U Codepoint`_
* `Valid escape characters`_

.. _Discussion on U Codepoint: http://stackoverflow.com/questions/21241224/unicode-codepoint-of-the-format-unnnnnnnn/
.. _Valid escape characters: http://en.cppreference.com/w/cpp/language/escape


.. seealso::

   * :c-suggest-improve:`Ex_1.2_exp_printf_c.c`
   * :c-better-explain:`Ex_1.2_exp_printf_c.rst`
   
