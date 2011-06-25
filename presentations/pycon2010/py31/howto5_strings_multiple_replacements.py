#!/usr/bin/env python3.1

"""
Source: Python Cookbook Recipe 1.18
Credits: Xavier Defrang, Alex Martelli

"""

import re

def multiple_replace(text, adict):
    rx = re.compile('|'.join(map(re.escape, adict)))
    def one_xlat(match):
        return adict[match.group(0)]
    return rx.sub(one_xlat, text)

# Closure based approach
def make_xlat(*args, **kwds):
    adict = dict(*args, **kwds)
    rx = re.compile('|'.join(map(re.escape, adict)))
    def one_xlat(match):
        return adict[match.group(0)]
    def xlat(text):
        return rx.sub(one_xlat, text)
    return xlat

if __name__ == "__main__":
    text = "Larry Wall is the creator of the Perl"
    adict = {
        "Larry Wall":"Guido van Rossum",
        "creator":"Benevolent Dictator for Life",
        "Perl":"Python",
    }
    print(multiple_replace(text, adict))
    translate = make_xlat(adict)
    print(translate(text))
