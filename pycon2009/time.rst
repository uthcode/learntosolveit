====
time
====

This module provides a number of functions to deal with dates and the time
within a day. It is a thin layer on top of the C runtime library.

A given date and time can either be represented as a floating point value (the
number of seconds since a reference date, usually January 1st, 1970), or as a
time tuple.

time, ctime, clock and sleep
----------------------------
``time.time()`` returns the unix time, that is the simple since the epoch. 
To know what is the epoch, look at ``time.gmtime(0)``, which is start of unix
time since 1 Jan 1970. 

``time.ctime()`` returns the wallclock time and ``time.clock()`` provides the
processor clock time, which is often used for benchmarking.

``time.sleep(seconds)`` would sleep ( do nothing) for the given seconds.

.. literalinclude::        time_time_ctime_clock.py

Benchmarking using time.clock
-----------------------------

The values returned from clock() can be used for performance testing,
benchmarking etc, since they reflect the actual time used by programs and can
be more precise than the values from time()

.. literalinclude::        time_clock.py

* hashlib - interface to many hash functions

Parsing time 
------------
In this snippet let us look into:

* ``time.strptime(string[,format])``, which parse a string representing a time
  according to a format. The return value is a struct_time as returned by
  gmtime() or localtime().

* ``time.strftime(format[, t])`` converts a tuple or struct_time representing a
  time as returned by gmtime() or localtime() to a string as specified by the
  format argument

* ``time.gmtime()``, ``time.localtime``  return a tuple or struct_time which
  can be parsed into various time components, like month, day, hour etc.
  Difference between gmtime and localtime is gmtime returns UTC while localtime
  returns the localtime.

* ``time.mktime()`` is the inverse of ``time.localtime`` which takes the
  ``time.localtime`` tuple and expresses it in localtime, which is in unix time
  format.

.. literalinclude::        time_parsing_time.py

Time Zone Calculations
----------------------

* ``time.timezone`` is the offset of the local (non-DST) timezone, in seconds
  west of UTC (negative in most of Western Europe, positive in the US, zero in
  the UK).

* ``time.tzname`` is a tuple of two strings: the first is the name of the local
  non-DST timezone, the second is the name of the local DST timezone.

* ``time.daylight`` defines the daylight savings time.

* ``time.tzset()``, resets the time conversion rules used by the library
  routines. The environment variable TZ specifies how this is done.  On many
  Unix systems, it is more convenient to use the system's zoneinfo (tzfile(5))
  database to specify the timezone rules. To do this, set the TZ environment
  variable to the path of the required timezone datafile, relative to the root
  of the systems `zoneinfo` timezone database, usually located at
  /usr/share/zoneinfo.

.. literalinclude::        time_timezone.py
