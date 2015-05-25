__author__ = 'linx'

from unittest import TestCase
from unittest import main
from chapter13.text import Text
from time import time
from random import randint

class cpt13(TestCase):
    def test_bruteForce(self):
        str = "safasbasdfsasdfasfvasdaaabbbcccasdfasb"
        #substr = "aaabbbccca"
        str = ''.join([chr(65 + randint(0, 25)) for i in xrange(100000)]) + str
        begin = randint(0, 100000)
        substr = str[begin:begin + 15]
        t = Text()

        start = time()
        print t.bruteForce1(str, substr), time() - start
        self.assertEqual(t.bruteForce1(str, substr), begin)
        start = time()
        print t.bruteForce2(str, substr), time() - start
        self.assertEqual(t.bruteForce2(str, substr), begin)
        start = time()
        print t.boyerMoore(str, substr), time() - start
        self.assertEqual(t.boyerMoore(str, substr), begin)


        pass
    pass

if __name__ == '__main__':
    main()
