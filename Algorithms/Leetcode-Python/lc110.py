__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

class Solution(object):
    # top down approach
    """def depth(self, root):
        if root == None:
            return 0
        if root.left == root.right == None:
            return 1

        return 1 + max(self.depth(root.left), self.depth(root.right))
        pass

    def isBalanced(self, root):
        if root == None:
            return True
        #print self.depth(root.left), self.depth(root.right)
        if abs(self.depth(root.left) - self.depth(root.right)) <= 1:
            return self.isBalanced(root.left) and self.isBalanced(root.right)

        return False
        pass
    """

    # bottom up approach
    def dfsHeight(self, root):
        if root is None:
            return 0

        left = self.dfsHeight(root.left)
        if left is -1:
            return -1
        right = self.dfsHeight(root.right)
        if right is -1:
            return -1

        if 1 < abs(left - right):
            return -1
        return 1 + max(left, right)
        pass

    def isBalanced(self, root):
        return self.dfsHeight(root) is not -1
        pass

    pass

if __name__ == '__main__':
    #table = [2, 2, 3, 4, 4, 3]
    #table = [3, 9, 20, '#', '#', 15, 7]
    table = [2, '#', 1]

    tree = TreeNode(1)
    queue = [tree]
    index = 0
    #while index < len(table):
    for i in xrange(len(table)):
        tmp = queue[0]
        if table[i] != '#':
            if i % 2 == 0:
                tmp.left = TreeNode(table[i])
                queue.append(tmp.left)
            else: # index = 2 * n
                tmp.right = TreeNode(table[i])
                queue.append(tmp.right)
        if i % 2: # index = 2 * n
            queue.pop(0)

    #print tree.left.val, tree.right.val
    #print tree.left.left.val, tree.left.right.val
    #print tree.right.left.val, tree.right.right.val

    print Solution().isBalanced(tree)

    pass

