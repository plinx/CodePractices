__author__ = 'linx'

from unittest import TestCase
from unittest import main
from random import randint
from time import time

from chapter2.sorts import insert_sort
from chapter2.sorts import insert_sort_up
from chapter2.sorts import select_sort
from chapter2.sorts import merge_sort_recursive
from chapter2.sorts import merge_sort_nonrecursive

class UT1(TestCase):
    def test_insert(self):
        arr = [5, 2, 4, 6, 1, 3]
        ans = [1, 2, 3, 4, 5, 6]
        insert_sort(arr)
        #print arr
        self.assertEqual(arr, ans)
        pass

    def test_e211(self):
        arr = [31, 41, 59, 26, 41, 58]
        ans = [26, 31, 41, 41, 58, 59]
        insert_sort(arr)
        #print arr
        self.assertEqual(arr, ans)
        pass

    def test_e212(self):
        arr = [31, 41, 59, 26, 41, 58]
        ans = [26, 31, 41, 41, 58, 59]
        ans.reverse()
        insert_sort_up(arr)
        #print arr
        self.assertEqual(arr, ans)
        pass

    def find(self, A, elem):
        for i in xrange(len(A)):
            if A[i] == elem:
                return i
        return -1
        pass

    def test_e213(self):
        A = [1, 3, 5, 2, 4, 6]
        self.assertEqual(self.find(A, 5), 2)
        self.assertEqual(self.find(A, 0), -1)
        pass

    def e214_sum(self, A, B):
        na, nb = len(A), len(B)
        n = 1 + (nb if na < nb else na)
        C = [0] * n

        inc = 0
        for i in xrange(1, len(C) + 1):
            if i <= na and i <= nb:
                sum = inc + A[na - i] + B[nb - i]
            elif i <= nb and na < i:
                sum = inc + B[nb - i]
            elif i <= na and nb < i:
                sum = inc + A[na - i]
            else:
                sum = inc

            C[n - i] = sum % 2
            inc = 0 if sum < 2 else 1

        return C
        pass

    def test_e214(self):
        A = [1, 0, 1, 1, 0, 0, 1, 0]
        B = [1, 0, 1, 1, 1]
        sum = [0, 1, 1, 0, 0, 1, 0, 0, 1]

        self.assertEqual(self.e214_sum(A, B), sum)
        #print self.e214_sum(A, B)

        pass

    def test_e222(self):
        arr = [5, 2, 4, 6, 1, 3]
        ans = [1, 2, 3, 4, 5, 6]
        select_sort(arr)
        self.assertEqual(arr, ans)
        pass

    def test_e232(self):
        arr = []
        narr = []

        size = 40
        for i in xrange(size):
            n = randint(0, size)
            arr.append(n)
            narr.append(n)


        start = time()
        merge_sort_recursive(arr, 0, size - 1)
        t1 = time() - start

        start = time()
        merge_sort_nonrecursive(narr)
        t2 = time() - start

        #print arr
        #print narr
        #print arr, narr
        #print t1, t2


    pass

if __name__ == '__main__':
    main()
