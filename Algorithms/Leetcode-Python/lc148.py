__author__ = 'linx'

from random import randint

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    pass

class Solution(object):
    def sortList(self, head):
        if head == None or head.next == None:
            return head
        result = []
        tmp = head
        while tmp:
            result.append(tmp)
            tmp = tmp.next

        #print [x.val for x in result]
        result.sort(key=lambda x:x.val)
        #print [x.val for x in result]

        for i in xrange(1, len(result)):
            result[i - 1].next = result[i]
        result[-1].next = None

        return result[0]
        pass
    pass

def main():
    Listin, Listout = [], []
    orgHead, curr = None, None
    for i in xrange(10):
        num = randint(0, 100)
        Listin.append(num)
        if curr != None:
            curr.next = ListNode(num)
            curr = curr.next
        else:
            orgHead = ListNode(num)
            curr = orgHead

    print Listin

    tmp = Solution().sortList(orgHead)
    while tmp != None:
        Listout.append(tmp.val)
        tmp = tmp.next

    print Listout


if __name__ == '__main__':
    main()

