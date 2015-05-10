__author__ = 'linx'

class ArrayQueue(object):
    DEFAULT_CAPACITY = 10

    def __init__(self):
        self._data = [None] * self.DEFAULT_CAPACITY
        self._size = 0
        self._front = 0

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def first(self):
        if self.is_empty():
            raise ValueError("Queue is empty")
        return self._data[self._front]

    def dequeue(self):
        if self.is_empty():
            raise ValueError("Queue is empty")
        head = self._data[self._front]
        self._data[self._front] = None
        self._front = (self._front + 1) % len(self._data)
        self._size -= 1
        if 0 < self._size < len(self._data) / 4:
            self._resize(len(self._data) / 2)
        return head

    def enqueue(self, obj):
        if self._size == len(self._data):
            self._resize(2 * self._size)

        avail = (self._front + self._size) % len(self._data)
        self._data[avail] = obj
        self._size += 1

    def _resize(self, cap):
        if cap < self.DEFAULT_CAPACITY:
            if len(self._data) == self.DEFAULT_CAPACITY:
                return
            cap = self.DEFAULT_CAPACITY

        old_data = self._data
        self._data = [None] * cap
        walk = self._front
        for k in xrange(self._size):
            self._data[k] = old_data[walk]
            walk = (walk + 1) % len(old_data)
        self._front = 0

    pass



