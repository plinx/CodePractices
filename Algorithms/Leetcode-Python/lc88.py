__author__ = 'linx'

class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i = m - 1
        j = n - 1
        k = m + n - 1
        while 0 <= i and 0 <= j:
            if (nums1[i] < nums2[j]):
                nums1[k] = nums2[j]
                k -= 1
                j -= 1
            else: # nums2[j] <= nums1[i]
                nums1[k] = nums1[i]
                k -= 1
                i -= 1

        while 0 <= j:
            nums1[k] = nums2[j]
            k -= 1
            j -= 1


if __name__ == '__main__':
    a = [1]
    b = []
    Solution().merge(a, 1, b, 0)
    print a
