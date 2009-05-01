n = input()

for tc in range(n):
    n,a,b,c,d,x0,y0,m= (int(x) for x in raw_input().split())
    cords_dict =
    {(0,0):0,(0,1):0,(0,2):0,(1,0):0,(1,1):0,(1,2):0,(2,0):0,(2,1):0,(2,2):0}
    if (x0%3,y%3) in cords_dict.keys():
        cords_dict[(x0%3,y0%3)] += 1
    x = x0
    y = y0
    for id in range(1,n):
        x = (a * x + b) % m
        y = (c * y + d) % m
        cords.append((x%3,y%3))
    print cords
