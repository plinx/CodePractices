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

    def test_lcs_mn(self):
        s1 = "ABCDE"
        s2 = "ACE"
        dp = DP()
        r = dp.lcs_mn(s1, s2)
        self.assertEqual("".join(dp.build_lcs(r, s1, s2)), "ACE")
        self.assertEqual(dp.lcs_m_n(s1, s2), 3)
        pass

    #15.4-1, 15.4-4
    def test_lcs_exercise(self):
        s1 = [1, 0, 0, 1, 0, 1, 0 ,1]
        s2 = [0, 1, 0, 1, 1, 0, 1, 1, 0]
        dp = DP()
        #15.4-1
        r = dp.lcs_mn(s1, s2)
        self.assertEqual(dp.build_lcs(r, s1, s2),
                         [1, 0, 1, 0, 1, 0])
        self.assertEqual(dp.lcs_m_n(s1, s2), 6)

        #15.4-4
        self.assertEqual(dp.lcs_m_n_2on(s1, s2), 6)
        self.assertEqual(dp.lcs_m_n_on(s1, s2), 6)

    #15.4-5
    def test_lis(self):
        s1 = [1, 1, 2, 3, 4, 1, 1, 1, 2, 3, 4, 5]
        s2 = [8, 8, 2, 3, 4, 8, 8, 1, 2, 3, 4, 5]
        s3 = [2, 3, 1, 2, 3, 4, 0, 0, 1, 2, 3, 1]
        s4 = [1, 1, 1, 2, 3, 0, 0, 0, 4, 5, 6, 7]
        s5 = [1, 1, 4, 5, 6, 0, 0, 0, 4, 5, 6, 7]
        s6 = [1, 1, 4, 5, 6, 0, 1, 2, 3, 4, 7, 8, 9]
        dp = DP()

        print dp.lis_with_sort_lcs(s3)
        print dp.lis_n2(s3)
        #self.assertEqual(dp.lis_n2(s5), [1, 2, 3, 4, 7, 8, 9])








    pass


if __name__ == '__main__':
    main()
