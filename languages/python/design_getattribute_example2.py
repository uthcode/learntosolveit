
# Override access to one variable in a class, but return all others normally
# http://stackoverflow.com/a/371833/18852

class D(object):
    def __init__(self):
        self.test = 20
        self.test2 = 40
    def __getattribute__(self, name):
        if name == 'test':
            return 0
        else:
            return object.__getattribute__(self, name)

obj1 = D()
print(obj1.test)
print(obj1.test2)
