def fibonacci(n):
    f1 = 0
    f2 = 1

    if n == 1:
        return f1
    if n == 2:
        return f2

    for _ in range(2, n + 1):
        f2, f1 = f2 + f1, f2

    return f1   # bug

if __name__ == '__main__':
    n = input("Hi Friend, give me a number, n, and I will give nth Fibnacci number. ")
    print(fibonacci(int(n)))
