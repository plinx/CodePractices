__author__ = 'linx'

from random import randint

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    pass

class Solution(object):
    def insertionSort(self, head):
        if head == None or head.next == None:
            return head

        newhead = ListNode(0)

        prev = newhead
        while head:
            if prev.next and prev.next.val > head.val:
                prev = newhead
            while prev.next != None and prev.next.val < head.val:
                prev = prev.next
            if prev != head:
                next = head.next
                head.next = prev.next
                prev.next = head
                head = next
            else:
                head = head.next

        return newhead.next

        pass
    pass

if __name__ == '__main__':
    Listin, Listout = [], []
    orgHead, curr = None, None
    for i in xrange(20):
        num = randint(0, 100)
        Listin.append(num)
        if curr != None:
            curr.next = ListNode(num)
            curr = curr.next
        else:
            orgHead = ListNode(num)
            curr = orgHead

    print Listin

    tmp = Solution().insertionSort(orgHead)
    while tmp != None:
        Listout.append(tmp.val)
        tmp = tmp.next

    print Listout
    pass
