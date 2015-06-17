__author__ = 'linx'

class Solution(object):
    def generate(self, numRows):
        result = [[1] * (i + 1) for i in xrange(numRows)]
        for i in xrange(2, numRows):
            for j in xrange(1, i):
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j]
        return result
        pass
    pass

if __name__ == '__main__':
    print Solution().generate(5)
    pass
