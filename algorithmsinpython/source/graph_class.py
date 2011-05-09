class Graph:
    def __init__(self, g):
        self.g = g

    def V(self):
        return list(self.g.keys())

    def Adj(self, v):
        return list(self.g[v].keys())

    def W(self, v, u):
        return self.g[v][u]
