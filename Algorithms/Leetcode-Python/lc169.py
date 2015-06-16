__author__ = 'linx'

class Solution(object):
	def majorityElement(self, nums):
		count, num = 1, nums[0]
		for i in xrange(1, len(nums)):
			if num == nums[i]:
				count += 1
			else:
				count -= 1

			if count == 0:
				num = nums[i]
				count = 1

		return num
		pass
	pass

def main():
	t = [1, 1, 1, 2, 3]
	#t = [6, 5, 5]
	print t
	print Solution().majorityElement(t)
	pass

if __name__ == '__main__':
	main()
