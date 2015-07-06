__author__ = 'linx'

class Solution(object):
    def canJump(self, nums):
        i, pos = 0, 0
        while i < len(nums) and i <= pos:
            pos = max(pos, nums[i] + i)
            i += 1
        print pos
        return (len(nums) - 1) <= pos
        pass
    pass

if __name__ == '__main__':
    nums1 = [2, 3, 1, 1, 4]
    nums2 = [3, 2, 1, 0, 4]
    nums3 = [2, 0]
    nums4 = [0, 2, 3]
    nums5 = [1, 1, 2, 2, 0, 1, 1]
    nums6 = [5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0]

    print Solution().canJump(nums4)
    pass


