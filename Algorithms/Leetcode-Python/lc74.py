__author__ = 'linx'

class Solution(object):
    def searchMatrix(self, matrix, target):
        if target < matrix[0][0] or matrix[-1][-1] < target:
            return False

        rl, rr = 0, len(matrix) - 1
        while rl < rr:
            rmid = (rl + rr) / 2
            if target < matrix[rmid][0]:
                rr = rmid - 1
            else:
                rl = rmid + 1

        rindex = rl - 1 if target < matrix[rl][0] else rl
        if target < matrix[rindex][0] and matrix[rindex][-1] < target:
            return False

        cl, cr = 0, len(matrix[rindex]) - 1
        while cl <= cr:
            cmid = (cl + cr) / 2
            #print cmid, cl, cr
            #print matrix[rindex][cmid]
            if target < matrix[rindex][cmid]:
                cr = cmid - 1
            elif matrix[rindex][cmid] < target:
                cl = cmid + 1
            else: #target == matrix[rindex][cmid]
                return True

        return False

    pass

if __name__ == '__main__':
    matrix = [
        #[1, 3, 5, 7],
        #[10, 11, 16, 20],
        #[23, 30, 34, 50]
        [1]
    ]
    print Solution().searchMatrix(matrix, 1)
    pass
