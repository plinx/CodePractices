__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def reverseList(self, head):
		if head == None or head.next == None:
			return head

		rethead = ListNode(None)
		curr = head
		while curr != None:
			tmp = curr
			curr = curr.next
			tmp.next = rethead.next
			rethead.next = tmp

		return rethead.next
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

	tmp = Solution().reverseList(orgHead)
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()

