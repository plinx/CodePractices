__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def removeElements(self, head, val):
		if head == None:
			return head

		rethead = ListNode(0)
		rethead.next = head
		curr = rethead
		while curr.next != None:
			if curr.next.val == val:
				curr.next = curr.next.next
				continue
			curr = curr.next

		return rethead.next
		pass
	pass

def main():
	Listin, Listout = [1, 2, 6, 3, 4, 5, 6], []
	orgHead = ListNode(Listin[0])
	curr = orgHead
	for i in xrange(1, len(Listin)):
		curr.next = ListNode(Listin[i])
		curr = curr.next

	print Listin

	#tmp = Solution().reverseBetween(orgHead, 0, 1)
	tmp = Solution().removeElements(orgHead, 6)
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()

