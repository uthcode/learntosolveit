#!/usr/bin/python

def my_decorator(fun):
    def wrapper(*args):
        print("Before Invocation")
        fun(*args)
        print("After Invocation")
    return wrapper

@my_decorator
def hello_world(x):
    print("Hello, World")
    print(x)

hello_world(10)
