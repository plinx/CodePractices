__author__ = 'linx'

class Solution(object):
    def findPeakElement(self, nums):
        i = 0
        for i in xrange(1, len(nums)):
            if nums[i] < nums[i - 1]:
                return i - 1

        return i

        pass
    pass

if __name__ == '__main__':
    nums1 = [1]
    nums2 = [1, 2]
    nums3 = [1, 2, 3]
    nums4 = [2, 1]
    nums5 = [3, 2, 1]
    nums6 = [1, 3, 5, 9, 7, 6, 2]
    nums7 = [1, 2, 9, 3, 3, 1]
    nums8 = [2, 1, 2]

    nums = nums7
    n = Solution().findPeakElement(nums)
    print "nums[%d]" % n, nums[n]

    pass