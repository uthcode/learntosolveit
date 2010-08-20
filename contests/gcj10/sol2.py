states = {}
states[1] = [1,1]
states[2] = [1,1,1,1]
s1, s2, s3, s4 = 3, 1, 3, 1
for i in range(3,31):
    states[i] = [s1,s2,s3,s4]
    s1,s2,s3,s4 = s1*2+1, s2, s3*2+1, s4

T = int(input())
for tests in xrange(T):
    N, K = map(int, raw_input().split())
    if N == 1:
        if K % 2 == 0:
            print 'Case #%d: %s' % (tests+1, 'OFF')
        else:
            print 'Case #%d: %s' % (tests+1, 'ON')
        continue
    if N == 2:
        if K == 0:
            print 'Case #%d: %s' %(tests+1, 'OFF')
            continue
        else:
            K = K % 4
            if K == 3:
                print 'Case #%d: %s' %(tests+1, 'ON')
            else:
                print 'Case #%d: %s' %(tests+1, 'OFF')
            continue
    K = K + 1
    totalstates = sum(states[N])
    if K == totalstates:
        print 'Case #%d: %s' %(tests+1, 'ON')
        continue
    if K % totalstates == 0:
        print 'Case #%d: %s' %(tests+1, 'ON')
    else:
        print 'Case #%d: %s' %(tests+1, 'OFF')
    continue
#    if K > totalstates:
#        K = K % totalstates
#    offstates = sum(states[N][0:-1])
#    if K <= offstates:
#        print 'Case #%d: %s' % (tests+1, 'OFF')
#        continue
#    else:
#        print 'Case #%d: %s' % (tests+1, 'ON')
#        continue
