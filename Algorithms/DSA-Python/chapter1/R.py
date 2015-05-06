__author__ = 'linx'

from random import randrange

class Reinforcememt(object):
    # R1.1
    def is_multiple(self, n, m):
        i = n / m
        return True if m * i == n else False

    # R1.2
    def is_even(self, k):
        return True if k % 2 == 0 else False

    # R1.3
    def minmax(self, data):
        try:
            min, max = data[0], data[0]
        except:
            raise ValueError("Input data value error.")

        for d in data:
            min = d if d < min else min
            max = d if max < d else max

        return (min, max)

    # R1.4
    def sum1(self, max):
        ret = 0
        for i in range(1, max):
            ret += i

        return ret

    # R1.5
    def sum2(self, max):
        return sum(range(max))

    # R1.6
    def oddsum1(self, max):
        ret = 0
        for i in range(1, max):
            ret += i if i % 2 != 0 else 0

        return ret

    # R1.7
    def oddsum2(self, max):
        return sum([i for i in range(max) if i % 2 != 0])

    # R1.8
    def negative_indext(self):
        s = "string"
        for k in range(1, len(s)):
            if s[-k] != s[len(s) - k]:
                return False

        return True

    # R1.9
    # range(50, 81, 10)

    # R1.10
    # range(8, -9, -2)

    # R1.11
    # [2**x for x in range(0, 9)]

    # R1.12
    def choice(self, data):
        return data[randrange(len(data))]


