def f():
    x = 10
    def g():
        y = 100
        print locals()
    g()
    print locals()

if __name__ == '__main__':
    f()
