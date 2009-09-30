n, k = map(int, raw_input().split())
ans = 0
for i in range(n):
    if (int(raw_input()) % k == 0):
        ans += 1

print ans
