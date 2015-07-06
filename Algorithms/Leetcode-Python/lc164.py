__author__ = 'linx'

class Solution(object):
    def maximunGap(self, nums):
        if len(nums) < 2:
            return 0

        MAXINF, MININF = 2**31 - 1, -2**31
        maxval, minval = max(nums), min(nums)
        bucket_max = [MININF for i in xrange(len(nums))]
        bucket_min = [MAXINF for i in xrange(len(nums))]
        bucket_step = (maxval - minval) / len(nums)
        bucket_step += 1
        #print bucket_step

        #print bucket_step
        for i in xrange(len(nums)):
            idx = (nums[i] - minval) / bucket_step
            #print nums[i] - minval, idx
            bucket_max[idx] = max(bucket_max[idx], nums[i])
            bucket_min[idx] = min(bucket_min[idx], nums[i])

        #print bucket_max
        #print bucket_min

        result = bucket_max[0] - bucket_min[0] if bucket_max[0] != bucket_min[0] else 0
        prev = bucket_max[0]
        for i in xrange(1, len(nums)):
            if bucket_min[i] != bucket_max[i]:
                result = max(result, bucket_max[i] - bucket_min[i])
                if bucket_min[i] != MAXINF:
                    result = max(result, bucket_min[i] - prev)
            else:
                result = max(result, bucket_min[i] - prev)
            prev = max(prev, bucket_max[i])


        return result
    pass

if __name__ == '__main__':
    #nums = [1, 3, 5, 9]
    #nums = [2, 9999999]
    nums = [3, 6, 9, 1]
    #nums = [100, 3, 2, 1]
    #nums = [15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740]
    print Solution().maximunGap(nums)
    nums.sort()
    r = 0
    for i in xrange(1, len(nums)):
        if r < nums[i] - nums[i - 1]:
            r = nums[i] - nums[i - 1]
            #print nums[i], nums[i - 1], nums[i] - nums[i - 1]
    print r

    pass
