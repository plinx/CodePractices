__author__ = 'linx'

class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        area1 =  (C - A) * (D - B)
        area2 =  (G - E) * (H - F)

        if C < E or G < A:
            return area1 + area2
        if D < F or H < B:
            return area1 + area2

        bottom_left = [A if A > E else E, B if B > F else F]
        top_right = [C if C < G else G, D if D < H else H]

        #print area1, area2
        return area1 + area2 - \
               (top_right[0] - bottom_left[0]) * (top_right[1] - bottom_left[1])
        pass
    pass

if __name__ == '__main__':
    #print Solution().computeArea(0, 0, 0, 0, -1, -1, 1, 1)
    #print Solution().computeArea(-2, -2, 2, 2, 3, 3, 4, 4)
    print Solution().computeArea(-3, 0, 3, 4, 0, -1, 9, 2)
    pass
