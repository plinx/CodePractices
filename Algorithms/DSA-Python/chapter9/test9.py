__author__ = 'linx'

from unittest import TestCase
from unittest import main
from inc.prioriryqueue import UnsortedPriorityQueue
from inc.prioriryqueue import SortedPriorityQueue

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

    pass

if __name__ == '__main__':
    main()

