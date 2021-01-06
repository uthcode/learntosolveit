def normfunc():
    iterable = list(range(10))
    for item in iterable:
        return item * item

afuncreturn = normfunc()

print(afuncreturn)
print(type(afuncreturn))

def genfunc():
    iterable = list(range(10))
    for item in iterable:
        yield item * item

agenerator = genfunc()

print(agenerator)
print(type(agenerator))

for item in agenerator:
    print(item)


explain = """
To master yield, you must understand that when you call the function, the code
you have written in the function body does not run. The function only returns
the generator object, this is bit tricky :-)

Then, your code will be run each time the for uses the generator.

The first time your function will run, it will run from the beginning until it
hits yield, then it'll return the first value of the loop. Then, each other call
will run the loop you have written in the function one more time, and return the
next value, until there is no value to return.

The generator is considered empty once the function runs but does not hit yield
anymore. It can be because the loop had come to ends, or because you do not
satisfy a "if/else" anymore.
"""
