senthil@kevin:~$ python3 
Python 3.3a0 (default:979ae5972604+, Mar 19 2011, 11:42:31) 
[GCC 4.4.5] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> print("€")
€
[57971 refs]
>>> print(hex(ord("€")))
0x20ac
[57973 refs]
>>> print("\N{bengali digit one}")
১
[58110 refs]
>>> print(hex(ord("\N{bengali digit one}")))
0x9e7
[58110 refs]
>>> print("\N{circled digit six}66")
⑥66
[58110 refs]
>>> x = _
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name '_' is not defined
[58137 refs]
>>> x = "\N{circled digit six}66"
[58139 refs]
>>> x.isdigit()
True
[58144 refs]
>>> int(x) * 10
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
ValueError: invalid literal for int() with base 10: '⑥66'
[58146 refs]
>>> 

