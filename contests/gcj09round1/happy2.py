

memo = [dict() for _ in range(0,11)]

def ishappy(number, base):
    if number == 1:
        return True
    if number in memo[base]:
        return memo[base][number]

    sum = 0
    i = number

    while i:
        sum += (i%base) * (i%base)
        i //= base

    memo[base][number] = False
    recurse_value = ishappy(sum, base)
    memo[base][number] = recurse_value
    return recurse_value

def happyGen(bases, i):
    if i == len(bases):
        n = 2
        while True:
            yield n
            n = n + 1
    else:
        for n in happyGen(bases, (i+1)):
            if ishappy(n, bases[i]):
                yield n

cases = int(raw_input())
for i in range(cases):
    bases = map(int, raw_input().split())
    print 'Case #%d: ' % (i+1),
    for n in happyGen(bases, 0):
        print n
        break
