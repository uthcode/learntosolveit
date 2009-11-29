import itertools

def calculate_bribe(cells):
    bribe = 0
    print cells
    for cell in cells:
        if not (cell == -1):
            if not isolated(cell,cells):
                bribe += 1

    return bribe

N = int(raw_input())
for tc in range(N):
    print 'Case #%d: ' % (tc+1),
    P, Q = map(int, raw_input().split())
    original_cells = [p for p in range(P)]
    Q = map(int, raw_input().split())
    min_bribe = 1000000000000
    for each in itertools.permutations(Q):
        prison_cells = original_cells[:]
        bribe = 0
        for c in each:
            prison_cells[c-1] = -1
            bribe += calculate_bribe(prison_cells)
        if bribe < min_bribe:
            min_bribe = bribe
        print min_bribe
