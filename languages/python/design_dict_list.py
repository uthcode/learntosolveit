def fun(a, *b, **c):
    print(a)
    for item in b:
        print(item)
    for k,v in c:
        print(k,v)

a = 42
b = [1,2,3]
c = {'a':'1','b':2,'c':True}

fun(a,b,c)
