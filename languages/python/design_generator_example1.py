def fibonacci():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a+b


for number in fibonacci():
    print(number)
