__author__ = 'linx'

from random import randint

class Solution(object):
    def searchRange(self, nums, target):
        left, right = 0, len(nums) - 1
        mid = left
        while left < right:
            mid = (left + right) / 2
            if nums[mid] < target:
                left = mid + 1
            elif target < nums[mid]:
                right = mid - 1
            else:
                left = right = mid
                break

        while 0 <= left and nums[left] == target:
            left -= 1

        while right < len(nums) and nums[right] == target:
            right += 1

        if left + 1 < len(nums) and nums[left + 1] == target:
            return [left + 1, right - 1]

        return [-1, -1]
        pass
    pass

if __name__ == '__main__':
    nums = [randint(0, 10) for i in xrange(10)]
    nums.sort()
    target = randint(0, 10)
    nums = [1]
    target = 1
    print nums
    print target
    print Solution().searchRange(nums, target)
    pass