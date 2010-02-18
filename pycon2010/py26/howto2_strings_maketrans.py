#!/usr/bin/env python2.6

import string

def translator(frm='', to='', delete='', keep=None):
    if len(to) == 1:
        to = to * len(frm)
    trans = string.maketrans(frm, to)
    if keep is not None:
        allchars = string.maketrans('','')
        delete = allchars.translate(allchars, keep.translate(allchars, delete))
    def translate(s):
        return s.translate(trans, delete)
    return translate

digits_only = translator(keep=string.digits)
print digits_only('Senthil - 007')

chars_only = translator(delete=string.digits)
print chars_only('Senthil - 007')
