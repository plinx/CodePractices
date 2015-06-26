__author__ = 'linx'

class Solution(object):
	def maxProfit(self, prices):
		r = [0] * len(prices)
		result, curr = 0, 0
		for i in xrange(1, len(prices)):
			r[i] = prices[i] - prices[i - 1]
			curr = max(0, curr + r[i])
			result = max(curr, result)


		print r
		return result

		pass
	pass

if __name__ == '__main__':
	#prices = [1, 2, 0, 4]
	prices = [3, 3, 5, 9, 4, 9, 10]
	#prices = [1, 4, 2]
	print Solution().maxProfit(prices)
	pass
