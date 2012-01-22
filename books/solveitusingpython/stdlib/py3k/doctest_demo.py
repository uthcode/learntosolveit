def add(a, b):
    """Add two arbitrary objects and return their sum.
    >>> add(1, 2)
    3
    >>> add([1],[2])
    [1, 2]
    >>> add('Calvin ','& Hobbes')
    'Calvin & Hobbes'
    >>>
    >>> add([1], 2)
    Traceback (most recent call last):
    TypeError: can only concatenate list (not "int") to list
    """
    return a + b

if __name__ == "__main__":
    import doctest
    doctest.testmod()
