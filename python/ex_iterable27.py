#!/usr/bin/python

class IterableObject(object):
    """A Simple example of object iteration in Python."""
    def __init__(self):
        self.obj_data = []

    def __iter__(self):
        for data_item in self.obj_data:
            yield data_item


class Something(IterableObject):
    def __init__(self):
        self.obj_data = ["one", "two", "three", "four", "five"]


if __name__ == '__main__':
    something = Something()
    for i in something:
        print (i)
