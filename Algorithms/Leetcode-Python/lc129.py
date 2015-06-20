__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

class Solution(object):
    def sumR(self, root, x):
        if root.left is root.right is None:
            return x * 10 + root.val

        val = 0
        if root.left is not None:
            val += self.sumR(root.left, 10 * x + root.val)
        if root.right is not None:
            val += self.sumR(root.right, 10 * x + root.val)

        return val
        pass
    def sumNumbers(self, root):
        if root is None:
            return 0
        return self.sumR(root, 0)
        pass

    pass

if __name__ == '__main__':
    #table = [2, 2, 3, 4, 4, 3]
    #table = [3, 9, 20, '#', '#', 15, 7]
    #table = [2, '#', 1]
    table = [2, 3]
    #table = [0, '#', 0]

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

    print Solution().sumNumbers(tree)

    pass

