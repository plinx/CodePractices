__author__ = 'linx'

import unittest
from chapter1.R import *
from chapter1.C import *
from chapter1.P import *

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
        c = Creativity()
        data, rdata = [1, 2, 3], [3, 2, 1]
        #print c.reverse(data)
        self.assertEqual(c.reverse(data), rdata)

    # C1.14
    def test_check_odd(self):
        c = Creativity()
        data = [2, 4, 6, 9]
        self.assertEqual(c.check_odd(data), True)
        data.pop(3)
        self.assertEqual(c.check_odd(data), False)

    # C1.15
    def test_check_same(self):
        c = Creativity()
        table = [1, 2, 3, 4, 5]
        self.assertEqual(c.check_same(table), False)
        table.append(1)
        self.assertEqual(c.check_same(table), True)

    # C1.20
    def test_shuffle(self):
        c = Creativity()
        t, table = [1, 2, 3, 4, 5], [1, 2, 3, 4, 5]
        self.assertNotEqual(c.shuffle(table), t)

    # C1.22
    def test_mul_array(self):
        c = Creativity()
        t1, t2, t3 = [1, 2, 3], [2, 2, 2], [2, 4, 6]
        self.assertEqual(c.mul_array(t1, t2), t3)

    # C1.24
    def test_count_vowels(self):
        c = Creativity()
        s = "abcde"
        self.assertEqual(c.count_vowels(s), 2)

    # C1.25
    def test_remove_punctiation(self):
        c = Creativity()
        pstr, npstr = "a, b.", "a b"
        self.assertEqual(c.remove_punctuation(pstr), npstr)

    # C1.27
    def test_fib(self):
        c = Creativity()
        f = c.fib(5)
        self.assertEqual(f.next(), 1)
        self.assertEqual(f.next(), 1)
        self.assertEqual(f.next(), 2)
        self.assertEqual(f.next(), 3)
        self.assertEqual(f.next(), 5)

    # C1.28
    def test_norm(self):
        c = Creativity()
        self.assertEqual(c.norm([3, 4], 2), 5)

    # Project test should be test in main.py
    # P1.29
    def test_str_perm(self):
        p = Project()
        table = ['c', 'a', 't', 'd', 'o', 'g']
        #p.str_perm(table, 0)

    # P1.30
    def test_divide_bytwo(self):
        p = Project()
        #print p.divide_two(2)

    # P1.32
    def test_calculator(self):
        p = Project()
        #p.calculator()


if __name__ == '__main__':
    unittest.main()

