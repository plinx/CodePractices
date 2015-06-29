__author__ = 'linx'

class Solution(object):
    def anagrams(self, strs):
        ht = {}
        result = {}
        for i in xrange(len(strs)):
            s = [strs[i][k] for k in xrange(len(strs[i]))]
            s.sort()
            s = ''.join(s)
            if ht.has_key(s):
                if not result.has_key(s):
                    result[s] = [ht[s]]
                result[s] += [strs[i]]
            else:
                ht[s] = strs[i]
            pass

        ret = []
        for key, val in result.items():
            ret += val

        return ret
        pass
    pass

if __name__ == '__main__':
    strs = ["dog", "cat", "tac", "god", "aaa", "abd"]
    strs1 = ["ant", "ant"]
    strs2 = ["and", "dan"]
    strs3 = ["", "", ""] # expect ["", "", ""]

    print Solution().anagrams(strs2)
    pass
