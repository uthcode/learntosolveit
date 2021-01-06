"""
A Simple Example of closure in python
A closure is function which returns another function. For example, the
``constant`` function here returns, ``_inner`` function. At the top level you
passed the value and calling the inner function from within, it is not required
to send the value.
"""
def constant(value):
    def sq(x):
        return x*x

    def _inner():
        return sq(value)
    return _inner

x = constant(5)
print((x()))
