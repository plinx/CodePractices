__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None
    pass

class Solution(object):
    def connect(self, root):
        if root is None or root.left is None and root.right is None:
            return

        curr = root
        head = curr.left
        prev = curr.left
        while curr is not None:
            if prev is curr.left:
                if curr.right is not None:
                    prev.next = curr.right



        pass

    pass

if __name__ == '__main__':
    #table = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
    #table = [2, 2, 3, 4, 4, 3]
    #table = [3, 9, 20, '#', '#', 15, 7]
    #table = [2, '#', 1]
    table = [2, 3, 4, 5, '#', 7]
    #table = [0, '#', 0]
    #table = [9, 20, 15, 7, '#', '#']

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

    Solution().connect(tree)
    print tree.left.left.next.next.val
    #print tree.left.next.left.next.val
    #print tree.left.left.next.next.val

    pass

