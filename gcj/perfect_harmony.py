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
    out = lcmm(*frequencies)
    found = False
    for i in range(L,H+1):
        if out % i == 0:
            # check for all frequencies
            allfreq = []
            print i
            print frequencies
            for f in frequencies:
                if i % f == 0:
                    allfreq.append(True)
                else:
                    allfreq.append(False)
                    continue
            print allfreq
            if all(allfreq):
                out = i
                found = True
                break
    if  L <= out <= H:
        print 'Case #%d: %d' % (tc, out)
    else:
        print 'Case #%d: %s' % (tc, 'NO')
