#!/usr/bin/env python3.1

import string

def translator(frm=b'', to=b'', delete=b'', keep=None):
    if len(to) == 1:
        to = to * len(frm)
    trans = bytes.maketrans(frm, to)
    if keep is not None:
        allchars = bytes.maketrans(b'',b'')
        delete = allchars.translate(allchars, keep.translate(allchars, delete))
    def translate(s):
        return s.translate(trans, delete)
    return translate

digits_only = translator(keep=bytes(string.digits,'utf-8'))
print(str(digits_only(b'Senthil - 007'),'utf-8'))

chars_only = translator(delete=bytes(string.digits,'utf-8'))
print(str(chars_only(b'Senthil - 007'),'utf-8'))
