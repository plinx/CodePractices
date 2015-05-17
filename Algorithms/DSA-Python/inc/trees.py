__author__ = 'linx'

class BinarySearchTree(object):
    class _Node(object):
        __slots__ = "_elem", "_left", "_right"
        def __init__(self, elem, left, right):
            self._elem = elem
            self._left = left
            self._right = right
        pass

    def __init__(self):
        self._root = None

    def is_empty(self):
        return self._root == None

    def find(self, elem):
        if self.is_empty():
            raise ValueError("Tree is empty.")
        return self._find(elem, self._root)

    def _find(self, elem, pos):
        if pos == None:
            return False
        if elem == pos._elem:
            return True
        elif elem < pos._elem:
            return self._find(elem, pos._left)
        else: # elem > pos._elem
            return self._find(elem, pos._right)

    def insert(self, elem):
        self._root = self._insert(self._root, elem)

    def _insert(self, pos, elem):
        if pos == None:
            return self._Node(elem, None, None)
        elif elem < pos._elem:
            pos._left =  self._insert(pos._left, elem)
            return pos
        elif elem > pos._elem:
            pos._right = self._insert(pos._right, elem)
            return pos

    def remove(self, elem):
        if self.is_empty():
            raise ValueError("Tree is empty.")
        #self._root = self._remove(self._root, elem)

    def _remove(self, pos, elem):
        # error
        pass

    def travel_inorder(self):
        self._travle_inorder(self._root)

    def _travle_inorder(self, pos):
        if pos == None:
            return
        else:
            self._travle_inorder(pos._left)
            print pos._elem
            self._travle_inorder(pos._right)




    pass

