__author__ = 'linx'

import unittest
from chapter1.R import *
from chapter1.C import *

# chapter1 test
class cpt1(unittest.TestCase):
    # R1.1 test
    def test_is_multiple(self):
        r = Reinforcememt()
        self.assertEqual(r.is_multiple(20, 5), True)
        self.assertEqual(r.is_multiple(2, 3), False)

    # R1.2 test
    def test_is_even(self):
        r = Reinforcememt()
        self.assertEqual(r.is_even(10), True)
        self.assertEqual(r.is_even(11), False)

    # R1.3 test
    def test_minmax(self):
        r = Reinforcememt()
        table = [1, 3, 5, 9]
        self.assertTupleEqual(r.minmax(table), (1, 9))

    # R1.4
    def test_sum1(self):
        r = Reinforcememt()
        self.assertEqual(r.sum1(10), 45)

    # R1.5
    def test_sum2(self):
        r = Reinforcememt()
        self.assertEqual(r.sum2(10), 45)

    # R1.6
    def test_oddsum1(self):
        r = Reinforcememt()
        self.assertEqual(r.oddsum1(10), 25)

    # R1.7
    def test_oddsum2(self):
        r = Reinforcememt()
        self.assertEqual(r.oddsum2(10), 25)

    # R1.8
    def test_negative_index(self):
        r = Reinforcememt()
        self.assertEqual(r.negative_indext(), True)

    # R1.12
    def test_choice(self):
        r = Reinforcememt()
        data, outdata = [1, 3, 5], [2, 4, 6]
        self.assertIn(r.choice(data), data)
        self.assertNotIn(r.choice(outdata), data)

    # C1.13
    def test_reverse(self):
        c = Craetivity()
        data, rdata = [1, 2, 3], [3, 2, 1]
        #print c.reverse(data)
        self.assertEqual(c.reverse(data), rdata)

    # C1.14
    def test_check_odd(self):
        c = Craetivity()
        data = [2, 4, 6, 9]
        self.assertEqual(c.check_odd(data), True)
        data.pop(3)
        self.assertEqual(c.check_odd(data), False)


if __name__ == '__main__':
    unittest.main()

