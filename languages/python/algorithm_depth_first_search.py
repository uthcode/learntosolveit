def depth_first_search(startnode, goalnode):
    nodevisited = set()

    def search_from(node):
        if node in nodevisited:
            return False
        elif node is goalnode:
            return True
        else:
            nodevisited.add(node)
            return any(search_from(nextnode) for nextnode in node.successors)

    return search_from(startnode)
