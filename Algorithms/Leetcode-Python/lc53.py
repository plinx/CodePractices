__author__ = 'linx'

class Sulotion(object):
	def maxSubArray(self, nums):
		r = [0] * len(nums)
		r[0] = nums[0]
		result = r[0]
		for i in xrange(1, len(nums)):
			r[i] = nums[i] + (r[i - 1] if r[i - 1] > 0 else 0)
			result = max(result, r[i])
			pass
		return result
		pass
	pass

if __name__ == '__main__':
	table = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
	print Sulotion().maxSubArray(table)
	pass
