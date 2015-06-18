__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

class Solution(object):
    # find a better way tomorrow!!!
    def isSymmetric(self, root):
        if root == None or root.left == root.right == None:
            return True

        queue = [root]
        tail = 0
        while queue != []:
            head = queue[0]
            if head != None:
                queue.append(head.left)
                queue.append(head.right)
            queue.pop(0)
            if tail == 0:
                #print queue
                #print head, tail
                n = len(queue)
                if n % 2: #
                    return False

                for i in xrange(n / 2):
                    if queue[i] == None or queue[n - i - 1] == None:
                        if queue[i] != queue[n - i - 1]:
                            return False
                        continue

                    if queue[i].val != queue[n - i - 1].val:
                        return False

                tail = n
                #tail = queue[n - 1] if n != 0 else None
            tail -= 1

        return True

        pass
    pass

if __name__ == '__main__':
    #table = [-42, -42, '#', 76, 76, '#', '#', 13, '#', 13]
    #table = [2, 2, '#', 3, '#', 3]
    #table = [2, 2, 3, 4, 4, 3]
    #table = [3, 9, 20, '#', '#', 15, 7]
    table = [2]

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

    print Solution().isSymmetric(tree)


    pass
