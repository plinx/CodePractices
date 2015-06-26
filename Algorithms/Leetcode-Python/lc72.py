__author__ = 'linx'

class Solution(object):
    def minDistance(self, word1, word2):
        n = len(word1)
        m = len(word2)
        r = [[0 for i in xrange(m + 1)] for j in xrange(n + 1)]

        common_pos = 0
        for j in xrange(n):
            for i in xrange(m):
                if word1[j] == word2[i]:
                    r[j + 1][i + 1] = r[j][i] + 1
                    if i == j:
                        common_pos += 1
                else:
                    r[j + 1][i + 1] = max(r[j][i + 1], r[j + 1][i])

        print min(n, m), r[n][m], common_pos, abs(n - m)
        return min(n, m) - r[n][m] + common_pos + abs(n - m)
        pass
    pass

if __name__ == '__main__':
    #s1 = "hello"
    #s2 = "ohll"
    s1 = "ab"
    s2 = "bc"
    print Solution().minDistance(s1, s2)
    pass
