================
Lexical Analyzer
================

Question
--------

Write a Lexical Analyzer for the tokens.

::

   # Write the lexical analyzer for the tokens:
   # Regular Expression    Tokens  Attribute-Value
   # ws                    -       -
   # if                    if      -
   # then                  then    -
   # else                  else    -
   # id                    id      pointer to table entry
   # num                   num     pointer to table entry
   # <                     relop   LT
   # <=                    relop   LE
   # =                     relop   EQ
   # <>                    relop   NE
   # >                     relop   GT
   # >=                    relop   GE

Solution
--------

.. literalinclude:: ../../languages/python/algorithm_lexical_analyzer_1.py
   :language: python
   :tab-width: 4

.. runcode:: ../../languages/python/algorithm_lexical_analyzer_1.py
   :language: python
   :codesite: ideone

Explanation
===========



.. git_changelog::

.. seealso::

   * :python-suggest-improve:`algorithm_lexical_analyzer_1.py`
   * :python-better-explain:`algorithm_lexical_analyzer_1.rst`

