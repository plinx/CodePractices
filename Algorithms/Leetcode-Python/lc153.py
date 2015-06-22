__author__ = 'linx'

from random import randint

class Solution(object):
    def findMin(self, nums):
        left, right = 0, len(nums) - 1
        if nums[left] < nums[right]:
            return nums[0]
        while left < right:
            mid = (left + right) / 2
            if nums[mid] < nums[right]:
                right = mid
            else: # nums[right] < nums[mid]
                left = mid + 1

        return nums[left]
        pass
    pass

if __name__ == '__main__':
    table = []
    for i in xrange(20):
        table.append(randint(0, 100))
    table.sort()
    newtable = table[7:] + table[:7]
    print min(newtable), newtable

    print Solution().findMin(newtable)
    pass
