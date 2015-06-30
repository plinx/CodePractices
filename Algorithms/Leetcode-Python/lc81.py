__author__ = 'linx'

from random import randint

class Solution(object):
    def search(self, nums, target):
        if len(nums) < 1:
            return False
        if len(nums) == 1:
            return nums[0] == target

        mid = (len(nums)) / 2
        return nums[mid] == target or self.search(nums[:mid], target) or self.search(nums[mid+1:], target)
        pass
    pass

if __name__ == '__main__':
    nums = [randint(0, 30) for i in xrange(randint(10, 30))]
    nums += [4, 5, 9]
    nums.sort()
    rot = randint(10, 30)
    nums = nums[rot:] + nums[:rot]
    elem = randint(5, 15)
    #nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23]
    #nums = [4, 5, 6, 7, 8, 1, 2, 3]
    #nums = [23, 24, 25, 26, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22]
    #nums = [5, 1, 3]
    #nums = [2, 2, 2, 0, 2]
    print nums
    #elem = 21
    #elem = 8
    #elem = 5
    #elem = 0

    print Solution().search(nums, elem), elem
    pass
