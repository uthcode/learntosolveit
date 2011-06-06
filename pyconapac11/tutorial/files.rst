Files - we handle them often
============================

* The builtin function ``open`` opens the file and returns a stream. It raises
  an IOError upon failure.

* A variant of 'r' that is sometimes precious is 'rU', which tells Python to
  read the file in text mode with "universal newlines": mode 'rU' can read text
  files independently of the line termination convention the files are using,
  be it the Unix way, the Windows way or even the (Old) Mac way. (Mac OS X
  today uses Unix for all intents and purposes, but releases of Mac OS 9 and
  earlier were different).

* When read is called with an integer argument N, it reads and returns the next
  N bytes (or all the remaining bytes if less than N bytes remain)

* Files have other writing related methods such as flush, to send any data
  being buffered, and writelines, to write a sequence of strings in a single
  call.  However, write is by far the most commonly used method.

* Other methods worth mentioning are seek and tell, which support random access
  to files. These methods are normally used with binary files made up of
  fixed-length records.

* StringIO objects are plug-and-play compatible with file objects, so scanner
  takes its three lines of text from an in-memory string object, rather than a
  true external file.This shows that Everywhere in Python, object interfaces,
  rather than specific data types are units of coupling.

* Often the data you want to write is not in one bit string, but in a list (or
  other sequence) of strings. In this case, you should use the writelines
  method (which despite its name, is not limited to lines and works just as
  well with binary data as well as text files). Calling writelines is much
  faster than the alternatives of joining the strings into one big string (e.g,
  with the ''.join) and then calling write or calling write repeatedly in a
  loop.  Calling close is even more advisable when you are writing to a file
  than you are reading from a file.

* With ZipFile, the flag is not used the same way when opening a file, and rb
  is not recognized. The r flag handles the inherently binary nature of all zip
  files on all platforms.

Reading a Single line from a file, give an line number
------------------------------------------------------
.. literalinclude:: py31/howto7_file_lookforline.py

Finding files given a search path and a pattern
-----------------------------------------------
.. literalinclude:: py31/howto8_file_filename_pattern.py

Creating a file-like object from a string
-----------------------------------------
.. literalinclude:: py31/howto9_file_filelike_from_line.py

How to Read and write to a zip file
-----------------------------------
.. literalinclude:: py31/howto10_file_write_read_zipfile.py
