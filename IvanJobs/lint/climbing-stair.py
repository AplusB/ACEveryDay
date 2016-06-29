class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def climbStairs(self, n):
        # write your code here
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            res = 0
            if i - 1 >= 0:
                res += dp[i - 1]
            if i - 2 >= 0:
                res += dp[i - 2]
            dp[i] = res
            
        return dp[n]
