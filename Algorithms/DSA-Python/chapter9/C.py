__author__ = 'linx'

class Creativity(object):
    class _PriorityQueueBase(object):
        class _Item(object):
            __slots__ = "_key", "_value"
            def __init__(self, key, value):
                self._key = key
                self._value = value
            pass

        def __len__(self):
            return len(self)
        pass

    # C9.26
    class Stack(_PriorityQueueBase):
        def __init__(self):
            self._data = []

        def __len__(self):
            return len(self._data)

        def is_empty(self):
            return len(self._data) == 0

        def push(self, key, value):
            self._data.append(self._Item(key, value))

        def pop(self):
            if self.is_empty():
                raise ValueError("Stack is empty.")
            item = self._data.pop()
            return (item._key, item._value)

        def top(self):
            if self.is_empty():
                raise ValueError("Stack is empty.")
            item = self._data[len(self._data) - 1]
            return (item._key, item._value)

    # 9.27
    class Queue(_PriorityQueueBase):
        def __init__(self):
            self._data = []

        def __len__(self):
            return len(self._data)

        def is_empty(self):
            return len(self._data) == 0

        def enquene(self, key, value):
            self._data.append(self._Item(key, value))

        def dequeue(self):
            item = self._data.pop(0)
            return (item._key, item._value)

        def first(self):
            if self.is_empty():
                raise ValueError("Queue is empty.")
            return (self._data[0]._key, self._data[0]._value)

    # C9.29
    class SortedPriorityQueue(object):
        def __init__(self):
            self._data = []

        def __len__(self):
            return len(self._data)

        def is_empty(self):
            return len(self._data) == 0

        def add(self, key, value):
            if self.is_empty():
                self._data.append((key, value))
                return
            for i in xrange(len(self._data)):
                if self._data[i][0] < key:
                    continue
                else:
                    self._data.insert(i, (key, value))

        def min(self):
            return self._data[0]

        def remove_min(self):
            return self._data.pop(0)

        pass
    pass
