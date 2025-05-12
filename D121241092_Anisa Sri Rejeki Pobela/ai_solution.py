# Definisi struktur Node untuk binary tree
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Fungsi untuk melakukan preorder traversal
def preOrder(root):
    if root is None:
        return
    print(root.data, end=' ')
    preOrder(root.left)
    preOrder(root.right)

# Contoh pembuatan tree sesuai sample input
# Tree yang dibentuk:
#     1
#      \
#       2
#        \
#         5
#        / \
#       3   6
#        \
#         4

# Membuat node satu per satu
root = Node(1)
root.right = Node(2)
root.right.right = Node(5)
root.right.right.left = Node(3)
root.right.right.right = Node(6)
root.right.right.left.right = Node(4)

# Memanggil fungsi preorder untuk mencetak hasil
preOrder(root)
