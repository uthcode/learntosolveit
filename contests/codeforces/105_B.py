# Dark Assembly

n, k, A = map(int, raw_input().split())

senators = []
B = 0

for i in range(n):
    bi, li = map(int, raw_input().split())
    senators.append([bi,li])
    B += int(bi)

p = A/(A-B)
print A
print B
print p
