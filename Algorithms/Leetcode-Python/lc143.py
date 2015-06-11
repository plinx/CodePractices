__author__ = 'linx'

from random import randint

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def reorderList(self, head):
		if head == None or head.next == None:
			return

		head2 = ListNode(-1)
		prev = tail = head
		while tail != None and tail.next != None:
			prev = prev.next
			tail = tail.next.next

		# reverse the head2
		tail = prev.next
		prev.next = None

		while tail != None:
			tmp = tail
			tail = tail.next
			tmp.next = head2.next
			head2.next = tmp

		prev = head
		tail = head2.next
		while tail != None:
			if prev.next == None:
				prev.next = tail
				return
			tmp = tail
			tail = tail.next
			tmp.next = prev.next
			prev.next = tmp
			prev = tmp.next

		return
		pass
	pass

def main():
	#Listin, Listout = [1, 2, 3, 4], []
	Listin, Listout = [1, 2, 3, 4, 5, 6], []
	orgHead = ListNode(Listin[0])
	curr = orgHead
	for i in xrange(1, len(Listin)):
		curr.next = ListNode(Listin[i])
		curr = curr.next

	print Listin

	Solution().reorderList(orgHead)
	tmp = orgHead
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()


