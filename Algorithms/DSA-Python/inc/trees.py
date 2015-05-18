__author__ = 'linx'

class TreeBase(object):
    class _Item(object):
        def __init__(self, key, value):
            self._key = key
            self._value = value

    class _Node(object):
        def __init__(self, item, parent, left, right):
            self._item = item
            self._parent = parent
            self._left = left
            self._right = right
    pass

class BinarySearchTree(TreeBase):
    def __init__(self):
        self._root = None

    def is_empty(self):
        return self._root == None

    def find(self, key):
        if self.is_empty():
            raise ValueError("Tree is empty.")
        return self._find(key, self._root)

    def _find(self, key, pos):
        if pos == None:
            return False
        if key < pos._item._key:
            return self._find(key, pos._left)
        elif key > pos._item._key:
            return self._find(key, pos._right)
        else: # elem == pos._elem:
            return True

    def insert(self, key, value):
        if self.is_empty():
            self._root = self._Node(self._Item(key, value), None, None, None)
            return
        self._insert(key, value, self._root, None)

    def _insert(self, key, value, pos, parent):
        if pos == None:
            return self._Node(self._Item(key, value), parent, None, None)
        elif key < pos._item._key:
            pos._left =  self._insert(key, value, pos._left, pos)
            return pos
        else: # key > pos._item._key:
            pos._right = self._insert(key, value, pos._right, pos)
            return pos

    def remove(self, key):
        if self.is_empty():
            raise ValueError("Tree is empty.")
        if key != self._root._item._key:
            self._remove(key, self._root)
        else: # remove root key
            if self._root._left == None:
                if self._root._right == None:
                    self._root = None
                else:
                    self._root = self._root._right
            else:
                if self._root._right == None:
                    self._root = self._root._left
                else:
                    rpos = self._root._left
                    while rpos._right != None:
                        rpos = rpos._right
                    self._root._item = rpos._item
                    rpos = rpos._parent
                    rpos._right = None

    def _remove(self, key, pos):
        if key < pos._item._key:
            self._remove(key, pos._left)
        elif key > pos._item._key:
            self._remove(key, pos._right)
        else: # key == pos._item._key:
            parent = pos._parent
            if pos._left == None:
                if pos == parent._left:
                    parent._left = pos._right
                else:
                    parent._right = pos._right
            elif pos._right == None:
                if pos == parent._right:
                    parent._left = pos._left
                else:
                    parent._right = pos._left
            else:
                rpos = pos._left
                while rpos._right != None:
                    print rpos._item._key
                    rpos = rpos._right
                pos._item = rpos._item
                parent = rpos._parent
                if rpos == parent._left:
                    parent._left = None
                else: # rpos = parent._right
                    parent._right = None

        pass

    def travel_inorder(self):
        self._travle_inorder(self._root)

    def _travle_inorder(self, pos):
        if pos == None:
            return
        else:
            self._travle_inorder(pos._left)
            print (pos._item._key, pos._item._value),
            self._travle_inorder(pos._right)


    pass

