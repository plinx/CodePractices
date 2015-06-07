__author__ = 'linx'

class Heap(object):
    def _Parent(self, i):
        return i / 2

    def _Left(self, i):
        return 2 * i + 1

    def _Right(self, i):
        return 2 * i + 2

    def max_heapify_recursive(self, A, n, index):
        if n < 2:
            return

        left, right = self._Left(index), self._Right(index)
        max = index

        if left < n and A[max] < A[left]:
            max = left
        if right < n and A[max] < A[right]:
            max = right

        if max != index:
            A[max], A[index] = A[index], A[max]
            self.max_heapify_recursive(A, n, max)

        pass


    def max_heapify_nonrecursive(self, A, n, index):
        if n < 2:
            return

        left, right = self._Left(index), self._Right(index)
        max = index

        while left < n or right < n:
            if left < n and A[max] < A[left]:
                max = left
            if right < n and A[max] < A[right]:
                max = right

            if max != self._Parent(left):
                A[max], A[self._Parent(left)] = A[self._Parent(left)], A[max]
                left = self._Left(max)
                right = self._Right(max)
            else:
                break

        pass

    def build_heap_recursive(self, A):
        n = len(A)
        for i in xrange(len(A) / 2, -1, -1):
            self.max_heapify_recursive(A, n, i)
        pass

    def build_heap_nonrecursive(self, A):
        n = len(A)
        for i in xrange(len(A) / 2, -1, -1):
            self.max_heapify_nonrecursive(A, n, i)
        pass

    def heap_sort(self, A):
        size = len(A)
        self.build_heap_nonrecursive(A)

        for i in xrange(len(A) - 1, 0, -1):
            A[0], A[i] = A[i], A[0]
            size -= 1
            self.max_heapify_nonrecursive(A, size, 0)
        pass

    pass
