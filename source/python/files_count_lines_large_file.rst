===========================
Count Lines in a Large File
===========================

Question
--------

How to count lines in a huge file.


Solution
--------

.. literalinclude:: ../../languages/python/files_count_lines_large_file.py
   :language: python
   :tab-width: 4

.. runcode:: ../../languages/python/files_count_lines_large_file.py
   :language: python
   :codesite: ideone

Explanation
===========

This loads the file in 'rb' (read binary) mode, in chunks and then counts the newline '\n'
characters. Loading in chunks takes care of reading a huge file part.






.. seealso::

   * :python-suggest-improve:`files_count_lines_large_file.py`
   * :python-better-explain:`files_count_lines_large_file.rst`

