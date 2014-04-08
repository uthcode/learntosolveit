import pudb
pudb.set_trace()
def func(a, b=[]):
    b.append(a)
    return b


print func(10)
print func(20)
print func(30)
print func(40)
