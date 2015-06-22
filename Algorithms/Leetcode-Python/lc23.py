__author__ = 'linx'

class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None
	pass

class Solution(object):
	def mergeKLists(self, lists):
		result = ListNode(0)
		prev = result
		while True:
			mink = 0
			for i in xrange(len(lists)):
				#print lists[i]
				if lists[mink] == None:
					mink = i
				if lists[i] != None and lists[i].val < lists[mink].val:
					mink = i
			if lists[mink] == None:
				break
			prev.next = lists[mink]
			prev = prev.next
			lists[mink] = lists[mink].next
			prev.next = None

		return result.next
		pass
	pass

def main():
	Listin = [[1, 3, 5], [2, 4, 6, 8], [3, 5, 7]]
	#Listin = [[1, 3]]
	listHead = [[None] for i in xrange(len(Listin))]
	Listout = []

	for i in xrange(len(Listin)):
		listHead[i] = ListNode(Listin[i][0])
		curr = listHead[i]
		for j in xrange(1, len(Listin[i])):
			curr.next = ListNode(Listin[i][j])
			curr = curr.next

	print Listin

	tmp = Solution().mergeKLists(listHead)

	while tmp != None:
		Listout.append(tmp.val)
		tmp = tmp.next

	print Listout


if __name__ == '__main__':
	main()

