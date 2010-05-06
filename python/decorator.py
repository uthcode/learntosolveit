#!/usr/bin/python
# Best Example of Decorator

def my_decorator(fun):
    def wrapper(*args):
        print "Before Invocation"
        fun(*args)
        print "After Invocation"
    return wrapper

@my_decorator
def hello_world():
    print "Hello, World"

hello_world()
