class Farm(object):
    def __init__(self):
        self.x = "I am from Farm"

class Barm(Farm):
    def __init__(self):
        Farm.__init__(self)

obj = Barm()
print obj.x
