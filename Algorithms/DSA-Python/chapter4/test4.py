__author__ = 'linx'

import unittest
from chapter4.R import Reinforcement
from chapter4.C import Creativity


class cpt4(unittest.TestCase):
    # R4.1
    def test_find_max(self):
        r = Reinforcement()
        table = [1, 3, 5, 4, 2]
        self.assertEqual(r.find_max(table), 5)

    # C4.9
    def test_minmax(self):
        c = Creativity()
        table = [5, 2, 1, 3, 4, 7, 6]
        self.assertEqual(c.minmax(table), [1, 7])

    # C4.11
    def test_unique(self):
        c = Creativity()
        table = [1, 2, 4, 6, 5]
        self.assertEqual(c.unique(table), False)
        table.append(2)
        self.assertEqual(c.unique(table), True)

    # C4.12
    def test_product(self):
        c = Creativity()
        self.assertEqual(c.product(20, 10), 200)

    # C4.16
    def test_reverse(self):
        c = Creativity()
        self.assertEqual(c.reverse("pots&pans"), "snap&stop")

    # C4.17
    def test_palindrome(self):
        c = Creativity()
        self.assertEqual(c.palindrome("gohanggnahog"), True)

    # C4.19
    def test_left_even(self):
        c = Creativity()
        table = [1, 2, 1, 3, 5, 2, 4]
        self.assertEqual(c.left_even(table), [4, 2, 2, 3, 5, 1, 1])







    pass

if __name__ == '__main__':
    unittest.main()