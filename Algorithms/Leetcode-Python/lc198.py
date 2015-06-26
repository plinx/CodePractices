__author__ = 'linx'

class Solution(object):
	def rob(self, nums):
		sum1, sum2 = 0, 0
		for i in xrange(len(nums)):
			if i % 2:
				sum1 = max(sum1 + nums[i], sum2)
			else:
				sum2 = max(sum1, sum2 + nums[i])
		#print sum1, sum2
		return sum1 if sum2 < sum1 else sum2
		pass
	pass

if __name__ == '__main__':
	nums = [2, 1, 1, 2]
	print Solution().rob(nums)
	pass

