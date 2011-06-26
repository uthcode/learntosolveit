"""
Simple implementation of a Queue datastructure in Python.
"""
class Queue:
    def __init__(self, items = None):
        if items is None:
            items = []
        self.__queue = items

    def __repr__(self):
        return str(self.__queue)

    def isempty(self):
        return len(self.__queue) == 0

    def enqueue(self, item):
        self.__queue.append(item)

    def dequeue(self):
        return self.__queue.pop(0)

    def peek(self):
        return self.__queue[0]

if __name__ == '__main__':
    q = Queue()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)
    q.enqueue(40)
    print q
    print q.peek()
    q.dequeue()
    print q
