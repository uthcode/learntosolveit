T = input()
for tc in range(T):
    print 'Case #%d:' %(tc+1),
    N, M = map(int, raw_input().split())
    available_paths = []
    required_paths = []
    for i in range(N):
        available_paths.append(raw_input())
    for i in range(M):
        required_paths.append(raw_input())
    print available_paths
    print required_paths
    tree = []
    for path in available_paths:
        nodes = [node for node in path.split('/') if node]
        for node in nodes:
            tree[node] = True



