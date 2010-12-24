#!/usr/bin/env python
# -*- coding: utf-8 -*-
# written by kennenth gonsalves

import codecs

def countsyll(instring):
    """This function counts the number of characters in a tamil string
        This is done by ignoring the vowel additions. If one uses the len
        function, the sample string has a length of 17 - but there are actually
        only 11 characters"""
    s = codecs.utf_8_encode(instring)
    print s
    x = codecs.utf_8_decode(s[0])[0]    
    print repr(x)
    syllen = 0
    vowels = [u'\u0bbe',u'\u0bbf',u'\u0bc0',
                u'\u0bc1',u'\u0bc2',u'\u0bc6',
                u'\u0bc7',u'\u0bc8',u'\u0bca',
                u'\u0bcb',u'\u0bcc',u'\u0bcd',]
    for y in x:
        if y not in vowels:
            syllen += 1    
    return syllen

if __name__=='__main__':
    print countsyll(u'ஆண்டவரின் துணைவன்')
