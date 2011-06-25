======
urllib
======

This module provides a high-level interface for fetching data across the World Wide Web. In particular, the urlopen() function is similar to the built-in function open(), but accepts Universal Resource Locators (URLs) instead of filenames. Some restrictions apply can only open URLs for reading, and no seek operations are available.

Changes in Py3k
---------------
The urllib module has been split into parts and renamed in Python 3.0 to urllib.request, urllib.parse, and urllib.error. The 2to3 tool will automatically adapt imports when converting your sources to 3.0. Also note that the urllib.urlopen() function has been removed in Python 3.0 in favor of urllib2.urlopen().

Example 1
---------
.. literalinclude::        urllib_encoded_args.py

Example 2
---------
.. literalinclude::        urllib_filelike.py

Example 3
---------
.. literalinclude::        urllib_get.py

Example 4
---------
.. literalinclude::        urllib_pathname.py

Example 5
---------
.. literalinclude::        urllib_post.py

Example 6
---------
.. literalinclude::        urllib_quote_unquote.py

Example 7
---------
.. literalinclude::        urllib_urlretrieve.py
