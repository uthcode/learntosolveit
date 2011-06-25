Date and time related
=====================

* One of the most used function is from the module time which is `time.time`.
  This returns the number of seconds passed since a fixed instant called the
  epoch, it is usually the midnight of 1 Jan 1970.
 
To find out which epoch, your platform uses.
::

>>> import time
>>> print time.asctime(time.gmtime(0))

* time.gmtime - converts any timestamp into a tuple without TZ convertion.
* time.asctime - represents it in human readable way.

Here is a way to unpack the tuple representing the current local time.

::

        >>> time.localtime()
        time.struct_time(tm_year=2010, tm_mon=2, tm_mday=10, tm_hour=20, tm_min=43,
        tm_sec=38, tm_wday=2, tm_yday=41, tm_isdst=0)

        >>> year, month, mday, hour, minute, sec, wday, yday, isdst = time.localtime()

        >>> time.localtime().tm_mday, time.localtime().tm_mon, time.localtime().tm_year
        (10, 2, 2010)


* calling time.localtime, time.gmtime, time.asctime without any argument, each
of them conveniently defaults to using the current time.


* time.strftime - builds a string from a time tuple.
* time.strptime - produces a time tuple from a string.
* time.sleep - helps you introduce delays in your python programs. 

The POSIX sleep accepts only the seconds delay, i.e. the integer value, but
Python version accepts float and allows for sub-second delays.


* The `datetime` module provides better abstractions to deal with dates and
  times.

Basic datetime handling method
------------------------------
.. literalinclude:: py31/howto11_datatime_basic.py


::

        >>> today = datetime.date.today()
        >>> print(today)
        2010-02-10
        >>> birthday = datetime.date(1987,3,9)
        >>> print(birthday)
        1987-03-09
        >>> currenttime = datetime.datetime.now().time()
        >>> lunchtime = datetime.time(13,00)
        >>> now = datetime.datetime.now()
        >>> epoch = datetime.datetime(1970,1,1)
        >>> meeting = datetime.datetime(2010,2,17,15,30)
        >>> print(meeting)
        2010-02-17 15:30:00


* Parse the RFC 1123 date format: Thu, 01 Dec 1994 16:00:00 GMT

::

        >>> datereturned = "Thu, 01 Dec 1994 16:00:00 GMT"
        >>> dateexpired = "Sun, 05 Aug 2007 03:25:42 GMT"
        >>> obj1 = datetime.datetime(*time.strptime(datereturned, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
        >>> obj2 = datetime.datetime(*time.strptime(dateexpired, "%a, %d %b %Y %H:%M:%S %Z")[0:6])
        >>> if obj1 == obj2:
                print "Equal"
            elif obj1 > obj2:
                print datereturned
            elif obj1 < obj2:
                print dateexpired

* The datetime objects are immutable. Useful when using in sets and
  dictionaries.

::

        >>> today = datetime.date.today()
        >>> next_year = today.replace(year=today.year+1)
        SyntaxError: invalid syntax
        >>> print(next_year)
        2011-02-10

* dateutil and mxDatetime are two third party utils that are worth looking at
  too.
