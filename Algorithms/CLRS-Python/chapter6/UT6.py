__author__ = 'linx'

from unittest import TestCase
from unittest import main
from chapter6.heap import Heap

class UT6(TestCase):
    def test_max_heapify(self):
        max_arr1 = [ 1, 5, 8, 6, 4, 3, 2, 7, 9 ]
        max_arr2 = [ 1, 5, 8, 6, 4, 3, 2, 7, 9 ]
        Heap().max_heapify_recursive(max_arr1, 0)
        Heap().max_heapify_nonrecursive(max_arr2)
        #print max_arr1, max_arr2
        self.assertEqual(max_arr1, max_arr2)

        pass
    pass


if __name__ == '__main__':
    main()
