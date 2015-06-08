__author__ = 'linx'

from random import randint

class qSort(object):
    def partition(self, A, left, right):
        i = left
        for j in xrange(left, right):
            if A[j] <= A[right]:
                A[i], A[j] = A[j], A[i]
                i += 1
        A[i], A[right] = A[right], A[i]

        return i if A[left] != A[right] else i / 2
        pass

    def quicksort(self, A, left, right):
        if left < right:
            mid = self.partition(A, left, right)
            self.quicksort(A, left, mid - 1)
            self.quicksort(A, mid, right)
        pass


    def partition_up(self, A, left, right):
        i = left
        for j in xrange(left, right):
            if A[j] >= A[right]:
                A[i], A[j] = A[j], A[i]
                i += 1
        A[i], A[right] = A[right], A[i]

        return i if A[left] != A[right] else i / 2
        pass

    def quicksort_up(self, A, left, right):
        if left < right:
            mid = self.partition_up(A, left, right)
            self.quicksort_up(A, left, mid - 1)
            self.quicksort_up(A, mid, right)
        pass

    def partition_random(self, A, left, right):
        i = randint(left, right)
        A[i], A[right] = A[right], A[i]

        return self.partition(A, left, right)

    def quicksort_random(self, A, left, right):
        if left < right:
            mid = self.partition_random(A, left, right)
            self.quicksort_random(A, left, mid - 1)
            self.quicksort_random(A, mid, right)
        pass


    pass

