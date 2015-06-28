__author__ = 'linx'

from unittest import TestCase
from unittest import main
from chapter16.greedy import Greedy

class UT16(TestCase):
    def test_greedy(self):
        s = [1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]
        f = [4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]
        result = [[1, 4], [5, 7], [8, 11], [12, 16]]
        gd = Greedy()

        self.assertEqual(gd.recursive_activity_selector(s, f, 0), result)
        self.assertEqual(gd.greedy_activity_selector(s, f), result)

        #16.1-1
        self.assertEqual(gd.dp_greedy_activity(s, f), result)

        #16.1-2
        self.assertEqual(gd.greedy_activity_night(s, f), result)

        #16.1-3
        #   1---3 4---6
        #     2------------8
        #s: 0 2   1
        #f:     0     1    2
        #1) select s[0], f[0] as earliest starter is error
        #2) select s[0], f[0] for minimum overlap is error

        #16.1-5
        #dp or greedy with v between intersect activities

    def test_knapsack(self):
        sacks = [[1, 6], [2, 10], [3, 12]]
        gd = Greedy()

        print gd.dp_knapsack(sacks, 5)
        pass


    pass


if __name__ == '__main__':
    main()

