class RestrictingWrapper(object):
    def __init__(self, obj, to_block):
        self._obj = obj
        self._to_block = to_block

    def __getattr__(self, name):
        if name in self._to_block:
            raise AttributeError(name)
        return getattr(self._obj, name)

class Foo(object):
    def __init__(self, x, y, z):
        self.x, self.y, self.z = x, y, z

f1 = Foo(1, 2, 3)
print(f1.x, f1.y, f1.z)

f2 = RestrictingWrapper(f1, "z")
print(f2.x, f2.y)
print(f2.z)
