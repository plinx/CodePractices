__author__ = 'linx'

class Solution(object):
    def isValidSudoku(self, board):
        row = [[0 for i in xrange(9)] for j in xrange(9)]
        column = [[0 for i in xrange(9)] for j in xrange(9)]
        field = [[0 for i in xrange(9)] for j in xrange(9)]

        for j in xrange(9):
            for i in xrange(9):
                if '.' != board[j][i]: # ord('0') => 48
                    num = ord(board[j][i]) - 48 - 1
                    fnum = (i / 3) + 3 * (j / 3)
                    #print num, j, i
                    if 0 != column[num][i] or \
                        0 != row[num][j] or \
                        0 != field[num][fnum]:
                        #print column[num][i], row[num][j], field[num][(i / 3) + 3 * (j / 3)]
                        #print num + 1, j, i, (i / 3) + 3 * (j / 3), "False"
                        #print row[num], column[num], field[num]
                        return False
                    else:
                        column[num][i] = row[num][j] = field[num][fnum] = 1

        return True
    pass

if __name__ == '__main__':
    board = [
        "53..7....", "6..195...", ".98....6.",
        "8...6...3", "4..8.3..1", "7...2...6",
        ".6....28.", "...419..5", "....8..79"
    ]

    board1 = [
        "..4...63.", ".........", "5......9.",
        "...56....", "4.3.....1", "...7.....",
        "...5.....", ".........", "........."
    ]

    print Solution().isValidSudoku(board1)
    pass
