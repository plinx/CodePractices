__author__ = 'linx'

from sys import getsizeof
from time import time
from time import sleep

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
    def str_efficiency(self):
        str1, str2, str3, str4 = "", "", "", ""
        t = []
        start = time()
        for i in xrange(100000):
            str1 += "l"
        t.append(time() - start)
        start = time()
        temp = []
        for i in xrange(100000):
            temp.append('l')
        str2 = ''.join(temp)
        t.append(time() - start)
        start = time()
        # most efficiency
        str3 = ''.join(['l' for i in xrange(100000)])
        t.append(time() - start)
        start = time()
        str4 = ''.join('l' for i in xrange(100000))
        t.append(time() - start)

        if str1 == str2 == str3 == str4:
            print t

    # C5.22
    # skip

    # C5.23
    # comprehension is more fast

    # C5.24
    # skip

    # C5.25
    def remove_all(self, data, value):
        temp = []
        for i in xrange(len(data)):
            if data[i] != value:
                temp.append(data[i])

        return temp



    pass
