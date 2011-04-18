#!/usr/bin/python
#$Id$

"""
Given an integer, covert to binary and convert to octal.

>>> b,o = binoct(42)
>>> b, o
('101010', '52')
>>> b, o = binoct(242)
>>> b, o
('11110010', '362')
>>> b, o = binoct(424)
>>> b, o
('110101000', '650')
>>> b, o = binoct(1000000000)
>>> b, o
('111011100110101100101000000000', '7346545000')
"""

def binoct(x):
    num = int(x)
    binary = bin(num)
    octal = oct(num)
    return binary.lstrip('0b'), octal.lstrip('0')
