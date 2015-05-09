__author__ = 'linx'

class Creativity(object):
    # C4.9
    def minmax(self, S):
        if len(S) < 1:
            return []
        elif len(S) == 1:
            return [S[0], S[0]]
        else:
            return self._minmax(S, 0, len(S) - 1)

    def _minmax(self, S, head, tail):
        if head == tail:
            return [S[head], S[tail]]
        min, max = [S[head], S[tail]]
        if max < min:
            min, max = max, min
        tmin, tmax = self._minmax(S, head + 1, tail - 1)
        if tmin < min:
           min = tmin
        if max < tmax:
            max = tmax
        return [min, max]

    # 4.9
    # skip

    # 4.10
    def unique(self, S):
        if len(S) < 1:
            return False
        elif len(S) == 1:
            return True
        else:
            return self._unique(S, 0, 1, len(S) - 1)

    def _unique(self, S, index, head, tail):
        if head == tail:
            if index == head:
                return False
            elif S[index] == S[head]:
                return True
            else:
                index += 1
                if index == tail:
                    return False
                else:
                    return self._unique(S, index, index + 1, tail)

        if S[index] == S[head]:
            return True
        else:
            return self._unique(S, index, head + 1, tail)

    # C4.12
    def product(self, m, n):
        if m < n:
            return self._product(n, m)
        else:
            return self._product(m, n)

    def _product(self, m, n):
        if n == 1:
            return m
        else:
            return m + self._product(m, n - 1)

    # C4.13
    # skip

    # C4.14
    def hanoi(self, num):
        return self._hanoi(num, "A", "B", "C")

    # Move disk from A to C via B
    def _hanoi(self, n, A, B, C):
        if n == 1:  # Move disk from A to C directly
            print "disk %d : %s => %s" % (n, A, C)
        else:
            """
            Target : Move all disks from A to C
            step1  : Move disks over the largest to B as temporary storage
            step2  : Move the largest dist to C
            step3  : Move the disks from B to C
            """
            self._hanoi(n - 1, A, C, B)
            print "disk %d : %s => %s" % (n, A, C)
            self._hanoi(n - 1, B, A, C)

    # C4.15
    # fail

    # C4.16
    def reverse(self, str):
        if len(str) == 1:
            return str
        else:
            strtable = [str[i] for i in xrange(len(str))]
            self._reverse(strtable, 0, len(str) - 1)
            str = ""
            for s in strtable:
                str += s
            return str

    def _reverse(self, table, start, end):
        if start == end:
            return table
        elif start == end - 1:
            table[start], table[end] = table[end], table[start]
            return table
        else:
            table[start], table[end] = table[end], table[start]
            return self._reverse(table, start + 1, end - 1)

    # C4.17
    def palindrome(self, str):
        if len(str) == 1:
            return True
        else:
            return self._palindrome(str, 0, len(str) - 1)

    def _palindrome(self, str, start, end):
        if start == end:
            return True
        elif start == end -1:
            if str[start] == str[end]:
                return True
            else:
                return False
        else:
            if str[start] == str[end]:
                return self._palindrome(str, start + 1, end - 1)
            else:
                return False
    # C4.18
    # skip

    # C4.19
    def left_even(self, S):
        if len(S) == 1:
            return S
        else:
            return self._left_even(S, 0, len(S) - 1)

    def _left_even(self, S, start, end):
        if start == end:
            return S
        else:
            if S[start] % 2 == 0:
                # if left is even, go to next element
                return self._left_even(S, start + 1, end)
            elif S[end] % 2 == 0:
                # left is odd and right is even
                # swap element and go to next left
                S[start], S[end] = S[end], S[start]
                return self._left_even(S, start + 1, end)
            else:
                # left is odd and right is odd
                # go to next right
                return self._left_even(S, start, end - 1)

    # C4.20
    # same as C4.19, running time O(n)

    # sleep now.


    pass
