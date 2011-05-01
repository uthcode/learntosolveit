"""
Problem:
    http://code.google.com/codejam/contest/dashboard?c=438101#

"""
N = int(raw_input())
for tc in range(1,N+1):
    G = int(raw_input())
    list_of_guests = raw_input().split()
    unique_guests = set(list_of_guests)
    for each in unique_guests:
        if list_of_guests.count(each) == 1:
            print 'Case #%d: %s' % (tc, each)
            break


