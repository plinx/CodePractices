__author__ = 'linx'

from tokenizer import Tokenizer
from AST import AssignTree
import acceptor

class Parser(object):
#class Visitor(object):
    # variable list, function list and current state
    #__slots__ = "_vars", "_funcs", "_state", "_package", "_tmp"
    def __init__(self):
        self._vars = {}
        self._funcs = {"main" : {}}
        self._state = "start"
        self._tmp = ""
        self._function = self._funcs["main"]

    def dispatch(self, package):
        self._package = package

    def visit(self, elem):
        if not isinstance(elem, type(None)):
            elem.accept(self)

    def next(self):
        self.visit(self._package)

    def template(self, type):
        if type == "assigntree":
            return AssignTree()

    # state operator
    @property
    def state(self):
        return self._state

    @state.setter
    def state(self, state):
        self._state = state

    # current function
    @property
    def function(self):
        return self._function

    # tmp operator
    @property
    def tmp(self):
        return self._tmp

    @tmp.setter
    def tmp(self, tmp):
        self._tmp = tmp

    @property
    def vars(self):
        return self._vars

    @vars.setter
    def vars(self, value):
        self._vars = value

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

if __name__ == '__main__':
    token = Tokenizer()
    token.read("hello.txt")
    data = token.token()
    print data
    #data = ['{', "a", "=", "[", "2.2", "]", "fuck", "=", "shit", "}", "\n"]
    package = acceptor.Dispatch(data)
    p = Parser()
    p.dispatch(package)
    #p.vars["a"] = 1
    #p.vars["a"] = 2
    p.vars["prpr"] = 0
    #p.function["a"] = p._funcs["assgintree"]
    #p.function["b"] = p._funcs["assgintree"]
    #p.function["a"] = p._funcs["assgintree"]
    p.next()
    pass


