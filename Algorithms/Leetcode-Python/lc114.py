__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

class Solution(object):
    def flatten(self, root):
        curr = root
        while curr is not None:
            prev = curr.left
            if prev is not None:
                while prev.right is not None:
                    prev = prev.right
                prev.right = curr.right
                curr.right = curr.left
                curr.left = None
            curr = curr.right
        pass

    pass

if __name__ == '__main__':
    #table = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
    #table = [2, 3, 4, 5, '#', 7]
    table = [2, '#', 3, 4, 5]
    #table = [2, '#', 3]

    #table = []
    #table = ['#', 2]
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

    Solution().flatten(tree)
    result, tmp = [], tree
    while tmp is not None:
        result.append(tmp.val)
        tmp = tmp.right

    print result


    pass

