__author__ = 'linx'

import unittest
from chapter5.R import Reinforcement

class cpt5(unittest.TestCase):
    # R5.4, R5.6, R5.8
    def test_Array(self):
        arr = Reinforcement.Array()
        self.assertEqual(len(arr), 0)
        for i in xrange(20):
            arr.append(i)
        self.assertEqual(arr[5], 5)
        arr.insert(99)
        self.assertEqual(arr[0], 99)
        arr.pop(5) # pop '4'
        self.assertEqual(arr[5], 5)

    # R5.7
    def test_find_repeated(self):
        r = Reinforcement()
        table = [1, 3, 5, 2, 4, 1, 9]
        self.assertEqual(r.find_repeated(table), 1)

    pass

if __name__ == '__main__':
    unittest.main()
