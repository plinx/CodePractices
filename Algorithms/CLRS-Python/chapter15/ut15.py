__author__ = 'linx'

from unittest import TestCase
from unittest import main
from time import time
from chapter15.dp import DP

class UT15(TestCase):
    def test_cur_rod(self):
        dp = DP()
        table = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
        start = time()
        for i in xrange(50):
            dp.cur_rod(table, 10)
        self.assertEqual(dp.cur_rod(table, 10), 30)
        print "cut rod : ", time() - start,
        start = time()
        for i in xrange(50):
            dp.memoized_cur_rod(table, 10)
        self.assertEqual(dp.memoized_cur_rod(table, 10), 30)
        print time() - start,
        start = time()
        for i in xrange(50):
            dp.bottom_up_cur_rod(table, 10)
        self.assertEqual(dp.bottom_up_cur_rod(table, 10), 30)
        print time() - start

        pass

    #15.1-1
    # T(0) = 1, T(n) = 1 + T(n - 1) + ...
    # T(n - 1) = 1 + T(n - 2) + ...
    # T(n) - T(n - 1) = 1 + T(n - 1)
    # T(n) = 2 * T(n - 1)
    # 2**n = 2 * 2**(n - 1)

    #15.1-4
    def test_cut_rod_result(self):
        table = [1, 5, 8, 9, 10, 17, 17, 20, 24, 30]
        dp = DP()
        self.assertEqual(dp.bottom_up_cur_rod_result(table, 10), (30, 10))
        pass

    #15.1-5
    def test_fib(self):
        dp = DP()
        start = time()
        self.assertEqual(dp.fib_r(25), 75025)
        print "fib : ", time() - start,
        start = time()
        self.assertEqual(dp.fib_dp(25), 75025)
        print time() - start
        pass





    pass


if __name__ == '__main__':
    main()
