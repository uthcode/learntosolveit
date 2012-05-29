Unicode Notes
-------------

A good introductory document for getting started with Unicode is, 
`Joel's article on Unicode`_

Trivia: In ASCII when you press CNTL, you subtract 64 from the value of the
next character.  So BELL is ASCII 7, which is CNTL+G, (CNTL is 64) and G is
71.

IN ASCII, the Codes below 32 were called unprintable. The space was 32 and
letter A was 65.  This could conveniently be stored in 7 bits.  Most computers
in those days were using 8 bit bytes, so not only you could store all the ASCII
characters, you had a whole bit to spare.  Because bytes have room for upto
eight bits, lots of people got into thinking, "gosh, we can use codes 128-255
for our own purposes." :) Eventually, this OEM free-for-all got codified in the
ANSI standard.  In the ANSI standard, everyone agreed for bottom 128 but not
the upper limits.  Asian alphabets have thousands of letters, which were never
going to fit into 8 bits.  This was actually solved by a messy system called
DBCS, the "double byte character set" in which some letters were stored in one
byte and others took two bytes.It was easy to move forward in a string, but it
was impossible to move backwards in the string.  Programmers were encouraged
not to use s++ or s-- but instead rely on Windows' AnsiNext and AnsiPrev
functions which knew how to deal with that mess.

**Unicode**

Unicode was a brave effort to create a single character set that included every
reasonable writing system on the planet.  Some people are under the
mis-conception that unicode is simply a 16-bit code where each character takes
16 bits and therefore there are 65,536 possible characters, which is incorrect.

In Unicode, every alphabet is assigned a magic number by the Unicode consortium
which is written like this: U+0639. This number is called the code-point. The
U+ means "Unicode" and the numbers are in hexadecimal notation. U+0639 is the
arabic letter Ain (ع).

There is no real limit on the number of letters that Unicode can define and in
fact, they have gone beyond 65,536 so not every unicode letter can really be
squeezed into two bytes. That was a myth anyways.

OK, so we have a string: Hello which, in Unicode, corresponds to these five
code-points: U+0048 U+0065 U+006C U+006C U+006F 

It was U- before 3.0 and then it became U+. If you look at the release notes of
Unicode 3.0, you might find the reason for the change.

How do we store those numbers?  That is where encoding comes in.

The earliest idea was, that to store the numbers in two bytes each:

	00 48 00 65 00 6C 00 6C 00 6F.

Why not it be stored like this:

	48 00 65 00 6C 00 6C 00 6F 00

Well, it could be stored in that way too. Early implementors wanted to store
the numbers in either big-endian or little-endian, in whichever way their
particular CPU  was fastest at. So, people came up with Byte Order Mark, where
FEFF denoted Little Endian and FFFE denoted big endian.

FEFF - Little Endian
FFFE - Big Endian

*nmemonic - Three F's together is BIG.*

For a while, it seemed like that might be good enough, but programmers were
complaining. "Look at all those zeros!", they said, since they were Americans
and they were looking at English text which rarely used code points above
U+OOFF.  People decided to ignore Unicode and things got worse.  And thus was
invented the brilliant concept of UTF-8. (Read Rob Pike's mail)

In UTF-8, every code point from 0-127 is stored in a single byte. Only code
points 128 and above are stored using 2, 3, in fact upto 6 bytes.  This has the
neat side-effect that English text looks exactly the same in UTF-8 as it did in
ASCII, so Americans don't even notice anything wrong.  Specifically, Hello
which was "0048, 0065, 006C, 006C and 006F" would simply be stored as
48,65,6C,6C and 6F.

So, here we have ways such as UCS-2 (UTF-16), which had its own UCS-2 little
endian or UCS-2 big endian and then UTF-8 encoding method.  There are also a
bunch of other ways of encoding Unicode. There is something called UTF-7, which
is lot like UTF-8 but guarantees that the high bit will always be zero.  It was
for systems which can recognize only 7 bits. UCS-4 which stores each code point
in 4 bytes, which has a nice property that every single code point can be
stored in same number of bytes. But that is memory hungry.

There are hundreds of traditional encodings, which can only store some
code-points correctly and change all other code points into question marks.
Some popular encodings of the English text are, Windows 1252 and ISO-8859-1,
aka Latin-1 (also useful for any western european languages). But try to store
Russian, or Hebrew letters in those encodings and you will get a bunch of
question marks. UTF 7, UTF 8, UTF 16 and UTF 32 all have the nice property of
being able to store any code point correctly.

If you have a string in memory, in a file, or in an email message, you have to
know what encoding it is in or you cannot interpret it or display to your users
correctly.  All the problems of ????, comes down to the fact that if you don't
tell me whether a particular string is encoded using UTF-8 or ASCII or ISO
8859-1 (Latin 1) or Western 1252 (Western European), you simply cannot display
it correctly or even figure it out where it actually ends.  There are over 100
encodings, and above code point 127, all the bets are off.

How do we preserve this information about what encoding a string uses?  Email,
Content-Type: text/plain; charset="UTF-8" For a web page, the original idea was
that the web server would return a similar Content-Type http header along with
the web page itself -- not in the HTML itself, but as one of the response
headers that are sent before the HTML page.

Relying on webserver to send Content-Type was problematic, because many
different people could use the same web-server for different types of web
pages.  It would be convenient, if you could put the Content-Type of the HTML
file right in the HTML file itself, using some kind of a special tag.  All
encoding uses same character between 32 and 127, so you could get to the point
wherein you could read the <meta> header.

The RFC which explains UTF-8::

        http://www.ietf.org/rfc/rfc3629.txt

        The most interesting part of the RFC, which is leading me to understand the
        system better is explained here:

           The table below summarizes the format of these different octet types.
           The letter x indicates bits available for encoding bits of the
           character number.

           Char. number range  |        UTF-8 octet sequence
              (hexadecimal)    |              (binary)
           --------------------+---------------------------------------------
           0000 0000-0000 007F | 0xxxxxxx
           0000 0080-0000 07FF | 110xxxxx 10xxxxxx
           0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
           0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

           Encoding a character to UTF-8 proceeds as follows:

           1.  Determine the number of octets required from the character number
               and the first column of the table above.  It is important to note
               that the rows of the table are mutually exclusive, i.e., there is
               only one valid way to encode a given character.

           2.  Prepare the high-order bits of the octets as per the second
               column of the table.

           3.  Fill in the bits marked x from the bits of the character number,
               expressed in binary.  Start by putting the lowest-order bit of
               the character number in the lowest-order position of the last
               octet of the sequence, then put the next higher-order bit of the
               character number in the next higher-order position of that octet,
               etc.  When the x bits of the last octet are filled in, move on to
               the next to last octet, then to the preceding one, etc. until all
               x bits are filled in.

           The definition of UTF-8 prohibits encoding character numbers between
           U+D800 and U+DFFF, which are reserved for use with the UTF-16
           encoding form (as surrogate pairs) and do not directly represent
           characters.  When encoding in UTF-8 from UTF-16 data, it is necessary
           to first decode the UTF-16 data to obtain character numbers, which
           are then encoded in UTF-8 as described above.  This contrasts with
           CESU-8 [CESU-8], which is a UTF-8-like encoding that is not meant for
           use on the Internet.  CESU-8 operates similarly to UTF-8 but encodes
           the UTF-16 code values (16-bit quantities) instead of the character
           number (code point).  This leads to different results for character
           numbers above 0xFFFF; the CESU-8 encoding of those characters is NOT
           valid UTF-8.

           Decoding a UTF-8 character proceeds as follows:

           1.  Initialize a binary number with all bits set to 0.  Up to 21 bits
               may be needed.

           2.  Determine which bits encode the character number from the number
               of octets in the sequence and the second column of the table
               above (the bits marked x).

           3.  Distribute the bits from the sequence to the binary number, first
               the lower-order bits from the last octet of the sequence and
               proceeding to the left until no x bits are left.  The binary
               number is now equal to the character number.

           Implementations of the decoding algorithm above MUST protect against
           decoding invalid sequences.  For instance, a naive implementation may
           decode the overlong UTF-8 sequence C0 80 into the character U+0000,
           or the surrogate pair ED A1 8C ED BE B4 into U+233B4.  Decoding
           invalid sequences may have security consequences or cause other
           problems.  See Security Considerations (Section 10) below.

        4.  Syntax of UTF-8 Byte Sequences

           For the convenience of implementors using ABNF, a definition of UTF-8
           in ABNF syntax is given here.

           A UTF-8 string is a sequence of octets representing a sequence of UCS
           characters.  An octet sequence is valid UTF-8 only if it matches the
           following syntax, which is derived from the rules for encoding UTF-8
           and is expressed in the ABNF of [RFC2234].

           UTF8-octets = \*( UTF8-char )
           UTF8-char   = UTF8-1 / UTF8-2 / UTF8-3 / UTF8-4
           UTF8-1      = %x00-7F
           UTF8-2      = %xC2-DF UTF8-tail
           UTF8-3      = %xE0 %xA0-BF UTF8-tail / %xE1-EC 2( UTF8-tail )/ 
                         %xED %x80-9F UTF8-tail / %xEE-EF 2( UTF8-tail )
           UTF8-4      = %xF0 %x90-BF 2( UTF8-tail ) / %xF1-F3 3( UTF8-tail )/
                         %xF4 %x80-8F 2( UTF8-tail )
           UTF8-tail   = %x80-BF

           NOTE -- The authoritative definition of UTF-8 is in [UNICODE].  This
           grammar is believed to describe the same thing Unicode describes, but
           does not claim to be authoritative.  Implementors are urged to rely
           on the authoritative source, rather than on this ABNF.


The official name of the encoding is UTF-8, where UTF stands for UCS
Transformation Format 8.  Write it as UTF-8 only.  There is no limit on the
number of the characters that Unicode could define.  and it has definiely
exceeded beyond, 65536 characters.

Exercise 1:

Convert the following to Unicode:
1) "Hello, World"
2) नमसूऐर दुनयि॥

Answer:

1)"Hello, World" is present in 

U0000 and U+0048 U+0065 U+006C U+006C U+006F U+002C U+0057 U+006F U+0072 U+006C
U+0064

2) नमसूऐर दुनयि॥

Is the devnagari script that starts with U0900 U+0928 U+092E U+0938 U+0942
U+0915 U+090 U+0930 U+0926 U+0941 U+0928 U+092F U+093F U+0965

The above was just a bunch of code points. We have not said anything about how
to store them in memory or represent them in email messages yet.

Encodings

English meaning of encoding is is wrapping it in a cipher code.  The earlier
method was to store those codepoints which are 4 hexadecimal digits as 2 bytes.

Convert Unicode to Hexadecimals::
http://ln.hixie.ch/?start=1064324988&count=1

Typing Unicode and maths symbols on gnome-terminal

1) Hold CTRL+SHIFT + U + codepoint + SPACE
2) For e.g. CTRL+SHIFT+U+2201+SPACE will give Unicode Maths Symbol 

Unicode code point chart:
http://inamidst.com/stuff/unidata/

Unicode objects by Fredrik Lundh
http://effbot.org/zone/unicode-objects.htm

.. _Joel's article on Unicode: http://www.joelonsoftware.com/articles/Unicode.html 
