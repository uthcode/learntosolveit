class fibnum:
        def __init__(self):
            self.fn1 = 2
            self.fn2 = 1

        def next(self):
            self.fn1, self.fn2, oldfn2 = self.fn1+self.fn2, self.fn1, self.fn2
            return oldfn2

        def __iter__(self):
            return self


def main():
    f = fibnum()
    for i in f:
        print i
        if i > 20: break

if __name__ == '__main__':
    main()
