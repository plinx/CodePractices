__author__ = 'linx'

from unittest import TestCase
from unittest import main
from time import time
from random import randint
from chapter6.heap import Heap

class UT6(TestCase):
    def test_max_heapify(self):
        max_arr1 = [ 1, 5, 8, 6, 4, 3, 2, 7, 9 ]
        max_arr2 = [ 1, 5, 8, 6, 4, 3, 2, 7, 9 ]
        Heap().max_heapify_recursive(max_arr1, 0)
        Heap().max_heapify_nonrecursive(max_arr2, 0)
        #print max_arr1, max_arr2
        self.assertEqual(max_arr1, max_arr2)

        pass

    def test_build_heap(self):
        max_arr1 = [ 1, 5, 8, 6, 4, 3, 2, 7, 9 ]
        max_arr2 = [ 1, 5, 8, 6, 4, 3, 2, 7, 9 ]

        for i in xrange(10000):
            num = randint(1, 10000)
            max_arr1.append(num)
            max_arr2.append(num)

        start = time()
        Heap().build_heap_recursive(max_arr1)
        t1 = time() - start
        start = time()
        Heap().build_heap_nonrecursive(max_arr2)
        t2 = time() - start

        #print max_arr1, max_arr2
        self.assertEqual(max_arr1, max_arr2)
        #print t1, t2

        pass

    def test_e631(self):
        A = [ 5, 3, 17, 10, 84, 19, 6, 22, 9 ]
        Heap().build_heap_nonrecursive(A)
        print A
        pass

    def test_heap_sort(self):
        A = [ 5, 3, 17, 10, 84, 19, 6, 22, 9 ]
        Heap().heap_sort(A)
        print A
        pass

    pass


if __name__ == '__main__':
    main()
