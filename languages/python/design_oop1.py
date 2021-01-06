class C:
    def __init__(self):
        self.c = 42

class A(C):
    def __init__(self):
        self.a = 100

class B(C,A):
    def __init__(self):
        self.b = 200
        C.__init__(self)
        A.__init__(self)

    def meth(self):
        print(self.b, self.a, self.c)
    def meth1(self,v):
        self.a = v

obj = B()
obj.meth()
obj.meth1(300)
obj.meth()
