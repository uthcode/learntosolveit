def add(a,b):
    return a+b

if __name__ == '__main__':
    import unittest, doctest
    suite = doctest.DocFileSuite('doctest_tests.txt')
    unittest.TextTestRunner().run(suite)
