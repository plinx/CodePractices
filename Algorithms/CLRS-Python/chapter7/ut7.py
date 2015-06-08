__author__ = 'linx'

from unittest import TestCase
from unittest import main
from chapter7.qsort import qSort

class UT7(TestCase):
    def test_qsort(self):
        A = [ 2, 8, 7, 1, 3, 5, 6, 4 ]
        qSort().quicksort(A, 0, len(A) - 1)
        print "test_qsort :", A
        pass

    def test_e711(self):
        A = [13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11]
        qSort().quicksort(A, 0, len(A) - 1)
        print "test_e711 : ", A
        pass

    def test_e712(self):
        A = [2, 2, 2, 2, 2, 2, 2, 2]
        print "new partion : ", qSort().partition(A, 0, len(A) - 1)

    def test_714(self):
        A = [13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11]
        qSort().quicksort_up(A, 0, len(A) - 1)
        print "test_e714 : ", A
        pass

    def test_qsort_random(self):
        A = [13, 19, 9, 5, 12, 8, 7, 4, 21, 2, 6, 11]
        qSort().quicksort_random(A, 0, len(A) - 1)
        print "test_qsort_random : ", A
        pass

    pass

if __name__ == '__main__':
    main()
