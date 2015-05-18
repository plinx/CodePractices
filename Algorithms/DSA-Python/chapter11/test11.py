__author__ = 'linx'

from unittest import TestCase
from unittest import main
from inc.trees import BinarySearchTree
from inc.trees import AVLTree

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

    def test_avltree(self):
        item = lambda x : [x, chr(ord('A') + x)]
        avl1, avl2 = AVLTree(), AVLTree()
        avl3, avl4 = AVLTree(), AVLTree()
        self.assertEqual(avl1.is_empty(), True)
        for i in xrange(5, 0, -1):
            avl1.insert(item(i)[0], item(i)[1])
        self.assertEqual(avl1._root._item._value, "E")
        for i in xrange(5):
            avl2.insert(item(i)[0], item(i)[1])
        self.assertEqual(avl2.is_empty(), False)
        self.assertEqual(avl2._root._item._value, "B")

        avl3.insert(item(5)[0], item(5)[1])
        avl3.insert(item(1)[0], item(1)[1])
        avl3.insert(item(2)[0], item(2)[1])
        self.assertEqual(avl3._root._item._value, "C")

        avl4.insert(item(5)[0], item(5)[1])
        avl4.insert(item(9)[0], item(9)[1])
        avl4.insert(item(6)[0], item(6)[1])
        self.assertEqual(avl4._root._item._value, "G")


    pass

if __name__ == '__main__':
    main()

