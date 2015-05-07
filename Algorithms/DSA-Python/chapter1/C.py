__author__ = 'linx'

from math import sqrt
from random import randint

class Creativity(object):
    # C1.13
    def reverse(self, data):
        rdata = data
        for i in range(len(rdata) / 2):
            rdata[i], rdata[-i - 1] = rdata[-i - 1], rdata[i]

        return rdata

    # C1.14
    def check_odd(self, data):
        for d in data:
            if d % 2 == 1:
                return True

        return False

    # C-1.15
    def check_same(self, data):
        for i in range(len(data)):
            for j in range(i + 1, len(data)):
                if data[i] == data[j]:
                    return True

        return False

    # C-1.16
    # list is mutable

    # C-1.17
    # it doesn't work
    # qus : 'for val in data : val *= factor' work properly?
    # ans : val is not a reference of data, it doesn't work

    # C-1.18
    # [ i * (i + 1) for i in xrange(10)]

    # C-1.19
    # [ chr(97 + i) for i in xrange(26)]

    # C-1.20
    def shuffle(self, data):
        for i in range(len(data)):
            j = randint(0, len(data) - 1)
            data[i], data[j] = data[j], data[i]

    # C-1.21
    def read_until_EOF(self):
        while True:
            try:
                str = raw_input("Enter : ")
            except EOFError:
                raise EOFError("End of input.")

    # C-1.22
    def mul_array(self, arr1, arr2):
        ret = []
        for i in xrange(len(arr1)):
            ret.append(arr1[i] * arr2[i])

        return ret

    # C-1.23
    def write_list(self, lst, index, data):
        try:
            lst[index] = data
        except IndexError:
            raise IndexError("Don't try buffer overflow attacks in Python.")

    # C-1.24
    def count_vowels(self, str):
        return sum([1 for s in str.lower() if s == 'a' or s == 'e'
                   or s == 'i' or s =='o' or s =='u'])


    # C-1.25
    def remove_punctuation(self, str):
        return str.replace(',', '').replace('.', '')

    # C-1.26
    # skip

    # C-1.27
    def fib(self, max):
        a, b = 0, 1
        for i in xrange(max):
            yield b
            a, b = b, a + b

    # C-1.28
    def norm(self, vlist, pow):
        return sqrt(sum([v**pow for v in vlist]))

