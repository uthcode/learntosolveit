#!/usr/bin/python
# Best Example of Decorator

def my_decorator(arg1, arg2):
    def wrap(f):
        print "Inside wrap"
        f(arg1, arg2)
        def wrapper(*args):
            print "Before Invocation"
            f(*args)
            print "After Invocation"
        return wrapper
    return wrap

@my_decorator(10, 20)
def hello_world(x, y):
    print "Hello, World"
    print x, y

hello_world(10, 20)

