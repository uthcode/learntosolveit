====
glob
====

`Credits: Dough Hellman for PyMOTW`

This module generates lists of files matching given patterns, just like the Unix shell.

File patterns are similar to regular expressions, but simpler. An asterisk (*)
matches zero or more characters, and a question mark (?) exactly one character.
You can also use brackets to indicate character ranges, such as [0-9] for a
single digit. All other characters match themselves.

glob(pattern) returns a list of all files matching a given pattern.

Note that glob returns full path names, unlike the os.listdir function. glob
uses the `fnmatch` module to do the actual pattern matching.

The following are some example programs which demonstrates the usage of glob module.

To test these programs, we must use `glob_maketestdata.py`.

Get all files and directories
------------------------------
.. literalinclude::        glob_all.py

Specify with a range
--------------------
.. literalinclude::        glob_charrange.py

Using a single wild character
-----------------------------
.. literalinclude::        glob_singlewildchar.py

Finding within a subdirectory
-----------------------------

.. literalinclude::        glob_subdir.py

