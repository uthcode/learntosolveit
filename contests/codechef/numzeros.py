def numzeros(n):
    q = 0
    for i in range(1,100):
        p = n / pow(5,i)
        if not p:
            break
        q += p
    return q

n = int(raw_input())
testcases = []
for i in range(n):
    testcases.append(int(raw_input()))

for tc in testcases:
    print numzeros(tc)

