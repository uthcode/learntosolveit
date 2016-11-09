==========================
Reading Data from Zip File
==========================

Question
--------

Reading the content from a zip file.


Solution
--------

.. literalinclude:: ../../languages/python/files_reading_zipfile.py
   :language: python
   :tab-width: 4

.. runcode:: ../../languages/python/files_reading_zipfile.py
   :language: python
   :codesite: ideone

Explanation
===========

We read the file with "r" permission instead of "rb", as Python cookbook
advises that it is more deterministic when running in Windows OS.

You can list the contents of the zipfile and then read few bytes of them as
show in the example.

Here is a sample run of this program.

::

    $zip -c sample.zip files_reading_zipfile.py

    $ python files_reading_zipfile.py
    File: files_reading_zipfile.py
    has 406 bytes





.. seealso::

   * :python-suggest-improve:`files_reading_zipfile.py`
   * :python-better-explain:`files_reading_zipfile.rst`

