__author__ = 'linx'

from math import sqrt

class Solution(object):
    def mySqrt(self, x):
        if x == 0:
            return 0

        left, right = 1, 2**31
        while True:
            mid = left + (right - left) / 2
            if (x / mid) < mid:
                right = mid - 1
            else:
                if (x / (mid + 1)) < (mid + 1):
                    return mid
                left = mid + 1
        pass
    pass

if __name__ == '__main__':
    print Solution().mySqrt(1)
    print int(sqrt(75))
    pass
