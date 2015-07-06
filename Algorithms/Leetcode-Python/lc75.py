__author__ = 'linx'

from random import randint

class Solution(object):
    def sortColort(self, nums):
        zero, two = 0, len(nums) - 1
        i = 0
        while i <= two:
            print i
            while nums[i] == 2 and i < two:
                nums[i], nums[two] = nums[two], nums[i]
                two -= 1
            while nums[i] == 0 and zero < i:
                nums[i], nums[zero] = nums[zero], nums[i]
                zero += 1
            i += 1
        print nums
        pass
    pass

if __name__ == '__main__':
    t1 = [1, 2, 0, 0, 2]
    for i in xrange(25):
        t1.append(randint(0, 2))
    t1 = [1, 0]
    print t1
    Solution().sortColort(t1)
    print t1
    #t1.sort()
    #print t1
    pass
