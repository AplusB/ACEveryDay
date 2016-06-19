class Solution:
    """
    @param nums: A list of integers
    @param k: As described
    @return: The majority number
    """
    def majorityNumber(self, nums, k):
        # write your code here
        hmap = {}
        for v in nums:
            if v in hmap:
                hmap[v] += 1
            else:
                hmap[v] = 1
        
        n = len(nums)
        
        for pending, v in hmap.items():
            if k * v > n:
                return pending
        
        

