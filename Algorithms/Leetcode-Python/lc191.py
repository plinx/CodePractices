__author__ = 'linx'

class Solution(object):
	def hammingWeight(self, n):
		count = 0
		while n != 0:
			if n % 2 != 0:
				count += 1
			n >>= 1
		return count
		pass
	pass

def main():
	num = 2
	print Solution().hammingWeight(num)

	pass

if __name__ == '__main__':
	main()
