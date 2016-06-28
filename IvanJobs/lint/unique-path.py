class Solution:
    """
    @param n and m: positive integer(1 <= n , m <= 100)
    @return an integer
    """ 
    def uniquePaths(self, m, n):
        # write your code here
        dp = [[0 for c0 in xrange(n)] for r0 in xrange(m)]
        
        dp[0][0] = 1
        for r in xrange(m):
            for c in xrange(n):
                if dp[r][c] == 0:
                    res = 0
                    if r - 1 >= 0:
                        res += dp[r - 1][c]
                    if c - 1 >= 0:
                        res += dp[r][c - 1]
                    dp[r][c] = res
                    
        return dp[m - 1][n - 1]
