__author__ = 'linx'

from random import randint

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

def preorder_traver(root):
    if root is None:
        return
    preorder_traver(root.left)
    print root.val,
    preorder_traver(root.right)

    pass

class Solution(object):
    def dfsBST(self, nums, left, right):
        if left < right:
            mid = (left + right) / 2
            root = TreeNode(nums[mid])
            root.left = self.dfsBST(nums, left, mid)
            root.right = self.dfsBST(nums, mid + 1, right)
            return root

        pass
    def sortedArrayToBST(self, nums):
        if nums == []:
            return None
        return self.dfsBST(nums, 0, len(nums))
        pass
    pass

if __name__ == '__main__':
    table = []
    for i in xrange(1):
        table.append(randint(0, 100))
    table.sort()

    tree = Solution().sortedArrayToBST(table)
    preorder_traver(tree)
    pass
