__author__ = 'linx'

from unittest import TestCase
from unittest import main
from inc.trees import BinarySearchTree

class cpt11(TestCase):
    def test_binarysearchtree(self):
        bst = BinarySearchTree()
        self.assertEqual(bst.is_empty(), True)
        bst.insert(10)
        self.assertEqual(bst.is_empty(), False)
        bst.insert(5)
        self.assertEqual(bst.find(5), True)
        bst.insert(15)
        bst.insert(1)
        bst.insert(7)
        bst.insert(6)
        bst.insert(8)
        #bst.remove(7)
        bst.travel_inorder()
    pass

if __name__ == '__main__':
    main()

