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

class AVLTree(TreeBase):
    def __init__(self):
        self._root = None

    def is_empty(self):
        return self._root == None

    def _height(self, pos):
        if pos == None:
            return 0
        else:
            return max(self._height(pos._left), self._height(pos._right)) + 1

    def insert(self, key, value):
        if self.is_empty():
            self._root = self._Node(self._Item(key, value), None, None, None)
            return
        self._insert(key, value, self._root, None)

    def _insert(self, key, value, pos, parent):
        if pos == None:
            return self._Node(self._Item(key, value), parent, None, None)
        elif key < pos._item._key:
            pos._left = self._insert(key, value, pos._left, pos)
            if self._height(pos._right) == self._height(pos._left) - 2:
                if key < pos._left._item._key:
                    #print "single left rotate"
                    pos = self._single_left_rotate(pos)
                else: # pos._left._item._key < key
                    #print "double left rotate"
                    pos._left = self._single_right_rotate(pos._left)
                    pos = self._single_left_rotate(pos)
            return pos
        elif pos._item._key < key:
            pos._right = self._insert(key, value, pos._right, pos)
            if self._height(pos._left) == self._height(pos._right) - 2:
                if pos._right._item._key < key:
                    #print "single right rotate"
                    pos = self._single_right_rotate(pos)
                else: # key < pos._right._item._key
                    #print "double right rotate"
                    pos._right = self._single_left_rotate(pos._right)
                    pos = self._single_right_rotate(pos)
            return pos
        pass

    def _single_left_rotate(self, pos):
        parent = pos._parent
        if parent != None:
            if pos == parent._left:
                parent._left = pos._left
                pos._left = parent._left._right
                parent._left._right = pos
                #print parent, self._root._right._item._key
                #print self._root._left._item._key
                #print self._root._left._right._item._key
                return parent._left
            else: # pos == parent._right
                parent._right = pos._left
                pos._left = parent._right._right
                parent._right._right = pos
                return parent._right
        else: # pos is root
            self._root = self._root._left
            pos._left = self._root._right
            self._root._right = pos
            return self._root

    def _single_right_rotate(self, pos):
        parent = pos._parent
        if parent != None:
            if pos == parent._left:
                parent._left = pos._right
                pos._right = parent._left._left
                parent._left._left = pos
                return parent._left
            else:
                parent._right = pos._right
                pos._right = parent._right._left
                parent._right._left = pos
                return parent._right
        else:
            self._root = self._root._right
            pos._right = self._root._left
            self._root._left = pos
            return self._root
    pass

class RBTree(object):
    class _Node(object):
        def __init__(self, elem, left, right, p):
            self._elem = elem
            self._left = left
            self._right = right
            self._p = p
        pass
    pass

