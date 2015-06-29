__author__ = 'linx'

class Solution(object):
    def lengthOfLogestSubstring(self, s):
        cindex = [-1 for i in xrange(256)]
        result, m = 0, 0

        for i in xrange(len(s)):
            m = max(cindex[ord(s[i])] + 1, m)
            cindex[ord(s[i])] = i
            result = max(result, i - m + 1)

        return result
        pass
    pass

if __name__ == '__main__':
    s1 = "abcabcbb"
    s2 = "bbbbb"

    print Solution().lengthOfLogestSubstring("b")
    pass
