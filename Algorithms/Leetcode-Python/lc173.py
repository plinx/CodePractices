__author__ = 'linx'

# Definition for a  binary tree node
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class BSTIterator(object):
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.stack = list()
        self.pushAll(root)

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        return self.stack

    # @return an integer, the next smallest number
    def next(self):
        tmpNode = self.stack.pop()
        self.pushAll(tmpNode.right)
        return tmpNode.val

    def pushAll(self, node):
        while node is not None:
            self.stack.append(node)
            node = node.left

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())

def main():
    tree = TreeNode(2)
    tree.left = TreeNode(1)
    tree.right = TreeNode(9)
    tree.right.left = TreeNode(5)

    it, v = BSTIterator(tree), []
    while it.hasNext():
        v.append(it.next())

    print v

    pass

if __name__ == '__main__':
    main()
