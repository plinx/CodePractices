__author__ = 'linx'

class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        ht = {}
        for i in xrange(len(nums)):
            if ht.has_key(nums[i]) and i - ht[nums[i]] <= k:
                #print ht[nums[i]], i, k, nums[i]
                return True
            else:
                ht[nums[i]] = i
        return False
        pass
    pass

if __name__ == '__main__':
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9,
            1, 2, 3, 9, 8, 7, 6, 5, 4]
    nums1 = [99, 99]
    nums2 = []

    print Solution().containsNearbyDuplicate(nums2, 1)

    pass
