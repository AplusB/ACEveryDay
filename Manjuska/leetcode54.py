class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        ans=nums[0]
        dp=[]
        dp.append(nums[0])
        for i in range(1,n):
            dp.append(max(dp[i-1]+nums[i],nums[i]))
            ans=max(dp[i],ans)
        return ans
