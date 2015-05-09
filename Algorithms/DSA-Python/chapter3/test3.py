__author__ = 'linx'

import unittest
from chapter3.R import Reinforcement

class cpt3(unittest.TestCase):
    # R3.2
    def test_cmp1(self):
        r = Reinforcement()
        self.assertEqual(r.cmp1(), 9)

    # R3.3
    def test_cmp2(self):
        r = Reinforcement()
        self.assertEqual(r.cmp2(), 21)

    # R3.6
    def test_even_sum(self):
        r = Reinforcement()
        self.assertEqual(r.even_sum(10), 110)

    # R3.7
    # obviously

    # R3.8
    # 2**10 < n * log(n) < 4n < 3n + 100log(n) < 2n + 4n * log(n) \
    # < n**2 + 10n < n**3 < 2**log(n) < 2**n

    # R3.9
    # d(n) <= f(n)
    # a * d(n) <= a * f(n)
    # O(a * d(n)) is O(a * f(n)) = O(f(n))

    # R3.10
    # d(n) <= f(n); e(n) <= g(n)
    # d(n) * e(n) <= f(n) * g(n)
    # O(d(n) * e(n)) is O(f(n) * g(n))

    # R3.11
    # obviously

    # R3.13
    # obviously

    # R3.14
    # max(f(n), g(n)) <= max(f(n), g(n)) + min(f(n), g(n))
    # max(f(n), g(n)) <= f(n) + g(n)
    # O(max(f(n), g(n)) = O(f(n) + g(n))

    # R3.15 - R3.x
    # skip




if __name__ == '__main__':
    unittest.main()
