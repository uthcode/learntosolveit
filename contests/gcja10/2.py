N = int(raw_input())
i = 1
for tc in range(N):
    l = raw_input().split()
    print 'Case #%d: %s' % (i, ' '.join(l[::-1]))
    i += 1
