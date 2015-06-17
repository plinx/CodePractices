__author__ = 'linx'

class Solution(object):
    def isPalindrome(self, x):
        if x < 0 or (x != 0 and x % 10 == 0):
            return False

        sum = 0
        while sum < x:
            sum = sum * 10 + x % 10
            x /= 10

        return x == sum or x == sum / 10
        pass
    pass

if __name__ == '__main__':
    print Solution().isPalindrome(214747412)
    pass
