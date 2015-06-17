__author__ = 'linx'

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def minDepth(self, root):
        if root == None:
            return 0
        if root.left == root.right == None:
            return 1

        if root.left == None or root.right == None:
            return self.minDepth(root.left) + self.minDepth(root.right) + 1

        return 1 + min(self.minDepth(root.left), self.minDepth(root.right))
