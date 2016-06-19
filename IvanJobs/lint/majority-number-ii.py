class Solution:
    """
    @param nums: A list of integers
    @return: The majority number occurs more than 1/3
    """
    def majorityNumber(self, nums):
        # write your code here
        k1, k2, c0, c1 = -1, -1, 0, 0
        
        i = 0
        n = len(nums)
        
        while i < n:
            if c0 == 0 or nums[i] == k1: # consume eles in array are not negtive
                k1 = nums[i]
                c0 += 1
            elif c1 == 0 or nums[i] == k2:
                k2 = nums[i]
                c1 += 1
            else:
                c0 -= 1
                c1 -= 1
            i += 1
            
        # count number of k1, k2
        c1, c2 = 0, 0
        for e in nums:
            if e == k1:
                c1 += 1
            if e == k2:
                c2 += 1
        if c1 > c2:
            return k1
        else:
            return k2
                

