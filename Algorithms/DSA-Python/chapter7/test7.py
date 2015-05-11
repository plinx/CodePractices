__author__ = 'linx'

import unittest
from inc.linkedstack import LinkedStack
from inc.linkedqueue import LinkedQueue
from inc.linkeddeque import LinkedDeque
from chapter7.C import Creativity

class cpt7(unittest.TestCase):
    def test_LinkedStack(self):
        stack = LinkedStack()
        self.assertEqual(stack.is_empty(), True)
        stack.push(1)
        stack.push(3)
        self.assertEqual(stack.top(), 3)
        self.assertEqual(len(stack), 2)
        stack.pop()
        stack.push(5)
        stack.push(7)
        self.assertEqual(stack.is_empty(), False)
        self.assertEqual(stack.top(), 7)

    def test_LinkedQueue(self):
        queue = LinkedQueue()
        self.assertEqual(queue.is_empty(), True)
        queue.enqueue(1)
        queue.enqueue(3)
        self.assertEqual(queue.first(), 1)
        self.assertEqual(len(queue), 2)
        queue.dequeue()
        queue.enqueue(5)
        queue.enqueue(7)
        self.assertEqual(queue.is_empty(), False)
        self.assertEqual(queue.first(), 3)

    def test_LinkedDeque(self):
        queue = LinkedDeque()
        self.assertEqual(queue.is_empty(), True)
        queue.add_first(1)
        queue.add_first(3)
        queue.add_first(5)
        self.assertEqual(len(queue), 3)
        self.assertEqual(queue.first(), 5)
        self.assertEqual(queue.last(), 1)
        queue.add_last(2)
        self.assertEqual(queue.last(), 2)
        queue.del_first()
        queue.del_first()
        self.assertEqual(queue.first(), 1)
        queue.del_first()
        queue.del_first()
        self.assertEqual(queue.is_empty(), True)
        queue.add_last(4)
        queue.add_last(6)
        self.assertEqual(queue.first(), 4)
        self.assertEqual(queue.last(), 6)
        self.assertEqual(queue.is_empty(), False)

    # P2.26
    def test_append_queue(self):
        q1 = LinkedQueue()
        q2 = LinkedQueue()
        q1.enqueue(1)
        q1.enqueue(3)
        q2.enqueue(2)
        q2.enqueue(4)
        q1.append_queue(q2)
        self.assertEqual(len(q1), 4)
        self.assertEqual(q1.first(), 1)
        q1.dequeue()
        q1.dequeue()
        self.assertEqual(q1.first(), 2)

    # P2.28
    def test_recursive_reverse(self):
        c = Creativity()
        l1 = c.ListNode(1, None)
        l2 = c.ListNode(2, l1)
        l3 = c.ListNode(3, l2)
        self.assertEqual(l3._elem, 3)
        self.assertEqual(l3._next._elem, 2)
        self.assertEqual(l3._next._next._elem, 1)

        [nl, tail] = c.recursive_reverse(l3)
        self.assertEqual(nl._elem, 1)
        self.assertEqual(nl._next._elem, 2)
        self.assertEqual(nl._next._next._elem, 3)

    # P2.29
    def test_insert_reverse(self):
        c = Creativity()

        l1 = c.ListNode(1, None)
        l2 = c.ListNode(2, l1)
        l3 = c.ListNode(3, l2)
        self.assertEqual(l3._elem, 3)
        self.assertEqual(l3._next._elem, 2)
        self.assertEqual(l3._next._next._elem, 1)

        nl = c.insert_reverse(l3)
        self.assertEqual(nl._elem, 1)
        self.assertEqual(nl._next._elem, 2)
        self.assertEqual(nl._next._next._elem, 3)



    pass

if __name__ == '__main__':
    unittest.main()
