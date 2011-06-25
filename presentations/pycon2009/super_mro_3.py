class A(object):
    def __init__(self):
        print "A init"

class B(A):
    def __init__(self):
        print "B init"
        super(B, self).__init__()

class C(A):
    def __init__(self):
        print "C init"
        super(C, self).__init__()

class D(B,C):
    def __init__(self):
        print "D init"
        super(D, self).__init__()

obj = D()
