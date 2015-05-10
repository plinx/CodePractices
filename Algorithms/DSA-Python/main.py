#!/usr/bin/env python
# -*- coding : utf-8 -*-

# packages
from inc.ArrayStack import ArrayStack
from inc.ArrayQueue import ArrayQueue
from chapter6.C import Creativity


def main():
    c = Creativity()
    stack = ArrayStack()
    for i in xrange(1, 10):
        stack.push(i)
    print stack._data
    print c.check_key(5, stack)
    print stack._data
    pass

if __name__ == '__main__':
    main()

