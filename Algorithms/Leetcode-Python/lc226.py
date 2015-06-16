__author__ = 'linx'

class Solution(object):
    def invertTree(self, root):
        if root == None or root.left == root.right == None:
            return root

        tmp = root.left
        root.left = self.invertTree(root.right)
        root.right = self.invertTree(tmp)

        return root
        pass
    pass

if __name__ == '__main__':
    pass
