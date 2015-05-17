__author__ = 'linx'

from unittest import TestCase
from unittest import main
from inc.prioriryqueue import UnsortedPriorityQueue
from inc.prioriryqueue import SortedPriorityQueue
from chapter9.C import Creativity

class cpt9(TestCase):
    def test_unsortedQueue(self):
        q = UnsortedPriorityQueue()
        self.assertEqual(len(q), 0)
        q.add(10, "C")
        q.add(5, "A")
        self.assertEqual(len(q), 2)
        self.assertEqual(q.min(), (5, "A"))
        q.remove_min()
        self.assertEqual(q.min(), (10, "C"))

    def test_sortedQueue(self):
        q = SortedPriorityQueue()
        self.assertEqual(len(q), 0)
        q.add(10, "C")
        q.add(5, "A")
        self.assertEqual(len(q), 2)
        self.assertEqual(q.min(), (5, "A"))
        q.remove_min()
        self.assertEqual(q.min(), (10, "C"))

    # C9.26
    def test_stack(self):
        s = Creativity.Stack()
        self.assertEqual(len(s), 0)
        s.push(1, "A")
        s.push(2, "B")
        self.assertEqual(s.top(), (2, "B"))
        self.assertEqual(s.pop(), (2, "B"))
        self.assertEqual(s.top(), (1, "A"))

    # C9.27
    def test_queue(self):
        q = Creativity.Queue()
        self.assertEqual(q.is_empty(), True)
        q.enquene(1, "A")
        q.enquene(2, "B")
        self.assertEqual(q.first(), (1, "A"))
        self.assertEqual(q.dequeue(), (1, "A"))
        self.assertEqual(q.first(), (2, "B"))
        self.assertEqual(len(q), 1)

    # C9.29
    def test_sortedqueue(self):
        q = Creativity.SortedPriorityQueue()
        self.assertEqual(len(q), 0)
        q.add(10, "C")
        q.add(5, "A")
        self.assertEqual(len(q), 2)
        self.assertEqual(q.min(), (5, "A"))
        q.remove_min()
        self.assertEqual(q.min(), (10, "C"))







    pass

if __name__ == '__main__':
    main()

