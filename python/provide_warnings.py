from functools import wraps
from warnings import warn

def add_warning(func, oldname):
    @wraps(func)
    def _wrapped(*args, **kwds):
        warn('Deprecated function %s being called' % oldname)
        return func(*args, **kwds)
    return _wrapped

def test(a=2, b=4):
    print a + b

old_test = add_warning(test, 'old_test')

old_test(123)
