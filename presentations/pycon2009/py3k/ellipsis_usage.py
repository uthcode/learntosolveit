class TestEllipsis(object):
    def __getitem__(self, item):
        if item is Ellipsis:
            return "Returning all items"
        else:
            return "return %r items" % item

x = TestEllipsis()
print x[2]
print x[...]
