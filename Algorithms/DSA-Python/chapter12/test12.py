__author__ = 'linx'

from unittest import TestCase
from unittest import main
from chapter12.sorts import Sorts
from time import time
from random import randint

class cpt12(TestCase):
    def test_arrMerge(self):
        s = Sorts()
        oldt = t = [1, 3, 2, 5, 4, 6, 9, 8, 0, 7]
        for i in xrange(10000):
            num = randint(1, 10000)
            oldt.append(num)
            t.append(num)
        start = time()
        s.arr_mergeSort(t)
        print "arrMerge sort : %s" % (time() - start)
        oldt.sort()
        #print t, oldt
        self.assertEqual(t, oldt)
        #print t, oldt

    def test_lqMerge(self):
        s = Sorts()
        lq = Sorts.LinkQueue()
        t = [1, 3, 2, 5, 4, 6, 9, 8, 0, 7]
        for i in xrange(10000):
            t.append(randint(1, 10000))

        for elem in t:
            lq.enqueue(elem)

        start = time()
        s.lq_mergeSort(lq)
        print "lqMerge sort : %s" % (time() - start)
        t.sort()
        self.assertEqual(lq.travel(), t)

    def test_arrQuickSort(self):
        s = Sorts()
        t = [2, 1, 3, 5, 4]
        for i in xrange(10000):
            t.append(randint(1, 10000))

        oldt = t
        start = time()
        s.arr_quickSort(t)
        print "arrQuick sort : %s" % (time() - start)
        oldt.sort()
        self.assertEqual(t, oldt)
        #print t

    pass


if __name__ == '__main__':
    main()