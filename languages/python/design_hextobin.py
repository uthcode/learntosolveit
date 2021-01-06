from functools import partial

hexbin = partial(int, base=16)
print((bin(hexbin("FFFF"))))