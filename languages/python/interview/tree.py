class Tree:
    def __init__(self, value):
        self.node = value
        self.left = self
        self.right = self

obj = Tree(10)
print obj.node
print obj.left
print obj.right
