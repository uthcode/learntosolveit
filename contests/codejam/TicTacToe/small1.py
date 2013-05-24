# 0  1  2  3
# 4  5  6  7
# 8  9  10 11
# 12 13 14 15

T = int(raw_input())
for tc in range(T):
    X = []
    fs = ""
    possible_draw = True
    result_found = False
    for row in range(4):
        x = "".join(raw_input().split())
        fs += x
        X.append(list(x))
    Z1 = fs[0] + fs[5] + fs[10] + fs[15]
    Z2 = fs[3] + fs[6] + fs[9] + fs[12]
    Y = zip(*X)
    print "Case #%d: " % (int(tc)+1),
    for row in range(4):
        X1 = "".join(X[row])
        Y1 = "".join(Y[row])
        # case1 if 4 is X or 0
        # case2 if contains T, 3 is X or 0
        # case3 if contains ., make note.
        # case4 if nothing, of above cases, print draw.
        if (X1.count('X') == 4 or Y1.count('X') == 4 or Z1.count('X') == 4 or Z2.count('X') == 4):
            print "X won"
            result_found = True
            break
        if (X1.count("O") == 4 or Y1.count("O") == 4 or Z1.count('O') == 4 or Z2.count('O') == 4):
            print "O won"
            result_found = True
            break
        if ("T" in X1 and X1.count('X') == 3):
                print "X won"
                result_found = True
                break
        if ("T" in X1 and X1.count('O') == 3):
                print "O won"
                result_found = True
                break
        if ("T" in Y1 and Y1.count('X') == 3):
                print "X won"
                result_found = True
                break
        if ("T" in Y1 and Y1.count('O') == 3):
                print "O won"
                result_found = True
                break
        if ("T" in Z1 and Z1.count('X') == 3):
                print "X won"
                result_found = True
                break
        if ("T" in Z1 and Z1.count('O') == 3):
                print "O won"
                result_found = True
                break
        if ("T" in Z2 and Z2.count('X') == 3):
                print "X won"
                result_found = True
                break
        if ("T" in Z2 and Z2.count('O') == 3):
                print "O won"
                result_found = True
                break

        if ("." in X1 or "." in Y1 or "." in Z1 or "." in Z2):
            possible_draw = False

    if not result_found:
        if possible_draw:
            print "Draw"
        else:
            print "Game has not completed"
    try:
        raw_input()
    except EOFError:
        pass

