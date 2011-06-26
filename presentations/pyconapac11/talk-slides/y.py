from x import add

def main():
    i = 0
    a = 0.0
    while i < 1000000000:
        a += 1.0
        add(a, a)
        i += 1

main()
