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
    a = unicode(b)
    a = u"xxx"
    a = U"""xxx"""
    a = ur'xxx'
    a = UR'''xxx'''
    a = Ur"xxx"
    a = uR"""xxx"""
    b = u"..." u'...'

def ne_examples():
    if x <> y:
        pass
    if x<>y:
        pass
    if x<>y<>z:
        pass

def has_key_examples():
    #
    x = d.has_key("x") or d.has_key("y")
    #
    x = a.b.c.d.has_key("x") ** 3
    #
    x = a.b.has_key(1 + 2).__repr__()
    #
    x = a.b.has_key(1 + 2).__repr__() ** -3 ** 4
    #
    x = a.has_key(f or g)
    #
    x = a + b.has_key(c)
    #
    x = a.has_key(lambda: 12)
    #
    x = a.has_key(a for a in b)
    #
    if not a.has_key(b): pass
    #
    if not a.has_key(b).__repr__(): pass
    #
    if not a.has_key(b) ** 2: pass

def foo():
	pass # body indented by tab

def test_ws_comma():
    yield 1,2 ,3
    f(1,2 ,3)
    `a ,b`
    def f(a,b ,c): pass
    { a:b,c:d , e : f }

def apply_examples():
    x = apply(f, g + h)
    y = apply(f, g, h)
    z = apply(fs[0], g or h, h or g)
    # Hello
    apply(f, (x, y) + t)
    apply(f, args,)
    apply(f, args, kwds,)
    # Test that complex functions are parenthesized
    x = apply(f+g, args)
    x = apply(f*g, args)
    x = apply(f**g, args)
    # But dotted names etc. not
    x = apply(f.g, args)
    x = apply(f[x], args)
    x = apply(f(), args)
    # Extreme case
    x = apply(a.b.c.d.e.f, args, kwds)
    # XXX Comments in weird places still get lost
    apply(   # foo
          f, # bar
          args)

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
    class X:
        __metaclass__ = Meta

    class X(b1, b2):
        bar = 23 # Comment on me!
        __metaclass__ = Meta
        spam = 27.23 # Laughable

    class X:
        __metaclass__ = Meta; x = 23; y = 34 # Yes, I can handle this, too.

def intern_examples():
    #
    # These should be refactored:
    #
    x = intern(a)
    #
    y = intern("b" # test
              )
    #
    z = intern(a+b+c.d,)
    #
    intern("y%s" % 5).replace("y", "")
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
    print 1, 1+1, 1+1+1
    #
    print 1, 2
    #
    print 1

    print

    # trailing commas
    print 1, 2, 3,
    #
    print 1, 2,
    #
    print 1,
    #
    print

    # >> stuff
    print >>sys.stderr, 1, 2, 3    # no trailing comma
    #
    print >>sys.stdder, 1, 2,      # trailing comma
    #
    print >>sys.stderr, 1+1        # no trailing comma
    #
    print >>  sys.stderr           # spaces before sys.stderr

def exec_examples():
    #
    exec code
    #
    exec code in ns
    #
    exec code in ns1, ns2
    #
    exec (a.b()) in ns
    #
    exec a.b() + c in ns
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
    x = `1 + 2`
    #
    y = `x`
    #
    z = `y`.__repr__()
    #
    x = `1, 2, 3`
    #
    x = `1 + `2``
    #
    x = `1, 2 + `3, 4``

def except_examples():
    try:
        pass
    except Exception, (f, e):
        pass
    except ImportError, e:
        print e.args
    #
    try:
        pass
    except (RuntimeError, ImportError), e:
        pass
    #
    try:
        pass
    except Exception, (a, b):
        pass
    #
    try:
        pass
    except Exception, d[5]:
        pass
    #
    try:
        pass
    except Exception, a.foo:
        pass
    #
    try:
        pass
    except Exception, a().foo:
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
    raise Exception, 5
    #
    raise Exception,5
    #
    raise Exception, (5, 6, 7)
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
    raise Exception, 5, 6
    #
    raise Exception,5,6
    #
    raise Exception, (5, 6, 7), 6

def long_examples():
    x = long(x)
    y = isinstance(x, long)
    z = type(x) in (int, long)
    a = 12L
    b = 0x12l
    # unchanged:
    a = 12
    b = 0x12
    c = 3.14

def dict_examples():
    #
    # Plain method calls
    #
    print d.keys()
    print d.items()
    print d.values()
    #
    # Plain method calls in special contexts
    #
    print iter(e.keys())
    for i in e.keys(): print i
    [i for i in e.keys()]
    (i for i in e.keys())
    #
    # Iterator method calls
    #
    print f.iterkeys()
    print f.iteritems()
    print f.itervalues()
    #
    # Iterator method calls in special contexts
    #
    print list(g.iterkeys())
    print sorted(g.iterkeys())
    print iter(g.iterkeys())
    for i in g.iterkeys(): print i
    [i for i in g.iterkeys()]
    (i for i in g.iterkeys())
    #
    # Examples with a "tail"; these are never "special"
    #
    print h.iterkeys().next()
    print h.keys()[0]
    print list(h.iterkeys().next())
    for x in h.keys()[0]: print x

def dict_negative_examples():
    #
    # These should all remain unchanged:
    #
    print list(h.keys())
    print sorted(h.keys())

def xrange_examples():
    for i in xrange(100): print i
    for i in xrange(0, 100): print i
    for i in xrange(0, 100, 10): print i

def input_examples():
    a = input()
    b = input(str(a))

def raw_input_examples():
    a = raw_input()
    b = raw_input(a.rstrip())

def filter_examples():
    filter(os.unlink, filenames)
    filter(None, "whatever")
    filter(lambda x: not x, range(4))

def map_examples():
    map(None, foo.bar)
    map(None, foo.bar,)
    map(None, foo, bar)
    map(f, foo.bar)
    map(lambda x: x+1, range(10))

def basestring_examples():
    if isinstance(x, basestring): pass

def buffer_examples():
    x = buffer(y)

def sys_exc_examples():
    print sys.exc_type, sys.exc_value, sys.exc_traceback

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
