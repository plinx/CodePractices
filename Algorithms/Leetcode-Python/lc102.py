__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

class Solution(object):
    # find a better way tomorrow!!!
    def levelOreder(self, root):
        if root == None:
            return []

        r = [[root.val], []]
        stack = [root]
        row = 1
        level_tail = root
        while stack != []:
            tmp = stack[0]
            if tmp.left != None:
                stack.append(tmp.left)
                r[row].append(tmp.left.val)
            if tmp.right != None:
                stack.append(tmp.right)
                r[row].append(tmp.right.val)

            if level_tail == stack[0]:
                #print "level_tail : ", level_tail.val
                level_tail = stack[len(stack) - 1]
                row += 1
                r.append([])
            stack.pop(0)

        return r[:row - 1]


        pass
    pass

if __name__ == '__main__':
    #table = [3, 9, 20, '#', '#', 15, 7]
    table = [2]

    tree = TreeNode(1)
    stack = [tree]
    index = 0
    while index < len(table):
        tmp = stack[0]
        if table[index] != '#':
            if index % 2:
                tmp.left = TreeNode(table[index])
                stack.append(tmp.left)
            else: # index = 2 * n
                tmp.right = TreeNode(table[index])
                stack.append(tmp.right)
        if index % 2 == 0: # index = 2 * n
            stack.pop(0)
        index += 1

    print Solution().levelOreder(tree)


    pass
