__author__ = 'linx'

def insert_sort(A):
    for j in xrange(1, len(A)):
        key = A[j]
        i = j - 1
        while 0 <= i and key < A[i]:
            A[i + 1] = A[i]
            i -= 1
        A[i + 1] = key
    pass

def insert_sort_up(A):
    for j in xrange(1, len(A)):
        key = A[j]
        i = j - 1
        while 0 <= i and A[i] < key:
            A[i + 1] = A[i]
            i -= 1
        A[i + 1] = key
    pass

def select_sort(A):
    for i in xrange(len(A)):
        key = i
        for j in xrange(i + 1, len(A)):
            if A[j] < A[key]:
                key = j

        A[i], A[key] = A[key], A[i]
    pass

def merge(A, left, mid, right):
    tmp = A[left:mid + 1]
    nt = len(tmp)
    i, j = 0, mid + 1

    index = left
    while i < nt and j <= right:
        if tmp[i] < A[j]:
            A[index] = tmp[i]
            i += 1
        else:
            A[index] = A[j]
            j += 1

        index += 1

    while i < nt:
        A[index] = tmp[i]
        index += 1
        i += 1

    while j <= right:
        A[index] = A[j]
        index += 1
        j += 1

    pass

def merge_sort_recursive(A, left, right):
    if right <= left:
        return

    mid = (left + right) / 2
    merge_sort_recursive(A, left, mid)
    merge_sort_recursive(A, mid + 1, right)
    merge(A, left, mid, right)

    pass

def merge_sort_nonrecursive(A):
    if len(A) <= 1:
        return

    size = 2
    n = len(A)
    while size <= n:
        left = 0
        right = size - 1
        while right < n:
            mid = (left + right) / 2
            merge(A, left, mid, right)
            left += size
            right += size
        size *= 2
    merge(A, 0, (size / 2) - 1, n - 1)

