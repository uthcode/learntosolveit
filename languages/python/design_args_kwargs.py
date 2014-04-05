def fun1(arg):
    print arg

def fun2(arg,arg2):
    print arg, arg2

def fun3(arg, *arg2):
    print arg, arg2

def fun4(*arg):
    print arg

def fun5(**kw):
    print kw

def fun6(*arg, **kw):
    print arg

def fun7(a, *arg, **kw):
    print a
    print arg
    print kw

def fun8(*arg, **kw):
    print "***args", arg
    fun7(*arg, **kw)

def fun9(a, b, *args, **kw):
    fun8(a, b, *args, **kw)

fun1(10)
fun2(10,20)
fun3(10,20,30)
fun3(10)
fun4(10,20,30,40)
fun5(a=10,b=20)
fun6(10,20,40)
fun7(10, 20, 30, k=40)
fun7(10, k=10)
fun8(10, 20, 30, k=40)
fun9(10, 20, 30, k=40)
