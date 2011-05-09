"""
I tried it simulating it.
"""

N = int(raw_input())
for tc in range(1, N+1):
    seq = raw_input().split()[1:]
    order = []
    bpos = []
    opos = []
    for x, y in zip(seq[::2],seq[1::2]):
        if x == 'B':
            bpos.append(int(y))
            order.append(x)
        if x == 'O':
            opos.append(int(y))
            order.append(x)
    bpath = []
    opath = []
    if bpos:
        atpos = 1
        for pos in bpos:
            topos = pos
            move = max(topos,atpos) - min(topos,atpos) + 1
            bpath.append(move)
            atpos = topos
    if opos:
        atpos = 1
        for pos in opos:
            topos = pos
            move = max(topos,atpos) - min(topos,atpos) + 1
            opath.append(move)
            atpos = topos

    b_order = []
    o_order = []
    o_move = 0
    b_move = 0
    timeslice = 0
    flag = None
    if opath:
        o_move = opath.pop(0)
    if bpath:
        b_move = bpath.pop(0)
    while True:
        if not order and o_move <= 1 and b_move <= 1 and not flag:
            break
        timeslice += 1
        if flag not in ['O','B']:
            flag = order.pop(0)
            if flag == 'O':
                o_step = 'p'
                b_step = 'w'
            elif flag == 'B':
                b_step = 'p'
                o_step = 'w'
        if o_move > 1:
            o_order.append('m')
            o_move -= 1
        else:
            if o_move == 1 and flag == 'O':
                o_order.append(o_step)
                flag = None
                if opath:
                    o_move = opath.pop(0)
            else:
                o_order.append(o_step)
        if b_move > 1:
            b_order.append('m')
            b_move -= 1
        else:
            if b_move == 1 and flag == 'B':
                b_order.append(b_step)
                flag = None
                if bpath:
                    b_move = bpath.pop(0)
            else:
                b_order.append(b_step)
    print 'Case #%d: %d' % (tc, timeslice)
