__author__ = 'linx'

class Creativity(object):
    # P7.24, 7.25 solved
    # P7.26
    # implement in LinkedQueue
    # append_queue(self, Q2)

    # P2.28
    class ListNode(object):
        __slots__ = "_elem", "_next"
        def __init__(self, elem, next):
            self._elem = elem
            self._next = next
        pass

    def recursive_reverse(self, Node):
        if Node._next == None:
            return [Node, Node]
        else:
            [head, tail] = self.recursive_reverse(Node._next)
            tail._next = Node
            Node._next = None
            return [head, Node]

    def insert_reverse(self, Node):
        head = Node
        curr = Node._next
        head._next = None
        while curr != None:
            tmpNode = curr._next
            curr._next = head
            head = curr
            curr = tmpNode

        return head
    pass