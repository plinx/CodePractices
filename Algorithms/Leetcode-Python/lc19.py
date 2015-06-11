__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def removeNthElements(self, head, n):
		if head == None:
			return head

		prev = ListNode(0)
		tail = prev.next = head
		total = 1
		while tail.next != None:
			prev = prev.next if total >= n else prev
			total += 1
			tail = tail.next

		if n == total:
			return prev.next.next

		prev.next = prev.next.next

		return head
		pass
	pass

def main():
	#Listin, Listout = [1, 2, 3, 4, 5, 6], []
	Listin, Listout = [1, 2], []
	orgHead = ListNode(Listin[0])
	curr = orgHead
	for i in xrange(1, len(Listin)):
		curr.next = ListNode(Listin[i])
		curr = curr.next

	print Listin

	#tmp = Solution().reverseBetween(orgHead, 0, 1)
	tmp = Solution().removeNthElements(orgHead, 4)
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()
