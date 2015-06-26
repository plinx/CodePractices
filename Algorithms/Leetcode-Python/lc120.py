__author__ = 'linx'

class Solution(object):
    def minimumTotal(self, triangle):
        if len(triangle) < 2:
            return triangle[0][0]

        n = len(triangle)
        m = len(triangle[n - 1])

        r = [0] * (m - 1)
        for i in xrange(m - 1):
            r[i] = min(triangle[n - 1][i], triangle[n - 1][i + 1])

        #print r
        for j in xrange(n - 2, -1, -1):
            m -= 1
            for i in xrange(m - 1):
                r[i] = min(r[i] + triangle[j][i], r[i + 1] + triangle[j][i + 1])

        #print r[0]
        return r[0] + triangle[0][0]

        pass

if __name__ == '__main__':
    triangle1 = [
        [2],
        [3, 4],
        [6, 5, 7],
        [4, 1, 8, 3]
    ]
    triangle2 = [
        [-1],
        [2, 3],
        [1, -1, -3]
    ]
    print Solution().minimumTotal(triangle1)
    pass