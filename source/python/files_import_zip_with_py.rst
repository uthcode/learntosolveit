=============================
Import a zipfile with py file
=============================

Question
--------

This snippet creates a zip file with a '.py' inside it. Demonstrates python
ability to import a zipfile and run the function inside it.

Solution
--------

.. literalinclude:: ../../languages/python/files_import_zip_with_py.py
   :language: python
   :tab-width: 4

.. runcode:: ../../languages/python/files_import_zip_with_py.py
   :language: python
   :codesite: ideone

Explanation
===========

Running this will emit an output.

::

   hello world from /var/folders/_2/kqmfvpxj3_l3dnj5wq1y6j1c0000gn/T/tmpK1ePKl.zip/hello.py


Note that I have imported `import hello` using a module name as the name of
the zipfile and accessed a function inside it. This demonstrates only ability
to package python files and run it as a package.

.. git_changelog::


.. seealso::

   * :python-suggest-improve:`files_import_zip_with_py.py`
   * :python-better-explain:`files_import_zip_with_py.rst`

