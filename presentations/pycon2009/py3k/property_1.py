print "---- First Section ----"

class Name(object):
    def __init__(self):
        self.name = "PyCon 2009"
    def confname(self):
        return self.name

conference = Name()
print conference.confname
print conference.confname()


print "---- Second Section ----"

class Name2(object):
    def __init__(self):
        self.name = "PyCon 2009"

    def confname(self):
        return self.name

    confname = property(confname)

conference2 = Name2()
print conference2.confname

# print conference2.confname() is not possible, because it is an attribute and
# not callable.

print "---- Third Section ----"

class Name3(object):
    def __init__(self):
        self.name = "PyCon 2009"

    @property
    def confname(self):
        return self.name


conference3 = Name3()
print conference3.confname
