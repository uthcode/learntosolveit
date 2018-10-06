"""
Simplest possible graph representation.abs

In theory, Graph is represented with vertices "V" and edges "E". We use the same notation here.

Expected Output
---------------

['a', 'c', 'b']
True
True
"""

class Graph:
    def __init__(self , g):
        self.g = g

    def V(self):
        return self.g.keys()

    def E(self, node1, node2):
        return node2 in self.g[node1]

if __name__ == '__main__':
    gobject = Graph({"a":["b","c"],"b":["e","c"],"c":["a","b"]})
    print(gobject.V())
    print(gobject.E("a","c"))
    print(gobject.E("b","e"))
