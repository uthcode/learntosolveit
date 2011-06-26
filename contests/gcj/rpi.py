def calculate_oowp(n, mat):
    mat = zip(*mat)
    mat = mat[0:n] + mat[n+1:]
    mat = zip(*mat)
    cal = 0
    wp  = 0
    for i,row in enumerate(mat):
        if not i == n and row[n] != '.':
            wp += row.count('1') / (row.count('1') + row.count('0'))
            cal += 1
    owp = wp/cal
    return owp

def calculate_owp(n, mat):
    mat = zip(*mat)
    mat = mat[0:n] + mat[n+1:]
    mat = zip(*mat)
    cal = 0
    wp  = 0
    for i,row in enumerate(mat):
        if not i == n and row[n] != '.':
            wp += row.count('1') / (row.count('1') + row.count('0'))
            cal += 1
    owp = wp/cal
    return owp

T = int(raw_input())
for tc in range(1,T+1):
    N = int(raw_input())
    mat = []
    for each in range(N):
        mat.append(list(raw_input()))
    for i, row in enumerate(mat):
        wp = row.count('1') / (row.count('1') + row.count('0'))
        owp = calculate_owp(i,mat)
        oowp = calculate_oowp(i,mat)
        rpi = wp + 0
        print rpi
