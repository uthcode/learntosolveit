def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""
    return reduce(lcm, args)

T = int(raw_input())
for tc in range(1,T+1):
    N, L, H = map(int,raw_input().split())
    frequencies = map(int,raw_input().split())
    found_within = False
    for i in range(L, H+1):
        divisible = []
        for f in frequencies:
            if f % i == 0:
                divisible.append(True)
            else:
                divisible.append(False)
        if all(divisible):
            out = i
            found_within = True
            break

    if found_within:
        print 'Case #%d: %d' % (tc, out)
    else:
        print 'Case #%d: %s' % (tc, "NO")
