Python3
-------

Python3 does not break backwards compatibility on a whim, but there were
certain warts in the language, which Guido wanted to correct.

Also, it does not give you a picture, that Python 3 exists because "Guido
wanted it that way or want to fix some mistakes". People throwing this argument
will definitely not be able to convince many folks to use Python 3. Instead it
portrays in a nice way as how the old python had its strong roots in C, and as
Python matured as a language, useful for writing frameworks and being used by
framework authors for various different purposes, it needs some good features
and needs to adopt from other major languages such as Java or C#.

Here are some important points from that.

1. Change in print stmt is acknowledged. (I have got used to writing print() as of 2011)
2. Layered IO. Explains how it mimics Java's IO to certain extent.
3. String formatting features. I really did not know that it was inspired from .Net framework. News to me.
4. Function annotations - And a way to write contract style programming using
function annotations and decorators. I shall write an example in the next post.
5. metaclass using metaclass keyword and does its processing before the class
definition execution as opposed later.
6. Unicode handling - Yes, the 'bite of python3'.

The article mentions that handling of Unicode is forced upon the programmer who
never had to deal with it so far. This is true. I hope when major frameworks
start using Python3, this gets abstracted away or rather we learn as how Java
crowd does it without any fuss.

As it was written during 3.0 release, it had written about IO layer being slow
as major drawback, this is no longer a case, where 3.1 had IO written in C and
is fast again.

On whole, it is really a good one to give a comprehensive and an objective
'Introduction to Python3'.
