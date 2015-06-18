__author__ = 'linx'

class Solution(object):
    def reverseWords(self, s):
        n = len(s)
        news = ""
        prei = 0
        for i in xrange(n):
            if s[i] == ' ':
                if s[prei] == ' ':
                    prei += 1
                    continue
                news = ' ' + s[prei:i] + news
                prei += 1

        news = s[prei:n] + news

        return news

        pass
    pass

if __name__ == '__main__':
    #s = "the sky is blue"
    s = "1 "
    #s = "    "
    print "," + Solution().reverseWords(s) + ","

    pass