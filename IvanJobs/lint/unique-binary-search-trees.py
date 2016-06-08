class Solution:
    # @paramn n: An integer
    # @return: An integer
    def numTrees(self, n):
        # write your code here
        dp = [1] * (n + 3)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n + 1):
            sumall = 0
            for j in range(1, i + 1):
                sumall += (dp[j - 1] * dp[i - j])
            dp[i] = sumall
        return dp[n]
