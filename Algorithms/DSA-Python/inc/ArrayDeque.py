__author__ = 'linx'

class ArrayDeque(object):
    DEFAULT_CAPACITY = 10
    def __init__(self):
        self._data = [None] * self.DEFAULT_CAPACITY
        self._size = 0
        self._front = 0
        self._back = len(self._data) - 1

    def __len__(self):
        return self._size

    def is_empty(self):
        return self._size == 0

    def first(self):
        return self._data[self._front]

    def last(self):
        return self._data[self._back]

    def add_first(self, obj):
        if self._size == len(self._data):
            self._resize(2 * self._size)

        self._front -= 1
        if self._front < 0:
            self._front = self._front + len(self._data)
        self._data[self._front] = obj
        self._size += 1

    def add_last(self, obj):
        if self._size == len(self._data):
            self._resize(2 * self._size)

        self._back += 1
        if self._back == len(self._data):
            self._back = 0
        self._data[self._back] = obj
        self._size += 1

    def delete_first(self):
        self._front += 1
        if self._front == len(self._data):
            self._front = 0
        self._data[self._front - 1] = None
        self._size -= 1
        if 0 < self._size <= len(self._data) / 4:
            self._resize(len(self._data) / 2)

    def delete_last(self):
        self._back -= 1
        if self._back < 0:
            self._back += len(self._data)
        self._data[(self._back + 1) % len(self._data)] = None
        self._size -= 1

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

