# Good example for args and kwargs

def fun(a, b, *args, **kwargs):
    print 'a:',a
    print 'b:',b
    print 'args:', args
    print 'kwargs:', kwargs

fun('a','b','c','d','e','f',g='g',h='h',i='i',j='j')
