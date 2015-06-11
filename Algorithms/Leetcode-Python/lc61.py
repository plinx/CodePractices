__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def rotateList(self, head, k):
		if head == None or head.next == None:
			return head

		total = 1
		tail = head
		while tail.next != None:
			tail = tail.next
			total += 1

		if (total - k % total) == total:
			return head

		rethead = head
		for i in xrange(total - k % total):
			prev = rethead
			rethead = rethead.next

		prev.next = None
		tail.next = head

		return rethead
		pass
	pass

def main():
	Listin, Listout = [1, 2, 3, 4, 5], []
	orgHead = ListNode(Listin[0])
	curr = orgHead
	for i in xrange(1, len(Listin)):
		curr.next = ListNode(Listin[i])
		curr = curr.next

	print Listin

	tmp = Solution().rotateList(orgHead, 10)
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()

