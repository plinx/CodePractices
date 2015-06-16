__author__ = 'linx'

class Solution(object):
    def reverseBits(self, n):
        bits = [0] * 32
        table = [2**i for i in xrange(32)]

        for i in xrange(31, -1, -1):
            if table[i] <= n:
                #print i, table[i], n
                n -= table[i]
                bits[31 - i] = 1

        #print bits
        ret = 0
        for i in xrange(32):
            if bits[i] != 0:
                ret += table[i]

        return ret
        pass
    pass

if __name__ == '__main__':
    print Solution().reverseBits(43261596)
    #print Solution().reverseBits(0)
    pass
