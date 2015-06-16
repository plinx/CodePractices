__author__ = 'linx'

class Solution:
    def postorderTraversal(self, root):
        if root == None:
            return []
        if root.left == root.right == None:
            return [root.val]

        data = []
        data += self.postorderTraversal(root.left)
        data += self.postorderTraversal(root.right)
        data.append(root.val)

        return data
