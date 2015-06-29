__author__ = 'linx'

from time import time

class Solution(object):
    def myPow(self, x, n):
        if n == 0:
            return 1.0
        if n < 0:
            n = -n
            x = 1 / x

        return self.myPow(x * x, n / 2) if n % 2 is 0 \
            else x * self.myPow(x * x, n / 2)
        pass
    pass

if __name__ == '__main__':
    start = time()
    print Solution().myPow(10.5, 6)
    end = time()
    print 10.5**6
    print end - start
    pass
