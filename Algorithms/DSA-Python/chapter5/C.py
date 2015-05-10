__author__ = 'linx'

from sys import getsizeof
from time import time

class Creativity(object):
    # C5.13
    def nonempty(self):
        data1, data2 = [], [1, 2, 3, 4, 5]
        for i in xrange(1, 6):
            data1.append(i)

        for i in xrange(6, 20):
            print getsizeof(data1), getsizeof(data2)
            data1.append(i)
            data2.append(i)

    # C5.14 - 5.15
    # skip

    # C5.16
    # implement in R5.6 pop(self, obj)

    # C5.17-5.20
    # skip, I'm not good at proof the algorithms

    # C5.21
    # eating dinner






    pass
