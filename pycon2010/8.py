def make_something(*args, **kwargs):
    print args
    print kwargs
    #adict = dict(*args, **kwargs)
    #return adict

print make_something(1,2,3,one='1',two='2')

