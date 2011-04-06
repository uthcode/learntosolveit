def constant(value):
    def _inner():
        return value
    return _inner
x = constant(5)
print(x())
