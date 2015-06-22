__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

class Solution(object):
    def buildTree(self, preorder, inorder):
        stack = []
        return stack[-1]

    def preorder_travel(self, root):
        if root == None:
            return
        if root.left == root.right == None:
            print root.val,
        else:
            print root.val,
            self.preorder_travel(root.left)
            self.preorder_travel(root.right)
        pass

    def inorder_travel(self, root):
        if root == None:
            return
        if root.left == root.right == None:
            print root.val,
        else:
            self.inorder_travel(root.left)
            print root.val,
            self.inorder_travel(root.right)
    pass

if __name__ == '__main__':
    preorder = [1, 2, 4, 5, 3, 6, 7]
    inorder = [4, 2, 5, 1, 6, 3, 7]
    #preorder = [1, 2, 3, 4, 5]
    #inorder = [4, 3, 2, 5, 1]
    tree = Solution().buildTree(preorder, inorder)

    Solution().preorder_travel(tree)
    print ""
    Solution().inorder_travel(tree)
    pass

