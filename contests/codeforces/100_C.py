n = int(raw_input())
list_of_n = map(int,raw_input().split())
list_of_n = list(set(sorted(list_of_n)))

result = []

for i in range(0, len(list_of_n), 3):
    result.append(list_of_n[i:i+3])

for e in result:
    if len(e) != 3:
        result.remove(e)

for e in result:
    res = sorted(e,reverse=True)
    res = map(str,res)
    print ' '.join(res)
