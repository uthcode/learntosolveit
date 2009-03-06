import sys
def foo():
    """blah"""
    print sys._getframe().f_back.f_locals[sys._getframe().f_code.co_name].__doc__

foo()
