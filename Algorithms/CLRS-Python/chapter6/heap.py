__author__ = 'linx'

class Heap(object):
    def _Parent(self, i):
        return i / 2

    def _Left(self, i):
        return 2 * i + 1

    def _Right(self, i):
        return 2 * i + 2

    def max_heapify_recursive(self, A, index):
        if len(A) < 2:
            return

        left, right = self._Left(index), self._Right(index)
        max = index

        if left < len(A) and A[max] < A[left]:
            max = left
        if right < len(A) and A[max] < A[right]:
            max = right

        if max != index:
            A[max], A[index] = A[index], A[max]
            self.max_heapify_recursive(A, max)

        pass


    def max_heapify_nonrecursive(self, A):
        if len(A) < 2:
            return

        n = len(A)
        index, left, right = 0, 1, 2
        max = index

        while left < n and right < n:
            if A[max] < A[left]:
                max = left
            if A[max] < A[right]:
                max = right

            if max != self._Parent(left):
                A[max], A[index] = A[index], A[max]
                index = max
                left = self._Left(index)
                right = self._Right(index)
            else:
                break

        pass

    pass
