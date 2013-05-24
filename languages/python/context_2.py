from contextlib import contextmanager

@contextmanager
def somefun():
    yield "something"

with somefun() as f:
    print f
