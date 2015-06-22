__author__ = 'linx'

class Solution(object):
    def rotate(self, matrix):
        matrix.reverse()
        for row in xrange(len(matrix)):
            for column in xrange(row + 1, len(matrix[row])):
                matrix[row][column], matrix[column][row] = \
                    matrix[column][row], matrix[row][column]

        pass
    pass

if __name__ == '__main__':
    matrix = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
    ]
    print matrix[0]
    print matrix[1]
    print matrix[2]
    Solution().rotate(matrix)
    print ""
    print matrix[0]
    print matrix[1]
    print matrix[2]

    pass
