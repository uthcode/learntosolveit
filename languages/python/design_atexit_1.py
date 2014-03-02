import atexit

def foo():
    print "foo"

class SomeClass(object):

    def __init__(self):
        self.a = 10
        self.b = 20
        atexit.register(foo)

obj = SomeClass()
print obj.a
print obj.b
