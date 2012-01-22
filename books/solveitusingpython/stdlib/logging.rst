=======
logging
=======

The logging module defines a standard API for reporting errors and status
information from all of your modules. The key benefit of having the logging API
provided by a standard library module is that all python modules can
participate in logging, so your application log can include messages from
third-party modules.

It is, of course, possible to log messages with different verbosity levels or
to different destinations. Support for writing log messgaes to files, HTTP
GET/POST locations, email via SMTP, generic sockets, or OS-specific logging
mechnisms are all supported by the standard module. You can also create your
own log destination class if you have special requirements not met by any of
the built-in classes.

Example 1:
----------
.. literalinclude::        logging_default.py

Example 2:
----------
.. literalinclude::        logging_levels.py

Example 3:
----------
.. literalinclude::        logging_modules_example.py

Example 4:
----------
.. literalinclude::        logging_rotatinglogfile.py
