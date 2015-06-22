__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def deleteDuplicates(self, head):
		if head == None or head.next == None:
			return head

		newhead = ListNode(0)
		newhead.next = head
		prev = newhead
		curr, tail = head, head.next
		while tail != None:
			if tail.val == curr.val:
				print tail.val
				tail = tail.next
				curr = curr.next
				continue
			if prev.next != curr:
				prev = prev.next
			prev.next = tail
			tail = tail.next

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

