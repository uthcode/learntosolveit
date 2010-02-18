#!/usr/bin/env python2.6
#-*- coding:utf-8 -*- 

class Keeper(object):
    def __init__(self, keep):
        self.keep = set(map(ord, keep))

    def __getitem__(self, n):
        if n not in self.keep:
            return None
        return unichr(n)

    def __call__(self, s):
        return unicode(s).translate(self)

makefilter = Keeper

if __name__ == '__main__':
    just_vowels_and_maths = makefilter(u'aeiouy∇∂')
    print just_vowels_and_maths(u'∇something about strings∂')
