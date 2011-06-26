import optparse

def test():
    "Stupid test function"
    L = []
    for i in range(100):
        L.append(i)

def time_test():
    from timeit import Timer
    t = Timer("test()", "from __main__ import test")
    print t.timeit()

if __name__ == '__main__':
    parser = optparse.OptionParser()
    parser.add_option('-t','--timeit',action='store_true',dest='timeit',default=False)
    options, arguments = parser.parse_args()
    if options.timeit:
        time_test()
    else:
        test()
