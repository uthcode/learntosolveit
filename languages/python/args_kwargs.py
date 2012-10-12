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


fun1(10)
fun2(10,20)
fun3(10,20,30)
fun3(10)
fun4(10,20,30,40)
fun5(a=10,b=20)
fun6(10,20,40)
