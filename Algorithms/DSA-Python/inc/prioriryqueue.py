__author__ = 'linx'

class PriorityQueueBase(object):
    class _Item(object):
        __slots__ = "_key", "_value"
        def __init__(self, key, value):
            self._key = key
            self._value = value

        def __lt__(self, other):
            return self._key < other._key

    def is_empty(self):
        return len(self) == 0

    pass

class UnsortedPriorityQueue(PriorityQueueBase):
    def __init__(self):
        self._data = []

    def _find_min(self):
        if self.is_empty():
            raise ValueError("Priority queue is empty.")
        min = self._data[0]
        for i in xrange(1, len(self._data)):
            if self._data[i] < min:
                min = self._data[i]
        return min

    def __len__(self):
        return len(self._data)

    def add(self, key, value):
        self._data.append(self._Item(key, value))

    def min(self):
        min = self._find_min()
        return (min._key, min._value)

    def remove_min(self):
        ret = self._find_min()
        self._data.remove(ret)
        return ret

class SortedPriorityQueue(PriorityQueueBase):
    def __init__(self):
        self._data = []

    def __len__(self):
        return len(self._data)

    def add(self, key, value):
        if self.is_empty():
            self._data.append(self._Item(key, value))
            return
        for i in xrange(len(self._data)):
            if self._data[i]._key < key:
                continue
            else:
                break

        self._data.insert(i, self._Item(key, value))

    def min(self):
        if self.is_empty():
            raise ValueError("Queue is empty.")
        return (self._data[0]._key, self._data[0]._value)

    def remove_min(self):
        if self.is_empty():
            raise ValueError("Queue is empty.")
        ret = self._data[0]
        self._data.pop(0)
        return (ret._key, ret._value)







