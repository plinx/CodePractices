# -*- coding : utf-8 -*-
__author__ = 'linx'

from math import log

class Reinforcement(object):
    # R3.1
    # drew it on text book

    # R3.2
    def cmp1(self):
        # 8n * log(n) < 2n**2 => 4n * log(n) < n
        for n in xrange(2, 30):
            ans1 = 4 * log(n)
            ans2 = n
            if ans1 > ans2:
                #print ans1, ans2
                continue
            else:
                return n

    # R3.3
    def cmp2(self):
        # 40n**2 < 2n**3 => 20 < n
        return 21

    # R3.4
    # skip

    # R3.5
    # log(n**c) = > clog(n)

    # R3.6
    def even_sum(self, num):
        #return sum([2 * i for i in xrange(num + 1)])
        # 0 + 2 + 4 + 6 + ... + (2n - 2) + 2n
        # => 2 * (1 + 2 + 3 + ... + (n - 1) + n) = > 2 * (n / 2) * (n + 1)
        # => n * (n + 1)
        return num * (num + 1)

    pass
