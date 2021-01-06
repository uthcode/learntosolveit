
# Override access to one variable in a class, but return all others normally

class D(object):
    def __init__(self):
        self.test = 20
        self.test2 = 40
    def __getattribute__(self, name):
        if name == 'test':
            return 0
        else:
            return self.__dict__[name]

# The above wont work.
# This will give
# RuntimeError: maximum recursion depth exceeded in cmp
# Look at getattribute_example2.py for correct solution.

obj1 = D()
print(obj1.test)
print(obj1.test2)

