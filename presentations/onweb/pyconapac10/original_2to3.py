#!/usr/bin/python
	# comment indented by tab

"""Docstring.

Here are some doctest exampes:

>>> print 42
42

 >>> d = {1: 1, 2: 2, 2: 2}
 >>> d.keys().sort()
 >>> print d
 {1: 1, 2: 2}

  >>> for i in d.keys():
  ...     print i, d[i]

And a tricky one:

>>> class X(Structure):
...     _fields_ = [("x", c_int), ("y", c_int), ("array", c_char_p * 5)]
...
>>> x = X()
>>> print x._objects
None
>>>

"""

import sys

def unicode_examples():
    a = str(b)
    a = "xxx"
    a = """xxx"""
    a = r'xxx'
    a = R'''xxx'''
    a = r"xxx"
    a = R"""xxx"""
    b = "..." '...'

def ne_examples():
    if x != y:
        pass
    if x!=y:
        pass
    if x!=y!=z:
        pass

def has_key_examples():
    #
    x = "x" in d or "y" in d
    #
    x = ("x" in a.b.c.d) ** 3
    #
    x = (1 + 2 in a.b).__repr__()
    #
    x = (1 + 2 in a.b).__repr__() ** -3 ** 4
    #
    x = (f or g) in a
    #
    x = a + (c in b)
    #
    x = (lambda: 12) in a
    #
    x = (a for a in b) in a
    #
    if b not in a: pass
    #
    if not (b in a).__repr__(): pass
    #
    if not (b in a) ** 2: pass

def foo():
	pass # body indented by tab

def test_ws_comma():
    yield 1,2 ,3
    f(1,2 ,3)
    repr((a ,b))
    def f(a,b ,c): pass
    { a:b,c:d , e : f }

def apply_examples():
    x = f(*g + h)
    y = f(*g, **h)
    z = fs[0](*g or h, **h or g)
    # Hello
    f(*(x, y) + t)
    f(*args)
    f(*args, **kwds)
    # Test that complex functions are parenthesized
    x = (f+g)(*args)
    x = (f*g)(*args)
    x = (f**g)(*args)
    # But dotted names etc. not
    x = f.g(*args)
    x = f[x](*args)
    x = f()(*args)
    # Extreme case
    x = a.b.c.d.e.f(*args, **kwds)
    # XXX Comments in weird places still get lost
    f(*args)

def bad_apply_examples():
    # These should *not* be touched
    apply()
    apply(f)
    apply(f,)
    apply(f, args, kwds, extras)
    apply(f, *args, **kwds)
    apply(f, *args)
    apply(func=f, args=args, kwds=kwds)
    apply(f, args=args, kwds=kwds)
    apply(f, args, kwds=kwds)

def metaclass_examples():
    class X(metaclass=Meta):
        pass

    class X(b1, b2, metaclass=Meta):
        bar = 23 # Comment on me!
        spam = 27.23 # Laughable

    class X(metaclass=Meta):
        x = 23; y = 34 # Yes, I can handle this, too.

def intern_examples():
    #
    # These should be refactored:
    #
    x = sys.intern(a)
    #
    y = sys.intern("b" # test
              )
    #
    z = sys.intern(a+b+c.d,)
    #
    sys.intern("y%s" % 5).replace("y", "")
    #
    # These not:
    #
    intern(a=1)
    #
    intern(f, g)
    #
    intern(*h)
    #
    intern(**i)

def print_examples():
    # plain vanilla
    print(1, 1+1, 1+1+1)
    #
    print(1, 2)
    #
    print(1)

    print()

    # trailing commas
    print(1, 2, 3, end=' ')
    #
    print(1, 2, end=' ')
    #
    print(1, end=' ')
    #
    print()

    # >> stuff
    print(1, 2, 3, file=sys.stderr)    # no trailing comma
    #
    print(1, 2, end=' ', file=sys.stdder)      # trailing comma
    #
    print(1+1, file=sys.stderr)        # no trailing comma
    #
    print(file=sys.stderr)           # spaces before sys.stderr

def exec_examples():
    #
    exec(code)
    #
    exec(code, ns)
    #
    exec(code, ns1, ns2)
    #
    exec((a.b()), ns)
    #
    exec(a.b() + c, ns)
    #
    # These should not be touched:
    #
    exec(code)
    #
    exec (code)
    #
    exec(code, ns)
    #
    exec(code, ns1, ns2)

def repr_examples():
    x = repr(1 + 2)
    #
    y = repr(x)
    #
    z = repr(y).__repr__()
    #
    x = repr((1, 2, 3))
    #
    x = repr(1 + repr(2))
    #
    x = repr((1, 2 + repr((3, 4))))

def except_examples():
    try:
        pass
    except Exception as xxx_todo_changeme:
        (f, e) = xxx_todo_changeme.args
        pass
    except ImportError as e:
        print(e.args)
    #
    try:
        pass
    except (RuntimeError, ImportError) as e:
        pass
    #
    try:
        pass
    except Exception as xxx_todo_changeme1:
        (a, b) = xxx_todo_changeme1.args
        pass
    #
    try:
        pass
    except Exception as xxx_todo_changeme2:
        d[5] = xxx_todo_changeme2
        pass
    #
    try:
        pass
    except Exception as xxx_todo_changeme3:
        a.foo = xxx_todo_changeme3
        pass
    #
    try:
        pass
    except Exception as xxx_todo_changeme4:
        a().foo = xxx_todo_changeme4
        pass
    #
    # These should not be touched:
    #
    try:
        pass
    except:
        pass
    #
    try:
        pass
    except Exception:
        pass
    #
    try:
        pass
    except (Exception, SystemExit):
        pass

def raise_examples():
    raise Exception(5)
    #
    raise Exception(5)
    #
    raise Exception(5, 6, 7)
    #
    # These should not be touched
    #
    raise Exception
    #
    raise Exception(5, 6)
    #
    # These should produce a warning
    # TODO: convert "raise E, V, T" to
    #  "e = E(V); e.__traceback__ = T; raise e;"
    #
    raise Exception(5).with_traceback(6)
    #
    raise Exception(5).with_traceback(6)
    #
    raise Exception(5, 6, 7).with_traceback(6)

def long_examples():
    x = int(x)
    y = isinstance(x, int)
    z = type(x) in (int, int)
    a = 12
    b = 0x12
    # unchanged:
    a = 12
    b = 0x12
    c = 3.14

def dict_examples():
    #
    # Plain method calls
    #
    print(list(d.keys()))
    print(list(d.items()))
    print(list(d.values()))
    #
    # Plain method calls in special contexts
    #
    print(iter(list(e.keys())))
    for i in list(e.keys()): print(i)
    [i for i in list(e.keys())]
    (i for i in list(e.keys()))
    #
    # Iterator method calls
    #
    print(iter(f.keys()))
    print(iter(f.items()))
    print(iter(f.values()))
    #
    # Iterator method calls in special contexts
    #
    print(list(g.keys()))
    print(sorted(g.keys()))
    print(iter(g.keys()))
    for i in g.keys(): print(i)
    [i for i in g.keys()]
    (i for i in g.keys())
    #
    # Examples with a "tail"; these are never "special"
    #
    print(next(h.iterkeys()))
    print(list(h.keys())[0])
    print(list(next(h.iterkeys())))
    for x in list(h.keys())[0]: print(x)

def dict_negative_examples():
    #
    # These should all remain unchanged:
    #
    print(list(h.keys()))
    print(sorted(h.keys()))

def xrange_examples():
    for i in range(100): print(i)
    for i in range(0, 100): print(i)
    for i in range(0, 100, 10): print(i)

def input_examples():
    a = eval(input())
    b = eval(input(str(a)))

def raw_input_examples():
    a = input()
    b = input(a.rstrip())

def filter_examples():
    list(filter(os.unlink, filenames))
    [_f for _f in "whatever" if _f]
    [x for x in list(range(4)) if not x]

def map_examples():
    list(map(None, foo.bar))
    list(map(None, foo.bar,))
    list(map(None, foo, bar))
    list(map(f, foo.bar))
    list(map(lambda x: x+1, list(range(10))))

def basestring_examples():
    if isinstance(x, str): pass

def buffer_examples():
    x = buffer(y)

def sys_exc_examples():
    print(sys.exc_info()[0], sys.exc_info()[1], sys.exc_info()[2])

def operator_examples():
    import operator
    operator.isCallable(foo)
    operator.sequenceIncludes(foo, bar)

    from operator import isCallable, sequenceIncludes
    # These should produce warnings.
    isCallable(foo)
    sequenceIncludes(foo, bar)

class X:
    def maximum(self):
        return max(self.data.values())
    def total(self):
        return sum(self.data.values())


# This is the last line.
