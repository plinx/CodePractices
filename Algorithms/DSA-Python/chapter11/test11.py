__author__ = 'linx'

from unittest import TestCase
from unittest import main
from inc.trees import BinarySearchTree

class cpt11(TestCase):
    def test_binarysearchtree(self):
        item = lambda x : [x, chr(ord('A') + x)]
        bst = BinarySearchTree()
        self.assertEqual(bst.is_empty(), True)
        bst.insert(item(10)[0], item(10)[1])
        self.assertEqual(bst.is_empty(), False)
        bst.insert(item(5)[0], item(5)[1])
        self.assertEqual(bst.find(5), True)
        bst.insert(item(15)[0], item(15)[1])
        bst.insert(item(1)[0], item(1)[1])
        bst.insert(item(7)[0], item(7)[1])
        bst.insert(item(6)[0], item(6)[1])
        bst.insert(item(8)[0], item(8)[1])
        #bst.travel_inorder()
        bst.remove(1)
        self.assertEqual(bst._root._left._left, None)
        bst.remove(10)
        self.assertEqual(bst._root._item._key, 8)
        #bst.travel_inorder()

    pass

if __name__ == '__main__':
    main()

