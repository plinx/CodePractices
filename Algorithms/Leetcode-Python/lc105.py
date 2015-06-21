__author__ = 'linx'

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    pass

class Solution(object):
    def buildTree(self, preorder, inorder):
        node = None
        stack = []

        for i in xrange(len(preorder)):
            node = TreeNode(preorder[i])
            if stack != []:
                if inorder.index(node.val) < inorder.index(stack[0].val):
                    stack[0].left = node
                    stack.insert(0, node)
                else:
                    while stack != []:
                        if inorder.index(stack[0].val) < inorder.index(node.val):
                            stack.pop(0)

                    print node.val
                    stack[0].right = node
                    stack.insert(0, node)
            else: # stack is empty
                stack.insert(0, node)

        #print stack[-1].left, stack[-1].right
        return stack[-1]
    pass

if __name__ == '__main__':
    preorder = [1, 2, 4, 5, 3, 6, 7]
    inorder = [4, 2, 5, 1, 6, 3, 7]
    #preorder = [1, 2, 3]
    #inorder = [2, 1, 3]
    tree = Solution().buildTree(preorder, inorder)
    print tree.left.right.left.val

    #print tree.right.val
    pass

