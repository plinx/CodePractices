__author__ = 'linx'

from unittest import TestCase
from unittest import main
from chapter12.sorts import Sorts

class cpt12(TestCase):
    def test_arrMerge(self):
        s = Sorts()
        oldt = t = [1, 3, 2, 5, 4, 6, 9, 8, 0, 7]
        s.arr_mergeSort(t)
        oldt.sort()
        #print t, oldt
        self.assertEqual(t, oldt)
        #print t, oldt

    def test_lqMerge(self):
        s = Sorts()
        lq = Sorts.LinkQueue()
        t = [1, 3, 2, 5, 4, 6, 9, 8, 0, 7]
        for elem in t:
            lq.enqueue(elem)

        s.lq_mergeSort(lq)
        t.sort()
        self.assertEqual(lq.travel(), t)


    pass


if __name__ == '__main__':
    main()