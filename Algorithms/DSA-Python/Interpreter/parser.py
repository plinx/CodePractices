__author__ = 'linx'

from abc import ABCMeta, abstractmethod
import acceptor

class Parser(object):

    pass

class Visitor(object):
    __metaclass__ = ABCMeta

    def __init__(self, dispatch):
        self._dispatch = dispatch

    def visit(self, elem):
        if not isinstance(elem, type(None)):
            elem.accept(self)

    def next(self):
        self.visit(self._dispatch)

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

if __name__ == '__main__':
    data = ['{', "a", "=", "[", "2.2", "]", "fuck", "=", "shit", "}", "\n"]
    dispatch = acceptor.Dispatch(data)
    visitor = Visitor(dispatch)
    visitor.next()


