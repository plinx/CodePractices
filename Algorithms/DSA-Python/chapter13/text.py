__author__ = 'linx'

class Text(object):
    def bruteForce1(self, T, P):
        n, m = len(T), len(P)
        if m == 0:
            return 0
        for i in xrange(n - m + 1):
            if T[i:i + m] == P:
                return i
        return -1

    def bruteForce2(self, T, P):
        n, m = len(T), len(P)
        if m == 0:
            return 0
        for i in xrange(n - m + 1):
            k = 0
            while k < m and T[i + k] == P[k]:
                k += 1
            if k == m:
                return i
        return -1

    def boyerMoore(self, T, P):
        n, m = len(T), len(P)
        if m == 0:
            return 0
        Pattern = {}
        for k in xrange(m):
            Pattern[P[k]] = k

        #print Pattern
        i = k = m - 1
        while i < n:
            if T[i] == P[k]:
                if k == 0:
                    return i
                else:
                    i -= 1
                    k -= 1
            else: # tail not match
                l = Pattern.get(T[i], -1)

                # case 1 : T[i] not in Pattern, skip the whole m, i += m
                # case 2 : T[i] in Pattern, but already match k element,
                #          so jump the max length between tail to k/l
                i += m - min(k, l + 1)
                k = m - 1
        return -1


    pass
