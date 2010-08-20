T = int(input())
for tests in xrange(T):
    power, state = 1,0
    snapper_chains = []
    N, K = map(int,raw_input().split())
    for snappers in range(N):
        snapper_chains.append([power,state])
        power = 0
        state = 0
    for clicks in xrange(K):
        for snapper in xrange(N):
            power, state = snapper_chains[snapper]
            if power:
                if state:
                    state = 0
                else:
                    state = 1
            if snapper:
                previous_snapper = snapper_chains[snapper-1]
                previous_power, previous_state = previous_snapper
                if previous_power and previous_state:
                    power = 1
                else:
                    power = 0
            snapper_chains[snapper] = [power, state]
            #if not (power or state or previous_power or previous_state):
            #    break
    power, state = snapper_chains[-1]
    if power and state:
        print 'Case #%d: %s' % (tests+1, 'ON')
    else:
        print 'Case #%d: %s' % (tests+1, 'OFF')
