__author__ = 'linx'

class Sorts(object):
    def count_sort(self, A, B, n):
        C = [0] * n
        for i in xrange(len(A)):
            C[A[i]] = C[A[i]] + 1

        for i in xrange(1, n):
            C[i] = C[i] + C[i - 1]

        for j in xrange(len(A) - 1, -1, -1):
            B[C[A[j]] - 1] = A[j]
            C[A[j]] -= 1
        pass

    def count_sort_up(self, A, B, n):
        C = [0] * n
        for i in xrange(len(A)):
            C[A[i]] = C[A[i]] + 1

        for i in xrange(1, n):
            C[i] = C[i] + C[i - 1]

        for j in xrange(len(A)):
            B[C[A[j]] - 1] = A[j]
            C[A[j]] -= 1
        pass

    def radix_sort(self, A, n):
        B = [[] for i in xrange(9)]
        for k in xrange(n):
            for i in xrange(len(A)):
                kth = (A[i] / 10**k) % 10
                B[kth].append(A[i])
            radix, j = 0, 0
            while radix < len(A):
                if B[j] != []:
                    A[radix] = B[j].pop(0)
                    radix += 1
                else:
                    j += 1
        pass

    def radix_sort_str(self, A, n):
        B = [[] for i in xrange(26)]
        for k in xrange(n):
            for i in xrange(len(A)):
                kth = ord(A[i][n - k - 1]) - 65
                B[kth].append(A[i])

            radix, j = 0, 0
            while radix < len(A):
                if B[j] != []:
                    A[radix] = B[j].pop(0)
                    radix += 1
                else:
                    j += 1
        pass

    pass

