T = int(raw_input())
for tc in range(1,T+1):
    R,C = map(int, raw_input().split())
    mat = []
    for i in range(R):
        mat.append(list(raw_input()))
    resultmat = mat[:]
    impossible = False
    for r in range(0,R-1,1):
        for c in range(0, C-1,1):
            if resultmat[r][c] == '#':
                if (resultmat[r][c+1] == '#' and resultmat[r+1][c] == '#' and resultmat[r+1][c+1] == '#'):
                    resultmat[r][c] = '/'
                    resultmat[r][c+1] = '\\'
                    resultmat[r+1][c] = '\\'
                    resultmat[r+1][c+1] = '/'
                else:
                    impossible = True
                    break
        if impossible:
            break
    # check last row and col
    for i in range(R):
        for j in range(C):
            if resultmat[i][C-1] == '#' or resultmat[R-1][j] == '#':
                impossible = True
                break
    print 'Case #%d:' % tc
    if impossible:
        print 'Impossible'
    else:
        for row in resultmat:
            print ''.join(row)
