__author__ = 'linx'

class Solution(object):
    def multiply(self, num1, num2):
        inum1 = 0
        n = len(num1)
        for i in xrange(n):
            inum1 += (ord(num1[n - i - 1]) - 48) * 10**i

        result = 0
        n = len(num2)
        for j in xrange(n):
            result += inum1 * (ord(num2[n - j - 1]) - 48) * 10**j

        if result == 0:
            return "0"

        retstr = ""
        while result:
            retstr = chr(result % 10 + 48) + retstr
            result /= 10

        return retstr

        pass
    pass

if __name__ == '__main__':
    num1 = "123"
    num2 = "456"
    num3 = "9133"
    num4 = "0"

    print Solution().multiply(num3, num4)
    print int(num1) * int(num2)

    pass
