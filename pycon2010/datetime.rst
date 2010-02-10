Date and time related
=====================

RFC 1123 date format:
Thu, 01 Dec 1994 16:00:00 GMT

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

Efficient Strategies for handling date and time related tasks
-------------------------------------------------------------

datetime module and time module
-------------------------------

calculating time periods in a date range
----------------------------------------
