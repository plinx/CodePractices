__author__ = 'linx'

class Solution(object):
    def jump(self, nums):
        n = len(nums)
        steps = [0 for i in xrange(n)]
        for i in xrange(n - 2, -1, -1):
            if nums[i] != 0:
                next = steps[min(n - 1, i + nums[i])]
                if i == 3:
                    print next
                if next == -1 and steps[i + 1] == -1:
                    steps[i] = min(next, steps[i + 1]) + 1 if next != -1 else -1
            else:
                steps[i] = -1

        print steps
        return steps[0]
        pass
    pass

if __name__ == '__main__':
    nums1 = [2, 3, 1, 1, 4]
    nums2 = [3, 2, 1, 0, 4]
    nums3 = [2, 0]
    nums4 = [0, 2, 3]
    nums5 = [1, 1, 2, 2, 0, 1, 1]
    nums6 = [5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0]

    print Solution().jump(nums5)
    pass
