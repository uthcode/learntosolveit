# Problem
# 
# A train line has two stations on it, A and B. Trains can take trips from A to B
# or from B to A multiple times during a day. When a train arrives at B from A
# (or arrives at A from B), it needs a certain amount of time before it is ready
# to take the return journey - this is the turnaround time. For example, if a
# train arrives at 12:00 and the turnaround time is 0 minutes, it can leave
# immediately, at 12:00.
# 
# A train timetable specifies departure and arrival time of all trips between A
# and B. The train company needs to know how many trains have to start the day at
# A and B in order to make the timetable work: whenever a train is supposed to
# leave A or B, there must actually be one there ready to go. There are passing
# sections on the track, so trains don't necessarily arrive in the same order
# that they leave. Trains may not travel on trips that do not appear on the
# schedule.
# 
# Input
# The first line of input gives the number of cases, N. N test cases follow.
# 
# Each case contains a number of lines. The first line is the turnaround time, T,
# in minutes. The next line has two numbers on it, NA and NB. NA is the number of
# trips from A to B, and NB is the number of trips from B to A. Then there are NA
# lines giving the details of the trips from A to B.
# 
# Each line contains two fields, giving the HH:MM departure and arrival time for
# that trip. The departure time for each trip will be earlier than the arrival
# time. All arrivals and departures occur on the same day. The trips may appear
# in any order - they are not necessarily sorted by time. The hour and minute
# values are both two digits, zero-padded, and are on a 24-hour clock (00:00
# through 23:59).
# 
# After these NA lines, there are NB lines giving the departure and arrival times
# for the trips from B to A.
# 
# Output
# For each test case, output one line containing "Case #x: " followed by the
# number of trains that must start at A and the number of trains that must start
# at B.
# 
# Limits
# 
# 1 ≤ N ≤ 100
# 
# Small dataset
# 
# 0 ≤ NA, NB ≤ 20
# 
# 0 ≤ T ≤ 5
# 
# Large dataset
# 
# 0 ≤ NA, NB ≤ 100
# 
# 0 ≤ T ≤ 60
# 
# Sample
# 
# Input
#     
# Output
# 2
# 5
# 3 2
# 09:00 12:00
# 10:00 13:00
# 11:00 12:30
# 12:02 15:00
# 09:00 10:30
# 2
# 2 0
# 09:00 09:01
# 12:00 12:02
# 
#     Case #1: 2 2
# Case #2: 2 0

import datetime

def get_dateobjs(dep, arr,t):
    h,m = dep.split(':')
    depobj = datetime.datetime(2008,06,18,int(h),int(m))
    h,m = arr.split(':')
    arrobj = datetime.datetime(2008,06,18,int(h),int(m))
    arrobj = arrobj + datetime.timedelta(minutes=int(t))
    return depobj,arrobj

tcs = input()
for ip in range(tcs):
    t = input()
    na,nb = (int(x) for x in raw_input().split(' '))
    tablea = []
    for i in range(na):
        d,a = raw_input().split()
        tablea.append(list(get_dateobjs(d,a,t)))
    tableb = []
    for i in range(nb):
        d,a = raw_input().split()
        tableb.append(list(get_dateobjs(d,a,t)))
    nta = len(tablea)
    ntb = len(tableb)

    dep_time_at_a = [x[0] for x in tablea]
    arr_time_at_b = [x[1] for x in tablea]

    dep_time_at_b = [x[0] for x in tableb]
    arr_time_at_a = [x[1] for x in tableb]

    dep_time_at_a.sort()
    arr_time_at_b.sort()
    dep_time_at_b.sort()
    arr_time_at_a.sort()

    for x in dep_time_at_a:
        for i in range(len(arr_time_at_a)):
            if x >= arr_time_at_a[i]:
                if not nta == 0:
                    nta = nta -1
                    arr_time_at_a =arr_time_at_a[i+1:]
            break

    for x in dep_time_at_b:
        for i in range(len(arr_time_at_b)):
            if x >= arr_time_at_b[i]:
                if not ntb == 0:
                    ntb = ntb - 1
                    arr_time_at_b = arr_time_at_b[i+1:]
            break

    print 'Case #%d: %d %d' % (ip+1,nta,ntb)
