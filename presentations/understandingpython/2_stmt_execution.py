import pudb
pudb.set_trace()
class Myclass(object):

    def __init__(self, arg):

        self.attr = arg

    def method(self):

        return "hello, world"


myobj = Myclass(42)
print myobj.attr
print myobj.method()
