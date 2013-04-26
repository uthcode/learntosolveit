class Some(object):
    def __init__(self):
        self.a = 10
    def foo(self, obj):
        print(obj.a)
    def bar(self):
        self.foo(self)
obj = Some()
obj.bar()
