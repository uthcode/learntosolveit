file = open("A-small-attempt0.in")
cases = int(file.readline())
import re
ans = open("1.out","wt")
print cases

for z in range(0,cases):
    p, k, l = [int(item) for item in file.readline().split(" ")]
    letters = [int(item) for item in file.readline().split(" ")]
    letters.sort()
    letters.reverse()
    res = 0
    #print p,k,l
    #print letters
    #for x in range(1,p+1):
        #for y in range(0, k):
    for x in range(0, l):
            keylvl = x/k + 1
            res += letters[x]*keylvl
            
    
    
    print "Case #%d: %d\n"%(z+1, res)
    ans.write("Case #%d: %d\n"%(z+1, res))
