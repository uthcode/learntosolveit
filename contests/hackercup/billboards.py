import math
import pudb

T = int(raw_input())
# T = 1
# pudb.set_trace()

def divide(s, rows, size,w):
    result = []
    for r in range(rows):
        result.append([])
    # result = [[],[],[]]
    # Take care of the tricky situation later.
    # Different combinations.
    i = 0
    words = s.split()
    next_word = True
    while words and i < rows:
        word = words.pop(0)
        existing_len = size * sum(map(len,result[i]))
        new_word_len = size * len(word)
        if existing_len + new_word_len + ((size * len(result[i])) if existing_len else 0) <= w:
            result[i].append(word)
        else:
            i += 1
            words.insert(0,word)
    if words:
        return False

    """
    for entry in result:
        word = words.pop(0)
        while (sum(map(len,entry)) + (size * len(word))) <= w:
            entry.append(word)
            word = words.pop(0)
    if words:
        return False

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
    """

    final_result = []
    for each_sub in result:
        split_sentence = " ".join(each_sub)
        final_result.append(split_sentence)
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
            # max_rows depends upon size
            for rows in range(2,max_rows+1):
                # How can we divide s into rows
                # Can a check be made here?
                result = divide(s,rows,size,w)
                if result:
                    gotit = True
                    #result = ["a b","c d"]
                    for each in result:
                        if size * len(each) > w or (size * rows) > h:
                            gotit = False
                            break
                    if gotit:
                        return size

for tc in range(T):
    tc_input = raw_input().split()
    # tc_input = '100 20 hacker cup 2013'.split()
    # tc_input = '20 6 hacker cup'.split()
    # tc_input = '100 20 Hack your way to the cup'.split()
    w = int(tc_input.pop(0))
    h = int(tc_input.pop(0))
    s = " ".join(tc_input)
    r = solve(w,h,s)
    print 'Case #%s: %d' % (str(tc+1),r)
