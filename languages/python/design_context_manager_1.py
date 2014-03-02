"""
This is a  simple example of a context manager. The context manager is
implemented by a decorator provided by the contextlib module.
You will see that tag will yield after the first print statement and as it a
contextmanager, it is resumed after the __exit__ call, which is called by
default when the with statement falls out of scope and in that case, the next
print statement is called.

This outputs:
    <h1>
        foo
     </h1>
"""

from contextlib import contextmanager

@contextmanager
def tag(name):
    print "<%s>" % name
    yield
    print "</%s>" % name

with tag("h1"):
    print "foo"
