class Solution:
    """
    @param nums: A list of integers
    @return: The majority number
    """
    def majorityNumber(self, nums):
        # write your code here
        res, cnt = -1, 0
        
        for num in nums:
            if cnt == 0:
                res = num
            
            if num == res:
                cnt += 1
            else:
                cnt -= 1
                
        return res
