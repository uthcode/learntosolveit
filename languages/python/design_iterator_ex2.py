dict1 = {'a':1,'b':2,'c':3}

sequence= dict1

it = iter(sequence)
while True:
    try:
        value = it.next()
    except StopIteration:
        break
    print value

