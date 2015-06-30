__author__ = 'linx'

from random import randint

class Solution(object):
    def findMin(self, nums):
        left, right = 0, len(nums) - 1
        mval = nums[left]
        while nums[left] == nums[right] and left < right:
            left += 1
            right -= 1
            mval = min(mval, nums[left], nums[right])

        while left < right:
            mid = (left + right) / 2
            mval = min(mval, nums[mid], nums[left], nums[right])
            #print nums[mid]
            if nums[mid] < nums[left]:
                #mval = min(mval, nums[right])
                right = mid - 1
            else:
                #mval = min(mval, nums[left])
                left = mid + 1

        #print left, right, mid, nums[left], nums[right], mval
        return mval#min(mval, nums[left], nums[right])
        pass
    pass

if __name__ == '__main__':
    nums = [randint(randint(0, 10), 30) for i in xrange(randint(10, 30))]
    nums.sort()
    rot = randint(10, len(nums))
    nums = nums[rot:] + nums[:rot]
    #nums = [3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 0, 1, 2]
    #nums = [3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 0, 1, 2]
    #nums = [10, 1, 10, 10, 10]
    nums = [3, 1, 3]
    print nums

    print Solution().findMin(nums), min(nums)
    pass
