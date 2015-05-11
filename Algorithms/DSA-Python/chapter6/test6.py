__author__ = 'linx'

import unittest
from inc.arraystack import ArrayStack
from inc.arrayqueue import ArrayQueue
from inc.arraydeque import ArrayDeque
from chapter6.C import Creativity

class cpt6(unittest.TestCase):
    # ArrayStack basic test
    def test_ArrayStack(self):
        s = ArrayStack()
        s.push(5)
        s.push(3)
        self.assertEqual(len(s), 2)
        s.pop()
        self.assertEqual(s.is_empty(), False)
        s.pop()
        self.assertEqual(s.is_empty(), True)
        s.push(7)
        s.push(9)
        self.assertEqual(s.top(), 9)
        s.push(4)
        self.assertEqual(len(s), 3)

    # ArrayQueue basic test
    def test_ArrayQueue(self):
        q = ArrayQueue()
        self.assertEqual(q.is_empty(), True)
        self.assertEqual(len(q._data), 10)
        for i in xrange(15):
            q.enqueue(i)
        #print q._data
        self.assertEqual(q.first(), 0)
        q.dequeue()
        self.assertEqual(q.first(), 1)
        for i in xrange(10):
            q.dequeue()
        self.assertEqual(q.first(), 11)
        self.assertEqual(len(q), 4)
        self.assertEqual(len(q._data), 10)
        self.assertEqual(q.is_empty(), False)

    # ArrayDeque basic test
    def test_ArrayDeque(self):
        d = ArrayDeque()
        self.assertEqual(d.is_empty(), True)
        d.add_first(5)
        d.add_last(3)
        d.add_first(7)
        #print d._data
        self.assertEqual(d.first(), 7)
        d.delete_first()
        #print d._data
        self.assertEqual(d.first(), 5)
        d.delete_first()
        self.assertEqual(d.first(), 3)
        d.add_first(6)
        d.add_first(8)
        self.assertEqual(d.last(), 3)
        d.delete_last()
        #print d._data
        self.assertEqual(d._size, 2)
        self.assertEqual(d.last(), 6)
        #print d._data

    def test_postfix_notation(self):
        c = Creativity()
        # should test it in main
        #c.postfix_notation()

    def test_check_key(self):
        c = Creativity()
        stack = ArrayStack()
        old_stack = ArrayStack()
        for i in xrange(10):
            stack.push(i)
            old_stack.push(i)
        self.assertEqual(c.check_key(5, stack), True)
        self.assertEqual(stack.top(), old_stack.top())



if __name__ == '__main__':
    unittest.main()

