class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        dp=[0]*(amount+1)
        for i in range(1,amount+1):
            min_num=amount
            for j in coins:
                if(i-j)>=0:
                    min_num = min(min_num, dp[i-j])
            dp[i] = min_num+1
        return dp[amount]==amount+1 and -1 or dp[amount]
