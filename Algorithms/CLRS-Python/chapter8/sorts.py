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

    def radix_sort_int(self, A, key):
        B = [[] for i in xrange(10)]
        for k in xrange(key):
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

    def radix_sort_str(self, A, key):
        B = [[] for i in xrange(26)]
        for k in xrange(key):
            for i in xrange(len(A)):
                kth = ord(A[i][key - k - 1]) - 65
                B[kth].append(A[i])

            radix, j = 0, 0
            while radix < len(A):
                if B[j] != []:
                    A[radix] = B[j].pop(0)
                    radix += 1
                else:
                    j += 1
        pass

    def bucket_sort(self, A):
        B = [[] for i in xrange(10)]
        for i in xrange(len(A)):
            kth = (A[i] / 10) % 10
            B[kth].append(A[i])

        for i in xrange(10):
            B[i].sort()

        index, kth = 0, 0
        while index < len(A):
            if B[kth] != []:
                A[index] = B[kth].pop(0)
                index += 1
            else:
                kth += 1

        pass



    pass

