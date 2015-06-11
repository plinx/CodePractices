__author__ = 'linx'

from random import randint

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def sortList(self, head):
		if head == None:
			return
		if head.next == None:
			return ListNode(head.val)



		return head
		pass
	pass

def main():
	orgHead = ListNode(1)
	curr = orgHead
	Listin, Listout = [1], []
	for i in xrange(10):
		num = randint(0, 100)
		curr.next = ListNode(num)
		Listin.append(num)
		curr = curr.next

	print Listin

	tmp = Solution().sortList(orgHead)
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()

