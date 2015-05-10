__author__ = 'linx'

from sys import getsizeof
from ctypes import py_object

class Reinforcement(object):
    # R5.1
    def fragment51(self, num):
        data = []
        for k in xrange(num):
            a = len(data)
            b = getsizeof(data)
            print "Length : {0:3d}; Size in bytes : {1:4d}".format(a, b)
            data.append(None)
    # R5.2
    # skip

    # R5.3
    def fragment53(self):
        data = [i for i in xrange(26)]
        for k in xrange(len(data)):
            a = len(data)
            b = getsizeof(data)
            print "Length : {0:3d}; Size in bytes : {1:4d}".format(a, b)
            data.pop(26 - i - 1)

    # R5.4, R5.6, R5.8
    class Array(object):
        def __init__(self):
            self._n = 0
            self._capacity = 1
            self._A = self._make_array(self._capacity)

        def __len__(self):
            return self._n

        def __getitem__(self, item):
            if self._n < abs(item):
                raise IndexError('Index out of array')
            elif item < 0:
                return self._A[self._n + item]
            return self._A[item]

        def append(self, obj):
            if self._n == self._capacity:
                self._resize(2 * self._capacity)
            self._A[self._n] = obj
            self._n += 1

        def insert(self, obj):
            if self._n == self._capacity:
                B = self._make_array(2 * self._capacity)
                B[0] = obj
                for k in xrange(1, self._n):
                    B[k] = self.A[k - 1]
                self._A = B
                self._capacity *= 2
                self._n += 1
            else:
                for k in xrange(self._n, 0, -1):
                    self._A[k] = self._A[k - 1]
                self._A[0] = obj
                self._n += 1

        def pop(self, item):
            for k in xrange(item, self._n - 1):
                self._A[k] = self._A[k + 1]
            self._n -= 1
            if self._n == self._capacity / 4:
                self._resize(self._capacity / 2)

        def _resize(self, c):
            B = self._make_array(c)
            for k in range(self._n):
                B[k] = self._A[k]
            self._A = B
            self._capacity = c

        def _make_array(self, c):
            return (c * py_object)()

    # R5.7
    def find_repeated(self, A):
        A.sort()
        for i in xrange(len(A)):
            if A[i] == A[i + 1]:
                return A[i]

    pass
