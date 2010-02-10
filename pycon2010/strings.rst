Let's start with strings
========================

The main tool Python gives us to process text is strings - immutable sequence
of characters.In Python2, there are two kinds of strings: plain strings, which
contain 8-bit (ASCII) characters; and Unicode Strings, which contain Unicode
characters.In Python3, there is only one string - which is unicode string.
Strings are immutable, which means that no matter what operations you do on a
string, you will always produce a new string object, rather than mutating the
existing string. In general, you can do anything to a string that you can do to
any other sequence, as long as it doesn't require changing the sequence, since
the strings are immutable.

:: 
	list_of_lines = one_large.string.splitlines()
	one_large_string = '\n'.join(list_of_lines)


Characters of a string.

::
	list("python")
	map(somefunc,"python")
	map(lambda x:x,"python")
	sets.Set("python")

Reversing

For sequences, the extended slicing with negative step can be used for
reversing. [::-1] There is reversed built-in function which can also be used
for reversing the words in a sentence.  But for reversing the characters in a
string, if reversed is used, then a ''.join needs to be called.  The reversed
returns an iterator, suitable for looping on or for passing to some
"accumulator" callable such as ''.join. It does not return a ready made string.

string functions

string.translate(s, table[, deletechars])

   Delete all characters from *s* that are in *deletechars* (if
   present), and then translate the characters using *table*, which
   must be a 256-character string giving the translation for each
   character value, indexed by its ordinal.  If *table* is ``None``,
   then only the character deletion step is performed.

string.maketrans(from, to)

   Return a translation table suitable for passing to ``translate()``,
   that will map each character in *from* into the character at the
   same position in *to*; *from* and *to* must have the same length.

   Note: Don't use strings derived from ``lowercase`` and ``uppercase`` as
     arguments; in some locales, these don't have the same length.
     For case conversions, always use ``str.lower()`` and
     ``str.upper()``.

:: 

   >>> from string import Template
   >>> s = Template('$who likes $what')
   >>> s.substitute(who='tim', what='kung pao')
   'tim likes kung pao'
   >>> d = dict(who='tim')
   >>> Template('Give $who $100').substitute(d)
   Traceback (most recent call last):
   [...]
   ValueError: Invalid placeholder in string: line 1, col 10
   >>> Template('$who likes $what').substitute(d)
   Traceback (most recent call last):
   [...]
   KeyError: 'what'
   >>> Template('$who likes $what').safe_substitute(d)
   'tim likes $what'


+---------+-----------------------------+---------------------------------------------+
| builtin |  *python2*                  |  *python3*                                  |
+=========+=============================+=============================================+
| repr    |   obj to str                |   obj to str                                |
+---------+-----------------------------+---------------------------------------------+
| ord     |   c to int                  |   c to int, valid surrogate pair accepted.  |
+---------+-----------------------------+---------------------------------------------+
| chr     |   i to c, 0 <= i < 256,     |   i to u , 0 <= i < 0x10ffff                |
+---------+-----------------------------+---------------------------------------------+
| unichr  |   i to u, 0 <= i < 0x10ffff |      NA                                     |
+---------+-----------------------------+---------------------------------------------+

string, unicode string, bytes, bytestring
-----------------------------------------

Strings are sequence of characters (ascii in python2 and unicode - python3),
e.g. an HTML Document.Bytes are not characters an JPEG Document.

A general rule of thumb is Bytesting contains encoded data and a unicode
object contains unencoded data.

*bytes object have a decode() method that takes a character encoding and returns a string.*

*string object has a encode method that takes a a character encoding and returns a bytes object.*

Python 2.0 had strings and Unicode Strings.
Python 3.0 has strings. That is it.But you wont miss 8 bit strings which acted
as bytes in python2, because there is a separate bytes datatype.

String filters
--------------

Translate and maketrans function
--------------------------------

Expanding and Compression of Tabs
---------------------------------

Multiple Replacements in Single Pass
------------------------------------

Reading a Text file by Paragraphs
---------------------------------
