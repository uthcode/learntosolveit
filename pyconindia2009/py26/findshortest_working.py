H = { 'A': ['C','D'],
      'B': ['A','D'],
      'C': ['D','E'],
      'D': ['E'],
      'E': []
    }

def find_shortest_path(graph, start, end, path=[]):
    path = path + [start]
    if start == end:
        return path
    if not graph.has_key(start):
        return None
    shortest = None
    for node in graph[start]:
        if node not in path:
            newpath = find_shortest_path(graph, node, end, path)
            if newpath:
                if not shortest or len(newpath) < len(shortest):
                    shortest = newpath
    return shortest


print find_shortest_path(H, 'B', 'E')
