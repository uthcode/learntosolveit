================================
Using Random Access Input Output
================================

Question
--------

Read a particular record from somewhere inside a large file of fixed-length
records.

Solution
--------

.. literalinclude:: ../../languages/python/files_random_access_input_output.py
   :language: python
   :tab-width: 4

.. runcode:: ../../languages/python/files_random_access_input_output.py
   :language: python
   :codesite: ideone

Explanation
===========

The file seek call, seeks to a particular position in the file. The read
method then reads the block of text.




.. seealso::

   * :python-suggest-improve:`files_random_access_input_output.py`
   * :python-better-explain:`files_random_access_input_output.rst`

