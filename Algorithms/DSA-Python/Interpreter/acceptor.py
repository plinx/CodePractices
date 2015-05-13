__author__ = 'linx'

from abc import ABCMeta, abstractmethod
from re import match
from tokenizer import Tokenizer

class Acceptor(object):
    __metaclass__ = ABCMeta
    __slots__ = "_data"
    @abstractmethod
    def accept(self, visitor): pass

class Dispatch(Acceptor):
    def __init__(self, data):
        self._data = data
        self._index = 0

    def _regex_type(self, value):
        if match("[a-zA-Z]", value):
            return Variable(value)
        if match("[0-9]", value):
            return Constant(value)
        if match("[=]", value):
            return EqualSign(value)
        if match("[\[\]{}]", value):
            return Scope(value)
        if match("\\\n", value):
            return EOL(value)

    def accept(self, visitor):
        if self._index != len(self._data):
            #print self._data[self._index]
            data_type = self._regex_type(self._data[self._index])
            self._index += 1
            visitor.visit(data_type)

    def prpr(self):
        print "prpr"

class Variable(Acceptor):
    def __init__(self, data):
        self._data = data

    def accept(self, visitor):
        print "Variable : %s " % self._data
        visitor.next()

class Constant(Acceptor):
    def __init__(self, data):
        self._data = data

    def accept(self, visitor):
        print "Constant : %s "
        visitor.next()

class EqualSign(Acceptor):
    def __init__(self, data):
        self._data = data

    def accept(self, visitor):
        print "EqualSign : %s " % self._data
        visitor.next()

class Scope(Acceptor):
    def __init__(self, data):
        self._data = data

    def accept(self, visitor):
        print "Scope : %s " % self._data
        visitor.next()

class EOL(Acceptor):
    def __init__(self, data):
        self._data = data

    def accept(self, visitor):
        print "End of Line : \\n"
        visitor.next()

