n = input()

def check_grid(t1,t2,t3):
        if ((t1[0]+t2[0]+t3[0]) % 3 == 0) and ((t1[1]+t2[1]+t3[1]) % 3 == 0):
            return True
        else:
            return False

for tc in range(n):
    n,a,b,c,d,x0,y0,m= (int(x) for x in raw_input().split())
    cords = []
    cords.append((x0,y0))
    x = x0
    y = y0
    for id in range(1,n):
        x = (a * x + b) % m
        y = (c * y + d) % m
        cords.append((x,y))
    result=0
    for v1 in range(0,len(cords)):
        for v2 in range(v1+1,len(cords)):
            for v3 in range(v2+1,len(cords)):
                if check_grid(cords[v1],cords[v2],cords[v3]):
                    result = result + 1
    print 'Case #%d: %d' %(tc+1,result)
