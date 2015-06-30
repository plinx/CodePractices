__author__ = 'linx'

from random import randint

class Solution(object):
    def search(self, nums, target):
        left, right = 0, len(nums) - 1
        mid = left
        while left < right:
            mid = (left + right) / 2
            if nums[right] < nums[mid]:
                left = mid + 1
            else:
                right = mid

        rot = left
        left, right = 0, len(nums) - 1
        if rot != 0:
            if nums[0] <= target:
                right = rot - 1
            else:
                left = rot

        while left <= right:
            mid = (left + right) / 2
            if nums[mid] < target:
                left = mid + 1
            elif target < nums[mid]:
                right = mid - 1
            else: # nums[mid] == target
                return mid

        return -1
        pass
    pass

if __name__ == '__main__':
    nums = [i for i in xrange(randint(10, 30))]
    nums += [4, 5, 9]
    nums.sort()
    rot = randint(10, 30)
    nums = nums[rot:] + nums[:rot]
    elem = randint(5, 15)
    #nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23]
    #nums = [4, 5, 6, 7, 8, 1, 2, 3]
    #nums = [23, 24, 25, 26, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22]
    #nums = [5, 1, 3]
    print nums
    #elem = 21
    #elem = 8
    #elem = 5

    result = Solution().search(nums, elem)
    mark = ["["]
    for i in xrange(len(nums)):
        if i != result:
            if nums[i] / 10:
                mark.append("  ,")
            else:
                mark.append(" ,")
        else:
            if nums[i] / 10:
                mark.append("^^,")
            else:
                mark.append("^,")
        mark.append(" ")
    mark.pop()
    mark[-1] = mark[-1].replace(",", "]")
    print "".join(mark)

    print elem, result, nums[result] if result != -1 else None
    pass