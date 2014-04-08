class C(object):
    def __getitem__(self, item):
        return item

print C()[1:2, ..., 3]
