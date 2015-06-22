__author__ = 'linx'

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
    pass

class Solution(object):
    def mergeKLists(self, lists):
        result = []
        for head in lists:
           while head:
                result.append(head)
                head = head.next

        result.sort(key = lambda x : x.val)
        for i in xrange(1, len(result)):
            result[i - 1].next = result[i]
        return result[0] if result != [] else []
        pass


def main():
    Listin = [[1, 3, 5], [2, 4, 6, 8], [3, 5, 7]]
    #Listin = [[1, 3]]
    listHead = [[None] for i in xrange(len(Listin))]
    Listout = []

    for i in xrange(len(Listin)):
        listHead[i] = ListNode(Listin[i][0])
        curr = listHead[i]
        for j in xrange(1, len(Listin[i])):
            curr.next = ListNode(Listin[i][j])
            curr = curr.next

    print Listin

    tmp = Solution().mergeKLists(listHead)

    while tmp != None:
        Listout.append(tmp.val)
        tmp = tmp.next

    print Listout


if __name__ == '__main__':
    main()

