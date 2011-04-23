T = int(raw_input())
for tc in range(1,T+1):
    N, K = map(int, raw_input().split())
    graph = []
    for r in range(N):
        rotated_row = []
        row = raw_input()
        for c in row:
            if not c is '.':
                rotated_row.append(c)
        row = ['.'] * (N-len(rotated_row)) + rotated_row
        graph.append(row)
    print graph
    for i in range(N):
        for j in range(N):
            # test right
            graphdict = {'B':0,'R':0}
            for k in range(K):
                t = j + k
                if t > (N-1):
                    break
                if graph[i][t] in graphdict:
                    graphdict[graph[i][t]] += 1
                    if (graphdict[graph[i][t]] == K):
                        print graphdict[graph[i][t]]
            # test down
            graphdict = {'B':0,'R':0}
            for k in range(K):
                t = j + k
                if t > (N-1):
                    break
                if graph[t][j] in graphdict:
                    graphdict[graph[t][j]] += 1
                    if (graphdict[graph[t][j]] == K):
                        print graphdict[graph[t][j]]
            # test diagonal right TODO
            graphdict = {'B':0,'R':0}
            for k in range(K):
                t = j + k
                if t > (N-1):
                    break
                if graph[i][t] in graphdict:
                    graphdict[graph[i][t]] += 1
                    if (graphdict[graph[i][t]] == K):
                        print graphdict[graph[i][t]]
            # test diagonal down TODO
            graphdict = {'B':0,'R':0}
            for k in range(K):
                t = j + k
                if t > (N-1):
                    break
                if graph[t][j] in graphdict:
                    graphdict[graph[t][j]] += 1
                    if (graphdict[graph[t][j]] == K):
                        print graphdict[graph[t][j]]

