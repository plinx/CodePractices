__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def swapPairs(self, head):
		if head == None:
			return
		if head.next == None:
			return ListNode(head.val)

		first, second = head.next, head
		retHead = ListNode(first.val)
		curr = retHead

		while first != None or second != None:
			curr.next = ListNode(second.val)
			curr = curr.next
			second = first.next
			if second == None:
				break
			first = second.next
			if first == None:
				curr.next = ListNode(second.val)
				break
			curr.next = ListNode(first.val)
			curr = curr.next

		return retHead

		pass

def main():
	orgHead = ListNode(1)
	curr = orgHead
	for i in xrange(2):
		curr.next = ListNode(i + 2)
		curr = curr.next

	tmp = Solution().swapPairs(orgHead)
	while tmp != None:
		print tmp.val,
		tmp = tmp.next



if __name__ == '__main__':
	main()