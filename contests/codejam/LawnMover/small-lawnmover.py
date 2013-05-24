import pprint
T = int(raw_input())
for tc in range(T):
    print "Case #%d:" %(int(tc)+1),
    N, M = map(int, raw_input().split())
    mat1 = []
    for i in range(N):
        mat1.append(map(int,raw_input().split()))
    mat2 = zip(*mat1)
    result_found = False
    possible = True
    for row in mat1:
        i = row[0]
#        if i < max(row):
#            same_col = mat2[0]
#            n_same_col = map(lambda x: x-i, same_col)
#            if sum(n_same_col) != 0:
#                result_found = True
#                possible = False
#                break
        nr = map(lambda x: x-i, row)
        for j in range(len(nr)):
            if nr[j] != 0:
                row2 = mat2[j]
                i2 = row2[0]
                nr2 = map(lambda x:x-i2, row2)
                for k in range(len(nr2)):
                    if nr2[k] != 0:
                        result_found = True
                        break
        if result_found:
            possible = False
    if possible:
        print "YES"
    else:
        print "NO"
