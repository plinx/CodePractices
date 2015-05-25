__author__ = 'linx'

class Sorts(object):
    def arr_merge(self, S1, S2, S):
        i = j = 0
        while i + j < len(S):
            if j == len(S2) or (i < len(S1) and S1[i] < S2[j]):
                S[i + j] = S1[i]
                i += 1
            else: # i == len(S1) and j < len(S2)
                S[i + j] = S2[j]
                j += 1

    def arr_mergeSort(self, S):
        n = len(S)
        if n < 2:
            return
        mid = n / 2
        S1 = S[0:mid]
        S2 = S[mid:n]
        self.arr_mergeSort(S1)
        self.arr_mergeSort(S2)
        self.arr_merge(S1, S2, S)

    class LinkQueue(object):
        class _Node(object):
            def __init__(self, elem, next):
                self._elem = elem
                self._next = next
            pass

        def __init__(self):
            self._first = self._Node(None, None)
            self._last = self._first
            self._size = 0
            pass

        def __len__(self):
            return self._size

        def is_empty(self):
            return len(self) == 0

        def first(self):
            return self._first._elem

        def enqueue(self, elem):
            if not self.is_empty():
                self._last._elem = elem
            else:
                self._first._elem = elem
            self._size += 1
            self._last._next = self._Node(None, None)
            self._last = self._last._next

        def dequeue(self):
            ret = self._first._elem
            self._first = self._first._next
            self._size -= 1
            return ret

        def travel(self):
            t = []
            tmp = self._first
            while tmp != self._last:
                t.append(tmp._elem)
                tmp = tmp._next
            #print t
            return t


    def lq_merge(self, S1, S2, S):
        while not S1.is_empty() and not S2.is_empty():
            if S1.first() < S2.first():
                S.enqueue(S1.dequeue())
            else: # S2.first() < S1.first()
                S.enqueue(S2.dequeue())

        while not S1.is_empty():
            S.enqueue(S1.dequeue())
        while not S2.is_empty():
            S.enqueue(S2.dequeue())

    def lq_mergeSort(self, S):
        n = len(S)
        if n < 2:
            return
        S1 = self.LinkQueue()
        S2 = self.LinkQueue()
        while len(S1) < n / 2:
            S1.enqueue(S.dequeue())
        while not S.is_empty():
            S2.enqueue(S.dequeue())
        self.lq_mergeSort(S1)
        self.lq_mergeSort(S2)
        self.lq_merge(S1, S2, S)

        pass

    def arr_quickSort(self, S):
        n = len(S)
        if n < 2:
            return
        pivot = S[0]
        lt = []
        gt = []
        for i in xrange(1, n):
            if S[i] < pivot:
                lt.append(S[i])
            else: # S[i] >= pivot
                gt.append(S[i])

        #print lt, gt
        self.arr_quickSort(lt)
        self.arr_quickSort(gt)

        nlt = len(lt)
        for i in xrange(n):
            if i < nlt:
                S[i] = lt[i]
            elif i > nlt:
                S[i] = gt[i - nlt - 1]
            else: # i == len(lt)
                S[i] = pivot
        #S[0:len(lt) - 1] = lt
        #S[len(lt)] = lt
        #S[len(lt) + 1:n] = gt





    pass