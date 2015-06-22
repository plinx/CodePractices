__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

def buildTree_level(table):
    root = None
    queue = []
    for i in xrange(len(table)):
        node = TreeNode(table[i]) if table[i] != None else None
        if queue != []:
            if i % 2: # i = 2n + 1
                queue[0].left = node
            else: # i = 2n
                queue[0].right = node
                if queue[0].left != None:
                    queue.append(queue[0].left)
                if queue[0].right != None:
                    queue.append(queue[0].right)
                queue.pop(0)
        else:
            root = node
            queue.append(node)

    return root
    pass

def preorder_travel(root):
    if root == None:
        return
    print root.val,
    preorder_travel(root.left)
    preorder_travel(root.right)
    pass

def inorder_travel(root):
    if root == None:
        return
    inorder_travel(root.left)
    print root.val,
    inorder_travel(root.right)

class Solution(object):
    def dfsPathSum(self, root):
        if root == None:
            return 0
        l = max(0, self.dfsPathSum(root.left))
        r = max(0, self.dfsPathSum(root.right))
        self.result = max(self.result, l + r + root.val)
        return root.val + max(l, r)
        pass
    def maxPathSum(self, root):
        self.result = -2147483648
        self.dfsPathSum(root)
        return self.result
        pass
    pass

if __name__ == '__main__':
    #nodes = [1, 2, 3, 4, 5, 6, None, 8]
    #nodes = [1, 2, 3]
    nodes = [2, -1]
    tree = buildTree_level(nodes)
    print Solution().maxPathSum(tree)

    print "[",
    preorder_travel(tree)
    print "]"
    print "[",
    inorder_travel(tree)
    print "]"

    pass

