__author__ = 'linx'

class Solution(object):
    def setZeroes(self, matrix):
        n, m = len(matrix), len(matrix[0])
        col0 = 1 if matrix[0][0] != 0 else 0
        for j in xrange(n):
            if matrix[j][0] == 0:
                col0 = 0
            for i in xrange(1, m):
                if matrix[j][i] == 0:
                    matrix[j][0] = matrix[0][i] = 0
        #print matrix

        for j in xrange(n - 1, -1, -1):
            for i in xrange(m - 1, 0, -1):
                if matrix[j][0] == 0 or matrix[0][i] == 0:
                    matrix[j][i] = 0
            if col0 == 0:
                matrix[j][0] = 0
        pass
    pass


if __name__ == '__main__':
    matrix = [
        [1, 1, 1, 3],
        [1, 1, 0, 1],
        [3, 3, 3, 3],
        [2, 2, 2, 2]
    ]
    m1 = [[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
    m2 = [[1,1,1],[0,1,2]]
    m3 = [[1, 0]]
    print m1
    Solution().setZeroes(m1)
    for j in xrange(len(m1)):
        print m1[j]
    pass
