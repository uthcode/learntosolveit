"""
Problem Statement:  http://code.google.com/codejam/contest/dashboard?c=544101

This is an interesting problem. Creating the rotated matrix is not so hard,
just involves bit of thinking in terms of representation. What was problematic
is  the way to count the rows, columns and diagonals. I **thought** that was
hard. It is easy only that it requires you to write a lot of code in the if
loops and with trials you have to get it right too. A paper-pencil trial could
help you here. I spent a good amount of time to solve, got constantly deviated
while writing the final checking loop.
"""

T = int(raw_input())
for tc in range(1,T+1):
    N, K = map(int, raw_input().split())
    graph = []
    matches = []
    for r in range(N):
        rotated_row = []
        row = raw_input()
        for c in row:
            if not c is '.':
                rotated_row.append(c)
        row = ['.'] * (N-len(rotated_row)) + rotated_row
        graph.append(row)
    for i in range(N):  # row
        for j in range(N): # column
            # test right
            graphdict = {'B':0,'R':0}
            for k in range(K):
                t = j + k
                if t > (N-1):
                    break
                char = graph[i][t]
                if char in graphdict:
                    graphdict[char] += 1
                    if (graphdict[char] == K):
                        if char not in matches:
                            matches.append(char)
            # test down
            graphdict = {'B':0,'R':0}
            for k in range(K):
                t = i + k
                if t > (N-1):
                    break
                char = graph[t][j]
                if char in graphdict:
                    graphdict[char] += 1
                    if (graphdict[char] == K):
                        if char not in matches:
                            matches.append(char)
            # test diagonal right
            graphdict = {'B':0,'R':0}
            for k in range(K):
                t = j + k
                if t > (N-1):
                    break
                r = i + k
                if r > (N-1):
                    break
                char = graph[r][t]
                if char in graphdict:
                    graphdict[char] += 1
                    if (graphdict[char] == K):
                        if char not in matches:
                            matches.append(char)
            # test diagonal down TODO
            graphdict = {'B':0,'R':0}
            for k in range(K):
                t = j - k
                if t < 0:
                    break
                r = i + k
                if r > (N-1):
                    break
                char = graph[r][t]
                if char in graphdict:
                    graphdict[char] += 1
                    if (graphdict[char] == K):
                        if char not in matches:
                            matches.append(char)
    if not matches:
        result = 'Neither'
    if len(matches) == 1:
        if 'R' in matches:
            result = 'Red'
        if 'B' in matches:
            result = 'Blue'
    if len(matches) == 2:
        result = 'Both'
    print 'Case #%d: %s' % (tc, result)
