__author__ = 'linx'

class Solution(object):
    def plusOne(self, digits):
        for i in xrange(len(digits) - 1, -1, -1):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                return digits
        return [1] + digits
        pass
    pass

if __name__ == '__main__':
    pass