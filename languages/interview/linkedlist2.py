import pudb
pudb.set_trace()
def mklist(*args):
    result = None
    for element in reversed(args):
        result = (element, result)

    return result

print mklist(1,2,3,4,5,6)
