__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def addTwoNumbers(self, l1, l2):
		if l1 == None:
			return l2
		if l2 == None:
			return l1


		l3 = ListNode(0)
		pl1, pl2, pl3 = l1, l2, l3
		inc = 0
		while pl1 != None and pl2 != None:
			val = pl1.val + pl2.val + inc
			inc = val / 10
			pl3.next = ListNode(val % 10)

			pl1 = pl1.next
			pl2 = pl2.next
			pl3 = pl3.next

		while pl1 != None:
			val = pl1.val + inc
			inc = val / 10
			pl3.next = ListNode(val % 10)
			pl1 = pl1.next
			pl3 = pl3.next

		while pl2 != None:
			val = pl2.val + inc
			inc = val / 10
			pl3.next = ListNode(val % 10)
			pl2 = pl2.next
			pl3 = pl3.next

		if inc != 0:
			pl3.next = ListNode(1)

		return l3.next
		pass
	pass

def main():
	#l1, l2, Listout = [2, 4, 3], [5, 6, 4], []
	l1, l2, Listout = [9, 9], [1], []
	hl1, hl2 = ListNode(l1[0]), ListNode(l2[0])
	pl1, pl2 = hl1, hl2
	for i in xrange(1, len(l1)):
		pl1.next = ListNode(l1[i])
		#pl2.next = ListNode(l2[i])
		pl1 = pl1.next
		#pl2 = pl2.next

	print l1, l2
	tmp = Solution().addTwoNumbers(hl1, hl2)
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()
