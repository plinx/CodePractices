__author__ = 'linx'

class LinkedQueue(object):
    # FIFO Queue implementation using a singly linked list for storage.

    # Nest _Node class
    class _Node(object):
        # Lightweight, nonpublic class for storing a singly linked node.
        __slots__ = "_elem", "_next"
        def __init__(self, elem, next):
            self._elem = elem
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
            raise ValueError("Queue is empty.")
        return self._head._elem

    def enqueue(self, elem):
        # we must create a new_node to storage the new element
        new_node = self._Node(elem, None)
        if self.is_empty():
            self._head = new_node
        else:
            self._tail._next = new_node

        self._tail = new_node
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            raise ValueError("Queue is empty.")

        ret = self._head._elem
        self._head = self._head._next
        self._size -= 1

        return ret

    # P7.26
    def append_queue(self, Q2):
        if Q2.is_empty():
            raise ValueError("Q2 is empty.")
        self._tail._next = Q2._head
        self._tail = Q2._tail
        self._size += Q2._size

    pass
