class Constant():
    def __init__(self, value):
        self._value = value

    def __call__(self):
        return self._value
y = Constant(5)
print((y()))
