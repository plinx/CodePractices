__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def partition(self, head, x):
		if head == None or head.next == None:
			return head

		head1 = ListNode(-1)
		head2 = ListNode(-1)

		curr = head
		tail1, tail2 = head1, head2

		while curr != None:
			if curr.val < x:
				tail1.next = curr
				tail1 = tail1.next
			else: # curr.val >= x
				tail2.next = curr
				tail2 = tail2.next
			curr = curr.next

		tail1.next = head2.next
		tail2.next = None

		return head1.next
		pass
	pass

def main():
	#Listin, Listout = [1, 2, 3, 4], []
	Listin, Listout = [1, 4, 3, 2, 5, 2], []
	orgHead = ListNode(Listin[0])
	curr = orgHead
	for i in xrange(1, len(Listin)):
		curr.next = ListNode(Listin[i])
		curr = curr.next

	print Listin

	tmp = Solution().partition(orgHead, 3)
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()



