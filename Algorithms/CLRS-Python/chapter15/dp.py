__author__ = 'linx'

class DP(object):
    def cur_rod(self, p, n):
        if n == 0:
            return 0
        q = -2147483648
        for i in xrange(n):
            q = max(q, p[i] + self.cur_rod(p, n - i - 1))
        return q
        pass

    def memoized_cur_rod(self, p, n):
        r = [-2147483648] * n
        return self.memoized_cur_rod_aux(p, n, r)
        pass

    def memoized_cur_rod_aux(self, p, n, r):
        if n == 0:
            return 0
        if 0 < r[n - 1]:
            return r[n - 1]
        q = r[n - 1] if n != 0 else 0
        for i in xrange(n):
            #print q, p[i], self.memoized_cur_rod_aux(p, n - i, r)
            q = max(q, p[i] + self.memoized_cur_rod_aux(p, n - i - 1, r))
        r[n - 1] = q
        #print r
        return q
        pass

    def bottom_up_cur_rod(self, p, n):
        r = [0] * (n + 1)
        for j in xrange(1, n + 1):
            q = -2147483648
            for i in xrange(j):
                q = max(q, p[i] + r[j - i - 1])
            r[j] = q

        return r[n]
        pass

    def bottom_up_cur_rod_result(self, p, n):
        r = [0] * (n + 1)
        s = [0] * (n + 1)
        for j in xrange(1, n + 1):
            q = -2147483648
            for i in xrange(j):
                if q < p[i] + r[j - i - 1]:
                    q = p[i] + r[j - i - 1]
                    s[j] = i
                    r[j] = q

        return r[n], s[n] + 1

    def fib_r(self, n):
        if n < 0:
            return 0
        if n < 2:
            return n
        return self.fib_r(n - 1) + self.fib_r(n - 2)
        pass

    def fib_dp(self, n):
        if n < 0:
            return 0

        s1, s2 = 0, 1
        i = 1
        while i < n:
            if i % 2:
                s1 = s1 + s2
            else:
                s2 = s1 + s2
            i += 1

        return s1 if i % 2 is 0 else s2

    def lcs_mn(self, s1, s2):
        n = len(s1)
        m = len(s2)
        r = [[0 for i in xrange(m + 1)] for j in xrange(n + 1)]

        for j in xrange(n):
            for i in xrange(m):
                if s1[j] == s2[i]:
                    r[j + 1][i + 1] = r[j][i] + 1
                else:
                    r[j + 1][i + 1] = max(r[j][i + 1], r[j + 1][i])

        return r

    def build_lcs(self, r, s1, s2):
        result = []

        n = len(s1)
        m = len(s2)

        while n > 0 and m > 0:
            if r[n][m] == r[n - 1][m]:
                n -= 1
            elif r[n][m] == r[n][m - 1]:
                m -= 1
            elif r[n][m] == r[n - 1][m - 1] + 1:
                result.insert(0, s2[m - 1])
                n -= 1
                m -= 1
        return result

    def lcs_m_n(self, s1, s2):
        n = len(s1)
        m = len(s2)

        r = [[0 for i in xrange(m + 1)] for j in xrange(n + 1)]

        for j in xrange(n):
            for i in xrange(m):
                if s1[j] == s2[i]:
                    r[j + 1][i + 1] = r[j][i] + 1
                else:
                    r[j + 1][i + 1] = max(r[j + 1][i], r[j][i + 1])

        return r[-1][-1]
        pass

    def lcs_m_n_2on(self, s1, s2):
        n = len(s1)
        m = len(s2)

        r = [[0 for i in xrange(m + 1)] for j in xrange(2)]

        for j in xrange(n):
            r[0][:] = r[1][:]
            for i in xrange(m):
                if s1[j] == s2[i]:
                    r[1][i + 1] = r[0][i] + 1
                else:
                    r[1][i + 1] = max(r[1][i], r[0][i + 1])

        return r[1][-1]
        pass

    def lcs_m_n_on(self, s1, s2):
        n = len(s1)
        m = len(s2)

        r = [0 for i in xrange(m + 1)]
        tmp = 0
        for j in xrange(n):
            #print r
            for i in xrange(m):
                if s1[j] == s2[i]:
                    if tmp < r[i] + 1:
                        tmp = r[i] + 1
                        r[i + 1] = r[i] + 1
                else:
                    r[i + 1] = max(r[i + 1], r[i])

        return r[-1]
        pass

    def lis_with_sort_lcs(self, s):
        s.sort()
        result = []

        for i in xrange(len(s) - 1):
            if s[i] != s[i + 1]:
                result.append(s[i])

        if result[-1] != s[-1]:
            result.append(s[-1])

        return result
        pass

    def lis_n2(self, s):
        n = len(s)

        r = [1 for i in xrange(n)]
        for i in xrange(n):
            for j in xrange(i):
                if s[j] < s[i] and r[i] < r[j] + 1:
                    r[i] = r[j] + 1

        return max(r)
        pass


    pass

