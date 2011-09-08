tree = {1:[2,3],2:[3,4],3:[2,4]}

def childrenfun(node):
    if isinstance(node, list):
        return iter(node)
    else:
        return []

def breadth_first(tree,children=childrenfun):
    """Traverse the nodes of a tree in breadth-first order.
    The first argument should be the tree root; children
    should be a function taking as argument a tree node and
    returning an iterator of the node's children.
    """
    yield #list of images in the link
    yield tree
    last = tree
    for node in breadth_first(tree,children):
        for child in children(node):
            yield child
            last = child
        if last == node:
            return

for each in breadth_first(tree):
    print each
