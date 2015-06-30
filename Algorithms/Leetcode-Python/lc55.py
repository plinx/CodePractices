__author__ = 'linx'

class Solution(object):
    def canJump(self, nums):
        if len(nums) == 1:
            return True

        n = len(nums)
        for i in xrange(n - 1):
            j = i
            while j < n - 1:
                if nums[j] == 0:
                    if j == 0 or nums[i + 1] == 0:
                        #print j, i, nums[i + 1]
                        #print "test"
                        return False
                    break
                j += nums[j]

            if (n - 1) <= j:
                return True
        return False
        pass
    pass

if __name__ == '__main__':
    nums1 = [2, 3, 1, 1, 4]
    nums2 = [3, 2, 1, 0, 4]
    nums3 = [2, 0]
    nums4 = [0, 2, 3]
    nums5 = [1, 1, 2, 2, 0, 1, 1]
    nums6 = [5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0]

    print Solution().canJump(nums6)
    pass

