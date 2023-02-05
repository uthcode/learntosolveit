========================================================
Exercise 3.2 - escape sequences into the real characters
========================================================

Question
========

Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a
switch. Write a function for the other direction as well, converting escape
sequences into the real characters.

.. literalinclude:: ../../languages/cprogs/Ex_3.2_escape.c
   :language: c
   :tab-width: 4

   :language: c

Explanation
===========

C Program interpreters ``\n`` and ``\t`` as space characters and outputs them. Our
intention is to capture the ``\n`` and ``\t`` characters and display them visibly as
**\n** or **\t**. In order to do that we need to *escape* them, the escaping is
done by adding ``\`` character.

So in the program as soon as we see a ``\n`` character, in the array where we are
copying to, we copy ``\\`` character and add a ``n`` character and similarly, when
we see a ``\t`` character, in the array where we are copying to, we copy ``\\``
character and add a ``t`` character.



.. seealso::

   * :c-suggest-improve:`Ex_3.2_escape.c`
   * :c-better-explain:`Ex_3.2_escape.rst`
