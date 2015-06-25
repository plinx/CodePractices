__author__ = 'linx'

class DP(object):
    def cur_rod(self, p, n):
        if n == 0:
            return 0
        q = -2147483648
        for i in xrange(1, n + 1):
            q = max(q, p[i] + self.cur_rod(p, n - i))
        return q
        pass

    def memoized_cur_rod(self, p, n):
        r = [-2147483648] * (n + 1)
        r[0] = 0
        return self.memoized_cur_rod_aux(p, n, r)
        pass

    def memoized_cur_rod_aux(self, p, n, r):
        if 0 <= r[n]:
            return r[n]
        q = r[n]
        for i in xrange(1, n + 1):
            #print q, p[i], self.memoized_cur_rod_aux(p, n - i, r)
            q = max(q, p[i] + self.memoized_cur_rod_aux(p, n - i, r))
        r[n] = q
        #print r
        return q
        pass

    def bottom_up_cur_rod(self, p, n):
        r = [0] * (n + 1)
        for j in xrange(1, n + 1):
            q = -2147483648
            for i in xrange(1, j + 1):
                q = max(q, p[i] + r[j - i])
            r[j] = q

        return r[n]
        pass

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





    pass

