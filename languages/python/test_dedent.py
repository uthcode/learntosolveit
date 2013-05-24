from textwrap import dedent

def test():
    # end first line with \ to avoid the empty line!
    s = '''\
    hello
      world
    '''
    print s
    print repr(s)          # prints '    hello\n      world\n    '
    print repr(dedent(s))  # prints 'hello\n  world\n'
test()
