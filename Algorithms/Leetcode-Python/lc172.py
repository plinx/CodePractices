__author__ = 'linx'

class Solution(object):
	def trailingZeroes(self, n):
		return 0 if n == 0 else n / 5 + self.trailingZeroes(n / 5)

		pass
	pass

if __name__ == '__main__':
	print Solution().trailingZeroes(5)
	pass

