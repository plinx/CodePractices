__author__ = 'linx'

from math import factorial

class Solution(object):
    def getPermutation(self, n, k):
        s = [i + 1 for i in xrange(n)]
        k = (k % factorial(n)) - 1
        permutation = []

        for i in xrange(n - 1, -1, -1):
            idx, k = divmod(k, factorial(i))
            permutation.append(s.pop(idx))

        return "".join(map(str, permutation))
        pass
    pass

if __name__ == '__main__':
    print Solution().getPermutation(3, 3)
    #print Solution()
    pass
