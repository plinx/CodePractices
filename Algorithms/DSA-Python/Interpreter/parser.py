__author__ = 'linx'

class Parser(object):

    pass

class Stack(object):
    def __init__(self):
        self._data = []

    def __len__(self):
        return len(self._data)

    def is_empty(self):
        return len(self._data) == 0

    def push(self, obj):
        self._data.append(obj)

    def pop(self):
        if self.is_empty():
            raise ValueError("Stack is empty.")
        self._data.pop()

    def top(self):
        if self.is_empty():
            raise ValueError("Stack is empty.")
        return self._data[-1]

    pass

class Tree(object):

    pass