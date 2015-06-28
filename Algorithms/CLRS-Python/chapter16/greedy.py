__author__ = 'linx'

class Greedy(object):
    def recursive_activity_selector(self, s, f, k):
        m = k + 1
        while m < len(s) and s[m] < f[k]:
            m = m + 1

        if m <= len(s):
            return [[s[k], f[k]]] + \
                   self.recursive_activity_selector(s, f, m)
        return []
        pass

    def greedy_activity_selector(self, s, f):
        result = [[s[0], f[0]]]
        for i in xrange(1, len(s)):
            if result[-1][-1] < s[i]:
                result.append([s[i], f[i]])

        return result
        pass

    def dp_greedy_activity(self, s, f):
        n = len(s)
        r = [[] for i in xrange(n + 1)]

        rindex = 0
        for j in xrange(n):
            r[j].append([s[j], f[j]])
            for i in xrange(j + 1, n):
                if r[j][-1][-1] < s[i]:
                    r[j].append([s[i], f[i]])
            if len(r[rindex]) < len(r[j]):
                rindex = j

        return r[rindex]
        pass

    def greedy_activity_night(self, s, f):
        result = [[s[-1], f[-1]]]

        for i in xrange(len(s) - 2, -1, -1):
            if f[i] < result[0][0]:
                result.insert(0, [s[i], f[i]])

        return result
        pass

    def dp_knapsack(self, s, w):
        n = len(s)
        r = [[0 for i in xrange(w + 1)] for j in xrange(n + 1)]

        rw = 0
        print [0, 0], r[0]
        for j in xrange(1, n + 1):
            print s[j - 1],
            for i in xrange(1, w + 1):
                if i < s[j - 1][0]:
                    r[j][i] = r[j - 1][i]
                else: # s[j][0] <= i
                    #if r[j - 1][i] < s[j - 1][1]:
                    if r[j - 1][i] < r[j - 1][i - s[j - 1][0]] + s[j - 1][1]:
                        r[j][i] = r[j - 1][i - s[j - 1][0]] + s[j - 1][1]
                    else:
                        r[j][i] = r[j - 1][i]

            print r[j]










        pass

    pass
