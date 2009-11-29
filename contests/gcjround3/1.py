T = int(raw_input())
for i in range(T):
    print 'Case #%d: ' % (i+1),
    alien = raw_input()
    smallest_base = len(set(alien))
    if smallest_base == 1:
        smallest_base = 2
    alien_ascii = dict()
    base_values = [x for x in range(smallest_base)]
    if len(base_values) == 1:
        base_values = [1]
    else: 
        base_values[0],base_values[1] = base_values[1], base_values[0]

    for a in alien:
        if not(a in alien_ascii):
            alien_ascii[a] = base_values.pop(0)

    sum = 0
    i = 0
    for x in reversed(alien):
        sum += alien_ascii[x] * pow(smallest_base,i)
        i+=1

    print sum
