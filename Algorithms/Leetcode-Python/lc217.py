__author__ = 'linx'

from random import randint

class Solution(object):
    def containsDuplicate(self, nums):

        n = len(nums) + 1
        ht = [[] for i in xrange(n)]

        for i in xrange(len(nums)):
            k = nums[i] % n
            if ht[k] != [] and nums[i] in ht[k]:
                return True
            ht[k].append(nums[i])

        return False
        pass
    pass

if __name__ == '__main__':
    table = []
    for i in xrange(15):
        table.append(randint(0, 100))

    table.sort()
    print table
    print Solution().containsDuplicate(table)
    pass
