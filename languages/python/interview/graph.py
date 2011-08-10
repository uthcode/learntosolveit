# Simplest possible graph.

class Graph:
    def __init__(self , d):
        self.d = d
    def v(self):
        return self.d.keys()
    def e(self, a, b):
        return b in self.d[a]

gobject = Graph({"a":["b","c"],"b":["e","c"],"c":["a","b"]})
print gobject.v()
print gobject.e("a","c")
print gobject.e("b","e")
