n, k = [int(x) for x in raw_input().split()]
r = 0
for i in range(n):
    t = int(raw_input())
    if t % k == 0:
        r += 1
print r
