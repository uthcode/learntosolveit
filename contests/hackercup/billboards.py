import math
import pudb

T = int(raw_input())
# T = 1
#pudb.set_trace()

def divide(s, rows, size,w):
    result = []
    for r in range(rows):
        result.append([])
    # result = [[],[],[]]
    # Take care of the tricky situation later.
    # Different combinations.
    i = 0
    for word in s.split():
        # take each word and add it to right list.
        # if it cannot be added to any list, return False
        if i >= rows: # reset i when it reaches max
            i = 0
        while (i <= rows):
        # take care that appending does not go beyond w
            if i == rows:
                return False
            if (sum(map(len,result[i]))) + (size* len(word)) <= w:
                result[i].append(word)
                i += 1
                break
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
                result = divide(s,rows,size,w)
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
    # tc_input = '20 6 hacker cup'.split()
    w = int(tc_input.pop(0))
    h = int(tc_input.pop(0))
    s = " ".join(tc_input)
    r = solve(w,h,s)
    print 'Case #%s: %d' % (str(tc+1),r)
