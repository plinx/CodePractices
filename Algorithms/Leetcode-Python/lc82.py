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

		return head
		pass
	pass

def main():
	#Listin, Listout = [2, 2], []
	#Listin, Listout = [1, 2, 2], []
	#Listin, Listout = [1, 1, 1, 2, 3, 4], []
	Listin, Listout = [1, 2, 3, 3, 4, 4, 5], []
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

