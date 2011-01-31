# TODO: Convert to C++
tc = int(raw_input())
for etc in range(tc):
    nelem = int(raw_input())
    nelemlist = [x for x in range(1,nelem+1)]
    while (len(nelemlist) != 1):
        newlist = nelemlist[:]
        for i in range(0,len(newlist),2):
            newlist[i] = -42
        nelemlist = [x for x in newlist if x != -42]
    print nelemlist[0]
