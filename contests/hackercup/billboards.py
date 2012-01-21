import math

T = int(raw_input())

def divide(w, s, rows):
    result = []
    for r in range(rows):
        result.append([])
    # result = [[],[],[]]
    # Take care of the tricky situation later.
    # Different combinations.
    i = 0
    for word in s.split():
        if i == rows: # reset i when it reaches max
            i = 0
        # take care that appending does not go beyond w
        if (sum(map(len,result[i]))) + len(word) <= w:
            result[i].append(word)
        else:
            i += 1
    final_result = []
    for each_sub in result:
        split_sentence = " ".join(each_sub)
        if s.find(split_sentence) == -1:
            return False
        else:
            final_result.append(" ".join(each_sub))
    return final_result

def solve(w, h, s):
    # algorithm
    num_of_words = len(s.split())
    min_rows = 1
    max_rows = num_of_words
    lower_limit = int(math.floor(h/max_rows))
    # should not become 0 or -1
    for size in range(h,0,-1):
        if size * len(s) <= w:
            return size
        else:
            # Can we decrease s and see.
            for rows in range(2,max_rows+1):
                # How can we divide s into rows
                # Can a check be made here?
                result = divide(w,s,rows)
                if result:
                    gotit = True
                    #result = ["a b","c d"]
                    for each in result:
                        if size * len(each) > w:
                            gotit = False
                            break
                    if gotit:
                        return size

for tc in range(T):
    tc_input = raw_input().split()
    w = int(tc_input.pop(0))
    h = int(tc_input.pop(0))
    s = " ".join(tc_input)
    r = solve(w,h,s)
    print tc, r
