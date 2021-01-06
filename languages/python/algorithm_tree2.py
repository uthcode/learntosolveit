class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

n1 = Node(1)
n2 = Node(2)
n3 = Node(3,n1,n2)
n4 = Node(4)
n5 = Node(5,n4,n3)

print('Inorder')
def inorder(n):
    if n == None:
        return
    inorder(n.left)
    print(n.value)
    inorder(n.right)

inorder(n5)

print('Preorder')
def preorder(n):
    if n == None:
        return
    print(n.value)
    preorder(n.left)
    preorder(n.right)

preorder(n5)

print('Postorder')
def postorder(n):
    if n == None:
        return
    postorder(n.left)
    postorder(n.right)
    print(n.value)

postorder(n5)
