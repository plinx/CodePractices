__author__ = 'linx'

class Solution(object):
    def longestCommonPrefix(self, strs):
        if len(strs) < 1:
            return ""

        pre = strs[0]
        j = len(pre) - 1
        for i in xrange(1, len(strs)):
            if (len(strs[i]) - 1) < j:
                j = len(strs[i]) - 1
            k = j
            while 0 <= k:
                if pre[k] != strs[i][k]:
                    j = k - 1
                k -= 1

        return pre[:j + 1]
        pass
    pass

if __name__ == '__main__':
    #table = ["abc", "abd", "ab", "c"]
    table = ["aca", "cba"]
    print Solution().longestCommonPrefix(table)
    pass
