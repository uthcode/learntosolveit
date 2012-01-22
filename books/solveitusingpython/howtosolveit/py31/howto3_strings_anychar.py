#!/usr/bin/env python3.1

import string

def containsAny(seq, aset):
    for c in seq:
        if c in aset: return True
    return False


def containsAny_itertoolsway(seq, aset):
    for item in filter(aset.__contains__, seq):
        return True
    return False

print(containsAny('916',string.digits))
print(containsAny_itertoolsway('916',string.digits))
