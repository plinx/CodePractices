__author__ = 'linx'

from inc.ArrayStack import ArrayStack
from inc.ArrayQueue import ArrayQueue
from time import time

class Creativity(object):
    # pick 6.20, 6.22, 6.27
    # C6.20
    # keep it

    # C6.22
    def postfix_notation(self):
        op = "(+-*/"
        op_stack = ArrayStack()
        value_stack = ArrayStack()
        normal = raw_input("Input normal notation : ")
        for c in normal:
            if c == ' ':
                continue

            if op.find(c) != -1:
                op_stack.push(c)
            elif c == ')':
                # turn the operator from op_stack to value_stack
                value_stack.push(op_stack.pop())
                # pop '('
                op_stack.pop()
            else:
                value_stack.push(c)

        while not op_stack.is_empty():
            if op_stack.top() == '(':
                print "Error : operator don't match."
                return
            else:
                value_stack.push(op_stack.pop())

        str = [None] * len(value_stack)
        index = len(str) - 1
        while not value_stack.is_empty():
            str[index] = value_stack.pop()
            index -= 1

        print "Output postfix notation : " + ''.join(str)

    # C6.27
    def check_key(self, key, stack):
        q = ArrayQueue()
        while not stack.is_empty():
            if stack.top() != key:
                q.enqueue(stack.pop())
            else:
                break

        if stack.is_empty():
            ret = False
        else:
            ret = True

        # reverse the string twice to get original order
        length = len(q)
        for i in xrange(length):
            stack.push(q.dequeue())

        for i in xrange(length):
            q.enqueue(stack.pop())

        while not q.is_empty():
            stack.push(q.dequeue())

        return ret





    pass
