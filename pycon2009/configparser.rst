============
configparser
============

The configparser module reads configuration files.The files should be written
in a format similar to Windows INI files.  The file contains one or more
sections, separated by section names written in brackets. Each section can
contain one or more configuration items.

Changes in Python 3k
--------------------

The ConfigParser module has been renamed to configparser in Python 3.0. The
2to3 tool will automatically adapt imports when converting your sources to 3.0.

Reading a configfile
--------------------
Class RawConfigParser and its subclass ConfigParser, provides the basic
configuration object.

The sections of the configuration object can be accessed through the object's
`sections()` method, the options for each section is availble through object's
`options(section)` method.  and config value can be accessed through object's,
`get(section,option)`.

The following example demonstrates the concepts which were discussed.


.. literalinclude::        config1.ini

.. literalinclude::        configparser_1.py

Writing to a configfile
-----------------------

RawConfigParser object can be used to write Configuration files.  When adding
sections or items, add them in the reverse order of how you want them to be
displayed in the actual file.  In addition, please note that using
RawConfigParser's and the raw mode of ConfigParser's respective set functions,
you can assign non-string values to keys internally, but will receive an error
when attempting to write to a file or when you get it in non-raw mode.
SafeConfigParser does not allow such assignments to take place.  

.. literalinclude::        configparser_2.py

Configfile generated using this example

.. literalinclude::        example.cfg

Reading the configfile with value types and interpolation
---------------------------------------------------------

An example of reading the configuration file again.

.. literalinclude::        configparser_2.py

* Note that getint and getfloat return respective value types.

* Also RawConfigParser() does not interpolate the option values, so the output
  will still be ``%(bar)s' or '%(baz)s``

* To get the output value interpolation (That is substition of option values at
  places denoted), use use a ConfigParser or SafeConfigParser and the third
  argument default 0 signifies interpolation and 1 indicates raw mode. There is
  a fourth argument possible, taking a dict which will take higher precedence
  to interpolation.

The following example demonstrates these concepts well.

.. literalinclude::        configparser_3.py
