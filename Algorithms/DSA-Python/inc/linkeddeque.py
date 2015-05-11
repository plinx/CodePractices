__author__ = 'linx'

class LinkedDeque(object):
    # Double-ended queue implementation based on double linked list.

    # Nest _Node Class
    class _Node(object):
        # Lightweight, nonpublic class for storing a singly linked node.
        __slots__ = "_elem", "_prev", "_next"
        def __init__(self, elem, prev, next):
            self._elem = elem
            self._prev = prev
            self._next = next

    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def first(self):
        if self.is_empty():
            raise ValueError("Deque is empty.")
        return self._head._elem

    def last(self):
        if self.is_empty():
            raise ValueError("Deque is empty.")
        return self._tail._elem

    def add_first(self, elem):
        # _Node(self, elem, prev, next)
        new_node = self._Node(elem, None, self._head)
        if self.is_empty():
            self._tail = new_node
        else:
            self._head._prev = new_node

        self._head = new_node
        self._size += 1

    def add_last(self, elem):
        # _Node(self, elem, prev, next)
        new_node = self._Node(elem, self._tail, None)
        if self.is_empty():
            self._head = new_node
        else:
            self._tail._next = new_node

        self._tail = new_node
        self._size += 1

    def del_first(self):
        if self.is_empty():
            raise ValueError("Deque is empty.")
        if self._head._next != None:
            self._head = self._head._next
            self._head._prev = None
        else:
            self._head = None
            self._tail = None
        self._size -= 1

    def del_last(self):
        if self.is_empty():
            raise ValueError("Deque is empty.")
        if self._tail._prev != None:
            self._tail = self._tail._prev
            self._tail._next = None
        else:
            self._head = None
            self._tail = None
        self._size -= 1



    pass

