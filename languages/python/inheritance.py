class A(object):
    def __init__(self):
        print("A is called.")

class B(object):
    def __init__(self):
        print("B is called.")

class C(A, B):
    def __init__(self):
        super(C, self).__init__()

c = C()
