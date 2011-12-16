num_events = int(raw_input())
list_of_events = []

for i in range(num_events):
    list_of_events.append(map(int, raw_input().split()))

list_of_events.sort(key=lambda x:x[1]-x[0],reversed=True)

for event in list_of_events:
    print event
