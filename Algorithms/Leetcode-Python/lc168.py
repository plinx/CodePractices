__author__ = 'linx'

class Solution(object):
	def convertToTitle(self, n):
		ret = ""
		while 0 < n:
			ret = chr((n - 1) % 26 + 65) + ret
			n = (n - 1) / 26

		return ret
		pass
	pass

if __name__ == '__main__':
	print Solution().convertToTitle(26*26+1)
	pass

