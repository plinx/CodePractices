__author__ = 'linx'

from abc import ABCMeta, abstractmethod
from re import match

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
            return String(value)
        if match("[0-9]", value):
            return Constant(value)
        if match("[+\-*/=]", value):
            return Operator(value)
        if match("[\[\]{}()\"]", value):
            return Scope(value)
        if match("\\n", value):
            return EOL(value)
        print value
        print "no match"

    def accept(self, visitor):
        if self._index != len(self._data):
            #print self._data[self._index]
            data_type = self._regex_type(self._data[self._index])
            self._index += 1
            visitor.visit(data_type)

    def prpr(self):
        print "prpr"

class String(Acceptor):
    def __init__(self, data):
        self._data = data

    def accept(self, visitor):
        #print "String : %s " % self._data
        if visitor.state in ["start", "normal"]:
            print "!! State : %s ==> " % visitor.state,
            visitor.tmp = self._data
            print visitor.vars
        elif visitor.state == "assign":
            print "State : %s ==> " % visitor.state,
            visitor.function[visitor.tmp].var = visitor.tmp
            visitor.function[visitor.tmp].op = "="
            visitor.function[visitor.tmp].value = str(visitor.vars[self._data])
            visitor.vars[visitor.tmp] = visitor.function[visitor.tmp].value
            visitor.state = "assigned"
            visitor.function[visitor.tmp].travel()
        elif visitor.state == "assigned":
            print "State : %s ==> " % visitor.state,
            #visitor.function[visitor.tmp].var = self._dat
            visitor.function[visitor.tmp].op = "+"
            visitor.function[visitor.tmp].value = str(visitor.vars[self._data])
            visitor.vars[visitor.tmp] = \
                str(float(visitor.function[visitor.tmp].var) +
                        float(visitor.function[visitor.tmp].value))
            visitor.state = "assigned"
            visitor.function[visitor.tmp].travel()
            print ""
            print visitor.vars
        visitor.next()

class Constant(Acceptor):
    def __init__(self, data):
        self._data = data

    def accept(self, visitor):
        #print "Constant : %s " % self._data
        print "State : %s ==> " % visitor.state,
        if visitor.state == "assign":
            visitor.vars[visitor.tmp] = self._data
            visitor.function[visitor.tmp].var = visitor.tmp
            visitor.function[visitor.tmp].op = "="
            visitor.function[visitor.tmp].value = self._data
            visitor.state = "assigned"
            visitor.function[visitor.tmp].travel()
        elif visitor.state == "assigned":
            visitor.vars[visitor.tmp] = str(float(self._data) +
                                            float(visitor.vars[visitor.tmp]))
            visitor.function[visitor.tmp].value = self._data
            visitor.function[visitor.tmp].travel()
        visitor.next()

class Operator(Acceptor):
    def __init__(self, data):
        self._data = data

    def accept(self, visitor):
        #print "Operator : %c " % self._data
        if visitor.state in ["start", "normal"]:
            visitor.state = "assign"
            visitor.function[visitor.tmp] = visitor.template("assigntree")
        elif visitor.state == "assigned":
            visitor.function[visitor.tmp].add_sub()
            visitor.function[visitor.tmp].op = self._data
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
        visitor.state = "normal"
        print ""
        #print "End of Line : \\n"
        visitor.next()

