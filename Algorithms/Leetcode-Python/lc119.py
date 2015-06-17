__author__ = 'linx'

class Solution(object):
    def generate(self, rowIndex):
        r = [[1] * (i + 1) for i in xrange(rowIndex + 1)]
        for i in xrange(2, rowIndex + 1):
            for j in xrange(1, i):
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j]
        return r[rowIndex]
        pass
    pass

if __name__ == '__main__':
    print Solution().generate(3)
    pass
