__author__ = 'linx'

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    pass

class Solution(object):
    def deleteDuplicates(self, head):
        newhead = ListNode(0)
        newhead.next = head

        preval = None
        if head != None and head.next != None:
            if head.val == head.next.val:
                preval = head.val
        prev = newhead
        curr = head
        while curr:
            if curr.next != None and curr.val == curr.next.val:
                prev.next = curr.next
                curr = curr.next
            else:
                if preval != curr.val:
                    print prev.val, preval
                    if prev.val == preval:
                        prev.next = curr.next
                        preval = curr.val
                    prev = curr
                    preval = curr.val
                    curr = curr.next
                else:
                    prev.next = curr.next
                    curr = curr.next
                    #prev = prev.next

        return newhead.next
        pass
    pass

def main():
    #Listin, Listout = [2, 2], []
    Listin, Listout = [1, 2, 2], []
    #Listin, Listout = [1, 1, 1, 2, 3, 4], []
    #Listin, Listout = [1, 2, 3, 3, 4, 4, 5], []
    orgHead = ListNode(Listin[0])
    curr = orgHead
    for i in xrange(1, len(Listin)):
        curr.next = ListNode(Listin[i])
        curr = curr.next

    print Listin

    tmp = Solution().deleteDuplicates(orgHead)
    while tmp != None:
        Listout.append(tmp.val)
        tmp = tmp.next

    print Listout


if __name__ == '__main__':
    main()

