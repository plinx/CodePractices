__author__ = 'linx'

from unittest import TestCase
from unittest import main
from chapter8.sorts import Sorts

class UT8(TestCase):
    #8.1-1
    #minimun degree : 1

    def test_count_sort(self):
        A = [2, 5, 3, 0, 2, 3, 0, 3]
        B = [0] * 8
        Sorts().count_sort(A, B, 6)
        print A, B
        pass

    def test_e821(self):
        A = [6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2]
        B = [0] * 11
        Sorts().count_sort(A, B, 7)
        print A, B
        pass

    def test_e823(self):
        A = [6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2]
        B = [0] * 11
        Sorts().count_sort_up(A, B, 7)
        print A, B
        pass

    def test_radix_sort(self):
        A = [421, 240, 35, 532, 305, 430, 134]
        Sorts().radix_sort(A, 3)
        print A
        pass

    #8.3-1
    def test_e831(self):
        A = ["COW", "DOG", "SEA", "RUG", "ROW", "MOB", "BOX",
             "TAB", "BAR", "EAR", "TAR", "DIG", "BIG", "TEA", "NOW", "FOX"]
        Sorts().radix_sort_str(A, 3)
        print A
        pass

    pass




if __name__ == '__main__':
    main()

