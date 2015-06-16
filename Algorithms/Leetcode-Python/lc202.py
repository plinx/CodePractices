__author__ = 'linx'

class Solution(object):
    def isHappy(self, n):
        ret = n

        sum = 0
        while ret != 0:
            sum += (ret % 10)**2
            ret /= 10
            if ret == 0:
                if 6 < sum:
                    print sum,
                    ret = sum
                    sum = 0
                else: # sum < 6
                    return True if sum == 1 else False

        pass
    pass

if __name__ == '__main__':
    print Solution().isHappy(7)

    pass
