num = int(raw_input())
listofnums = map(int,raw_input().split())
print len(set(range(1,num+1)) - set(listofnums))
