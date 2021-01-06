"""
Implementation of stack data structure in Python.
"""

class Stack:
    def __init__(self,*vargs):
        self.stack = list(vargs)

    def __repr__(self):
        return str(self.stack)

    def top(self):
        return self.stack[0]

    def push(self,elem):
        self.stack.insert(0,elem)

    def pop(self):
        return self.stack.pop(0)


if __name__ == '__main__':
    stk = Stack(1,2,3,4)
    print(stk)
    print(stk.top())
    stk.push(10)
    print(stk)
    print(stk.pop())
    print(stk)
