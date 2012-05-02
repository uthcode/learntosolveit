def function(a):
    def add(b):
        return a + b
    return add

closure = function(100)

print closure(10)
print closure(110)
