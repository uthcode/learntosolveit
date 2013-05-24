class Test:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    def run(self):
        print "hello"

def something(a, b):
    return Test(a, b)

a = something(10, 20)
a.run()

something(10,20).run()
