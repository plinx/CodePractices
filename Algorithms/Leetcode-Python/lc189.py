__author__ = 'linx'

class Solution(object):
    def rotate(self, nums, k):
        index = len(nums) - k % len(nums)
        newnum = nums[index:]
        newnum += nums[0:index]
        #for i in xrange(len(nums)):
        nums[:] = newnum[:]
        pass
    pass

if __name__ == '__main__':
    nums = [1, 2, 3]
    print nums
    Solution().rotate(nums, 1)
    print nums
    pass
