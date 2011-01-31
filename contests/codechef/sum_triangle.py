# TODO:
tc = int(raw_input())
for etc in range(tc):
    nl  = int(raw_input())
    row = []
    for i in range(nl):
        row.append(map(int,raw_input().split()))
    print row
