__author__ = 'linx'

from abc import ABCMeta, abstractmethod

class AST(object):
    __metaclass__ = ABCMeta
    class _Node(object):
        __slots__ = "_elem", "_left", "_right"
        def __init__(self, elem = None, left = None, right = None):
            self._elem = elem
            self._left = left
            self._right = right
        pass

    @abstractmethod
    def __init__(self): pass
        #self._root = self._Node(None, None, None)
        #self._pos = self._root

    def _travel(self, node):
        if node._left == None:
            print node._elem,
        else:
            self._travel(node._left)
            print node._elem,
            self._travel(node._right)
    pass

class AssignTree(AST):
    def __init__(self):
        self._root = self._Node()
        self._root._left = self._Node()
        self._root._right = self._Node()
        self._curr = self._root

    @property
    def var(self):
        return self._curr._left._elem

    @var.setter
    def var(self, variable):
        self._curr._left._elem = variable

    @property
    def op(self):
        return self._curr._elem

    @op.setter
    def op(self, operator):
        self._curr._elem = operator

    @property
    def value(self):
        return self._curr._right._elem

    @value.setter
    def value(self, value):
        self._curr._right._elem = value

    def add_sub(self):
        self._curr = self._curr._right
        self._curr._left = self._Node()
        self._curr._right = self._Node()
        self._curr._left._elem = self._curr._elem

    def travel(self):
        self._travel(self._root)

    pass
