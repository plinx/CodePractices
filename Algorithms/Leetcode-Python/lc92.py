__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def reverseBetween(self, head, m, n):
		if head == None or head.next == None:
			return head

		prev = ListNode(0)
		prev.next = head
		curr = head
		for i in xrange(m - 1):
			prev = curr
			curr = curr.next

		tail = curr
		for i in xrange(n - m + 1):
			tail = tail.next

		for i in xrange(n - m + 1):
			tmp = curr
			curr = curr.next
			tmp.next = tail
			tail = tmp

		prev.next = tail

		return head if m != 1 else prev.next
		pass
	pass

def main():
	Listin, Listout = [3, 5], []
	orgHead = ListNode(Listin[0])
	curr = orgHead
	for i in xrange(1, len(Listin)):
		curr.next = ListNode(Listin[i])
		curr = curr.next

	print Listin

	#tmp = Solution().reverseBetween(orgHead, 0, 1)
	tmp = Solution().reverseBetween(orgHead, 1, 2)
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()

