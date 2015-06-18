__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

class Solution(object):
    # find a better way tomorrow!!!
    def levelOrederBottom(self, root):
        if root == None:
            return []

        r = [[root.val]]
        trees = [[root]]
        row = 0
        while row < len(trees):
            #r.append([])
            #trees.append([])
            for i in xrange(len(trees[row])):
                tmp = trees[row][i]
                if tmp.left == tmp.right == None:
                    continue
                elif row == len(trees) - 1:
                    r.append([])
                    trees.append([])

                if tmp.left != None:
                    trees[row + 1].append(tmp.left)
                    r[row + 1].append(tmp.left.val)
                if tmp.right != None:
                    trees[row + 1].append(tmp.right)
                    r[row + 1].append(tmp.right.val)
            row += 1

        r.reverse()
        return r


        pass
    pass

if __name__ == '__main__':
    table = [2, 2, 3, 4, 4, 3]
    #table = [3, 9, 20, '#', '#', 15, 7]
    #table = [2]

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

    print Solution().levelOrederBottom(tree)


    pass
