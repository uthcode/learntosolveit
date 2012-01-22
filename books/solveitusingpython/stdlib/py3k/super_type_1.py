class Farm(object):
    def __init__(self):
        self.x = "I am from Farm"

class Barm(Farm):
    def __init__(self):
        super(Barm, self).__init__()

obj = Barm()
print obj.x
