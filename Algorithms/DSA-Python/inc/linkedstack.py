__author__ = 'linx'

class LinkedStack(object):
    # LIFO Stack implementation using a singly linked list for storage.

    # Nest _Node class
    class _Node(object):
        # Lightweight, nonpublic class for storing a singly linked node.
        __slots__ = "_elem", "_next"

        # Singly linked init
        def __init__(self, elem, next):
            self._elem = elem
            self._next = next

    # Stack init
    def __init__(self):
        self._head = None
        self._size = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def push(self, elem):
        self._head = self._Node(elem, self._head)
        self._size += 1

    def top(self):
        if self.is_empty():
            raise ValueError("Stack is empty.")
        return self._head._elem

    def pop(self):
        if self.is_empty():
            raise ValueError("Stack is empty.")

        ret = self._head._elem
        self._head = self._head._next
        self._size -= 1
        return ret

