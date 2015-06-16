__author__ = 'linx'

class Solution:
    def preorderTraversal(self, root):
        if root == None:
            return []
        if root.left == root.right == None:
            return [root.val]

        data = [root.val]
        data += self.preorderTraversal(root.left)
        data += self.preorderTraversal(root.right)
        return data

