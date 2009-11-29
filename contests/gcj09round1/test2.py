import time

B = [3, 4]


def happyGen(B, i):
    if i == len(B):
        n = 2
        while True:
            yield n
            print 'I come here', n
            n = n +1
            time.sleep(0.2)
    else:
        for n in happyGen(B, i+1):
            if n == 10:
                yield n

for n in happyGen(B, 0):
    print n

