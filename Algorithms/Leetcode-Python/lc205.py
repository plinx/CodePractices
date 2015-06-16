__author__ = 'linx'

class Solution(object):
    def isIsomorphic(self, s, t):
        t1, t2 = [0] * 256, [0] * 256

        for i in xrange(len(s)):
            if (t1[ord(s[i])] != t2[ord(t[i])]):
                return False
            t1[ord(s[i])] = i + 1
            t2[ord(t[i])] = i + 1

        return True

        pass
    pass

if __name__ == '__main__':
    str1 = "aba"
    str2 = "baa"

    print Solution().isIsomorphic(str1, str2)
    pass
