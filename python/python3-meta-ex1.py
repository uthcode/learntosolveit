class mymeta(type):
    def __new__(cls, name, bases, dict):
        print("Creating name:", name)
        print("Base Classes:", bases)
        print("Class Body:", dict)
        # create the actual class object
        return type.__new__(cls, name, bases, dict)

class Rectangle(object, metaclass=mymeta):
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

    def perimeter(self):
        return 2*self.width + 2* self.height
