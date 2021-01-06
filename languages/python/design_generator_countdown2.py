def countdown(n):
    print("Counting down from ", n)
    while n > 0:
        yield n
        n -= 1

x = countdown(5) # no print is output

print('before running')
for i in x:
    print(i)
