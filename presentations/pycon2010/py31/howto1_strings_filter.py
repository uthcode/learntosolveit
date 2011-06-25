#!/usr/bin/env python3.1

class Keeper(object):
    def __init__(self, keep):
        self.keep = set(map(ord, keep))

    def __getitem__(self, n):
        if n not in self.keep:
            return None
        return chr(n)

    def __call__(self, s):
        return str(s).translate(self)

makefilter = Keeper

if __name__ == '__main__':
    just_vowels_and_maths = makefilter('aeiouy∇∂')
    print(just_vowels_and_maths('∇something about strings∂'))
