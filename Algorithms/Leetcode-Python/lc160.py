__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def getIntersectionNode(self, headA, headB):
		if headA == None or headB == None:
			return None

		currA = headA
		cntA = 0
		while currA != None:
			currA = currA.next
			cntA += 1

		currB = headB
		cntB = 0
		while currB != None:
			currB = currB.next
			cntB += 1

		currA, currB = headA, headB
		if cntB < cntA:
			for i in xrange(cntA - cntB):
				currA = currA.next
		elif cntA < cntB:
			for i in xrange(cntB - cntA):
				currB = currB.next

		while currA != None and currB != None:
			if currA.val == currB.val:
				return currA
			currA = currA.next
			currB = currB.next

		return None
		pass
	pass

def main():
	Listin, Listout = [1, 2, 3, 4, 5, 6, 7], []
	headA = ListNode(Listin[0])
	currA = headA
	for i in xrange(1, len(Listin)):
		currA.next = ListNode(Listin[i])
		currA = currA.next

	headB = ListNode(0)
	currB = headB
	for i in xrange(2):
		currB.next = ListNode(i + 10)
		currB = currB.next

	currA = headA
	for i in xrange(4):
		currA = currA.next

	currB.next = currA
	print currA.val

	tmp = Solution().getIntersectionNode(headA, headB)
	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()

