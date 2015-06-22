__author__ = 'linx'

class Solution(object):
    def findKthLargest(self, nums, k):
        nums.sort()
        return nums[-k]
        pass
    pass

if __name__ == '__main__':
    nums = [1, 2]
    print Solution().findKthLargest(nums, 1)
    pass
