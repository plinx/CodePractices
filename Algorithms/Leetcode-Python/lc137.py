__author__ = 'linx'

class Solution(object):
    def singleNumber(self, nums):
        if len(nums) == 1:
            return nums[0]

        result = nums[0]
        for i in xrange(1, len(nums)):
            result ^= nums[i]

        return result
        pass
    pass

if __name__ == '__main__':
    t1 = [1, 2, 1]
    t2 = [1, 2, 3, 3, 2]

    print Solution().singleNumber(t1)
    print Solution().singleNumber(t2)
    pass
